//
//  PlayGame.cpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "PlayGame.hpp"
#include "ResetGame.hpp"
#include "PlayBall.hpp"
#include "ScoreManagement.hpp"

void playGame(){
    
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    int continuer = 1;
    int winnerOfTheBall = 0;
    
    while(continuer){
        
        winnerOfTheBall = playBall(winnerOfTheBall, scorePlayer1, scorePlayer2);
        updateScore(winnerOfTheBall, &scorePlayer1, &scorePlayer2);
        
        int gameWinner = isGameFinish(scorePlayer1, scorePlayer2);
        if(gameWinner){
            continuer = 0;
        }

        
    }
    
    
}