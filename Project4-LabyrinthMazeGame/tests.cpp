#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"
#include <string>


TEST(grid, defaultConstructor){
    Grid<int> trial1;
    Grid<char> trial2;
    Grid<string> trial3;
    Grid<bool> trial4;
    Grid<double> trial5;
    Grid<float> trial6;

    EXPECT_EQ(trial1.size(), 16);
    EXPECT_EQ(trial1.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(trial1.numcols(i), 4);
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            EXPECT_EQ(trial1(r, c), 0);
        }
    }

    EXPECT_EQ(trial2.size(), 16);
    EXPECT_EQ(trial2.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(trial2.numcols(i), 4);
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            EXPECT_EQ(trial2(r, c), 0);
        }
    }

    EXPECT_EQ(trial3.size(), 16);
    EXPECT_EQ(trial3.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(trial3.numcols(i), 4);
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            EXPECT_EQ(trial3(r, c), "");
        }
    }

    EXPECT_EQ(trial4.size(), 16);
    EXPECT_EQ(trial4.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(trial4.numcols(i), 4);
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            EXPECT_EQ(trial4(r, c), 0);
        }
    }

    EXPECT_EQ(trial5.size(), 16);
    EXPECT_EQ(trial5.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(trial5.numcols(i), 4);
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            EXPECT_EQ(trial5(r, c), 0);
        }
    }


    EXPECT_EQ(trial6.size(), 16);
    EXPECT_EQ(trial6.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(trial6.numcols(i), 4);
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            EXPECT_EQ(trial6(r, c), 0);
        }
    }
}


TEST(grid, parameterizedConstructor){
    int R = 5;
    int C = 6;
    Grid<int> trial7(R, C);
    Grid<char> trial8(R, C);
    Grid<string> trial9(R, C);
    Grid<bool> trial10(R, C);
    Grid<double> trial11(R, C);
    Grid<float> trial12(R, C);

    EXPECT_EQ(trial7.size(), R * C);
    EXPECT_EQ(trial7.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial7.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial7(r, c), 0);
        }
    }

    EXPECT_EQ(trial8.size(), R * C);
    EXPECT_EQ(trial8.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial8.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial8(r, c), 0);
        }
    }

    EXPECT_EQ(trial9.size(), R * C);
    EXPECT_EQ(trial9.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial9.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial9(r, c), "");
        }
    }

    EXPECT_EQ(trial10.size(), R * C);
    EXPECT_EQ(trial10.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial10.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial10(r, c), 0);
        }
    }

    EXPECT_EQ(trial11.size(), R * C);
    EXPECT_EQ(trial11.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial11.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial11(r, c), 0);
        }
    }

    EXPECT_EQ(trial12.size(), R * C);
    EXPECT_EQ(trial12.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial12.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial12(r, c), 0);
        }
    }
}

TEST(grid, parameterizedConstructor1){
    int R = 10;
    int C = 10;
    Grid<int> trial7(R, C);
    Grid<char> trial8(R, C);
    Grid<string> trial9(R, C);
    Grid<bool> trial10(R, C);
    Grid<double> trial11(R, C);
    Grid<float> trial12(R, C);

    EXPECT_EQ(trial7.size(), R * C);
    EXPECT_EQ(trial7.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial7.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial7(r, c), 0);
        }
    }

    EXPECT_EQ(trial8.size(), R * C);
    EXPECT_EQ(trial8.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial8.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial8(r, c), 0);
        }
    }

    EXPECT_EQ(trial9.size(), R * C);
    EXPECT_EQ(trial9.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial9.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial9(r, c), "");
        }
    }

    EXPECT_EQ(trial10.size(), R * C);
    EXPECT_EQ(trial10.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial10.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial10(r, c), 0);
        }
    }

    EXPECT_EQ(trial11.size(), R * C);
    EXPECT_EQ(trial11.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial11.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial11(r, c), 0);
        }
    }

    EXPECT_EQ(trial12.size(), R * C);
    EXPECT_EQ(trial12.numrows(), R);
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial12.numcols(i), C);
    }
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            EXPECT_EQ(trial12(r, c), 0);
        }
    }
}

TEST(grid, copyConstructor) {
    int counter = 0;
    int R = 4;
    int C = 4;
    Grid<int> trial7(R, C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            trial7(i, j) = counter;
            counter++;
        }
    }
    Grid<int> copyTrial7(trial7);

    EXPECT_EQ(trial7.numrows(), R);
    EXPECT_EQ(copyTrial7.numrows(), R);
    EXPECT_EQ(trial7.numrows(), copyTrial7.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial7.numcols(i), C);
        EXPECT_EQ(copyTrial7.numcols(i), C);
        EXPECT_EQ(copyTrial7.numcols(i), trial7.numcols(i));
    }

    //checks each val if they are the same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial7(i, j), copyTrial7(i, j));
        }
    }
    // changing value of 1 and making sure only one of them changed
    trial7(0, 0) = 100;
    EXPECT_EQ(trial7(0, 0), 100);
    EXPECT_EQ(copyTrial7(0, 0), 0);


    R = 9;
    C = 5;
    Grid<char> trial8(R, C);
    Grid<char> copyTrial8(trial8);
    EXPECT_EQ(trial8.numrows(), R);
    EXPECT_EQ(copyTrial8.numrows(), R);
    EXPECT_EQ(trial8.numrows(), copyTrial8.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial8.numcols(i), C);
        EXPECT_EQ(copyTrial8.numcols(i), C);
        EXPECT_EQ(copyTrial8.numcols(i), trial8.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial8(i, j), copyTrial8(i, j));
        }
    }

    // checking to make sure both matrices change seperatly
    trial8(0,0) = 'a';
    EXPECT_EQ(trial8(0, 0), 'a');
    EXPECT_EQ(copyTrial8(0, 0), 0);


    R = 3;
    C = 3;
    Grid<string> trial9(R, C);
    Grid<string> copyTrial9(trial9);
    EXPECT_EQ(trial9.numrows(), R);
    EXPECT_EQ(copyTrial9.numrows(), R);
    EXPECT_EQ(trial9.numrows(), copyTrial9.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial9.numcols(i), C);
        EXPECT_EQ(copyTrial9.numcols(i), C);
        EXPECT_EQ(copyTrial9.numcols(i), trial9.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial9(i, j), copyTrial9(i, j));
        }
    }

    trial9(0,0) = "Yay";
    EXPECT_EQ(trial9(0, 0), "Yay");
    EXPECT_EQ(copyTrial9(0, 0), "");

    R = 6;
    C = 8;
    Grid<bool> trial10(R, C);
    Grid<bool> copyTrial10(trial10);
    EXPECT_EQ(trial10.numrows(), R);
    EXPECT_EQ(copyTrial10.numrows(), R);
    EXPECT_EQ(trial10.numrows(), copyTrial10.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial10.numcols(i), C);
        EXPECT_EQ(copyTrial10.numcols(i), C);
        EXPECT_EQ(copyTrial10.numcols(i), trial10.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial10(i, j), copyTrial10(i, j));
        }
    }

    trial10(0,0) = 1;
    EXPECT_EQ(trial10(0, 0), 1);
    EXPECT_EQ(copyTrial10(0, 0), 0);


    R = 10;
    C = 2;
    Grid<double> trial11(R, C);
    Grid<double> copyTrial11(trial11);
    EXPECT_EQ(trial11.numrows(), R);
    EXPECT_EQ(copyTrial11.numrows(), R);
    EXPECT_EQ(trial11.numrows(), copyTrial11.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial11.numcols(i), C);
        EXPECT_EQ(copyTrial11.numcols(i), C);
        EXPECT_EQ(copyTrial11.numcols(i), trial11.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial11(i, j), copyTrial11(i, j));
        }
    }

    trial11(0,0) = 1;
    EXPECT_EQ(trial11(0, 0), 1);
    EXPECT_EQ(copyTrial11(0, 0), 0);


    R = 2;
    C = 10;
    Grid<float> trial12(R, C);
    Grid<float> copyTrial12(trial12);
    EXPECT_EQ(trial12.numrows(), R);
    EXPECT_EQ(copyTrial12.numrows(), R);
    EXPECT_EQ(trial12.numrows(), copyTrial12.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial12.numcols(i), C);
        EXPECT_EQ(copyTrial12.numcols(i), C);
        EXPECT_EQ(copyTrial12.numcols(i), trial12.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial12(i, j), copyTrial12(i, j));
        }
    }

    trial12(0,0) = 1;
    EXPECT_EQ(trial12(0, 0), 1);
    EXPECT_EQ(copyTrial12(0, 0), 0);
}

TEST(grid, copyEqual) {
    int counter = 0;
    int R = 4;
    int C = 5;
    Grid<int> trial7(R, C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            trial7(i, j) = counter;
            counter++;
        }
    }
    Grid<int> copyTrial7;
    copyTrial7 = trial7;

    EXPECT_EQ(trial7.numrows(), R);
    EXPECT_EQ(copyTrial7.numrows(), R);
    EXPECT_EQ(trial7.numrows(), copyTrial7.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial7.numcols(i), C);
        EXPECT_EQ(copyTrial7.numcols(i), C);
        EXPECT_EQ(copyTrial7.numcols(i), trial7.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial7(i, j), copyTrial7(i, j));
        }
    }
    // changes value and makes sure only one of them changes
    trial7(0, 0) = 100;
    EXPECT_EQ(trial7(0, 0), 100);
    EXPECT_EQ(copyTrial7(0, 0), 0);


    R = 9;
    C = 5;
    Grid<char> trial8(R, C);
    Grid<char> copyTrial8;
    copyTrial8 = trial8;
    EXPECT_EQ(trial8.numrows(), R);
    EXPECT_EQ(copyTrial8.numrows(), R);
    EXPECT_EQ(trial8.numrows(), copyTrial8.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial8.numcols(i), C);
        EXPECT_EQ(copyTrial8.numcols(i), C);
        EXPECT_EQ(copyTrial8.numcols(i), trial8.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial8(i, j), copyTrial8(i, j));
        }
    }

    // checking to make sure both matrices change seperatly
    trial8(0,0) = 'a';
    EXPECT_EQ(trial8(0, 0), 'a');
    EXPECT_EQ(copyTrial8(0, 0), 0);


    R = 3;
    C = 3;
    Grid<string> trial9(R, C);
    Grid<string> copyTrial9;
    copyTrial9 = trial9;
    EXPECT_EQ(trial9.numrows(), R);
    EXPECT_EQ(copyTrial9.numrows(), R);
    EXPECT_EQ(trial9.numrows(), copyTrial9.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial9.numcols(i), C);
        EXPECT_EQ(copyTrial9.numcols(i), C);
        EXPECT_EQ(copyTrial9.numcols(i), trial9.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial9(i, j), copyTrial9(i, j));
        }
    }

    trial9(0,0) = "Yay";
    EXPECT_EQ(trial9(0, 0), "Yay");
    EXPECT_EQ(copyTrial9(0, 0), "");

    R = 6;
    C = 8;
    Grid<bool> trial10(R, C);
    Grid<bool> copyTrial10;
    copyTrial10 = trial10;
    EXPECT_EQ(trial10.numrows(), R);
    EXPECT_EQ(copyTrial10.numrows(), R);
    EXPECT_EQ(trial10.numrows(), copyTrial10.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial10.numcols(i), C);
        EXPECT_EQ(copyTrial10.numcols(i), C);
        EXPECT_EQ(copyTrial10.numcols(i), trial10.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial10(i, j), copyTrial10(i, j));
        }
    }

    trial10(0,0) = 1;
    EXPECT_EQ(trial10(0, 0), 1);
    EXPECT_EQ(copyTrial10(0, 0), 0);


    R = 10;
    C = 2;
    Grid<double> trial11(R, C);
    Grid<double> copyTrial11;
    copyTrial11 = trial11;
    EXPECT_EQ(trial11.numrows(), R);
    EXPECT_EQ(copyTrial11.numrows(), R);
    EXPECT_EQ(trial11.numrows(), copyTrial11.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial11.numcols(i), C);
        EXPECT_EQ(copyTrial11.numcols(i), C);
        EXPECT_EQ(copyTrial11.numcols(i), trial11.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial11(i, j), copyTrial11(i, j));
        }
    }

    trial11(0,0) = 1;
    EXPECT_EQ(trial11(0, 0), 1);
    EXPECT_EQ(copyTrial11(0, 0), 0);


    R = 2;
    C = 10;
    Grid<float> trial12(R, C);
    Grid<float> copyTrial12;
    copyTrial12 = trial12;
    EXPECT_EQ(trial12.numrows(), R);
    EXPECT_EQ(copyTrial12.numrows(), R);
    EXPECT_EQ(trial12.numrows(), copyTrial12.numrows());

    // checks each row
    for (int i = 0; i < R; i++) {
        EXPECT_EQ(trial12.numcols(i), C);
        EXPECT_EQ(copyTrial12.numcols(i), C);
        EXPECT_EQ(copyTrial12.numcols(i), trial12.numcols(i));
    }

    //checks each val if they are teh same
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            EXPECT_EQ(trial12(i, j), copyTrial12(i, j));
        }
    }

    trial12(0,0) = 1;
    EXPECT_EQ(trial12(0, 0), 1);
    EXPECT_EQ(copyTrial12(0, 0), 0);
}

TEST(grid, numRows) {
    for (int R = 1; R < 20; R++) {
        for (int C = 1; C < 20; C++) {
            Grid<int> trial7(R, C);
            EXPECT_EQ(trial7.numrows(), R);
            Grid<char> trial8(R, C);
            EXPECT_EQ(trial8.numrows(), R);
            Grid<string> trial9(R, C);
            EXPECT_EQ(trial9.numrows(), R);
            Grid<bool> trial10(R, C);
            EXPECT_EQ(trial10.numrows(), R);
            Grid<double> trial11(R, C);
            EXPECT_EQ(trial11.numrows(), R);
            Grid<float> trial12(R, C);
            EXPECT_EQ(trial12.numrows(), R);
        }
    }
}

TEST(grid, numCols) {

    for (int R = 0; R < 15; R++) {
        for (int C = 0; C < 15; C++) {
            Grid<int> trial7(R, C);
            for (int i = 0; i < R; i++) {
                EXPECT_EQ(trial7.numcols(i), C);
            }
            EXPECT_THROW(trial7.numcols(R), invalid_argument);
            Grid<char> trial8(R, C);
            for (int i = 0; i < R; i++) {
                EXPECT_EQ(trial8.numcols(i), C);
            }
            EXPECT_THROW(trial8.numcols(R), invalid_argument);
            Grid<string> trial9(R, C);
            for (int i = 0; i < R; i++) {
                EXPECT_EQ(trial9.numcols(i), C);
            }
            EXPECT_THROW(trial9.numcols(R), invalid_argument);
            Grid<bool> trial10(R, C);
            for (int i = 0; i < R; i++) {
                EXPECT_EQ(trial10.numcols(i), C);
            }
            EXPECT_THROW(trial10.numcols(R), invalid_argument);
            Grid<double> trial11(R, C);
            for (int i = 0; i < R; i++) {
                EXPECT_EQ(trial11.numcols(i), C);
            }
            EXPECT_THROW(trial11.numcols(R), invalid_argument);
            Grid<float> trial12(R, C);
            for (int i = 0; i < R; i++) {
                EXPECT_EQ(trial12.numcols(i), C);
            }
            EXPECT_THROW(trial12.numcols(R), invalid_argument);
        }
    }

}

TEST(grid, size) {
    for (int R = 1; R < 20; R++) {
        for (int C = 1; C < 20; C++) {
            Grid<int> trial7(R, C);
            EXPECT_EQ(trial7.size(), R * C);
            Grid<char> trial8(R, C);
            EXPECT_EQ(trial8.size(), R * C);
            Grid<string> trial9(R, C);
            EXPECT_EQ(trial9.size(), R * C);
            Grid<bool> trial10(R, C);
            EXPECT_EQ(trial10.size(), R * C);
            Grid<double> trial11(R, C);
            EXPECT_EQ(trial11.size(), R * C);
            Grid<float> trial12(R, C);
            EXPECT_EQ(trial12.size(), R * C);
        }
    }
}

TEST(grid, operatorParenthesis) {
    int counter = 0;
    for (int R = 1; R < 5; R++) {
        for (int C = 1; C < 5; C++) {
            Grid<int> trial7(R, C);
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    EXPECT_EQ(trial7(i, j), 0);
                    trial7(i, j) = counter;
                    EXPECT_EQ(trial7(i, j), counter);
                    counter++;
                }
            }
            EXPECT_THROW(trial7(R, C - 1), invalid_argument);
            EXPECT_THROW(trial7(R - 1, C), invalid_argument);
            EXPECT_THROW(trial7(R, C), invalid_argument);

            Grid<char> trial8(R, C);
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    EXPECT_EQ(trial8(i, j), 0);
                    trial8(i, j) = 'y';
                    EXPECT_EQ(trial8(i, j), 'y');
                    counter++;
                }
            }
            EXPECT_THROW(trial8(R, C - 1), invalid_argument);
            EXPECT_THROW(trial8(R - 1, C), invalid_argument);
            EXPECT_THROW(trial8(R, C), invalid_argument);

            Grid<string> trial9(R, C);
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    EXPECT_EQ(trial9(i, j), "");
                    trial9(i, j) = to_string(counter);
                    EXPECT_EQ(trial9(i, j), to_string(counter));
                    counter++;
                }
            }
            EXPECT_THROW(trial9(R, C - 1), invalid_argument);
            EXPECT_THROW(trial9(R - 1, C), invalid_argument);
            EXPECT_THROW(trial9(R, C), invalid_argument);

            Grid<bool> trial10(R, C);
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    EXPECT_EQ(trial10(i, j), 0);
                    trial10(i, j) = 1;
                    EXPECT_EQ(trial10(i, j), 1);
                    counter++;
                }
            }
            EXPECT_THROW(trial10(R, C - 1), invalid_argument);
            EXPECT_THROW(trial10(R - 1, C), invalid_argument);
            EXPECT_THROW(trial10(R, C), invalid_argument);

            Grid<double> trial11(R, C);
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    EXPECT_EQ(trial11(i, j), 0);
                    trial11(i, j) = counter;
                    EXPECT_EQ(trial11(i, j), counter);
                    counter++;
                }
            }
            EXPECT_THROW(trial11(R, C - 1), invalid_argument);
            EXPECT_THROW(trial11(R - 1, C), invalid_argument);
            EXPECT_THROW(trial11(R, C), invalid_argument);

            Grid<float> trial12(R, C);
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    EXPECT_EQ(trial12(i, j), 0);
                    trial12(i, j) = counter;
                    EXPECT_EQ(trial12(i, j), counter);
                    counter++;
                }
            }
            EXPECT_THROW(trial12(R, C - 1), invalid_argument);
            EXPECT_THROW(trial12(R - 1, C), invalid_argument);
            EXPECT_THROW(trial12(R, C), invalid_argument);
        }
    }
}



//// Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);

    MazeCell* start = m.getStart(2, 2);

    /* These paths are the ones in the handout. They all work. */
    EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
    EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
    EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

    /* These paths don't work, since they don't pick up all items. */
    EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

    /* These paths don't work, since they aren't legal paths. */
    EXPECT_FALSE(isPathToFreedom(start, "WW"));
    EXPECT_FALSE(isPathToFreedom(start, "NN"));
    EXPECT_FALSE(isPathToFreedom(start, "EE"));
    EXPECT_FALSE(isPathToFreedom(start, "SS"));
}

TEST(maze, basic1) {
    vector<string> textMaze;

    textMaze.push_back("* *-P-*");
    textMaze.push_back("| | | |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("*-*-*-W");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-* * S");

    Maze m(textMaze);

    MazeCell* start = m.getStart(0, 1);

    EXPECT_TRUE(isPathToFreedom(start, "EESSS"));

    EXPECT_FALSE(isPathToFreedom(start, "WWW"));
    EXPECT_FALSE(isPathToFreedom(start, "SWSS"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

    EXPECT_FALSE(isPathToFreedom(start, "WWW"));
    EXPECT_FALSE(isPathToFreedom(start, "NNN"));
    EXPECT_FALSE(isPathToFreedom(start, "EEN"));
    EXPECT_FALSE(isPathToFreedom(start, "SSW"));
}

TEST(maze, basic2) {
    vector<string> textMaze;

    textMaze.push_back("*-*-P *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("W-*-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-*-S");

    Maze m(textMaze);

    MazeCell* start = m.getStart(0, 0);

    EXPECT_TRUE(isPathToFreedom(start, "EEWWSESWSEEE"));

    EXPECT_FALSE(isPathToFreedom(start, "WWW"));
    EXPECT_FALSE(isPathToFreedom(start, "SWSS"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

    EXPECT_FALSE(isPathToFreedom(start, "W"));
    EXPECT_FALSE(isPathToFreedom(start, "N"));
    EXPECT_FALSE(isPathToFreedom(start, "EEN"));
    EXPECT_FALSE(isPathToFreedom(start, "SSW"));

    vector<string> textMaze1;

    textMaze.push_back("P-*-* *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("W-*-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-*-S");

    Maze m1(textMaze1);

    MazeCell* start1 = m.getStart(0, 0);

    EXPECT_TRUE(isPathToFreedom(start, "EEWWSESWSEEE"));
}
//
//// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
    vector<string> textMaze;

    textMaze.push_back("* S *");
    textMaze.push_back("     ");
    textMaze.push_back("W * P");
    textMaze.push_back( "     ");
    textMaze.push_back( "* * *");

    Maze m(textMaze);

    MazeCell* start = m.getStart(1, 1);

    EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
    EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
    EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
    EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}
//
//// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
    vector<string> textMaze;

    textMaze.push_back("P-S-W");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    EXPECT_TRUE(isPathToFreedom(start, "EE"));
    start = m.getStart(0, 1);
    EXPECT_TRUE(isPathToFreedom(start, "WEE"));
    start = m.getStart(0, 2);
    EXPECT_TRUE(isPathToFreedom(start, "WW"));

}
//
//// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    /* These paths contain characters that aren't even close to permissible. */
    EXPECT_FALSE(isPathToFreedom(start, "Q"));
    EXPECT_FALSE(isPathToFreedom(start, "X"));
    EXPECT_FALSE(isPathToFreedom(start, "!"));
    EXPECT_FALSE(isPathToFreedom(start, "?"));

    EXPECT_FALSE(isPathToFreedom(start, "n"));
    EXPECT_FALSE(isPathToFreedom(start, "s"));
    EXPECT_FALSE(isPathToFreedom(start, "e"));
    EXPECT_FALSE(isPathToFreedom(start, "w"));

    ///* These are tricky - they're legal paths that happen to have an unexpected
    // * character at the end.
    start = m.getStart(2, 2);
    EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

}
//
//// Provided Test: This tests your personalized regular maze to see if you were
//// able to escape.
TEST(maze, escapeRegularMaze) {
    Maze m(4, 4);
    MazeCell* start = m.mazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}
//
//// Provided Test: This tests your personalized twisty maze to see if you were
//// able to escape.
TEST(maze, escapeTwistyMaze) {
    Maze m(4, 4);
    MazeCell* start = m.twistyMazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}

