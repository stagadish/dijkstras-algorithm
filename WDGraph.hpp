//
//  WDGraph.hpp
//  dijkstras-algorithm-xcode
//
//  Created by Gil Dekel on 4/26/16.
//  Last updated by Gil Dekel on 4/26/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#ifndef _WDGRAPH_H_
#define _WDGRAPH_H_

#include <iostream>
#include <unordered_map>

/*
 * WDGraph stands for Weighted-Directed graph, which is
 * the requiered data structure for this exercise.
 *
 * --Assumptions--
 * 1) All vertices are unique (i.e. no duplicates).
 * 2) Objects of type Comparable define operator<
 *    (i.e. it is possible to compare between two objects of type Comparable)
 * 3) Weights are non-negative double values. The algorithm will fail if given
 *    negative weight values.
 */
template <typename Comparable>
class WDGraph {
private:
    // A vertex holds its value and an adjacency list to
    // represent edges to its neighbors.
    struct Vertex {
        Comparable val;
        std::unordered_map<Comparable, std::pair<Comparable, double>> adj_l;
    };
    
    // The set of vertices searchable by their values.
    std::unordered_map<Comparable, Vertex> vertices_;
    
public:
    // Using default ctors, assignment operators and destructor.
    WDGraph() = default;
    WDGraph(const WDGraph &rhs) = default;
    WDGraph& operator=(const WDGraph &rhs) = default;
    WDGraph(WDGraph &&rhs) = default;
    WDGraph& operator=(WDGraph &&rhs) = default;
    ~WDGraph() = default;
    
    // Check if a a certain value is in the graph.
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
    
    // return the size of the graph (i.e. num of vertices)
    size_t Size() const { return vertices_.size(); }
    
    // prints the graph for testing.
    // assumes Comparable implements operator<<
    void printGraph() const;
    
};

#endif /* _WDGRAPH_H_ */
