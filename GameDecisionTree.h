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
        int ctr=0;
        int tempEventNumber;
        int tempLeftEventNumber;
        int tempRightEventNumber;
        //Story tempStory;
        int tempIndex;
        ifstream readingFile;

        readingFile.open(filename);
        if (readingFile) {//used to check if there is an actual file there to begin with
            while (getline(readingFile, lineFromFile, delimiter)) { //while (getline(readingFile, lineFromFile, delimiter))


                cout << lineFromFile << endl; //current issue is that another delimiter is missing...somehow need to figure out how to recgonize a new line?
                if (ctr==0) {
                    tempEventNumber = stoi(lineFromFile);
                    ctr++;
                    cout << "The event number is: " << tempEventNumber << endl;
                    cout<< " " << endl;
                }
                else if (ctr==1) {
                    tempDescription = lineFromFile;
                    ctr++;
                    cout << "The description is: " << tempDescription << endl;
                    cout<< " " << endl;
                }
                else if (ctr==2) {
                    tempLeftEventNumber = stoi(lineFromFile);
                    ctr++;
                    cout << "The left event number is: " << tempLeftEventNumber << endl;
                    cout<< " " << endl;
                }
                else if (ctr==3) {
                    tempRightEventNumber = stoi(lineFromFile);
                    ctr++;
                    cout << "The right event number is: " << tempRightEventNumber << endl;
                    //maybe implement a helper method somewhere to check when stuff is missing from the txt file.
                    cout<< " " << endl;
                    cout<< "The line is currently :" << lineFromFile << endl;
                }
                else {
                    ctr=0;
                }
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