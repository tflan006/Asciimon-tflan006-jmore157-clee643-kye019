#include "../header/AsciimonCodex.hpp"
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h> 
#include <cassert>


using namespace std;



Asciimon AsciimonCodex::generateRandomAsciimon()
{
    srand (time(NULL));
    int numToType = rand()%ELEMETAL_COUNT;
    ElementalType type = NumberToType(numToType);

    StatGenerator statGenerator;
    Statistics randomStats = statGenerator.generateStats();
    
    int health = randomStats.getMaxHealth();
    string name = TypetoName(type);

    Asciimon newAsciimon(name, health, type, 0, randomStats);

    generateMoves(type, newAsciimon);

    asciimonCodex.push_back(newAsciimon);

    return newAsciimon;
}

Asciimon AsciimonCodex::generateAsciimon(ElementalType type)
{
    StatGenerator statGenerator;
    Statistics randomStats = statGenerator.generateStats();

    int health = randomStats.getMaxHealth();
    string name = TypetoName(type);

    Asciimon newAsciimon(name, health, type, 0, randomStats);

    generateMoves(type, newAsciimon);

    asciimonCodex.push_back(newAsciimon);

    return newAsciimon;

}

Asciimon AsciimonCodex::generateAsciimon(string name)
{
    StatGenerator statGenerator;
    Statistics randomStats = statGenerator.generateStats();

    int health = randomStats.getMaxHealth();
    ElementalType type = NameToType(name);

    Asciimon newAsciimon(name, health, type, 0, randomStats);

    generateMoves(type, newAsciimon);

    asciimonCodex.push_back(newAsciimon);

    return newAsciimon;
}



string AsciimonCodex::TypetoName(ElementalType type)
{
    if(type == FIRE)
    {
        return "Charmander";
    }
    else if(type == WATER)
    {
        return "Squirtle";
    }
    else if(type == GRASS)
    {
        return "Bulbasaur";
    }
    else if(type == GROUND)
    {
        return "Diglet";
    }
    else if(type == ELECTRIC)
    {
        return "Pikachu";
    }
    else if(type == ICE)
    {
        return "Articuno";
    }
    else if(type == DRAGON)
    {
        return "Dragonite";
    }
    else if(type == DARK)
    {
        return "Meowth";
    }
        return "Snorlax";
    
        
    
}

ElementalType AsciimonCodex::NameToType(string name)
{
    if(name == "Charmander")
    {
        return FIRE;
    }
    else if(name == "Squirtle")
    {
        return WATER;
    }
    else if(name == "Bulbasaur")
    {
        return GRASS;
    }
    else if(name == "Diglet")
    {
        return GROUND;
    }
    else if(name == "Pikachu")
    {
        return ELECTRIC;
    }
    else if(name == "Articuno")
    {
        return ICE;
    }
    else if(name == "Dragonite")
    {
        return DRAGON;
    }
    else if(name == "Meowth")
    {
        return DARK;
    }
        return LIGHT;
}

void AsciimonCodex::generateMoves(ElementalType type, Asciimon& asciimon)
{
    if(type == FIRE)
    {
        // Fire moves
        Move flameBurst("Flame Burst", "A fiery blast that scorches everything in its path.", 0.85, 60);
        Move inferno("Inferno", "Engulfs the opponent in a massive firestorm.", 0.5, 100);
        Move heatWave("Heat Wave", "Creates a wave of intense heat that may burn the opponent.", 0.8, 70);
        asciimon.addMove(flameBurst);
        asciimon.addMove(inferno);
        asciimon.addMove(heatWave);
    }
    else if(type == WATER)
    {
        // Water moves
        Move aquaJet("Aqua Jet", "Strikes the opponent with a high-speed water rush.", 0.9, 40);
        Move tidalWave("Tidal Wave", "Summons a massive wave to crash down on the opponent.", 0.7, 90);
        Move bubbleBeam("Bubble Beam", "Fires a stream of bubbles that can lower the opponent's speed.", 1.0, 45);
        asciimon.addMove(aquaJet);
        asciimon.addMove(tidalWave);
        asciimon.addMove(bubbleBeam);    
    }

    else if(type == GRASS)
    {
        // Grass moves
        Move leafBlade("Leaf Blade", "Slices the opponent with razor-sharp leaves.", 0.95, 55);
        Move solarBeam("Solar Beam", "Absorbs sunlight and unleashes a powerful beam.", 0.7, 100);
        Move vineWhip("Vine Whip", "Strikes the opponent with strong, whip-like vines.", 1.0, 45);
        asciimon.addMove(leafBlade);
        asciimon.addMove(solarBeam);
        asciimon.addMove(vineWhip);     
    }
    else if(type == GROUND)
    {
        Move earthquake("Earthquake", "Shakes the ground violently, damaging all opponents.", 0.8, 75);
        Move mudSlap("Mud Slap", "Hurls mud at the opponent, reducing their accuracy.", 1.0, 20);
        Move sandstorm("Sandstorm", "Summons a fierce sandstorm that damages all opponents over time.", 1.0, 40);
        asciimon.addMove(earthquake);
        asciimon.addMove(mudSlap);
        asciimon.addMove(sandstorm);   
    }
    else if(type == ELECTRIC)
    {
        // Electric moves
        Move thunderShock("Thunder Shock", "Zaps the opponent with a jolt of electricity.", 0.95, 40);
        Move lightningStrike("Lightning Strike", "Summons a powerful lightning bolt from the sky.", 0.7, 90);
        Move electroBall("Electro Ball", "Hurls a ball of electricity that gets stronger the faster the user is compared to the opponent.", 1.0, 40);
        asciimon.addMove(thunderShock);
        asciimon.addMove(lightningStrike);
        asciimon.addMove(electroBall);  
    }
    else if(type == ICE)
    {
        Move frostBite("Frost Bite", "Bites the opponent with icy fangs, may freeze the target.", 0.85, 50);
        Move blizzard("Blizzard", "Unleashes a blizzard that hits all opponents.", 0.6, 95);
        Move iceShard("Ice Shard", "Fires shards of ice at the opponent, always strikes first.", 1.0, 40);
        asciimon.addMove(frostBite);
        asciimon.addMove(blizzard);
        asciimon.addMove(iceShard);  
    }
    else if(type == DRAGON)
    {
        // Dragon moves
        Move dragonClaw("Dragon Claw", "Slashes the opponent with sharp, dragon-like claws.", 0.9, 60);
        Move dragonBreath("Dragon Breath", "Breathes a stream of dragon fire, may paralyze the opponent.", 0.8, 70);
        Move dragonTail("Dragon Tail", "Whips the opponent with a powerful tail, can force them to switch out.", 0.9, 60);
        asciimon.addMove(dragonClaw);
        asciimon.addMove(dragonBreath);
        asciimon.addMove(dragonTail);
    }
    else if(type == DARK)
    {
        // Dark moves
        Move shadowSneak("Shadow Sneak", "Attacks from the shadows, striking first.", 1.0, 40);
        Move nightSlash("Night Slash", "Slashes the opponent with a blade of darkness.", 0.85, 70);
        Move darkPulse("Dark Pulse", "Emits a dark shockwave that may cause the opponent to flinch.", 0.9, 80);
        asciimon.addMove(shadowSneak);
        asciimon.addMove(nightSlash);
        asciimon.addMove(darkPulse);
    }
    else
    {
        // Light moves
        Move radiantBeam("Radiant Beam", "Fires a beam of pure light at the opponent.", 0.9, 50);
        Move holyNova("Holy Nova", "Releases a burst of holy energy that damages all opponents.", 0.7, 80);
        Move blindingFlash("Blinding Flash", "Emits a blinding light that reduces the opponent's accuracy.", 1.0, 20);
        asciimon.addMove(radiantBeam);
        asciimon.addMove(holyNova);
        asciimon.addMove(blindingFlash);
    }
}

ElementalType AsciimonCodex::NumberToType(int numToType)
{
    ElementalType type{static_cast<ElementalType>(numToType)};
    assert(numToType >= 0 && numToType < ELEMETAL_COUNT);
    return type;
}