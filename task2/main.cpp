#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool haveSameLetters(const std::string &word1, const std::string &word2)
{
    // Sort the characters in both words
    std::string sortedWord1 = word1;
    std::string sortedWord2 = word2;

    std::sort(sortedWord1.begin(), sortedWord1.end());
    std::sort(sortedWord2.begin(), sortedWord2.end());

    // Compare the sorted words
    return sortedWord1 == sortedWord2;
}

int main(int argc, char *argv[])
{
    if (argc > 1 && std::stoi(argv[1]) == 1)
    {
        // Level 1
        std::string word1, word2;
        std::cout << "Enter two words: ";
        std::cin >> word1 >> word2;

        bool result = haveSameLetters(word1, word2);
        std::cout << (result ? "true" : "false") << std::endl;
    }
    else
    {
        // Level 2
        std::vector<std::string> words;
        std::string word;

        while (std::cin >> word)
        {
            words.push_back(word);
        }

        // generate a map to store groups of words based on their sorted letters
        std::unordered_map<std::string, std::vector<std::string>> wordGroups;

        // Iterate through each word and group them based on sorted letters
        for (const auto &currentWord : words)
        {
            std::string sortedCurrentWord = currentWord;
            std::sort(sortedCurrentWord.begin(), sortedCurrentWord.end());

            wordGroups[sortedCurrentWord].push_back(currentWord);
        }

        // Print the grouped words
        for (const auto &group : wordGroups)
        {
            const std::vector<std::string> &wordsInGroup = group.second;

            // Print the group if there are more than one word
            if (wordsInGroup.size() > 1)
            {
                for (const std::string &wordInGroup : wordsInGroup)
                {
                    std::cout << wordInGroup;
                    if (&wordInGroup != &wordsInGroup.back())
                    {
                        std::cout << ",";
                    }
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
