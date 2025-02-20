# DesktopProject (C++)

**Description**:  
DesktopProject is a C++ desktop automation tool designed to organize cluttered desktop files by sorting them into predefined folders (e.g., Documents, Images, Videos) and moving unnecessary files to the Recycle Bin. This project demonstrates my skills in file system manipulation, cross-platform development, and automation.

---

### **Key Features**
- **File Sorting**: Automatically sorts files into predefined folders based on their type.
- **Recycle Bin Cleanup**: Moves unnecessary files to the Recycle Bin (or Trash on macOS/Linux).
- **Cross-Platform Compatibility**: Works on Windows, macOS, and Linux systems.
- **Error Handling**: Includes robust error handling to ensure smooth operation.

---

### **Technologies Used**
- **C++**: Core programming language.
- **File System Library**: For file and directory operations (C++17 `<filesystem>` or platform-specific APIs).
- **Platform-Specific APIs**:
  - **Windows**: Uses `SHFileOperation` or `IFileOperation` for moving files to the Recycle Bin.
  - **macOS/Linux**: Uses `trash` command or `gio trash` for moving files to the Trash.

---

### **How to Run**
1. Clone the repository:
   ```bash
   git clone https://github.com/csusb-denny/DesktopProject.git
