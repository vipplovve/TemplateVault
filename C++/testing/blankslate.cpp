#include <fstream>
#include <iostream>
using namespace std;
  
int main()
{
    string line;

    ifstream ini_file{"templateC++.txt"};

    ofstream out_file{"sourcecode.cpp"};
     
    if (ini_file && out_file) 
        while (getline(ini_file, line)) 
            out_file << line << "\n";

    ini_file.close();
    out_file.close();

    ifstream ini_fileX{"templateC++.txt"};

    ofstream out_fileX{"bruteforce.cpp"};
    
    string lineX;

    if (ini_fileX && out_fileX) 
        while (getline(ini_fileX, lineX)) 
            out_fileX << lineX << "\n";

    ini_fileX.close();
    out_fileX.close();

    ifstream ini_fileY{"templateGenerator.txt"};

    ofstream out_fileY{"generator.cpp"};
    
    string lineY;

    if (ini_fileY && out_fileY) 
        while (getline(ini_fileY, lineY)) 
            out_fileY << lineY << "\n";

    ini_fileY.close();
    out_fileY.close();
    
    cout << "\nTemplates have been re-written..\n";

    cout << "\nGenerator has been cleaned..\n";

    return 0;
}
