#ifndef __TRAINERGENERATOR_HPP
#define __TRAINERGENERATOR_HPP

#include "../header/Asciimon.hpp"
#include "../header/AsciimonCodex.hpp"
#include "../header/Trainer.hpp"


class TrainerGenerator {

    public:

    Trainer generateTrainer(int);

    private:

    string difficutlyToName(int);
};



#endif
