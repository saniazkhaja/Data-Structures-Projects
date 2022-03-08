#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Sania Khaja";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "EEEWWSSSENNSSWNWN";
const string kPathOutOfTwistyMaze = "EEEEWWSNWWWS";


// Used to see if moves would lead to all items being found or not
// also makes sure that all moves are valid
// looks at each position that user specified
// Parameter start are used to move through linked list
// parameter moves is used to know where to move
bool isPathToFreedom(MazeCell *start, const string& moves) {
    // variables to know which items were found
    bool spellbookFound = false;
    bool potionFound = false;
    bool wandFound = false;

    // checking for errors
    if (start == nullptr) {
        return false;
    }
    // checking for invalid grid moves
    if (moves.size() == 0) {
        return false;
    }
    // checking if start has an item
    if (start -> whatsHere == "Spellbook") {
        spellbookFound = true;
    }
    if (start -> whatsHere == "Potion") {
        potionFound = true;
    }
    if (start -> whatsHere == "Wand") {
        wandFound = true;
    }
    // going through all moves
    for (int i = 0; i < moves.size(); i++) {
        // checking valid move
        if (moves.at(i) == 'N' || moves.at(i) == 'S' ||
            moves.at(i) == 'E' || moves.at(i) == 'W') {
            // seeing which direction to point to and move to
            if (moves.at(i) == 'N') {
                start = start -> north;
            } else if (moves.at(i) == 'S') {
                start = start -> south;
            } else if (moves.at(i) == 'E') {
                start = start -> east;
            } else if (moves.at(i) == 'W') {
                start = start -> west;
            }
            // making sure that the position moved to is valid
            if (start == nullptr) {
                return false;
            }
            // checking for items at position
            if (start -> whatsHere == "Spellbook") {
                spellbookFound = true;
            }
            if (start -> whatsHere == "Potion") {
                potionFound = true;
            }
            if (start -> whatsHere == "Wand") {
                wandFound = true;
            }
        } else {
            return false;
        }
    }
    // checking if all items are found or not
    if (spellbookFound == true && potionFound == true && wandFound == true) {
        return true;
    } else {
        return false;
    }
}
