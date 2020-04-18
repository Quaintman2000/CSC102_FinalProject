#pragma once
#include <string>

using namespace std;

void Introduction();

string StoryGetName();
string StoryGetClass();
string GetUserInput();
string PlayGameIntro(string* playerName, string& playerClass);
string DetermineAction(string& playerClass, int& sceneNum, string& playerAnswer, bool& alive, string* playerName);
string AskToPlayAgain(bool& alive);

int& NextScene(int& sceneNum);

bool PlayAgainYesOrNo();

