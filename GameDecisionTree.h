#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        string lineFromFile;
        string tempDescription;
        int tempEventNumber;
        int tempLeftEventNumber;
        int tempRightEventNumber;
        //Story tempStory;
        int tempIndex;
        ifstream readingFile;

        readingFile.open(filename);
        if (readingFile.is_open()) {
            //used to check if there is an actual file there to begin with
            while (getline(readingFile, lineFromFile)) {
                cout << "Hello!" << endl;
            }
        } else {
            cout << "File could not be found" << endl;
        }
        readingFile.close();
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){}
};

#endif // GAMEDECISIONTREE_H