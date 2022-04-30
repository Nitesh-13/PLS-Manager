#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#pragma comment(lib, "Urlmon.lib")

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void downloadArchives(const wchar_t* url1, const wchar_t* url2, const wchar_t* url3, const wchar_t* url4, const wchar_t* file1, const wchar_t* file2, const wchar_t* file3, const wchar_t* file4);
void downloadArchives(const wchar_t* url1, const wchar_t* file1);
void extractArchives(const char* zipUnarc);
void deleteArchives(const char* file1, const char* file2, const char* file3, const char* file4);
void setPathVariable(const char* varPath);

//Programming Languages
void cppSetup();
void javaSetup();
void pythonSetup();

//Code Editors
void atomSetup();
void vscodeSetup();
void sublimeSetup();

#endif