#pragma once
#ifndef BRAINFUCK_MACHINE_HPP
#define BRAINFUCK_MACHINE_HPP

#include "Band.hpp"
#include <iostream>
#include <map>
#include <vector>

/**
 * @author Alexander Gorka
 * @class BrainfuckMachine
 * @brief Core interpreter for executing Brainfuck programs.
 *
 * The BrainfuckMachine class implements the logic required to
 * interpret and execute Brainfuck source code. It maintains an
 * internal memory tape (Band), manages program flow, handles
 * loops, input/output, and tracks the current execution position.
 *
 * This class preprocesses the Brainfuck program to build fast
 * lookup tables for matching brackets, enabling efficient loop
 * execution.
 */
class BrainfuckMachine
{
private:
    /**
     * @brief Tracks the current position in the Brainfuck program.
     *
     * Represents the index of the instruction currently being executed.
     */
    int programCounter = 0;

    /**
     * @brief Memory tape used by the Brainfuck program.
     *
     * The Band instance represents the program's working memory,
     * where each cell can be incremented, decremented, read, or written.
     */
    Band band;

    /**
     * @brief Maps the index of an opening bracket '[' to its matching closing bracket ']'.
     *
     * This lookup table is precomputed by analyzeProgramCode() to
     * speed up loop jumps during execution.
     */
    std::map<int, int> closingBracesSet;

    /**
     * @brief Maps the index of a closing bracket ']' to its matching opening bracket '['.
     *
     * Used to efficiently jump backward in loops during program execution.
     */
    std::map<int, int> openingBracesSet;

    /**
     * @brief Stack used to manage nested loops.
     *
     * Each time a loop begins ('['), its index is pushed onto the stack.
     * When a loop ends (']'), the last entry is popped. This helps track
     * currently active or nested loops during analysis or execution.
     */
    std::vector<int> loopIndexStack;

    /**
     * @brief Handles logic when encountering the '[' instruction.
     *
     * If the current cell value is zero, execution jumps to the instruction
     * immediately after the corresponding ']'. Otherwise, the loop continues.
     */
    void loopBegin();

    /**
     * @brief Handles logic when encountering the ']' instruction.
     *
     * If the current cell value is nonzero, execution jumps back to the
     * corresponding '[' instruction, repeating the loop.
     */
    void loopEnd();

    /**
     * @brief Checks if a given unsigned char value is printable.
     *
     * Determines whether the byte should be output as a character or
     * represented numerically.
     *
     * @param value The byte to check.
     * @return True if the value is a printable ASCII character, false otherwise.
     */
    bool isPrintableChar(unsigned char value);

    /**
     * @brief Outputs the value of the current memory cell.
     *
     * If the value is printable (as determined by isPrintableChar()),
     * it is displayed as a character. Otherwise, it is printed as its
     * numeric value.
     */
    void output();

    /**
     * @brief Preprocesses the program code before execution.
     *
     * Builds the @ref openingBracesSet and @ref closingBracesSet lookup maps,
     * allowing for efficient bracket matching during runtime.
     *
     * @param programCode Pointer to the Brainfuck source code.
     * @return The total number of instructions processed.
     */
    int analyzeProgramCode(const char* programCode);

    /**
     * @brief Reads a single character from standard input.
     *
     * Used for the ',' Brainfuck command. Returns the ASCII value
     * of the entered character.
     *
     * @return The character read from input as an unsigned char.
     */
    unsigned char readChar();

public:
    /**
     * @brief Default constructor.
     */
    BrainfuckMachine();

    /**
     * @brief Destructor.
     */
    ~BrainfuckMachine();

    /**
     * @brief Executes a Brainfuck program.
     *
     * Takes the Brainfuck source code as input, analyzes it,
     * and sequentially executes its instructions.
     *
     * @param programCode Pointer to the Brainfuck source code (null-terminated C-string).
     */
    void execute(const char* programCode);
};

#endif // BRAINFUCK_MACHINE_HPP
