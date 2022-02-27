// barchart.h
// Used to display and store all the bars
// Graphs bars, allocates memory for each bar and adds bars to array
// can also get bars and see them
// Utilizes a class and uses bar.h


#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in autograder, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  Used primarily
// in barchartanimate.h
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Replit (dark mode terminal)
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};


// BarChart
// class used to store multiple bars
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;
    
 public:
    // default constructor
    BarChart() {
        capacity = 0;
        size = 0;
        frame = "";
        bars = new Bar[0];
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        capacity = n;
        bars = new Bar[capacity];
        size = 0;
        frame = "";
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
        this->bars = new Bar[other.capacity];
        this->capacity = other.capacity;
        this->size = other.size;
        this->frame = other.frame;

        // used to store each bar in class
        for (int i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];
        }
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
        BarChart bc;
        if (this == &other) {
            return *this;
        }
        delete[] bars;
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        this->frame = other.frame;

        // stores each bar into bar object array in class
        for (int i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];
        }
        
        return *this;
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        capacity = 0;
        size = 0;
        frame = "";
        if (bars != nullptr) {
            delete[] bars;
        }
        bars = new Bar[0];
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {
        if (bars != nullptr) {
            delete[] bars;
        }
    }
    
    // setFrame
    // sets the frame
    void setFrame(string frame) {
    	this->frame = frame;
    }
    
    // getFrame()
    // Returns the frame of the BarChart object.
    string getFrame() {
        return frame;
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is no room
    bool addBar(string name, int value, string category) {
        if (size == capacity) {
            return false;
        }
        Bar b(name, value, category);
        bars[size] = b;
        size++;
        return true;
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        return size;
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        // checking for potential error
        if (i > size) {
            throw out_of_range("BarChart: i out of bounds");
        }
        return bars[i];
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        sort(bars, bars + size, greater<Bar>());
        output << "frame: " << frame << endl;

        // going through all bars and printing that
        for (int i = 0; i < size; i++) {
            output << bars[i].getName() << " " << bars[i].getValue() << " "
            << bars[i].getCategory() << endl;
        }
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
        // sorts from high to low order
        sort(bars, bars + size, greater<Bar>());
        string color = "";

        // going through bars until how many the user wanted
       for (int e = 0; e < top; e++) {
           string barstr = "";
           // calculates how many boxes needed
           double percent = (double) bars[e].getValue() / (double) bars[0].getValue();
           lenMax = (int) (percent * 60.0);

           // checking for color and if no color then defaults to black
           if (colorMap.empty() || colorMap.count(bars[e].getCategory()) == 0) {
               color = "\033[1;37m";
           } else {
               color = colorMap.at(bars[e].getCategory());
           }

           // adding boxes to string
           for (int i = 0; i < lenMax; i++) {
               barstr += BOX;
           }
           // printing put graph
           output << color << barstr << " " << bars[e].getName() << " "
           << bars[e].getValue() << endl;
       }
    }

    // specifically used when user input was used
    // similar to previous graph function
    // addition parameters are isTop
    // isTop is used to determine which way to sort (descending or ascending order)
    // also used to figure out box calculation
    void userGraph(ostream &output, map<string, string> &colorMap, int topBottom, bool isTop) {
        int lenMax = 60;  // this is number of BOXs that should be printed
        // sorts from high to low order
        if (isTop == true) {
            sort(bars, bars + size, greater<Bar>());
        } else {
            // sorts in ascending order
            sort(bars, bars + size);
        }

        string color = "";

        // going through bars until how many the user wanted
        for (int e = 0; e < topBottom; e++) {
            string barstr = "";
            double percent = 0;
            // calculates how many boxes needed
            if (isTop == false) {
                percent = (double) bars[e].getValue() / (double) bars[topBottom - 1].getValue();
            } else {
                percent = (double) bars[e].getValue() / (double) bars[0].getValue();
            }
            lenMax = (int) (percent * 60.0);

            // checking for color and if no color then defaults to black
            if (colorMap.empty() || colorMap.count(bars[e].getCategory()) == 0) {
                color = "\033[1;37m";
            } else {
                color = colorMap.at(bars[e].getCategory());
            }

            // adding boxes to string
            for (int i = 0; i < lenMax; i++) {
                barstr += BOX;
            }
            // printing put graph
            output << color << barstr << " " << bars[e].getName() << " "
                   << bars[e].getValue() << endl;
        }
    }
};

