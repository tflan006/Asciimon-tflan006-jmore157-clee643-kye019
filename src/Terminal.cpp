#include "../header/Terminal.hpp"
#include "../header/HumanPlayer.hpp"
#include "../header/ComputerPlayer.hpp"
#include "../header/BattleSimulator.hpp"
#include "../header/BattleResults.hpp"
#include "../header/AsciimonCodex.hpp"
#include <iostream>
#include <cassert> // Include for assert

using namespace std;

void displayIntro(std::ostream& out) {
    out << "****************************************************\n";
    out << "  ___   _____ _____ _____ ________  ________ _   _ \n"
" / _ \\ /  ___/  __ \\_   _|_   _|  \\/  |  _  | \\ | |\n"
"/ /_\\ \\\\ `--.| /  \\/ | |   | | | .  . | | | |  \\| |\n"
"|  _  | `--. \\ |     | |   | | | |\\/| | | | | . ` |\n"
"| | | |/\\__/ / \\__/\\_| |_ _| |_| |  | \\ \\_/ / |\\  |\n"
"\\_| |_/\\____/ \\____/\\___/ \\___/\\_|  |_/\\___/\\_| \\_/";
    out << "\n\n****************************************************" << std::endl;
}

void displayMainMenu(std::ostream& out) {
    out << "********************************************" << endl;
    out << "*              ASCII DASHBOARD             *" << endl;
    out << "********************************************" << endl;
    out << "*                                          *" << endl;
    out << "*  1. Quit                                 *" << endl;
    out << "*  2. Fight a Trainer                      *" << endl;
    out << "*  3. List Asciimon Names                  *" << endl;
    out << "*  4. Fight an Asciimon                    *" << endl;
    out << "*                                          *" << endl;
    out << "********************************************" << endl;
    out << "Enter choice: ";
}

Asciimon chooseStarterAsciimon(int listCount, std::string name, std::ostream& out) {
    AsciimonCodex codex;
    std::vector<Asciimon> choices;
    choices.reserve(listCount);
    choices.push_back(codex.generateAsciimon(FIRE));
    choices.push_back(codex.generateAsciimon(ELECTRIC));
    choices.push_back(codex.generateAsciimon(GRASS));

    std::size_t choice{std::numeric_limits<std::size_t>::max()};
    out << "********************************************" << endl;
    out << "               CHOOSE ASCIIMON              " << endl;
    out << "Welcome " << name << "!" << std::endl;
    do {
        out << "Please choose your starter asciimon:\n";
        for (std::size_t i{0}; i < choices.size(); ++i) {
            out << i << ": " << choices[i].getName() << std::endl;
        }
        if (!(std::cin >> choice) || choice >= listCount) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            out << "**Invalid choice, please try again**" << std::endl;
            choice = listCount;
        }
    } while(choice >= listCount);
    out << "You have chosen " << choices[choice].getName() << "!\n";
    out << "Get ready for adventure!\n";
    return choices[choice];
}

void displayAsciimonNames(const Trainer& trainer, std::ostream& out) {
    out << "********************************************" << std::endl;
    out << "*          ASCIIMON TEAM MEMBERS           *" << std::endl;
    out << "********************************************" << std::endl;

    const auto& team = trainer.getTeam();
    for (size_t i = 0; i < team.size(); ++i) {
        out << i + 1 << ". " << team[i].getName() << std::endl;
    }

    out << "********************************************\n" << std::endl;
}


bool fightAsciimon(Trainer& player, BattleSimulator& sim, std::ostream& out) {
    out << "You have chosen to fight an Asciimon!" << endl;
    UI obj = [](const BattlePlayer& player, const BattlePlayer& opponent, std::string message, std::string details){};
    AsciimonCodex codex;
    auto asciimon{codex.generateRandomAsciimon()};
    auto[presult, oresults] = sim.battle(HumanPlayer::make(player), ComputerPlayer::make(asciimon));
    switch (presult.getResults()) {
        case BattleResults::WON:
            out << "Congratulations, you beat " << oresults.getPlayer()->getAsciimon().getName() << "!" << endl;
            player.setParty(presult.getPlayer()->getParty());
            return true;
        case BattleResults::LOSS:
            out << "Game over! You were defeated by " << oresults.getPlayer()->getAsciimon().getName() << "!" << endl;
            return false;
        case BattleResults::FLED:
            out << "You fled and live to fight another day!" << endl;
            return true;
        default: 
            assert(false && "Unknown battle results...");
    }
}


GameState fightTrainer(Trainer& player, Trainer& opponent, BattleSimulator& sim, bool comps, std::ostream& out) {
    out << "You have chosen to fight an Asciimon!" << endl;
    if (opponent.getTeam().empty()) {
        out << "No Asciimon available to fight!" << endl;
        return CONTINUE;
    }
    UI obj = [](const BattlePlayer& player, const BattlePlayer& opponent, std::string message, std::string details){};
    auto[presult, oresults] = !comps ? sim.battle(HumanPlayer::make(player), ComputerPlayer::make(opponent)) : sim.battle(ComputerPlayer::make(player), ComputerPlayer::make(opponent), obj);
    switch (presult.getResults()) {
        case BattleResults::WON:
            out << "Congratulations, you beat " << oresults.getPlayer()->getName() << "!" << endl;
            return TRAINER_WIN;
        case BattleResults::LOSS:
            out << "Game over! You were defeated by " << oresults.getPlayer()->getName() << "!" << endl;
            return LOSS;
        case BattleResults::FLED:
            out << "You fled and live to fight another day!" << endl;
            return CONTINUE;
        default: 
            assert(false && "Unknown battle results...");
    }
}

GameState processUserChoice(char choice, Trainer& player, Trainer& opponent, BattleSimulator& sim, bool comps, std::ostream& out) {
    switch (choice) {
        case '1':
            out << "Goodbye, Trainer!" << endl;
            return QUIT;
        case '2':
            return fightTrainer(player, opponent,sim,comps,out);
            break;
        case '3':
            displayAsciimonNames(player, out);
            return CONTINUE;
        case '4':
            if (fightAsciimon(player, sim, out)) {
                return CONTINUE;
            }
            else {
                return LOSS;
            }
            break;
        default:
            out << "Invalid choice. Please try again." << endl;
            return CONTINUE;
    }
}
