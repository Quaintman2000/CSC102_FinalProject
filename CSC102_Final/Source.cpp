//including libraries and header files
#include "CharactersClass.h"
#include "StoryFunctions.h"
#include "PlayerClass.h"
#include <iostream>
#include <string>
#include <istream>

//declaring namespaces
using namespace std;

int main()
{
	//Declaring classes
	PlayerClass Player;
	bool& r_IsAlive = Player.alive;
	CharactersClass Narrator;
	//setting the name of narrator to narrator
	Narrator.SetName("Narrator");
	
	//Introduction
	Introduction();

	//Play the game until the player determines not to
	bool playAgain = true;
	bool r_playagain = playAgain;
	while (playAgain)
	{
		//set player to be alive
		r_IsAlive = true;
		//Grab player's name
		Player.SetName(StoryGetName());
		string name = Player.GetName();
		string* p_name = &name;

		//Determine player's desired class
		Player.PlayerClass = StoryGetClass();
		string& r_class = Player.PlayerClass;
		
		//intro into the game
		Narrator.Talk(PlayGameIntro(p_name, r_class));
		
		//set scene to the first one
		int scene = 1;
		int& r_scene = scene;
		//play the game as long as the player is still alive
		while (Player.alive)
		{
			//get player's answer
			string answer = GetUserInput();
			string r_answer = answer;

			//player says their answer
			Player.Talk(r_answer);

			Narrator.Talk(DetermineAction(r_class, r_scene, r_answer, r_IsAlive,p_name));

			//check if player is still alive and it's not the last scene
			if (Player.alive && r_scene < 3)
			{
				//change it to the next scene
				NextScene(r_scene);
			}
			else 
			{
				break;
			}
			//if not end the game
		}
		//ask if the player wants to play again
		Narrator.Talk(AskToPlayAgain(r_IsAlive));
		//get answer
		playAgain = PlayAgainYesOrNo();
	}

	//end the program
	return 0;
}