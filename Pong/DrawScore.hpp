//
//  DrawScore.hpp
//  Pong
//
//  Created by Thibault Simonetto on 17/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#ifndef DrawScore_hpp
#define DrawScore_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include<sstream>

template <typename T> //Magic code from THE Internet to convert int in str cause to_string does not work on raspi
std::string to_sstring(T value);
void drawScore(sf::RenderWindow &window, sf::Font &font, int scorePlayer1, int scorePlayer2);

#endif /* DrawScore_hpp */
