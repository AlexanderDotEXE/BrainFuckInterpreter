#ifndef OPCODES_H
#define OPCODES_H

namespace OperationCodes
{
    /**
     * @author Alexander Gorka
     * @brief Enum with all valid brainfuck OpCodes
     * 
     * Enum with all brainfuck Operation Codes
     * and the corrosponding char values
     */
    enum BrainfuckOPC
    {
        STACK_LEFT = '<',
        STACK_RIGHT = '>',
        INCREASE_STACK = '+',
        DECREASE_STACK = '-',
        OUTPUT = '.',
        INPUT = ',',
        LOOP_BEGIN = '[',
        LOOP_END = ']'
    };
} // namespace OperationCodes

#endif