// Name: Sania Khaja
// NET-ID: saniak2
// Class: CS 251 1 pm
// Project 1: DNA Profiling
// Creative Portion:
// Called search_name and need to type this to run this code
// Need to have database loaded in order for this command to work as intended
// The name you type also must have the first letter as an uppercase letter
// in order to match the database
// The idea behind search_name is that you want to find a particular person
// in the database and see if they exist. You have the choice to display
// the person's STR counts and what the STR is by typing "yes" or "no" when prompted
// If the person is not found in the database, you will not have this choice
// and it will say this person was not found

#include <fstream>
#include <string>
#include <iostream>
#include "ourvector.h"
using namespace std;

// class that stores the data in the database
class Database {
 public:
    // constructor
    Database() {
        name = {};
        str1 = {};
        str2 = {};
        str3 = {};
        str4 = {};
        str5 = {};
        str6 = {};
        str7 = {};
        str8 = {};
    }
    // qualified constructor for small database
    Database(ourvector<char> theName, ourvector<char> theStr1,
             ourvector<char> theStr2, ourvector<char>theStr3) {
        name = theName;
        str1 = theStr1;
        str2 = theStr2;
        str3 = theStr3;
    }
    // qualified constructor for large database
    Database(ourvector<char> theName, ourvector<char> theStr1,
             ourvector<char> theStr2, ourvector<char>theStr3,
             ourvector<char> theStr4, ourvector<char> theStr5,
             ourvector<char> theStr6, ourvector<char> theStr7,
             ourvector<char> theStr8) {
        name = theName;
        str1 = theStr1;
        str2 = theStr2;
        str3 = theStr3;
        str4 = theStr4;
        str5 = theStr5;
        str6 = theStr6;
        str7 = theStr7;
        str8 = theStr8;
    }
    // the following are get functions
    // used to get name and STRs when needed
    ourvector<char> getName() {
        return name;
    }
    ourvector<char> getStr1() {
        return str1;
    }
    ourvector<char> getStr2() {
        return str2;
    }
    ourvector<char> getStr3() {
        return str3;
    }
    ourvector<char> getStr4() {
        return str4;
    }
    ourvector<char> getStr5() {
        return str5;
    }
    ourvector<char> getStr6() {
        return str6;
    }
    ourvector<char> getStr7() {
        return str7;
    }
    ourvector<char> getStr8() {
        return str8;
    }

 private:
    // all variables are char ourvectors to store information from database
    ourvector<char> name;
    ourvector<char> str1;
    ourvector<char> str2;
    ourvector<char> str3;
    ourvector<char> str4;
    ourvector<char> str5;
    ourvector<char> str6;
    ourvector<char> str7;
    ourvector<char> str8;
};

// this function is used to print out the data from the large file
// the data in the database is passed by reference
// i is which index (person in the database) we are on
void displayLargeFileData(ourvector<Database>& theData, int i) {
    cout << " ";
    // getting the 4th STR of person i from database class
    ourvector<char> tempData = theData.at(i).getStr4();
    // looping through the 4th STR and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    cout << " ";
    // getting the 5th STR of person i from database class
    tempData = theData.at(i).getStr5();
    // looping through the 5th STR and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    cout << " ";
    // getting the 6th STR of person i from database class
    tempData = theData.at(i).getStr6();
    // looping through the 6th STR and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    cout << " ";
    // getting the 7th STR of person i from database class
    tempData = theData.at(i).getStr7();
    // looping through the 7th STR and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    cout << " ";
    // getting the 8th STR of person i from database class
    tempData = theData.at(i).getStr8();
    // looping through the 8th STR and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
}

// this function is used to print out the data from the small file
// checks if data needs to be printed from the large file
// the data in the database is passed by reference
// i is which index (person in the database) we are on
// filename is used to know if data from the large file needs to be printed
void displayFileData(ourvector<Database>& theData, int i, string filename) {
    // getting the name of person i from database class
    ourvector<char> tempData = theData.at(i).getName();
    // looping through the name ourvector and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    cout << " ";
    // getting the 1st STR of person i from database class
    tempData = theData.at(i).getStr1();
    // looping through the 1st STR ourvector and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    cout << " ";
    // getting the 2nd STR of person i from database class
    tempData = theData.at(i).getStr2();
    // looping through the 2nd STR ourvector and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    cout << " ";
    // getting the 3rd STR of person i from database class
    tempData = theData.at(i).getStr3();
    // looping through the 3rd STR ourvector and displaying it
    for (int j = 0; j < tempData.size(); j++) {
        cout << tempData.at(j);
    }
    // checking to if large database was selected
    if (filename == "large.txt") {
        // used to display the rest of the data in the large database file
        displayLargeFileData(theData, i);
    }
}

// used to display the DNA sequence from chosen file
// passes DNAData to display the DNA sequence
void displayDNA(ourvector<char>& DNAData) {
    for (int i = 0; i < DNAData.size(); i++) {
        cout << DNAData.at(i);
    }
    cout << endl << endl;
}

// used to determine the STR counts by looking in the DNA data
// finds what the longest sequence for a particular STR is and stores that
// uses a STRCount parameter to store the data
// looks at the DNAData to find the longest consecutive sequence of an STR
// theSTR is used to know which STR to look for in the DNA
void determineSTRCounts(ourvector<int>& STRCount,
                        ourvector<char>& DNAData, ourvector<char>& theSTR) {
    // creating storage space for STR
    STRCount.push_back(0);
    // to keep track of the highest consecutive number for the STR
    int currentConsecutiveAmount = 0;

    // looping through the whole DNA
    for (int i = 0; i < DNAData.size() - theSTR.size() + 1; i++) {
        // used to keep track of how much of STR is matching to DNA
        int tempCounter = 0;
        // looping through each index of the STR
        for (int j = 0; j < theSTR.size(); j++) {
            // checking to see if the STR and DNA sequence match
            if (theSTR.at(j) == DNAData.at(j + i)) {
                tempCounter++;
            } else {
                currentConsecutiveAmount = 0;
                break;
            }
        }
        // means one match of the STR was found in the DNA
        if (tempCounter == theSTR.size()) {
            currentConsecutiveAmount++;
            // incrementing to skip the DNA that was looked at since match was found
            i = i + theSTR.size() - 1;
            // checking to see if the current highest STR count is still the highest count
            if (STRCount.at(STRCount.size() - 1) < currentConsecutiveAmount) {
                // updates the consecutive count for the current STR
                STRCount.at(STRCount.size() - 1) = currentConsecutiveAmount;
            }
        }
    }
}

// used to go through each STR and find the highest count in the DNA for the STR
// theData is needed to know the STR sequence
// the STR sequence has to be found in the DNAData
// STRCount is used to keep track of the highest count for each STR in the DNA
// filename is used to determine how many STR are needed to be looked at
// databaseLoaded and DNALoaded is used to see if necessary info is present
// DNAProcessed is used to update if the DNA has been processed or not
// return value is used to exit the function
int processSTRCounts(ourvector<Database>& theData, ourvector<char>& DNAData,
                     ourvector<int>& STRCount, string filename,
                     bool databaseLoaded, bool DNALoaded, bool& DNAProcessed) {
    // checking to see if database was loaded or not
    if (databaseLoaded == false) {
        cout << "No database loaded." << endl;
        return 0;
    }
    if (DNALoaded == false) {
        cout << "No DNA loaded." << endl;
        return 0;
    }
    cout << "Processing DNA..." << endl;
    // the following code is going through each STR in the database
    // then calls function to determine the highest STR count for each STR
    ourvector<char> theSTR = theData.at(0).getStr1();
    determineSTRCounts(STRCount, DNAData, theSTR);
    theSTR = theData.at(0).getStr2();
    determineSTRCounts(STRCount, DNAData, theSTR);
    theSTR = theData.at(0).getStr3();
    determineSTRCounts(STRCount, DNAData, theSTR);

    // checking for large file in order to go through the rest of the STRs
    if (filename == "large.txt") {
        // the following code is going through each STR in the large database
        // then calls function to determine the highest STR count for each STR
        theSTR =  theData.at(0).getStr4();
        determineSTRCounts(STRCount, DNAData, theSTR);
        theSTR =  theData.at(0).getStr5();
        determineSTRCounts(STRCount, DNAData, theSTR);
        theSTR = theData.at(0).getStr6();
        determineSTRCounts(STRCount, DNAData, theSTR);
        theSTR = theData.at(0).getStr7();
        determineSTRCounts(STRCount, DNAData, theSTR);
        theSTR = theData.at(0).getStr8();
        determineSTRCounts(STRCount, DNAData, theSTR);
    }
    DNAProcessed = true;
    return 0;
}

// Displays STR and then the highest consecutive count for the STR
// Goes through each STR in database
// needs theData to display actual STR
// STRCount is used to display the highest consecutive count for the STR
// filename is used to determine if more STRs need to be displayed
void displaySTRCounts(ourvector<Database>& theData, ourvector<int>& STRCount,
                      string filename) {
    // displays the 1st STR and count
    for (int i = 0; i < theData.at(0).getStr1().size(); i++) {
        cout <<theData.at(0).getStr1().at(i);
    }
    cout << ": " << STRCount.at(0) << endl;
    // displays the 2nd STR and count
    for (int i = 0; i < theData.at(0).getStr2().size(); i++) {
        cout <<theData.at(0).getStr2().at(i);
    }
    cout << ": " << STRCount.at(1) << endl;
    // displays the 3rd STR and count
    for (int i = 0; i < theData.at(0).getStr3().size(); i++) {
        cout <<theData.at(0).getStr3().at(i);
    }
    cout << ": " << STRCount.at(2) << endl;
    // checking for large file to display rest of the STRs
    if (filename == "large.txt") {
        // displays the 4th STR and count
        for (int i = 0; i < theData.at(0).getStr4().size(); i++) {
            cout <<theData.at(0).getStr4().at(i);
        }
        cout << ": " << STRCount.at(3) << endl;
        // displays the 5th STR and count
        for (int i = 0; i < theData.at(0).getStr5().size(); i++) {
            cout <<theData.at(0).getStr5().at(i);
        }
        cout << ": " << STRCount.at(4) << endl;
        // displays the 6th STR and count
        for (int i = 0; i < theData.at(0).getStr6().size(); i++) {
            cout <<theData.at(0).getStr6().at(i);
        }
        cout << ": " << STRCount.at(5) << endl;
        // displays the 7th STR and count
        for (int i = 0; i < theData.at(0).getStr7().size(); i++) {
            cout <<theData.at(0).getStr7().at(i);
        }
        cout << ": " << STRCount.at(6) << endl;
        // displays the 8th STR and count
        for (int i = 0; i < theData.at(0).getStr8().size(); i++) {
            cout <<theData.at(0).getStr8().at(i);
        }
        cout << ": " << STRCount.at(7) << endl;
    }
    cout << endl;
}

// used to display data based on what information was loaded
// calls respective functions to display information
// the first three booleans are used to see what data was loaded
// filename and DNAFilename is used to know what to display
// theData, DNAData and STRCount is what has the data stored
void displayData(bool databaseLoaded, bool DNALoaded, bool DNAProcessed,
                 const string & filename, ourvector<Database>& theData,
                 ourvector<char>& DNAData,
                 ourvector<int>& STRCount, string DNAFilename) {
    // checking if data loaded and displays info it is
    if (databaseLoaded == true) {
        cout << "Database loaded: " << endl;
        // going through each person in the database
        for (int i = 1; i < theData.size(); i++) {
            displayFileData(theData, i, filename);
            cout << endl;
        }
    } else {
        cout << "No database loaded." << endl;
    }
    cout << endl;
    // checking if DNA is not loaded and gives a message accordingly
    if (DNALoaded == false) {
        cout << "No DNA loaded." << endl << endl;
    } else {
        cout << "DNA loaded: " << endl;
        displayDNA(DNAData);
    }
    // checking if DNA is not processed and gives a message accordingly
    if (DNAProcessed == false) {
        cout << "No DNA has been processed." << endl;
    } else {
        cout << "DNA processed, STR counts: " << endl;
        displaySTRCounts(theData, STRCount, filename);
    }
}

// return used to exit function
// the function is used to read and store the database in the database class
// filename is used to know which file to open
// databaseLoaded is updated based on if the database was read in
// theData is what stores the info from the file database
int readInDatabase(string filename, bool& databaseLoaded,
                   ourvector<Database>& theData) {
    ifstream inFS;
    char theChar;
    ourvector< ourvector<char> > fullLineData;
    ourvector<char> tempCharData;

    cout << "Loading database..." << endl;
    inFS.open(filename);
    if (!inFS.is_open()) {
        cout <<  "Error: unable to open " << "'" << filename << "'" << endl;
        return 0;
    }
    databaseLoaded = true;
    while (!inFS.eof() && !inFS.fail()) {
        inFS.get(theChar);
        if (!inFS.fail()) {
            Database newData;
            // pushing back chars till comma or end of line
            if (theChar != ',' && theChar != '\n') {
                tempCharData.push_back(theChar);
            }
            // pushing back each person's data
            if (theChar == ',' || theChar == '\n') {
                fullLineData.push_back(tempCharData);
                tempCharData.clear();
            }
            if (theChar == '\n') {
                // seeing which qualified constructor is needed
                if (filename == "small.txt") {
                    newData = {fullLineData.at(0), fullLineData.at(1),
                               fullLineData.at(2), fullLineData.at(3)};
                }
                else {
                    newData = {fullLineData.at(0), fullLineData.at(1),
                               fullLineData.at(2), fullLineData.at(3),
                               fullLineData.at(4),
                               fullLineData.at(5),fullLineData.at(6),
                               fullLineData.at(7), fullLineData.at(8)};
                }
                // pushing object into a class vector
                theData.push_back(newData);
                fullLineData.clear();
            }
        }
    }
    return 0;
}

// return is used to exit the function
// the function saves the DNA an ourvector by reading the file
// DNAFilename is used to know which file to read in and save
// DNALoaded is to keep track of whether the file was opened
// DNAData is what stores the actual data in the file
int loadInDNA(string DNAFilename, bool& DNALoaded, ourvector<char>& DNAData) {
    ifstream inFS;
    char theChar;

    cout << "Loading DNA..." << endl;
    inFS.open(DNAFilename);
    if (!inFS.is_open()) {
        cout <<  "Error: unable to open " << "'" << DNAFilename << "'" << endl;
        return 0;
    }
    DNALoaded = true;

    // DNA is being added to vector
    while (!inFS.eof() && !inFS.fail()) {
        inFS.get(theChar);
        if (!inFS.fail()) {
            DNAData.push_back(theChar);
        }
    }
    return 0;
}

// this is used to convert the rest of the STR counts in the large file
// converts to ourvector<string>
// theData is used to get the STR numbers for each person
// dataNumbers stores the STR numbers as an ourvector<string>
// i is each person in the database
void largeFileGettingNumbers(ourvector<Database>& theData,
                             ourvector<string>& dataNumbers, int i) {
    string dataNumber = "";
    // going through each str num and making it a string
    // then pushing string into ourvector to use for comparison later
    for (int j = 0; j < theData.at(i).getStr4().size(); j++) {
        dataNumber.push_back(theData.at(i).getStr4().at(j));
    }
    dataNumbers.push_back(dataNumber);

    dataNumber = "";
    for (int j = 0; j < theData.at(i).getStr5().size(); j++) {
        dataNumber.push_back(theData.at(i).getStr5().at(j));
    }
    dataNumbers.push_back(dataNumber);

    dataNumber = "";
    for (int j = 0; j < theData.at(i).getStr6().size(); j++) {
        dataNumber.push_back(theData.at(i).getStr6().at(j));
    }
    dataNumbers.push_back(dataNumber);

    dataNumber = "";
    for (int j = 0; j < theData.at(i).getStr7().size(); j++) {
        dataNumber.push_back(theData.at(i).getStr7().at(j));
    }
    dataNumbers.push_back(dataNumber);

    dataNumber = "";
    for (int j = 0; j < theData.at(i).getStr8().size(); j++) {
        dataNumber.push_back(theData.at(i).getStr8().at(j));
    }
    dataNumbers.push_back(dataNumber);
}

// checks if the DNA STR numbers and person STR numbers matched
// displays if there was match or not and who the match was
// bool return used to know if match was found and break out of loop
// dataNumbers and STRNum are compared to see if the numbers are matched
// theData and i (person) is used to print a name if needed
bool checkForSTRMatch(ourvector<string>& dataNumbers, int i,
                      ourvector<string>& STRNum, bool& STRMatched,
                      ourvector<Database>& theData) {
    int STRMatchedCounter = 0;
    // goes through each STR and checking if the STR numbers matched
    for (int r = 0; r < STRNum.size(); r++) {
        if (STRNum.at(r) == dataNumbers.at(r)) {
            STRMatchedCounter++;
        }
        if (STRMatchedCounter == dataNumbers.size()) {
            STRMatched = true;
        }
    }
    if (STRMatched == true) {
        cout << "Found in database!  DNA matches: ";
        for (int j = 0; j < theData.at(i).getName().size(); j++) {
            cout << theData.at(i).getName().at(j);
        }
        cout << endl;
        return true;
    }
}

// goes through each STR number in data and stores as string for comparison
// theData is needed in order to get each STR number
// dataNumbers and STRNum stores the STR numbers to compare
// the filename helps with knowing how many ST's need to be looked at
void gettingNumbers(ourvector<Database>& theData,
                    ourvector<string>& dataNumbers,
                    string filename, ourvector<string>& STRNum) {
    bool STRMatched = false;
    // going through each person
    for (int i = 1; i < theData.size(); i++) {
        string dataNumber = "";
        dataNumbers.clear();
        // going through each str num and making it a string
        // then pushing string into ourvector to use for comparison later
        for (int j = 0; j < theData.at(i).getStr1().size(); j++) {
            dataNumber.push_back(theData.at(i).getStr1().at(j));
        }
        dataNumbers.push_back(dataNumber);

        dataNumber = "";
        for (int j = 0; j < theData.at(i).getStr2().size(); j++) {
            dataNumber.push_back(theData.at(i).getStr2().at(j));
        }
        dataNumbers.push_back(dataNumber);

        dataNumber = "";
        for (int j = 0; j < theData.at(i).getStr3().size(); j++) {
            dataNumber.push_back(theData.at(i).getStr3().at(j));
        }
        dataNumbers.push_back(dataNumber);
        // used to also convert numbers to ourvector<string>
        if (filename == "large.txt") {
            largeFileGettingNumbers(theData, dataNumbers, i);
        }
        if (checkForSTRMatch(dataNumbers, i, STRNum, STRMatched, theData) == true) {
            break;
        }
    }
    if (STRMatched == false) {
        cout << "Not found in database." << endl;
    }
}

// return is used to exit function if there isn't enough data
// function checks for enough data and converts STRCount to string ourvectors
// Calls another function to compare person STR and DNA STR count
// databaseLoaded, DNALoaded, DNAProcessed are used to check if sufficient info is present
// theData is needed to look at each person STR
// STRCount has how many of each STR is present in the DNA
// filename lets us know which database was used
int searchDatabase(bool databaseLoaded, bool DNALoaded,
                   bool DNAProcessed, ourvector<Database>& theData,
                   ourvector<int>& STRCount, string filename) {
    ourvector<string> dataNumbers;
    ourvector<string> STRNum;
    if (databaseLoaded == false) {
        cout << "No database loaded." << endl;
        return 0;
    }
    if (DNALoaded == false) {
        cout << "No DNA loaded." << endl;
        return 0;
    }

    if (DNAProcessed == false) {
        cout << "No DNA processed." << endl;
        return 0;
    }
    cout << "Searching database..." << endl;
    // convert str count into string numbers
    for (int i = 0; i < STRCount.size(); i++) {
        STRNum.push_back(to_string(STRCount.at(i)));
    }
    gettingNumbers(theData, dataNumbers, filename, STRNum);
    return 0;
}

// used to display the STR and then the STR number of one particular individual
// i is the person who we are displaying and person who the user looked up
// theData is used to get the STR and then the number associated with the STR
void displayLargeSTRWithCount(int i, ourvector<Database>& theData) {
    // prints STR name
    for (int r = 0; r < theData.at(0).getStr4().size(); r++) {
        cout << theData.at(0).getStr4().at(r);
    }
    cout << ": ";
    // prints STR number of individual i
    for (int s = 0; s < theData.at(i).getStr4().size(); s++) {
        cout << theData.at(i).getStr4().at(s);
    }
    cout << endl;

    for (int r = 0; r < theData.at(0).getStr5().size(); r++) {
        cout << theData.at(0).getStr5().at(r);
    }
    cout << ": ";
    for (int s = 0; s < theData.at(i).getStr5().size(); s++) {
        cout << theData.at(i).getStr5().at(s);
    }
    cout << endl;

    for (int r = 0; r < theData.at(0).getStr6().size(); r++) {
        cout << theData.at(0).getStr6().at(r);
    }
    cout << ": ";
    for (int s = 0; s < theData.at(i).getStr6().size(); s++) {
        cout << theData.at(i).getStr6().at(s);
    }
    cout << endl;

    for (int r = 0; r < theData.at(0).getStr7().size(); r++) {
        cout << theData.at(0).getStr7().at(r);
    }
    cout << ": ";
    for (int s = 0; s < theData.at(i).getStr7().size(); s++) {
        cout << theData.at(i).getStr7().at(s);
    }
    cout << endl;

    for (int r = 0; r < theData.at(0).getStr8().size(); r++) {
        cout << theData.at(0).getStr8().at(r);
    }
    cout << ": ";
    for (int s = 0; s < theData.at(i).getStr8().size(); s++) {
        cout << theData.at(i).getStr8().at(s);
    }
    cout << endl;
}

// used in order to display the STR name and STR count of a particular person
// i is the person who we are displaying and person who the user looked up
// theData is used to get the STR and then the number associated with the STR
// filename is used to determine if more STRs need to be printed
void displaySTRWithCounts(int i, ourvector<Database>& theData, string theName, string filename) {
    cout << "The following is the STR count for " << theName << ": " << endl;
    // printing str name
    for (int r = 0; r < theData.at(0).getStr1().size(); r++) {
        cout << theData.at(0).getStr1().at(r);
    }
    cout << ": ";
    // printing str number
    for (int s = 0; s < theData.at(i).getStr1().size(); s++) {
        cout << theData.at(i).getStr1().at(s);
    }
    cout << endl;

    for (int r = 0; r < theData.at(0).getStr2().size(); r++) {
        cout << theData.at(0).getStr2().at(r);
    }
    cout << ": ";
    for (int s = 0; s < theData.at(i).getStr2().size(); s++) {
        cout << theData.at(i).getStr2().at(s);
    }
    cout << endl;

    for (int r = 0; r < theData.at(0).getStr3().size(); r++) {
        cout << theData.at(0).getStr3().at(r);
    }
    cout << ": ";
    for (int s = 0; s < theData.at(i).getStr3().size(); s++) {
        cout << theData.at(i).getStr3().at(s);
    }
    cout << endl;

    if (filename == "large.txt") {
        displayLargeSTRWithCount(i, theData);
    }
}

// checks if the name the user input exists in the database
// theData needed to find the name
// i is needed to look through each person in the database
// return bool is used to determine if the name was found in the database or not
bool checkForName(int i, string theName, ourvector<Database>& theData) {
    int sameLetterCounter = 0; // used to see if all chars in name match
    // looking through each char in name
    for (int j = 0; j < theName.size(); j++) {
        if (theData.at(i).getName().at(j) == theName.at(j)) {
            sameLetterCounter++;
        }
    }
    if(sameLetterCounter == theName.size()) {
        return true;
    }
    else {
        return false;
    }
}

// checks if a database is loaded and if it is then searches for the name the user inputted
// calls respective functions for checking for the name and then displaying if conditions are met
// database loaded is used to know if needed information is present
// theData contains the names of the people
// filename is used to know which database was used
void searchForName(bool databaseLoaded, ourvector<Database>& theData, string filename) {
    string theName;
    string yesNo;
    bool nameFound = false;

    if (databaseLoaded == false) {
       cout << "No database loaded. Load database to search for name" << endl;
    } else {
        cout << "Input the name you want to search: "
                "First letter of name must be uppercase. " << endl;
        cin >> theName;
        for (int i = 0; i < theData.size(); i++) {
            if (theName.size() == theData.at(i).getName().size()) {
                nameFound = checkForName(i, theName, theData);
            }
            if (nameFound == true) {
                cout << theName << " was found. Would you like to see their STR counts?"
                        " Type yes or no." << endl;
                cin >> yesNo;
                if (yesNo == "yes") {
                    displaySTRWithCounts(i,theData, theName, filename);
                }
                break;
            }
        }
        if (nameFound == false) {
            cout << theName << " not found." << endl;
        }
    }
}

// looks at user input and calls respective functions
// function stores data
// return value is used to exit program
int main() {
    string userInput;
    string filename;
    string DNAFilename;
    // stores needed data
    ourvector<Database> theData;
    ourvector<char> DNAData;
    ourvector<int> STRCount;
    // variables to keep track of what is loaded and not
    bool databaseLoaded = false;
    bool DNALoaded = false;
    bool DNAProcessed = false;
    bool inProgress = true;

    cout << "Welcome to the DNA Profiling Application." << endl;
    // checking if program still needs to run
    while (inProgress == true) {
        cout << "Enter command or # to exit: ";
        cin >> userInput;

        // the following if statements look at the user input
        // determines what needs to be done based on the input
        if (userInput == "load_db") {
            theData.clear();
            cin >> filename;
            readInDatabase(filename, databaseLoaded, theData);
        } else if (userInput == "display") {
            displayData(databaseLoaded, DNALoaded, DNAProcessed,
            filename, theData, DNAData, STRCount, DNAFilename);
        } else if (userInput == "load_dna") {
            DNAData.clear();
            cin >> DNAFilename;
            loadInDNA(DNAFilename, DNALoaded, DNAData);
        } else if (userInput == "process") {
            processSTRCounts(theData, DNAData, STRCount, filename, databaseLoaded, DNALoaded, DNAProcessed);
        } else if (userInput == "search") {
            searchDatabase(databaseLoaded, DNALoaded, DNAProcessed, theData, STRCount, filename);
        } else if (userInput == "#") {
            inProgress = false;
            return 0;
        } else if (userInput == "search_name") {
            searchForName(databaseLoaded, theData, filename);
        }
    }
}

