#include "../header/TrainerGenerator.hpp"



using namespace std;


Trainer TrainerGenerator::generateTrainer(int difficulty)
{
    string name = difficutlyToName(difficulty);
    Trainer newTrainer(name);


    AsciimonCodex codex;
    for (int i = 0; i<difficulty; i++)
    {
        Asciimon newAsciimon = codex.generateRandomAsciimon();
        newTrainer.addAsciimon(newAsciimon);
    }

    return newTrainer;
}


string TrainerGenerator::difficutlyToName(int difficulty)
{
    string name;
    if (difficulty == 1)
    {
        name = "Siddharta Dutta";
    }
    else if(difficulty == 2)
    {
        name = "Jordan Chan";
    }
    else
    {
        name = "Reem Ali";
    }
    return name;
}
