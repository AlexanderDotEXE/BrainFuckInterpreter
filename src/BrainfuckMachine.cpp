#include <iostream>
#include <cstring> //for strlength

#include "BrainfuckMachine.hpp"
#include "OpcodeDefinitions.h"

bool BrainfuckMachine::isPrintableChar(unsigned char value) {
    char printChar = (char) value;

    // Is char in alphabet
    if ((printChar >= 'A' && printChar <= 'Z') || (printChar >= 'a' && printChar <= 'z')) {
        return true;
    }

    // Characters i could think of that could be usefully outputted.
    char validChars[] = {'!', ' ', '.', ',', '?', '<', '>', '+', '-', '[', ']', '@', '\n', (char) 26}; // (char)26 => End of medium
    for(char c : validChars) {
        if(printChar == c) return true;
    }

    return false;
}

unsigned char BrainfuckMachine::readChar()
{
    char c = '\0';
    std::cin >> std::noskipws >> c; // Important for reading whitespaces
    return static_cast<unsigned char>(c);
}

void BrainfuckMachine::output() {

    // Cast here already so you can call the function with this var already
    const char printChar = (char) this->band.getCurrentBandValue();
    
    if(isPrintableChar(printChar)) {
        std::cout << printChar;
    }else {
        std::cout << this->band.getCurrentBandValue();
    }

}

int BrainfuckMachine::analyzeProgramCode(const char *programCode)
{
    // Clear sets
    this->openingBracesSet.clear();
    this->closingBracesSet.clear();

    int programCodeLength = std::strlen(programCode);
    std::vector<int> braceStack; // Saves the positions of the opening braces '['

    for (int i = 0; i < programCodeLength; i++)
    {
        OperationCodes::BrainfuckOPC operationCode = static_cast<OperationCodes::BrainfuckOPC>(programCode[i]);

        if (operationCode == OperationCodes::LOOP_BEGIN)
        {
            braceStack.push_back(i); // Save position of '['
        }
        else if (operationCode == OperationCodes::LOOP_END)
        {
            if (braceStack.empty())
            {
                std::cerr << "Error: Unmatched ']' at position " << i << std::endl;
                continue;
            }

            // Get last opening brace index
            int openIndex = braceStack.back();
            //Delete it from the 'band'
            braceStack.pop_back();

            // And store it in the sets
            this->openingBracesSet.insert({openIndex, i});
            this->closingBracesSet.insert({i, openIndex});
        }
    }

    // Communicate error if there is an unmatched opening brace
    if (!braceStack.empty())
    {
        std::cerr << "Error: Unmatched '[' at position " << braceStack.back() << std::endl;
    }


    return programCodeLength;
}


void BrainfuckMachine::loopBegin()
{
    // If the current band value is zero
    if (this->band.getCurrentBandValue() == 0)
    {
        // Go to matching ]
        this->programCounter = this->openingBracesSet.at(this->programCounter) + 1;
    }
    // Else if there is no loop index or the last loop index isnt the current index
    else if (loopIndexStack.size() == 0 || loopIndexStack.back() != this->programCounter)
    {
        // Save it to the stack
        loopIndexStack.push_back(this->programCounter);
    }
}

void BrainfuckMachine::loopEnd()
{
    // If the current stack value is zero
    if (this->band.getCurrentBandValue() != 0)
    {
        // Go to matching [
        this->programCounter = this->closingBracesSet.at(this->programCounter);
    }
    else
    {
        // Delete last entry
        this->loopIndexStack.pop_back();
    }
}

void BrainfuckMachine::execute(const char *programCode)
{
    this->programCounter = 0;
 
    //Analyze the Programcode to fill the openingBracesSet and closingBracesSet
    int programmCodeLength = analyzeProgramCode(programCode);

    //Run while there is code to execute
    while (programCounter != programmCodeLength)
    {
        //Store current programcounter to detect later if a jump occured
        int prevCounter = programCounter;
        enum OperationCodes::BrainfuckOPC operationCode = static_cast<OperationCodes::BrainfuckOPC>(programCode[programCounter]);
        switch (operationCode)
        {
        case OperationCodes::LOOP_BEGIN:
            loopBegin();
            break;
        case OperationCodes::LOOP_END:
            loopEnd();
            break;
        case OperationCodes::STACK_LEFT:
            this->band.decreaseIndex();
            break;
        case OperationCodes::STACK_RIGHT:
            this->band.increaseIndex();
            break;
        case OperationCodes::INCREASE_STACK:
            this->band.increaseBandValue();
            break;
        case OperationCodes::DECREASE_STACK:
            this->band.decreaseBandValue();
            break;
        case OperationCodes::OUTPUT:
            output();
            break;
        case OperationCodes::INPUT:
            this->band.setCurrentBandValue((unsigned char)readChar());
            break;
        default:
            std::cout << programCode[programCounter] << " is not a valid Brainfuck instruction! " << std::endl;
            break;
        }

        if(prevCounter == programCounter) {
            programCounter++;
        }
    }
    // Else there is a % at the end of the line...
    std::cout << std::endl;
}

//Initialize the brainfuckmachine with a Bandsize of 2048
BrainfuckMachine::BrainfuckMachine()
    : band(2048)
{
}

BrainfuckMachine::~BrainfuckMachine()
{
}
