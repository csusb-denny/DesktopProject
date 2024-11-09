//
// Created by Denny on 11/8/24.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
using namespace std;

extern const string DESKTOP_PATH;                           //Declare lgobally

vector<string> listDesktopFiles(const string &path);
bool isExcludedFileType(const string &fileName);

#endif //FILEHANDLER_H
