#include <iostream>
#include "FileHandler.h"  // Assuming this is where your function declarations are

int main() {
    try {
        // Call the function to organize the desktop files
        organizeDesktop();
        std::cout << "Desktop cleanup completed successfully." << std::endl;
    } catch (const std::exception& e) {
        // Catch any unexpected errors and display a message
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

/*int main()
{
    fs::path source = "/Users/denny/Desktop/testfile.txt";
    fs::path destination = "/Users/denny/Desktop/Trash/testfile.txt";

    try
    {
        if (!fs::exists(destination.parent_path()))
        {
           fs::create_directory(destination.parent_path());
        }
        fs::rename(source, destination);
        cout << "Moved file to: " << destination << endl;
    }
    catch(const fs::filesystem_error& e){
        cerr << "File moved error: " << e.what() << endl;
    }

    return 0;
}
*/