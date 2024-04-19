
/*
    Santa has to mine AdventCoins
    Find MD5 hashes which start with 5 zeroes in hex

    Find lowest positive number that produces such a hash

*/
#include "hash-library-master/md5.h"
#include <iostream> 
#include <string>

std::string findSecretKey(std::string input) {
    std::string result;
    MD5 md5;
    int number = 1;
    bool found = false;

    while (number <= INT32_MAX && !found) {
        result = input + std::to_string(number);
        std::string generated_hash = md5(result);
        if (generated_hash.substr(0, 6) == "000000")
            found = true;
        else {
            number++;
        }
    }

    if (found)
        return result;

    return "not found";
}

int main(int argc, char const *argv[]) {
    std::string input = "yzbqklnj", result;
    
    result = findSecretKey(input);
    std::cout << result << "\n";

    return 0;
}
