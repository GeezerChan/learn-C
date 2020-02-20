/*
	(name header)
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
public:
	Pokemon();
	Pokemon(const std::string& newName, int newNumber,
		const std::string& newType1);
	Pokemon(const std::string& newName, int newNumber,
		const std::string& newType1, const std::string& newType2);
	
	std::string  getType1() const;
	std::string  getType2() const;

	bool commonType(const Pokemon& otherPokemon) const;

	void print() const;

	~Pokemon();

private:
	std::string name;
	int number;
	std::string type1;
	std::string type2;
};

#endif 
