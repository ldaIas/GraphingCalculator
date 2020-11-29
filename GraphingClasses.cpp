//
// Created by Admin on 11/26/2020.
//

#include "GraphingClasses.h"
#include "WinD.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/** Constructor for the graph
 *
 * @param display The pointer for the window being used to display the graph
 */

Graphing::Graphing(WinD* display) {

    winDisplay = display;
    posX = winDisplay->getWidth() * .1;
    posY = winDisplay->getHeight() * .1;

    if(winDisplay->getWidth() < winDisplay->getHeight()){
        width = winDisplay->getWidth() * .75;
        height = winDisplay->getWidth() * .75;
    }
    else{
        width = winDisplay->getHeight() * .75;
        height = winDisplay->getHeight() * .75;
    }

    axisThickness = 2;
    vertRes = 20;
    horRes = 20;

}

//Render the graph for display to the window
int Graphing::renderGraph() {

    //Display the background for the graph
    int bkgCode = winDisplay->displaySegment(posX, posY, width, height, bkgColor);
    if(bkgCode != 0){
        cout << "Error rendering background of graph" << endl;
        return bkgCode;
    }

    //Draw the vertical axis
    int vertCode = winDisplay->displaySegment(((width / 2) + posX), posY, axisThickness, height, axisColor);
    if(vertCode != 0){
        cout << "Error rendering vertical axis of graph" << endl;
        return vertCode;
    }

    //Draw the segments on the vertical axis
    int segmentY = posY;
    for(int i = 0; i <= vertRes; i++){

        //If show grid enabled, a gray grid will appear
        if(showGrid) {
            int vertSegCode = winDisplay->displaySegment(posX, segmentY,
                                                         width, axisThickness, gridColor);
            if(vertSegCode != 0){
                cout << "Error rendering vertical axis segments of graph" << endl;
                return vertSegCode;
            }
        }

        //Draw the segments on the vertical axis
        int vertSegCode = winDisplay->displaySegment(((width / 2) + posX - 5), segmentY,
                                                     10, axisThickness, axisColor);
        if(vertSegCode != 0){
            cout << "Error rendering vertical axis segments of graph" << endl;
            return vertSegCode;
        }
        segmentY += height / vertRes;
    }


    //Draw horizontal axis
    int horizCode = winDisplay->displaySegment(posX, ((height / 2) + posY), width, axisThickness, axisColor);
    if(horizCode != 0){
        cout << "Error rendering horizontal axis of graph" << endl;
        return horizCode;
    }

    //Draw the segments on the horizontal axis
    int segmentX = posX;
    for(int i = 0; i <= horRes; i++) {

        //If show grid enabled, a gray grid will appear
        if (showGrid) {

            //Don't draw over the vertical axis
            if( segmentX == ((width / 2) + posX)){
                segmentX += width / horRes;
                continue;
            }
            int horizSegCode = winDisplay->displaySegment(segmentX, posY,
                                                          axisThickness, height, gridColor);
            if (horizSegCode != 0) {
                cout << "Error rendering vertical axis segments of graph" << endl;
                return horizSegCode;
            }
        }

        // Draw the segments on the horizontal axis
        int horizSegCode = winDisplay->displaySegment(segmentX, ((width / 2) + posY - 5),
                                                      axisThickness, 10, axisColor);
        if (horizSegCode != 0) {
            cout << "Error rendering vertical axis segments of graph" << endl;
            return horizSegCode;
        }
        segmentX += width / horRes;
    }
    return 0;
}


//Get a function to graph from user input
void Graphing::getFunction() {
    //cout << "Enter a function to graph" << endl;
    //getline(cin, function);

    functCompute();
}

//Parse and compute the input function
void Graphing::functCompute(){

    //First, remove whitespace from input
    /*for(int i = 0; i < function.length(); i++){
        if(function[i] == ' ') {
            function.erase(i, 1);
            i -= 1;
        }
    }
    cout << function << endl;*/

    graphPoint();

    SDL_Delay(5000);
}

float Graphing::functParse(float x) {

    /* TODO
     * Scrap this. It needs to comform to pemdas
     * something like find *, then /, then -, so on
     */
    vector<string> operationQueue;
    int lastOpIndex = 2;
    string funct = function;
    for(int i = 0; i < function.length(); i++){

        char first = function[i];
        if(checkForOperation(function[i])) {

            // Iterate to next operator to get operation substring
            for(int j = i + 1; j < function.length(); j++){
                char sec = function[j];
                if(checkForOperation(function[j])) {
                    operationQueue.push_back(function.substr(lastOpIndex, j - 2));
                    i = j - 2;
                    lastOpIndex += j - 2;
                    break;
                }
            }
        }
    }

    for(auto & i : operationQueue){
        cout << i << endl;
    }

    return 0;

}

//Check if the current char is an operation
bool Graphing::checkForOperation(char c){

    switch(c) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '|':
            return true;

        default:
            return false;
    }

}


int Graphing::graphPoint() {

    int xPoint = posX;
    int lastPointX = xPoint;
    int lastPointY;
    cout << (horRes / 2) * 100 << endl;
    for(int xIt = ((horRes / 2) - horRes) * 100 ; xIt <= (horRes / 2) * 100; xIt += functRes * 100) {

        cout << "xIt: " << xIt << endl;
        double x = xIt / 100.0;
        double y = pow(x, 2);

        int yPoint = (posY + (height / 2)) + ( (height / vertRes) * (y * -1) ) - (5 - axisThickness);

        if(xIt == ((horRes / 2) - horRes) * 100){
            lastPointY = yPoint;
        }

        cout << "X: " << xPoint << endl;
        cout << "Y: " << yPoint << endl;

        int drawCode = winDisplay->displaySegment(xPoint, yPoint, 5, 5, functColor);
        if(drawCode != 0){
            cout << "Error drawing point at: " << x << "," << y << endl;
            return drawCode;
        }
        winDisplay->drawLine(lastPointX + 2, lastPointY + 2, xPoint + 2, yPoint + 2, functColor);

        lastPointX = xPoint;
        lastPointY = yPoint;

        xPoint += (width / horRes) * functRes;


    }
    cout << "stopping point" << endl;
    cin >> xPoint;

    return 0;
}