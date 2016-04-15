//
//  ResetGame.cpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "ResetGame.hpp"

void resetScore(int *scorePlayer1, int *scorePlayer2){
    *scorePlayer1 = 0;
    *scorePlayer2 = 0;
}

int isGameFinish(int scorePlayer1, int scorePlayer2){
    
    if (scorePlayer1 >=10){
        return 1;
    } else if (scorePlayer2 >=10) {
        return 2;
    }
    return 0;
}