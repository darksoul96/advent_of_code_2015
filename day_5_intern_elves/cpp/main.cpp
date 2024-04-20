
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>


int countVowels(std::string line) {
    
    // for (char c : line) {
    //     if (vowels.find(c) != std::string::npos) {
    //         number_of_vowels++;
    //     }
    // }
    auto is_vowel = [] (char a) {
        std::string vowels = {"aeiou"};
        return vowels.find(a) != std::string::npos;
    };
    return std::count_if(line.begin(), line.end(), is_vowel);
}


bool letterAppearsTwiceInARow(std::string line) {
    return std::adjacent_find(line.begin(), line.end()) != line.end();
}

bool containsBannedStrings(std::string line) {
    std::vector<std::string> banned_strings = {"ab","cd","pq","xy"};
    for (std::string s:banned_strings) {
        if (line.find(s) != std::string::npos) {
            return true;
        }
    }

    return false;
}


bool isNice(std::string line) {
    bool nice = true;
    if (countVowels(line) <3)
        return false;
    
    if (!letterAppearsTwiceInARow(line))    
        return false;

    if (containsBannedStrings(line))
        return false;

    return nice;
}

int countNiceFileStrings() {
    std::ifstream file("../input.txt");
    std::string line;
    int count_nice_lines = 0;
    if (file.is_open()) {
        while (!file.eof()) {
            std::getline(file, line);
            if (isNice(line)) {
                count_nice_lines++;
            }
        }
    }

    return count_nice_lines;
}

int main(int argc, char const *argv[]) {
    int nice_strings = countNiceFileStrings();
    
    std::cout << nice_strings << "\n";
    return 0;
}
