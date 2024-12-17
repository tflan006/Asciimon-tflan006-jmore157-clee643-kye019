#include "../header/HitDetails.hpp"
#include <cassert>

HitDetails::HitDetails(const std::string &message, const std::string &details, int damage)
    : message(message),
    details(details),
    damage(damage)
{
    assert(damage >= 0);
}

const std::string& HitDetails::getMessage() const
{
    return message;
}

const std::string& HitDetails::getDetails() const
{
    return details;
}

int HitDetails::getDamage() const
{
    return damage;
}
