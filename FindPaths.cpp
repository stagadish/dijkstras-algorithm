//
//  CreateGraphAndTest.cpp
//  dijkstras-algorithm-xcode
//
//  Created by Gil Dekel on 4/27/16.
//  Last updated by Gil Dekel on 4/27/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#include "WDGraph.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// A function to parse the input data into a graph and return it.
WDGraph<int> parseInputToGraph(const std::string &graph_input);


int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << "||||| Should be: <GRAPH_FILE> <STARTING_VERTEX>" << std::endl;
        return 0;
    }
    
    std::cout << "Graph input file is " << argv[1] << ", and the starting vertex is " << argv[2] << std::endl;
    
    WDGraph<int> testGraph = std::move(parseInputToGraph(argv[1]));
//    testGraph.printGraph();
    
    int starting_vertex = 0;
    // Try to translate STARTING_VERTEX to int in order to queue dijkstra's algorithm.
    try {
        starting_vertex = std::stoi(argv[2]);
        if (testGraph.DijkstrasShortestPath(starting_vertex)) {
            for (int i = 1; i <= testGraph.Size(); ++i) {
                if (i == starting_vertex) {
                    std::cout << i << ": " << i << " is the starting vertex, Total Cost: " << testGraph.GetCostOf(i) << std::endl;
                } else {
                    std::cout << i << ": "; testGraph.PrintShortestPathOf(i);
                    std::cout << "Total cost: " << testGraph.GetCostOf(i) << std::endl;
                    
                }
            }
        } else
            std::cout << "Failed to execute Dijkstra's algorithm. " << starting_vertex << " is not in the graph.\n";
        
    } catch (std::invalid_argument) {
        std::cout << "Invalid argument for STARTING_VERTEX::::TERMINATING PROGRAM\n";
        exit(1);
    }
    return 0;
}



WDGraph<int> parseInputToGraph(const std::string &graph_input) {
    std::ifstream graph_in(graph_input);
    if (graph_in.fail()) {
        std::cout << "ERROR:: CANNOT READ FROM FILE: '" << graph_input << "'\n";
        exit(1);
    }
    
    WDGraph<int> myGraph;
    std::string graph_in_line;
    
    //Skip the first value. No need for it.
    graph_in.ignore(1000, '\n');
    while (getline(graph_in, graph_in_line)) {
        std::stringstream ss(graph_in_line);
        int originVertex, destinyVertex;
        double weight;
        
        ss >> originVertex;
        myGraph.AddVertex(originVertex);
        
        while (ss >> destinyVertex >> weight) {
            myGraph.AddVertex(destinyVertex);
            myGraph.AddEdge(originVertex, destinyVertex, weight);
        }
    }
    graph_in.close();
    
    return myGraph;
}


