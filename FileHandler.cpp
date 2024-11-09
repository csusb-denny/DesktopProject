//
// Created by Denny on 11/9/24.
//

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

// Define your desktop path here
const std::string DESKTOP_PATH = "/Users/denny/Desktop";
//file ending with function
bool ends_with(const std::string& str, const std::string& suffix) {
    if (str.size() < suffix.size()) return false;
    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
};
// Function to list files on the desktop
std::vector<std::string> listDesktopFiles() {
    std::vector<std::string> files;

    std::cout << "Listing files in: " << DESKTOP_PATH << std::endl;
    for (const auto& entry : fs::directory_iterator(DESKTOP_PATH)) {
        std::string filePath = entry.path().string();
        std::string fileName = entry.path().filename().string();
        if(fileName == "pdf" || fileName == "docx" || fileName == "Trash")
        {
           continue;
        }

        std::cout << "Found file: " << filePath << std::endl;  // Debug: Show each file
        files.push_back(filePath);
    }

    return files;
};

// Function to check if a file should be excluded
bool isExcluded(const std::string& fileName) {
    bool excluded = ends_with(fileName, ".pdf") || ends_with(fileName,".docx");
    std::cout << "File " << fileName << " excluded: " << (excluded ? "Yes" : "No") << std::endl;  // Debug
    return excluded;
};

// Function to move a file to the trash folder
void moveToTrash(const std::string& filePath) {
    fs::path trashFolder = DESKTOP_PATH + "/Trash";

    // Create the Trash folder if it doesn't exist
    if (!fs::exists(trashFolder)) {
        fs::create_directory(trashFolder);
    }

    fs::path destination = trashFolder / fs::path(filePath).filename();
    try {
        fs::rename(filePath, destination);
        std::cout << "Moved " << filePath << " to Trash" << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error moving file " << filePath << ": " << e.what() << std::endl;
    }
};

// Function to move a file to a specific folder based on its extension
void moveToFolder(const std::string& filePath) {
    fs::path pdfFolder = DESKTOP_PATH + "/pdf";
    fs::path docxFolder = DESKTOP_PATH + "/docx";

    // Ensure destination folders exist
    if (!fs::exists(pdfFolder)) fs::create_directory(pdfFolder);
    if (!fs::exists(docxFolder)) fs::create_directory(docxFolder);

    fs::path destination;
    if (ends_with(filePath, ".pdf")) {
        destination = pdfFolder / fs::path(filePath).filename();
    } else if (ends_with(filePath, ".docx")) {
        destination = docxFolder / fs::path(filePath).filename();
    }

    try {
        fs::rename(filePath, destination);
        std::cout << "Moved " << filePath << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error moving file " << filePath << ": " << e.what() << std::endl;
    }
};

// Main function or function that organizes the flow
void organizeDesktop() {
    auto files = listDesktopFiles();

    for (const auto& file : files) {
        if (isExcluded(file)) {
            moveToFolder(file);
        } else {
            moveToTrash(file);
        }
    }
};
