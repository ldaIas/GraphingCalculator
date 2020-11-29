//
// Created by Admin on 11/26/2020.
//

#ifndef GRAPHINGCALCULATOR_GRAPHINGCLASSES_H
#define GRAPHINGCALCULATOR_GRAPHINGCLASSES_H

#include "WinD.h"
#include <string>
using namespace std;

class Graphing {

public:

    Graphing(WinD* display);

    //Render the graph on the window
    int renderGraph();

    //Get the function to graph from user input
    void getFunction();

    //Graph a point
    int graphPoint();

private:

    //Compute the input function
    void functCompute();

    //Parse the input function
    float functParse(float x);

    //Check if the current character is an operation
    static bool checkForOperation(char c);

    string function;

    WinD* winDisplay;

    //Variables controlling graph placement and color in window
    int posX;
    int posY;
    int width;
    int height;
    int bkgColor [3] = {255, 255, 255};

    //Variables controlling axis settings
    int axisThickness;
    int axisColor [3] = {0, 0, 0};
    bool showGrid = true;
    int gridColor [3] = {192, 192, 192};
    //Controls how many segments are shown on the axis (ie -10 to 10 is 20)
    int vertRes;
    int horRes;

    /* Resolution for graphing the function
     * Ie a value of 1 graphs a point at each segment, while .5 graphs a point
     * halfway between each segment
     */
    double functRes = 1;
    int functColor [3] = {50, 25, 255};

};

#endif //GRAPHINGCALCULATOR_GRAPHINGCLASSES_H
