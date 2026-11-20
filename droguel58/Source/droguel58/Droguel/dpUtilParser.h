#pragma once

#include <string>
#include <vector>
#include <map>

struct tagInfoStruct
{
    bool isValid;  //values are set or not set
    bool isContainer;
    bool isHeight;
    bool isWidth;
    int xRelPos;   //xContainerPos
    int yRelPos;   //yContainerPos
    int xAbsPos;
    int yAbsPos;
    int height;
    int width;
    int marginX1;
    int marginY1;
    int marginX2;
    int marginY2;
};


typedef std::map<std::string, std::string> BBML_ParamValMap;
typedef std::pair<std::string, std::string> BBML_ParamValPair;
typedef std::vector<std::string> vectorTagQueue;


class CUtilParser
{
public:
    CUtilParser(void);
    ~CUtilParser(void);

    //tag info
    bool isCloseTag(std::string tag);
    bool isOpenTag(std::string tag);
    bool isSingleTag(std::string tag);
    bool tagGetName(std::string tag, std::string &name);

    //tag reader - read file till tag then get tag and content
    bool getTag(std::string &sTagStr, std::fstream &fin);
    bool getTagContent(std::string &sStrContent, std::fstream &fin);

    //tag tools
    bool passOnSpaces(int &i, std::string inStr);
    bool tagClean(std::string &line);
    std::string getIndent(int indent);

    //other
    void errorOut(std::string errorStr);
    bool traverseFileExample(std::string fname);

    //Param List
    bool paramExists(BBML_ParamValMap &paramList, std::string param);
    bool tagGetEqualParam(std::string tag, std::string &param, std::string &value, int &pos);
    bool getParamsWithEqual(std::string tag, BBML_ParamValMap &paramList);
    bool getParamString(BBML_ParamValMap &paramValMap, std::string param, std::string &value);
    bool getParamInt(BBML_ParamValMap &paramValMap, std::string param, int &value);
    bool getFourInts(std::string inParam, std::string &x1, std::string &y1, std::string &x2, std::string &y2);

    void AddParamToTag(std::string param, std::string value, std::string &tag);
    void AddParamToTag(std::string param, int value, std::string &tag);

    void changeParamInt(BBML_ParamValMap &paramValMap, std::string param, int newval, bool adjust);

    //old
    bool getMarginX1Y1X2Y2(std::string inValues, std::string &x1, std::string &y1, std::string &x2, std::string &y2);
    std::string getValueOrNothing(BBML_ParamValMap &paramValMap, std::string inParam, std::string outParamPre, std::string outParamPost);
    std::string getValueOrDefaultInt(BBML_ParamValMap &paramValMap, std::string inParam, std::string outParamPre, std::string outParamPost, int defaultInt);
    std::string cleanBbmlColor(std::string inColor);
    std::string buildHtmlStyleFromBBML(int enumtype, BBML_ParamValMap &paramValMap);

    //scraper
    static int getTagContentInt( std::string startTag, std::string endTag, std::string inputline );
    static std::string getTagContent( std::string startTag, std::string endTag, std::string inputline );
    static void findAndReadTag( std::string inputline, std::string tagStart, std::string tagEnd, std::string &tagContent );
    static bool getNumParamValue( std::string inputline, std::string tag, std::string &outParam );
    static bool getParamStringEqualQuote( std::string inputline, std::string tag, std::string &outParam );
    static bool parseLineWithDelimiter( std::string linein, std::string delim, std::vector<std::string> &parseVector );
};
