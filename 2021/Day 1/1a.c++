#include<fstream>
#include<iostream>
#include<list>

using namespace std;

int main() {
    string filename("1input.txt");
    ifstream inputFile(filename);
    int a,b,c,d, sum1, sum2;
    d = -1;
    sum2 = 0;
    inputFile >> a;
    inputFile >> b;
    while (inputFile >> c)
       {sum1 = a + b + c;
        if (sum1 > sum2)
            d++;
       a = b;
       b = c;
       sum2 = sum1;
       }
    

cout << d;
}