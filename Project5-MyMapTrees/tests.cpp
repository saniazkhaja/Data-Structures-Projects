#include <gtest/gtest.h>
#include "mymap.h"

TEST(mymap, defaultConstructor) {
    mymap<int, int> mapIntInt;
    EXPECT_EQ(mapIntInt.Size(), 0);
    mymap<int, double> mapIntDouble;
    EXPECT_EQ(mapIntDouble.Size(), 0);
    mymap<int, string> mapIntString;
    EXPECT_EQ(mapIntString.Size(), 0);
    mymap<int, char> mapIntChar;
    EXPECT_EQ(mapIntChar.Size(), 0);

    mymap<double, double> mapDoubleDouble;
    EXPECT_EQ(mapDoubleDouble.Size(), 0);
    mymap<double, int> mapDoubleInt;
    EXPECT_EQ(mapDoubleInt.Size(), 0);
    mymap<double, string> mapDoubleString;
    EXPECT_EQ(mapDoubleString.Size(), 0);
    mymap<double, char> mapDoubleChar;
    EXPECT_EQ(mapDoubleChar.Size(), 0);

    mymap<string, string> mapStringString;
    EXPECT_EQ(mapStringString.Size(), 0);
    mymap<string, double> mapStringDouble;
    EXPECT_EQ(mapStringDouble.Size(), 0);
    mymap<string, int> mapStringInt;
    EXPECT_EQ(mapStringInt.Size(), 0);
    mymap<string, char> mapStringChar;
    EXPECT_EQ(mapStringChar.Size(), 0);


    mymap<char, char> mapCharChar;
    EXPECT_EQ(mapCharChar.Size(), 0);
    mymap<char, int> mapCharInt;
    EXPECT_EQ(mapCharInt.Size(), 0);
    mymap<char, double> mapCharDouble;
    EXPECT_EQ(mapCharDouble.Size(), 0);
    mymap<char, string> mapCharString;
    EXPECT_EQ(mapCharString.Size(), 0);
}

TEST(mymap, put) {
    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    EXPECT_EQ(mapIntIntBig.Size(), 10);

    mymap<int, int> mapIntInt;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapIntInt.put(arr[i], arr[i]);
    }
    EXPECT_EQ(mapIntInt.Size(), 3);

    mymap<int, int> mapIntIntKeyRepeat;
    int arrIntRepeat[] = {2, 1, 3, 3, 2, 1};
    for (int i = 0; i < 6; i++) {
        mapIntIntKeyRepeat.put(arrIntRepeat[i], arrIntRepeat[i]);
    }
    EXPECT_EQ(mapIntIntKeyRepeat.Size(), 3);

    mymap<int, int> mapIntIntValRepeat;
    for (int i = 0; i < 6; i++) {
        mapIntIntValRepeat.put(i, arrIntRepeat[i]);
    }
    EXPECT_EQ(mapIntIntValRepeat.Size(), 6);

    for (int j = 0; j < 100; j++) {
        mymap<int, int> mapIntIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntIntRandom.put(i, arrRandom[i]);
        }
        EXPECT_EQ(mapIntIntRandom.Size(), randomSize);
    }

    mymap<int, double> mapIntDouble;
    double arrDouble[] = {2.2, 1.1, 3.4};
    for (int i = 0; i < 3; i++) {
        mapIntDouble.put(i, arrDouble[i]);
    }
    EXPECT_EQ(mapIntDouble.Size(), 3);


    mymap<double, double> mapDoubleDouble;
    for (int i = 0; i < 3; i++) {
        mapDoubleDouble.put(arrDouble[i], arrDouble[i]);
    }
    EXPECT_EQ(mapDoubleDouble.Size(), 3);

    mymap<char, char> mapCharChar;
    char arrChar[] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++) {
        mapCharChar.put(i, arrChar[i]);
    }
    EXPECT_EQ(mapCharChar.Size(), 3);

    mymap<string, string> mapStringString;
    string arrString[] = {"a", "b", "cab", "food", "hope"};
    for (int i = 0; i < 5; i++) {
        mapStringString.put(to_string(i), arrString[i]);
    }
    EXPECT_EQ(mapStringString.Size(), 5);

    mymap<string, char> mapStringChar;
    for (int i = 0; i < 3; i++) {
        mapStringChar.put(to_string(i), arrChar[i]);
    }
    EXPECT_EQ(mapStringChar.Size(), 3);

    for (int j = 0; j < 100; j++) {
        mymap<int, char> mapIntCharRandom;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntCharRandom.put(i, arrRandom[i]);
        }
        EXPECT_EQ(mapIntCharRandom.Size(), randomSize);
    }
}

TEST(mymap, size) {
    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    EXPECT_EQ(mapIntIntBig.Size(), 10);

    for (int j = 0; j < 100; j++) {
        mymap<int, int> mapIntIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntIntRandom.put(i, arrRandom[i]);
        }
        EXPECT_EQ(mapIntIntRandom.Size(), randomSize);
    }

    for (int j = 0; j < 100; j++) {
        mymap<int, double> mapIntDoubleRandom;
        int randomSize = rand() % 100;
        double arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntDoubleRandom.put(i, arrRandom[i]);
        }
        EXPECT_EQ(mapIntDoubleRandom.Size(), randomSize);
    }

    for (int j = 0; j < 100; j++) {
        mymap<int, char> mapIntCharRandom;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntCharRandom.put(i, arrRandom[i]);
        }
        EXPECT_EQ(mapIntCharRandom.Size(), randomSize);
    }

    for (int j = 0; j < 100; j++) {
        mymap<int, string> mapIntStringRandom;
        int randomSize = rand() % 100;
        string arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntStringRandom.put(i, arrRandom[i]);
        }
        EXPECT_EQ(mapIntStringRandom.Size(), randomSize);
    }

    for (int j = 0; j < 100; j++) {
        mymap<string, string> mapStringStringRandom;
        int randomSize = rand() % 100;
        string arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapStringStringRandom.put(to_string(i), arrRandom[i]);
        }
        EXPECT_EQ(mapStringStringRandom.Size(), randomSize);
    }

    for (int j = 0; j < 100; j++) {
        mymap<char, char> mapCharCharRandom;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapCharCharRandom.put(i, arrRandom[i]);
        }
        EXPECT_EQ(mapCharCharRandom.Size(), randomSize);
    }

    for (int j = 0; j < 100; j++) {
        mymap<string, char> mapStringCharRandom;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapStringCharRandom.put(to_string(i), arrRandom[i]);
        }
        EXPECT_EQ(mapStringCharRandom.Size(), randomSize);
    }
}

TEST(mymap, contains) {
    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_TRUE(mapIntIntBig.contains(arrBig[i]));
    }
    EXPECT_FALSE(mapIntIntBig.contains(4));
    EXPECT_FALSE(mapIntIntBig.contains('5'));
    EXPECT_FALSE(mapIntIntBig.contains(10));

    mymap<int, int> mapIntInt;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapIntInt.put(arr[i], arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_TRUE(mapIntInt.contains(arr[i]));
    }
    EXPECT_FALSE(mapIntInt.contains(4));
    EXPECT_FALSE(mapIntInt.contains('5'));
    EXPECT_FALSE(mapIntInt.contains(10));

    for (int j = 0; j < 100; j++) {
        mymap<int, int> mapIntIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntIntRandom.put(arrRandom[i], arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_TRUE(mapIntIntRandom.contains(arrRandom[i]));
        }
        EXPECT_FALSE(mapIntIntRandom.contains(1000));
    }

    for (int j = 0; j < 100; j++) {
        mymap<char, char> mapCharCharRandom;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapCharCharRandom.put(arrRandom[i], arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_TRUE(mapCharCharRandom.contains(arrRandom[i]));
        }
        EXPECT_FALSE(mapCharCharRandom.contains('}'));
    }

    for (int j = 0; j < 100; j++) {
        mymap<string, string> mapStringStringRandom;
        int randomSize = rand() % 100;
        string arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapStringStringRandom.put(arrRandom[i], arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_TRUE(mapStringStringRandom.contains(arrRandom[i]));
        }
        EXPECT_FALSE(mapStringStringRandom.contains("yay"));
        EXPECT_FALSE(mapStringStringRandom.contains("1000"));
    }

    for (int j = 0; j < 100; j++) {
        mymap<double, double> mapDoubleDoubleRandom;
        int randomSize = rand() % 100;
        double arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapDoubleDoubleRandom.put(arrRandom[i], arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_TRUE(mapDoubleDoubleRandom.contains(arrRandom[i]));
        }
        EXPECT_FALSE(mapDoubleDoubleRandom.contains(1000.0));
    }

    for (int j = 0; j < 100; j++) {
        mymap<int, char> mapIntCharRandom;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntCharRandom.put(arrRandom[i], arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_TRUE(mapIntCharRandom.contains(arrRandom[i]));
        }
        EXPECT_FALSE(mapIntCharRandom.contains(1000.0));
    }

    for (int j = 0; j < 100; j++) {
        mymap<string, int> mapStringIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapStringIntRandom.put(to_string(arrRandom[i]), arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_TRUE(mapStringIntRandom.contains(to_string(arrRandom[i])));
        }
        EXPECT_FALSE(mapStringIntRandom.contains("1000.0"));
    }
}

TEST(mymap, get) {
    mymap<int,int> mapBlank;
    int arrBlank[] = {};
    EXPECT_EQ(mapBlank.get(0), NULL);

    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(mapIntIntBig.get(arrBig[i]), arrBig[i]);
        EXPECT_EQ(mapIntIntBig.get(4), 0);
        EXPECT_EQ(mapIntIntBig.Size(), 10);
    }

    mymap<int, int> mapIntInt;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapIntInt.put(arr[i], arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapIntInt.get(arr[i]), arr[i]);
        EXPECT_EQ(mapIntInt.get(4), 0);
        EXPECT_EQ(mapIntInt.Size(), 3);
    }

    mymap<string, string> mapStringString;
    string arrString[] = {"yay", "boo", "fun"};
    for (int i = 0; i < 3; i++) {
        mapStringString.put(arrString[i], arrString[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapStringString.get(arrString[i]), arrString[i]);
        EXPECT_EQ(mapStringString.get("foo"), "");
        EXPECT_EQ(mapStringString.Size(), 3);
    }

    mymap<char, char> mapCharChar;
    char arrChar[] = {'y', 'a', 'p'};
    for (int i = 0; i < 3; i++) {
        mapCharChar.put(arrChar[i], arrChar[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapCharChar.get(arrChar[i]), arrChar[i]);
        EXPECT_EQ(mapCharChar.get('f'), '\0');
        EXPECT_EQ(mapCharChar.Size(), 3);
    }

    mymap<double, double> mapDoubleDouble;
    double arrDouble[] = {2.2, 1.1, 3.3};
    for (int i = 0; i < 3; i++) {
        mapDoubleDouble.put(arrDouble[i], arrDouble[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapDoubleDouble.get(arrDouble[i]), arrDouble[i]);
        EXPECT_EQ(mapDoubleDouble.get(4), 0.0);
        EXPECT_EQ(mapDoubleDouble.Size(), 3);
    }

    for (int j = 0; j < 50; j++) {
        mymap<string, int> mapStringIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapStringIntRandom.put(to_string(arrRandom[i]), arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_EQ(mapStringIntRandom.get(to_string(arrRandom[i])), arrRandom[i]);

        }
        EXPECT_EQ(mapStringIntRandom.get("1000"), 0);
    }

    for (int j = 0; j < 50; j++) {
        mymap<double, int> mapDoubleIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapDoubleIntRandom.put(arrRandom[i], arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_EQ(mapDoubleIntRandom.get(arrRandom[i]), arrRandom[i]);

        }
        EXPECT_EQ(mapDoubleIntRandom.get(1000.0), 0);
    }
}

TEST(mymap, toString) {
    mymap<int,int> mapBlank;
    int arrBlank[] = {};
    EXPECT_EQ(mapBlank.toString(), "");

    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    string sol1 = "key: 8 value: 8\nkey: 15 value: 15\nkey: 20 value: 20\n"
                  "key: 25 value: 25\nkey: 28 value: 28\nkey: 30 value: 30\n"
                  "key: 40 value: 40\nkey: 50 value: 50\nkey: 60 value: 60\n"
                  "key: 70 value: 70\n";

    EXPECT_EQ(sol1, mapIntIntBig.toString());

    mymap<int, int> mapIntInt;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapIntInt.put(arr[i], arr[i]);
    }
    string sol = "key: 1 value: 1\nkey: 2 value: 2\nkey: 3 value: 3\n";

    EXPECT_EQ(sol, mapIntInt.toString());

    mymap<string, string> mapStringString;
    string arrString[] = {"2", "1", "3"};
    for (int i = 0; i < 3; i++) {
        mapStringString.put(arrString[i], arrString[i]);
    }
    EXPECT_EQ(sol, mapStringString.toString());

    mymap<char, char> mapCharChar;
    char arrChar[] = {'2', '1', '3'};
    for (int i = 0; i < 3; i++) {
        mapCharChar.put(arrChar[i], arrChar[i]);
    }
    EXPECT_EQ(sol, mapCharChar.toString());

    mymap<double, double> mapDoubleDouble;
    double arrDouble[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapDoubleDouble.put(arrDouble[i], arrDouble[i]);
    }
    EXPECT_EQ(sol, mapDoubleDouble.toString());

    mymap<int, double> mapIntDouble;
    for (int i = 0; i < 3; i++) {
        mapIntDouble.put(arr[i], arrDouble[i]);
    }
    EXPECT_EQ(sol, mapIntDouble.toString());

    mymap<string, char> mapStringInt;
    for (int i = 0; i < 3; i++) {
        mapStringInt.put(arrString[i], arrChar[i]);
    }
    EXPECT_EQ(sol, mapStringInt.toString());
}

TEST(mymap, operatorBracket) {
    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(mapIntIntBig[arrBig[i]], arrBig[i]);
        EXPECT_EQ(mapIntIntBig.Size(), 10);
    }
    EXPECT_EQ(mapIntIntBig[4], 0);
    EXPECT_EQ(mapIntIntBig.Size(), 11);

    mymap<int, int> mapIntInt;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapIntInt.put(arr[i], arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapIntInt[arr[i]], arr[i]);
        EXPECT_EQ(mapIntInt.Size(), 3);
    }
    EXPECT_EQ(mapIntInt[4], 0);
    EXPECT_EQ(mapIntInt.Size(), 4);

    mymap<string, string> mapStringString;
    string arrString[] = {"2", "1", "3"};
    for (int i = 0; i < 3; i++) {
        mapStringString.put(arrString[i], arrString[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapStringString[arrString[i]], arrString[i]);
        EXPECT_EQ(mapStringString.Size(), 3);
    }
    EXPECT_EQ(mapStringString["4"], "");
    EXPECT_EQ(mapStringString.Size(), 4);

    mymap<char, char> mapCharChar;
    char arrChar[] = {'2', '1', '3'};
    for (int i = 0; i < 3; i++) {
        mapCharChar.put(arrChar[i], arrChar[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapCharChar[arrChar[i]], arrChar[i]);
        EXPECT_EQ(mapCharChar.Size(), 3);
    }
    EXPECT_EQ(mapCharChar['4'], '\0');
    EXPECT_EQ(mapCharChar.Size(), 4);

    mymap<double, double> mapDoubleDouble;
    double arrDouble[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapDoubleDouble.put(arrDouble[i], arrDouble[i]);
    }
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(mapDoubleDouble[arrDouble[i]], arrDouble[i]);
        EXPECT_EQ(mapDoubleDouble.Size(), 3);
    }
    EXPECT_EQ(mapDoubleDouble[4.0], 0);
    EXPECT_EQ(mapDoubleDouble.Size(), 4);

    for (int j = 0; j < 50; j++) {
        mymap<string, int> mapStringIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapStringIntRandom.put(to_string(arrRandom[i]), arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_EQ(mapStringIntRandom[to_string(arrRandom[i])], arrRandom[i]);
        }
    }

    for (int j = 0; j < 50; j++) {
        mymap<int, char> mapIntCharRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntCharRandom.put(arrRandom[i], arrRandom[i]);
        }
        for (int i = 0; i < randomSize; i++) {
            EXPECT_EQ(mapIntCharRandom[arrRandom[i]], arrRandom[i]);
        }
    }
}

TEST(myMap, operatorplusplusAndBegin) {
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    int order[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }
    int i = 0;
    for (auto key : map) {
        EXPECT_EQ(order[i++], key);
    }

    mymap<int, int> map1;
    int arr1[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    int order1[] = {8, 15, 20, 25, 28, 30, 40, 50, 60, 70};
    for (int i = 0; i < 10; i++) {
        map1.put(arr1[i], arr1[i]);
    }
    int i1 = 0;
    for (auto key : map1) {
        EXPECT_EQ(order1[i1++], key);
    }

    mymap<char, char> mapCharChar;
    char arrCharChar[] = {'b', 'c', 'a', 'n'};
    char orderCharChar[] = {'a', 'b', 'c', 'n'};
    for (int i = 0; i < 4; i++) {
        mapCharChar.put(arrCharChar[i], arrCharChar[i]);
    }
    int iCharChar = 0;
    for (auto key : mapCharChar) {
        EXPECT_EQ(orderCharChar[iCharChar++], key);
    }

    mymap<string, string> mapStringString;
    string arrStringString[] = {"b", "c", "a", "n"};
    string orderStringString[] = {"a", "b", "c", "n"};
    for (int i = 0; i < 4; i++) {
        mapStringString.put(arrStringString[i], arrStringString[i]);
    }
    int iStringString = 0;
    for (auto key : mapStringString) {
        EXPECT_EQ(orderStringString[iStringString++], key);
    }

    mymap<double, double> mapDoubleDouble;
    double arrDoubleDouble[] = {30.0, 15.5, 50.0, 8.8, 25.5, 40.0, 70.0, 20.0, 28.8, 60.0};
    double orderDoubleDouble[] = {8.8, 15.5, 20.0, 25.5, 28.8, 30.0, 40.0, 50.0, 60.0, 70.0};
    for (int i = 0; i < 10; i++) {
        mapDoubleDouble.put(arrDoubleDouble[i], arrDoubleDouble[i]);
    }
    int iDoubleDouble = 0;
    for (auto key : mapDoubleDouble) {
        EXPECT_EQ(orderDoubleDouble[iDoubleDouble++], key);
    }

    mymap<int, string> mapIntString;
    int arrIntString[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    int orderIntString[] = {8, 15, 20, 25, 28, 30, 40, 50, 60, 70};
    for (int i = 0; i < 10; i++) {
        mapIntString.put(arrIntString[i], to_string(arrIntString[i]));
    }
    int iIntString = 0;
    for (auto key : mapIntString) {
        EXPECT_EQ(orderIntString[iIntString++], key);
    }

    mymap<string, int> mapStringInt;
    int arrStringInt[] = {50, 33, 89, 41, 66, 91};
    string arrString[] = {"50", "33", "89", "41", "66", "91"};
    string orderStringInt[] = {"33", "41", "50", "66", "89", "91"};
    for (int i = 0; i < 6; i++) {
        mapStringInt.put(arrString[i], arrStringInt[i]);
    }
    int iStringInt = 0;
    for (auto key : mapStringInt) {
        EXPECT_EQ(orderStringInt[iStringInt++], key);
    }
}

TEST(myMap, clear) {
    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    mapIntIntBig.clear();
    EXPECT_EQ(mapIntIntBig.Size(), 0);

    mymap<int, int> mapIntInt;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        mapIntInt.put(arr[i], arr[i]);
    }
    mapIntInt.clear();
    EXPECT_EQ(mapIntInt.Size(), 0);

    mymap<int, int> mapIntIntKeyRepeat;
    int arrIntRepeat[] = {2, 1, 3, 3, 2, 1};
    for (int i = 0; i < 6; i++) {
        mapIntIntKeyRepeat.put(arrIntRepeat[i], arrIntRepeat[i]);
    }
    mapIntIntKeyRepeat.clear();
    EXPECT_EQ(mapIntIntKeyRepeat.Size(), 0);

    mymap<int, int> mapIntIntValRepeat;
    for (int i = 0; i < 6; i++) {
        mapIntIntValRepeat.put(i, arrIntRepeat[i]);
    }
    mapIntIntValRepeat.clear();
    EXPECT_EQ(mapIntIntValRepeat.Size(), 0);

    for (int j = 0; j < 100; j++) {
        mymap<int, int> mapIntIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntIntRandom.put(i, arrRandom[i]);
        }
        mapIntIntRandom.clear();
        EXPECT_EQ(mapIntIntRandom.Size(), 0);
    }

    mymap<int, double> mapIntDouble;
    double arrDouble[] = {2.2, 1.1, 3.4};
    for (int i = 0; i < 3; i++) {
        mapIntDouble.put(i, arrDouble[i]);
    }
    mapIntDouble.clear();
    EXPECT_EQ(mapIntDouble.Size(), 0);


    mymap<double, double> mapDoubleDouble;
    for (int i = 0; i < 3; i++) {
        mapDoubleDouble.put(arrDouble[i], arrDouble[i]);
    }
    mapDoubleDouble.clear();
    EXPECT_EQ(mapDoubleDouble.Size(), 0);

    mymap<char, char> mapCharChar;
    char arrChar[] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++) {
        mapCharChar.put(i, arrChar[i]);
    }
    mapCharChar.clear();
    EXPECT_EQ(mapCharChar.Size(), 0);

    mymap<string, string> mapStringString;
    string arrString[] = {"a", "b", "cab", "food", "hope"};
    for (int i = 0; i < 5; i++) {
        mapStringString.put(to_string(i), arrString[i]);
    }
    mapStringString.clear();
    EXPECT_EQ(mapStringString.Size(), 0);

    mymap<string, char> mapStringChar;
    for (int i = 0; i < 3; i++) {
        mapStringChar.put(to_string(i), arrChar[i]);
    }
    mapStringChar.clear();
    EXPECT_EQ(mapStringChar.Size(), 0);

    for (int j = 0; j < 100; j++) {
        mymap<int, char> mapIntCharRandom;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntCharRandom.put(i, arrRandom[i]);
        }
        mapIntCharRandom.clear();
        EXPECT_EQ(mapIntCharRandom.Size(), 0);
    }
}

TEST(myMap, operatorEqual) {
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    int order[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }
    mymap<int, int> mapCopy;
    mapCopy = map;
    EXPECT_EQ(map.Size(), mapCopy.Size());
    EXPECT_EQ(map.toString(), mapCopy.toString());

    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    mymap<int, int> mapIntIntBigCopy;
    mapIntIntBigCopy = mapIntIntBig;
    EXPECT_EQ(mapIntIntBig.Size(), mapIntIntBigCopy.Size());
    EXPECT_EQ(mapIntIntBig.toString(), mapIntIntBigCopy.toString());

    for (int j = 0; j < 100; j++) {
        mymap<int, int> mapIntIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntIntRandom.put(i, arrRandom[i]);
        }
        mymap<int, int> mapIntIntRandomCopy;
        mapIntIntRandomCopy = mapIntIntRandom;
        EXPECT_EQ(mapIntIntRandom.Size(), mapIntIntRandomCopy.Size());
        EXPECT_EQ(mapIntIntRandom.toString(), mapIntIntRandomCopy.toString());
    }

    mymap<int, double> mapIntDouble;
    double arrDouble[] = {2.2, 1.1, 3.4};
    for (int i = 0; i < 3; i++) {
        mapIntDouble.put(i, arrDouble[i]);
    }
    mymap<int, double> mapIntDoubleRandomCopy;
    mapIntDoubleRandomCopy = mapIntDouble;
    EXPECT_EQ(mapIntDouble.Size(), mapIntDoubleRandomCopy.Size());
    EXPECT_EQ(mapIntDouble.toString(), mapIntDoubleRandomCopy.toString());


    mymap<double, double> mapDoubleDouble;
    for (int i = 0; i < 3; i++) {
        mapDoubleDouble.put(arrDouble[i], arrDouble[i]);
    }
    mymap<double, double> mapDoubleDoubleRandomCopy;
    mapDoubleDoubleRandomCopy = mapDoubleDouble;
    EXPECT_EQ(mapDoubleDouble.Size(), mapDoubleDoubleRandomCopy.Size());
    EXPECT_EQ(mapDoubleDouble.toString(), mapDoubleDoubleRandomCopy.toString());

    mymap<char, char> mapCharChar;
    char arrChar[] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++) {
        mapCharChar.put(i, arrChar[i]);
    }
    mymap<char, char> mapCharCharRandomCopy;
    mapCharCharRandomCopy = mapCharChar;
    EXPECT_EQ(mapCharChar.Size(), mapCharCharRandomCopy.Size());
    EXPECT_EQ(mapCharChar.toString(), mapCharCharRandomCopy.toString());

    mymap<string, string> mapStringString;
    string arrString[] = {"a", "b", "cab", "food", "hope"};
    for (int i = 0; i < 5; i++) {
        mapStringString.put(to_string(i), arrString[i]);
    }
    mymap<string, string> mapStringStringCopy;
    mapStringStringCopy = mapStringString;
    EXPECT_EQ(mapStringString.Size(), mapStringStringCopy.Size());
    EXPECT_EQ(mapStringString.toString(), mapStringStringCopy.toString());

    mymap<string, char> mapStringChar;
    for (int i = 0; i < 3; i++) {
        mapStringChar.put(to_string(i), arrChar[i]);
    }
    mymap<string, char> mapStringCharCopy;
    mapStringCharCopy = mapStringChar;
    EXPECT_EQ(mapStringChar.Size(), mapStringCharCopy.Size());
    EXPECT_EQ(mapStringChar.toString(), mapStringCharCopy.toString());
}

TEST(myMap, copyConstructor) {
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    int order[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }
    mymap<int, int> mapCopy = map;
    EXPECT_EQ(map.Size(), mapCopy.Size());
    EXPECT_EQ(map.toString(), mapCopy.toString());

    mymap<int, int> mapIntIntBig;
    int arrBig[] = {30, 15, 50, 8, 25, 40, 70, 20, 28, 60};
    for (int i = 0; i < 10; i++) {
        mapIntIntBig.put(arrBig[i], arrBig[i]);
    }
    mymap<int, int> mapIntIntBigCopy = mapIntIntBig;
    EXPECT_EQ(mapIntIntBig.Size(), mapIntIntBigCopy.Size());
    EXPECT_EQ(mapIntIntBig.toString(), mapIntIntBigCopy.toString());

    for (int j = 0; j < 100; j++) {
        mymap<int, int> mapIntIntRandom;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntIntRandom.put(i, arrRandom[i]);
        }
        mymap<int, int> mapIntIntRandomCopy = mapIntIntRandom;
        EXPECT_EQ(mapIntIntRandom.Size(), mapIntIntRandomCopy.Size());
        EXPECT_EQ(mapIntIntRandom.toString(), mapIntIntRandomCopy.toString());
    }

    mymap<int, double> mapIntDouble;
    double arrDouble[] = {2.2, 1.1, 3.4};
    for (int i = 0; i < 3; i++) {
        mapIntDouble.put(i, arrDouble[i]);
    }
    mymap<int, double> mapIntDoubleRandomCopy = mapIntDouble;
    EXPECT_EQ(mapIntDouble.Size(), mapIntDoubleRandomCopy.Size());
    EXPECT_EQ(mapIntDouble.toString(), mapIntDoubleRandomCopy.toString());


    mymap<double, double> mapDoubleDouble;
    for (int i = 0; i < 3; i++) {
        mapDoubleDouble.put(arrDouble[i], arrDouble[i]);
    }
    mymap<double, double> mapDoubleDoubleRandomCopy = mapDoubleDouble;
    EXPECT_EQ(mapDoubleDouble.Size(), mapDoubleDoubleRandomCopy.Size());
    EXPECT_EQ(mapDoubleDouble.toString(), mapDoubleDoubleRandomCopy.toString());

    mymap<char, char> mapCharChar;
    char arrChar[] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++) {
        mapCharChar.put(i, arrChar[i]);
    }
    mymap<char, char> mapCharCharRandomCopy = mapCharChar;
    EXPECT_EQ(mapCharChar.Size(), mapCharCharRandomCopy.Size());
    EXPECT_EQ(mapCharChar.toString(), mapCharCharRandomCopy.toString());

    mymap<string, string> mapStringString;
    string arrString[] = {"a", "b", "cab", "food", "hope"};
    for (int i = 0; i < 5; i++) {
        mapStringString.put(to_string(i), arrString[i]);
    }
    mymap<string, string> mapStringStringCopy = mapStringString;
    EXPECT_EQ(mapStringString.Size(), mapStringStringCopy.Size());
    EXPECT_EQ(mapStringString.toString(), mapStringStringCopy.toString());

    mymap<string, char> mapStringChar;
    for (int i = 0; i < 3; i++) {
        mapStringChar.put(to_string(i), arrChar[i]);
    }
    mymap<string, char> mapStringCharCopy = mapStringChar;
    EXPECT_EQ(mapStringChar.Size(), mapStringCharCopy.Size());
    EXPECT_EQ(mapStringChar.toString(), mapStringCharCopy.toString());
}

TEST(myMap, mixOfTests) {
    mymap<string, double> mapStringDouble;
    string arrString[] = {"50", "33", "89", "41", "66", "91", "92", "974"};
    double arrStringDouble[] = {50, 33, 89, 41, 66, 91, 92, 974};
    string orderStringDouble[] = {"33", "41", "50", "66", "89", "91", "92", "974"};
    for (int i = 0; i < 8; i++) {
        mapStringDouble.put(arrString[i], arrStringDouble[i]);
    }
    EXPECT_EQ(mapStringDouble.Size(), 8);
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(mapStringDouble.get(arrString[i]), arrStringDouble[i]);
    }
    string sol1 = "key: 33 value: 33\nkey: 41 value: 41\nkey: 50 value: 50\n"
                  "key: 66 value: 66\nkey: 89 value: 89\nkey: 91 value: 91\n"
                  "key: 92 value: 92\nkey: 974 value: 974\n";

    EXPECT_EQ(sol1, mapStringDouble.toString());

    int iStringDouble = 0;
    for (auto key : mapStringDouble) {
        EXPECT_EQ(orderStringDouble[iStringDouble++], key);
    }
}

TEST(myMap, toVector) {
    vector<pair<int, int> > solution;
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
        solution.push_back(make_pair(i + 1, i + 1));
    }
    EXPECT_EQ(map.toVector(), solution);

    for (int j = 0; j < 100; j++) {
        mymap<int, int> mapIntIntRandom;
        vector<pair<int, int> > solution;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntIntRandom.put(i, arrRandom[i]);
            solution.push_back(make_pair(i, arrRandom[i]));
        }
        EXPECT_EQ(mapIntIntRandom.toVector(), solution);
    }

    for (int j = 0; j < 100; j++) {
        mymap<double, double> mapRandom;
        vector<pair<double, double> > solution;
        int randomSize = rand() % 100;
        double arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapRandom.put(i, arrRandom[i]);
            solution.push_back(make_pair(i, arrRandom[i]));
        }
        EXPECT_EQ(mapRandom.toVector(), solution);
    }

    for (int j = 0; j < 100; j++) {
        mymap<char, char> mapRandom;
        vector<pair<char, char> > solution;
        int randomSize = rand() % 100;
        char arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapRandom.put(i, arrRandom[i]);
            solution.push_back(make_pair(i, arrRandom[i]));
        }
        EXPECT_EQ(mapRandom.toVector(), solution);
    }

    for (int j = 0; j < 100; j++) {
        mymap<string, string> mapRandom;
        vector<pair<string, string> > solution;
        int randomSize = rand() % 100;
        string arrRandom[10];
        for (int i = 0; i < 10; i++) {
            arrRandom[i] = rand() % 10;
            mapRandom.put(to_string(i), arrRandom[i]);
            solution.push_back(make_pair(to_string(i), arrRandom[i]));
        }
        EXPECT_EQ(mapRandom.toVector(), solution);
    }

    for (int j = 0; j < 100; j++) {
        mymap<int, string> mapIntStringRandom;
        vector<pair<int, string> > solution;
        int randomSize = rand() % 100;
        string arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapIntStringRandom.put(i, arrRandom[i]);
            solution.push_back(make_pair(i, arrRandom[i]));
        }
        EXPECT_EQ(mapIntStringRandom.toVector(), solution);
    }

    for (int j = 0; j < 100; j++) {
        mymap<char, string> mapCharStringRandom;
        vector<pair<char, string> > solution;
        int randomSize = rand() % 100;
        string arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapCharStringRandom.put(i, arrRandom[i]);
            solution.push_back(make_pair(i, arrRandom[i]));
        }
        EXPECT_EQ(mapCharStringRandom.toVector(), solution);
    }
    for (int j = 0; j < 100; j++) {
        mymap<double, int> mapDoubleIntRandom;
        vector<pair<double, int> > solution;
        int randomSize = rand() % 100;
        int arrRandom[randomSize];
        for (int i = 0; i < randomSize; i++) {
            arrRandom[i] = rand() % 100;
            mapDoubleIntRandom.put(i, arrRandom[i]);
            solution.push_back(make_pair(i, arrRandom[i]));
        }
        EXPECT_EQ(mapDoubleIntRandom.toVector(), solution);
    }
}

TEST(myMap, checkBalance) {
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }
    string sol = "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    EXPECT_EQ(map.checkBalance(), sol);

    mymap<int, int> map1;
    int arr1[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        map1.put(arr1[i], arr1[i]);
    }
    string sol1 = "key: 1, nL: 0, nR: 2\nkey: 2, nL: 0, nR: 1\nkey: 3, nL: 0, nR: 0\n";
    EXPECT_EQ(map1.checkBalance(), sol1);

    mymap<string, int> map2;
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < 12; i++) {
        map2.put(to_string(arr2[i]), arr2[i]);
    }
    string sol2 = "key: 1, nL: 0, nR: 11\nkey: 2, nL: 0, nR: 10\nkey: 3, nL: 0, nR: 9\n"
                  "key: 4, nL: 0, nR: 8\nkey: 5, nL: 0, nR: 7\nkey: 6, nL: 0, nR: 6\n"
                  "key: 7, nL: 0, nR: 5\nkey: 8, nL: 0, nR: 4\nkey: 9, nL: 0, nR: 3\n"
                  "key: 10, nL: 0, nR: 2\nkey: 11, nL: 0, nR: 1\nkey: 12, nL: 0, nR: 0\n";
    EXPECT_NE(map2.checkBalance(), sol2);

    mymap<string, int> map3;
    int arr3[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int i = 0; i < 3; i++) {
        map3.put(to_string(arr3[i]), arr3[i]);
    }
    string sol3 =  "key: 12, nL: 0, nR: 11\nkey: 11, nL: 0, nR: 10\nkey: 10, nL: 0, nR: 9\n"
                   "key: 9, nL: 0, nR: 8\nkey: 8, nL: 0, nR: 7\nkey: 7, nL: 0, nR: 6\n"
                   "key: 6, nL: 0, nR: 5\nkey: 5, nL: 0, nR: 4\nkey: 4, nL: 0, nR: 3\n"
                   "key: 3, nL: 0, nR: 2\nkey: 2, nL: 0, nR: 1\nkey: 1, nL: 0, nR: 0\n";
    EXPECT_NE(map3.checkBalance(), sol3);
}
