#include "../header/BattleSimulator.hpp"
#include <memory>  
#include <string>  
#include <queue>
#include "../header/Screen.hpp"

namespace
{
    void battleUI(const BattlePlayer& player, const BattlePlayer& opponent, std::string message, std::string details) {
        const auto playerRatio{ healthRatio(player) };
        const auto playerUI{ vbox(
            center(text(player.getName())),
            separator(),
            center(text(player.getAsciimon().getName())) | flex, center(text(playerRatio.first)), gauge(playerRatio.second * .98f)
        ) | flex};
        const auto oppRatio{ healthRatio(opponent) };
        const auto oppUI{ vbox(
            center(text(opponent.getName())),
            separator(),
            center(text(opponent.getAsciimon().getName())) | flex, center(text(oppRatio.first)), gaugeDirection(oppRatio.second*.98f, ftxui::Direction::Left)
        ) | flex};
        const auto playerStage{hbox(playerUI, separator(), oppUI) | flex};
        auto main_container{ Container::Horizontal({}) };
        main_container |= CatchEvent([&](Event event) {
            if (event == Event::Return || event == Event::Character(' ')) {
                screen.Exit();
            }
            return event == Event::Return || event == Event::Character(' ');
        });

        auto main_renderer = Renderer(main_container, [&] {
            return window(text(""), vbox(
                playerStage,
                separator(),
                hbox( center(vbox(center(paragraph(message)), center(paragraph(details)))) | flex) | flex,
                align_right(text("Press enter/space to continue..."))
            ));
        });
        system("clear");
        screen.Loop(main_renderer);
    }
}

BattleSimulator::BattleSimulator(BattleMechanics mechanics)
    : mechanics(mechanics)
{

}

std::pair<BattleResults, BattleResults> BattleSimulator::battle(BattlePlayer::Ptr player, BattlePlayer::Ptr opponent, UI ui)
{
    std::queue<BattlePlayer*> turnTable;
    turnTable.push(player.get());
    turnTable.push(opponent.get());

    do {
        auto activePlayer{ turnTable.front() };
        auto targetPlayer{ turnTable.back() };
        PlayerMove playerMove{ activePlayer->makeMove(*targetPlayer) };
        std::string message{ playerMove.getMessage().value_or("") };
        std::string details{ };
        if (const auto move{playerMove.getMove()}; move.has_value()) {
            const Asciimon& activeAsciimon{ activePlayer->getAsciimon() };
            const Asciimon& targetAsciimon{ targetPlayer->getAsciimon() };
            const HitDetails hit{ mechanics.attemptHit(move.value(), activeAsciimon, targetAsciimon) };
            targetPlayer->takeDamage(hit.getDamage());
            message = hit.getMessage();
            details = hit.getDetails();
        }
        else if (!playerMove.getMessage().has_value() && playerMove.hasFled()) {
            message = activePlayer->getName() + " attempts to flee!";
        }
        else if (playerMove.getMessage().value_or("") == "catch") {
            message = activePlayer->getName() + " attempts to catch " + opponent->getAsciimon().getName() + "!";
        }
        if (playerMove.hasFled()) {
            system("clear");
            break;
        }

        ui(*player, *opponent, message, details);   
        if (playerMove.getMessage().value_or("") == "catch") {
            const Asciimon& activeAsciimon{ activePlayer->getAsciimon() };
            const Asciimon& targetAsciimon{ targetPlayer->getAsciimon() };
            if (targetAsciimon.getHealth() <= targetAsciimon.getStatistics().getMaxHealth() / 2) {
                activePlayer->addMember(targetAsciimon);
                ui(*player, *opponent, std::string{"You caught "} + targetAsciimon.getName(), "");
                opponent->takeDamage(opponent->getAsciimon().getHealth());
            }
            else {
                ui(*player, *opponent, std::string{"You failed to catch "} + opponent->getAsciimon().getName(), "");
            }
        }
        else if (targetPlayer->getAsciimon().getHealth() <= 0) {
            const Asciimon& activeAsciimon{ activePlayer->getAsciimon() };
            const Asciimon& targetAsciimon{ targetPlayer->getAsciimon() };
            ui(*player, *opponent, targetPlayer->getAsciimon().getName() + " has fallen!", "");   
            const auto exp{ mechanics.calculateVictoryExp(activeAsciimon, targetAsciimon) };
            const auto levels{ activePlayer->getAsciimon().gainExperience(exp) };
            if (levels > 0) {
                ui(*player, *opponent, activeAsciimon.getName() + " has gained " + std::to_string(levels) + " levels!", ""); 
            }
        }
        if (!targetPlayer->isDefeated() && targetPlayer->getAsciimon().getHealth() <= 0) {
            targetPlayer->changeAsciimon(*activePlayer);
            ui(*player, *opponent, targetPlayer->getName() + " sends out " + targetPlayer->getAsciimon().getName() + "!", "");
        }
        turnTable.pop();
        turnTable.push(activePlayer);
    } while(!player->isDefeated() && !opponent->isDefeated());

    const bool playerWins{ opponent->isDefeated() };
    const bool opponentWins{ player->isDefeated() };
    const auto playerResults{ playerWins ? BattleResults::WON : BattleResults::LOSS };
    const auto opponentResults{ opponentWins ? BattleResults::WON : BattleResults::LOSS };
    return { 
        BattleResults{ (!playerWins && !opponentWins) ? BattleResults::FLED : playerResults, std::move(player) },
        BattleResults{ (!playerWins && !opponentWins) ? BattleResults::FLED : opponentResults, std::move(opponent) }
     };
}

std::pair<BattleResults, BattleResults> BattleSimulator::battle(BattlePlayer::Ptr player, BattlePlayer::Ptr opponent)
{
    return battle(std::move(player), std::move(opponent), [](const BattlePlayer& player, const BattlePlayer& opponent, std::string message, std::string details) {
        battleUI(player, opponent, message, details);
    });
}   
