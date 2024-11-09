//
// Created by Denny on 11/8/24.
//
#include "FileHandler.h"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
using namespace std;

vector<string> listDesktopFiles(const string &path)
{
    vector<string> files;

    //check if the directory exists
    if (!fs::exists(path) || !fs::is_directory(path))
    {
        cerr << "Error: Path not found: " << path << endl;
        return files;
    }

    for (const auto &entry : fs::directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            files.push_back(entry.path().filename().string());
        }
    }
    return files;
};

bool isExcludedFileType(const string &fileName)
{
    //get extension of the file
    string extension = fs::path(fileName).extension();

    //check if extension matches excluded types
    if (extension == ".pdf" || extension == ".docx")
    {
       return true;
    }
    return false;
};