//
//  WDGraph.hpp
//  dijkstras-algorithm-xcode
//
//  Created by Gil Dekel on 4/26/16.
//  Last updated by Gil Dekel on 4/29/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#ifndef _WDGRAPH_H_
#define _WDGRAPH_H_

#include <iostream>
#include <vector>
#include <limits>           // std::numeric_limits
#include <queue>            // std::priority_queue
#include <unordered_map>

/*
 * WDGraph stands for Weighted-Directed graph, which is
 * the required data structure for this exercise.
 *
 * --Assumptions--
 * 1) All vertices are unique (i.e. no duplicates).
 * 2) Objects of type Comparable define operator<
 *    (i.e. it is possible to compare between two objects of type Comparable)
 * 3) Weights are non-negative double values. The algorithm will fail if given
 *    negative weight values.
 */

const double INF = std::numeric_limits<double>::infinity();     //define infinity

template <typename Comparable>
class WDGraph {
private:
    // A vertex holds an adjacency list to represent edges to its neighbors.
    // Key is the value of the neighbor, and value is the weight of the edge
    // between this vertex and the neighbor vertex.
    struct Vertex {
        Comparable val;
        Vertex* path;
        double dist;
        bool known;
        std::unordered_map<Comparable, double> adj_l;
        
        Vertex() : path(nullptr), dist(0.0), known(false) {}
        Vertex(Comparable nuVal) : val(nuVal), path(nullptr), dist(0.0), known(false) {}
    };
    
    // Comparison class (struct) for the priority queue.
    struct CompareByDist {
        bool operator()(const Vertex *v1, const Vertex *v2) const {
            
            return (v1->dist > v2->dist);
        }
    };
    
    // The set of vertices searchable by their values.
    std::unordered_map<Comparable, Vertex> vertices_;
    
    // Print the shortest path of the given vertex to the
    // origin, calculated in the last run of DijkstrasShortestPath().
    // param vertex: a pointer to the destiny vertex.
    void PrintShortestPathOf(const Vertex *v) const;
    
public:
    // Using default ctors, assignment operators and destructor.
    WDGraph() = default;
    WDGraph(const WDGraph &rhs) = default;
    WDGraph& operator=(const WDGraph &rhs) = default;
    WDGraph(WDGraph &&rhs) = default;
    WDGraph& operator=(WDGraph &&rhs) = default;
    ~WDGraph() = default;
    
    // Check if a certain value is in the graph.
    // param val: The Comparable object as a value to search.
    // return: True if the value is already in the graph. False otherwise.
    bool ContainsVertex(const Comparable &val) const;
    
    // Add a new vertex to the graph.
    // param val: the Comparable object as a value to the new vertex.
    // return: True if the vertex was added to the graph. False otherwise.
    bool AddVertex(const Comparable &val);
    
    // Check if a DIRECTED edge exists between two vertices in the graph.
    // param lhs: the 'from' vertex value.
    // param rhs: the 'to' vertex value.
    // return: True if the edge exists between the two vertices. False otherwise.
    bool ContainsEdge(const Comparable &lhs, const Comparable &rhs) const;
    
    // Add a new DIRECTED edge between two vertices in the graph.
    // Will work only if both vertices are already in the graph.
    // param lhs: the 'from' vertex value.
    // param rhs: the 'to' vertex value.
    // param weight: a positive value.
    // return: True if the edge was added between the two vertices. False otherwise.
    bool AddEdge(const Comparable &lhs, const Comparable &rhs, double weight);
    
    // Get the weight value between two vertices in the graph.
    // param lhs: the 'from' vertex value.
    // param rhs: the 'to' vertex value.
    // return a positive double value if a and edge exists between the two vertices.
    // -1 otherwise. Remember, no negative weights are allowed.
    double GetWeightBetween(const Comparable &lhs, const Comparable &rhs) const;
    
    // Find the shortest weighted path from one vertex to all the others.
    // Done using Djikstra's algorithm, and breadth search first (priority queue).
    // Complexity O(|E|log|V|), where |E| is the number of edges, and |V| is the
    // number of vertices in the graph.
    // param start: the origin vertex.
    bool DijkstrasShortestPath(const Comparable &start);
    
    // This is a wrapper function to the private function
    // member PrintShortestPathOf(). It takes in a val from
    // the user and execute a print on vertices pointers.
    // Print the shortest path of the given vertex to the
    // origin, calculated in the last run of DijkstrasShortestPath().
    // param vertex: the destiny vertex.
    void PrintShortestPathOf(const Comparable vertexVal) const;
    
    // Get the current cost/distance of a vertex to the
    // origin, calculated in the last run of DijkstrasShortestPath().
    // param vertex: the destiny vertex value.
    // return the vertex's dist value. -1 if the value is not in the graph.
    double GetCostOf(const Comparable &val);
    
    // return the size of the graph (i.e. num of vertices)
    size_t Size() const { return vertices_.size(); }
    
    // prints the graph for testing.
    // assumes Comparable implements operator<<
    void printGraph() const;
    
};

#include "WDGraph.cpp"
#endif /* _WDGRAPH_H_ */
