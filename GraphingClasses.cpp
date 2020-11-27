//
// Created by Admin on 11/26/2020.
//

#include "GraphingClasses.h"
#include "WinD.h"
#include <iostream>
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

}

//Render the graph for display to the window
int Graphing::renderGraph() {

    //Display the background for the graph
    cout << "bkg" << endl;
    int bkgCode = winDisplay->displaySegment(posX, posY, width, height, bkgColor);
    if(bkgCode != 0){
        cout << "Error rendering background of graph" << endl;
        return bkgCode;
    }

    //Draw the vertical axis
    cout << "vert" << endl;
    int vertCode = winDisplay->displaySegment(((width / 2) + posX), posY, axisThickness, height, axisColor);
    if(vertCode != 0){
        cout << "Error rendering vertical axis of graph" << endl;
        return vertCode;
    }

    //Draw horizontal axis
    cout << "hor" << endl;
    int horizCode = winDisplay->displaySegment(posX, ((height / 2) + posY), width, axisThickness, axisColor);
    if(horizCode != 0){
        cout << "Error rendering horizontal axis of graph" << endl;
        return horizCode;
    }

    return 0;
}


//Get a function to graph from user input
void Graphing::getFunction() {
    cout << "Enter a function to graph" << endl;
    getline(cin, function);
}

