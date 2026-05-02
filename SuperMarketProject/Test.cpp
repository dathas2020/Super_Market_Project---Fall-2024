#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    file.open("testfile.txt", ios::app);
    if(file.is_open())
    {
        string str;
        file << "\n" << "Aata";
        file.close();
    }
}