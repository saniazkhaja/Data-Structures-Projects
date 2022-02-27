// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart. Used to see final creation
//
// Sania Khaja
// U. of Illinois, Chicago
// CS 251: Spring 2022
//

// Creative component:
// User can choose to display:
// 1. bottom to top entry (least to greatest) or other way round
// 2. and can choose to start at the end or beginning (time wise)
// then when run these options will be reflected in the graph
// had to use barchart and barchartanimate to facilitate these changes
// affects the graphing and order of barcharts
// To run:
// user can choose any of the files that are available
// so first choose a file
// then use cout prompts to choose options
// first option is choosing to display least to greatest or other way round
// you input 1 or 2 based on which option you want
// second option is choosing time order as either forwards or backwards
// Again type in 1 or 2 based on what you want
// then it will run and you will see your graph
// this file has to be used in order for this to work

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
    string filename = "";
    string topOrBottom = "";
    string forwardOrBackwards = "";

    // to get user options for file, low to high or high to low and time order
    cout << "Input file name you want:" << endl;
    cin >> filename;
    cout << "Do you want to display from "
            "1. highest(top) value to lowest(bottom) value or"
            "2. lowest(bottom) value to highest(top) value "
            "Please type in 1 or 2 based on option wanted" << endl;
    cin >> topOrBottom;
    cout << "Do you want to display from "
            "1. starting year to most recent year or"
            "2. from the most recent year to the first year of data "
            "Please type in 1 or 2 based on option wanted" << endl;
    cin >> forwardOrBackwards;

    // reads in first three lines as a header
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

    // setting barchartanimate parameter constructor
	BarChartAnimate bca(title, xlabel, source);
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	// user options used in order to know what parameters to pass
    if (topOrBottom == "1" && forwardOrBackwards == "1") {
        bca.userAnimate(cout, 12, -1, true, true);
    } else if (topOrBottom == "1" && forwardOrBackwards == "2") {
        bca.userAnimate(cout, 12, -1, true, false);
    } else if (topOrBottom == "2" && forwardOrBackwards == "1") {
        bca.userAnimate(cout, 12, -1, false, true);
    } else if (topOrBottom == "2" && forwardOrBackwards == "2") {
        bca.userAnimate(cout, 12, -1, false, false);
    }

    return 0;
}
