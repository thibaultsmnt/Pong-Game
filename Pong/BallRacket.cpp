//
//  BallRacket.cpp
//  Pong
//
//  Created by Thibault Simonetto on 17/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include <cmath>
#include "GameConstant.hpp"

#include "BallRacket.hpp"


void checkBallRacket1(float *racketPositionY, float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY){
    
    
    if (((*ballPositionX - RACKET_1_POSITION_X) < BALL_SIZE) && ((*ballPositionX - RACKET_1_POSITION_X) > 0)){

        if ( (*racketPositionY <  (*ballPositionY+BALL_SIZE/2)) && ((*ballPositionY+BALL_SIZE/2)) < (*racketPositionY + RACKET_HEIGHT)){
            
            
            float relativeBallPosition = getRelativePosition(*racketPositionY, *ballPositionY);
            setAngle(relativeBallPosition, ballSpeedX, ballSpeedY);
            setSpeed(relativeBallPosition, ballSpeedX, ballSpeedY);
            
        }
        
        
    }
}

void checkBallRacket2(float *racketPositionY, float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY){
    
    
    if (((*ballPositionX - RACKET_2_POSITION_X) > -BALL_SIZE) && ((*ballPositionX - RACKET_2_POSITION_X) < 0)){
        
        if ( (*racketPositionY <  (*ballPositionY+BALL_SIZE/2)) && ((*ballPositionY+BALL_SIZE/2)) < (*racketPositionY + RACKET_HEIGHT)){
            
            
            float relativeBallPosition = getRelativePosition(*racketPositionY, *ballPositionY);
            setAngle(relativeBallPosition, ballSpeedX, ballSpeedY);
            setSpeed(relativeBallPosition, ballSpeedX, ballSpeedY);
            *ballSpeedX *= -1; //invertion
        }
        
        
    }
}

float getRelativePosition(float racketPositionY, float ballPositionY){
    
    float centerBall =  ballPositionY + BALL_SIZE/2;
    float centerRacket = racketPositionY + RACKET_HEIGHT/2;
    float relativeBallPosition = (centerRacket-centerBall)/(RACKET_HEIGHT/2);
    return -1*relativeBallPosition; //-1 otherwise wrong way
    
}

void setAngle(float relativeBallPosition, float *ballSpeedX, float *ballSpeedY){
    
    *ballSpeedY = relativeBallPosition * sin(MAX_ANGLE);
    *ballSpeedX = cos(asin(*ballSpeedY));
}

void setSpeed(float relativeBallPosition, float *ballSpeedX, float *ballSpeedY){
    
    float factor = exp(1.1 * fabs(relativeBallPosition));
    *ballSpeedX = *ballSpeedX * factor * BALL_SPEED_UNITY;
    *ballSpeedY = *ballSpeedY * factor * BALL_SPEED_UNITY;
    
}
