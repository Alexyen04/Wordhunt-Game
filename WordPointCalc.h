#ifndef WORDPOINTCALC_H
#define WORDPOINTCALC_H
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
#endif