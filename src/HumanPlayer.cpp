#include "../header/HumanPlayer.hpp"
#include "../header/Screen.hpp"
#include <variant>

using namespace ftxui;

namespace
{
    PlayerMove battleUI(const BattlePlayer& player, const BattlePlayer& opponent) {
        PlayerMove choice;

        std::string message{};
        std::variant<ftxui::Element, ftxui::Component> infoSection{ paragraph("Prepare to battle!") };
        bool refresh{ true };
        std::vector<std::string> moves{};
        int moveIndex{};
        auto FIGHT_BTN{ makeButton("FIGHT", [&] {
            moves.clear();
            for (auto& move : player.getAsciimon().getMoveSet()) {
                moves.push_back("Move: " + move.getName());
            }
            infoSection = Container::Vertical(
                {Radiobox(&moves, &moveIndex), 
                makeButton("Confirm", [&]{
                    auto move{player.getAsciimon().getMoveSet().at(moveIndex)};
                    choice = PlayerMove{ move };
                    refresh = false;    
                    screen.ExitLoopClosure()();
                }) }
            );
            screen.ExitLoopClosure()();
        }) };
        auto ASCII_BTN{ makeButton("ASCIIMON", [&]{

        }) }; 

        auto CATCH_BTN{ makeButton(opponent.catchable() ? "CATCH" : "", [&]{
            if (opponent.catchable()) {
                choice = PlayerMove{std::string{"catch"}};
                refresh = false;    
                screen.ExitLoopClosure()();
            }
        }) };
        auto FLEE_BTN { makeButton("RUN", [&]{ 
            choice = PlayerMove{ true };
            refresh = false;
            screen.ExitLoopClosure()();
        }) };
       
        // The tree of components. This defines how to navigate using the keyboard.
        // The selected `row` is shared to get a grid layout.
        int row{ 0 };
        auto buttons = Container::Vertical({
            Container::Horizontal({FIGHT_BTN, ASCII_BTN}, &row) | flex,
            Container::Horizontal({CATCH_BTN, FLEE_BTN}, &row) | flex,
        });

        do {
            system("clear");
            std::variant<ftxui::Element, ftxui::Component> details{ infoSection };
            const bool isDetailsComponent{ std::holds_alternative<ftxui::Component>(details) };
            auto main_container{ Container::Horizontal(
                 !isDetailsComponent ? ftxui::Components{ buttons } : ftxui::Components{ std::get<ftxui::Component>(details), buttons }
            ) };
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

            auto main_renderer = Renderer(main_container, [&] {
                return window(text(""), vbox(
                    playerStage,
                    separator(),
                    hbox(
                        center(isDetailsComponent ? std::get<ftxui::Component>(details)->Render() : std::get<ftxui::Element>(details)) | flex,
                        separator(),
                        buttons->Render()
                    ) | flex
                ));
            });
            screen.Loop(main_renderer);
        } while(refresh);
        screen.Clear();
        screen.Exit();
        return choice;
    }
}


HumanPlayer::HumanPlayer(Trainer player) 
    : BattlePlayer(player.getName(), player.getTeam()) {

}

PlayerMove HumanPlayer::makeMove(const BattlePlayer& target)
{
    return battleUI(*this, target);
}

HumanPlayer::Ptr HumanPlayer::make(Trainer player)
{
    return std::make_unique<HumanPlayer>(player);
}

void HumanPlayer::changeAsciimon(const BattlePlayer& target)
{
    std::vector<std::string> asciiOptions;
    for (auto& candidate : remainingParty()) {
        asciiOptions.push_back(candidate->getName());
    }
    int selected{};
    auto radioOptions{ Radiobox(&asciiOptions, &selected) };
    auto confirmBtn{ makeButton("Confirm", [&] {
        switchAsciimon(*std::next(std::begin(remainingParty()), selected));
        screen.Exit();
    }) };
    auto selectionUI{ Container::Vertical({
        radioOptions, 
        confirmBtn
    } ) };
    auto main_container{ selectionUI };
    auto main_renderer = Renderer(main_container, [&] {
        return window(text("Next Asciimon..."), hbox(vbox(
            center(radioOptions->Render()) | flex,
            center(confirmBtn->Render())
        ), separator()));
    });
    system("clear");
    screen.Loop(main_renderer);
}
