//
//  MoveBall.cpp
//  Pong
//
//  Created by Thibault Simonetto on 17/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//
#include <SFML/System.hpp>

#include "MoveBall.hpp"

void moveBall(float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY, sf::Clock &clock){
    
    float sec = clock.restart().asSeconds();
    *ballPositionX = (*ballPositionX + *ballSpeedX*sec);
    *ballPositionY = (*ballPositionY + *ballSpeedY*sec);
    //printf("%f\n",  sec);    
    
}
