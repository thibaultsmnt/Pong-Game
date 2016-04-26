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

    //set a clock
    sf::Clock clock;
    
    //ball attribute
    float ballPositionX = 0;
    float ballPositionY = 0;
    float ballSpeedX = 0;
    float ballSpeedY = 0;

    //potential winner
    int potentialWinner = 0;

    //racket attribute
    float racket1PositionY = 0;
    float racket2PositionY = 0;
    
    
    //Create object racket
    sf::RectangleShape racket1(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));
    sf::RectangleShape racket2(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));

    //Create border and set their position
    sf::RectangleShape borderUp(sf::Vector2f(WIN_WIDTH, BORDER_SIZE));
    borderUp.setPosition(0, BORDER_MARGIN);
    
    sf::RectangleShape borderDown(sf::Vector2f(WIN_WIDTH, BORDER_SIZE));
    borderDown.setPosition(0, WIN_HEIGHT-BORDER_MARGIN-BORDER_SIZE);
    
    sf::RectangleShape borderMiddle(sf::Vector2f(BORDER_SIZE, WIN_HEIGHT-2*BORDER_MARGIN));
    borderMiddle.setPosition(WIN_WIDTH/2-BORDER_SIZE/2, BORDER_MARGIN);
    
    
    //Create the ball object
    sf::RectangleShape ball(sf::Vector2f(BALL_SIZE, BALL_SIZE));
    
    //Create and set the text object for the score
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
    
    while(window.isOpen()) {

        //Event manager : Necessary for SFML
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Windows close with the cross
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        
        //Check if the ball is out and return the winner
        potentialWinner = isBallOut(ballPositionX, ballPositionY);
        if (potentialWinner){
            return potentialWinner;
        }
        
        //Check if the button reset is pressed
        if (checkResetInput()){
        	resetScore(&scorePlayer1, &scorePlayer2);
        	return 0;
        }
        
        
        //Move Ball
        moveBall(&ballPositionX, &ballPositionY, &ballSpeedX, &ballSpeedY, clock);
        ball.setPosition(ballPositionX, ballPositionY);

        
        
        //Check if the ball hit the wall
        checkBallWall(&ballPositionY, &ballSpeedY);
        
        //Get new racket positions
        racketPosition(&racket1PositionY, 1, I2CFile);
        racketPosition(&racket2PositionY, 2, I2CFile);
        racket1.setPosition(RACKET_1_POSITION_X, racket1PositionY);
        racket2.setPosition(RACKET_2_POSITION_X, racket2PositionY);
        
        
        //Check if the ball hit the racket and apply new vector
        checkBallRacket1(&racket1PositionY, &ballPositionX, &ballPositionY, &ballSpeedX, &ballSpeedY);
        checkBallRacket2(&racket2PositionY, &ballPositionX, &ballPositionY, &ballSpeedX, &ballSpeedY);


        
        
        //Draw all our object
        window.clear(Color::Black);

        window.draw(borderUp);
        window.draw(borderDown);
        window.draw(borderMiddle);

        window.draw(racket1);
        window.draw(racket2);

        window.draw(textScore1);
        window.draw(textScore2);

        window.draw(ball);
        window.display();
                
        
    }
    
    return 1;
    
}
