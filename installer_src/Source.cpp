#include <iostream>
#include "functions.h"
using namespace std;

int main(int argc, char** argv)
{
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);
    string argument = argv[1];

    if (argument == "Cpp" || argument == "cpp")
    {
        cppSetup();
    }
    else if (argument == "Java" || argument == "java")
    {
        javaSetup();
    }
    else if (argument == "Python" || argument == "python")
    {
        pythonSetup();
    }
    else if (argument == "Atom" || argument == "atom")
    {
        atomSetup();
    }
    else if (argument == "VSCode" || argument == "vscode")
    {
        vscodeSetup();
    }
    else if (argument == "Sublime" || argument == "sublime")
    {
        sublimeSetup();
    }

    return 0;
}