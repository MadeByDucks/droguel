#include "dpUtilShell.h"
#include "dpUtilLog.h"
#include "dpUtilString.h"
#include <windows.h> //ShellExecute  //Shell32.lib ShellExecuteExW

//=============================================================================
dpUtilShell::dpUtilShell( void )
{
}


//=============================================================================
dpUtilShell::~dpUtilShell( void )
{
}

bool dpUtilShell::runProgram( std::string exec, std::string params )
{
    bool testPass = true;
    std::string commandLine = exec + " " + params;
    dpUtilLog::outputMessageBox( "runProgram: " + commandLine );
    int result = system( commandLine.c_str() );
    testPass = (result >= 0);
    if ( !testPass )
    {
        dpUtilLog::outputMessageBox( "dpUtilShell::runProgram: FAILED" );
        //GetLastErrorStdStr()
    }
    return testPass;
}

bool dpUtilShell::runProgramShell( std::string exec, std::string params )
{
    bool testPass = true;
    dpUtilLog::outputMessageBox( "runProgramEx: " + exec + " " + params );

    SHELLEXECUTEINFO ExecuteInfo;
    memset( &ExecuteInfo, 0, sizeof( ExecuteInfo ) );

    std::wstring wstr_exec = CUtilString::s2ws( exec );
    LPCWSTR lpcwstr_exec = wstr_exec.c_str();
    LPCSTR lpcstr_exec = exec.c_str();

    std::wstring wstr_params = CUtilString::s2ws( params );
    LPCWSTR lpcwtsr_params = wstr_params.c_str();
    LPCSTR lpcstr_params = params.c_str();

    ExecuteInfo.cbSize = sizeof( SHELLEXECUTEINFO );
    ExecuteInfo.fMask = NULL;
    ExecuteInfo.hwnd = NULL;
    ExecuteInfo.lpVerb = L"open";              //;_T("open");
    ExecuteInfo.lpFile = lpcwstr_exec;        // lpcstr_exec;         // lpcwstr_exec;
    ExecuteInfo.lpParameters = lpcwtsr_params; // lpcstr_params; // lpcwtsr_params;
    ExecuteInfo.lpDirectory = NULL;
    ExecuteInfo.nShow = SW_SHOW; //SW_MAXIMIZE; SW_SHOWNORMAL;// SW_MAXIMIZE; //SW_SHOW; //SW_MAXIMIZE;
    ExecuteInfo.hInstApp = NULL;

    testPass = ShellExecuteEx( &ExecuteInfo );
    if ( !testPass )
    {
        dpUtilLog::outputMessageBox( "dpUtilShell::runProgramShell: FAILED" );
        //GetLastErrorStdStr()
    }

    return testPass;
}

void dpUtilShell::runCurl( std::string url, std::string outfile )
{
    std::string exec = "G:\\curl\\curl-7.59.0-win64-mingw\\bin\\curl.exe";
    std::string params = url + " >> G:\\here\\results.html";
    runProgram( exec, params );
}