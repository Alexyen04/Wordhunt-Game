#include "ScoreboardScreen.h"
#include "Dictionary.h"

std::vector <std::string> ScoreBoardScreen::getValidWords(std::vector <std::string> v){ 
    Dictionary dict;
    v.erase(std::remove_if(v.begin(), v.end(), [](const std::string& word) {
        return !(dict.contains(word));
    }), v.end());
}