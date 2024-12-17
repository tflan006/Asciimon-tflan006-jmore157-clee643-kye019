#pragma once

#ifndef MOVE_HPP
#define MOVE_HPP

#include <string>

class Move {
    private:
        std::string name;
        std::string description;
        float accuracy;
        int power;


    public:
        Move(std::string name, std::string description, float accuracy, int power);
        std::string getName() const;
        std::string getDescription() const;
        float getAccuracy() const;
        int getPower() const;
};

#endif
