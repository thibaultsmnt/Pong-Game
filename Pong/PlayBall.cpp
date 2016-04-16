//
//  PlayBall.cpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include <SFML/Graphics.hpp>

#include "PlayBall.hpp"
#include "InitializeBall.hpp"
#include "BallOut.hpp"
#include "BallWall.hpp"
#include "GameConstant.hpp"
#include "RacketPosition.hpp"
#include "DrawBorder.hpp"
#include "DrawRackets.hpp"
#include "DrawBall.hpp"

using namespace sf;

int playBall(RenderWindow &window, int winnerOfLastBall, int scorePlayer1, int scorePlayer2){
    
    int positionRacket1 = 0;
    int positionRacket2 = 0;
    
    int ballPositionX = 0;
    int ballPositionY = 0;
    int ballSpeedX = 0;
    int ballSpeedY = 0;
    
    int potentialWinner = 0;
    int racket1PositionY = 0;
    int racket2PositionY = 0;
    
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
        //TODO
        
        //if ball mur inverse x
        checkBallWall(&ballPositionY, &ballSpeedY);
        
        
        
        //if ball raquette = dark magique pour determiner les nouveau vector
        //TODO
        
        
        //get new racket positions
        racketPosition(&racket1PositionY, 1);
        racketPosition(&racket2PositionY, 2);
        
        //On dessine
        window.clear(Color::Black);
        drawBorder(window);
        drawRacket(window, racket1PositionY, racket2PositionY);
        drawBall(window, ballPositionX, ballPositionY);
        window.display();
        
        
        
    }
    
    
    
    return 1;
    
    
}