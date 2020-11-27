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

private:



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



};

#endif //GRAPHINGCALCULATOR_GRAPHINGCLASSES_H
