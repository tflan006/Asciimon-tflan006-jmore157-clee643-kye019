#include "../header/ComputerPlayer.hpp"
#include <random>


namespace
{
    template<typename Container>
    Move mostAccurateMove(const Container& moveSet) {
        Move safest{ *std::begin(moveSet) };

        for (const Move& move : moveSet) {
            if (move.getAccuracy() > safest.getAccuracy() || 
                (move.getAccuracy() == safest.getAccuracy() && move.getPower() > safest.getPower()) ) {
                safest = move;
            }
        }

        return safest;
    }

    template<typename Container>
    Move mostPowerfulMove(const Container& moveSet) {
        Move strongest{ *std::begin(moveSet) };

        for (const Move& move : moveSet) {
            if (move.getPower() > strongest.getPower() || 
                (move.getPower() == strongest.getPower() && move.getAccuracy() > strongest.getAccuracy()) ) {
                strongest = move;
            }
        }

        return strongest;
    }

    template<typename Container, typename Engine>
    auto randomElement(const Container& container, Engine& engine) {
        std::uniform_int_distribution<std::size_t> dist{ 0, container.size() - 1 };

        return std::next(std::begin(container), dist(engine));
    }

    static std::default_random_engine engine{ std::random_device{}() };
}

ComputerPlayer::ComputerPlayer(Trainer trainer, double intelligence)
    : BattlePlayer(trainer.getName(), trainer.getTeam()),
    intelligence(intelligence),
    isCatchable(false) {

}

PlayerMove ComputerPlayer::makeMove(const BattlePlayer& target)
{
    Asciimon liveAsciimon{ getAsciimon() };
    const Move mostAccurate{ mostAccurateMove(liveAsciimon.getMoveSet()) };
    const Move mostDamage{ mostPowerfulMove(liveAsciimon.getMoveSet()) };

    static std::uniform_real_distribution<> play{ 0., 1. };
    const auto roll{ play(engine) };

    const Move pick{ [&]() {
        // 50% chance to make a random move, 50% chance to make a smarter move.
        if (roll >= intelligence) {
            return *randomElement(liveAsciimon.getMoveSet(), engine);
        }
        else if (mostAccurate.getPower() >= target.getAsciimon().getHealth()) {
            return mostAccurate;
        }
        else {
            return mostDamage;
        }
    }() };

    return { pick };
}

ComputerPlayer::Ptr ComputerPlayer::make(Trainer trainer) {
    return std::make_unique<ComputerPlayer>(trainer);
}

ComputerPlayer::Ptr ComputerPlayer::make(Asciimon asciimon) {
    Trainer trainer{"WILD ASCIIMON"};
    trainer.addAsciimon(asciimon);
    auto ptr{make(trainer)};
    ptr->isCatchable = true;
    return ptr;
}

void ComputerPlayer::changeAsciimon(const BattlePlayer& target)
{
    auto remaining{ remainingParty() };
    assert(!remaining.empty());
    switchAsciimon(*randomElement(remaining, engine));
}

bool ComputerPlayer::catchable() const {
    return isCatchable;
}