//
// Created by Admin on 11/26/2020.
//

#include "WinD.h"
#include "GraphingClasses.h"

int main( int argc, char* args[]){

    //Create the window display
    WinD* windowDisplay = new WinD();

    int init = windowDisplay->initialize();
    if(init != 0) return init;

    Graphing graph(windowDisplay);
    int graphCode = graph.renderGraph();
    if(graphCode != 0){
        return graphCode;
    }

    return 0;
}