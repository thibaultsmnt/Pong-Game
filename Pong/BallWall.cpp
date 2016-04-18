//
//  BallWall.cpp
//  Pong
//
//  Created by Thibault Simonetto on 16/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "BallWall.hpp"
#include "GameConstant.hpp"

void checkBallWall(float *ballPositionY, float *ballSpeedY){
    
    
    if (*ballPositionY <= (BORDER_SIZE+BORDER_MARGIN) && (*ballSpeedY <0)){ //If the ball hit the upper wall AND the ball goes up
        *ballSpeedY *= -1; //inverser la direction
    } else if ( (*ballPositionY + BALL_SIZE) >= (WIN_HEIGHT-BORDER_MARGIN-BORDER_SIZE) && (*ballSpeedY > 0) ) { //If the ball hit the bottom wall AND the ball goes down
        *ballSpeedY *= -1;
    }
    
}