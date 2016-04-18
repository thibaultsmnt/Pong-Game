//
//  BallRacket.hpp
//  Pong
//
//  Created by Thibault Simonetto on 17/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#ifndef BallRacket_hpp
#define BallRacket_hpp

#include <stdio.h>



void checkBallRacket1(float *racketPositionY, float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY);
void checkBallRacket2(float *racketPositionY, float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY);
float getRelativePosition(float racketPositionY, float ballPositionY);
void setAngle(float relativeBallPosition, float *ballSpeedX, float *ballSpeedY);
void setSpeed(float relativeBallPosition, float *ballSpeedX, float *ballSpeedY);



#endif /* BallRacket_hpp */
