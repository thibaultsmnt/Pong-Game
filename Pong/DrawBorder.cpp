//
//  DrawBorder.cpp
//  Pong
//
//  Created by Thibault Simonetto on 16/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "DrawBorder.hpp"
#include <SFML/Graphics.hpp>
#include "GameConstant.hpp"

using namespace sf;

void drawBorder(sf::RenderWindow &window){
    
    sf::RectangleShape borderUp(sf::Vector2f(WIN_WIDTH, BORDER_SIZE));
    borderUp.setPosition(0, BORDER_MARGIN);
    
    sf::RectangleShape borderDown(sf::Vector2f(WIN_WIDTH, BORDER_SIZE));
    borderDown.setPosition(0, WIN_HEIGHT-BORDER_MARGIN-BORDER_SIZE);
    
    sf::RectangleShape borderMiddle(sf::Vector2f(BORDER_SIZE, WIN_HEIGHT-2*BORDER_MARGIN));
    borderMiddle.setPosition(WIN_WIDTH/2-BORDER_SIZE/2, BORDER_MARGIN);
    
    
    window.draw(borderUp);
    window.draw(borderDown);
    window.draw(borderMiddle);
    
}