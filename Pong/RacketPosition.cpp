//
//  RacketPosition.cpp
//  Pong
//
//  Created by Thibault Simonetto on 16/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "RacketPosition.hpp"
#include "GameConstant.hpp"
#include "PlayerInput.hpp"

void racketPosition(float *racketPositionY, int racketNumber, int &I2CFile){
    
    float pourcentagePosition =  getPlayerInput(racketNumber-1, &I2CFile); //demander a la fonction potentiomettre
    
    *racketPositionY = RACKET_MIN_POSITION_Y + (( RACKET_MAX_POSITION_Y - RACKET_MIN_POSITION_Y)*pourcentagePosition/100);
    
}