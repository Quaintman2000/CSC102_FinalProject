//including libraries and header files
#include "CharactersClass.h"
#include "StoryFunctions.h"
#include "PlayerClass.h"
#include <iostream>
#include <string>
#include <istream>
#include <stdio.h>

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
	
	//Play the game until the player determines not to
	bool playAgain = true;
	bool r_playagain = playAgain;
	while (playAgain)
	{
		//Introduction
		Introduction();

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
		bool ended = false;
		//play the game as long as the player is still alive
		while (Player.alive && !ended)
		{
			//get player's answer
			string answer = GetUserInput();
			string r_answer = answer;

			//player says their answer
			Player.Talk(r_answer);

			

			//check if player is still alive and it's not the last scene
			if (Player.alive && r_scene <= 2)
			{
				Narrator.Talk(DetermineAction(r_class, r_scene, r_answer, r_IsAlive, p_name));
				//change it to the next scene
				NextScene(r_scene);
				//narrator talks about next scene
				
			}
			//if not end the game
			else
			{
				//narrator talks about last scene
				Narrator.Talk(DetermineAction(r_class, r_scene, r_answer, r_IsAlive, p_name));
				//stops the loop
				ended = true;
			}
			
		}
		//ask if the player wants to play again
		Narrator.Talk(AskToPlayAgain(r_IsAlive));
		//get answer
		playAgain = PlayAgainYesOrNo();
		//clear the screen
		system("CLS");
	}

	//end the program
	return 0;
}