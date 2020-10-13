//
// Created by zennoma on 08.10.2020.
//
#include "unic.h"

bool symmetric (std::string input) {

    for(int i =0; i<input.size()/2; i++) {
        if ( input[i] != input[input.size()-1-i]) {
            return 0;
        }
    }
    return 1;
}
