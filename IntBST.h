//
// Created by Alie on 10/9/2020.
//

#ifndef LAB4_INTBST_INTBST_H
#define LAB4_INTBST_INTBST_H


class IntBST {

public:
    IntBST();
    ~IntBST();
    IntBST &operator=(IntBST &rhs);
    IntBST(const IntBST &other);
    // TODO: rest of big 4
    // FIXME: does the same!

    bool has(int key) const;
    void add(int newKey);
    void remove(int key);
    bool empty() const;

private:
    struct Node{
        int key;
        Node *left, *right;

        // convenience constructor
        Node(int k, Node *lch, Node *rch){
            key = k;
            left = lch; // always think of left before right
            right = rch;
        }
        // there is no reason this is a method on the Node rather than on the
        int findMax() const;

        bool isLeaf() const;
    };
    Node *root;
    bool has(Node *me, int key) const;
    Node *add(Node *me, int key);
    Node *remove(Node *me, int key);
    Node *copy(Node *me);
    void clear(Node *me);

};


#endif //LAB4_INTBST_INTBST_H
