#include <iostream>
#include "Dictionary.h"

using namespace std ;

int calculatePoints(string word) {
    int length = word.length();

    if (length >= 3) {
        if (length == 3) {
            return 100;
        } else if (length == 4) {
            return 400;
        } else if (length == 5) {
            return 800;
        } else if (length >= 6) {
            return (400 * length) - 1000;
        }
    }

    // Return 0 for words with length less than 3
    return 0;
}

void promptAndCalculatePoints() {
    Dictionary dictionary;
    std::string word;

    std::cout << "Enter a word: ";
    std::cin >> word;

    std::transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c) { return std::tolower(c); });

    if (dictionary.contains(word)) {
        int points = calculatePoints(word);
        std::cout << "Points: " << points << std::endl;
    } else {
        std::cout << "Word not found in the dictionary." << std::endl;
    }
}