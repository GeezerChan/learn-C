/*
	(name header)
*/

#include "Pokemon.h"

#include <iostream>
using namespace std;

Pokemon::Pokemon() 
{
	number = 0;
}

Pokemon::Pokemon(const string& newName, int newNumber,
	const string& newType1)
{
	name = newName;
	number = newNumber;
	type1 = newType1;
}

Pokemon::Pokemon(const string& newName, int newNumber,
	const string& newType1, const string& newType2)
{
	name = newName;
	number = newNumber;
	type1 = newType1;
	type2 = newType2;
}

string Pokemon::getType1() const
{
	return type1;
}

string Pokemon::getType2() const
{
	return type2;
}

bool Pokemon::commonType(const Pokemon& otherPokemon) const
{
	// Assume that there is at least one type.
		
	return (type1 == otherPokemon.type1 ||
		type1 == otherPokemon.type2 ||
		type2 == otherPokemon.type1 ||
		(type2 == otherPokemon.type2 && type2 != ""));
}

void Pokemon::print() const
{
	cout << name << ": " << type1 << " " << type2;
}

Pokemon::~Pokemon() {}