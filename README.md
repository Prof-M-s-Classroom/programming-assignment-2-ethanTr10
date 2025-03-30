[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Ethan Truong`  
### **Student ID:** `131855344`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

- In this project, all information is taken in from the story.txt file. Within each file line is an event number, description, left node event number, and a right node event number. All this information gets represented as a node where each node has a story and a pointer to the left and right nodes. When there is no additional node to the left or right (event numbers both being -1), that means the current node is a leaf node. The construction of all the nodes means the game forms a binary decision tree. When the user first starts the game, the root node’s description is broadcast in the console, and they are given the option to progress to the left node by typing 1 or the right node by typing 2. The user gets to traverse the entire decision tree of events until a leaf node is reached where a message will appear “You have reached the end of the path.”

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `This file is in charge of creating a GameDecisionTree of type Story. It clarifies that the input file is called story.txt and sets the delimiter of choice to be |. Then loadStoryFromFile is called with the file name and char for delimiter to construct the tree and then playGame() is called for the user to interact with the different paths of the tree.`  
- **`GameDecisionTree.h`** → `Contains the constructor GameDecisionTree() where root is assigned to nullptr, loadStoryFromFile() method with input parameters of the filename and delimiter of choice to construct the binary tree, and playGame() method which starts traversing the tree depending on how the user chooses their path.`  
- **`Node.h`** → `Contains the constructor of a node which takes in and assigns the instance variables for a generic T data type and pointers to the left and right nodes.`  
- **`Story.h`** → `Contains the default constructor Story() and parameterized constructor Story(string desc, int num, int leftNum, int rightNum) to assign to the instance variables description, eventNumber, leftEventNumber, and rightEventNumber.  `  
- **`story.txt`** → `Each line in the file contains an event represented by eventNumber | description | leftChildEventNumber | rightChildEventNumber. The game loads the story through the use of fstream and checking if the file has been opened properly. If so, the story.txt is read char by char to find delimiters and new lines. When either is approached, temporary description, event number, left event number, and right event number variables get assigned to them and then a new story is created when is then input into the parameterized constructor to constuct a node. The nodes get stored in a vector due to its dynamic sizing and after reading all lines of the text file, the nodes get assigned to the proper left and right pointers.`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file? After checking if the fstream object has opened successfully, a while loop is used to read every char of every line in the text file. There is a variable called tempCharFromFile which reads each individual char and gets added to the end of the string variable textReadFromFileSoFar when there is no delimiter or new line. When a delimiter is encountered, the textReadFromFile is converted to an int if the position of the text is indicative of any event number and then assigned to a temporary variable counterpart of event number, left event, and right event numbers. If it is not for an event number, then the temporary variable counterpart of description is assigned to textReadFromFileSoFar. After the assignments, then textReadFromFileFar gets assigned back to a blank string. Reaching a new line means the end of an event so a parameterized Story constructor is used with the temporary variable counterparts from earlier to description, tempEventNumber, tempLeftEventNumber, and tempRightEventNumber as the inputs. Then a new Node is created with that Story and added to a vector called binaryTree which stores all the event nodes and the file closes after constructing all nodes. 
- How are nodes linked based on left and right event numbers? A vector called binaryTree stores all the created event nodes. Each index is visited using a for loop where each node's data is accessed (a Story) and then the left and right event numbers based on the Story data. With those left and right event numbers, the temp node's left and right node pointers then get assigned to the node at binaryTree's index of left/right event number-1. Must include the subtraction of 1 because the vector stores nodes one index lower than the event number.   
- What happens if an event has `-1` as left or right children? Since the if statements ensure that the left and right event numbers are not -1, they will not execute if a -1 is encountered. Since the content inside the if-statements will not occur, the node's left or right child will not be linked to another node given that the constructor of a node assigns left and right to be nullptr at first.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken? A while loop is used to check if the current node being visited referenced as temp Node pointer is not a nullptr. If it is not a nullptr, I prompt the user to enter a 1 or 2 to go left or right. I use the cin function which assigns the input to int tempInput. If tempInput is 1, then the Node pointer temp gets assigned to the left of temp. If tempInput is 2, then the Node pointer temp gets assigned to the right of temp. The while loop then executes again printing out temp's new description and performs then asks for input again if it is not a leaf node.
- What happens when the player reaches a leaf node?  There is an if statement when the temporary node pointer's left and right pointers are both nullptr. When that statement is reached for a leaf node, then the game is over and breaks out of the while loop.
- Explain the special case where multiple events lead to the same outcome. The special case is event 9 "You try your best to keep the cat warm, give it lots of water and decide to keep the kitty until at least tomorrow. The cat starts to purr a ton and ends up climbing into bed to snuggle." since the right child of event 4 points to 9 and the left child of event 5 points to 9. 

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter? I read each file line char by char using a while loop where each char is assigned to tempCharFromFile. If the char is not the delimiter nor a new line, then the char is pushed back to another string called textReadFromFileSoFar which keeps track of things read so far prior to a delimiter. When a delimiter has been reached, delimiterCtr gets incremented by one, and I then assign it to the correct temporary instance variable based on the delimiterCtr value and if-statement. The first section of text before a delimiter is reached is the eventNumber (ctr==1), second section is the description (ctr==3), third section is the leftEventNumber (ctr==5), and fourth section is rightEventNumber (ctr==7). Therefore, I increment the delimiterCtr by one every time a delimiter is encountered and convert the string to an int when getting event numbers. After I assign the information from the txt file to the temporary instance variable keeping track of the story instance variables, textReadFromFileSoFar is set to be "" to clear out information for the next reading then increment delimiterCtr by one again so that delimiterCtr is in between the edge cases of 1,3,5, and 7 to avoid the code from running the assignments of incorrect information.  When a delimiter is reached again, then delimiterCtr increments to assign the value. When a new line is reached, that particularly indicates rightEventNumber and concludes that one particular event.
- How do you ensure nodes are properly linked? A for-loop is used to peruse through all the event nodes in the vector binaryTree and gets linked the correct left and right event numbers. For each node of study which is assigned to temp, an if statement is used to check if tempLeftEventNumber-1 >=0 to ensure the index (tempLeftEventNumber-1) of access at the vector is not negative and makes sure tempLeftEventNumber is not -1 which would be nullptr, and if tempLeftEventNumber-1 <binaryTree.size() to prevent the node linkage to an event that does not exist since there would be no index with that node. If all those statements are true, then the temp node's left pointer is assigned to the node pointer within the vector binaryTree at the index of tempLeftEventNumber-1 because the vector stores the node one index less than its event number. To account for the right pointer, the same exact if statement and execution occurs as mentioned, but for tempRightEventNumber and temp's right pointer instead of tempLeftEventNumber and temp's left pointer. When the conditions of the if statement are not met, then the node at study does not alter in its left/right children pointers, staying at the default nullptr during node construction since there is no valid event node as the child. 
- Any challenges faced while handling file input?  I faced the issue of the IDE not being able to read/find the file. I was able to fix that issue by moving the story.txt file to the cmake-build-debug folder since the creation of txt files through the code would put it there.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

- When I was trying to extract the information from the text file, I kept on encountering an "exit code error 134 (interrupted by signal 6:SIGABRT)." To solve this, I made an if statement to account for when tempCharFromFile was the delimiter or when a new line is encountered so that it does not add that char to the end of my temp string, textReadFromFileSoFar. The exclusion of delimiter and new line meant that I was able correctly convert the string into the ints for event, left, and right numbers which solved the error code from popping up again.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

You see a collar-less cat lurking while on a walk around the neighborhood late at night. Do you:
1. Swoop up the cat and take it home. (Go left)
2. Leave it and go home. You go on a walk with different path and cat comes running up to you and starts rubbing against you showing affection. (Go right)
   Enter choice (1 for left, 2 for right): 1
   You chose: 1

Swoop up the cat and take it home. Do you:
1. Feed the cat some left-over chicken. (Go left)
2. Bother your cat-lover friend at 11pm to drop off some food. They mention how they could take care of the cat if you do not prefer to. (Go right)
   Enter choice (1 for left, 2 for right): 2
   You chose: 2

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n) assuming that n is the number of char in the text file and loading requires the visitation of every char in the txt file`  
- **Searching for an event in the tree** → `O(logn) because the tree traverses going left or right per maneuver to search`  
- **Game traversal efficiency** → `O(logn) because the game traverses going left or right per maneuver`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

- One edge case I tested is if the file could not be open. I created a fstream object called readingFile which I then call readingFile.open(filename) to try and open the file of the filename specified. I then do if(readingFile) which returns true if the txt was found and opened. If not, then the else section executes saying how the "File could not be found". In addition, I tested for when a leaf node is reached when the game is played. If a node's left and right pointers are nullptr, then I output how they have reached the end of the path. 

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

- I added a feature where it provides players the option to play the game again once they reach a leaf node. If a leaf node is reached, then I make use of cin which assigns tempInput a value of 1 or 2. If the player inputs 1, they want to play again so I assign temp to be root again and tempInput to be 0. If player inputs 2, they do not want to play again so it break out of the while loop, indicating the complete end of game. I got inspired to do this since I did not want to have to press the play button everytime I wanted to test different paths. 

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
