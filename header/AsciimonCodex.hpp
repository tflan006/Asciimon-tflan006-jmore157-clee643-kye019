#ifndef __ASCIIMONCODEX_HPP
#define __ASCIIMONCODEX_HPP

#include <string>
#include <vector>
#include "../header/Asciimon.hpp"
#include "../header/StatGenerator.hpp"
#include "../header/Move.hpp"



using namespace std;

class AsciimonCodex{
private:
vector<Asciimon> asciimonCodex;


public:
Asciimon generateRandomAsciimon();
Asciimon generateAsciimon(ElementalType type);
Asciimon generateAsciimon(string name);
string TypetoName(ElementalType);
ElementalType NumberToType(int);
private:
ElementalType NameToType(string);
void generateMoves(ElementalType, Asciimon&);


};

#endif
