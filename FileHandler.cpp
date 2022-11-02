#include "FileHandler.h"

void OpenFile(std::string fileName, std::wifstream *wifstream)
{
	wifstream->open(fileName);
	wifstream->imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
}

void OpenFile(std::wstring fileName, std::wifstream* wifstream)
{
	wifstream->open(fileName);
	wifstream->imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
}

void OpenFile(std::wstring fileName, std::wofstream* wofstream)
{
	wofstream->open(fileName);
	wofstream->imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
}

int ReadDataFromFile(std::string fileName, std::vector<std::wstring>* dataContainer)
{	
	std::wstring line;
	std::wifstream file;
	OpenFile(fileName, &file);

	while (!file.fail())
	{
		std::getline(file, line);
		dataContainer->emplace_back(line);
	}
	dataContainer->pop_back();

	file.close();

	return 0;
}

bool ReadLineFromFile(std::wifstream* wifstream, std::wstring* input)
{
	std::wstring line;

	if (wifstream->fail())
	{
		std::wcout << L"Помилка читання файлу!\n";
		return false;
	}

	std::getline(*wifstream, line);
	(*input) = line;

	return true;
}

bool WriteLineToFile(std::wofstream* wofstream, std::wstring output)
{
	std::wstring line;

	(*wofstream) << output;

	return true;
}
