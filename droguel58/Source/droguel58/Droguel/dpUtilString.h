#pragma once

#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <vector>

typedef std::vector<std::string> strVector;


//https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
// trim from start (in place)
static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}





//std::string loc_itoa( int value )
//{
//    char sValue[255];
//    _itoa_s( value, sValue, 255, 10 );
//    std::string output( sValue );
//    return output;
//}
//
//void removeAllSubStrFromStr( std::string substr, std::string &instr )
//{
//    while ( instr.find( substr, 0 ) != std::string::npos )
//    {
//        instr.erase( instr.find( substr, 0 ), substr.length() );
//    }
//}
//
////=============================================================================
////void dpUtilPhoneXmlReader::replaceTag(std::string &str, std::string tagIn, std::string tagOut)
//void replaceTag( std::string &str, std::string tagIn, std::string tagOut )
//{
//    //replace the tag //delete the tag and insert new text
//    bool bDone = false;
//    while ( !bDone )
//    {
//        std::size_t pos = str.find( tagIn );
//        bDone = (pos == std::string::npos);
//        if ( pos != std::string::npos )
//        {
//            str.erase( pos, tagIn.length() );
//            str.insert( pos, tagOut );
//        }
//    }
//}
//
//std::string makeLower( std::string convert )
//{
//    std::transform( convert.begin(), convert.end(), convert.begin(), ::tolower );
//    return convert;
//}
//
//
//std::string makeUpper( std::string convert )
//{
//    std::transform( convert.begin(), convert.end(), convert.begin(), ::toupper );
//    return convert;
//}
//





class CUtilString
{
public:
    //static std::string convertCStringToStdString(CString inStr)
    //{
    //  // Convert a TCHAR string to a LPCSTR
    //  CT2CA pszConvertedAnsiString (inStr);
    //  // construct a std::string using the LPCSTR input
    //  std::string strStd (pszConvertedAnsiString);
    //  return strStd;
    //}

    CUtilString();
    ~CUtilString();


public:
    static std::string makeLower(std::string convert);
    static std::string makeUpper(std::string convert);
    static std::string strSearchReplace(std::string inStr, std::string tagIn, std::string tagOut);
    static std::string strSearchReplaceOnePass(std::string inStr, std::string tagIn, std::string tagOut);

    static std::string wchar2string( wchar_t* inStr );
    static std::wstring s2ws(const std::string& s);
    static std::string padStrWithChar(std::string str, const size_t num, const char padChar = ' ');
    static std::string getEnvironmentVar(std::string env);

    static void stringParserWithParseChar(char parseChar, std::string parseString, strVector &parseResult);
    static void stringParserWithParseString(std::string delimeter, std::string parseString, strVector& parseResult);

    static void removeAllSubStrFromStr( std::string substr, std::string &instr );
    static void replaceTag( std::string &str, std::string tagIn, std::string tagOut );

    static bool isBlankStr(std::string instr);

    static void stripQuotesDelim(std::string delim, std::string &instr);
};

