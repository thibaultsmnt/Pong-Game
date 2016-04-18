//
//  MoveBall.hpp
//  Pong
//
//  Created by Thibault Simonetto on 17/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#ifndef MoveBall_hpp
#define MoveBall_hpp

#include <SFML/System.hpp>
#include <stdio.h>

void moveBall(float *ballPositionX, float *ballPositionY, float *ballSpeedX, float *ballSpeedY, sf::Clock &clock);

#endif /* MoveBall_hpp */
