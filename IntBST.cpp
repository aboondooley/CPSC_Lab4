//
// Created by Alie on 10/9/2020.
//

#include "IntBST.h"

IntBST::IntBST() {
    root = nullptr;
}

bool IntBST::has(int key) const {
    return has(root, key);
}

void IntBST::add(int newKey) {
    root = add(root, newKey);
}

void IntBST::remove(int key) {
    root = remove(root, key);

}

bool IntBST::empty() const {
    if (root == nullptr) {
        return true;
    }
    return false;
}

bool IntBST::has(IntBST::Node *me, int key) const {
    if (me == nullptr)
        return false;
    else if (key < me->key)
        return has(me->left, key);
    else if (key > me->key)
        return has(me->right, key);
    else // key == me->key
        return true;

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
    // else equal - do nothing
    return me;


}

IntBST::~IntBST() {
    clear(root); // delete the root and everything below

}

void IntBST::clear(IntBST::Node *me) {
    if (me != nullptr)
        clear(me->left);
    clear(me->right);
    delete me;
    // basecase is nothing! The implied else - if the next is a

}

IntBST::IntBST(const IntBST &other) {
    root = copy(other.root);

}

IntBST::Node *IntBST::copy(IntBST::Node *me) {
    if (me == nullptr)
        return nullptr;
    new Node(me->key, copy(me->left), copy(me->right));
}

IntBST &IntBST::operator=(IntBST &rhs) {
    if (&rhs != this){
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
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
    } else
        // FOUND IT!
    if (me->left == nullptr) {
        Node *myReplacement = me->right;
        delete me;
        return myReplacement;
    } else if (me->right == nullptr){
        Node *myReplacement = me->left;
        delete me;
        return myReplacement;
    } else {
        // replace me with max element in my left subtree
        me->key = me->left->findMax();
        me->left = remove(me->left, me->key);
    }

}



int IntBST::Node::findMax() const { // notice that it is within intBST and Node
    if (right == nullptr)
        return key;
    else
        return right->findMax();
}

bool IntBST::Node::isLeaf() const {
    if (left == nullptr && right == nullptr){
        return true;
    }
    return false;
}
