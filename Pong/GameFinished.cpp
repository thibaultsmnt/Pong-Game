//
// Created by thibault on 26/04/16.
//
#include "GameFinished.hpp"
#include <stdio.h>
#include "DrawScore.hpp"
#include "GameConstant.hpp"
#include "ResetGame.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

void gameFinished(sf::RenderWindow &window, sf::Font &font,int winner){

    sf::Text textWinner;
    sf::Text textReset;

    //Set text textWinner
    textWinner.setString("Player " + to_sstring(winner)+ " win!");
    //Set Properties textWinner
    textWinner.setFont(font);
    textWinner.setCharacterSize(CHARACTER_SIZE);
    textWinner.setColor(Color::White);
    //Set Position textWinner
    float textWinnerPositonX = WIN_WIDTH/2 -  textWinner.getLocalBounds().width;
    float textWinnerPositonY = WIN_HEIGHT/2 - textWinner.getLocalBounds().height - SCORE_MARGIN_MIDDLE;
    textWinner.setPosition(textWinnerPositonX, textWinnerPositonY);

    //Set text textReset
    textReset.setString("Press the button to restart a game");
    //Set Properties textReset
    textReset.setFont(font);
    textReset.setCharacterSize(CHARACTER_SIZE);
    textReset.setColor(Color::White);
    //Set Position textReset
    float textResetPositonX = WIN_WIDTH/2 -  textWinner.getLocalBounds().width;
    float textResetPositonY = WIN_HEIGHT/2  + SCORE_MARGIN_MIDDLE;
    textReset.setPosition(textResetPositonX, textResetPositonY);

    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            // Windows close with the cross
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (checkResetInput()){
            return;
        }
        window.clear();
        window.draw(textWinner);
        window.draw(textReset);
        window.display();
    }
}