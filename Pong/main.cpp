
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <unistd.h>
#include "GameConstant.hpp"
#include <iostream>

// Here is a small helper for you ! Have a look.

using namespace sf;
using namespace std;

#include "ResourcePath.hpp"
#include "PlayGame.hpp"

int main(int, char const**)
{
    
    playGame();
    
    return 0;
}
