#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

 Node(T value, Node* tempLeft, Node* tempRight) : data(value), left(nullptr), right(nullptr) { } //Non-default constructor
    //which takes in a generic T value to assign for data while also leaving the Node* left and right as nullptr O(1)
 };

#endif // NODE_H