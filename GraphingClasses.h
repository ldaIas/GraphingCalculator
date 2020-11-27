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

    //Get the function to graph from user input
    void getFunction();

private:

    //Render the graph on the window
    void renderGraph();

    string function;

    WinD* winDisplay;
    int posX;
    int posY;
    int width;
    int height;
    int bkgColor [3] = {255, 255, 255};

};

#endif //GRAPHINGCALCULATOR_GRAPHINGCLASSES_H
