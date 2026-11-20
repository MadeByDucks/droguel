#pragma once

#include <string>

class CUtilDate
{
public:
    CUtilDate();
    ~CUtilDate();

    static std::string getTimeDateNow();
    static std::string getDateTimeStr();
    static std::string convertDateTimeDbToSitemap(std::string time);

    //Calendar Block Shift Controls
    int CalBlockGetDayWithIndex(int blockIndex, int year, int month);    
    std::string CalBlockPattern(int blockIndex, std::string shiftPattern, int offset);
    std::string CalBlockTopColorWithIndex(int blockIndex, std::string shiftPattern, int offset);
    std::string CalBlockBottomColorWithIndex(int blockIndex, std::string shiftPattern, int offset);
    std::string CalBlockTextWithIndex(int blockIndex, std::string shiftPattern, int offset);

    //general
    int dayofweek(int y, int m, int d);
    static bool isLeapYear(int year);
    static int numDaysInMonth(int year, int month);
    static int calcDayNumFromDate(int y, int m, int d);
    void calcDateFromDayNum(int g, int &y, int &m, int &d);

    static std::string getNextDay(std::string date_str);  //yyyymmddhhmmss
};

