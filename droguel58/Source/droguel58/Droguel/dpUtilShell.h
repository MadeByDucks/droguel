#pragma once
#include <string>


class dpUtilShell
{
public:
    dpUtilShell( void );
    ~dpUtilShell( void );

    bool runProgram( std::string exec, std::string params );
    bool runProgramShell( std::string exec, std::string params );
    void runCurl( std::string url, std::string outfile );
};

