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
#include <fcntl.h>     // open
#include <inttypes.h>  // uint8_t, etc
#include <linux/i2c-dev.h> // I2C bus definitions
#include <unistd.h>
#include "PlayerInput.hpp"
#include <wiringPi.h>

void playGame(){
    
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "My window");
    

    int I2CFile;
    
    I2CFile = open("/dev/i2c-1", O_RDWR);     // Open the I2C device
    ioctl(I2CFile, I2C_SLAVE, ADS_ADDRESS);   // Specify the address of the I2C Slave to communicate with


    if (wiringPiSetup()==-1){
    	printf("GPIO Reset button Error\n");
    	return ;
    }
    pullUpDnControl(RESET_PIN, PUD_UP);
    pinMode(RESET_PIN, INPUT);


    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    int continuer = 1;
    int winnerOfTheBall = 0;
//    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(50);

    sf::Font font;
    
    if (!font.loadFromFile("/home/pi/workspace/Pong-Game/Pong/police_pong.ttf")){
        printf("Error while loading police\n");
        return;
    }
    
    
    while(continuer && window.isOpen()){
        
        
        
       winnerOfTheBall = playBall(window, font, winnerOfTheBall, scorePlayer1, scorePlayer2, I2CFile);
        updateScore(winnerOfTheBall, &scorePlayer1, &scorePlayer2);
        
        int gameWinner = isGameFinish(scorePlayer1, scorePlayer2);
        if(gameWinner){
        	scorePlayer1=0;
        	scorePlayer2=0;
        }
        
    }
    
    
}
