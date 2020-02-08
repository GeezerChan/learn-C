/*
	Blood, William

	February 7, 2020

	CS A250
	Lab 2
*/

#include "Pokemon.h"
#include <iostream>

// Initializing variables
Pokemon::Pokemon() {
	pokeName = "";
	pokeID = 0;
	pokeType1 = "";
	pokeType2 = "";
}

Pokemon::Pokemon(
	const string& name, int id, const string& type1) {
	pokeName = name;
	pokeID = id;
	pokeType1 = type1;
}

Pokemon::Pokemon(
	const string& name, int id, const string& type1, const string& type2) {
	pokeName = name;
	pokeID = id;
	pokeType1 = type1;
	pokeType2 = type2;
}

string Pokemon::getType1() const { return pokeType1; }
string Pokemon::getType2() const { return pokeType2; }

bool Pokemon::commonType(Pokemon newPokemon) const {
	bool commonType = false;
	if (newPokemon.getType2().empty()) {	// Compares with pure types
		string firstType = newPokemon.getType1();
		if (firstType == pokeType1 || firstType == pokeType2) {
			commonType = true;
		}
	}
	else {									// Comapres with mixed types
		string firstType = newPokemon.getType1();
		if (firstType == pokeType1 || firstType == pokeType2)
			commonType = true;
		string secondType = newPokemon.getType2();
		if (secondType == pokeType1 || secondType == pokeType2)
			commonType = true;
	}
	return commonType;
}

void Pokemon::print() const {
	cout << pokeName << ": "
		<< pokeType1 << " "
		<< pokeType2;
}

Pokemon::~Pokemon() {}