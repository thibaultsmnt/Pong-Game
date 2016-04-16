//
//  DrawBall.cpp
//  Pong
//
//  Created by Thibault Simonetto on 16/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "DrawBall.hpp"
#include "GameConstant.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

void drawBall(sf::RenderWindow &window, int ballPositionX, int ballPositionY){
    
    sf::RectangleShape ball(sf::Vector2f(BALL_SIZE, BALL_SIZE));
    ball.setPosition(ballPositionX, ballPositionY);

    window.draw(ball);
    
    
}