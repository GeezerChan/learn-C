/*
	Blood, William

	February 7, 2020

	CS A250
	Lab 2
*/

#include "Pokemon.h"
#include <iostream>

// Initializing constructor variables
Pokemon::Pokemon() {
	pokeName = "";
	pokeID = 0;
	pokeType1 = "";
	pokeType2 = "";
}

Pokemon::Pokemon(
	const string& name, int id,
	const string& type1) {
	pokeName = name;
	pokeID = id;
	pokeType1 = type1;
}

Pokemon::Pokemon(
	const string& name, int id, 
	const string& type1, 
	const string& type2) {
	pokeName = name;
	pokeID = id;
	pokeType1 = type1;
	pokeType2 = type2;
}

string Pokemon::getType1() const { return pokeType1; }
string Pokemon::getType2() const { return pokeType2; }

bool Pokemon::commonType(Pokemon newPokemon) const {
	string newType1 = newPokemon.getType1();	
	string newType2 = newPokemon.getType2();
	bool isSingleType =					// Validates common single types
		   newType1 == pokeType1
		|| newType1 == pokeType2
		?  true : false;	
	if (newType2.empty())				// Returns result immediately
		return isSingleType;			// when single type is found.	
	return isSingleType					// Otherwise checks for
		|| newType2 == pokeType1		// common dual types.
		|| newType2 == pokeType2
		?  true : false;
}

void Pokemon::print() const {
	cout << pokeName << ": "
		<< pokeType1 << " "
		<< pokeType2;
}

Pokemon::~Pokemon() {}