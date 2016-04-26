//
//  WDGraph.cpp
//  dijkstras-algorithm-xcode
//
//  Created by Gil Dekel on 4/26/16.
//  Last updated by Gil Dekel on 4/26/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#include "WDGraph.hpp"

template <typename Comparable>
bool WDGraph<Comparable>::ContainsVertex(const Comparable &val) const {
    auto fetchVertex = vertices_.find(val);
    if (fetchVertex == vertices_.end())
        return false;
    else
        return true;
}

template <typename Comparable>
bool WDGraph<Comparable>::AddVertex(const Comparable &val) {
    if (ContainsVertex(val))
        return false;
    else {
        Vertex newVertex;
        newVertex.val = val;
        vertices_.insert(std::pair<Comparable, Vertex>(newVertex.val, newVertex));
        return true;
    }
}

template <typename Comparable>
bool WDGraph<Comparable>::ContainsEdge(const Comparable &lhs, const Comparable &rhs) const {
    // Check if both values are in the graph
    if (ContainsVertex(lhs) && ContainsVertex(rhs)) {
        auto fetchVertex = vertices_.find(lhs);     // get the first vertex.
        auto findNeighbor = fetchVertex->second.adj_l.find(rhs);    // find the second vertx in the first vertex's adjacency list.
        if (findNeighbor == fetchVertex->second.adj_l.end())
            return false;
        else
            return true;
    } else
        return false;
}

template <typename Comparable>
bool WDGraph<Comparable>::AddEdge(const Comparable &lhs, const Comparable &rhs, double weight) {
    if (ContainsEdge(lhs, rhs))
        return false;
    else {
        if (ContainsVertex(lhs) && ContainsVertex(rhs)) {
            auto fetchVertex = vertices_.find(lhs);
            std::pair<Comparable, std::pair<Comparable, double>> insertEdge(rhs, std::pair<Comparable, double>(rhs, weight));
            fetchVertex->second.adj_l.insert(insertEdge);
            return true;
        } else
            return false;
    }
}

template <typename Comparable>
void WDGraph<Comparable>::printGraph() const {
    for (auto verx : vertices_) {
        std::cout << "Vertex " << verx.second.val << " is connected to:\n";
        for (auto neighbor : verx.second.adj_l)
            std::cout << "\t" << neighbor.first << ":" << neighbor.second.second << std::endl;
    }
}



