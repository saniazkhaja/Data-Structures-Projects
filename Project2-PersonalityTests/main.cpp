/*
Author: Sania Khaja
Class: CS 251
Project 2 - Personality Tests
Description: Personality Test app
This file deals with the displaying, storing of data and calling background functions
Reads in question file and personality test file
Displays actual quiz and who/what the user is similar to
Date: 2/05/2022

Creative Component: mine.people -> Different Desserts/Sweets
*/

#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "driver.h"

using namespace std;


// function used to store data into the correct set
// set parameters are used to store data extracted from the current sentence
// isQuestion is used to know which set to store data into
void addQuestionsAndTestsToSet(string currentSentence,
                               set<Question>& allQuestions,
                               set<Person>& allPeople, bool isQuestion) {
    Question theQuestion;
    Person thePerson;
    // needed to know where factors start in the line
    int theSplittingPoint = currentSentence.find('.');
    string theFactors = currentSentence.substr(theSplittingPoint + 1,
                                               currentSentence.size() - 1);
    string updatedString;  // used to know which factor we are on
    // goes through all factors in order to extract each part
    for (int i = 0; i < theFactors.size(); i++) {
        if (theFactors.at(i) == ':') {
            updatedString = theFactors.substr(i + 1, theFactors.size() - i);
            // gets number associated with factor
            string num = theFactors.substr(i + 1, updatedString.find(' '));

            // checking which set to store data in
            if (isQuestion == true) {
                // adding the factor and factor number into the question set map
                theQuestion.factors.insert(pair<char, int>
                        (theFactors.at(i - 1), stoi(num)));
            } else {
                // adding factor and score into the person set map
                thePerson.scores.insert(pair<char, int>
                        (theFactors.at(i - 1), stoi(num)));
            }
        }
    }
    if (isQuestion == true) {
        // getting and storing the question
        theQuestion.questionText = currentSentence.substr(0,
                                                          theSplittingPoint + 1);
        // adding question with factor map into set
        allQuestions.insert(theQuestion);
    } else {
        // getting and storing the name of the person
        thePerson.name = currentSentence.substr(0, theSplittingPoint);
        // adding name and score map to the set
        allPeople.insert(thePerson);
    }
}

// function used to read in file.
// Calls another function to extract and store data
// parameters sets stores data.
// filename used later to know which set to store data in
// return used to exit function
int readInFiles(set<Question>& allQuestions, set<Person>& allPeople, string filename) {
    ifstream inFS;     // Input file stream
    string currentSentence;
    bool isQuestion = false;

    inFS.open(filename);
    if (!inFS.is_open()) {
        cout <<  "**file not found" << endl;
        return 0;  // 0 indicates error
    }
    if (filename == "questions.txt") {
        isQuestion = true;
    }

    // going through whole file
    while (!inFS.eof()) {
        getline(inFS, currentSentence);
        if (!inFS.fail()) {
            // calling function to preform storing of information into sets
            addQuestionsAndTestsToSet(currentSentence, allQuestions,
                                      allPeople, isQuestion);
        }
    }
    return 0;
}

// displays question and then options
// parameter used to know what question to display
void display(Question theQuestion) {
    cout << "How much do you agree with this statement?" << endl;
    cout << '"' << theQuestion.questionText << '"' << endl << endl;
    cout << "1. Strongly disagree\n"
            "2. Disagree\n"
            "3. Neutral\n"
            "4. Agree\n"
            "5. Strongly agree\n" << endl <<
            "Enter your answer here (1-5): " << endl;
}

// function used in order to know which file to read in based on user input
// parameters used to keep track of data
void chooseTest(int userNum, set<Question>& allQuestions,
                set<Person>& allPeople) {
    string filename = "";

    // storing filename based on user input
    if (userNum == 1) {
        filename = "BabyAnimals.people";
    } else if (userNum == 2) {
        filename = "Brooklyn99.people";
    } else if (userNum == 3) {
        filename = "Disney.people";
    } else if (userNum == 4) {
        filename = "Hogwarts.people";
    } else if (userNum == 5) {
        filename = "MyersBriggs.people";
    } else if (userNum == 6) {
        filename = "SesameStreet.people";
    } else if (userNum == 7) {
        filename = "StarWars.people";
    } else if (userNum == 8) {
        filename = "Vegetables.people";
    } else if (userNum == 9) {
        filename = "mine.people";
    }
    readInFiles(allQuestions, allPeople, filename);
}

// keeps track of variables, maps and sets. Stores data
// takes in user input and the calls respective functions
// return used to exit the function
int main() {
    int numOfQuestions = 0;
    int userNum = -1;  // needed in order to know which personality test to use
    int userScoreInput = -1;
    set<Question> allQuestions;
    set<Person> allPeople;
    Question theQuestion;
    Person similarPerson;
    string filename;
    map<Question, int> answersToQuestions;  // users answers
    map<char, int> scores;

    cout << "Welcome to the Personality Quiz!" << endl << endl;
    cout << "Choose number of questions: " << endl;
    cin >> numOfQuestions;
    readInFiles(allQuestions, allPeople, "questions.txt");

    // used to display how many questions the user wanted to answer
    while (numOfQuestions >= 1) {
        theQuestion = randomQuestionFrom(allQuestions);
        display(theQuestion);
        cin >> userScoreInput;
        // storing user answer with respective question in map to use later
        answersToQuestions.insert(pair<Question, int>(theQuestion,
                                                      userScoreInput));
        numOfQuestions--;
    }
    scores = scoresFrom(answersToQuestions);

    // user choosing whether to quit or see which personality they want to see
    while (userNum != 0) {
        allPeople.erase(allPeople.begin(), allPeople.end());
        cout << "1. BabyAnimals\n" "2. Brooklyn99\n" "3. Disney\n"
                "4. Hogwarts\n" "5. MyersBriggs\n" "6. SesameStreet\n"
                "7. StarWars\n" "8. Vegetables\n" "9. mine\n"
                "0. To end program.\n\n"
                "Choose test number (1-9, or 0 to end): " ;
        cin >> userNum;
        if (userNum == 0) {
            cout << "Goodbye!" << endl;
            return 0;
        }
        // calling function to know which file to read in
        chooseTest(userNum, allQuestions, allPeople);
        similarPerson = mostSimilarTo(scores, allPeople);
        cout << "You got " << similarPerson.name << "!" << endl << endl;
    }
    return 0;
}
