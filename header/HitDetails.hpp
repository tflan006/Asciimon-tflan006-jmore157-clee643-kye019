#pragma once

#ifndef HIT_DETAILS_HPP
#define HIT_DETAILS_HPP

#include <string>

class HitDetails {
private:
    std::string message;
    std::string details;
    int damage;
public:
    HitDetails(const std::string& message, const std::string& details, int damage);

    const std::string& getMessage() const;

    const std::string& getDetails() const;

    int getDamage() const;
};

#endif /* HIT_DETAILS_HPP */
