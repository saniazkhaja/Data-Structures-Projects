//
// STARTER CODE: util.h
//
// Name: Sania Khaja
// Does the huffman Encoding and Decoding
//

#include <iostream>
#include <fstream>
#include <map>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <string>
#include "bitstream.h"
#include "hashmap.h"
#include "mymap.h"
#pragma once

struct HuffmanNode {
    int character;
    int count;
    HuffmanNode* zero;
    HuffmanNode* one;
};

//
// *This method frees the memory allocated for the Huffman tree.
//
void freeTree(HuffmanNode* node) {
    if (node == NULL) {
        return;
    }

    // deleting subtrees
    freeTree(node -> zero);
    freeTree(node -> one);

    delete node;
}

//
// *This function build the frequency map.  If isFile is true, then it reads
// from filename.  If isFile is false, then it reads from a string filename.
//
void buildFrequencyMap(string filename, bool isFile, hashmap &map) {
    int val = 0;
    if (isFile == true) {
        ifstream inFS(filename);
        char c;
        while (inFS.get(c)) {
            if (map.containsKey(c) == false) {
                map.put(c, 1);
            } else {
                val = map.get(c) + 1;
                map.put(c, val);
            }
        }
    } else {
        for (char c : filename) {
            if (map.containsKey(c) == false) {
                map.put(c, 1);
            } else {
                val = map.get(c) + 1;
                map.put(c, val);
            }
        }
    }
    map.put(256, 1);
}

class prioritize  // you could also use a struct
{
public:
    bool operator()(const HuffmanNode* p1, const HuffmanNode* p2) const
    {
        return p1->count > p2->count;  // HuffmanNode* will be different
    }
};


//
// *This function builds an encoding tree from the frequency map.
//
HuffmanNode* buildEncodingTree(hashmap &map) {
    priority_queue<
            HuffmanNode*,
            vector<HuffmanNode*>,
            prioritize> pq;

    vector<int> allKeys = map.keys();
    for (int i = 0; i < map.size(); i++) {
        HuffmanNode* node1 = new HuffmanNode();

        node1 -> character = allKeys.at(i);
        node1 -> count = map.get(allKeys.at(i));

        pq.push(node1);
    }

    while (pq.size() > 1) {
        HuffmanNode* firstPop = pq.top();
        pq.pop();
        HuffmanNode* secondPop = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode();
        newNode -> count = firstPop -> count + secondPop -> count;
        newNode -> character = NOT_A_CHAR;
        newNode -> zero = firstPop;
        newNode -> one = secondPop;

        pq.push(newNode);
    }

    return pq.top();
}

void _preOrder(HuffmanNode* tree, mymap <int, string>& encodingMap, string buildString) {
    if (tree -> character != NOT_A_CHAR) {
        encodingMap.put((int)tree -> character, buildString);
        return;
    }

    buildString += "0";
    // left subtree
    _preOrder(tree->zero, encodingMap, buildString);
    buildString.erase(buildString.size() - 1);

    buildString += "1";
    // right subtree
    _preOrder(tree->one, encodingMap, buildString);
    buildString.erase(buildString.size() - 1);
}

//
// *This function builds the encoding map from an encoding tree.
//
mymap <int, string> buildEncodingMap(HuffmanNode* tree) {
    mymap <int, string> encodingMap;
    string buildString = "";

    if (tree == nullptr) {
        return encodingMap;
    }
    _preOrder(tree, encodingMap, buildString);

    return encodingMap;
}

//
// *This function encodes the data in the input stream into the output stream
// using the encodingMap.  This function calculates the number of bits
// written to the output stream and sets result to the size parameter, which is
// passed by reference.  This function also returns a string representation of
// the output file, which is particularly useful for testing.
//
string encode(ifstream& input, mymap <int, string> &encodingMap,
              ofbitstream& output, int &size, bool makeFile) {
    string theBits = "";
    char c;

    while (input.get(c)) {
        theBits += encodingMap.get(c);
    }
    theBits += encodingMap.get(PSEUDO_EOF);

    if (makeFile == true) {
        for (int i = 0; i < theBits.size(); i++) {
            if (theBits.at(i) == '0') {
                output.writeBit(0);
            } else if (theBits.at(i) == '1') {
                output.writeBit(1);
            } else {
                theBits.erase(i);
            }
        }
    }

    size = theBits.size();
    return theBits;
}


//
// *This function decodes the input stream and writes the result to the output
// stream using the encodingTree.  This function also returns a string
// representation of the output file, which is particularly useful for testing.
//
string decode(ifbitstream &input, HuffmanNode* encodingTree, ofstream &output) {
    string storingChars = "";
    HuffmanNode* root = encodingTree;
    while (!input.eof()) {
        int bit = input.readBit();
        if (bit == 0) {
            encodingTree = encodingTree -> zero;
        } else if (bit == 1) {
            encodingTree = encodingTree -> one;
        } else {
            continue;
        }

        if (encodingTree -> character == PSEUDO_EOF) {
            encodingTree = root;
            break;
        }
        if (encodingTree -> character != NOT_A_CHAR) {
            output.put(encodingTree -> character);
            storingChars += encodingTree -> character;
            encodingTree = root;
        }
    }
    return storingChars;
}

//
// *This function completes the entire compression process.  Given a file,
// filename, this function (1) builds a frequency map; (2) builds an encoding
// tree; (3) builds an encoding map; (4) encodes the file (don't forget to
// include the frequency map in the header of the output file).  This function
// should create a compressed file named (filename + ".huf") and should also
// return a string version of the bit pattern.
//
string compress(string filename) {
    hashmap frequencyMap;
    HuffmanNode *tree;
    int size = 0;
    mymap <int, string> encodingMap;
    string compressed = "";

    buildFrequencyMap(filename, true, frequencyMap);
    tree = buildEncodingTree(frequencyMap);
    encodingMap = buildEncodingMap(tree);
    ofbitstream output(filename + ".huf");
    output << frequencyMap;
    ifstream input(filename);
    encode(input, encodingMap, output, size, true);
    freeTree(tree);

    return compressed;
}

//
// *This function completes the entire decompression process.  Given the file,
// filename (which should end with ".huf"), (1) extract the header and build
// the frequency map; (2) build an encoding tree from the frequency map; (3)
// using the encoding tree to decode the file.  This function should create a
// compressed file using the following convention.
// If filename = "example.txt.huf", then the uncompressed file should be named
// "example_unc.txt".  The function should return a string version of the
// uncompressed file.  Note: this function should reverse what the compress
// function did.
//
string decompress(string filename) {
    hashmap frequencyMap;
    HuffmanNode *tree;
    string decoded = "";

    ifbitstream input(filename);
    ofstream output(filename.substr(0, filename.find('.')) + "_unc.txt");
    input >> frequencyMap;

    tree = buildEncodingTree(frequencyMap);

    decoded = decode(input, tree, output);
    freeTree(tree);

    return decoded;
}
