//
//  WDGraph.cpp
//  dijkstras-algorithm-xcode
//
//  Created by Gil Dekel on 4/26/16.
//  Last updated by Gil Dekel on 4/27/16.
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
        Vertex newVertex(val);
        vertices_.insert(std::pair<Comparable, Vertex>(newVertex.val, newVertex));
        return true;
    }
}

template <typename Comparable>
bool WDGraph<Comparable>::ContainsEdge(const Comparable &lhs, const Comparable &rhs) const {
    // Check if both values are in the graph
    if (ContainsVertex(lhs) && ContainsVertex(rhs)) {
        auto fetchVertex = vertices_.find(lhs);                     // get the first vertex.
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
            fetchVertex->second.adj_l.insert(std::pair<Comparable, double>(rhs, weight));
            return true;
        } else
            return false;
    }
}

template <typename Comparable>
double WDGraph<Comparable>::GetWeightBetween(const Comparable &lhs, const Comparable &rhs) const {
    if (ContainsVertex(lhs) && ContainsVertex(rhs)) {
        if (ContainsEdge(lhs, rhs)) {
            return vertices_.find(lhs)->second.adj_l.find(rhs)->second;
        } else
            return -1;
    } else
        return -1;
}

template <typename Comparable>
bool WDGraph<Comparable>::DijkstrasShortestPath(const Comparable &start) {
    auto sVertex = vertices_.find(start);
    if (sVertex == vertices_.end())     //check if the query is in the graph.
        return false;
    
    std::priority_queue<Vertex*, std::vector<Vertex*>, CompareByDist> pq;
	for(auto v = vertices_.begin(); v != vertices_.end(); ++v ){
        v->second.dist = INF;
        v->second.known = false;
    }
    
    sVertex->second.dist = 0;
    pq.push(&sVertex->second);
    
    for (int i = 1 ; ; ++i) {
        bool success = false;
        while (!pq.empty() && !success) {
            if (!pq.top()->known)
                success = true;
            else
                pq.pop();
        }
        if (!success) break;
        
        Vertex *v = pq.top();
        pq.pop();
        v->known = true;
        for (auto neighborWeight : v->adj_l) {
            auto neighborVertex = vertices_.find(neighborWeight.first);
            if (v->dist + neighborWeight.second < neighborVertex->second.dist) {
                neighborVertex->second.dist = v->dist + neighborWeight.second;
                neighborVertex->second.path = v;
                pq.push(&neighborVertex->second);
            }
        }
    }
    return true;
}

template <typename Comparable>
void WDGraph<Comparable>::PrintShortestPathOf(const Comparable vertexVal) const {
    auto fetchVertex = vertices_.find(vertexVal);
    if (fetchVertex != vertices_.end()) {
        PrintShortestPathOf(&fetchVertex->second);
    }
}

template <typename Comparable>
void WDGraph<Comparable>::PrintShortestPathOf(const Vertex *v) const {
    if (v->path == nullptr)
        std::cout << v->val << ", ";
    else {
        PrintShortestPathOf(v->path);
        std::cout << v->val << ", ";
    }
    
}

template <typename Comparable>
double WDGraph<Comparable>::GetCostOf(const Comparable &val) {
    auto fetchVertex = vertices_.find(val);
    if (fetchVertex != vertices_.end()) {
        return fetchVertex->second.dist;
    }
    else return -1;
}

template <typename Comparable>
void WDGraph<Comparable>::printGraph() const {
    for (auto verx : vertices_) {
        std::cout << "Vertex " << verx.second.val << " is connected to:\n";
        for (auto neighbor : verx.second.adj_l)
            std::cout << "\t" << neighbor.first << ":" << neighbor.second << std::endl;
    }
}



