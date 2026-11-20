#pragma once

#include <string>
#include <vector>
#include <Windows.h>

class CUtilFile
{
public:
    CUtilFile(void);
    ~CUtilFile(void);

    bool writeStringToFile(std::string &filedata, std::string filename);

    //file info
    static void getParsePath(std::string path, std::vector<std::string> &pathlist);
    static void getFileInfoFromFullPath(std::string fullpath, std::string &path, std::string &fname, std::string &extension);
    static std::string getFilenameFromFullPath(std::string fullpath);
    static std::string getFileExtFromFullPath(std::string fullpath);
    static std::string getFullPath(std::string fnameIn);

    //file attributes
    static bool isDots(std::string fname);
    static bool isDir(std::string fname);
    static void setFileAttrib(std::string fname, DWORD attrib);
    static std::string fileAttribString(std::string fname);

    //files and vectors
    static bool writeStringArrayToFile(std::vector<std::string> &filedata, std::string filename);
    static bool readFileToStringArray(std::vector<std::string> &filedata, std::string filename);

    //directories
    void traverseDirectoryFileList(std::string sourcePath, std::vector<std::string> &outFileList);
    void traverseForDirectoryList(std::string sourcePath, std::vector<std::string>& outDirList);
    //void traverseDirectory(std::string dirName);

    //files and directories
    static bool createDir(std::string dirname);
    bool fileExists(std::string fname);
    bool removeFile(std::string fname);
    bool renameFile(std::string source, std::string dest);
    bool copyFile(std::string source, std::string dest);
   
    
    static std::string patchPath(std::string fname);

    bool ReplaceTagsWithData(std::string fnameIn, std::string fnameOut, std::string tagIn, std::string tagOut);


};
