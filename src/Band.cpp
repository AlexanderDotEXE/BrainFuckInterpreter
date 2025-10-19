#include "Band.hpp"
#include <iostream>
 

void Band::decreaseBandValue()
{
    this->band[bandIndex]--;
}


void Band::increaseBandValue()
{
    this->band[bandIndex]++;
}


unsigned char Band::getCurrentBandValue()
{
    return this->band[bandIndex];
}


void Band::setCurrentBandValue(unsigned char value)
{
    this->band[bandIndex] = value;
}


void Band::increaseIndex()
{
    this->bandIndex++;

    //Wrap around if the index is higher than the bandsize
    if (this->bandIndex >= bandSize)
    {
        this->bandIndex = 0;
    }
}


void Band::decreaseIndex()
{
    this->bandIndex--;

    //Wrap around if the index would be negative
    if (bandIndex < 0)
    {
        this->bandIndex = bandSize - 1;
    }
}


Band::Band(int bandSize)
{
    this->bandSize = bandSize;
    this->bandIndex = 0;
    this->band = (unsigned char *)malloc(sizeof(unsigned char) * bandSize);

    // Initialize all cells to zero
    for (int i = 0; i < bandSize; i++)
    {
        this->band[i] = 0;
    }
}


Band::~Band()
{
    //Free allocated Memory for band array
    free(this->band);
}
