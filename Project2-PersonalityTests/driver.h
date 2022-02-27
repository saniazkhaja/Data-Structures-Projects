// Name: Sania Khaja
// File: driver.h
// Project 2 - Personality Tests
// CS 251 1pm section
// Date: 2/05/2022
// Description: File handles the behind the scenes calculations
// These calculations consist of normalizing the scores and finding similarity amounts
// Also, sees who is the most similar to the user
// Contains Person and Question structs
// Gets random question


#include <math.h>
#include <limits>
#include <string>
#include <map>
#include <set>
#include "myrandom.h"

using namespace std;

constexpr double lowest_double = std::numeric_limits<double>::lowest();

/* Type: Question
 *
 * Type representing a personality quiz question.
 */
struct Question {
    string questionText;  // Text of the question
    map<char, int> factors;   // Map from factors to +1 or -1
    friend bool operator< (const Question& lhs, const Question& rhs) {
        return lhs.questionText < rhs.questionText;
    }
    friend bool operator== (const Question& lhs, const Question& rhs) {
        return lhs.questionText == rhs.questionText;
    }
    friend bool operator!= (const Question& lhs, const Question& rhs) {
        return lhs.questionText != rhs.questionText;
    }
};

/* Type: Person
 *
 * Type representing a person, used to represent people when determining
 * who's the closest match to the user.
 */
struct Person {
    string name;      // Name of the person
    map<char, int> scores;  // Map from factors to +1 or -1
    friend bool operator< (const Person& lhs,   const Person& rhs) {
        return lhs.name < rhs.name;
    }
    friend bool operator== (const Person& lhs, const Person& rhs) {
        return lhs.name == rhs.name;
    }
    friend bool operator!= (const Person& lhs, const Person& rhs) {
        return lhs.name != rhs.name;
    }
};

/* randomElement
 *
 * This function selects, at random, a Question from the inputted questions set
 * and returns the question.  Note, this function does not remove the randomly
 * selected question from the set.
*/
Question randomElement(set<Question>& questions) {
    int ind = randomInteger(0, (int)questions.size()-1);
    int i = 0;
    for (auto e : questions) {
        if (i == ind) {
            return e;
        }
        i++;
    }
    return {};
}

// used to get a random question from the question set
// removes question from set
// throws error if no questions in the set
// the parameter is to keep the questions in the set
// Returns a Question type which would have the question
Question randomQuestionFrom(set<Question>& questions) {
    Question questionIndex = randomElement(questions);
    // checking if set has questions
    if (questions.empty() == false) {
        questions.erase(questionIndex);
        return questionIndex;
    } else {
        throw runtime_error("Error");
    }
}

// used to calculate scores based on the question and user input
// map contains all the questions and the user input
// the int in map is the user agree/disagree scale
// returns a map of factors with its score
map<char, int> scoresFrom(map<Question, int>& answers) {
    map<char, int> oceanLettersScore;
    // going through each question in map
    for (auto q : answers) {
        Question question = q.first;
        int userNum = q.second;
        int multiplier = userNum - 3;

        // going through each factor in map
        for (auto f : question.factors) {
            char oceanLetter = f.first;
            int oceanNum = f.second;
            // adds entry if key does not exist
            oceanLettersScore.emplace(oceanLetter, 0);
            // adjusting score for particular factor
            oceanLettersScore.at(oceanLetter) += oceanNum * multiplier;
        }
    }
    return oceanLettersScore;
}

// function calculates the normalized scores and stores that in a map for later comparison
// keeps which factor the normalized score is related to
// parameter is used to get the ocean letters and the scores
// returns the map with a factor with the normalized score
map<char, double> normalize(map<char, int>& scores) {
    double normalize = 0;
    map <char, double> normalizedScores;
    // going through each score element adding the squares up
    for (auto const& e : scores) {
        double theNum = e.second;
        normalize += pow(theNum, 2);
    }
    normalize = sqrt(normalize);
    if (normalize == 0) {
        throw runtime_error("Error");
    }
    // calculating and storing normalize in map
    for (auto const &e : scores) {
        char factor = e.first;
        double num = e.second;
        double theNormal = num / normalize;
        normalizedScores.emplace(factor, theNormal);
    }
    return normalizedScores;
}

// function used to see how similar both people's responses were
// parameter maps used for comparison purposes
// returns similarity amount
double cosineSimilarityOf(const map<char, double>& lhs,
                          const map<char, double>& rhs) {
    double similarity = 0;
    for (auto const& e : lhs) {
        // checking to see if factor exists in both maps
        if (rhs.count(e.first) == 0) {
            continue;
        }
        for (auto const& r : rhs) {
            // making sure same factor is multiplied
            if (e.first == r.first) {
                similarity += (e.second * r.second);
                break;
            }
        }
    }
    return similarity;
}

// function uses normalize and cosine similarity
// used to figure out which person user is most similar to
// parameter contains the user score inputs in a map
// next parameter contains name and map of scores in a set
// returns the most similar person to the user
Person mostSimilarTo(map<char, int>& scores, set<Person>& people) {
    Person mostSimilar = {};
    double highestSimilarityScore = -1.0;
    double currentSimilarityScore = -1.0;
    map<char, double> personNormalScores;
    int count = 0;
    const map<char, double> userNormalScores = normalize(scores);

    if (people.empty() == true) {
        throw runtime_error("Error");
    }
    for (auto const& p : people) {
        count++;
        map<char, int> peopleScores = p.scores;
        personNormalScores = normalize(peopleScores);
        currentSimilarityScore = cosineSimilarityOf(userNormalScores, personNormalScores);

        // keeps track of the highest similarity score and the person with that score
        if (currentSimilarityScore > highestSimilarityScore) {
            highestSimilarityScore = currentSimilarityScore;
            mostSimilar = p;
        }
    }
    return mostSimilar;
}
