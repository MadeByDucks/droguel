#include "dpUtilParser.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "dpUtilLog.h"
#include "dpUtilFile.h"
#include "dpUtilString.h"


CUtilParser::CUtilParser(void)
{
}


CUtilParser::~CUtilParser(void)
{
}


bool CUtilParser::isCloseTag(std::string tag)
{
    return (tag.find("</", 0) != std::string::npos);
}


bool CUtilParser::isOpenTag(std::string tag)
{
    return (tag.find("</", 0) == std::string::npos);
}


bool CUtilParser::isSingleTag(std::string tag)
{
    return (tag.find("/>", 0) != std::string::npos);
}


bool CUtilParser::getTag(std::string &sTagStr, std::fstream &fin)
{
    bool bSuccess = true;
    char c = ' ';
    sTagStr = "";

    //get to tag
    std::string sPreStr = "";
    while ((bSuccess) && (!fin.eof()) && (c != '<'))
    {
        c = fin.get();
        sPreStr += c;
    }

    //extract the tag
    if (c == '<')
    {
        sTagStr = c;
        while ((bSuccess) && (!fin.eof()) && (c != '>'))
        {
            c = fin.get();
            if ((c != '\n') && (c != '\r') && (c != 0))
                sTagStr += c;
        }
    }
    trim(sTagStr);
    return bSuccess;
}


bool CUtilParser::getTagContent(std::string &sStrContent, std::fstream &fin)
{
    bool bSuccess = true;
    char c = ' ';
    sStrContent = "";

    //post tag
    int iCounter = 0;
    while ((bSuccess) && (!fin.eof()) && (c != '<'))
    {
        c = fin.get();
        if ((c != '<') && (c != '\n') && (c != '\r') && (c != 0) && (c != -1))
            sStrContent += c;
    }

    //put last tag back together for next read
    if ((bSuccess) && (!fin.eof()) && (c == '<'))
        fin.putback(c);

    trim(sStrContent);
    return bSuccess;
}


bool CUtilParser::tagGetName(std::string tag, std::string &name)  //tagGetNameFromTag
{
    bool bSuccess = true;
    name = "";

    //get start pos to find name
    int tagPos = 0;
    passOnSpaces(tagPos, tag);
    tagPos++; //Get past '<'
    if (isCloseTag(tag))
        tagPos++;

    size_t numChars = tag.size();
    while ((tagPos < numChars) && (tag[tagPos] != ' ') && (tag[tagPos] != '/') && (tag[tagPos] != '>'))
    {
        name += tag[tagPos];
        tagPos++;
    }

    //ttdtodo
    //if (m_debugLinesTagInfo)
    //    outputLine(output, getIndent(m_level) + "<!--tag: " + tagName + ":  " + tag + " -->");

    return bSuccess;
}


///////////////////////////////////////////////////////////////////////////////
// Tag Tools
///////////////////////////////////////////////////////////////////////////////


//Find index from given index of first non space char
bool CUtilParser::passOnSpaces(int &i, std::string inStr)
{
    bool bSuccess = true;
    size_t numChars = inStr.size();
    while ((i < numChars) && (inStr[i] == ' '))
        i++;
    return bSuccess;
}


bool CUtilParser::tagClean(std::string &line)
{
    bool bSuccess = true;
    while (line.find("  ", 0) != std::string::npos)
        line.erase(line.find("  ", 0), 2);
    return bSuccess;
}


std::string CUtilParser::getIndent(int indent)
{
    std::string outStr = "";
    for (int i = 0; i < indent; i++)
        outStr += "    ";
    return outStr;
}


///////////////////////////////////////////////////////////////////////////////
// Other
///////////////////////////////////////////////////////////////////////////////


void CUtilParser::errorOut(std::string errorStr)
{
    //LineNumber, ColumnNumber
    //ErrorType: Info, Fatal, Error
    int x = 0;
    int y = 0;
    int z = x / y;
}


bool CUtilParser::traverseFileExample(std::string fname)
{
    bool bSuccess = true;
    std::fstream fin;
    std::string sStrContent = "";
    std::string sTagStr = "";

    //open up the file
    if (bSuccess)
    {
        fin.open(fname, std::ios::in);
        bSuccess = fin.is_open();
    }

    //traverse through file
    while (!fin.eof())
    {
        bSuccess = getTag(sTagStr, fin);
        getTagContent(sStrContent, fin);

        //process tag
    }

    fin.close();

    return bSuccess;
}



///////////////////////////////////////////////////////////////////////////////
// Param List
///////////////////////////////////////////////////////////////////////////////



bool CUtilParser::tagGetEqualParam(std::string tag, std::string &param, std::string &value, int &pos)
{
    //ttdtodo-now - quick fix, need to see why it is empty and effect afterwards.
    if (tag == "")
        return false;





    //ttdtodo: make sure we cover the entire tag for params

    bool bSuccess = true;
    bool bDone = false;

    //ttdtodo: rewrite to find the = then go back for the param and forward to find the param

    //Get past name
    if (pos == 0)
    {
        passOnSpaces(pos, tag);
        pos++; //Get past '<'
        if (isCloseTag(tag))
            pos++;

        size_t numChars = tag.size();
        while ((pos < numChars) && (tag[pos] != ' ') && (tag[pos] != '/') && (tag[pos] != '>'))
        {
            pos++;
        }
    }

    //
    passOnSpaces(pos, tag);
    size_t numChars = tag.size();
    param = "";
    value = "";

    //Check if we are at the end
    if (((tag[pos] == '/') && (tag[pos + 1] == '>')) || (tag[pos] == '>'))
        bDone = true;

    if (!bDone)
    {
        //Get the parameter
        while ((pos < numChars) && (tag[pos] != ' ') && (tag[pos] !=
            '/') && (tag[pos] != '>') && (tag[pos] != '='))
        {
            param += tag[pos];
            pos++;
        }

        passOnSpaces(pos, tag);

        if (tag[pos] == '=')
            pos++;
        else
            errorOut("tagGetEqualParam: did not find '='");

        passOnSpaces(pos, tag);

        //Skip the quote
        if (tag[pos] == '"')
            pos++;
        else
            errorOut("tagGetEqualParam: did not find start '\"'");


        while ((pos < numChars) && (tag[pos] != '"'))
        {
            value += tag[pos];
            pos++;
        }

        //Skip the quote
        if (tag[pos] == '"')
            pos++;
        else
            errorOut("tagGetEqualParam: did not find end '\"'");
    }

    return (!param.empty());
}


bool CUtilParser::getParamsWithEqual(std::string tag, BBML_ParamValMap &paramList)
{
    bool bSuccess = true;
    std::string param = "";
    std::string value = "";

    //clear old if any
    paramList.clear();

    //get params
    int paramCount = 0;
    int tagPos = 0;
    while (tagGetEqualParam(tag, param, value, tagPos))
    {
        paramList.insert(BBML_ParamValPair(param, value));
        //if (m_debugLinesTagInfo)
        //    outputLine(output, getIndent(m_level) + "<!--     Param: " + param + "   value:  " + value + " -->");
        paramCount++;
    }
    if (paramCount == 0)
    {
        //if (m_debugLinesTagInfo)
        //    outputLine(output, getIndent(m_level) + "<!--      NoParam " + " -->");
    }
    //if (m_debugLinesTagInfo)
    //    outputLine(output, getIndent(m_level) + "<!--      Level: " + std::to_string(m_level) + " -->");

    return bSuccess;
}


bool CUtilParser::paramExists(BBML_ParamValMap &paramList, std::string param)
{
    bool bFound = (paramList.find(param) != paramList.end());
    return bFound;
}


bool CUtilParser::getParamString(BBML_ParamValMap &paramValMap, std::string param, std::string &value)
{
    bool bFound = false;
    value = "";
    if (paramValMap.find(param) != paramValMap.end())
    {
        value = paramValMap.find(param)->second;
        bFound = true;
    }
    return bFound;
}


bool CUtilParser::getParamInt(BBML_ParamValMap &paramValMap, std::string param, int &value)
{
    bool bFound = false;
    std::string valuestr = "";
    value = -1;
    if (paramValMap.find(param) != paramValMap.end())
    {
        valuestr = paramValMap.find(param)->second;
        bFound = true;
    }

    if (bFound)
        value = std::stoi(valuestr);

    return bFound;
}


bool CUtilParser::getFourInts(std::string inParam, std::string &x1, std::string &y1, std::string &x2, std::string &y2)
{
    //bool bHasMargin = (inValues != "");
    int paramCounter = 1;

    for (int i = 0; i <= inParam.length(); i++)
    {
        if ((inParam[i] == ' ') || (inParam[i] == '"'))
        {
        }
        else if (inParam[i] == ',')
            paramCounter++;
        else if (paramCounter == 1)
            x1 += inParam[i];
        else if (paramCounter == 2)
            y1 += inParam[i];
        else if (paramCounter == 3)
            x2 += inParam[i];
        else if (paramCounter == 4)
            y2 += inParam[i];
    }


    return true;
}


void CUtilParser::AddParamToTag(std::string param, std::string value, std::string &tag)
{
    size_t location = 0;

    if (tag.find("/>", 0) != std::string::npos)
        location = tag.find("/>", 0);
    else if (tag.find(">", 0) != std::string::npos)
        location = tag.find(">", 0);
    else
        location = tag.size();

    std::string newParam = " " + param + "=\"" + value + "\"";
    tag.insert(location, newParam);
}


void CUtilParser::AddParamToTag(std::string param, int value, std::string &tag)
{
    size_t location = 0;
    std::string sVal = std::to_string(value);

    if (tag.find("/>", 0) != std::string::npos)
        location = tag.find("/>", 0);
    else if (tag.find(">", 0) != std::string::npos)
        location = tag.find(">", 0);
    else
        location = tag.size();

    std::string newParam = " " + param + "=\"" + sVal + "\"";
    tag.insert(location, newParam);
}




///////////////////////////////////////////////////////////////////////////////
// OLD
///////////////////////////////////////////////////////////////////////////////



bool CUtilParser::getMarginX1Y1X2Y2(std::string inValues, std::string &x1, std::string &y1, std::string &x2, std::string &y2)
{
    bool bHasMargin = (inValues != "");

    //x1 = 0;    //y1 = 0;    //x2 = 0;    //y2 = 0;
    x1 = "";
    y1 = "";
    x2 = "";
    y2 = "";

    std::string::iterator it;
    int paramCounter = 1;
    for (it = inValues.begin(); it < inValues.end(); it++)
    {
        if (*it == ' ')
        {
            //do nothing
        }
        else if (*it == ',')
            paramCounter++;
        else if (paramCounter == 1)
            x1 += *it;
        else if (paramCounter == 2)
            y1 += *it;
        else if (paramCounter == 3)
            x2 += *it;
        else if (paramCounter == 4)
            y2 += *it;
    }

    if (x1 == "")
        x1 = "0";
    if (y1 == "")
        y1 = "0";
    if (x2 == "")
        x2 = "0";
    if (y2 == "")
        y2 = "0";

    return bHasMargin;
}


std::string CUtilParser::getValueOrNothing(BBML_ParamValMap &paramValMap, std::string inParam, std::string outParamPre, std::string outParamPost)
{
    std::string outStr = "";

    //Create Style Tag
    if (paramValMap.find(inParam) != paramValMap.end())
    {
        outStr = outStr + outParamPre + paramValMap.find(inParam)->second + outParamPost;
    }

    return outStr;
}


std::string CUtilParser::getValueOrDefaultInt(BBML_ParamValMap &paramValMap, std::string inParam, std::string outParamPre, std::string outParamPost, int defaultInt)
{
    std::string outStr = getValueOrNothing(paramValMap, inParam, outParamPre, outParamPost);
    if (outStr == "")
        outStr = outStr + outParamPre + std::to_string(defaultInt) + outParamPost;
    return outStr;
}


std::string CUtilParser::cleanBbmlColor(std::string inColor)
{
    std::string outColor = inColor;

    if (inColor.find("#", 0) >= 0)
        inColor.erase(inColor.find("#", 0) + 1, 2);
    return inColor;
}


std::string CUtilParser::buildHtmlStyleFromBBML(int enumtype, BBML_ParamValMap &paramValMap)
{
    std::string outStr = "";

    //Grab Margins if any
    std::string marginX1 = "0";
    std::string marginY1 = "0";
    std::string marginX2 = "0";
    std::string marginY2 = "0";
    bool bHasMargin = getMarginX1Y1X2Y2(getValueOrNothing(paramValMap, "Margin", "", ""), marginX1, marginY1, marginX2, marginY2);

    //Create Style Tag
    if (paramValMap.find("Height") != paramValMap.end())
    {
        outStr = outStr + "height: " + paramValMap.find("Height")->second + "px; ";
    }

    if (paramValMap.find("Width") != paramValMap.end())
    {
        outStr = outStr + "width: " + paramValMap.find("Width")->second + "px; ";
    }

    //Background = "#FFF7F7F7"
    if (paramValMap.find("Background") != paramValMap.end())
    {
        outStr = outStr + "background-color: " + cleanBbmlColor(paramValMap.find("Background")->second) + "; ";
    }

    //x y pos
    if (paramValMap.find("xRelPos") != paramValMap.end())
    {
        outStr = outStr + "left: " + paramValMap.find("xRelPos")->second + "px; ";
    }
    if (paramValMap.find("yRelPos") != paramValMap.end())
    {
        outStr = outStr + "top: " + paramValMap.find("yRelPos")->second + "px; ";
    }

    //handle enums and create enum type
    if (enumtype == 1)
    {
        outStr = outStr + " position: relative;";
    }
    else if (enumtype == 2)
    {
        outStr = outStr + " position: absolute;";
    }

    if (outStr != "")
        outStr = " style=\"" + outStr + "\"";

    return outStr;
}


void CUtilParser::changeParamInt(BBML_ParamValMap &paramValMap, std::string param, int newval, bool adjust)
{
    if (paramExists(paramValMap, param))
    {
        int curval = 0;
        getParamInt(paramValMap, param, curval);
        if (adjust)
            curval += newval;
        else
            curval = newval;

        //find and replace
        BBML_ParamValMap::iterator it = paramValMap.find(param);
        if (it != paramValMap.end())
            it->second = std::to_string(curval);
    }
    else
    {
        std::string value_str = std::to_string(newval);
        paramValMap.insert(BBML_ParamValPair(param, value_str));
    }
}




///////////////////////////////////////////////////////////////////////////////
// scraper ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


//<tagStart>tagContent<tagEnd>
std::string CUtilParser::getTagContent( std::string startTag, std::string endTag, std::string inputline )
{
    std::string outStr = "";
    size_t startPos = 0;
    size_t endPos = 0;

    startPos = inputline.find( startTag, 0 );
    endPos = inputline.find( endTag, startPos);

    if ( (startPos == std::string::npos) || (endPos == std::string::npos) || (startPos >= endPos) )
    {
        //dpUtilLog::outputProgress( "ERROR: No start tag: " + startTag + " \n" );
    }
    else
    {
        outStr = inputline.substr( startPos + startTag.length(), endPos - startPos - startTag.length() );
    }


    return outStr;
}

//<tagStart>tagContent<tagEnd>
int CUtilParser::getTagContentInt( std::string startTag, std::string endTag, std::string inputline )
{
    int intVal = 0;
    std::string strVal = getTagContent( startTag, endTag, inputline );
    if ( strVal != "" )
        intVal = std::stoi( strVal );
    return intVal;
}

//<tagStart>tagContent<tagEnd>
void CUtilParser::findAndReadTag( std::string inputline, std::string tagStart, std::string tagEnd, std::string &tagContent )
{
    size_t startPos = 0;
    size_t endPos = 0;
    tagContent = "";

    //Start Pos
    startPos = inputline.find( tagStart, 0 );

    //End Pos
    if ( startPos != std::string::npos )
    {
        endPos = inputline.find( tagEnd, startPos );
        if ( endPos == std::string::npos )
            endPos = inputline.length();
    }

    //Traverse and build content
    size_t pos = startPos;
    bool bFound = false;
    while ( (startPos != std::string::npos) && (pos < endPos) )
    {
        if ( bFound )
            tagContent += inputline[pos];

        if ( inputline[pos] == '>' )
            bFound = true;
        pos++;
    }
}

//tag=outParam  Number only     - tag input has "=" in it
bool CUtilParser::getNumParamValue( std::string inputline, std::string tag, std::string &outParam )
{
    bool bSuccess = false;
    outParam = "";

    size_t pos = 0;
    pos = inputline.find( tag, 0 );

    if ( pos != std::string::npos )
    {
        bSuccess = true;
        outParam = tag;
        pos = pos + tag.length();
        while ( pos < inputline.length() && (inputline[pos] != '\'') && (inputline[pos] != '\\') && (inputline[pos] != '\"') && (inputline[pos] != '&') )//(inputline[pos] >= '0') && (inputline[pos] <= '9') )
        {
            outParam += inputline[pos];
            pos++;
        }
        //outParam += "\n";
    }
    return bSuccess;
}


//tag="outParam"   returns no quote string
bool CUtilParser::getParamStringEqualQuote( std::string inputline, std::string tag, std::string &outParam )
{
    bool bSuccess = false;
    outParam = "";
    bool firstQuote = false;

    size_t pos = 0;
    pos = inputline.find( tag, 0 );

    if ( pos != std::string::npos )
    {
        bSuccess = true;
        pos = pos + tag.length();
        while ( pos < inputline.length() && ((inputline[pos] != '\"') || (!firstQuote)) )
        {
            if ( !firstQuote )
                firstQuote = inputline[pos] == '\"';
            else
                outParam += inputline[pos];
            pos++;
        }
        //outParam += "\n";
    }
    return bSuccess;
}


bool CUtilParser::parseLineWithDelimiter( std::string linein, std::string delim, std::vector<std::string> &parseVector )
{
    bool bSuccess = true;
    std::string param = "";
    for ( int i = 0; i < linein.length(); i++ )
    {
        if ( std::string(1, linein[i]) == delim)
        {
            parseVector.push_back( param );
            param = "";
        }
        else
            param += linein[i];
    }
    if ( param != "" )
    {
        parseVector.push_back( param );
    }
    return bSuccess;
}
