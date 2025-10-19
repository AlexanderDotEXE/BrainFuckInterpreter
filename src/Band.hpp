#pragma once
#ifndef Band_HPP
#define Band_HPP

/**
 * @author Alexander Gorka
 * @class  Band
 * @brief  Represents a cyclic memory band (similar to a Brainfuck memory tape).
 *
 * The Band class provides an array of unsigned char values ("cells")
 * and an index that moves forward and backward through them.
 * The index wraps around when it reaches either end.
 */
class Band
{
private:
    /**
     * Used to store the current index of the band
     */
    int bandIndex;

    /**
     * Pointer to the array of unsigned chars (band)
     * Size is determent by this->bandSize
     */
    unsigned char *band;

    /**
     * Size of the band (band array) used
     */
    int bandSize;

public:
    /**
     * @brief Constructs a Band object with a specified size.
     *
     * Initializes all band cells to zero and sets the current index to 0.
     *
     * @param bandSize The number of cells in the band.
     */
    Band(int bandSize);

    /**
     * @brief Destructor for the Band class.
     *
     * Frees the dynamically allocated memory used for the band.
     */
    ~Band();

    /**
     * @brief Moves the band index one position forward.
     *
     * If the index exceeds the band size, it wraps around to 0.
     * Corresponds to the '>' keyword
     */
    void increaseIndex();

    /**
     * @brief Moves the band index one position backward.
     *
     * If the index goes below 0, it wraps around to the last position (bandSize - 1).
     * Corresponds to the '<' keyword
     */
    void decreaseIndex();

    /**
     * @brief Increases the value at the current band index by 1.
     *
     * No bounds checking is performed; if the value is 255, it will wrap around to 0
     * because the band stores values as unsigned chars.
     * Corresponds to the '+' keyword
     */
    void increaseBandValue();

    /**
     * @brief Decreases the value at the current band index by 1.
     *
     * No bounds checking is performed; if the value is 0, it will wrap around to 255
     * because the band stores values as unsigned chars.
     * Corresponds to the '-' keyword
     */
    void decreaseBandValue();

    /**
     * @brief Sets the value at the current band index.
     * Used for the ',' keyword
     * @param value The unsigned char value to set.
     */
    void setCurrentBandValue(unsigned char value);

    /**
     * @brief Returns the value at the current band index.
     *
     * @return The current unsigned char value at the band index.
     */
    unsigned char getCurrentBandValue();
};

#endif