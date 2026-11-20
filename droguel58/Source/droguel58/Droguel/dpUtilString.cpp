#include "dpUtilString.h"
#include <stdlib.h>
#include <string>
#include <time.h>
//#include <windows.h>//s2ws


CUtilString::CUtilString()
{
}


CUtilString::~CUtilString()
{
}


std::string CUtilString::makeLower(std::string convert)
{
    std::transform(convert.begin(), convert.end(), convert.begin(), ::tolower);
    return convert;
}

std::string CUtilString::makeUpper(std::string convert)
{
    std::transform(convert.begin(), convert.end(), convert.begin(), ::toupper);
    return convert;
}

std::string CUtilString::strSearchReplace(std::string inStr, std::string tagIn, std::string tagOut)
{
    //ttdtodo: if tagin is a subset of tag out then issue with the while loop and pos
    while (inStr.find(tagIn, 0) != std::string::npos)
    {
        size_t pos = inStr.find(tagIn, 0);
        inStr.erase(pos, tagIn.length());
        inStr.insert(pos, tagOut);
    }
    return inStr;
}

std::string CUtilString::strSearchReplaceOnePass(std::string inStr, std::string tagIn, std::string tagOut)
{
    size_t pos = 0;
    while (inStr.find(tagIn, pos) != std::string::npos)
    {
        pos = inStr.find(tagIn, pos);
        inStr.erase(pos, tagIn.length());
        inStr.insert(pos, tagOut);
        pos += tagOut.length();
    }
    return inStr;
}

/////////////////////////////////////////////////////////////////////////////////
//std::string CUtilString::strPathToCppStrPath( std::string inPath )
//{
//    std::string outStr;
//
//    for ( int i = 0; i < inPath.length(); i++ )
//    {
//        outStr += inPath[i];
//        if ( inPath[i] == '\\' )
//            outStr += '\\';
//    }
//    return outStr;
//}


std::string CUtilString::wchar2string( wchar_t* inStr )
{
    std::wstring ws( inStr );
    std::string outStr( ws.begin(), ws.end() );
    return outStr;
}


//std::wstring stemp = std::wstring(s.begin(), s.end());
//LPCWSTR sw = stemp.c_str();
std::wstring CUtilString::s2ws(const std::string& s)
{
    std::wstring stemp = std::wstring(s.begin(), s.end());
    return stemp;
}


std::string CUtilString::padStrWithChar(std::string str, const size_t num, const char padChar)
{
    std::string outStr = str;
    if (num > outStr.size())
        outStr.insert(0, num - outStr.size(), padChar);
    return outStr;
}


//std::string CUtilString::convertCStringToStdString(CString inStr)
//{
//  //std::string outStr(CW2A(inStr.GetString(), CP_UTF8));
//  std::string outStr = CStringA(inStr);
//  return outStr;
//}


std::string CUtilString::getEnvironmentVar(std::string env)
{
    std::string outStr = "";

    char *pValue;
    size_t len;
    errno_t err = _dupenv_s(&pValue, &len, env.c_str());
    if (err)
    {
        puts("getEnvironmentVar: Error: input = ");// env
    }
    else
    {
        outStr = pValue;
        //ttdtodo:logs//  puts("getEnvironmentVar: Success: value = ");// env and pValue
        free(pValue);
    }

    return outStr;
}


void CUtilString::stringParserWithParseChar(char parseChar, std::string parseString, strVector &parseResult)
{
    parseResult.clear();

    int i = 0;
    std::string resultStr = "";
    while (i < parseString.length())
    {
        if (parseString[i] == parseChar)
        {
            parseResult.push_back(resultStr);
            resultStr = "";
        }
        else
        {
            resultStr += parseString[i];
        }
        i++;
    }
    if (resultStr != "")
        parseResult.push_back(resultStr);
}

void CUtilString::stringParserWithParseString(std::string delimiter, std::string parseString, strVector& parseResult)
{
    parseResult.clear();

    size_t pos = 0;
    std::string token;
    while ((pos = parseString.find(delimiter)) != std::string::npos) 
    {
        token = parseString.substr(0, pos);
        parseResult.push_back(token);
        parseString.erase(0, pos + delimiter.length());
    }
    if (parseString != "")
    {
        parseResult.push_back(parseString);
    }
}

void CUtilString::removeAllSubStrFromStr( std::string substr, std::string &instr )
{
    while ( instr.find( substr, 0 ) != std::string::npos )
    {
        instr.erase( instr.find( substr, 0 ), substr.length() );
    }
}


//void dpUtilPhoneXmlReader::replaceTag(std::string &str, std::string tagIn, std::string tagOut)
void CUtilString::replaceTag( std::string &str, std::string tagIn, std::string tagOut )
{
    //replace the tag //delete the tag and insert new text
    bool bDone = false;
    while ( !bDone )
    {
        std::size_t pos = str.find( tagIn );
        bDone = (pos == std::string::npos);
        if ( pos != std::string::npos )
        {
            str.erase( pos, tagIn.length() );
            str.insert( pos, tagOut );
        }
    }
}

bool CUtilString::isBlankStr(std::string instr)
{
    bool isEmpty = false;

    removeAllSubStrFromStr("\t", instr);
    removeAllSubStrFromStr("\n", instr);
    trim(instr);

    isEmpty = ((instr.empty()) || (instr == ""));

    return isEmpty;
}

void CUtilString::stripQuotesDelim(std::string delim, std::string &instr)
{
    trim(instr);
    if (instr.find(delim, 0) == 0)
    {
        instr.erase(0, 1);
        if (instr.rfind(delim) == instr.size()-1)
        {
            instr.erase(instr.size() - 1, 1);
        }
    }
}
