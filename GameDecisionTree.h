#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <vector>//added this so make sure to describe how you added this because it is a lot more efficient than having to count how many lines there are in the text file and then havin to create an array based on that size and the n trying to persue again to re add it all
template<typename T>
class GameDecisionTree {
private:
    Node<T> *root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {
    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string &filename, char delimiter) {
        char tempCharFromFile;
        string textReadFromFileSoFar;
        string tempDescription;
        int delimiterCtr = 0;
        int tempEventNumber;
        int tempLeftEventNumber;
        int tempRightEventNumber;
        vector<Node<T> *> binaryTree;
        int tempIndex;
        int nodeCtr = 0;
        fstream readingFile;

        readingFile.open(filename);
        if (readingFile) {
            //used to check if there is an actual file there to begin with
            while (readingFile >> noskipws >> tempCharFromFile) {
                //This reads every character within the text file
                //count delimiters, check where end line is, its basically checking each character, then does an if chain
                if (tempCharFromFile == delimiter || tempCharFromFile == '\n') {
                    delimiterCtr++;
                } else {
                    //excludes the delimiter from being included
                    textReadFromFileSoFar.push_back(tempCharFromFile);
                }

                if (delimiterCtr == 1) {
                    tempEventNumber = stoi(textReadFromFileSoFar);
                    //cout << "Here is my event number: " << tempEventNumber << endl;
                    textReadFromFileSoFar = "";
                    delimiterCtr++;
                } else if (delimiterCtr == 3) {
                    tempDescription = textReadFromFileSoFar;
                    //cout << "Here is my description: " << tempDescription << endl;
                    textReadFromFileSoFar = "";
                    delimiterCtr++;
                } else if (delimiterCtr == 5) {
                    tempLeftEventNumber = stoi(textReadFromFileSoFar);
                    //cout << "Here is my left event number: " << tempLeftEventNumber << endl;
                    textReadFromFileSoFar = "";
                    delimiterCtr++;
                } else if (delimiterCtr == 7) {
                    tempRightEventNumber = stoi(textReadFromFileSoFar);
                    //cout << "Here is my right event number: " << tempRightEventNumber << endl;
                    textReadFromFileSoFar = "";
                    delimiterCtr++;
                }

                if (tempCharFromFile == '\n') {
                    delimiterCtr = 0;
                    Story tempStory(tempDescription, tempEventNumber, tempLeftEventNumber, tempRightEventNumber);
                    Node<T> *tempNode = new Node<T>(tempStory, nullptr, nullptr);
                    binaryTree.push_back(tempNode); //doing this because to keep track of ALL nodes being created.
                }
            }
        } else {
            cout << "File could not be found" << endl;
        }
        readingFile.close();

        Node<T> *temp;
        for (int i=0; i<binaryTree.size(); i++) {
            temp=binaryTree[i];
            tempLeftEventNumber = temp->data.leftEventNumber;
            tempRightEventNumber = temp->data.rightEventNumber;
            if (i==0) {
                root= temp;
            }
            if (tempLeftEventNumber!= -1 && tempLeftEventNumber-1>=0 && tempLeftEventNumber-1<binaryTree.size()) {
                temp->left = binaryTree[tempLeftEventNumber - 1];
            }
            if (tempRightEventNumber!= -1 && tempRightEventNumber-1>=0 && tempRightEventNumber-1<binaryTree.size()) {
                temp->right = binaryTree[tempRightEventNumber - 1];
            }
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T> *temp = root;
        int tempInput;
        while (temp != nullptr) {
            cout << temp->data.description;
            if (temp->left != nullptr && temp->right == nullptr) { //If there is a left node but no right node
                tempInput=1;
                cout << endl;
            }
            else if (temp->left == nullptr && temp->right != nullptr ) { //If there is a right node but no left node
                tempInput=2;
                cout << endl;
            }
            else if (temp->left == nullptr && temp->right == nullptr) {
                cout << "You have reached the end of the path. " << endl;
                break;
            } else {
                cout << "Do you: " << endl;
                cout << "1." << temp->left->data.description << "(Go left)" << endl;
                cout << "2." << temp->right->data.description << "(Go right)" << endl;
                cout << "Enter choice (1 for left, 2 for right): ";
                cin >> tempInput;
                cout << tempInput << "\n" << endl;
            }

            if (tempInput == 1) {
                temp = temp->left;
            }
            if (tempInput == 2) {
                temp = temp->right;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H
