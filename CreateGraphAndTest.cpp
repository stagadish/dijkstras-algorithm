////
////  CreateGraphAndTest.cpp
////  dijkstras-algorithm-xcode
////
////  Created by Gil Dekel on 4/26/16.
////  Last updated by Gil Dekel on 4/27/16.
////  Copyright © 2016 Gil Dekel. All rights reserved.
////
//
//#include "WDGraph.cpp"
//
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//
//// A function to parse the input data into a graph and return it.
//WDGraph<int> parseInputToGraph(const std::string &graph_input);
//
//// A function to test the graph using an input query file.
//void queryGraph(const WDGraph<int> &graph, const std::string &graph_query);
//
//
//
//int main(int argc, char **argv) {
//    if (argc != 3) {
//        std::cout << "Usage: " << argv[0] << "||||| Should be: <inputfilename> <queryfilename>" << std::endl;
//        return 0;
//    }
//    
//    std::cout << "Graph input file is " << argv[1] << ", and query file is " << argv[2] << std::endl;
//    
//    WDGraph<int> testGraph = std::move(parseInputToGraph(argv[1]));
//    
//    testGraph.printGraph();
//    queryGraph(testGraph, argv[2]);
//    
//    
//    return 0;
//}
//
//
//
//WDGraph<int> parseInputToGraph(const std::string &graph_input) {
//    std::ifstream graph_in(graph_input);
//    if (graph_in.fail()) {
//        std::cout << "ERROR:: CANNOT READ FROM FILE: '" << graph_input << "'\n";
//        exit(1);
//    }
//    
//    WDGraph<int> myGraph;
//    std::string graph_in_line;
//    
//    //Skip the first value. No need for it.
//    graph_in.ignore(1000, '\n');
//    while (getline(graph_in, graph_in_line)) {
//        std::stringstream ss(graph_in_line);
//        int originVertex, destinyVertex;
//        double weight;
//        
//        ss >> originVertex;
//        myGraph.AddVertex(originVertex);
//        
//        while (ss >> destinyVertex >> weight) {
//            myGraph.AddVertex(destinyVertex);
//            myGraph.AddEdge(originVertex, destinyVertex, weight);
//        }
//    }
//    graph_in.close();
//    
//    return myGraph;
//}
//
//void queryGraph(const WDGraph<int> &graph, const std::string &graph_query) {
//    std::ifstream graph_qs(graph_query);
//    if (graph_qs.fail()) {
//        std::cout << "ERROR:: CANNOT READ FROM FILE: '" << graph_query << "'\n";
//        exit(1);
//    }
//    
//    int from, to;
//    while (graph_qs >> from >> to) {
//        std::cout << from << " " << to << ": ";
//        if (graph.ContainsEdge(from, to))
//            std::cout << "Connected, weight of edge is " << graph.GetWeightBetween(from, to) << std::endl;
//        else
//            std::cout << "Not Connected" << std::endl;
//    }
//    
//}
//
//
