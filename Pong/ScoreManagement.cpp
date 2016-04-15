//
//  ScoreManagement.cpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "ScoreManagement.hpp"

void updateScore(int winnerOfTheBall, int *scorePlayer1, int *scorePlayer2){
    
    if (winnerOfTheBall == 1){
        *scorePlayer1 +=1;
    } else if (winnerOfTheBall == 2){
        *scorePlayer2 +=1;
    }
}
