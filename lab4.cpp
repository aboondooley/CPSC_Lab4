#include <iostream>
#include "IntBST.h"
using namespace std;

/**
 * Tests the basic functionality (from lecture 5)
 * @return true if all tests passed or false if any failed
 */
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

/**
 * Tests the empty(), size(), isLeaf(), and getLeafCount() methods!
 * @return true if all tests passed or false if any failed
 */
bool second_test(){
    string title = "second test: ";
    IntBST bst;
    cout << title << "check if empty tree is empty" << endl;
    if (!bst.empty())
        return false;

    cout << title << "check if size == 0" << endl;
    cout << "size == " << bst.size() << endl;
    if (bst.size()!=0)
        return false;

    cout << title << "check if empty tree has 0 leaves" << endl;
    cout << "number of leaves: " << bst.getLeafCount() << endl << endl;
    if (bst.getLeafCount()!=0)
        return false;

    cout << title << "add 1 node and check if tree is empty" << endl;
    bst.add(10);
    if (bst.empty())
        return false;

    cout << title << "check if size == 1" << endl;
    cout << "size == " << bst.size() << endl;
    if (bst.size()!=1)
        return false;

    cout << title << "check if number of leaves == 1" << endl;
    cout << "number of leaves: " << bst.getLeafCount() << endl << endl ;
    if (bst.getLeafCount()!=1)
        return false;

    cout << title << "add 10 nodes and check if tree is empty" << endl;
    bst.add(15); bst.add(3); bst.add(12);
    bst.add(8); bst.add(9); bst.add(1);
    bst.add(4); bst.add(17); bst.add(7);
    if (bst.empty())
        return false;

    cout << title << "check if size() == 10" << endl;
    cout << "size == " << bst.size() << endl;
    if (bst.size()!=10)
        return false;

    cout << title << "check if number of leaves == 5" << endl;
    cout << "number of leaves: " << bst.getLeafCount() << endl << endl;
    if (bst.getLeafCount()!=5)
        return false;

    cout << title << "remove 3 nodes and check if size() == 7" << endl;
    bst.remove(15); bst.remove(10); bst.remove(4);
    cout << "size == " << bst.size() << endl << endl;
    if (bst.size()!=7)
        return false;

    cout << title << "check if number of leaves == 3" << endl;
    cout << "number of leaves: " << bst.getLeafCount() << endl << endl;
    if (bst.getLeafCount()!=3)
        return false;

    cout << title << "add 9 nodes to 7 nodes and check if size is 16" << endl;
    bst.add(15); bst.add(10); bst.add(4);
    bst.add(57); bst.add(32); bst.add(14);
    bst.add(27); bst.add(11); bst.add(38);
    cout << "size == " << bst.size() << endl << endl;
    if (bst.size()!=16)
        return false;

    cout << title << "check if number of leaves == 6" << endl;
    cout << "number of leaves: " << bst.getLeafCount() << endl << endl;
    if (bst.getLeafCount()!=6)
        return false;

    cout << title;
    return true;
}


/**
 * Entry point to test all functionality of the IntBST class
 * @return 0
 */
int main() {
    cout << (first_test() ? "passed" : "failed") << endl << endl;
    cout << (second_test() ? "passed" : "failed") << endl << endl;
    return 0;
}
