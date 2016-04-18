//
//  GameConstant.hpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#ifndef GameConstant_hpp
#define GameConstant_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

//WINDOWS
#define WIN_HEIGHT 720
#define WIN_WIDTH 1280

//BORDER
#define BORDER_SIZE 20
#define BORDER_MARGIN 20


//RACKET
#define RACKET_WIDTH 30
#define RACKET_HEIGHT 150
#define RACKET_MARGIN 40
#define RACKET_1_POSITION_X RACKET_MARGIN
#define RACKET_2_POSITION_X (WIN_WIDTH - RACKET_MARGIN -RACKET_WIDTH)
#define RACKET_MIN_POSITION_Y (BORDER_MARGIN + BORDER_SIZE)
#define RACKET_MAX_POSITION_Y (WIN_HEIGHT - BORDER_MARGIN - BORDER_SIZE - RACKET_HEIGHT)


//BALL
#define BALL_SIZE 30
#define INITIAL_BALL_POSITION_Y (WIN_HEIGHT/2) - BALL_SIZE/2
#define INITIAL_BALL_POSITION_X 100 //Position centre ball par rapport au centre du fillet)

#define INITIAL_BALL_SPEED_X 200 //pt /sec
#define INITIAL_BALL_SPEED_Y 0 //pt /sec
#define MAX_ANGLE 1.04719755
#define BALL_SPEED_UNITY 300

//SCORE DISPLAY
#define CHARACTER_SIZE 150
#define SCORE_MARGIN_TOP 30
#define SCORE_MARGIN_MIDDLE 50


#endif /* GameConstant_hpp */
