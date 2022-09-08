#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string filename("input.txt");
    ifstream inputFile(filename);
    int x, y, d, aim;
    x = y = aim = d = 0;
    string c;
    while(inputFile >> c){
        inputFile >> d;
        if (c == "forward"){
            x = x + d;
            y = y + aim * d;}
        if (c == "down")
            aim = aim + d;
        if (c == "up")
            aim = aim - d;
    }

    cout << x * y;
}