//
//  PlayBall.cpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

//TODO REMOVE QUANDPLUS BESOINS
#include <iostream>

#include <SFML/Graphics.hpp>

#include "PlayBall.hpp"
#include "InitializeBall.hpp"
#include "BallOut.hpp"
#include "BallWall.hpp"
#include "GameConstant.hpp"
#include "RacketPosition.hpp"
#include "DrawScore.hpp"
#include "MoveBall.hpp"
#include "BallRacket.hpp"
#include "ResetGame.hpp"

using namespace sf;


int playBall(sf::RenderWindow &window, sf::Font &font, int winnerOfLastBall, int &scorePlayer1, int &scorePlayer2, int &I2CFile){
    
    sf::Clock clock;
    
    
    float ballPositionX = 0;
    float ballPositionY = 0;
    float ballSpeedX = 0;
    float ballSpeedY = 0;
    
    int potentialWinner = 0;
    float racket1PositionY = 0;
    float racket2PositionY = 0;
    
    
    //draw
    sf::RectangleShape racket1(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));
    sf::RectangleShape racket2(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));
    
    sf::RectangleShape borderUp(sf::Vector2f(WIN_WIDTH, BORDER_SIZE));
    borderUp.setPosition(0, BORDER_MARGIN);
    
    sf::RectangleShape borderDown(sf::Vector2f(WIN_WIDTH, BORDER_SIZE));
    borderDown.setPosition(0, WIN_HEIGHT-BORDER_MARGIN-BORDER_SIZE);
    
    sf::RectangleShape borderMiddle(sf::Vector2f(BORDER_SIZE, WIN_HEIGHT-2*BORDER_MARGIN));
    borderMiddle.setPosition(WIN_WIDTH/2-BORDER_SIZE/2, BORDER_MARGIN);
    
    
    
    sf::RectangleShape ball(sf::Vector2f(BALL_SIZE, BALL_SIZE));
    
    
    sf::Text textScore1;
    sf::Text textScore2;
    
    
    textScore1.setFont(font);
    textScore1.setString(to_sstring(scorePlayer1));
    textScore1.setCharacterSize(CHARACTER_SIZE);
    textScore1.setColor(Color::White);
    float textScore1PositonX = WIN_WIDTH/2 -  textScore1.getLocalBounds().width - SCORE_MARGIN_MIDDLE;
    textScore1.setPosition(textScore1PositonX, SCORE_MARGIN_TOP);
    
    textScore2.setFont(font);
    textScore2.setString(to_sstring(scorePlayer2));
    textScore2.setCharacterSize(CHARACTER_SIZE);
    textScore2.setColor(Color::White);
    float textScore2PositonX = WIN_WIDTH/2 + SCORE_MARGIN_MIDDLE;
    textScore2.setPosition(textScore2PositonX, SCORE_MARGIN_TOP);

    
    
    
    
    // initialize the ball position in function of the winner Last Ball
    initializeBall(winnerOfLastBall, &ballPositionX, &ballPositionY, &ballSpeedX, &ballSpeedY);
    
    while(1 && window.isOpen()) {
        
        sf::Event event;                        //Code qui sert a rien mais si non ca marche pas
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        
        //if ball out return winner
        potentialWinner = isBallOut(ballPositionX, ballPositionY);
        if (potentialWinner){
            return potentialWinner;
        }
        
        //if btnpress return 0 reset
        if (checkResetInput()){
        	resetScore(&scorePlayer1, &scorePlayer2);
        	return 0;
        }
        
        
        //move Ball
        moveBall(&ballPositionX, &ballPositionY, &ballSpeedX, &ballSpeedY, clock);
        ball.setPosition(ballPositionX, ballPositionY);

        //TODO
        
        
        //if ball mur inverse x
        checkBallWall(&ballPositionY, &ballSpeedY);
        
        //get new racket positions
        racketPosition(&racket1PositionY, 1, I2CFile);
        racketPosition(&racket2PositionY, 2, I2CFile);
        
        
        
        //if ball raquette = dark magique pour determiner les nouveau vector
        checkBallRacket1(&racket1PositionY, &ballPositionX, &ballPositionY, &ballSpeedX, &ballSpeedY);
        checkBallRacket2(&racket2PositionY, &ballPositionX, &ballPositionY, &ballSpeedX, &ballSpeedY);
        racket1.setPosition(RACKET_1_POSITION_X, racket1PositionY);
        racket2.setPosition(RACKET_2_POSITION_X, racket2PositionY);


        //TODO
        
        
        //On dessine
        window.clear(Color::Black);
       
        window.draw(borderUp);
        window.draw(borderDown);
        window.draw(borderMiddle);
        
        window.draw(racket1);
        window.draw(racket2);
        
        window.draw(ball);

        window.draw(textScore1);
        window.draw(textScore2);
        window.display();
                
        
    }
    
    return 1;
    
}
