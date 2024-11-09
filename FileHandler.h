//
// Created by Denny on 11/8/24.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
using namespace std;

extern const string DESKTOP_PATH;                           //Declare lgobally

vector<string> listDesktopFiles();
bool ends_with(const std::string& str, const std::string& suffix);
bool isExcluded(const string &fileName);
//void createDesktopFiles(const string &path, vector<string> &desktopFiles);
void moveToTrash(const string &filePath);
void moveToFolder(const string &filePath);
void organizeDesktop();
#endif //FILEHANDLER_H
