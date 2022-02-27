#include <iostream>
#include <stack>
#include <fstream>
#include<vector>

using namespace std;

struct Data {
    int numOfGames;
    string monthYear;
};

// passing by value so we do not lose data when doing.pop()
void increase(stack<Data> steamGames) {
    vector<string> incrementing;
    Data theData;
    int prevNum;
    int currentNum;
    string prevDate;
    string currentDate;
    cout << "Months where number of games released increased from the previous month:" << endl;

    // getting top entry which was the most recent date
    theData = steamGames.top();
    // needed for comparing num and storing month
    prevNum = theData.numOfGames;
    prevDate = theData.monthYear;
    steamGames.pop();

    // going through all entries in stack
    while (!steamGames.empty()) {
        // needed for comparing num and storing month
        theData = steamGames.top();
        currentNum = theData.numOfGames;
        currentDate = theData.monthYear;
        steamGames.pop();

        // checking to see if games released increased each month and adding to vector
        // prevNum is technically the more recent date since stacks store most recent entry at the top
        if (prevNum > currentNum) {
            incrementing.push_back(prevDate);
        }
        prevDate = currentDate;
        prevNum = currentNum;
    }
    for (int i = incrementing.size() - 1; i >= 0; i--) {
        cout << incrementing.at(i) << endl;
    }

}

void creative(stack<Data> steamGames) {
    Data theData;
    string userInput;
    cout << "Type in lastEntry to get most recent data: " << endl;
    cin >> userInput;
    if (userInput == "lastEntry") {
        theData = steamGames.top();
        int num = theData.numOfGames;
        string date = theData.monthYear;
        cout << "Last entry was on " << date << " and the number games was " << num << endl;
    }
}

int readInFile(stack<Data>& steamGames, string& header) {
    ifstream inFS;
    string fullLine;
    Data theData;

    inFS.open("student9_DataFiles.txt");
    int counter = 0; // used to keep track of which line
    if (!inFS.is_open()) {
        cout << "**file not found" << endl;
        return 0;  // 0 indicates error
    }
    while (!inFS.eof()) {
        getline(inFS, fullLine);
        if (!inFS.fail()) {
            counter++;
            if(counter > 3) {
                // pushing each data struct into stack
                int findSpace = fullLine.find(' '); // used to know where number and date is seperated
                theData.numOfGames = stoi(fullLine.substr(0, findSpace));
                theData.monthYear = fullLine.substr(findSpace + 1, fullLine.size());
                steamGames.push(theData);
            } else { // to get and store header
                header += " " + fullLine;
            }
        }
    }
    cout << header << endl;
}

int main() {
    stack<Data> steamGames;
    string header;
    readInFile(steamGames, header);
    increase(steamGames);
    creative(steamGames);

    return 0;
}
