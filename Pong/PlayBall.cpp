//
//  PlayBall.cpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "PlayBall.hpp"
#include "BallOut.hpp"
#include "BallWall.hpp"

int playBall(int winnerOfLastBall, int scorePlayer1, int scorePlayer2){
    
    int positionRacket1 = 0;
    int positionRacket2 = 0;
    int ballPositionX = 0;
    int ballPositionY = 0;
    int ballSpeedX = 0;
    int ballSpeedY = 0;
    int potentialWinner = 0;
    
    // initialize the ball position in function of the winner Last Ball
    
    while(1) {
        
        
        
        //if ball out return winner
        potentialWinner = isBallOut(ballPositionX, ballPositionY);
        if (potentialWinner){
            return potentialWinner;
        }
        
        //if btnpress return 0 reset
        
        
        //if ball mur inverse x
        checkBallWall(&ballPositionY, &ballSpeedY);
        
        
        
        //if ball raquette = dark magique pour determiner les nouveau vector
        
        //get position raquette
        //draw all this shit
        
        
        
    }
    
    
    
    return 1;
    
    
}