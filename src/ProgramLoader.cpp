#include "ProgramLoader.h"

std::string ProgramLoader::loadProgramFromFile(const char *filePath)
{
    using namespace std;

    string programCode;
    string line;
    ifstream file(filePath);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file '" << filePath << "'." << endl;
        return "";
    }

    while (getline(file, line))
    {
        line = cleanCode(line);
        programCode += line;
    }

    return programCode;
}

std::string ProgramLoader::cleanCode(std::string line)
{
    using namespace OperationCodes;

    // Ignore comment lines starting with ";;"
    if (line.length() >= 2 && line.at(0) == ';' && line.at(1) == ';')
    {
        return "";
    }

    // Filter valid Brainfuck operation codes
    std::string cleanedCode;
    for (char opCode : line)
    {
        switch (opCode)
        {
        case STACK_LEFT:
        case STACK_RIGHT:
        case INCREASE_STACK:
        case DECREASE_STACK:
        case OUTPUT:
        case INPUT:
        case LOOP_BEGIN:
        case LOOP_END:
            cleanedCode += opCode;
            break;
        default:
            break;
        }
    }

    return cleanedCode;
}