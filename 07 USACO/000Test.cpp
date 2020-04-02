/*
ID: yashjai4
TASK: test
LANG: C++14              
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a + b << endl;
    return 0;
}