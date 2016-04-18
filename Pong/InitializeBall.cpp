//
//  InitializeBall.cpp
//  Pong
//
//  Created by Thibault Simonetto on 16/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//
#include <stdlib.h>
#include <ctime> //Ne pas oublier d'inclure le fichier time.h
#include "InitializeBall.hpp"
#include "GameConstant.hpp"

void initializeBall(int lastWinner, float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY){
    
    *ballPositionY = INITIAL_BALL_POSITION_Y;
    *ballSpeedX = INITIAL_BALL_SPEED_X;
    *ballSpeedY = INITIAL_BALL_SPEED_Y;
    
    if (lastWinner == 0){ //If there is no last winner, we choose one randomly
        srand(time(NULL));
        lastWinner = rand()%2 + 1;

    }
    
    if (lastWinner == 1 ) {
        *ballPositionX = WIN_WIDTH/2 - BALL_SIZE/2 - INITIAL_BALL_POSITION_X;
        *ballSpeedX *= -1;

    } else if (lastWinner == 2){
        *ballPositionX = WIN_WIDTH/2 - BALL_SIZE/2 + INITIAL_BALL_POSITION_X;
    }
    
    
}
