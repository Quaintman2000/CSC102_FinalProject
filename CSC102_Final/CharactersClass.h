#pragma once
//declaring libraries
#include <string>

//declaring namespace;
using namespace std;

//Base Class
class CharactersClass
{
public:
	void Talk(string stuffToSay);
	void SetName(string name);
	string GetName();
private:
	string Name;
};



