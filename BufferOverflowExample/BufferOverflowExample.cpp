#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
//#include <cstring>

inline bool file_exists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

void exploitable(const char* p, int len)
{
    //char nops[]{ 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
    char buffer[700];
    memcpy(buffer, p, len);
}

int main()
{
    std::string inputFile = "";
    std::string inputText = "";

    std::cout << "Please enter filename:\n";
    std::cin >> inputFile;

    bool fileExists = file_exists(inputFile);

    if (fileExists == true) {
        std::ifstream t(inputFile);
        std::string str((std::istreambuf_iterator<char>(t)),
            std::istreambuf_iterator<char>());
        inputText = str;
    }
    else{
        std::cout << "File does not exist\n";
        std::cin >> inputFile;
        return 0;
    }

    exploitable(inputText.c_str(), inputText.size());
    std::cin >> inputText;

    return 0;
}