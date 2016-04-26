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
    
    //If the ball is in the horizontal field
    if (((*ballPositionX - RACKET_1_POSITION_X) < BALL_SIZE) && ((*ballPositionX - RACKET_1_POSITION_X) > 0)){

        //If the racket is in front of the ball
        if ( (*racketPositionY <  (*ballPositionY+BALL_SIZE/2)) && ((*ballPositionY+BALL_SIZE/2)) < (*racketPositionY + RACKET_HEIGHT)){

            //Get the relative position of the ball compare to the racket from -1 to 1
            float relativeBallPosition = getRelativePosition(*racketPositionY, *ballPositionY);
            //Set the angle in function of the relative position
            setAngle(relativeBallPosition, ballSpeedX, ballSpeedY);
            //Apply a speed coefficient in function of the relative position
            setSpeed(relativeBallPosition, ballSpeedX, ballSpeedY);
            
        }
        
        
    }
}

void checkBallRacket2(float *racketPositionY, float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY){

    //If the ball is in the horizontal field
    if (((*ballPositionX - RACKET_2_POSITION_X) > -BALL_SIZE) && ((*ballPositionX - RACKET_2_POSITION_X) < 0)){

        //If the racket is in front of the ball
        if ( (*racketPositionY <  (*ballPositionY+BALL_SIZE/2)) && ((*ballPositionY+BALL_SIZE/2)) < (*racketPositionY + RACKET_HEIGHT)){

            //Get the relative position of the ball compare to the racket from -1 to 1
            float relativeBallPosition = getRelativePosition(*racketPositionY, *ballPositionY);
            //Set the angle in function of the relative position
            setAngle(relativeBallPosition, ballSpeedX, ballSpeedY);
            //Apply a speed coefficient in function of the relative position
            setSpeed(relativeBallPosition, ballSpeedX, ballSpeedY);
            //Inverse the X vector because the same function but the other direction in the game
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

    //Pourcentage of the sinus of the maximum angle for Y vector
    *ballSpeedY = relativeBallPosition * sin(MAX_ANGLE);
    //Vector X in function of the vector Y to have the good angle
    *ballSpeedX = cos(asin(*ballSpeedY));
}

void setSpeed(float relativeBallPosition, float *ballSpeedX, float *ballSpeedY){

    //Apply a coefficient to the vector to set the speed
    float factor = exp(1.1 * fabs(relativeBallPosition));
    *ballSpeedX = *ballSpeedX * factor * BALL_SPEED_UNITY;
    *ballSpeedY = *ballSpeedY * factor * BALL_SPEED_UNITY;
    
}
