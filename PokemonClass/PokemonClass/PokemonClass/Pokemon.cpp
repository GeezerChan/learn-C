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
	string newType1 = newPokemon.getType1();
	string newType2 = newPokemon.getType2();

	bool isSingleType =				  // Prioritizes comparing single types
		newType1 == pokeType1 || newType1 == pokeType2 ?
		true : false;
	if (newType2.empty())			  // Immediately returns result when
		 return isSingleType;		  // single type detected
	else {								
		if (isSingleType)			  // Compares both single types & 
			return true;			  // dual types
		bool isDualType =
			newType2 == pokeType1 || newType2 == pokeType2 ?
			true : false;
		return isDualType;
	}
}

void Pokemon::print() const {
	cout << pokeName << ": "
		<< pokeType1 << " "
		<< pokeType2;
}

Pokemon::~Pokemon() {}