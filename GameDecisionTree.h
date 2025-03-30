#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <vector> //added this to store nodes because it is a lot more efficient than having to count how many lines
//there are in the text file and then creating an array based on that size

template<typename T>
class GameDecisionTree {
private:
    Node<T> *root;

public:
    //Default constructor where the root starts off as nullptr to indicate an empty binary tree without any nodes O(1)
    GameDecisionTree() : root(nullptr) {
    }

    //Takes in the filename and custom delimiter from main.cpp to read each char of the txt file, obtain all parts of a
    //story (eventNumber, description, leftEventNumber, and rightEventNumber) to construct a story, create a node using
    //a story, and then linking the correct left and right node pointers. O(n) since it reads char by char.
    void loadStoryFromFile(const std::string &filename, char delimiter) {
        //variables needed to create stories and nodes
        char tempCharFromFile;
        string textReadFromFileSoFar;
        string tempDescription;
        int tempEventNumber;
        int tempLeftEventNumber;
        int tempRightEventNumber;
        int delimiterCtr;

        //variables used link the correct left and right node pointers
        vector<Node<T> *> binaryTree;
        Node<T> *temp;

        //used to open the story.txt file
        fstream readingFile;
        readingFile.open(filename);

        if (readingFile) { //true is an actual file that is able to be opened
            while (readingFile >> noskipws >> tempCharFromFile) { //This reads every character within the text file

                if (tempCharFromFile == delimiter || tempCharFromFile == '\n') {
                    delimiterCtr++;
                } else { //excludes the delimiter from being included in the content read so far
                    textReadFromFileSoFar.push_back(tempCharFromFile);
                }

                if (delimiterCtr == 1) {
                    tempEventNumber = stoi(textReadFromFileSoFar); //use stoi to convert the string to an int
                    textReadFromFileSoFar = "";
                    delimiterCtr++; //increment delimiterCtr to prevent unwanted repeat assignments of wrong information
                    //until another delimiter is found which would increment delimiterCtr again
                } else if (delimiterCtr == 3) {
                    tempDescription = textReadFromFileSoFar;
                    textReadFromFileSoFar = "";
                    delimiterCtr++;
                } else if (delimiterCtr == 5) {
                    tempLeftEventNumber = stoi(textReadFromFileSoFar);
                    textReadFromFileSoFar = "";
                    delimiterCtr++;
                } else if (delimiterCtr == 7) {
                    tempRightEventNumber = stoi(textReadFromFileSoFar);
                    textReadFromFileSoFar = "";
                    delimiterCtr++;
                }

                if (tempCharFromFile == '\n') { //the end of line means the conclusion of an event, so must reset
                    //delimiter ctr, create a story, create a node with a story, and add the node to a vector of
                    //binaryTree
                    delimiterCtr = 0;
                    T tempStory(tempDescription, tempEventNumber, tempLeftEventNumber, tempRightEventNumber);
                    Node<T> *tempNode = new Node<T>(tempStory, nullptr, nullptr);
                    binaryTree.push_back(tempNode); //doing this because to keep track of ALL nodes being created.
                }
            }
        } else { //edge case of file not being found
            cout << "File could not be found" << endl;
        }
        readingFile.close();

        for (int i = 0; i < binaryTree.size(); i++) { //peruses each node event that has been created and properly links
            //the left and right node pointers for each node to build the binary tree
            temp = binaryTree[i];
            tempLeftEventNumber = temp->data.leftEventNumber;
            tempRightEventNumber = temp->data.rightEventNumber;
            if (i == 0) {
                root = temp; //establishes the root of the binary tree
            }
            if (tempLeftEventNumber - 1 >= 0 && tempLeftEventNumber - 1 < binaryTree.size()) {
                temp->left = binaryTree[tempLeftEventNumber - 1]; //vector stores the node one index below the event number
            }
            if (tempRightEventNumber - 1 >= 0 && tempRightEventNumber - 1 < binaryTree.size()) {
                temp->right = binaryTree[tempRightEventNumber - 1];
            }
        }
    }

    //Traverses the binary tree outputting the current, left and right nodes. Provides user with the opportunity to go
    //left or right and to play again. Also notifies when the end of a path has been reached. O(logn) since tree is
    //traversed going left or right per decision.
    void playGame() {
        Node<T> *temp = root;
        string tempInput; //used to store user input
        while (temp != nullptr) { //runs until a leaf node is reached
            cout << temp->data.description;
            if (temp->left != nullptr && temp->right == nullptr) { //If there is a left node but no right node
                tempInput = "1"; //skips the user input because there would only be one path to take
                cout << endl;
            } else if (temp->left == nullptr && temp->right != nullptr) { //If there is a right node but no left node
                tempInput = "2"; //skips the user input because there would only be one path to take
                cout << endl;
            } else if (temp->left == nullptr && temp->right == nullptr) { //leaf node
                cout << "You have reached the end of the path. \n" << endl;
                cout << "Do you want to play again? ('1' for yes, '2' for no) \n" << endl;
                getline(cin, tempInput); //assign tempInput with the entire line of string from cin
                if (tempInput != "1" && tempInput != "2") {
                    cout<< "Invalid input. Please choose 1 or 2 : \n"<< endl;
                } else if (tempInput == "1") { //if player wants to play again, reset temp to be the root and tempInput back to 0
                    temp=root;
                    tempInput="";
                } else if (tempInput == "2") {
                    cout << "Thanks for playing!" << endl;
                    break; //indicates the end of the game since no more while-loop traversal of the tree
                }
            } else { //when there are multiple node options
                cout << "Do you: " << endl;
                cout << "1." << temp->left->data.description << "(Go left)" << endl;
                cout << "2." << temp->right->data.description << "(Go right)" << endl;
                cout << "Enter choice (1 for left, 2 for right): ";
                getline(cin, tempInput);
                cout << "You chose: " << tempInput << "\n" << endl;
                if (tempInput != "1" && tempInput != "2") {
                    cout<< "Invalid input. Please choose 1 or 2 : \n"<< endl;
                }
            }
            if (tempInput == "1") { //traverses left
                temp = temp->left;
            }
            else if (tempInput == "2") { //traverses right
                temp = temp->right;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H
