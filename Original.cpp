//
// Created by Denny on 11/8/24.
//
#include "FileHandler.h"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
using namespace std;

const string DESKTOP_PATH = "/Users/denny/Desktop";
//list all regular files on the directory
vector<string> listDesktopFiles()
{
    vector<string> files;
    //debug to confirm the function is called
    cout << "Listing files in: " << DESKTOP_PATH << endl;

    //check if the directory exists
    if (!fs::exists(path) || !fs::is_directory(path))
    {
        cerr << "Error: Path not found: " << path << endl;
        return files;
    }
    //iterate through files and add file names to the vector
    for (const auto &entry : fs::directory_iterator(path))
    {
        string file = entry.path().string();
        if (entry.is_regular_file())
        {
            cout << "Found file: " << file << endl;
            files.push_back(entry.path().filename().string());
        }
    }
    return files;
};
//check if the file is a type to be excluded
bool isExcludedFileType(const string &fileName)
{
    //get extension of the file
    string extension = fs::path(fileName).extension().string();

    //check if extension matches excluded types
    if (extension == ".pdf" || extension == ".docx")
    {
       return true;
    }
    return false;
};
//move file to the specified folder
void moveFile(const string &filePath, const string &destinationFolder)
{
    string destinationPath = destinationFolder + "/" + fs::path(filePath).filename().string();
    try
    {
        fs::rename(filePath, destinationPath);  //move file
    }
    catch(const fs::filesystem_error &e)
    {
        cerr << "Error moving file: " << e.what() << endl;
    }
};
//delete file
void deleteFile(const string& filePath)
{
    try
    {
        if(!fs::exists(filePath))
        {
            fs::remove(filePath); //delete file
        }
    }
    catch(const fs::filesystem_error &e)
    {
        cerr << "Error deleting file: " << e.what() << endl;
    }
};
//handle suffixes
bool ends_with(const string &str, const string &suffix)
{
    if(str.length() < suffix.length())
    {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
};