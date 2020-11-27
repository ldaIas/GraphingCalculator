//
// Created by Admin on 11/12/2020.
//
#include <SDL2/SDL.h>
#include "WinD.h"
#include <iostream>
using namespace std;


WinD::WinD() {

}



/**
 * Initialize the SDL graphics engine
 *
 * @return Error value. 0 if no errors
 */
int WinD::initialize() {

    if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
        cout << "SDL Init Error: " << SDL_GetError << endl;
        return -1;
    }

    //Create the window
    int dispCode = display();
    return dispCode;
}

int WinD::display() {

    //Create Window
    win = SDL_CreateWindow("Graphing Calculator", 100, 100, width, height, SDL_WINDOW_SHOWN);
    if(win == nullptr){
        cout << "SDL_CreateWindow Error: " << SDL_GetError << endl;
        SDL_Quit();
        return -2;
    }

    //Create SDL renderer
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(ren == nullptr){
        SDL_DestroyWindow(win);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError << endl;
        SDL_Quit();
        return -3;
    }

    //Draw the background of the window
    drawBackground();


}

//Draw the background of the opened window gray
void WinD::drawBackground() {

    //Set the color of the background
    SDL_SetRenderDrawColor(ren, bkgColor, bkgColor, bkgColor, 255);

    //Clear the window to re-render with new color
    SDL_RenderClear(ren);

    //Re-render with new color
    SDL_RenderPresent(ren);

}

/**
 * Display a segment in the window
 *
 * @param posX X position to display segment in
 * @param posY Y position to display segment in
 * @param width Width of the segment
 * @param height Height of the segment
 * @param colors Array of colors (r, g, b)
 */

void WinD::displaySegment(int posX, int posY, int width, int height, int color[]) {

    SDL_SetRenderDrawColor(ren, color[0], color[1], color[2], 255);

    SDL_Rect* graph = new SDL_Rect();
    graph->x = posX;
    graph->y = posY;
    graph->w = width;
    graph->h = height;

    SDL_RenderFillRect(ren, graph);
    SDL_RenderPresent(ren);

    //TODO Delete later
    SDL_Delay(5000);
    windowClose();
}



//Close the window
void WinD::windowClose() {

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}