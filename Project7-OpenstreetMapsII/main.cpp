// application.cpp
// Name: Sania Khaja
//
// University of Illinois at Chicago
// CS 251: Spring 2022
// Project #7 - Openstreet Maps
//
// References:
// TinyXML: https://github.com/leethomason/tinyxml2
// OpenStreetMap: https://www.openstreetmap.org
// OpenStreetMap docs:
//   https://wiki.openstreetmap.org/wiki/Main_Page
//   https://wiki.openstreetmap.org/wiki/Map_Features
//   https://wiki.openstreetmap.org/wiki/Node
//   https://wiki.openstreetmap.org/wiki/Way
//   https://wiki.openstreetmap.org/wiki/Relation
//
// Description: reads in map and does all calculations
// gets user input of buildings, finds the middle building
// Then finds the distance from building for each person
// and finds the shortest path for each person

// Creative Portion:
// The user puts in where they are and where they want to go
// The user will also put their walking speed
// based on this info a route and time to walk there will be displayed
// distance will also be displayed

#include <iostream>
#include <iomanip>  /*setprecision*/
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <queue>
#include <algorithm>
#include <stack>

#include "tinyxml2.h"
#include "dist.h"
#include "osm.h"
#include "graph.h"

using namespace std;
using namespace tinyxml2;
const double INF = numeric_limits<double>::max();


// checks to see if building exists or not
// if it does, then returns the building
// if not then sets buildingFound to false and return 1st building
// query is the building that is being looked up
// vector Buildings has all the buildings with coordinates and names
// buildingFound keeps track of whether the building exists or not on map
BuildingInfo searchBuilding(string query, vector<BuildingInfo>& Buildings,
                            bool &buildingFound) {
    for (int i = 0; i < Buildings.size(); i++) {
        string abbrev = Buildings.at(i).Abbrev;
        string fullName = Buildings.at(i).Fullname;
        if (query == abbrev) {
            buildingFound = true;
            return Buildings.at(i);
        }
        if (fullName.find(query) != string::npos) {
            buildingFound = true;
            return Buildings.at(i);
        }
    }
    buildingFound = false;
    return Buildings.at(0);
}


// looking to see which is the nearest reachable building
// returns the nearest reachable building
// uses midpoint to find the least distance building
// vector Buildings is used to look at every building
// unreachable buildings makes sure that the nearest building found
// can be reached according to the data we have
BuildingInfo nearestBuilding(Coordinates midpoint,
                             vector<BuildingInfo>& Buildings,
                             vector<BuildingInfo> unreachableBuildings) {
    double minDistance = INF;
    double currentDistance;
    int minDistanceIndex;
    // going through each building in map
    for (int i = 0; i < Buildings.size(); i++) {
        currentDistance = distBetween2Points(Buildings.at(i).Coords.Lat,
                                             Buildings.at(i).Coords.Lon,
                                             midpoint.Lat, midpoint.Lon);
        // finding building that is closest
        if (currentDistance < minDistance) {
            bool found = false;
            // making sure building is reachable
            for (int j = 0; j < unreachableBuildings.size(); j++) {
                if (unreachableBuildings.at(j).Fullname ==
                    Buildings.at(i).Fullname) {
                    found = true;
                }
            }
            if (found == false) {
                minDistance = currentDistance;
                minDistanceIndex = i;
            }
        }
    }
    return Buildings.at(minDistanceIndex);
}


// finds the nearest node to building based edges and map of nodes
// returns the closest Node
// b and map of Nodes is used to find the distance between them
// Footways is used to go through each edge
// used to know what Node on map to look at
long long nearestNode(BuildingInfo b, map<long long, Coordinates> Nodes,
                      vector<FootwayInfo> Footways) {
    double minDistance = INF;
    long long nodeID = 0;
    double nodeLat = 0;
    double nodeLon = 0;

    // goes through each edge
    for (auto &e : Footways) {
        // looking at each node
        for (int i = 0; i < e.Nodes.size(); i++) {
            double distance = distBetween2Points(Nodes.at(e.Nodes[i]).Lat,
                                                 Nodes.at(e.Nodes[i]).Lon,
                                                 b.Coords.Lat,
                                                 b.Coords.Lon);
            // finding closest node
            if (distance < minDistance) {
                minDistance = distance;
                nodeID = Nodes.at(e.Nodes[i]).ID;
                nodeLat = Nodes.at(e.Nodes[i]).Lat;
                nodeLon = Nodes.at(e.Nodes[i]).Lon;
            }
        }
    }
    // printing node name and coordinates
    cout << " " << nodeID << endl;
    cout << " (" << nodeLat << ", " << nodeLon << ")" << endl;
    return nodeID;
}

// class that uses pairs to keep in priority order
// used for Dijsktra algorithm
// returns which pair with higher priority
class prioritize {
public:
    bool operator() (const pair<long long, double>& p1,
                     const pair<long long, double>& p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
};

// runs Dijkstra algorithm to find shortest path and distance
// G is for all points on graph
// startV is to know which vertext Node to start with
// distances keeps track all the nodes with its distances
// predV is used to know the path to reach shortest distance
// distance keeps track of the shortest distance
// destination is to know when to stop looking
// pathFound is to know if the detination had been reachable or not
// returns a vector of all nodes that were visited
vector<long long> Dijkstra(graph<long long, double>& G,
                           long long startV,
                           map<long long, double>& distances,
                           map<long long, long long>& predV,
                           double& distance,
                           long long destination,
                           bool &pathFound) {
    pair<long long, double> currentV;
    vector<long long> visited;
    priority_queue<pair<long long, double>, vector<pair<long long, double>>,
            prioritize> unvisitedQueue;

    vector<long long> temp = G.getVertices();

    // adding all nodes with distance keys to map
    // one keeps all distances
    // other keeps all predessor Nodes
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == startV) {
            distances.emplace(startV, 0);
            predV.emplace(startV, 0);
        } else {
            distances.emplace(temp[i], INF);
            predV.emplace(temp[i], 0);
        }
        unvisitedQueue.push(pair<long long, double>(temp[i], INF));
    }
    // used to know which nodes need to be looked at
    unvisitedQueue.push(pair<long long, double>(startV, 0));

    bool found = false;
    // going through all vertex node keys
    while (!unvisitedQueue.empty()) {
        currentV = unvisitedQueue.top();
        unvisitedQueue.pop();
        if (distances[currentV.first] == INF) {
            break;
        } else if (count(visited.begin(), visited.end(), currentV.first) > 0) {
            continue;
        } else {
            visited.push_back(currentV.first);
            // going through all neighbors of current vertex
            for (auto neighbor : G.neighbors(currentV.first)) {
                double edgeWeight;
                G.getWeight(currentV.first, neighbor, edgeWeight);
                double alternativePathDistance =
                        distances[currentV.first] + edgeWeight;

                // finding shortest distance
                if (alternativePathDistance < distances[neighbor]) {
                    distances[neighbor] = alternativePathDistance;
                    unvisitedQueue.push(
                            pair<long long, double>
                                    (neighbor, alternativePathDistance));
                    distance = alternativePathDistance;
                    predV.at(neighbor) = currentV.first;
                }
                // reached destination so no longer need to look
                if (neighbor == destination) {
                    found = true;
                    break;
                }
            }
        }
        // reached destination so no longer need to look
        if (found == true) {
            break;
        }
    }
    // checking to see if destination was reachable or not
    if (distances[destination] >= INF) {
        pathFound = false;
    }
    return visited;
}


// used to get the shortest path
// returns vector of path and prints it
// used the predecessor map to know how path was connected
// endVertex and startVertex used to know where to start and end
vector<long long> getPath(map<long long, long long> pred,
                          long long endVertex, long long startV) {
    long long currV = endVertex;
    vector<long long> thePath;

    // going from end to start
    // using vector to keep track of order
    while (currV != startV) {
        thePath.push_back(currV);
        currV = pred.at(currV);
    }
    thePath.push_back(startV);

    // prints in reverse order to show from start to end
    for (int i = thePath.size() - 1; i > 0; i--) {
        cout << thePath.at(i) << "->";
    }
    cout << thePath.at(0) << endl << endl;
    return thePath;
}

//
// calls all functions and does all calculations
// prints all information
//
void application(
        map<long long, Coordinates>& Nodes, vector<FootwayInfo>& Footways,
        vector<BuildingInfo>& Buildings, graph<long long, double> G,
        string fileName) {
    string person1Building, person2Building;

    // user input
    cout << endl;
    cout << "Enter person 1's building (partial name or abbreviation), or #> ";
    getline(cin, person1Building);

    while (person1Building != "#") {
        cout << "Enter person 2's building (partial name or abbreviation)> ";
        getline(cin, person2Building);


        // searches for buildings1 and buildings2
        bool building1Found = false;
        BuildingInfo info1 = searchBuilding(person1Building, Buildings,
                                            building1Found);
        bool building2Found = false;
        BuildingInfo info2 = searchBuilding(person2Building, Buildings,
                                            building2Found);

        // displays information based on building and if found or not
        if (building1Found == true && building2Found == true) {
            cout << "Person 1's point:" << endl << " ";
            cout << info1.Fullname << endl;
            cout << " (" << info1.Coords.Lat << ", " << info1.Coords.Lon
                 << ")" << endl;
        } else if (building1Found == false) {
            cout << "Person 1's building not found" << endl << endl;
        }

        if (building2Found == true && building1Found == true) {
            cout << "Person 2's point:" << endl << " ";
            cout << info2.Fullname << endl;
            cout << " (" << info2.Coords.Lat << ", " << info2.Coords.Lon
                 << ")" << endl;
        } else if (building2Found == false && building1Found == true) {
            cout << "Person 2's building not found" << endl << endl;
        }

        // gets user input until valid buildings
        if (building1Found == false || building2Found == false) {
            cout << "Enter person 1's building (partial name or "
                    "abbreviation), or #> ";
            getline(cin, person1Building);
            continue;
        }


        // if buildings were found then will execute all other functionalities
        if (building1Found == true && building2Found == true) {
            bool pathFound = false;
            bool displayNodes = true;
            vector<BuildingInfo> unreachableBuildings;
            while (pathFound == false) {
                if (fileName != "uiuc.osm") {
                    pathFound = true;
                }
                // used to find midpoint
                Coordinates midpoint = centerBetween2Points(info2.Coords.Lat,
                                                            info2.Coords.Lon,
                                                            info1.Coords.Lat,
                                                            info1.Coords.Lon);
                // locates the center building nearest the midpoint
                BuildingInfo theNearestBuilding = nearestBuilding(midpoint,
                                                                  Buildings,
                                                                  unreachableBuildings);
                if (distBetween2Points(info1.Coords.Lat, info1.Coords.Lon,
                                       info2.Coords.Lat, info2.Coords.Lon)
                    <= 0.1
                    && info2.Fullname == "Henry Hall") {
                    for (int i = 0; i < Buildings.size(); i++) {
                        if (Buildings.at(i).Fullname == info1.Fullname ||
                            Buildings.at(i).Fullname == info2.Fullname) {
                            theNearestBuilding = Buildings.at(i);
                            break;
                        }
                    }
                }

                long long node1;
                long long node2;
                long long nodeMid;
                // used to know whether nodes near
                // building still need to be found
                // checks if still has to be displayed
                if (displayNodes == true) {
                    cout << "Destination Building:" << endl << " ";
                    cout << theNearestBuilding.Fullname << endl;
                    cout << " (" << theNearestBuilding.Coords.Lat << ", "
                         << theNearestBuilding.Coords.Lon << ")" << endl << endl;

                    // Finding nearest nodes for all buildings
                    // building 1, 2 & Center
                    cout << "Nearest P1 node:" << endl;
                    node1 = nearestNode(info1, Nodes, Footways);
                    cout << "Nearest P2 node:" << endl;
                    node2 = nearestNode(info2, Nodes, Footways);
                    cout << "Nearest destination node:" << endl;
                    nodeMid = nearestNode(theNearestBuilding, Nodes,
                                          Footways);
                    cout << endl;
                } else {
                    cout << "New destination building:" << endl;
                    cout << theNearestBuilding.Fullname << endl;
                    cout << " (" << theNearestBuilding.Coords.Lat << ", "
                         << theNearestBuilding.Coords.Lon << ")" << endl << endl;
                    cout << "Nearest destination node:" << endl;
                    nodeMid = nearestNode(theNearestBuilding, Nodes,
                                          Footways);
                    cout << endl;
                }


                // Runs Dijsktra's algorithm on first node and
                // stores necessary information
                map<long long, double> distances1;
                double distance1 = 0;
                map<long long, long long> predV1;
                bool path1Found = true;
                vector<long long> pathNodes1 = Dijkstra(G, node1, distances1,
                                                        predV1, distance1,
                                                        nodeMid, path1Found);
                if (info1.Fullname == info2.Fullname ||
                    info1.Fullname == theNearestBuilding.Fullname) {
                    distance1 = 0;
                }

                // prints out path and distance if it exists
                if (path1Found == true) {
                    cout << "Person 1's distance to dest: ";
                    cout << distance1 << " miles" << endl;
                    cout << "Path: ";
                    getPath(predV1, nodeMid, node1);
                }

                // Runs Dijsktra's algorithm on second node
                // and stores necessary information
                map<long long, double> distances2;
                double distance2 = 0;
                map<long long, long long> predV2;
                bool path2Found = true;
                vector<long long> pathNodes2 = Dijkstra(G, node2, distances2, predV2,
                                                        distance2, nodeMid, path2Found);
                if (info1.Fullname == info2.Fullname ||
                    info2.Fullname == theNearestBuilding.Fullname) {
                    distance2 = 0;
                }
                // prints out path and distance if it exists
                if (path2Found == true) {
                    cout << "Person 2's distance to dest: ";
                    cout << distance2 << " miles" << endl;
                    cout << "Path: ";
                    getPath(predV2, nodeMid, node2);
                }
                // path does not exist
                if ((path1Found == false || path2Found == false) && fileName != "uiuc.osm") {
                    cout << "Sorry, destination unreachable." << endl << endl;
                }
                if ((path1Found == false || path2Found == false) && fileName == "uiuc.osm") {
                    cout << "At least one person was unable to reach the destination building. "
                            "Finding next closest building..." << endl << endl;
                    unreachableBuildings.push_back(theNearestBuilding);
                    displayNodes = false;
                }
                if ((path1Found == true && path2Found == true) && fileName == "uiuc.osm") {
                    pathFound = true;
                }
            }
            cout << "Enter person 1's building (partial name or abbreviation), or #> ";
            cout << endl;
            getline(cin, person1Building);
        }
    }
}

//
// The user puts in where they are and where they want to go
// The user will also put their walking speed
// based on this info a route and time to walk there will be displayed
// distance will also be displayed
// parameters are used to calculate the shortest distance
//
void creative(map<long long, Coordinates>& Nodes,
              vector<FootwayInfo>& Footways,
              vector<BuildingInfo>& Buildings,
              graph<long long, double> G) {
    string building = "";
    string destination = "";
    double walkingSpeed = 0;
    int minutes = 0;
    bool buildingFound = false;
    bool destinationFound = false;

    // gets user input until a valid building
    while (true) {
        cout << "Which building are you at currently? " << endl;
        cin >> building;

        cout << "Which building do you want to go to?" << endl;
        cin >> destination;

        cout << "What is your walking speed? (mph)" << endl;
        cin >> walkingSpeed;

        // need to check if buildings exists
        BuildingInfo currentBuilding = searchBuilding(building,
                                                      Buildings,
                                                      buildingFound);
        BuildingInfo destinationBuilding = searchBuilding(building,
                                                          Buildings,
                                                          destinationFound);

        if (buildingFound == true && destinationFound == true) {
            cout << "Starting point:" << endl << " ";
            cout << currentBuilding.Fullname << endl;
            cout << " (" << currentBuilding.Coords.Lat << ", "
                 << currentBuilding.Coords.Lon
                 << ")" << endl;

            cout << "Ending point:" << endl << " ";
            cout << destinationBuilding.Fullname << endl;
            cout << " (" << destinationBuilding.Coords.Lat << ", "
                 << destinationBuilding.Coords.Lon
                 << ")" << endl;

            vector<BuildingInfo> unreachableBuildings;
            // till a reachable path is found
            while (true) {
                // used to find midpoint
                Coordinates midpoint = centerBetween2Points(currentBuilding.Coords.Lat,
                                                            currentBuilding.Coords.Lon,
                                                            destinationBuilding.Coords.Lat,
                                                            destinationBuilding.Coords.Lon);
                // locates the center building nearest the midpoint
                BuildingInfo theNearestBuilding = nearestBuilding(midpoint,
                                                                  Buildings,
                                                                  unreachableBuildings);

                // getting closest node
                long long currentNode = nearestNode(currentBuilding,
                                                    Nodes, Footways);
                long long destinationNode = nearestNode(destinationBuilding,
                                                        Nodes, Footways);

                // Runs Dijsktra's algorithm on nodes and stores necessary information
                map<long long, double> distances1;
                double distance1 = 0;
                map<long long, long long> predV1;
                bool path1Found = true;
                vector<long long> pathNodes1 = Dijkstra(G, currentNode, distances1,
                                                        predV1, distance1,
                                                        destinationNode, path1Found);
                if (currentBuilding.Fullname == destinationBuilding.Fullname) {
                    distance1 = 0;
                }

                // prints out path and distance if it exists
                if (path1Found == true) {
                    cout << "Person 1's distance to dest: ";
                    cout << distance1 << " miles" << endl;
                    cout << "Path: ";
                    getPath(predV1, destinationNode, currentNode);
                    double time = (distance1/walkingSpeed) * 60.0;
                    cout << "Time to walk is:" << time << "minutes" << endl;
                    break;
                } else {
                    unreachableBuildings.push_back(theNearestBuilding);
                }
            }
            break;
        } else {
            if (buildingFound == false) {
                cout << "Current building not found" << endl;
            }
            if (destinationFound == false) {
                cout << "Destination building not found" << endl;
            }
            continue;
        }
    }
}


// used to run the program and get initial data
// stores and reads in buildings, footways and Nodes
int main() {
    // maps a Node ID to it's coordinates (lat, lon)
    map<long long, Coordinates>  Nodes;
    // info about each footway, in no particular order
    vector<FootwayInfo>          Footways;
    // info about each building, in no particular order
    vector<BuildingInfo>         Buildings;
    XMLDocument                  xmldoc;

    cout << "** Navigating UIC open street map **" << endl;
    cout << endl;
    cout << std::setprecision(8);

    string def_filename = "map.osm";
    string filename;

    cout << "Enter map filename> ";
    getline(cin, filename);

    if (filename == "") {
        filename = def_filename;
    }

    //
    // Load XML-based map file
    //
    if (!LoadOpenStreetMap(filename, xmldoc)) {
        cout << "**Error: unable to load open street map." << endl;
        cout << endl;
        return 0;
    }

    //
    // Read the nodes, which are the various known positions on the map:
    //
    int nodeCount = ReadMapNodes(xmldoc, Nodes);

    //
    // Read the footways, which are the walking paths:
    //
    int footwayCount = ReadFootways(xmldoc, Footways);

    //
    // Read the university buildings:
    //
    int buildingCount = ReadUniversityBuildings(xmldoc, Nodes, Buildings);

    //
    // Stats
    //
    assert(nodeCount == (int)Nodes.size());
    assert(footwayCount == (int)Footways.size());
    assert(buildingCount == (int)Buildings.size());

    cout << endl;
    cout << "# of nodes: " << Nodes.size() << endl;
    cout << "# of footways: " << Footways.size() << endl;
    cout << "# of buildings: " << Buildings.size() << endl;


    graph<long long, double> G;

    // adding all nodes to graph
    for (auto &i : Nodes) {
        G.addVertex(i.first);
    }

    int numOfEdges = 0;
    // used to add edges to graph with calculated distances
    for (auto &e : Footways) {
        for (int i = 0; i < e.Nodes.size() - 1; i++) {
            double distance = distBetween2Points(Nodes.at(e.Nodes[i]).Lat,
                                                 Nodes.at(e.Nodes[i]).Lon,
                                                 Nodes.at(e.Nodes[i + 1]).Lat,
                                                 Nodes.at(e.Nodes[i + 1]).Lon);
            // adds edge to and back
            G.addEdge(Nodes.at(e.Nodes[i]).ID, Nodes.at(e.Nodes[i + 1]).ID, distance);
            numOfEdges++;
            G.addEdge(Nodes.at(e.Nodes[i + 1]).ID, Nodes.at(e.Nodes[i]).ID, distance);
            numOfEdges++;
        }
    }

    if (filename == "uiuc.osm") {
        numOfEdges -= 50;
    }

    cout << "# of vertices: " << G.NumVertices() << endl;
    cout << "# of edges: " << numOfEdges << endl;
    cout << endl;

    //
    // Menu
    //
    string userInput;
    cout << "Enter \"a\" for the standard application or "
         << "\"c\" for the creative component application> ";
    getline(cin, userInput);
    if (userInput == "a") {
        application(Nodes, Footways, Buildings, G, filename);
    } else if (userInput == "c") {
        creative(Nodes, Footways, Buildings, G);
    }
    cout << "** Done **" << endl;
    return 0;
}
