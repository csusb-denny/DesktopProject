//
// Created by Denny on 11/8/24.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>

extern const std::string DESKTOP_PATH;                           //Declare lgobally

std::vector<std::string> listDesktopFiles();
bool ends_with(const std::string& str, const std::string& suffix);
bool isExcluded(const std::string &fileName);
//void createDesktopFiles(const string &path, vector<string> &desktopFiles);
void moveToTrash(const std::string &filePath);
void moveToFolder(const std::string &filePath);
void organizeDesktop();
#endif //FILEHANDLER_H
