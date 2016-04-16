//
//  DrawRacket.cpp
//  Pong
//
//  Created by Thibault Simonetto on 16/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "DrawRackets.hpp"
#include <SFML/Graphics.hpp>
#include "GameConstant.hpp"

using namespace sf;

void drawRacket(sf::RenderWindow &window, int racket1PositionY, int racket2PositionY){
    
    sf::RectangleShape racket1(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));
    racket1.setPosition(RACKET_1_POSITION_X, racket1PositionY);
    
    sf::RectangleShape racket2(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));
    racket2.setPosition(RACKET_2_POSITION_X, racket2PositionY);

    window.draw(racket1);
    window.draw(racket2);
}