#include <iostream>
#include <vector>
#include <string>
#include <io.h>
#include <fcntl.h>

#include "FileHandler.h"
#include "Interpreter.h"

int main(int argc, char* argv[])
{
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	std::vector<std::wstring> program;
	unsigned int lineCounter = 1;
	std::wstring userInput = L"";
	int result;

	std::setlocale(LC_ALL, "ukrainian");

	if (argc == 1)
	{
		std::wcout << L"Istoriya\n"
			<< L"����� 1.0\n"
			<< L"(C) 2022 ����� ���������\n"
			<< L"\n"
			<< L"�������������� ���������� ���� �������������, ��� ����������� �����, ������, ����\n"
			<< L"� �������� ��� � ����� ������ XX-XXI ��. � ����� ������.\n"
			<< L"\n";

		return 0;
	}

	ReadDataFromFile(argv[1], &program);

	if (!StartOfTheProgram(&program))
	{
		std::wcout << L"�� ������� ��������? �� �i���� �� ���� ��� ���? I�� ��� i�����!\n";
		return -1;
	}

	ScanForLabels(&program);

	std::srand(std::time(0));

	result = ExecuteCode(&program, &lineCounter, &userInput, ISTORIYA_END);

	while (result < 0)
	{
		if (IsGotoInProgress())
		{
			FinishGoto();
			result = ExecuteCode(&program, &lineCounter, &userInput, ISTORIYA_END);
		}
		else
		{
			ThrowError(L"� ���i �������� �������. ����� ��� i����i�!\n");
			return -1;
		}
	}

	CloseOpenedFiles();

	return 0;
}