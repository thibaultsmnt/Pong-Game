//
//  DrawScore.cpp
//  Pong
//
//  Created by Thibault Simonetto on 17/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "DrawScore.hpp"
#include <SFML/Graphics.hpp>
#include "GameConstant.hpp"

using namespace sf;
using namespace std;

void drawScore(sf::RenderWindow &window, sf::Font &font, int scorePlayer1, int scorePlayer2){
    
    sf::Text textScore1;
    sf::Text textScore2;
    
    
    textScore1.setFont(font);
    textScore1.setString(to_string(scorePlayer1));
    textScore1.setCharacterSize(CHARACTER_SIZE);
    textScore1.setColor(Color::White);
    float textScore1PositonX = WIN_WIDTH/2 -  textScore1.getLocalBounds().width - SCORE_MARGIN_MIDDLE;
    textScore1.setPosition(textScore1PositonX, SCORE_MARGIN_TOP);
    
    textScore2.setFont(font);
    textScore2.setString(to_string(scorePlayer2));
    textScore2.setCharacterSize(CHARACTER_SIZE);
    textScore2.setColor(Color::White);
    float textScore2PositonX = WIN_WIDTH/2 + SCORE_MARGIN_MIDDLE;
    textScore2.setPosition(textScore2PositonX, SCORE_MARGIN_TOP);
    
    
    window.draw(textScore1);
    window.draw(textScore2);
    
    return;
    
}