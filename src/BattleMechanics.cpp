#include "../header/BattleMechanics.hpp"
#include "../header/Asciimon.hpp"
#include "../header/Move.hpp"
#include <random>


namespace
{
    std::string moveMessage(const Move& move, const Asciimon& attacker, const Asciimon& defender)
    {
        return attacker.getName() + " uses the move " + move.getName();
    }

    std::string evasionMessage(const Move& move, const Asciimon& attacker, const Asciimon& defender)
    {
        return defender.getName() + " evades the attack!";
    }

    std::string criticalMessage(const Move& move, const Asciimon& attacker, const Asciimon& defender)
    {
        return attacker.getName() + " lands a critical hit!";
    }

    static std::default_random_engine engine{ std::random_device{}() };
} 


BattleMechanics::BattleMechanics(float criticalChance)
    : criticalChance(criticalChance)
{

}

bool BattleMechanics::isCriticalMove(const Move& move, const Asciimon& attacker, const Asciimon& defender) const
{
    std::uniform_real_distribution<float> distribution{ 0.f, 1.f };
    const auto attackSpeed{ static_cast<float>(attacker.getStatistics().getSpeed()) }; 
    const auto defenseSpeed{ static_cast<float>(defender.getStatistics().getSpeed()) };

    return distribution(engine) <= (criticalChance * sqrt(attackSpeed / defenseSpeed));
}

bool BattleMechanics::attemptMove(const Move& move, const Asciimon& attacker, const Asciimon& defender) const
{
    std::uniform_real_distribution<float> distribution{ 0.f, 1.f };
    const auto attackSpeed{ static_cast<float>(attacker.getStatistics().getSpeed()) }; 
    const auto defenseSpeed{ static_cast<float>(defender.getStatistics().getSpeed()) };

    return distribution(engine) <= (move.getAccuracy() * sqrt(attackSpeed / defenseSpeed));
}

int BattleMechanics::computeMoveDamage(const Move& move, const Asciimon& attacker, const Asciimon& defender, bool isCritical) const
{
    std::uniform_real_distribution<float> distribution{ 0.8f, 1.f };
    const auto attackStats{ static_cast<float>(attacker.getStatistics().getAttack()) };
    const auto defenseStats{ static_cast<float>(defender.getStatistics().getDefense()) };
    const float multiplier{ distribution(engine) * (isCritical ? 2.f : 1.f) };
    const float statScale{ attackStats / defenseStats };
    const int damage{ static_cast<int>(move.getPower() * multiplier * statScale) };
    return std::min(damage, defender.getHealth());
}


int BattleMechanics::calculateVictoryExp(const Asciimon& attacker, const Asciimon& defender) const
{
    const Statistics& attackerStats{ attacker.getStatistics() };
    const Statistics& defenderStats{ defender.getStatistics() };
    const auto levelScaling{ pow(std::max(defenderStats.getLevel(), 1) / std::max(attackerStats.getLevel(), 1), 2) };
    const auto statTotal{ defenderStats.getAttack() + defenderStats.getDefense()
                          + defenderStats.getSpeed() + defenderStats.getMaxHealth()
    };
    return static_cast<int>((defenderStats.getLevel() + statTotal/2) * levelScaling);
}

HitDetails BattleMechanics::attemptHit(const Move& move, const Asciimon& attacker, const Asciimon& defender) const
{
    std::string message{ moveMessage(move, attacker, defender) };
    std::string details{ evasionMessage(move, attacker, defender) };
    int damage{};

    if (attemptMove(move, attacker, defender)) {
        const bool isCritical{ isCriticalMove(move, attacker, defender) };
        if (isCritical) {
            details = criticalMessage(move, attacker, defender);
        }
        else {
            details = "";
        }
        damage = computeMoveDamage(move, attacker, defender, isCritical);
    }

    return { message, details, damage };
}
