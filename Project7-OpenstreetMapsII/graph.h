// graph.h
// Name: Sania Khaja
//
// Graph class that was implemented with a map of vector pairs
// adds vertexes, edges and gets both
//
// University of Illinois at Chicago
// CS 251: Spring 2022
// Project #7 - Openstreet Maps
//

#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>

using namespace std;

template<typename VertexT, typename WeightT>
class graph {
private:
    struct EdgeData {
        bool     EdgeExists;
        WeightT  Weight;

        EdgeData() {
            EdgeExists = false;  // initially no edge, and no weight
        }
    };

    // the map contains all the vertices
    // each key in the map has a vector as the value
    // this vector has all the edge vertices and edge weights
    typedef pair<VertexT, WeightT> vwPair;
    unordered_map<VertexT, vector<vwPair>> adjList;
    // keeps track of how many total vertices
    int numOfEdges = 0;


    //
    // _LookupVertex
    //
    // Finds the vertex in the Vertices vector and returns it's
    // index position if found, otherwise returns -1.
    //
    int _LookupVertex(VertexT v) const {
        // checking if vertex exists in map
        if (adjList.count(v) > 0) {
            // calculates the index
            return distance(adjList.begin(), adjList.find(v));
        } else {
            return -1;
        }
    }

public:
    // constructor:
    //
    // Constructs an empty graph
    graph() {
    }

    //
    // NumVertices
    //
    // Returns the # of vertices currently in the graph.
    //
    int NumVertices() const {
        return adjList.size();
    }

    //
    // NumEdges
    //
    // Returns the # of edges currently in the graph.
    //
    int NumEdges() const {
        return numOfEdges;
    }

    //
    // addVertex
    //
    // Adds the vertex v to the graph.
    // If the vertex already exists in the graph, then false is returned.
    //
    bool addVertex(VertexT v) {
        if (adjList.count(v) > 0) {
            return false;
        }
        vector<vwPair> emptyVector;
        adjList.emplace(v, emptyVector);

        return true;
    }

    //
    // addEdge
    //
    // Adds the edge (from, to, weight) to the graph, and returns
    // true.  If the vertices do not exist, false is returned
    //
    // NOTE: if the edge already exists, the existing edge weight
    // is overwritten with the new edge weight.
    //
    bool addEdge(VertexT from, VertexT to, WeightT weight) {
        // checking that vertices exist
        if (adjList.count(from) == 0 || adjList.count(to) == 0) {
            return false;
        }

        bool foundTo = false;
        // looking through all edges and vertices
        for (auto &i : adjList.at(from)) {
            // if vertex exists then updates edge
            if (i.first == to) {
                foundTo = true;
                i.second = weight;
                break;
            }
        }
        // vertex and edge does not exist so added it to vector pairs
        if (foundTo == false) {
            numOfEdges++;
            adjList.at(from).push_back(make_pair(to, weight));
        }
        return true;
    }

    //
    // getWeight
    //
    // Returns the weight associated with a given edge.  If
    // the edge exists, the weight is returned via the reference
    // parameter and true is returned.  If the edge does not
    // exist, the weight parameter is unchanged and false is
    // returned.
    //
    bool getWeight(VertexT from, VertexT to, WeightT& weight) const {
        // vertices not in map
        if (adjList.count(from) == 0 || adjList.count(to) == 0) {
            return false;
        } else {
            // going through each edge
            for (auto &i : adjList.at(from)) {
                // found vertex so updates edge
                if (i.first == to) {
                    weight = i.second;
                    return true;
                }
            }
            return false;
        }
    }

    //
    // neighbors
    //
    // Returns a set containing the neighbors of v, i.e. all
    // vertices that can be reached from v along one edge.
    // Since a set is returned, the neighbors are returned in
    // sorted order; use foreach to iterate through the set.
    //
    set<VertexT> neighbors(VertexT v) const {
        set<VertexT> S;

        // for special cases
        if (adjList.count(v) == 0) {
            return S;
        }
        if (adjList.at(v).size() == 0) {
            return S;
        }

        for (auto &i : adjList.at(v)) {
            S.insert(i.first);
        }
        return S;
    }

    //
    // getVertices
    //
    // Returns a vector containing all the vertices currently in
    // the graph.
    //
    vector<VertexT> getVertices() const {
        vector <VertexT> vertices;
        // storing all vertices in map
        for (auto &i : adjList) {
            vertices.push_back(i.first);
        }
        return vertices;
    }

    //
    // dump
    //
    // Dumps the internal state of the graph for debugging purposes.
    //
    // Example:
    //    graph<string,int>  G(26);
    //    ...
    //    G.dump(cout);  // dump to console
    //
    void dump(ostream& output) const {
//    output << "***************************************************" << endl;
//    output << "********************* GRAPH ***********************" << endl;
//
//    output << "**Num vertices: " << this->NumVertices() << endl;
//    output << "**Num edges: " << this->NumEdges() << endl;
//
//    output << endl;
//    output << "**Vertices:" << endl;
//    for (int i = 0; i < this->NumVertices(); ++i) {
//      output << " " << i << ". " << this->Vertices[i] << endl;
//    }
//
//    output << endl;
//    output << "**Edges:" << endl;
//
//    output << "**************************************************" << endl;
    }
};