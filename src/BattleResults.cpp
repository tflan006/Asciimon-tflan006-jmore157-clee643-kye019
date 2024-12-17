#include "../header/BattleResults.hpp"
#include <cassert>

BattleResults::BattleResults(Results results, BattlePlayer::Ptr player)
    : results(results),
    player(std::move(player))
{
   assert(this->player != nullptr);
}

BattleResults::Results BattleResults::getResults() const
{
    return results;
}

std::vector<Asciimon> BattleResults::getBattleParty() const
{
    std::vector<Asciimon> party{ player->getParty() };
    
    for (auto& member : party) {
        member.setHealth(member.getStatistics().getMaxHealth());
    }

    return party;
}

BattlePlayer *BattleResults::getPlayer()
{
    return player.get();
}

const BattlePlayer *BattleResults::getPlayer() const
{
    return player.get();
}
