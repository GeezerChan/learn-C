/*
	Blood, William

	February 7, 2020

	CS A250
	Lab 2
*/

#ifndef POKEMON_H
#define POKEMON_H	

#include <string>
using namespace std;

class Pokemon {
public:
	Pokemon();
	Pokemon(const string& name, int id, const string& type1);
	Pokemon(const string& name, int id, const string& type1, const string& type2);

	string getType1() const;
	string getType2() const;

	/**
	 * Returns true if at least one type is the same.
	 *
	 * @param newPokemon object contains name, type and id.
	 * @see getType1()
	 * @see getType2()
	 * @see Pokemon();
	 * @see ~Pokemon();
	 * @return bool
	 */
	bool commonType(Pokemon newPokemon) const;
	/**
	 *
	 *
	*/
	void print() const;

	~Pokemon();

private:
	int pokeID;
	string pokeName;
	string pokeType1;
	string pokeType2;
};

#endif // !POKEMON_H
