#include <iostream>
#include "IntBST.h"
using namespace std;

bool first_test(){
    string title = "first test: ";

    IntBST bst;
    cout << title << "check if empty tree has 1" << endl;
    if (bst.has(1))
        return false;

    cout << title << "add 1 and check tree has 1" << endl;
    bst.add(1);
    IntBST bst2(bst); // create copy to check later
    if (!bst.has(1))
        return false;

    cout << title << "remove 1 and check tree has 1" << endl;
    bst.remove(1);
    if (bst.has(1))
        return false;

    cout << title << "check if copy has 1" << endl;
    if (!bst2.has(1))
        return false;

    cout << title << "check assigned version has 1" << endl;
    bst = bst2;
    if (!bst.has(1))
        return false;

    cout << title;
    return true;
}

bool second_test(){
    string title = "second test: ";
    IntBST bst;
    cout << title << "check if empty tree is empty";
    if (!bst.empty())
        return false;

    cout << title << "add 10 and check if tree is empty";
    bst.add(10);
    if (bst.empty())
        return false;

    cout << title;
    return true;
}

int main() {
    cout << (first_test() ? "passed" : "failed") << endl;
    cout << (second_test() ? "passed" : "failed") << endl;

    return 0;
}
