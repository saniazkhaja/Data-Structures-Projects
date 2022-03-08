// TO DO:  Write file header.
// Name: Sania Khaja
// Project: Labyrinth Escape II
// Spring 2022
// Used linked list to create a board
// accesses amount of rows, columns
// has default, parameterized and copy constructor
// uses memory allocation

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
class Grid {
private:
    struct CELL {
        CELL* Next;
        T Val;
        size_t NumCols;  // total # of columns (0..NumCols-1)
        CELL(CELL* _Next = nullptr, T _Val = T(), size_t _NumCols = 0) {
            Next = _Next;
            Val = _Val;
            NumCols = _NumCols;
        }
    };

    size_t NumRows;  // total # of rows (0..NumRows-1)
    CELL** Rows;     // C array of linked lists
public:
    //
    // default constructor:
    //
    // Called automatically by C++ to construct a 4x4 Grid.  All
    // elements are initialized to the default value of T.
    //
    Grid() {
        // initialize 4 rows
        Rows = new CELL*[4];
        NumRows = 4;

        // allocate the first cell of the linked list with default value:
        for (size_t r = 0; r < NumRows; ++r) {
            Rows[r] = new CELL(nullptr, T(), 4);
            CELL* cur = Rows[r];

            // create the linked list for this row.
            for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
                cur->Next = new CELL(nullptr, T());
                cur = cur->Next;
            }
        }

    }


    //
    // parameterized constructor:
    //
    // Called automatically by C++ to construct a Grid with R rows,
    // where each row has C columns. All elements are initialized to
    // the default value of T.
    //
    Grid(size_t R, size_t C) {
        Rows = new CELL*[R];
        NumRows = R;

        // allocate the first cell of the linked list with parameter values:
        for (size_t r = 0; r < NumRows; ++r) {
            Rows[r] = new CELL(nullptr, T(), C);
            CELL* cur = Rows[r];

            // creating the linked list for this row.
            for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
                cur->Next = new CELL(nullptr, T());
                cur = cur->Next;
            }
        }
    }


    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the vector.
    //
    virtual ~Grid() {
        for (size_t r = 0; r < NumRows; r++) {
            CELL *cur = Rows[r];
            CELL *temp = Rows[r];
            int cols = Rows[r]->NumCols;
            // deleting each value in linked list
            for (size_t c = 0; c < cols; c++) {
                temp = cur->Next;
                delete cur;
                cur = temp;
            }
            delete temp;
        }
        delete[] Rows;
    }


    //
    // copy constructor:
    //
    // Called automatically by C++ to construct a Grid that contains a
    // copy of an existing Grid.  Example: this occurs when passing
    // Grid as a parameter by value
    //
    //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
    //   { ... }
    //
    Grid(const Grid<T>& other) {
        // looking to know how many rows to create based on other
        this -> Rows = new CELL*[other.NumRows];
        this -> NumRows = other.NumRows;

        // going through linked list
        for (size_t r = 0; r < NumRows; ++r) {
            // creates columns
            Rows[r] = new CELL(nullptr, T(), other.Rows[r]->NumCols);
            this -> Rows[r] -> NumCols = other.Rows[r]->NumCols;
            // used to keep track of which position in both linked lists
            CELL* curOther = other.Rows[r];
            CELL* curRows = Rows[r];

            // create new linked list for this row
            // sets values from other linked list to class linked list
            // does this for all values
            for(size_t c = 0; c < Rows[r]->NumCols; ++c) {
                curRows->Next = new CELL(nullptr, T());
                curRows -> Val = curOther -> Val;
                curOther = curOther -> Next;
                curRows = curRows -> Next;
            }
        }
    }


    //
    // copy operator=
    //
    // Called when you assign one vector into another, i.e. this = other;
    //
    Grid& operator=(const Grid& other) {
        // may need to assign values too
        Grid<T> temp;

        // checking to make sure not the same memory address
        if (this == &other) {
            return *this;
        }
        // deleting elements
        for (size_t r = 0; r < NumRows; r++) {
            CELL *cur = Rows[r];
            CELL *temp = Rows[r];
            int cols = Rows[r]->NumCols;
            for (size_t c = 0; c < cols; c++) {
                temp = cur->Next;
                delete cur;
                cur = temp;
            }
            delete temp;
        }
        delete[] Rows;

        // copying over all data
        // similar to copy constructor
        this -> Rows = new CELL*[other.NumRows];
        this -> NumRows = other.NumRows;

        for (size_t r = 0; r < NumRows; ++r) {
            Rows[r] = new CELL(nullptr, T(), other.Rows[r]->NumCols);
            this -> Rows[r] -> NumCols = other.Rows[r]->NumCols;
            CELL* curOther = other.Rows[r];
            CELL* curRows = Rows[r];

            // create the linked list for this row.
            for(size_t c = 0; c < Rows[r]->NumCols; ++c) {
                curRows->Next = new CELL(nullptr, T());
                curRows -> Val = curOther -> Val;
                curOther = curOther -> Next;
                curRows = curRows -> Next;
            }
        }
        return *this;
    }


    //
    // numrows
    //
    // Returns the # of rows in the Grid.  The indices for these rows
    // are 0..numrows-1.
    //
    size_t numrows() const {
        return NumRows;
    }


    //
    // numcols
    //
    // Returns the # of columns in row r.  The indices for these columns
    // are 0..numcols-1.  For now, each row will have the same number of columns.
    //
    size_t numcols(size_t r) const {
        if (r >= NumRows) {
            throw invalid_argument("InValid r");
        }
        return Rows[r]->NumCols;
    }


    //
    // size
    //
    // Returns the total # of elements in the grid.
    //
    size_t size() const {
        return NumRows * Rows[0]->NumCols;
    }


    //
    // ()
    //
    // Returns a reference to the element at location (r, c); this
    // allows you to access the element or change it:
    //
    //    grid(r, c) = ...
    //    cout << grid(r, c) << endl;
    //
    T& operator()(size_t r, size_t c) {
        T temp;
        if (r >= NumRows) {
            throw invalid_argument("InValid r");
        }
        if (c >= Rows[r] -> NumCols) {
            throw invalid_argument("InValid c");
        }

        CELL* cur = Rows[r];
        // going through column nodes
        for (size_t col = 0; col < c; col++) {
            cur = cur -> Next;
        }
        return cur -> Val;
    }

    //
    // _output
    //
    // Outputs the contents of the grid; for debugging purposes.  This is not
    // tested.
    //
    void _output() {
        // goes through each row
        for (size_t r = 0; r < NumRows; r++) {
            CELL* cur = Rows[r];
            // goes through each column and prints the value in it
            for (size_t c = 0; c < Rows[r]->NumCols; c++) {
                cout << " " << cur -> Val << " ";
                cur = cur -> Next;
            }
            cout << endl;
        }
        cout << endl;
    }
};
