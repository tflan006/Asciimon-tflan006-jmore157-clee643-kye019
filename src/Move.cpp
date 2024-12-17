#include "../header/Move.hpp"
using namespace std;

Move::Move(string name, string description, float accuracy, int power)
    :   name{name},
        description{description},
        accuracy{accuracy},
        power{power} {

}

string Move::getName() const {
    return name;
}

string Move::getDescription() const {
    return description;
}

float Move::getAccuracy() const {
    return accuracy;
}

int Move::getPower() const {
    return power;
}
