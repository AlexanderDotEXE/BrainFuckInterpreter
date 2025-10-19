#pragma once
#ifndef PROGRAM_LOADER_H
#define PROGRAM_LOADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "OpcodeDefinitions.h"

/**
 * @author Alexander Gorka
 * @file   ProgramLoader.h
 * @brief  Provides functionality for loading and cleaning Brainfuck source files.
 *
 * The ProgramLoader namespace contains simple utilities for reading Brainfuck
 * code from a text file, stripping out invalid characters and comments, and
 * returning a clean version suitable for execution by the BrainfuckMachine.
 *
 * It ensures that only valid Brainfuck operation symbols remain in the output
 * string. Lines starting with ";;" are treated as comments and ignored.
 *
 * @note
 * The cleaning logic is based on operation definitions from @ref OperationCodes.
 *
 * Example:
 * @code
 * std::string code = ProgramLoader::loadProgramFromFile("hello_world.bf");
 * BrainfuckMachine machine;
 * machine.execute(code.c_str());
 * @endcode
 */
namespace ProgramLoader
{
    /**
     * @brief Removes all non-Brainfuck symbols from a given line of text.
     *
     * This function filters out any character that is not part of the Brainfuck
     * instruction set defined in @ref OperationCodes. It also removes comment
     * lines that begin with ";;".
     *
     * Valid Brainfuck operation symbols are:
     * - `>` Move the data pointer to the right  
     * - `<` Move the data pointer to the left  
     * - `+` Increment the value at the current cell  
     * - `-` Decrement the value at the current cell  
     * - `.` Output the current cell's value  
     * - `,` Read a byte from input into the current cell  
     * - `[` Jump past the matching `]` if the current cell is zero  
     * - `]` Jump back to the matching `[` if the current cell is nonzero  
     *
     * @param line A single line of raw Brainfuck source code.
     * @return A cleaned string containing only valid Brainfuck operation symbols.
     */
    std::string cleanCode(std::string line);

    /**
     * @brief Loads and cleans a Brainfuck program from a file.
     *
     * Opens the specified file, reads it line by line, and cleans each line
     * using @ref cleanCode() to remove comments and non-operation symbols.
     * The resulting Brainfuck source code is returned as a single string.
     *
     * @param filePath Path to the Brainfuck source file.
     * @return The cleaned Brainfuck program code as a string.
     *
     * @warning
     * If the file cannot be opened, the returned string will be empty.
     */
    std::string loadProgramFromFile(const char* filePath);
} // namespace ProgramLoader

#endif // PROGRAM_LOADER_H
