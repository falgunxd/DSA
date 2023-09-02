#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
    fstream file("input2.txt", ios::in | ios::app | ios::out);
    if (!file.is_open())
    {
        cout << "Error opening the desired file";
    }
    else
    {
        // file << "Wow kya ladka hai. Isse to bohot maza ayega" << endl;
        string wow;
        while (file.good())
        {
            getline(file, wow);
            cout << wow << endl;
        }
    }
    // try
    // {
    //     {/* code */}
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
}