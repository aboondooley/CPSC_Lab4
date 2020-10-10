//
// Created by Alie on 10/9/2020.
//

#ifndef LAB4_INTBST_INTBST_H
#define LAB4_INTBST_INTBST_H


class IntBST {

public:
    IntBST();
    ~IntBST();
    IntBST(const IntBST &other);
    IntBST &operator=(IntBST &rhs);


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

    public:
        bool isLeaf() const;
    };
    Node *root;
    static bool has(Node *me, int key);
    static Node *add(Node *me, int key);
    static Node *remove(Node *me, int key);
    static Node *copy(Node *me);
    static void clear(Node *me);

};


#endif //LAB4_INTBST_INTBST_H
