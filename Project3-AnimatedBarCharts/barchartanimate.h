// barchartanimate.h
// Animates all frames
// calls class barchart and stores all frames of barchart in array
// frames are used to help with animation
// also decides on colors for colormap and reads in file
// class that uses bar.h and barchart.h function in order to display

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    int color = 0;

 public:

    // a parameterized constructor:
    // barcharts array is allocated in memory with capacity of 4
    BarChartAnimate(string title, string xlabel, string source) {
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        size = 0;
        capacity = 4;
        barcharts = new BarChart[capacity];
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if (barcharts != nullptr) {
            for (int i = 0; i < capacity; i++) {
                 barcharts[i].clear();
            }
            delete[] barcharts;
        }
    }

    // used to read in file, set variables and set colormap
    // also adds barcharts into array
    // currentline is the line we are on in the file
    // used to help info into private variables
    // file is the file we are reading in
    void readInFile(string currentLine, ifstream &file) {
        // this line had how many bars were in the frame
        int num = stoi(currentLine);
        BarChart bc(num);
        // going through each bar in frame
        for (int i = 0; i < num; i++) {
            // resetting variables
            string temp = "";
            string name = "";
            int value = 0;
            string category = "";
            int countComma = 0;
            // getting bar data and storing that
            getline(file, currentLine);
            // going through each line to extract data
            // such as name, value and category
            for (int j = 0; j < currentLine.size(); j++) {
                // storing each section of data
                if (currentLine.at(j) != ','){
                    temp.push_back(currentLine.at(j));
                } else {
                    // checking which data we are looking at
                    // stores data in variables
                    if (countComma == 0) {
                        bc.setFrame(temp);
                    } else if (countComma == 1) {
                        name = temp;
                    } else if (countComma == 3) {
                        value = stoi(temp);
                    }
                    temp.clear();
                    countComma++;  // used to keep track of which data
                    if (countComma == 4) {
                        category = currentLine.substr(j + 1, currentLine.size() - j);
                        break;
                    }
                }
            }
            // setting color key if key does not exist
            if (colorMap.count(category) == 0) {
                colorMap.emplace(category, COLORS.at(color));
                color++;
            }
            // going back to beginning of color array since no more new colors
            if (color == 7) {
                color = 0;
            }
            // used to add a barchart with the bars
            bc.addBar(name, value, category);
        }
        // stores the frame as a barchart
        barcharts[size] = bc;
        size++;
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, doubles the capacity
    // file is used to read in and store info
    void addFrame(ifstream &file) {
        // need to allocate more space and allocates space
        if (size == capacity) {
            capacity = capacity * 2;
            BarChart* newBarCharts = new BarChart[capacity];

            for (int i = 0; i < size; i++) {
                newBarCharts[i] = barcharts[i];
                newBarCharts[i].setFrame(barcharts[i].getFrame());
            }
            delete[] barcharts;
            barcharts = newBarCharts;
        }

        string currentLine = "";
        getline(file, currentLine);
        // means new frame is reached
        if (!file.fail()) {
            // means new frame is reached
            if (currentLine.empty()) {
                currentLine = "";
                getline(file, currentLine);
                // only reads file if there is a frame that still exists
                if (!file.eof()) {
                    readInFile(currentLine, file);
                }
            }
        }
    }

    // animate:
    // this function plays each frame stored in barcharts
    // output used to know how to output graphs and info
    // top is used to know how many top bars to print
    // endItr determines how many iterations (frames) to print
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        // go through all iterations/frames
        if (endIter == -1) {
            endIter = size;
        }
        // going through iterations and displaying each frame
        for (int i = 0; i < endIter; i++) {
            usleep(3 * microsecond);
            output << CLEARCONSOLE;
            output << COLORS.at(6) << title << endl;
            output << COLORS.at(6) << source << endl;
            barcharts[i].graph(output, colorMap, top);
            output << COLORS.at(6) << xlabel << endl;
            output << COLORS.at(6) << "Frame: " << barcharts[i].getFrame() << endl;
        }
	}

    // similar as above function but used when user input is provided
    // new varibles is isTop and isForwards
    // isTop is used to know whether to print the top or bottom bars
    // isForwards is used to know to go in time order or backwards
    void userAnimate(ostream &output, int bottomTop, int endIter, bool isTop, bool isForwards) {
        unsigned int microsecond = 50000;
        if (endIter == -1) {
            endIter = size;
        }
        // wants to go in time order
        if (isForwards == true) {
            for (int i = 0; i < endIter; i++) {
                usleep(3 * microsecond);
                output << CLEARCONSOLE;
                output << COLORS.at(6) << title << endl;
                output << COLORS.at(6) << source << endl;
                barcharts[i].userGraph(output, colorMap, bottomTop, isTop);
                output << COLORS.at(6) << xlabel << endl;
                output << COLORS.at(6) << "Frame: " << barcharts[i].getFrame() << endl;
            }
        } else {  // wants in backwards time order
            for (int i = endIter - 1; i >= 0; i--) {
                usleep(3 * microsecond);
                output << CLEARCONSOLE;
                output << COLORS.at(6) << title << endl;
                output << COLORS.at(6) << source << endl;
                barcharts[i].userGraph(output, colorMap, bottomTop, isTop);
                output << COLORS.at(6) << xlabel << endl;
                output << COLORS.at(6) << "Frame: " << barcharts[i].getFrame() << endl;
            }
        }

    }

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        return size;
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throws an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        if (i > size) {
            throw out_of_range("BarChartAnimate: i out of bounds");
        }
        return barcharts[i];
    }
};
