#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

 Node(T value, Node* tempLeft, Node* tempRight) : data(value), left(nullptr), right(nullptr) { } //Non-default constructor
    //which takes in a generic T value and left and right Node pointers and assigns the instance variables with them
 };

#endif // NODE_H