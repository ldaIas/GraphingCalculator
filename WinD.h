//
// Created by Admin on 11/12/2020.
//

#ifndef MAZESOLVER_WIND_H
#define MAZESOLVER_WIND_H
#include <SDL2/SDL.h>

class WinD {
public:

    WinD();

    //Initialize SDL
    int initialize();

    //Create the display window
    int display();

    //Close the windows
    void windowClose();

    //Draw the background of the window
    void drawBackground();

    //Display a segment in the window
    int displaySegment(int posX, int posY, int width, int height, int colors[]);

    //Draw a line between two points
    void drawLine(int x1, int y1, int x2, int y2, int colors[]);

    int getHeight() {return height;}
    int getWidth() {return width;}

private:

    //Dimensions for the window
    int height = 800;
    int width = 1500;

    //TODO Implement a scaling factor to allow different window sizes
    double scale = 1;

    //Window and renderer pointers
    SDL_Window* win;
    SDL_Renderer* ren;

    //Value for background color of the window (gray)
    int bkgColor = 75;

};


#endif //MAZESOLVER_WIND_H
