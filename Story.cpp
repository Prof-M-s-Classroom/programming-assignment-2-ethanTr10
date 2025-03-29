#include "Story.h"

//Default constructor
Story::Story() : description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {}

//Non-default constructor with specific inputs of a string description, event number, left event number and right event
//number and assigns them to the instance variables description, eventNumber, leftEventNumber, and rightEventNumber
Story::Story(std::string desc, int num, int leftNum, int rightNum)
        : description(desc), eventNumber(num), leftEventNumber(leftNum), rightEventNumber(rightNum) {}