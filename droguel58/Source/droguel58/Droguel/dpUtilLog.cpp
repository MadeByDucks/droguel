#include "dpUtilLog.h"
#include <stdio.h>
#include <iostream>
#include <string>



/*
//std::cout << "StressTester Version" << "\n";
//std::cout << "StressTester Version" << "\n";
//std::cout << "StressTester Version" << "\n";

// TRACE("TESTING TRACE");
 std::string tmp = "testind debug testind debug testind debug testind debug";

 std::wostringstream os_;
 os_ << tmp.c_str();
 OutputDebugStringW(os_.str().c_str());

 LOG_DEBUG(main, "TESTING LOGS: ");
 LOG_DEBUG(main, "TESTING LOGS: ");
 LOG_DEBUG(main, "TESTING LOGS: ");
 */



dpUtilLog::dpUtilLog()
{
}


dpUtilLog::~dpUtilLog()
{
}


void dpUtilLog::PressEnterToContinue()
{
    //std::cout << "Press ENTER to continue... " << std::flush;
    //std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    int c;
    printf("Press ENTER to continue... ");
    std::fflush(stdout);
    do c = getchar(); while ((c != '\n') && (c != EOF));
}


void dpUtilLog::outputMessageBox(std::string mesg)
{
    //puts("*********************************************************");
    //puts("*********************************************************");
    //puts(mesg.c_str());
    //puts("*********************************************************");
    //puts("*********************************************************");
    std::cout << "*********************************************************" << std::endl;
    std::cout << "*********************************************************" << std::endl;
    std::cout << mesg << std::endl;
    std::cout << "*********************************************************" << std::endl;
    std::cout << "*********************************************************" << std::endl;
}


void dpUtilLog::outputProgress(std::string mesg)
{
    //puts(mesg.c_str());
    std::cout << mesg;
}


void dpUtilLog::outputProgressLine(std::string mesg)
{
    //puts(mesg.c_str());
    std::cout << mesg << std::endl;
}


void dpUtilLog::outputErrorMessageAndPause(std::string mesg)
{
    //puts("*** ERROR *** ERROR *** ERROR *** ");
    //puts(mesg.c_str());
    std::cout << "*** ERROR *** ERROR *** ERROR *** " << std::endl;
    std::cout << mesg << std::endl;
    PressEnterToContinue();
}
