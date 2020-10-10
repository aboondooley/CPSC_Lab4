//
// Created by Alie on 10/9/2020.
//

#include "IntBST.h"

IntBST::IntBST() {
    root = nullptr;
}


IntBST::~IntBST() {
    clear(root); // delete the root and everything below
}


IntBST::IntBST(const IntBST &other) {
    root = copy(other.root);
}


IntBST &IntBST::operator=(IntBST &rhs) {
    if (&rhs != this){
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

// Lab 4 methods below!!

bool IntBST::empty() const {
    if (root == nullptr) {
        return true;
    }
    return false;
}


bool IntBST::Node::isLeaf() const { // also method of IntBST::Node
    if (left == nullptr && right == nullptr){
        return true;
    }
    return false;
}


int IntBST::size() const {
    return size(root);
}

// recursive helper!
int IntBST::size(IntBST::Node *me) {
    if (me == nullptr)
        return 0;
    return 1 + size(me->right) + size(me->left);
}


int IntBST::getLeafCount() const {
    return getLeafCount(root);
}

// recursive helper!
int IntBST::getLeafCount(IntBST::Node *me) {
    if (me == nullptr)
        return 0;
    if (me->isLeaf())
        return 1;
    return getLeafCount(me->left) + getLeafCount(me->right);
}

// Lab 4 methods above!!

bool IntBST::has(int key) const {
    return has(root, key);
}

bool IntBST::has(IntBST::Node *me, int key) {
    if (me == nullptr)
        return false;
    if (key < me->key)
        return has(me->left, key);
    if (key > me->key)
        return has(me->right, key);
    // key == me->key
    return true;
}

void IntBST::add(int newKey) {
    root = add(root, newKey);
}

// recursive helper
IntBST::Node *IntBST::add(IntBST::Node *me, int newKey) {
    if (me == nullptr)
        // this is where I go!!
        me = new Node(newKey, nullptr, nullptr);
    else if (newKey < me->key)
        me->left = add(me->left, newKey);
    else if (newKey > me->key)
        me->right = add(me->right, newKey);
    // else equal (key already in set) - do nothing
    return me;
}


void IntBST::remove(int key) {
    root = remove(root, key);
}


IntBST::Node *IntBST::remove(IntBST::Node *me, int key) {
    if (me == nullptr)
        return nullptr; // nothing to remove, key not found
    if (key < me->key) {
        me->left = remove(me->left, key);
        return me;
    } else if (key > me->key) {
        me->right = remove(me->right, key);
        return me;
    } else {
        // FOUND IT!
        if (me->left == nullptr) {
            Node *myReplacement = me->right;
            delete me;
            return myReplacement;
        } else if (me->right == nullptr) {
            Node *myReplacement = me->left;
            delete me;
            return myReplacement;
        } else {
            // replace me with max element in my left subtree
            me->key = me->left->findMax();
            me->left = remove(me->left, me->key);
        }
    }

}


int IntBST::Node::findMax() const { // method of IntBST::Node
   if (right == nullptr)
        return key;
    else
        return right->findMax();
}


void IntBST::clear(IntBST::Node *me) {
    if (me != nullptr) {
        clear(me->left);
        clear(me->right);
        delete me;
    }
    // base case is nothing! The implied else - if the next is a nullptr then
    // we do nothing bc there is nothing to clear!
}


IntBST::Node *IntBST::copy(IntBST::Node *me) {
    if (me == nullptr) {
        return nullptr;
    }
    new Node(me->key, copy(me->left), copy(me->right));
}

