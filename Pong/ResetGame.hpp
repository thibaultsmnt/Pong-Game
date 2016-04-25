//
//  ResetGame.hpp
//  Pong
//
//  Created by Thibault Simonetto on 15/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#ifndef ResetGame_hpp
#define ResetGame_hpp

#include <stdio.h>

void resetScore(int *scorePlayer1, int *scorePlayer2);
int isGameFinish(int scorePlayer1, int scorePlayer2);
int checkResetInput();

#endif /* ResetGame_hpp */
