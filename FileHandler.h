#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>

void OpenFile(std::string fileName, std::wifstream *wifstream);
void OpenFile(std::wstring fileName, std::wifstream* wifstream);
void OpenFile(std::wstring fileName, std::wofstream* wofstream);

int ReadDataFromFile(std::string fileName, std::vector<std::wstring>* dataContainer);
bool ReadLineFromFile(std::wifstream* wifstream, std::wstring* input);
bool WriteLineToFile(std::wofstream* wofstream, std::wstring output);