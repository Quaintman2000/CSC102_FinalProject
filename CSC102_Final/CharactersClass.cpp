//declaring libraries
#include "CharactersClass.h"
#include <string>
#include <iostream>

//declaring namespace;
using namespace std;


void CharactersClass::Talk(string stuffToSay)
{
	cout << endl << GetName() << ": " << stuffToSay << endl;
}

void CharactersClass::SetName(string name)
{
	Name = name;
}

string CharactersClass::GetName()
{
	return Name;
}


