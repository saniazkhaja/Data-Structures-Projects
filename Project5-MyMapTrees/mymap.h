// mymap.h
//
// Name: Sania Khaja
// CS 251 Spring 2022
// Project 5: MyMap
// creating map functionality using Binary Search Trees
// utilized right and left pointers to connect nodes in tree
// tree is threaded
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

template<typename keyType, typename valueType>
class mymap {
 private:
    struct NODE {
        keyType key;  // used to build BST
        valueType value;  // stored data for the map
        NODE* left;  // links to left child
        NODE* right;  // links to right child
        int nL;  // number of nodes in left subtree
        int nR;  // number of nodes in right subtree
        bool isThreaded;
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of key/value pairs in the mymap

    //
    // iterator:
    // This iterator is used so that mymap will work with a foreach loop.
    //
    struct iterator {
     private:
        NODE* curr;  // points to current in-order node for begin/end

     public:
        iterator(NODE* node) {
            curr = node;
        }

        keyType operator *() {
            return curr -> key;
        }

        bool operator ==(const iterator& rhs) {
            return curr == rhs.curr;
        }

        bool operator !=(const iterator& rhs) {
            return curr != rhs.curr;
        }

        bool isDefault() {
            return !curr;
        }

        //
        // operator++:
        //
        // This function should advance curr to the next in-order node.
        // O(logN)
        //
        iterator operator++() {
            if (curr == nullptr) {
                return iterator(curr);
            }
            if (curr -> isThreaded == true) {
                curr = curr -> right;
            } else {
                curr = curr -> right;
                while (curr != nullptr) {
                    curr = curr -> left;
                }
            }
            return iterator(curr);
        }
    };

 public:
    //
    // default constructor:
    //
    // Creates an empty mymap.
    // Time complexity: O(1)
    //
    mymap() {
        root = nullptr;
        size = 0;
    }

    // pre-order recursion. Used for copying the tree
    // parameter used to keep track of what node we are on in the tree
    void _copy(NODE* othercurr) {
        if (othercurr == nullptr) {
            return;
        } else {
            put(othercurr -> key, othercurr -> value);
            _copy(othercurr -> left);
            _copy((othercurr -> isThreaded) ? nullptr : othercurr -> right);
        }
    }


    //
    // copy constructor:
    //
    // Constructs a new mymap which is a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap(const mymap& other) {
        size = 0;
        root = nullptr;
        _copy(other.root);
    }

    //
    // operator=:
    //
    // Clears "this" mymap and then makes a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap& operator=(const mymap& other) {
        clear();
        _copy(other.root);

        return *this;
    }

    // uses recursion to delete all nodes
    // post order traversal
    // parameter sed to know which node in tree we are on
    void _deleteTree(NODE* node) {
        if (node == nullptr) {
            return;
        } else {
            _deleteTree(node -> left);
            _deleteTree((node -> isThreaded) ? nullptr : node -> right);

            delete node;
            size--;
        }
    }

    // clear:
    //
    // Frees the memory associated with the mymap; can be used for testing.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    void clear() {
        if (root == nullptr) {
            return;
        } else {
            _deleteTree(root);
            root = nullptr;
        }
    }

    //
    // destructor:
    //
    // Frees the memory associated with the mymap.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    ~mymap() {
        clear();
    }

    //
    // put:
    //
    // Inserts the key/value into the threaded, self-balancing BST based on
    // the key.
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-tree that needs to be re-balanced.
    // Space complexity: O(1)
    //
    void put(keyType key, valueType value) {
        NODE* prev = nullptr;
        NODE* curr = root;

        // searching tree to see where to insert
        // if key exists then just updates value
        while (curr != nullptr) {
            // key exists and updates value
            if (key == curr -> key) {
                curr -> value = value;
                return;
            }
            // used to know where to move in tree
            if (key < curr -> key) {
                prev = curr;
                curr = curr -> left;
            } else {
                prev = curr;
                curr = (curr -> isThreaded) ? nullptr : curr -> right;
            }
        }
        // inserting new node if not found
        // setting default NODE values
        NODE* n = new NODE();
        n -> key = key;
        n -> value = value;
        n -> left = nullptr;
        n -> right = nullptr;
        n -> nL = 0;
        n -> nR = 0;
        n -> isThreaded = false;

        // no nodes were in tree
        if (prev == nullptr) {
            root = n;
        } else if (key < prev -> key) {  // checks were to insert node
            prev -> left = n;
            n -> right = prev;
            n -> isThreaded = true;
        } else {
            n -> right = prev -> right;
            prev -> right = n;
            n -> isThreaded = true;
            prev -> isThreaded = false;
        }
        size++;
    }

    //
    // contains:
    // Returns true if the key is in mymap, return false if not.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    bool contains(keyType key) {
        NODE* curr = root;

        // searching tree
        while (curr != nullptr) {
            // key exists and updates value
            if (key == curr -> key) {
                return true;
            }
            // used to know where to move in tree
            if (key < curr -> key) {
                curr = curr -> left;
            } else {
                curr = (curr -> isThreaded) ? nullptr : curr -> right;
            }
        }
        return false;
    }

    //
    // get:
    //
    // Returns the value for the given key; if the key is not found, the
    // default value, valueType(), is returned (but not added to mymap).
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    valueType get(keyType key) {
        NODE* curr = root;

        // searching tree
        while (curr != nullptr) {
            // key exists and updates value
            if (key == curr -> key) {
                return curr -> value;
            }
            // used to know where to move in tree
            if (key < curr -> key) {
                curr = curr -> left;
            } else {
                curr = (curr -> isThreaded) ? nullptr : curr -> right;
            }
        }
        return valueType();
    }

    //
    // operator[]:
    //
    // Returns the value for the given key; if the key is not found,
    // the default value, valueType(), is returned (and the resulting new
    // key/value pair is inserted into the map).
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-trees that need to be re-balanced.
    // Space complexity: O(1)
    //
    valueType operator[](keyType key) {
        NODE* curr = root;

        // searching tree
        while (curr != nullptr) {
            // key exists and updates value
            if (key == curr -> key) {
                return curr -> value;
            }
            // used to know where to move in tree
            if (key < curr -> key) {
                curr = curr -> left;
            } else {
                curr = (curr -> isThreaded) ? nullptr : curr -> right;
            }
        }
        // inserting node with default value in tree
        put(key, valueType());
        return valueType();
    }

    //
    // Size:
    //
    // Returns the # of key/value pairs in the mymap, 0 if empty.
    // O(1)
    //
    int Size() {
        return size;
    }

    //
    // begin:
    //
    // returns an iterator to the first in order NODE.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    iterator begin() {
        NODE* curr = root;
        if (curr == nullptr) {
            return iterator(curr);
        }
        // leftmost node would be first order NODE
        while (curr -> left != nullptr) {
            curr = curr -> left;
        }
        return iterator(curr);
    }

    //
    // end:
    //
    // returns an iterator to the last in order NODE.
    // this function is given to you.
    // 
    // Time Complexity: O(1)
    //
    iterator end() {
        return iterator(nullptr);
    }


    // uses recursion to build string
    // out used to store string and node is to know which node we are on
    // in-order traversal
    void _buildString(NODE* node, ostream& out) {
        if (node == nullptr) {
            return;
        }
        _buildString(node -> left, out);
        out << "key: " << node -> key << " value: " << node -> value << "\n";
        _buildString((node -> isThreaded) ? nullptr : node -> right, out);
    }
    //
    // toString:
    //
    // Returns a string of the entire mymap, in order.
    // Format for 8/80, 15/150, 20/200:
    // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string toString() {
        stringstream stringTree;
        _buildString(root, stringTree);

        return stringTree.str();
    }

    // recursive function
    // uses in-order and creates key and value pairs to store into vector
    // node keeps track of which node we are on
    // mapVector stores all <key, value> pairs
    void _buildVector(NODE* node, vector<pair<keyType, valueType> > &mapVector) {
        if (node == nullptr) {
            return;
        }
        _buildVector(node -> left, mapVector);
        mapVector.push_back(make_pair(node -> key, node -> value));
        _buildVector((node -> isThreaded) ? nullptr : node -> right, mapVector);
    }

    //
    // toVector:
    //
    // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
    // {{8, 80}, {15, 150}, {20, 200}}
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    vector<pair<keyType, valueType> > toVector() {
        vector<pair<keyType, valueType> > mapVector;
        _buildVector(root, mapVector);
        return mapVector;
    }

    // recursive function
    // uses pre-order to traverse and print tree key and nL and nR
    // node keeps track of which node in the tree we are on
    // out stores the string
    void _stringBalance(NODE* node, ostream& out) {
        if (node == nullptr) {
            return;
        } else {
            out << "key: " << node -> key << ", nL: " << node -> nL << ", nR: " << node -> nR << "\n";
            _stringBalance(node -> left, out);
            _stringBalance((node -> isThreaded) ? nullptr : node -> right, out);
        }
    }

    //
    // checkBalance:
    //
    // Returns a string of mymap that verifies that the tree is properly
    // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
    // function should return a string in this format (in pre-order):
    // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    // Time complexity: O(n), where n is total number of nodes in the
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string checkBalance() {
        stringstream stringTree;
        _stringBalance(root, stringTree);
        return stringTree.str();
    }
};
