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

    renderGraph();
}

//Render the graph for display to the window
void Graphing::renderGraph() {

    winDisplay->displaySegment(posX, posY, width, height, bkgColor);

}


//Get a function to graph from user input
void Graphing::getFunction() {
    cout << "Enter a function to graph" << endl;
    getline(cin, function);
}

