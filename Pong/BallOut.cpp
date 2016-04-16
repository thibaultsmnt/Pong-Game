//
//  BallOut.cpp
//  Pong
//
//  Created by Thibault Simonetto on 16/04/2016.
//  Copyright © 2016 Thibault Simonetto. All rights reserved.
//

#include "BallOut.hpp"
#include "GameConstant.hpp"

int isBallOut(int ballPositionX, int ballPositionY){
    
    if (ballPositionX < 0){
        return 2; //ball out dans le coté gauche donc on retourne 2 (joueur droite) a gagner
    } else if (ballPositionX > WIN_WIDTH) {
        return 1; //ball out dans le coté droit donc on retourne 1 (joueur gauche) a gagner
    }
    
    return 0;
    
    
}