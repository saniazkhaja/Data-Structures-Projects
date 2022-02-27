// bar.h
// This is a bar class that is used to create a bar.
// It has a default and parameter constructor.
// Uses variables name, value and category to keep track of bar.
// Has function to get these functions
// Uses overloading functions to compare values of bars

#include <iostream>
#include <string>
#include "myrandom.h" // used in autograder, do not remove
using namespace std;

// Bar class used to store, get bar values and compare bars
class Bar {
 private:
    // Private member variables for a Bar object
    string name = "";
    int value = 0;
    string category = "";

 public:
    // default constructor:
    Bar() {
        name = "";
        value = 0;
        category = "";
    }

    // Parameter passed in constructor Bar object.
    // Used to store name, value and category as a bar
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
        
    }

    // destructor:
    virtual ~Bar() {
        // not needed
    }

    // getName: used to return name of bar
	string getName() {
        return name;
	}

    // getValue: used to return value of bar
	int getValue() {
        return value;
	}

    // getCategory: used to get the category of the bar
	string getCategory() {
        return category;
	}

	// the following four functions are operators
    // This allows you to compare two Bar objects.
    // Comparison is based on the Bar's value
	bool operator<(const Bar &other) const {
        return (this->value < other.value);
	}

	bool operator<=(const Bar &other) const {
        return (this->value <= other.value);
	}

	bool operator>(const Bar &other) const {
        return (this->value > other.value);
	}

	bool operator>=(const Bar &other) const {
        return (this->value >= other.value);
	}
};

