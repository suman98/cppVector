#include "./CP2WordVector.h"

// Constructor
CP2WordVector::CP2WordVector() : size(0)
{
    // Initialize the array with WordInfo objects
    for (int i = 0; i < capacity; ++i)
    {
        items[i] = WordInfo();
    }
}

CP2WordVector::~CP2WordVector() {}

// Return a pointer to the start of the array
WordInfo *CP2WordVector::begin()
{
    return items;
}

// Return a pointer to the end of the stored items
WordInfo *CP2WordVector::end()
{
    return items + size;
}

// Insert a new item
void CP2WordVector::insert(WordInfo *position, const WordInfo &newItem)
{
    // Move elements to make space for the new item
    for (WordInfo *i = end(); i > position; --i)
    {
        *i = *(i - 1);
    }

    *position = newItem;
    ++this->size; // Increment the size
}

// Return the number of elements stored in the vector
int CP2WordVector::getCurrentSize() const
{
    return size;
}
