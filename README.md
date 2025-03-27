[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Ethan Truong`  
### **Student ID:** `131855344`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

- In this project, all information is taken in from the story.txt file. Within each file line is an event number, description, left node event number, and a right node event number. All this information gets represented as a node where each node has a story and a pointer to the left and right nodes. When there is no additional node to the left or right (event numbers being -1), that means the current node is a leaf node. The construction of all the nodes means the game forms a binary decision tree. When the user plays the game, the root node’s description is broadcasted in the console and they are given the option to progress to the left node by typing 1 or the right node by typing 2. The user gets to traverse the entire decision tree of events until a leaf node is reached where a message will appear “You have reached the end of the path.”

- Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function]`  
- **`GameDecisionTree.h`** → `[Explain what this file contains]`  
- **`Node.h`** → `[Explain what this file contains]`  
- **`Story.h`** → `[Explain what this file contains]`  
- **`story.txt`** → `[Explain how the game loads story events from this file]`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

- When I was trying to extract the information from the text file, I kept on encountering an "exit code error 134 (interrupted by signal 6:SIGABRT)." To solve this, I made an if statement to account for when tempCharFromFile was the delimiter or when a new line is encountered so that it does not add that char to the end of my temp string, textReadFromFileSoFar. The exclusion of delimiter and new line meant that I was able correctly convert the string into the ints for event, left, and right numbers.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n) assuming that n is the number of char in the text file`  
- **Searching for an event in the tree** → `O(n) since it is unsorted`  
- **Game traversal efficiency** → `O(logn) because the game traverses going left or right per maneuver`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
