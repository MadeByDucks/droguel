#include "dpUtilDate.h"
#include "dpUtilString.h"
#include <string>
#include <time.h>


//ttdtodo gen calendar settings
//First Day of Week Sat/Sun/Mon
//Hide Sat/Sun
//offset into pattern


CUtilDate::CUtilDate()
{
}


CUtilDate::~CUtilDate()
{
}

std::string CUtilDate::getTimeDateNow()  //datafield
{
    std::string sToday = "invalid";
    struct tm newtime;
    __time64_t long_time;

    _time64(&long_time);  // Get time as 64-bit integer.
    errno_t err = _localtime64_s(&newtime, &long_time);  // Convert to local time.

    std::string year = CUtilString::padStrWithChar(std::to_string(newtime.tm_year + 1900), 4, '0');
    std::string month = CUtilString::padStrWithChar(std::to_string(newtime.tm_mon+1), 2, '0'); //zero based
    std::string day = CUtilString::padStrWithChar(std::to_string(newtime.tm_mday), 2, '0');
    std::string hour = CUtilString::padStrWithChar(std::to_string(newtime.tm_hour), 2, '0');
    std::string minute = CUtilString::padStrWithChar(std::to_string(newtime.tm_min), 2, '0');
    std::string second = CUtilString::padStrWithChar(std::to_string(newtime.tm_sec), 2, '0');

    //"%04i%02i%02i%02i%02i%02i"
    sToday = year + month + day + hour + minute + second;
    return sToday;
}

std::string CUtilDate::getDateTimeStr() //display 
{
    std::string sToday = "invalid";
    struct tm newtime;
    __time64_t long_time;

    _time64(&long_time);  // Get time as 64-bit integer.
    errno_t err = _localtime64_s(&newtime, &long_time);  // Convert to local time.

    std::string year = CUtilString::padStrWithChar(std::to_string(newtime.tm_year + 1900), 4, '0');
    std::string month = CUtilString::padStrWithChar(std::to_string(newtime.tm_mon+1), 2, '0');//zero based
    std::string day = CUtilString::padStrWithChar(std::to_string(newtime.tm_mday), 2, '0');
    std::string hour = CUtilString::padStrWithChar(std::to_string(newtime.tm_hour), 2, '0');
    std::string minute = CUtilString::padStrWithChar(std::to_string(newtime.tm_min), 2, '0');
    std::string second = CUtilString::padStrWithChar(std::to_string(newtime.tm_sec), 2, '0');

    //"%02i/%02i/%04i - %02i:%02i"
    sToday = month + "/" + day + "/" + year + " - " + hour + ":" + minute;
    return sToday;
}

std::string CUtilDate::convertDateTimeDbToSitemap(std::string time)
{
    //20180809112900
    //"2019-10-31T14:24:14+00:00";
    if (time.length() < 14)
    {
        time = getTimeDateNow();
    }
    std::string year   = CUtilString::padStrWithChar(time.substr(0, 4), 4, '0');
    std::string month  = CUtilString::padStrWithChar(time.substr(4, 2), 2, '0');
    std::string day    = CUtilString::padStrWithChar(time.substr(6, 2), 2, '0');
    std::string hour   = CUtilString::padStrWithChar(time.substr(8, 2), 2, '0');
    std::string minute = CUtilString::padStrWithChar(time.substr(10, 2), 2, '0');
    std::string second = CUtilString::padStrWithChar(time.substr(12, 2), 2, '0');

    time = year + '-' + month + "-" + day + "T" + hour + ":" + minute + ":" + second + "+00:00";
    return time;
}

int CUtilDate::CalBlockGetDayWithIndex(int blockIndex, int year, int month)
{
    int day = 0;
    int dow = dayofweek(year, month, 1);

    //june 2014 entire first week is blank
    //if (dow == 0)
    //    dow = 7;

    day = blockIndex - dow + 1;

    //Adjust pre month
    if (day <= 0)
    {
        int premonth = month - 1;
        if (premonth <= 0)
            premonth = 12;

        int test = numDaysInMonth(year, premonth);
        day = numDaysInMonth(year, premonth) + day;
    }

    //Adjust post month
    else if (day > numDaysInMonth(year, month))
    {
        day = day - numDaysInMonth(year, month);
    }

    return day;
}

std::string CUtilDate::CalBlockPattern(int blockIndex, std::string shiftPattern, int offset)
{
    size_t len = shiftPattern.length();
    size_t index = blockIndex % len;

    //adjust with offset
    index = index + offset;
    if (index >= len)
        index = index - len;

    //set retults
    std::string outStr = shiftPattern.substr(index, 1);
    return outStr;
}

std::string CUtilDate::CalBlockTopColorWithIndex(int blockIndex, std::string shiftPattern, int offset)
{
    std::string outColor = "#000000";
    std::string outShift = CalBlockPattern(blockIndex, shiftPattern, offset);

    //Get Color
    if ((outShift == "A") || (outShift == "a") || (outShift == "1"))
        outColor = "#FFEEEE";
    else if ((outShift == "B") || (outShift == "b") || (outShift == "2"))
        outColor = "#EEFFEE";
    else if ((outShift == "C") || (outShift == "c") || (outShift == "3"))
        outColor = "#EEEEFF";
    else
        outColor = "#DDDDDD";

    return outColor;
}

std::string CUtilDate::CalBlockBottomColorWithIndex(int blockIndex, std::string shiftPattern, int offset)
{
    std::string outColor = "#000000";
    std::string outShift = CalBlockPattern(blockIndex, shiftPattern, offset);

    //Get Color
    if ((outShift == "A") || (outShift == "a") || (outShift == "1"))
        outColor = "#FF0000";
    else if ((outShift == "B") || (outShift == "b") || (outShift == "2"))
        outColor = "#00FF00";
    else if ((outShift == "C") || (outShift == "c") || (outShift == "3"))
        outColor = "#0000FF";
    else
        outColor = "#DDDDDD";

    return outColor;
}

std::string CUtilDate::CalBlockTextWithIndex(int blockIndex, std::string shiftPattern, int offset)
{
    std::string outShift = CalBlockPattern(blockIndex, shiftPattern, offset);
    outShift = outShift + " shift"; //"Shift: " + outShift;
    return outShift;
}

int CUtilDate::dayofweek(int y, int m, int d)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

bool CUtilDate::isLeapYear(int year)
{
    //Check if the year is divisible by 4 or is divisible by 400
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int CUtilDate::numDaysInMonth(int year, int month)
{
    int numberOfDays;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        numberOfDays = 30;
    else if (month == 2)
    {
        if (isLeapYear(year))
            numberOfDays = 29;
        else
            numberOfDays = 28;
    }
    else
        numberOfDays = 31;
    return numberOfDays;
}

int CUtilDate::calcDayNumFromDate(int y, int m, int d)
{
    //Calculate day number from date.
    //All division is integer division, operator % is modulus.
    //Given integer y, m, d, calculate day number g as :
    //function g(y, m, d)
    //m = (m + 9) % 12;
    //y = y - m / 10;
    //return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);

    tm date = {};
    date.tm_year = y - 1900;
    date.tm_mon = m - 1;
    date.tm_mday = d;
    mktime(&date);
    int dayNumber = date.tm_yday;
    return dayNumber;
}

void CUtilDate::calcDateFromDayNum(int g, int &y, int &m, int &d)
{
    y = 0;
    m = 0;
    d = 0;

    ////Calculate date from day number
    ////All division is integer division, operator % is modulus.
    ////Given day number g, calculate year, month, and day :
    ////function d(g)
    //y = (10000 * g + 14780) / 3652425;
    //int ddd = g - (365 * y + y / 4 - y / 100 + y / 400);
    //if (ddd < 0)
    //{
    //    y = y - 1;
    //    ddd = g - (365 * y + y / 4 - y / 100 + y / 400);
    //}
    //int mi = (100 * ddd + 52) / 3060;
    //int mm = (mi + 2) % 12 + 1;
    //y = y + (mi + 2) / 12;
    //int dd = ddd - (mi * 306 + 5) / 10 + 1;
    //
    ////return y, mm, dd
    //m = mm;
    //d = dd;
}




std::string CUtilDate::getNextDay(std::string date_str)  //yyyymmddhhmmss
{
    std::string year   = date_str.substr(0, 4);
    std::string month  = date_str.substr(4, 2);
    std::string day    = date_str.substr(6, 2);
    std::string hour   = date_str.substr(8, 2);
    std::string minute = date_str.substr(10, 2);
    std::string second = date_str.substr(12, 2);

    int year_num = atoi(year.c_str());
    int month_num = atoi(month.c_str());
    int day_num = atoi(day.c_str());

    day_num++;

    int days_in_month = numDaysInMonth(year_num, month_num);

    if (day_num > days_in_month)
    {
        day_num = 1;
        month_num++;
    }

    if (month_num > 12)
    {
        month_num = 1;
        year_num++;
    }

    year = std::to_string(year_num);
    month = std::to_string(month_num);
    day = std::to_string(day_num);

    if (month.length() == 1)
    {
        month = "0" + month;
    }

    if (day.length() == 1)
    {
        day = "0" + day;
    }

    return year + month + day + hour + minute + second;
}
