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
			<< L"Версія 1.0\n"
			<< L"(C) 2022 Назар Федоренко\n"
			<< L"\n"
			<< L"Інтерпретована езотерична мова програмування, яка використовує факти, терміни, дати\n"
			<< L"з програми ЗНО з історії України XX-XXI ст. в якості команд.\n"
			<< L"\n";

		return 0;
	}

	ReadDataFromFile(argv[1], &program);

	if (!StartOfTheProgram(&program))
	{
		std::wcout << L"Де початок програми? Ти нiчого не знаєш про УЦР? Iди вчи iсторію!\n";
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
			ThrowError(L"У кодi виявлено помилки. Краще вчи iсторiю!\n");
			return -1;
		}
	}

	CloseOpenedFiles();

	return 0;
}