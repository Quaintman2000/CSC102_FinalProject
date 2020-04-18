//declaring libraries and headers
#include "StoryFunctions.h"
#include "CharactersClass.h"
#include <iostream>
#include <string>

//declaring namespace
using namespace std;

void Introduction()
{
	//intro
	cout << "Welcome to Dungeon Quest!\n";
	cout << "An exciting adventure game where you explore a mysterious dungeon in search of gold and glory!\n";
}

string StoryGetName()
{
	string name;
	cout << "Please enter you name\n";
	//takes in the players name for the story
	getline(cin,name);
	//caps the first letter of the name just in case
	name[0] = toupper(name[0]);
	return name;
}

string StoryGetClass()
{
	//ask for desired class
	string answer;
	cout << "\nPlease enter the corresponding number for your class you will like to play as for your adventure.\n";
	cout << "Noble Knight or Keen Rouge\n";
	//gets input
	answer = GetUserInput();
	//checks if input is valid
	if (answer != "NOBLE KNIGHT" && answer != "KEEN ROUGE" && answer != "KNIGHT" && answer != "ROUGE")
	{
		while (answer != "NOBLE KNIGHT" && answer != "KEEN ROUGE" && answer != "KNIGHT" && answer != "ROUGE")
		{
			cout << "invalid input. Please try again.\n";
			cout << "Noble Knight or Keen Rouge\n";
			//gets input
			answer = GetUserInput();
		}
	}
	//change to full name if shortened
	if (answer == "KNIGHT")
	{
		answer = "NOBLE KNIGHT";
	}
	else if (answer == "ROUGE")
	{
		answer = "KEEN ROUGE";
	}

	//return their answer
	return answer;
}

string GetUserInput()
{
	//grabs the string
	string answer;
	getline(cin, answer);

	//make the answer caps to make it easier to read
	for (int i = 0; i < answer.length(); i++)
	{
		answer[i] = toupper(answer[i]);
	}
	//returns the string in caps
	return answer;
}

string PlayGameIntro(string* playerName, string& playerClass)
{
	//return a string of the intro of the game for the narrator to say
	string stuffToSay;
	stuffToSay += "At the height of medieval era and in a far distant, mystical land,\n";
	stuffToSay += "\t an adventurer and " + playerClass + " dubbed " + *playerName + " is in search\n";
	stuffToSay += "\t of gold and glory that will put your name in the history books.\n";
	stuffToSay += "\t During the adventurer's travels, " + *playerName + " over hears a conversation about\n";
	stuffToSay += "\t a dungeon close by filled to the brim with gold. You make your way to the dungeon.\n\n";
	stuffToSay += "\t ...";
	stuffToSay += "\n\n\t You've reached the dungeon entrance and you can here the sounds of spiders within.\n";
	stuffToSay += "\t Do you go in? Enter yes or no.\n";
	return stuffToSay;
}

string DetermineAction(string& playerClass, int& sceneNum, string& playerAnswer, bool& alive, string* playerName)
{
	string stuffToSay;
	//if it's scene 1
	if (sceneNum == 1)
	{
		//if player said yes
		if (playerAnswer == "YES")
		{
			//return what to say
			stuffToSay += "You enter the dungeon but you were immiediately introduced to a giant spider!\n";
			stuffToSay += "\t The spider charges at you! What will you do?\n";
			stuffToSay += "\t Attack, Block, or Dodge?\n";

			return stuffToSay;
		}
		//if player types no
		else if(playerAnswer == "NO")
		{
			//return what to say
			stuffToSay += "You decide its not worth it so you take your leave but, a gaint boulder falls out of no where and smashes you.\n\n";
			stuffToSay += "\t Game over...\n *cough* *cough* Just go inside you pussy! *cough* *cough*\n";

			return stuffToSay;
		}
		//if the player types in an invalid input
		else
		{
			//return what to say
			stuffToSay += "As you sat there and did nothing, a poisonous snake comes by and bites your leg.\n";
			stuffToSay += "\t You keel over and die from the poison...\n\n";
			stuffToSay += "\t Game over... Hint: try putting in a valid input next time!\n";

			//set alive status to false
			alive = false;

			return stuffToSay;
		}
	}
	//if it's scene 2
	else if( sceneNum == 2)
	{
		//if tried to attack
		if (playerAnswer == "ATTACK")
		{
			//return what to say
			stuffToSay += "You tried to swing your weapon but the spider got to you first and you died.\n\n";
			stuffToSay += "\t Game over...\n";

			//set alive status to false
			alive = false;

			return stuffToSay;
		}
		else if (playerAnswer == "BLOCK")
		{
			//if the player is the knight
			if (playerClass == "NOBLE KNIGHT")
			{
				//return what to say
				stuffToSay += "You block the spider's attack with your shield then you swing a fatal counter blow\n";
				stuffToSay += "\t killing the spider. You continue down further the dungeon...\n\n";
				stuffToSay += "\t You reached the end of the dungeon, killing a few more spiders on the way, and it appears to be a large room with a chest on the other side\n";
				stuffToSay += "\t but it's guarded by a giant Oger with a club. It seems to being currently distracted as it's feasting on a donkey carcass...\n";
				stuffToSay += "\t what will you do?\n";
				stuffToSay += "\t Steal or Assassinate?\n";

				return stuffToSay;
			}
			//if the player is the rouge
			else
			{
				//return what to say
				stuffToSay += "You try to block the attack with your tiny knife but failed.\n";
				stuffToSay += "\t The spider mauls you to death.\n\n";
				stuffToSay += "\t Game over... Hint: Try dodging as a " + playerClass + " next time!\n";

				//set alive status to false
				alive = false;

				return stuffToSay;
			}
		}
		else if (playerAnswer == "DODGE")
		{
			//if the player is the knight
			if (playerClass == "NOBLE KNIGHT")
			{
				//return what to say
				stuffToSay += "You try move your fat ass out of the way but you were too slow.\n";
				stuffToSay += "\tThe spider mauls you to death.\n\n";
				stuffToSay += "\tGame over... Hint: Try blocking as a " + playerClass + " next time!\n";

				//set alive status to false
				alive = false;

				return stuffToSay;
			}
			//if the player is the rouge
			else
			{
				//return what to say
				stuffToSay += "You swiftly dodge out of the way of the spiders attack and then you land a critical blow as you stab the back of the spider's head,\n";
				stuffToSay += "\t killing the spider. You continue down further the dungeon...\n\n";
				stuffToSay += "\t You reached the end of the dungeon, killing a few more spiders on the way, and it appears to be a large room with a chest on the other side\n";
				stuffToSay += "\t but it's guarded by a giant Oger with a club. It seems to being currently distracted as it's feasting on a donkey carcass...\n";
				stuffToSay += "\t what will you do?\n";
				stuffToSay += "\t Steal or Assassinate?\n";

				return stuffToSay;
			}
		}
		else
		{
			//return what to say
			stuffToSay += "You sat there doing nothing as the spider jumps onto you and mauls you.\n\n";
			stuffToSay += "\t Game over... Hint: try putting in a valid input next time!\n";

			//set alive status to false
			alive = false;

			return stuffToSay;
		}
	}
	//if it's scene 3
	else if (sceneNum == 3)
	{
		//if player tries to steal
		if (playerAnswer == "STEAL")
		{
			//if the player is the knight
			if (playerClass == "NOBLE KNIGHT")
			{
				//return stuff to say for the narrator
				stuffToSay += "You sheath your sword and pull out a cloth bag to put the gold in. The sound of your armor clinking together and the rustling of gold coins\n";
				stuffToSay += "\t made just enough noise for the oger to hear you and he grabs his club, quickly turns around, and smacks you into wall with the club. Breaking ever bone you had.\n";
				stuffToSay += "\t You slowly bleed out.\n\n Game over...";
				
				//set alive status to dead
				alive = false;

				return stuffToSay;
			}
			//if the player is a rouge
			else
			{
				//return stuff to say for the narrator
				stuffToSay += "silently sneak up to the treasure chest without the oger noticing due to your lack of armor and\n";
				stuffToSay += "\t You grab as much gold as you can carry and quickly sneak back out of the dungeon to live the rest of your days in riches!\n";
				stuffToSay += "\t As the world hear's your story, you earn the title: " + *playerName + " the oger deciever!\n\n";
				stuffToSay += "\t You win! Try playing as the knight next time!\n";
				
				return stuffToSay;
			}
		}
		else if (playerAnswer == "ASSASSINATE")
		{
			//if the player is the knight
			if (playerClass == "NOBLE KNIGHT") 
			{
				//return stuff to say for the narrator
				stuffToSay += "You slowly tip-toe up to the oger. He doesn't notice you still so you grab your sword with both hands and shove it up the ogers back.\n";
				stuffToSay += "\t It pierces the oger's heart and it dies.\n\n";
				stuffToSay += "\t You grab as much gold as you can carry and walk back out of the dungeon to live the rest of your days in riches!\n";
				stuffToSay += "\t As the world hear's your story, you earn the title: " + *playerName + " the oger slayer!\n";
				stuffToSay += "\t You win! Try playing as the rouge next time!\n";

				return stuffToSay;
			}
			//if the player is a rouge
			else
			{
				//return stuff to say for the narrator
				stuffToSay += "You slowly sneak up to the oger and you quickly stab the oger in the back.\n";
				stuffToSay += "\t It doesn't appear to be affective because oger slowly stands up, turns to you, pulls the knife out his back, and gives you a 'what the fuck bro' look.\n";
				stuffToSay += "\t You give a nervous laugh and quickly makes towards the exit. The oger grabs and flings you into the wall, breaking ever bone you had.\n";
				stuffToSay += "\t You slowly bleed out.\n\n Game over...\n";

				//set alive status to dead
				alive = false;

				return stuffToSay;
			}
		}
		else
		{
			//return stuff to say for the narrator
			stuffToSay += "As you sat there and do nothing, the oger notices you and throws his club at you.\n";
			stuffToSay += "\t It was a direct hit and you die from the blow.\n\n Game over... Hint: try putting a valid input next time.\n";
			
			//set alive status to dead
			alive = false;

			return stuffToSay;
		}
	}
}

int& NextScene(int& sceneNum)
{
	// TODO: insert return statement here
	return sceneNum += 1;
}

bool PlayAgainYesOrNo()
{
	//grab user input
	string answer = GetUserInput();
	//if no
	if (answer == "NO")
	{
		return false;
	}
	//if yes
	else
	{
		return true;
	}
}

string AskToPlayAgain(bool& alive)
{
	string stuffToSay;

	if (alive)
	{
		stuffToSay += "Congratulations! You made to the end of the adventure!\n";
		stuffToSay += "\t Would you like to play again?\n";
		stuffToSay += "\t Yes or No?";
	}
	else
	{
		stuffToSay += "Aw man, it seems like you didn't make it...\n";
		stuffToSay += "\t Would you like to play again?\n";
		stuffToSay += "\t Yes or No?";
	}
	return stuffToSay;
}
