#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarGetName() {
    Bar b("Chicago", 9234324, "US");
    Bar c("New York", 10000, "USA");
    if (b.getName() != "Chicago") {
        cout << "testBarGetName: getName() Bar b failed" << endl;
        return false;
    }
    if (c.getName() != "New York") {
        cout << "testBarGetName: getName() Bar c failed" << endl;
        return false;
    }
    cout << "testBarGetName: all passed!" << endl;
    return true;
}

bool testBarGetValue() {
    Bar b("Chicago", 9234324, "US");
    Bar c("New York", 10000, "USA");
    if (b.getValue() != 9234324) {
        cout << "testBarGetValue: getValue() Bar b failed" << endl;
        return false;
    }
    if (c.getValue() != 10000) {
        cout << "testBarGetName: getValue() Bar c failed" << endl;
        return false;
    }
    cout << "testBarGetValue: all passed!" << endl;
    return true;
}

bool testBarGetCategory() {
    Bar b("Chicago", 9234324, "US");
    Bar c("New York", 10000, "USA");
    if (b.getCategory() != "US") {
        cout << "testBarGetCategory: getCategory() Bar b failed" << endl;
        return false;
    }
    if (c.getCategory() != "USA") {
        cout << "testBarGetCategory: getCategory() Bar c failed" << endl;
        return false;
    }
    cout << "testBarGetCategory: all passed!" << endl;
    return true;
}

bool testBarOperatorLessThan() {
    Bar b1("a", 1, "cat");
    Bar b2("b", 2, "cat");
    Bar b3("c", 10, "cat");
    Bar b4("d", 5, "cat");
    if (!b1.operator < (b2)) {
        cout << "testBarOperatorLessThan: b1 vs b2 (1 < 2) failed" << endl;
        return false;
    }
    if (!b4.operator < (b3)) {
        cout << "testBarOperatorLessThan: b4 vs b3 (5 < 10) failed" << endl;
        return false;
    }
    cout << "testBarOperatorLessThan: all passed!" << endl;
    return true;
}

bool testBarOperatorLessThanEqual() {
    Bar b1("a", 1, "cat");
    Bar b2("b", 2, "cat");
    Bar b3("c", 10, "cat");
    Bar b4("d", 5, "cat");
    Bar b5("e", 20, "cat");
    Bar b6("f", 20, "cat");

    if (!b1.operator <= (b2)) {
        cout << "testBarOperatorLessThanEqual: b1 vs b2 (1 <= 2) failed" << endl;
        return false;
    }
    if (!b4.operator <= (b3)) {
        cout << "testBarOperatorLessThanEqual: b4 vs b3 (5 <= 10) failed" << endl;
        return false;
    }
    if (!b5.operator <= (b6)) {
        cout << "testBarOperatorLessThanEqual: b5 vs b6 (20 <= 20) failed" << endl;
        return false;
    }
    if (!b6.operator <= (b5)) {
        cout << "testBarOperatorLessThanEqual: b6 vs b5 (20 <= 20) failed" << endl;
        return false;
    }
    cout << "testBarOperatorLessThanEqual: all passed!" << endl;
    return true;
}

bool testBarOperatorGreaterThan() {
    Bar b1("a", 1, "cat");
    Bar b2("b", 2, "cat");
    Bar b3("c", 10, "cat");
    Bar b4("d", 5, "cat");
    if (!b2.operator > (b1)) {
        cout << "testBarOperatorGreaterThan: b2 vs b1 (2 > 1) failed" << endl;
        return false;
    }
    if (!b3.operator > (b4)) {
        cout << "testBarOperatorGreaterThan: b3 vs b4 (10 > 5) failed" << endl;
        return false;
    }
    cout << "testBarOperatorGreaterThan: all passed!" << endl;
    return true;
}

bool testBarOperatorGreaterThanEqual() {
    Bar b1("a", 1, "cat");
    Bar b2("b", 2, "cat");
    Bar b3("c", 10, "cat");
    Bar b4("d", 5, "cat");
    Bar b5("e", 20, "cat");
    Bar b6("f", 20, "cat");

    if (!b2.operator >= (b1)) {
        cout << "testBarOperatorGreaterThanEqual: b2 vs b1 (2 >= 1) failed" << endl;
        return false;
    }
    if (!b3.operator >= (b4)) {
        cout << "testBarOperatorGreaterThanEqual: b3 vs b4 (10 >= 5) failed" << endl;
        return false;
    }
    if (!b5.operator >= (b6)) {
        cout << "testBarOperatorGreaterThanEqual: b5 vs b6 (20 >= 20) failed" << endl;
        return false;
    }
    if (!b6.operator >= (b5)) {
        cout << "testBarOperatorGreaterThanEqual: b6 vs b5 (20 >= 20) failed" << endl;
        return false;
    }
    cout << "testBarOperatorGreaterThanEqual: all passed!" << endl;
    return true;
}

bool testBarChartDefaultConstructor() {
    BarChart b;
    if (b.getFrame() != "") {
        cout << "testBarChartDefaultConstructor: getFrame() failed" << endl;
        return false;
    } else if (b.getSize() != 0) {
        cout << "testBarChartDefaultConstructor: getSize() failed" << endl;
        return false;
    }
    cout << "testBarChartDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarChartParamConstructor() {
    BarChart b(1);
    BarChart c(10000);
    if (b.getFrame() != "") {
        cout << "testBarChartParamConstructor: getFrame() b failed" << endl;
        return false;
    } else if (b.getSize() != 0) {
        cout << "testBarChartParamConstructor: getSize() b failed" << endl;
        return false;
    } else if (c.getFrame() != "") {
        cout << "testBarChartParamConstructor: getFrame() c failed" << endl;
        return false;
    } else if (c.getSize() != 0) {
        cout << "testBarChartParamConstructor: getSize() c failed" << endl;
        return false;
    } else if (!b.addBar("a", 1, "cat")) {
        cout << "testBarChartParamConstructor: add b failed" << endl;
        return false;
    }
    cout << "testBarChartParamConstructor: all passed!" << endl;
    return true;
}

bool testBarChartCopyConstructor() {
    BarChart bc(1);
    BarChart bcCopy(bc);

    BarChart bcc(1);
    bcc.addBar("a", 1, "cat");
    BarChart bccCopy(bcc);

    BarChart bccc(10);
    bccc.addBar("a", 1, "cat");
    bccc.addBar("b", 2, "cat");
    bccc.setFrame("1950");
    BarChart bcccCopy(bccc);

    if (bcCopy.getFrame() != "") {
        cout << "testBarChartCopyConstructor: getFrame() bcCopy failed" << endl;
        return false;
    } else if (bcCopy.getSize() != 0) {
        cout << "testBarChartCopyConstructor: getSize() bcCopy failed" << endl;
        return false;
    } else if (!bcCopy.addBar("a", 1, "cat")) {
        cout << "testBarChartCopyConstructor: add bcCopy failed" << endl;
        return false;
    } else if (bccCopy.getSize() != 1) {
        cout << "testBarChartCopyConstructor: bccCopy size failed" << endl;
        return false;
    } else if (bcccCopy.getSize() != 2) {
        cout << "testBarChartCopyConstructor: bcccCopy size failed" << endl;
        return false;
    } else if (bcccCopy.getFrame() != "1950") {
        cout << "testBarChartCopyConstructor: bcccCopy frame failed" << endl;
        return false;
    }
    cout << "testBarChartCopyConstructor: all passed!" << endl;
    return true;
}

bool testBarChartCopyOperatorEqual() {
    BarChart bc1;
    BarChart bc2(10);
    bc1 = bc2;

    BarChart bc3;
    BarChart bc4(10);
    bc4.addBar("a", 1, "cat");
    bc4.addBar("b", 2, "cat");
    bc4.setFrame("1950");
    bc3 = bc4;

    if (bc1.getSize() != bc2.getSize()) {
        cout << "testBarChartCopyOperatorEqual: getSize() failed" << endl;
        return false;
    } else if (bc1.getFrame() != bc2.getFrame()) {
        cout << "testBarChartCopyOperatorEqual: getFrame() failed" << endl;
        return false;
    } else if (bc3.getSize() != bc4.getSize()) {
        cout << "testBarChartCopyOperatorEqual: getSize() failed" << endl;
        return false;
    } else if (bc3.getFrame() != bc4.getFrame()) {
        cout << "testBarChartCopyOperatorEqual: getFrame() failed" << endl;
        return false;
    }
    cout << "testBarChartCopyOperatorEqual: all passed!" << endl;
    return true;
}

bool testBarChartClear() {
    BarChart bc(10);
    bc.addBar("a", 1, "cat");
    bc.addBar("b", 2, "cat");
    bc.setFrame("1950");
    bc.clear();

    if (bc.getSize() != 0) {
        cout << "testBarChartClear: getSize() failed" << endl;
        return false;
    } else if (bc.getFrame() != "") {
        cout << "testBarChartClear: getFrame() failed" << endl;
        return false;
    }
    BarChart bcc(1);
    bc.addBar("b", 20, "cat");
    bc.setFrame("2020");
    bcc.clear();
    if (bcc.getSize() != 0) {
        cout << "testBarChartClear: getSize() failed" << endl;
        return false;
    } else if (bcc.getFrame() != "") {
        cout << "testBarChartClear: getFrame() failed" << endl;
        return false;
    }
    cout << "testBarChartClear: all passed!" << endl;
    return true;
}

bool testBarChartFrame() {
    BarChart bc;
    bc.setFrame("100");

    BarChart bc1(20);
    bc1.setFrame("YAY");

    if (bc.getFrame() != "100") {
        cout << "testBarChartFrame: getFrame() failed" << endl;
        return false;
    } else if (bc1.getFrame() != "YAY") {
        cout << "testBarChartFrame: getFrame() failed" << endl;
        return false;
    }
    cout << "testBarChartFrame: all passed!" << endl;
    return true;
}

bool testBarChartAddBar() {
    BarChart bc(10);
    if (!bc.addBar("a", 1, "cat")) {
        cout << "testBarChartAddBar: adding bar failed" << endl;
        return false;
    }
    bc.clear();
    BarChart bc1(0);
    if (bc1.addBar("a", 1, "cat")) {
        cout << "testBarChartAddBar: adding bar did not fail when it should have" << endl;
        return false;
    }
    bc1.clear();
    BarChart bc2(1);
    if (!bc2.addBar("a", 1, "cat")) {
        cout << "testBarChartAddBar: adding bar failed" << endl;
        return false;
    } else if (bc2.addBar("b", 2, "cat")) {
        cout << "testBarChartAddBar: adding bar did not fail when it should have" << endl;
        return false;
    }
    cout << "testBarChartAddBar: all passed!" << endl;
    return true;
}

bool testBarChartGetSize() {
    BarChart bc(10);
    bc.addBar("a", 1, "cat");
    bc.addBar("b", 2, "cat");

    BarChart bc1(1);
    bc1.addBar("a", 1, "cat");

    if (bc.getSize() != 2) {
        cout << "testBarGetSize: getSize() failed" << endl;
        return false;
    } else if (bc1.getSize() != 1) {
        cout << "testBarGetSize: getSize() failed" << endl;
        return false;
    }
    cout << "testBarGetSize: all passed!" << endl;
    return true;
}

bool testBarChartOperatorArray() {
    BarChart bc(1);
    bc.addBar("a", 1, "cat");

    if (bc[0].getName() != "a") {
        cout << "testBarChartOperatorArray: getName() failed";
        return false;
    } else if (bc[0].getValue() != 1) {
        cout << "testBarChartOperatorArray: getValue() failed";
        return false;
    } else if (bc[0].getCategory() != "cat") {
        cout << "testBarChartOperatorArray: getCategory() failed";
        return false;
    }
    cout << "testBarChartOperatorArray: all passed!" << endl;
    return true;
}

bool testBarChartDump() {
    BarChart bc(5);
    bc.addBar("a", 1, "cat");
    bc.addBar("b", 2, "cat");
    bc.addBar("c", 1020, "cat");
    bc.addBar("d", 1200, "cat");
    bc.addBar("e", 1300, "cat");
    bc.dump(cout);

    cout << endl;

    stringstream ss("");
    bc.dump(ss);
    cout << ss.str();

    cout << "testBarChartDump: all passed!" << endl;
    return true;
}

bool testBarChartGraph() {
    BarChart bc(5);
    bc.addBar("a", 1, "cat");
    bc.addBar("b", 2, "cat");
    bc.addBar("c", 1020, "dog");
    bc.addBar("d", 1200, "dog");
    bc.addBar("e", 1300, "cat");

    string red("\033[1;36m");
    string blue("\033[1;33m");
    map<string, string> colorMap;
    colorMap["cat"] = red;
    colorMap["dog"] = blue;
    bc.graph(cout, colorMap, 3);
    if (bc.getSize() != 5) {
        cout << "testBarChartGraph: wrong size" << endl;
        return false;
    } else if (!colorMap.count("cat")) {
        cout << "testBarChartGraph: key not added" << endl;
        return false;
    }
    cout << "testBarChartGraph: all passed!" << endl;
    colorMap.clear();
    bc.graph(cout, colorMap, 3);
    return true;
}

bool testBarChartAnimateParamConstructor() {
    BarChartAnimate bca("title", "xlabel", "source");
    BarChartAnimate bca1("1", "2", "3");
    if (bca.getSize() != 0) {
        cout << "testBarChartAnimateParamConstructor: getSize() failed" << endl;
        return false;
    }
    if (bca1.getSize() != 0) {
        cout << "testBarChartAnimateParamConstructor: getSize() failed" << endl;
        return false;
    }
    cout << "testBarChartAnimateParamConstructor: all passed!" << endl;
    return true;
}

bool testBarChartAnimateArray() {
    string filename = "cities.txt";
    ifstream inFile(filename);
    string title;
    getline(inFile, title);
    string xlabel;
    getline(inFile, xlabel);
    string source;
    getline(inFile, source);

    BarChartAnimate bca(title, xlabel, source);

    while (!inFile.eof()) {
        bca.addFrame(inFile);
    }
    if (bca[0].getSize() != 12) {
        cout << "testBarChartAnimateArray: wrong size" << endl;
        return false;
    } else if (bca[0].getFrame() != "1500") {
        cout << "testBarChartAnimateArray: wrong frame" << endl;
        return false;
    }

    cout << "testBarChartAnimateArray: all passed!" << endl;
    return true;
}

bool testBarChartAnimateAddFrame() {
    string filename = "cities.txt";
    ifstream inFile(filename);
    string title;
    getline(inFile, title);
    string xlabel;
    getline(inFile, xlabel);
    string source;
    getline(inFile, source);

    BarChartAnimate bca(title, xlabel, source);

    while (!inFile.eof()) {
        bca.addFrame(inFile);
    }
    if (bca[1].getSize() != 12) {
        cout << "testBarChartAnimateAddFrame: wrong size" << endl;
        return false;
    } else if (bca[1].getFrame() != "1501") {
        cout << "testBarChartAnimateAddFrame: wrong frame" << endl;
        return false;
    } if (bca[2].getSize() != 12) {
        cout << "testBarChartAnimateAddFrame: wrong size" << endl;
        return false;
    } else if (bca[2].getFrame() != "1502") {
        cout << "testBarChartAnimateAddFrame: wrong frame" << endl;
        return false;
    }

    cout << "testBarChartAnimateAddFrame: all passed!" << endl;
    return true;
}

bool testBarChartAnimateAnimate() {
    string filename = "cities.txt";
    ifstream inFile(filename);
    string title;
    getline(inFile, title);
    string xlabel;
    getline(inFile, xlabel);
    string source;
    getline(inFile, source);

    BarChartAnimate bca(title, xlabel, source);

    while (!inFile.eof()) {
        bca.addFrame(inFile);
    }
    bca.animate(cout, 12, 2);

    if (bca.getSize() != 519) {
        cout << "testBarChartAnimateAnimate: wrong size" << endl;
        return false;
    }
    cout << "testBarChartAnimateAddFrame: all passed!" << endl;
    return true;
}

int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
    testBarGetName();
    testBarGetValue();
    testBarGetCategory();
    testBarOperatorLessThan();
    testBarOperatorLessThanEqual();
    testBarOperatorGreaterThan();
    testBarOperatorGreaterThanEqual();
    testBarChartDefaultConstructor();
    testBarChartParamConstructor();
    testBarChartCopyConstructor();
    testBarChartCopyOperatorEqual();
    testBarChartClear();
    testBarChartFrame();
    testBarChartAddBar();
    testBarChartGetSize();
    testBarChartOperatorArray();
    testBarChartDump();
    testBarChartGraph();
    testBarChartAnimateParamConstructor();
    testBarChartAnimateArray();
    testBarChartAnimateAddFrame();
    testBarChartAnimateAnimate();
	
    return 0;
}