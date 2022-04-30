#include "functions.h"

//multifile downloading
void downloadArchives(const wchar_t* url1, const wchar_t* url2, const wchar_t* url3, const wchar_t* url4, const wchar_t* file1, const wchar_t* file2, const wchar_t* file3, const wchar_t* file4)
{
    URLDownloadToFileW(NULL, url1, file1, 0, NULL);
    URLDownloadToFileW(NULL, url2, file2, 0, NULL);
    URLDownloadToFileW(NULL, url3, file3, 0, NULL);
    URLDownloadToFileW(NULL, url4, file4, 0, NULL);
}

//single file downloading
void downloadArchives(const wchar_t* url1, const wchar_t* file1)
{
    URLDownloadToFileW(NULL, url1, file1, 0, NULL);
}

void extractArchives(const char* zipUnarc)
{
    system(zipUnarc);
}

void deleteArchives(const char* file1, const char* file2, const char* file3, const char* file4)
{
    remove(file1);
    remove(file2);
    remove(file3);
    remove(file4);
}

void setPathVariable(const char* varPath)
{
    system(varPath);
}


//Programming Languages
void cppSetup()
{
    const wchar_t* url1 = L"https://dl.dropboxusercontent.com/s/wan2bnsqo0dmz6b/MinGW.part02.rar";
    const wchar_t* url2 = L"https://dl.dropboxusercontent.com/s/wjby7k69qg4e3t3/MinGW.part03.rar";
    const wchar_t* url3 = L"https://dl.dropboxusercontent.com/s/0688dk6plv1rurj/MinGW.part04.rar";
    const wchar_t* url4 = L"https://dl.dropboxusercontent.com/s/0s2rex7xcj0x0q9/MinGW.part01.exe";

    const wchar_t* file1 = L"C:\\MinGW\\MinGW.part02.rar";
    const wchar_t* file2 = L"C:\\MinGW\\MinGW.part03.rar";
    const wchar_t* file3 = L"C:\\MinGW\\MinGW.part04.rar";
    const wchar_t* file4 = L"C:\\MinGW\\MinGW.part01.exe";

    const char* File1 = "C:\\MinGW\\MinGW.part02.rar";
    const char* File2 = "C:\\MinGW\\MinGW.part03.rar";
    const char* File3 = "C:\\MinGW\\MinGW.part04.rar";
    const char* File4 = "C:\\MinGW\\MinGW.part01.exe";

    const char* varPath = "setx /M path \"%path%;C:\\MinGW\\bin\"";

    int createDir = system("mkdir C:\\MinGW");
    if (createDir == 1)
    {
        system("rd /s /q C:\\MinGW");
        system("mkdir C:\\MinGW");
    }
    downloadArchives(url1, url2, url3, url4, file1, file2, file3, file4);
    extractArchives(File4);
    deleteArchives(File1, File2, File3, File4);
    setPathVariable(varPath);
}

void javaSetup()
{
    const wchar_t* url1 = L"https://dl.dropboxusercontent.com/s/bc3emo0x96ilon4/JDK.part2.rar";
    const wchar_t* url2 = L"https://dl.dropboxusercontent.com/s/q6etu79evl97vmo/JDK.part3.rar";
    const wchar_t* url3 = L"https://dl.dropboxusercontent.com/s/6sms5a2nepzxchy/JDK.part4.rar";
    const wchar_t* url4 = L"https://dl.dropboxusercontent.com/s/kmhyartw2nwwn14/JDK.part1.exe";

    const wchar_t* file1 = L"C:\\Program Files\\Java\\JDK.part2.rar";
    const wchar_t* file2 = L"C:\\Program Files\\Java\\JDK.part3.rar";
    const wchar_t* file3 = L"C:\\Program Files\\Java\\JDK.part4.rar";
    const wchar_t* file4 = L"C:\\Program Files\\Java\\JDK.part1.exe";

    const char* File1 = "C:\\Program Files\\Java\\JDK.part2.rar";
    const char* File2 = "C:\\Program Files\\Java\\JDK.part3.rar";
    const char* File3 = "C:\\Program Files\\Java\\JDK.part4.rar";
    const char* File4 = "C:\\Program Files\\Java\\JDK.part1.exe";

    const char* varPath = "setx /M path \"%path%;C:\\Program Files\\Java\\jdk-17.0.1\\bin\"";

    int createDir = system("mkdir \"C:\\Program Files\\Java\"");
    if (createDir == 1)
    {
        system("rd /s /q C:\\Program Files\\Java");
        system("mkdir \"C:\\Program Files\\Java\"");
    }
    downloadArchives(url1, url2, url3, url4, file1, file2, file3, file4);
    extractArchives(File4);
    deleteArchives(File1, File2, File3, File4);
    setPathVariable(varPath);
}

void pythonSetup()
{
    const wchar_t* url1 = L"https://dl.dropboxusercontent.com/s/hykq4jvzupwklhy/python.exe";
    const wchar_t* file1 = L"C:\\Python\\python.exe";

    const char* File1 = "C:\\Python\\python.exe";

    int createDir = system("mkdir C:\\Python");
    if (createDir == 1)
    {
        system("rd /s /q C:\\Python");
        system("mkdir C:\\Python");
    }

    downloadArchives(url1, file1);
    extractArchives(File1);
    system("rd /s /q C:\\Python");
}

//Code Editors

void atomSetup()
{
    const wchar_t* url1 = L"https://dl.dropboxusercontent.com/s/cvx8wsv2y7f9uyv/atom.exe";
    const wchar_t* file1 = L"C:\\editors\\atom.exe";

    const char* File1 = "C:\\editors\\atom.exe";

    int createDir = system("mkdir C:\\editors");
    if (createDir == 1)
    {
        system("rd /s /q C:\\editors");
        system("mkdir C:\\editors");
    }
    downloadArchives(url1, file1);
    extractArchives(File1);
    system("rd /s /q C:\\editors");
}

void vscodeSetup()
{
    const wchar_t* url1 = L"https://dl.dropboxusercontent.com/s/d1d2luglauj3680/vscode.exe";
    const wchar_t* file1 = L"C:\\editors\\vscode.exe";

    const char* File1 = "C:\\editors\\vscode.exe";

    int createDir = system("mkdir C:\\editors");
    if (createDir == 1)
    {
        system("rd /s /q C:\\editors");
        system("mkdir C:\\editors");
    }
    downloadArchives(url1, file1);
    extractArchives(File1);
    system("rd /s /q C:\\editors");
}

void sublimeSetup()
{
    const wchar_t* url1 = L"https://dl.dropboxusercontent.com/s/zpp56tcoy59kvps/sublime.exe";
    const wchar_t* file1 = L"C:\\editors\\sublime.exe";

    const char* File1 = "C:\\editors\\sublime.exe";

    int createDir = system("mkdir C:\\editors");
    if (createDir == 1)
    {
        system("rd /s /q C:\\editors");
        system("mkdir C:\\editors");
    }
    downloadArchives(url1, file1);
    extractArchives(File1);
    system("rd /s /q C:\\editors");
}