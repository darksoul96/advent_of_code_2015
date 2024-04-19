
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Pos {
    int x;
    int y;
    Pos(int x, int y) : x(x), y(y){}
};

// Custom hash function for Pos
struct PosHash {
    std::size_t operator()(const Pos& p) const {
        // Simple hash combining x and y
        return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
    }
};

// Custom equality comparison for Pos
struct PosEqual {
    bool operator()(const Pos& lhs, const Pos& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

int presentsPart1(string line) {
    unordered_map<Pos, int, PosHash, PosEqual> visitedHouses;
    Pos currentPosition = Pos(5000,5000);
    visitedHouses[currentPosition] = 1;

    for (char c:line) {
        switch(c) {
            case '<':
                currentPosition.x -= 1;
                break;
            case '>':
                currentPosition.x += 1;
                break;
            case '^':
                currentPosition.y += 1;
                break;
            case 'v':
                currentPosition.y -= 1;
                break;
        }
        if (visitedHouses.find(currentPosition) != visitedHouses.end()) {
            visitedHouses[currentPosition]++;
        } else
            visitedHouses[currentPosition] = 1;
    }
    return visitedHouses.size();
}

int presentsPart2(string line) {
    unordered_map<Pos, int, PosHash, PosEqual> visitedHousesSanta;
    Pos currentPositionSanta = Pos(5000,5000);
    Pos currentPositionRoboSanta = Pos(5000,5000);
    visitedHousesSanta[currentPositionSanta] = 1;
    int i=0;
    while (i<line.size()) {
        if (i%2 == 0) {
            switch(line[i]) {
                case '<':
                    currentPositionSanta.x -= 1;
                    break;
                case '>':
                    currentPositionSanta.x += 1;
                    break;
                case '^':
                    currentPositionSanta.y += 1;
                    break;
                case 'v':
                    currentPositionSanta.y -= 1;
                    break;
            }
            if (visitedHousesSanta.find(currentPositionSanta) != visitedHousesSanta.end()) {
                visitedHousesSanta[currentPositionSanta]++;
            } else {
                visitedHousesSanta[currentPositionSanta] = 1;
            }
        } else {
            switch(line[i]) {
                case '<':
                    currentPositionRoboSanta.x -= 1;
                    break;
                case '>':
                    currentPositionRoboSanta.x += 1;
                    break;
                case '^':
                    currentPositionRoboSanta.y += 1;
                    break;
                case 'v':
                    currentPositionRoboSanta.y -= 1;
                    break;
            }
            if (visitedHousesSanta.find(currentPositionRoboSanta) != visitedHousesSanta.end()) {
                visitedHousesSanta[currentPositionRoboSanta]++;
            } else {
                visitedHousesSanta[currentPositionRoboSanta] = 1;
            }
        }
        i++;
    }
    return visitedHousesSanta.size();
}

void readHouses(int &countPresentsInHouses, int &countPresentsRoboSanta) {
    
    ifstream inputFile("../input.txt");
    string line;
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            getline(inputFile, line);
        }
    }
    countPresentsInHouses = presentsPart1(line);
    countPresentsRoboSanta = presentsPart2(line);
}


int main(int argc, char const *argv[])
{
    int countPresentsInHouses, countPresentsRoboSanta;
    readHouses(countPresentsInHouses, countPresentsRoboSanta);
    cout << countPresentsInHouses << "\n";
    cout << countPresentsRoboSanta << "\n";
    return 0;
}
