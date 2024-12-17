#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "../header/BattleSimulator.hpp"
#include "../header/Move.hpp"
#include "../header/Trainer.hpp"
#include "../header/HumanPlayer.hpp"
#include "../header/ComputerPlayer.hpp"
#include "../header/Terminal.hpp"
#include "../header/Screen.hpp"
#include "../header/TrainerGenerator.hpp"

ScreenInteractive screen{ ScreenInteractive::FixedSize(96, 24) };

Trainer Introduction() {
    std::string name;
    std::cout << "In the dim recesses of AsciiLand, a tale of darkness unfolds." << std::endl;
    std::cout << "Once, harmony reigned between humans and ASCIIMON, until greed shattered their bond. Now, the realm languishes in eternal twilight, torn apart by chaos." << std::endl;
    std::cout << "Emerging from this turmoil are three legendary ASCIIMON trainers, each vying for dominance over AsciiLand." << std::endl;
    std::cout << "As a new ASCIIMON trainer, you embark on a perilous quest to bring light to the shadows." << std::endl;
    std::cout << "Guided by the fallen, you face wild ASCIIMON and formidable foes, including the legendary trainers who seek to bend the realm to their will." << std::endl;
    std::cout << "Will you defy the darkness and emerge victorious, or succumb to its allure? In AsciiLand, the fate of all hangs in the balance." << std::endl;
    std::cout << std::endl;
    std::cout << "What is your name, Trainer?" << std::endl;
    std::getline(std::cin, name);
    Trainer Player(name);
    return Player;
}

void EndingofGameResult(bool victory){
    if(victory){
        std::cout << "In the dim recesses of AsciiLand, your quest has reached its conclusion." << std::endl;
        std::cout << "You’ve faced wild ASCIIMON and the three legendary trainers, triumphing over darkness." << std::endl;
        std::cout << "With your victory, the eternal twilight lifts, and harmony is restored." << std::endl;
        std::cout << "AsciiLand breathes again, the shadows dispelled. You are hailed as the hero who brought light to the realm." << std::endl;
        std::cout << "Peace returns to AsciiLand, a beacon of hope shines, and your legacy endures in the rejuvenated world." << std::endl << std::endl;
        std::cout << "YOU HAVE BEAT THE GAME, CONGRATS!" << std::endl;
    }
    else{
        std::cout << "In the dim recesses of AsciiLand, your quest has ended in sorrow." << std::endl;
        std::cout << "The wild ASCIIMON and three legendary trainers proved too powerful, and darkness overwhelmed you." << std::endl;
        std::cout << "The eternal twilight deepens, and AsciiLand falls further into chaos. The realm languishes in shadows, and the harmony is lost." << std::endl;
        std::cout << "You have succumbed to the darkness, leaving AsciiLand in despair, where hope is but a fading memory." << std::endl << std::endl;

        std::cout << "  _____          __  __ ______    ______      ________ _____  " << std::endl;
        std::cout << " / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ " << std::endl;
        std::cout << "| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | " << std::endl;
        std::cout << "| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /  " << std::endl;
        std::cout << "| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\  " << std::endl;
        std::cout << " \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ " << std::endl;

    }
}

GameState play() {
    AsciimonCodex codex;
    Trainer player{ Introduction() };
    player.addAsciimon(chooseStarterAsciimon(3, player.getName()));
    TrainerGenerator generator;
    BattleSimulator sim;
    char choice;
    int counter{};
    GameState gameState{CONTINUE};
    do {
        Trainer opp{generator.generateTrainer(counter+1)};
        displayMainMenu();
        std::cin >> choice;
        gameState = processUserChoice(choice, player, opp, sim);
        if (gameState == TRAINER_WIN) {
            ++counter;
        }
    } while (choice != '1' && counter < 3 && (gameState == CONTINUE || gameState == TRAINER_WIN));
    if (counter >= 3) {
        gameState == WIN;
    }
    return gameState;
}

int main() {
    system("clear");
    displayIntro();
    std::cout << "Press enter to play...";
    std::cin.get();
    char choice{};
    do {
        switch (play())
        {
        case WIN:
            EndingofGameResult(true);
        case LOSS:
            EndingofGameResult(false);
        case QUIT:
            return 0;
        default:
            assert(false && "Unknown game state");
            break;
        }
        std::cout << "Would you like to play again?\n";
        std::cout << "Y/y for yes, else to quit: ";
        std::cin >> choice;
    } while(choice == 'y' || choice == 'Y');
    return 0;
}
