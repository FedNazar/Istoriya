#include "Interpreter.h"

std::unordered_map<std::wstring, wchar_t> istoriya_char_table =
{
	{L"Автокефальна церква - православна церква, яка має цілковиту самостійність у розв'язанні організаційних і культових питань." , L'А'},
	{L"Бандерівці - члени ОУН(Б), того її крила самостійників-державників, яке очолював Степан Бандера." , L'Б'},
	{L"Український визвольний рух - національно-визвольний рух на етнічних українських землях у 20-50-х рр. ХХ ст." , L'В'},
	{L"Генеральний секретаріат - виконавчий орган, створений за рішенням Малої Ради від 15 червня 1917 р." , L'Г'},
	{L"Гласність - ліквідація цензури в СРСР М.Горбачовим, складова проголошеної ним програми реформ." , L'Ґ'},
	{L"Дисидент - учасник руху, спрямованого проти комуністичного тоталітарного режиму." , L'Д'},
	{L"Евакуація - організоване вивезення людей, підприємств, установ та матеріальних цінностей з небезпечної місцевості під час війни." , L'Е'},
	{L"Євген Петрушевич - державний і політичний діяч, один із керівників Української революції 1917-1920 рр." , L'Є'},
	{L"Андрій Жук - громадський і політичний діяч, публіцист, кооператор, член РУП та УСДРП (1901-1911)." , L'Ж'},
	{L"9 листопада 1918 р. - утворено Західноукраїнську Народну Республіку (ЗУНР)." , L'З'},
	{L"Вільгельм Франц фон Габсбург-Лотаринген (Василь Вишиваний) - австрійський архікнязь, полковник Українських січових стрільців, поет." , L'И'},
	{L"Іван Багряний - публіцист, письменник, політичний діяч. Належав до літературної організації письменників Києва «МАРС»." , L'І'},
	{L"Українська Центральна Рада - провідник українського національно-визвольного руху." , L'Ї'},
	{L"Йосип Сліпий - митрополит Української греко-католицької церкви (3 1944 р.)." , L'Й'},
	{L"Курултай - орган громадського кримськотатарського національного руху, утворений 26 листопада (9 грудня) 1917 р." , L'К'},
	{L"Лібералізація (за «відлиги») - курс на пом'якшення політичного режиму." , L'Л'},
	{L"Мобілізація - комплекс заходів, спрямованих на переведення країни у воєнний стан." , L'М'},
	{L"Націонал-ухильництво - ідеологічний штамп, що вживався в агітаційно-пропагандистській роботі в СРСР." , L'Н'},
	{L"Олесь Гончар - письменник, громадський діяч, академік, автор трилогії «Прапороносці»." , L'О'},
	{L"Помаранчева революція - сукупність протестів та інших актів громадянської непокори на підтримку Віктора Ющенка." , L'П'},
	{L"Русинство - соціально-політична течія, що виникла на Закарпатті й прихильники якої обстоювали ідею, слов'янське населення тут відмінне від українців." , L'Р'},
	{L"Соборність - ідея об'єднання в одне державне утворення всіх етнічно-історичних українських земель." , L'С'},
	{L"Тимчасово окупована територія - частина території України, яка контролюється росією." , L'Т'},
	{L"10 (23) червня 1917 р. - Перший Універсал Української Центральної Ради." , L'У'},
	{L"Володимир Філатов - офтальмолог і хірург, засновник відомої офтальмологічної школи." , L'Ф'},
	{L"Холодноярська республіка - героїчна сторінка боротьби за незалежність України в 1919-1922 рр. Повстанський селянський рух здебільшого охоплював Чигиринський повіт Київської губернії." , L'Х'},
	{L"Олександр Богомолець - видатний учений-патофізіолог, державний і громадський діяч, організатор науки." , L'Ц'},
	{L"Чортківська офензива - найуспішніша наступальна операція Української галицької армії, проведена 7-28 червня 1919 р." , L'Ч'},
	{L"Шістдесятники - представники української літературно-мистецької та суспільно-політичної течій наприкінці 50-х - на початку 70-х рр. ХХ ст." , L'Ш'},
	{L"Отаманщина - явище, що зародилося в Армії УНР наприкінці 1918 р. під час антигетьманського повстання." , L'Щ'},
	{L"Тіньова економіка - господарська діяльність, яка відбувається поза офіційним (державним) обліком і контролем." , L'Ь'},
	{L"Віктор Ющенко - Президент України (2005-2010)." , L'Ю'},
	{L"Ярослав Стецько - діяч українського національно-визвольного руху, член ОУН (з 1932 р.)." , L'Я'},
	{L"Вересень 2014 р., лютий 2015 р. - Мінські угоди." , L' '},
	{L"Грудень 1919 р. - травень 1920 р. - Перший зимовий похід Армії УНР." , L'('},
	{L"Листопад 1921 р. - Другий зимовий похід Армії УНР." , L')'},
	{L"Михайло Волобуєв - вчений-економіст, автор статті «До проблеми української економіки (1928)»." , L':'},
	{L"Самвидав - тексти, виготовлені й поширені з метою висловлення протесту проти придушення свободи слова радянською владою." , L','},
	{L"Тамвидав - видання книги вітчизняного автора за кордоном, переважно в радянські часи." , L';'},
	{L"Експропріація - примусове відчуження приватної власності." , L'-'},
	{L"Корупція - негативне суспільне явище, яке проявляється у злочинному використанні громадськими і політичними діячами їхніх прав для особистого збагачення." , L'.'},
	{L"В'ячеслав Чорновіл - учасник дисидентського руху із середини 60-х років ХХ ст." , L'`'},
	{L"24 серпня 1991 р. - ухвалення Акта проголошення незалежності України." , L'!'},
	{L"3 (16) липня 1917 р. - Другий Універсал Української Центральної Ради." , L'?'},
	{L"«Червоний терор» - заходи насильства, що їх вживали більшовики проти широких соціальних груп." , L'*'},
	{L"Під час індустріалізації в Україні було побудовано 12 промислових гігантів." , L'+'},
	{L"22 січня 1919 р. - проголошення Акта Злуки УНР і ЗУНР." , L'='},
	{L"Вересень 1996 р. - в обіг запроваджено гривню." , L'₴'},
	{L"Середньорічні темпи зростання капіталовкладень у народне господарство України знизилися 3 6,8% до 6,4% у 9-ій п`ятирічці." , L'%'},
	{L"2004 р. Янукович отримав курячим яйцем по морді." , L'№'},
	{L"1970-1972 рр. - вихід друком самвидавного «Українського вісника»." , L'"'},
	{L"Реабілітація - поновлення доброго імені, репутації несправедливо звинуваченої людини." , L'/'},
	{L"Політичною реабілітацією вважають винесення виправдовувального вироку під час перегляду справи із безпідставними звинуваченнями." , L'\x005C'}, // Зворотня похила риска
	{L"Першим судовим процесом проти української гуманітарної інтелігенції став розгляд справи «Спілки визволення України» (1930)." , L'|'},
	{L"Казимир Малевич - український художник-авангардист, один із фундаторів кубофутуризму." , L'█'},
	{L"Колективізація сільського господарства - процес докорінної перебудови аграрного сектора, ініційований більшовиками наприкінці 20-х років ХХ ст." , L'▓'},
	{L"16 липня 1990 р. - ухвалення Декларації про державний сувернітет України." , L'0'},
	{L"Леонід Кравчук - Перший Президент України (1991-1994)." , L'1'},
	{L"Грудень 1942 р. - початок вигнання німецьких окупантів із території України." , L'2'},
	{L"1923 р. - саморозпуск уряду ЗУНР." , L'3'},
	{L"1914 р. - Галицька битва." , L'4'},
	{L"1915 р. - утворення Загальної Української Ради (ЗУР)." , L'5'},
	{L"28 червня 1996 р. - ухвалення Конституції України." , L'6'},
	{L"17 вересня 1939 р. - вторгнення червоної армії на територію Західної України." , L'7'},
	{L"2008 р. - вступ України до Світової організації торгівлі (СОТ)." , L'8'},
	{L"1959 р. - утворення Української робітничо-селянської спілки." , L'9'},
	{L"Жовтень 1990 р. - Революція на граніті.", L'\n'}
};

std::unordered_map<std::wstring, uint8_t> istoriya_num_table =
{
	{L"16 липня 1990 р. - ухвалення Декларації про державний сувернітет України." , 0},
	{L"Леонід Кравчук - Перший Президент України (1991-1994)." , 1},
	{L"Грудень 1942 р. - початок вигнання німецьких окупантів із території України." , 2},
	{L"1923 р. - саморозпуск уряду ЗУНР." , 3},
	{L"1914 р. - Галицька битва." , 4},
	{L"1915 р. - утворення Загальної Української Ради (ЗУР)." , 5},
	{L"28 червня 1996 р. - ухвалення Конституції України." , 6},
	{L"17 вересня 1939 р. - вторгнення червоної армії на територію Західної України." , 7},
	{L"2008 р. - вступ України до Світової організації торгівлі (СОТ)." , 8},
	{L"1959 р. - утворення Української робітничо-селянської спілки." , 9}
};

std::unordered_map<wchar_t, unsigned int> labels;

std::wifstream readFile;
std::wofstream writeFile;

bool gotoInProgress = false;

bool StartOfTheProgram(std::vector<std::wstring>* program)
{
    return (*program)[0] == ISTORIYA_BEGIN;
}

void ScanForLabels(std::vector<std::wstring>* program)
{
	for (unsigned int line = 0; line < program->size(); line++)
	{
		if ((*program)[line] == ISTORIYA_LABEL)
		{
			labels[istoriya_char_table[(*program)[line + 1]]] = line + 1;
		}
	}
}

int ExecuteCode(std::vector<std::wstring>* program, unsigned int* lineCounter, 
	std::wstring* userInput, std::wstring endKeyPhrase)
{
	std::wstring codeLine;

	codeLine = (*program)[*lineCounter];

	while (codeLine != endKeyPhrase)
	{
		if (*lineCounter == program->size() - 1 && codeLine != endKeyPhrase)
		{
			std::wcout << L"Де кiнець програми?\n";
			return -1;
		}

		if (endKeyPhrase == ISTORIYA_END_IF_STATEMENT)
		{
			if (codeLine == ISTORIYA_ELSE_STATEMENT ||
				codeLine == ISTORIYA_ELSEIF_STATEMENT)
			{
				return 1;
			}
			if (codeLine == ISTORIYA_BREAK_FOR_LOOP)
			{
				return 2;
			}
		}
		else if (endKeyPhrase == ISTORIYA_END_FOR_LOOP)
		{
			if (codeLine == ISTORIYA_BREAK_FOR_LOOP)
			{
				return 1;
			}
		}

		if (codeLine == ISTORIYA_BLANK)
		{

		}
		else if (codeLine == ISTORIYA_PRINT)
		{
			if (!Print(program, lineCounter, userInput))
			{
				ThrowError(L"Не можу вивести текст. Iсторiю краще читай!\n");
				return -2;
			}
		}
		else if (codeLine == ISTORIYA_LABEL)
		{
			(*lineCounter)++;
		}
		else if (codeLine == ISTORIYA_CLEAR_SCREEN)
		{
			ClearScreen();
		}
		else if (codeLine == ISTORIYA_DELAY)
		{
			(*lineCounter)++;
			Delay(istoriya_num_table[(*program)[*lineCounter]]);
		}
		else if (codeLine == ISTORIYA_REQUEST_USER_INPUT)
		{
			(*userInput) = GetUserInput();
		}
		else if (codeLine == ISTORIYA_GOTO)
		{
			if (!GotoLabel(istoriya_char_table[(*program)[*lineCounter+1]], 
				&labels, lineCounter))
			{
				return -6;
			}
		}
		else if (codeLine == ISTORIYA_START_FOR_LOOP)
		{
			(*lineCounter)++;
			if (!ForLoop(program, lineCounter, userInput, istoriya_num_table[(*program)[*lineCounter]]))
			{
				ThrowError(L"Є проблеми iз FOR-петлею, тому що, мабуть, ти iсторiю погано читав(читала)!\n");
				return -5;
			}
		}
		else if (codeLine == ISTORIYA_IF_STATEMENT)
		{
			(*lineCounter)++;
			std::wstring stringToCompare = ReadStringValue(program, lineCounter, userInput);
			int ifResult = IfStatement(program, lineCounter, userInput, stringToCompare);

			if (ifResult == -1)
			{
				return -3;
			}
			else if (ifResult == 2)
			{
				return 1;
			}
		}
		else if (codeLine == ISTORIYA_FILE_READ_LINE)
		{
			if (!ReadLineFromFile(&readFile, userInput))
			{
				return -8;
			}
		}
		else if (codeLine == ISTORIYA_FILE_WRITE_LINE)
		{
			std::wstring lineToWrite;

			(*lineCounter)++;

			lineToWrite = ReadStringValue(program, lineCounter, userInput);
			if (lineToWrite != L"ERROR")
			{
				if (!WriteLineToFile(&writeFile, lineToWrite))
				{
					return -9;
				}
			}
			else
			{
				ThrowError(L"Що це за назва файлу така?\n");
				return -7;
			}
		}
		else if (codeLine == ISTORIYA_FILE_OPEN_READ)
		{
			std::wstring fileName;

			(*lineCounter)++;

			fileName = ReadStringValue(program, lineCounter, userInput);
			if (fileName != L"ERROR")
			{
				OpenFile(fileName, &readFile);
			}
			else
			{
				ThrowError(L"Що це за назва файлу така?\n");
				return -7;
			}
		}
		else if (codeLine == ISTORIYA_FILE_OPEN_WRITE)
		{
			std::wstring fileName;

			(*lineCounter)++;

			fileName = ReadStringValue(program, lineCounter, userInput);
			if (fileName != L"ERROR")
			{
				OpenFile(fileName, &writeFile);
			}
			else
			{
				ThrowError(L"Що це за назва файлу така?\n");
				return -7;
			}
		}
		else
		{
			ThrowError(L"Що це за функцiя така? Iсторiю взагалi знаєш?\n");
			return -4;
		}

		(*lineCounter)++;
		codeLine = (*program)[*lineCounter];
	}

	return 0;
}

bool Print(std::vector<std::wstring>* program, unsigned int* lineCounter, std::wstring* userInput)
{
	std::wstring string;

	(*lineCounter)++;

	string = ReadStringValue(program, lineCounter, userInput);
	if (string != L"ERROR")
	{
		std::wcout << string;
		return true;
	}
	else
	{
		return false;
	}
}

std::wstring GetUserInput()
{
	std::wstring input;

	std::getline(std::wcin, input);

	return input;
}

std::wstring ReadStringValue(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput)
{
	std::wstring string = L"";
	wchar_t wchar;

	while ((*program)[*lineCounter] != ISTORIYA_END_OF_STRING)
	{
		if (*lineCounter == program->size() - 1 &&
			(*program)[*lineCounter] != ISTORIYA_END_OF_STRING)
		{
			ThrowError(L"Де кiнець тексту?\n");
			return L"ERROR";
		}

		if ((*program)[*lineCounter] == ISTORIYA_REQUEST_USER_INPUT)
		{
			string = *userInput;
			return string;
		}

		if ((*program)[*lineCounter] == ISTORIYA_RANDOM_CHAR)
		{
			wchar = GetRandomChar(program, lineCounter, userInput);
			if (wchar != NULL)
			{
				string += wchar;
				(*lineCounter)++;
				continue;
			}
			else
			{
				ThrowError(L"Помилка випадкових чисел\n");
				return L"ERROR";
			}
		}

		wchar = istoriya_char_table[(*program)[*lineCounter]];
		if (wchar != NULL)
		{
			string += wchar;
			(*lineCounter)++;
		}
		else
		{
			ThrowError(L"Що це за незрозумiлий символ?\n");
			return L"ERROR";
		}
	}

	return string;
}

int IfStatement(std::vector<std::wstring>* program, unsigned int* lineCounter, 
	std::wstring* userInput, std::wstring stringToCompare)
{
	if (*userInput == stringToCompare || L"ELSE" == stringToCompare)
	{
		(*lineCounter)++;
		int codeBranchResult =
			ExecuteCode(program, lineCounter, userInput, ISTORIYA_END_IF_STATEMENT);

		if (codeBranchResult < 0)
		{
			ThrowError(L"Є проблеми з кодом в IF-розгалуженнi. Iсторiю краще читай!\n");
			return -1;
		}
		else if (codeBranchResult == 2)
		{
			return 2;
		}
		else
		{
			std::wstring codeLine = (*program)[*lineCounter];
			while (codeLine != ISTORIYA_END_IF_STATEMENT)
			{
				(*lineCounter)++;
				codeLine = (*program)[*lineCounter];
			}
		}

		return 0;
	}
	else
	{
		(*lineCounter)++;
		std::wstring codeLine = (*program)[*lineCounter];

		while (codeLine != ISTORIYA_END_IF_STATEMENT)
		{
			(*lineCounter)++;
			codeLine = (*program)[*lineCounter];

			if (codeLine == ISTORIYA_ELSE_STATEMENT)
			{
				return IfStatement(program, lineCounter, userInput, L"ELSE");
			}
			else if (codeLine == ISTORIYA_ELSEIF_STATEMENT)
			{
				(*lineCounter)++;
				std::wstring newStringToCompare = ReadStringValue(program, lineCounter, userInput);
				return IfStatement(program, lineCounter, userInput, newStringToCompare);
			}
		}

		return 1;
	}
}

void Delay(uint8_t seconds)
{
	if (seconds == 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
	}
	else
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
	}
}

void ClearScreen()
{
	// Я знаю, що це погано.
	std::system("cls");
}

bool ForLoop(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput, uint8_t times)
{
	(*lineCounter)++;

	int codeBranchResult;
	unsigned int startPosition = *lineCounter;

	if (times == 0)
	{
		while (1)
		{
			codeBranchResult =
				ExecuteCode(program, lineCounter, userInput, ISTORIYA_END_FOR_LOOP);

			if (codeBranchResult < 0)
			{
				return false;
			}
			else if (codeBranchResult == 1)
			{
				while ((*program)[*lineCounter] != ISTORIYA_END_FOR_LOOP)
				{
					(*lineCounter)++;
				}
				break;
			}

			*lineCounter = startPosition;
		}
		return true;
	}
	else
	{
		for (uint8_t i = 0; i < times; i++)
		{
			codeBranchResult =
				ExecuteCode(program, lineCounter, userInput, ISTORIYA_END_FOR_LOOP);

			if (codeBranchResult < 0)
			{
				return false;
			}
			else if (codeBranchResult == 1)
			{
				while ((*program)[*lineCounter] != ISTORIYA_END_FOR_LOOP)
				{
					(*lineCounter)++;
				}
				break;
			}

			if (i != times - 1)
			{
				*lineCounter = startPosition;
			}
		}
		return true;
	}
}

wchar_t GetRandomChar(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput)
{
	(*lineCounter)++;
	std::wstring possibleValues = ReadStringValue(program, lineCounter, userInput);

	if (possibleValues == L"ERROR")
	{
		return L'\0';
	}

	return possibleValues[(std::rand() % possibleValues.size())];
}

bool GotoLabel(wchar_t label, std::unordered_map<wchar_t, unsigned int>* labels, 
	unsigned int* lineCounter)
{
	unsigned int codeLocation = (*labels)[label];
	
	if (codeLocation == 0)
	{
		ThrowError(L"Неправильна мітка! Вчи iсторію!\n");
		return false;
	}

	(*lineCounter) = codeLocation+1;
	gotoInProgress = true;
	return false;
}

void ThrowError(std::wstring error)
{
	if (!gotoInProgress)
	{
		std::wcout << error;
	}
}

bool IsGotoInProgress()
{
	return gotoInProgress;
}

void FinishGoto()
{
	gotoInProgress = false;
}

void CloseOpenedFiles()
{
	if (readFile.is_open())
	{
		readFile.close();
	}

	if (writeFile.is_open())
	{
		writeFile.close();
	}
}

