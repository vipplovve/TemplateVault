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

    ifstream ini_fileX{"templatePy.txt"};

    ofstream out_fileX{"sourcecode.py"};
    
    string lineX;

    if (ini_fileX && out_fileX) 
        while (getline(ini_fileX, lineX)) 
            out_fileX << lineX << "\n";

    ini_fileX.close();
    out_fileX.close();
    
    ofstream out_file2{ "output.out" };
    out_file2.close();
    
    ofstream out_file3{ "input.in" };
    out_file3.close();
    
    cout << "\nI/O Files have Been Cleaned..\n\n";
    
    cout << "Templates have been re-written..\n";

    return 0;
}
