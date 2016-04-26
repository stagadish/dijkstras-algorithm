//
//  CreateGraphAndTest.cpp
//  dijkstras-algorithm-xcode
//
//  Created by Gil Dekel on 4/26/16.
//  Last updated by Gil Dekel on 4/26/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#include "WDGraph.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << "||||| Should be: <inputfilename> <queryfilename>" << std::endl;
        return 0;
    }
    
    const std::string graph_input(argv[1]);
    const std::string graph_query(argv[2]);
    std::cout << "Graph input file is " << graph_input << ", and query file is " << graph_query << std::endl;
    
    
    //Parse the input file.
    std::ifstream graph_in(graph_input);
    if (graph_in.fail()) {
        std::cout << "ERROR:: CANNOT READ FROM FILE: '" << graph_input << "'\n";
        exit(1);
    }
    
    int originVertex, destinyVertex;
    double weight;
    WDGraph<int> myGraph;
    std::string graph_in_line;
    
    //Skip the first value. No need for it.
    graph_in >> originVertex;
    while (getline(graph_in, graph_in_line)) {
        std::stringstream ss(graph_in_line);
        ss >> originVertex;
        myGraph.AddVertex(originVertex);
        
        while (ss >> destinyVertex >> weight) {
            myGraph.AddVertex(destinyVertex);
            myGraph.AddEdge(originVertex, destinyVertex, weight);
        }
    }
    graph_in.close();
    
    myGraph.printGraph();
    
    return 0;
}