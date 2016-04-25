//
//  PlayBall.hpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#ifndef PlayBall_hpp
#define PlayBall_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

int playBall(sf::RenderWindow &window, sf::Font &font, int winnerOfLastBall, int &scorePlayer1, int &scorePlayer2, int &I2CFile);

#endif /* PlayBall_hpp */
