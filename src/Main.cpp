/**
 * @file main.cpp
 * @brief Entry point for the Brainfuck interpreter.
 *
 * Loads and executes a Brainfuck program from a specified file.
 *
 * Usage:
 * @code
 * ./BrainfuckInterpreter --file <path_to_program.bf>
 * @endcode
 *
 * Exits with:
 * - 0: Successful execution
 * - 1: Missing or invalid arguments
 * - 2: File could not be loaded
 *
 * Author: Alexander Gorka
 */

#include "BrainfuckMachine.hpp"
#include "ProgramLoader.h"

#include <iostream>
#include <optional>
#include <string>

/**
 * @brief Parses command-line arguments and extracts the Brainfuck file path.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return The file path if provided, otherwise std::nullopt.
 */
std::optional<std::string> parseArguments(int argc, const char* argv[])
{
    for (int i = 1; i < argc - 1; ++i) {
        std::string arg = argv[i];
        if (arg == "--file") {
            return std::string(argv[i + 1]);
        }
    }
    return std::nullopt;
}

/**
 * @brief Displays a short usage message.
 */
void printUsage()
{
    std::cout << "Usage: BrainfuckInterpreter --file <path_to_program.bf>\n";
}

/**
 * @brief Main entry point.
 */
int main(int argc, const char* argv[])
{
    if (argc < 3) {
        std::cerr << "Error: Missing arguments.\n";
        printUsage();
        return 1;
    }

    auto filePath = parseArguments(argc, argv);
    if (!filePath) {
        std::cerr << "Error: No valid '--file' argument found.\n";
        printUsage();
        return 1;
    }

    std::cout << "Loading Brainfuck program from: " << *filePath << std::endl;
    std::string brainfuckProgram = ProgramLoader::loadProgramFromFile(filePath->c_str());

    if (brainfuckProgram.empty()) {
        std::cerr << "Error: Could not read or load the specified file.\n";
        return 2;
    }

    BrainfuckMachine machine;
    std::cout << "Executing program...\n";
    machine.execute(brainfuckProgram.c_str());
    std::cout << "\nExecution finished successfully.\n";

    return 0;
}
