#include <iostream>
#include "FileHandler.h"

using namespace std;

const string DESKTOP_PATH = "/Users/denny/Desktop";



int main()
{
    vector<string> files = listDesktopFiles(DESKTOP_PATH);              //List files and filter as needed

    for (const auto& file : files)                           //process and display files (unit testing)
    {
        if(!isExcludedFileType(file))
        {
            cout << file << " (Included)\n";
        }
        else
        {
            cout << file << " (Excluded)\n";
        }
    }
    return 0;
}
