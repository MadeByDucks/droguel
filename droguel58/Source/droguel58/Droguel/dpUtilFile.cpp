#include "dpUtilFile.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include "dpUtilString.h"
#include "dpUtilLog.h"
#include <Windows.h>



//ttdtodo
//Create a function to create directory given full path including file



CUtilFile::CUtilFile(void)
{
}


CUtilFile::~CUtilFile(void)
{
}


///////////////////////////////////////////////////////////////////////////////
//file inf          
///////////////////////////////////////////////////////////////////////////////

void CUtilFile::getParsePath(std::string path, std::vector<std::string> &pathlist)
{
    std::string element = "";

    for (int i = 0; i < path.length(); i++)
    {
        if ((path[i] == '\\') || (path[i] == '/'))
        {
            pathlist.push_back(element);
            element = "";
        }
        else
        {
            element = element + path[i];
        }
    }

    if (element != "")
    {
        pathlist.push_back(element);
    }
}

void CUtilFile::getFileInfoFromFullPath(std::string fullpath, std::string &path, std::string &fname, std::string &extension)
{
    //ttdtodo
    //handle double extensions (aspx.cs) with upper and lower case
    //handle both / and \ in path

    std::string parse = fullpath;

    CUtilString strhelp;

    extension = "";
    if (parse.rfind(".aspx.cs") != std::string::npos) 
    {
        extension = ".aspx.cs";
        strhelp.removeAllSubStrFromStr(extension, parse);
    }
    else if (parse.rfind(".cshtml.cs") != std::string::npos)
    {
        extension = ".cshtml.cs";
        strhelp.removeAllSubStrFromStr(extension, parse);
    }
    else if (parse.rfind(".") != std::string::npos)
    {
        size_t lastpos = parse.rfind(".");
        size_t extlen = parse.length() - lastpos;

        extension = parse.substr(lastpos, extlen);
        parse.erase(lastpos, extlen);
    }

    //get fname
    if (parse.rfind("\\") != std::string::npos)
    {
        size_t lastpos = parse.rfind("\\");
        size_t fnamelen = parse.length() - lastpos;

        fname = parse.substr(lastpos + 1, fnamelen - 1);
        parse.erase(lastpos, fnamelen);
    }

    //get path
    path = parse;
}

std::string CUtilFile::getFilenameFromFullPath(std::string fullpath)
{
    std::string fname = fullpath;
    std::string path = "";
    std::string extension = "";
    getFileInfoFromFullPath(fullpath, path, fname, extension);
    return fname;
}

std::string CUtilFile::getFileExtFromFullPath(std::string fullpath)
{
    std::string fname = fullpath;
    std::string path = "";
    std::string extension = "";
    getFileInfoFromFullPath(fullpath, path, fname, extension);
    return extension;
}

std::string CUtilFile::getFullPath(std::string fnameIn)
{
    std::string fname = "";
    std::string path = "";
    std::string extension = "";
    getFileInfoFromFullPath(fnameIn, path, fname, extension);
    return path;
}

///////////////////////////////////////////////////////////////////////////////
//files and vectors
///////////////////////////////////////////////////////////////////////////////

bool CUtilFile::writeStringToFile(std::string &filedata, std::string filename)
{
    bool bSuccess = true;
    std::fstream fout;
    std::string str;

    if (bSuccess)
    {
        fout.open(filename, std::ios::out);
        bSuccess = fout.is_open();
    }

    if (bSuccess)
        fout << filedata;

    fout.close();
    return bSuccess;
}


bool CUtilFile::writeStringArrayToFile(std::vector<std::string> &filedata, std::string filename)
{
    bool bSuccess = true;
    std::fstream fout;
    std::string str;

    if (bSuccess)
    {
        fout.open(filename, std::ios::out);
        bSuccess = fout.is_open();
    }

    for (std::vector<std::string>::const_iterator i = filedata.begin(); i != filedata.end(); ++i)
    {
        fout << *i << std::endl;
    }

    fout.close();
    return bSuccess;
}


bool CUtilFile::readFileToStringArray(std::vector<std::string> &filedata, std::string filename)
{
    bool bSuccess = true;
    std::fstream fin;
    std::string str;
    filedata.clear();

    if (bSuccess)
    {
        fin.open(filename, std::ios::in);
        bSuccess = fin.is_open();
    }

    while ((bSuccess) && (!fin.eof()))
    {
        std::getline(fin, str, '\n');
        filedata.push_back(str);
    }

    fin.close();
    return bSuccess;
}




///////////////////////////////////////////////////////////////////////////////
// Directories
///////////////////////////////////////////////////////////////////////////////


void CUtilFile::traverseDirectoryFileList(std::string sourcePath, std::vector<std::string> &outFileList)
{
    sourcePath = CUtilFile::patchPath(sourcePath);
    std::string findfile = sourcePath + "*.*";
    bool bdone = false;
    CUtilFile futil;

    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    //hFind = FindFirstFile( findfile.c_str(), &ffd );
    hFind = FindFirstFile(CUtilString::s2ws(findfile).c_str(), &ffd);

    while ((!bdone) && (INVALID_HANDLE_VALUE != hFind))
    {
        std::string fname = CUtilString::wchar2string(ffd.cFileName); //ffd.cFileName;
        std::string attrib = CUtilFile::fileAttribString(sourcePath + fname);

        if (CUtilFile::isDir(sourcePath + fname) && (!CUtilFile::isDots(fname)))
            traverseDirectoryFileList(sourcePath + fname, outFileList);
        else if (!CUtilFile::isDots(fname))
        {
            //printf( "%s%s\n", sourcePath.c_str(), fname.c_str() );
            printf("+");
            outFileList.push_back(sourcePath + fname);
        }

        bdone = (FindNextFile(hFind, &ffd) == 0);
    }
    printf("\n");

    FindClose(hFind);
}

void CUtilFile::traverseForDirectoryList(std::string sourcePath, std::vector<std::string>& outDirList)
{
    sourcePath = CUtilFile::patchPath(sourcePath);
    std::string findfile = sourcePath + "*.*";
    bool bdone = false;
    CUtilFile futil;

    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    //hFind = FindFirstFile( findfile.c_str(), &ffd );
    hFind = FindFirstFile(CUtilString::s2ws(findfile).c_str(), &ffd);

    while ((!bdone) && (INVALID_HANDLE_VALUE != hFind))
    {
        std::string fname = CUtilString::wchar2string(ffd.cFileName); //ffd.cFileName;
        std::string attrib = CUtilFile::fileAttribString(sourcePath + fname);

        if (CUtilFile::isDir(sourcePath + fname) && (!CUtilFile::isDots(fname)))
        {
            outDirList.push_back(sourcePath + fname);               
            traverseForDirectoryList(sourcePath + fname, outDirList);
            printf("+");
            //printf( "%s%s\n", sourcePath.c_str(), fname.c_str() );
     
        }


        bdone = (FindNextFile(hFind, &ffd) == 0);
    }
    printf("\n");

    FindClose(hFind);
}


//void CUtilFile::traverseDirectory(std::string dirName)
//{
//    bool recursive = true;
//    std::string wildcard = "*.*";
//    bool isDir = false;
//    bool isDots = false;
//    bool isFile = false;
//}


///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////


//*****************************************************************************
std::string CUtilFile::patchPath(std::string fname)
{
    std::string outstr = fname;
    if (fname != "")
    {
        if (fname[fname.length() - 1] != '\\')
            outstr += '\\';
    }

    return outstr;
}

///////////////////////////////////////////////////////////////////////////////
//windows makedir
bool CUtilFile::createDir(std::string dirname)
{
    //bool bSuccess = ((CreateDirectory(dirname.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError()));
    bool bSuccess = ((CreateDirectory( CUtilString::s2ws(dirname).c_str(), NULL ) || ERROR_ALREADY_EXISTS == GetLastError()));
    return bSuccess;
}

///////////////////////////////////////////////////////////////////////////////
bool CUtilFile::fileExists(std::string fname)
{
    bool bFileExist = false;
    std::fstream fin;

    fin.open(fname, std::ios::in);
    if (fin.is_open())
    {
        fin.close();
        bFileExist = true;
    }

    return bFileExist;
}

///////////////////////////////////////////////////////////////////////////////
bool CUtilFile::removeFile(std::string fname)
{
    bool bSuccess = false;

    std::string errorMsg = "";

    if (fileExists(fname))
    {
        if (remove(fname.c_str()) != 0)
        {
            perror(std::string("RemoveFile: Error deleting file: " + fname).c_str());
        }
        else
        {
            //ttdtodo:logs// puts(std::string("RemoveFile: File successfully deleted: " + fname).c_str());
            bSuccess = true;
        }
    }
    else
    {
        puts(std::string("RemoveFile: File does not exist: " + fname).c_str());
    }

    return bSuccess;
}

///////////////////////////////////////////////////////////////////////////////
bool CUtilFile::renameFile(std::string source, std::string dest)
{
    bool bSuccess = false;

    int result = rename(source.c_str(), dest.c_str());
    if (result == 0)
    {
        puts(std::string("RenameFile: File successfully renamed: " + source + "/" + dest).c_str());
        bSuccess = true;
    }
    else
    {
        perror(std::string("RenameFile: Error renaming file: " + source + "/" + dest).c_str());
    }

    return bSuccess;
}

///////////////////////////////////////////////////////////////////////////////
bool CUtilFile::copyFile(std::string source, std::string dest)
{
    //std::filesystem::copy( source, dest );  //ttdtodo

    //ttdtodo: Put this in and remove old
    bool bSuccess = true;
    std::ifstream  src( source, std::ios::binary );
    std::ofstream  dst( dest, std::ios::binary );
    dst << src.rdbuf();
    return bSuccess;

    //std::fstream fin;
    //std::fstream fout;
    //std::string str;
    //bool bSuccess = true;

    //if (bSuccess)
    //{
    //    fout.open(dest, std::ios::out);
    //    bSuccess = fout.is_open();
    //}

    //if (bSuccess)
    //{
    //    fin.open(source, std::ios::in);
    //    bSuccess = fin.is_open();
    //}

    //while ((bSuccess) && (!fin.eof()))
    //{
    //    std::getline(fin, str, '\n');
    //    fout << str << std::endl;
    //}

    //fout.close();
    //fin.close();

    //return bSuccess;
}


///////////////////////////////////////////////////////////////////////////////
//Replace tags with data
//ttdtodo: This does not work if the tag has a linefeed in the middle
//ttdtodo: Check tagIn and TagOut to make sure they are not the same
bool CUtilFile::ReplaceTagsWithData(std::string fnameIn, std::string fnameOut, std::string tagIn, std::string tagOut)
{
    ////ttdtodo: Put this in and remove old
    bool bFound = false;
    std::vector<std::string> filedataIn;
    std::vector<std::string> filedataOut;
    bool bSuccess = readFileToStringArray( filedataIn, fnameIn );
    if ( bSuccess )
    {
        for ( int i = 0; i < filedataIn.size(); i++ )
        {
            std::string str = filedataIn[i];
            if ( !bFound )
                bFound = (str.find( tagIn, 0 ) != std::string::npos);
            str = CUtilString::strSearchReplace( str, tagIn, tagOut );
            filedataOut.push_back( str );
        }
    }
    if ( bSuccess )
        bSuccess = writeStringArrayToFile( filedataOut, fnameOut );
    return bSuccess;

    ////fnameIn will be template or second pass file
    ////fnameOut will be the output
    ////tagIn is tag to replase
    ////tagOut is what tag in is being replaced with
    //std::fstream fin;
    //std::fstream fout;
    //std::string str = "";
    //bool bSuccess = true;
    //bool bFound = false;  //tag found

    //CUtilString y;
    //std::string val = y.getEnvironmentVar("DevDuck");
    //std::string fnameTemp = val + "\\temp\\tempWorkspace\\tempData.txt";
    //removeFile(fnameTemp);

    ////create temp file
    //if (bSuccess)
    //{
    //    fout.open(fnameTemp, std::ios::out);
    //    bSuccess = fout.is_open();
    //}

    ////open file
    //if (bSuccess)
    //{
    //    fin.open(fnameIn, std::ios::in);
    //    bSuccess = fin.is_open();
    //}

    //while ((bSuccess) && (!fin.eof()))
    //{
    //    //get the line
    //    std::getline(fin, str, '\n');

    //    //replace the tag //delete the tag and insert new text
    //    if (!bFound)
    //        bFound = (str.find(tagIn, 0) != std::string::npos);
    //    str = strSearchReplace( str, tagIn, tagOut );
    //    //bool bDone = false;
    //    //while (!bDone)
    //    //{
    //    //    int pos = str.find(tagIn);
    //    //    bDone = (pos == std::string::npos);
    //    //    if (pos != std::string::npos)
    //    //    {
    //    //        bFound = true;
    //    //        str.erase(pos, tagIn.length());
    //    //        str.insert(pos, tagOut);
    //    //    }
    //    //}

    //    //out the results
    //    fout << str << std::endl;
    //}

    //fout.close();
    //fin.close();

    ////Copy 
    //bSuccess = copyFile(fnameTemp, fnameOut);

    ////Error out, tag not in template.  
    ////if (!bFound)  //ttdtodo
    ////    dpUtilLog::outputErrorMessageAndPause( "ReplaceTagsWithData: Tag was not found in template file: Call not needed: " + fnameIn + "   " + tagIn );

    //return bSuccess;
}

/////////////////////////////////////////////////////////////////////////////////
////void CUtilFile::CreateTextFile(CString filename)
////{
////    std::fstream fin, fout;
////
////    //create test file
////    fout.open("c:\\here\\test.txt", std::ios::out);
////    if (!fout.is_open()) return;
////
////    for (int i=0; i<10; i++)
////        fout << "this is line #" << i+1 << std::endl;
////    fout.close();
////
////    //read test file
////    fin.open("c:\\here\\test.txt", std::ios::in);
////    if (!fin.is_open()) return;
////
////    std::string str;
////    while (!fin.eof())
////    {
////        std::getline(fin, str, '\n');
////        std::cout << str << std::endl;
////    }
////    fin.close();
////
////}


bool CUtilFile::isDots(std::string fname)
{
    if ((fname == ".") || (fname == ".."))
        return true;

    return false;
}


bool CUtilFile::isDir(std::string fname)
{
    //std::wstring wfname = s2ws(fname);
    //LPCWSTR lpcwstr_fname = wfname.c_str();
    //DWORD attribs = GetFileAttributes(lpcwstr_fname);
    //DWORD attribs = GetFileAttributes(fname.c_str());
    DWORD attribs = GetFileAttributes( CUtilString::s2ws(fname).c_str());

    if ((attribs & FILE_ATTRIBUTE_DIRECTORY) != 0)
        return true;

    return false;
}


void CUtilFile::setFileAttrib(std::string fname, DWORD attrib)
{
    //FILE_ATTRIBUTE_NORMAL
    //SetFileAttributes(fname.c_str(), attrib);
    SetFileAttributes( CUtilString::s2ws(fname).c_str(), attrib);
}


std::string CUtilFile::fileAttribString(std::string fname)
{
    std::string output = "";

    //std::wstring wfname = s2ws(fname);
    //LPCWSTR lpcwstr_fname = wfname.c_str();
    //DWORD attribs = GetFileAttributes(lpcwstr_fname);
    //DWORD attribs = GetFileAttributes(fname.c_str());
    DWORD attribs = GetFileAttributes( CUtilString::s2ws(fname).c_str());

    if ((attribs & FILE_ATTRIBUTE_ARCHIVE) != 0)
        output = "<Archive>";
    if ((attribs & FILE_ATTRIBUTE_COMPRESSED) != 0)
        output = "<Compressed>";
    if ((attribs & FILE_ATTRIBUTE_DIRECTORY) != 0)
        output = "<Directory>";
    if ((attribs & FILE_ATTRIBUTE_HIDDEN) != 0)
        output = "<Hidden>";
    if ((attribs & FILE_ATTRIBUTE_NORMAL) != 0)
        output = "<Normal>";
    if ((attribs & FILE_ATTRIBUTE_READONLY) != 0)
        output = "<ReadOnly>";
    if ((attribs & FILE_ATTRIBUTE_SYSTEM) != 0)
        output = "<System>";

    return output;
}
