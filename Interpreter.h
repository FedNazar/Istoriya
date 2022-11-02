#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <chrono>
#include <thread>

#include "FileHandler.h"

#define ISTORIYA_BEGIN L"1 серпня 1914 р. - утворення Головної Української Ради, головою якої став Кость Левицький."

#define ISTORIYA_BLANK L""

#define ISTORIYA_PRINT L"6 (19) квітня 1917 р. - відкриття Українського національного конгресу в Києві."
#define ISTORIYA_END_OF_STRING L"Останній день Українського національного конгресу присвятили виборам нового складу Центральної Ради."

#define ISTORIYA_START_FOR_LOOP L"Грудень 1917 р. - березень 1918 рр. - перша війна рсфрр і УНР."
#define ISTORIYA_END_FOR_LOOP L"9 (22) січня 1918 р. - видано Четвертий Універсал УЦР та проголошено УНР."
#define ISTORIYA_BREAK_FOR_LOOP L"18 лютого 1918 р. розпочався наступ армії Четверного союзу та військ УНР проти більшовиків."

#define ISTORIYA_REQUEST_USER_INPUT L"15 (28) червня 1917 р. - створено Генеральний секретаріат УЦР, який очолив Володимир Винниченко."

#define ISTORIYA_IF_STATEMENT L"27 січня (9 лютого) 1918 р. - ухвалено Брестський мирний договір між УНР та Четверного союзу."
#define ISTORIYA_ELSEIF_STATEMENT L"Сторони відмовлялися від взаємних претензій щодо відшкодування завданих війною збитків."
#define ISTORIYA_ELSE_STATEMENT L"Зобов'язання УНР: постачати продовольство Німеччині та Австро-Угорщині."
#define ISTORIYA_END_IF_STATEMENT L"Наслідок Брестського мирного договору: звільнення території УНР від більшовиків."

#define ISTORIYA_DELAY L"Період «застою» - передостанній період існування радянського режиму (середина 60-х - початок 80-х рр. ХХ ст.)."
#define ISTORIYA_CLEAR_SCREEN L"«Випалена земля» - метод ведення війни за допомогою знищення всього корисного на території, яку може зайняти противник. Використовувалася радянськими та німецькими військами."

#define ISTORIYA_RANDOM_CHAR L"Референдум - прийняття електоратом рішення з політичних питань."

#define ISTORIYA_LABEL L"«Поліська Січ» - перша українська повстанська формація, що діяла під Другої світової війни під орудою Тараса Бульби-Боровця."
#define ISTORIYA_GOTO L"«Похідні групи» були створені ОУН зі свідомих українців на українських землях органів місцевого самоврядування під час Другої світової війни."

#define ISTORIYA_FILE_OPEN_READ L"Українська національна партія (жовтень 1989 р.) - Львів, нечисленна."
#define ISTORIYA_FILE_OPEN_WRITE L"Українська республіканська партія (квітень 1990 р.) - Київ."
#define ISTORIYA_FILE_READ_LINE L"Українська хритиянсько-демократична партія (квітень 1990 р.) - Львів."
#define ISTORIYA_FILE_WRITE_LINE L"Ліберально-демократична партія (червня 1990 р.) - Київ."

#define ISTORIYA_END L"24 серпня 2022 р. - 31-й День Незалежності України."

bool StartOfTheProgram(std::vector<std::wstring>* program);
void ScanForLabels(std::vector<std::wstring>* program);
int ExecuteCode(std::vector<std::wstring>* program, unsigned int* lineCounter, 
	std::wstring* userInput, std::wstring endKeyPhrase);
bool Print(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput);
std::wstring GetUserInput();
std::wstring ReadStringValue(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput);
int IfStatement(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput, std::wstring stringToCompare);
void Delay(uint8_t seconds);
void ClearScreen();
bool ForLoop(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput, uint8_t times);
wchar_t GetRandomChar(std::vector<std::wstring>* program, unsigned int* lineCounter,
	std::wstring* userInput);
bool GotoLabel(wchar_t label, std::unordered_map<wchar_t, unsigned int>* labels, 
	unsigned int* lineCounter);
void ThrowError(std::wstring error);
bool IsGotoInProgress();
void FinishGoto();

void CloseOpenedFiles();