#include "./CP2WordVector.h"
#include <iostream>
#include <algorithm>
#include <iterator>

// Level 1 function
void level1()
{
    CP2WordVector wordVector;

    printf("Enter words (press Ctrl + Z on Windows or Ctrl + D on Unix-like systems to finish):\n");

    // Read words from standard input and insert them into the vector
    std::string word;
    while (std::cin >> word)
    {
        WordInfo newWordInfo;
        newWordInfo.word = word;
        newWordInfo.counter = 1;

        wordVector.insert(wordVector.end(), newWordInfo);
    }

    // Print the contents
    for (WordInfo *it = wordVector.begin(); it != wordVector.end(); ++it)
    {
        printf("%s: %d\n", it->word.c_str(), it->counter);
    }

    printf("Total entries: %d\n", wordVector.getCurrentSize());
}

// Level 2 function
void level2()
{
    CP2WordVector wordVector;

    printf("Enter words (press Ctrl + Z on Windows or Ctrl + D on Unix-like systems to finish):\n");

    // Read words from standard input and insert them into the vector
    std::string word;
    while (std::cin >> word)
    {
        // Check if the word is already in the vector
        auto it = std::find_if(wordVector.begin(), wordVector.end(),
                               [&word](const WordInfo &wi)
                               { return wi.word == word; });

        if (it != wordVector.end())
        {
            // increment its counter if the word is already in vector
            it->counter++;
        }
        else
        {
            // insert it with counter set to 1 if the word is not in vector
            WordInfo newWordInfo;
            newWordInfo.word = word;
            newWordInfo.counter = 1;
            wordVector.insert(wordVector.end(), newWordInfo);
        }
    }

    // Print the contents of the vector
    for (WordInfo *it = wordVector.begin(); it != wordVector.end(); ++it)
    {
        printf("%s: %d\n", it->word.c_str(), it->counter);
    }

    printf("Total entries: %d\n", wordVector.getCurrentSize());
}

// Level 3 function
void level3()
{
    CP2WordVector wordVector;

    printf("Enter words (press Ctrl + Z on Windows or Ctrl + D on Unix-like systems to finish):\n");

    // Read words from standard input and insert them into the vector
    std::string word;
    while (std::cin >> word)
    {
        // Check if the word is already in the vector
        auto it = std::find_if(wordVector.begin(), wordVector.end(),
                               [&word](const WordInfo &wi)
                               { return wi.word == word; });

        if (it != wordVector.end())
        {
            // increment its counter if the word is already in vector
            it->counter++;
        }
        else
        {
            // find right position to insert alphabetically
            auto insertPosition = std::lower_bound(wordVector.begin(), wordVector.end(), word,
                                                   [](const WordInfo &wi, const std::string &w)
                                                   {
                                                       return wi.word < w;
                                                   });

            WordInfo newWordInfo;
            newWordInfo.word = word;
            newWordInfo.counter = 1;
            wordVector.insert(insertPosition, newWordInfo);
        }
    }

    // Print the contents of the vector
    for (WordInfo *it = wordVector.begin(); it != wordVector.end(); ++it)
    {
        printf("%s: %d\n", it->word.c_str(), it->counter);
    }

    printf("Total entries: %d\n", wordVector.getCurrentSize());
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <level>\n", argv[0]);
        return 1;
    }

    int level = std::stoi(argv[1]);

    switch (level)
    {
    case 1:
        level1();
        break;
    case 2:
        level2();
        break;
    case 3:
        level3();
        break;
    default:
        printf("Invalid level\n");
        break;
    }

    return 0;
}
