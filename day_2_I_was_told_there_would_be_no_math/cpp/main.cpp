/*
    Box dimensions
    length, width, height

    Every present is a box -> Area = 2*l*w + 2*w*h + 2*h*l
    Extra paper = Area of smallest side
*/

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void getIntValues(string line, int& length, int& width, int& height) {
    int beginIndex = 0, endIndex;
    endIndex = line.find('x');
    length = stoi(line.substr(beginIndex, endIndex));
    line.erase(beginIndex, endIndex+1);
    endIndex = line.find('x');
    width = stoi(line.substr(beginIndex, endIndex));
    line.erase(beginIndex, endIndex+1);
    height = stoi(line);
}

int calculateBoxArea(int length, int width, int height) {
    int areaSide = length*width;
    int areaFront = width*height;
    int areaTop = height*length;
    return 2*areaSide + 2*areaFront + 2*areaTop + min(areaTop, min(areaFront, areaSide));
}

int calculateSmallestPerimeter(int length, int width, int height) {
    int sidePerimeter = 2*length + 2*width;
    int frontPerimeter = 2*width + 2*height;
    int topPerimeter = 2*height + 2*length;
    return min(min(sidePerimeter, frontPerimeter),topPerimeter);
}

void wrapperAndRibbons(int &feetOfPaper, int &ribbonLength) {
    string line;
    int length, width, height, totalArea = 0, feetOfRibbon = 0;
    ifstream inputFile("../input.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            getline(inputFile, line);
            if (!line.empty()) {
                getIntValues(line, length, width, height);
                totalArea += calculateBoxArea(length, width, height);
                feetOfRibbon += calculateSmallestPerimeter(length, width, height) + length*width*height;
            }
        }
    }
    feetOfPaper = totalArea;
    ribbonLength = feetOfRibbon;
}

int main(int argc, char const *argv[])
{   
    int feetOfPaper, ribbonLength;
    wrapperAndRibbons(feetOfPaper, ribbonLength);
    cout << "Total Area: " << feetOfPaper << "\n";
    cout << "Total Ribbon Length: " << ribbonLength << "\n";
    return 0;
}
