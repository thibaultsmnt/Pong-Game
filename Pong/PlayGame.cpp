//
//  PlayGame.cpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "GameConstant.hpp"
#include "PlayGame.hpp"
#include "ResetGame.hpp"
#include "PlayBall.hpp"
#include "ScoreManagement.hpp"
#include <SFML/Graphics.hpp>

void playGame(){
    
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "My window");
    
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    int continuer = 1;
    int winnerOfTheBall = 0;
    
    while(continuer && window.isOpen()){
        
    
        
       winnerOfTheBall = playBall(window,  winnerOfTheBall, scorePlayer1, scorePlayer2);
        updateScore(winnerOfTheBall, &scorePlayer1, &scorePlayer2);
        
        int gameWinner = isGameFinish(scorePlayer1, scorePlayer2);
        if(gameWinner){
            continuer = 0;
        }
        
    }
    
    
}