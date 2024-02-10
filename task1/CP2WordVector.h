#ifndef CP2WORDVECTOR_H
#define CP2WORDVECTOR_H

#include <string>

// Define the WordInfo structure
struct WordInfo
{
    std::string word;
    int counter;
};

// Define the CP2WordVector class
class CP2WordVector
{
public:
    CP2WordVector();

    ~CP2WordVector();

    // Return a pointer
    WordInfo *begin();

    // Return a pointer to the end of the stored items
    WordInfo *end();

    // Insert a new item into the specified position
    void insert(WordInfo *position, const WordInfo &newItem);

    // Return the number of elements stored in the vector
    int getCurrentSize() const;

private:
    static const int capacity = 1000; // Maximum capacity
    WordInfo items[capacity];         // Array to store WordInfo objects
    int size;                         // Number of elements currently stored in the vector
};

#endif
