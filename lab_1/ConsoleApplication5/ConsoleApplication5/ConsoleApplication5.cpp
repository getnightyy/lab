#include "pch.h"
#include "Windows.h"
using namespace System;

int main(array<String^>^ args)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Зчитую перший рядок
	Console::Write("Введіть перший рядок: ");
	String^ first = Console::ReadLine()->Trim();
	// Trim() Для прибирання зайвих пробілів с початку та в кінці рядка

	// Зчитую другий рядок
	Console::Write("Введіть перший рядок: ");
	String^ second = Console::ReadLine()->Trim();

	Console::WriteLine();

	// Визначення довжини рядків
	int lengthFirst = first->Length;
	int lengthSecond = second->Length;

	// Порівняння рядків за довжиною
	if (lengthFirst > lengthSecond)
		Console::WriteLine("Перший рядок довший за другий ({0} > {1}).", lengthFirst, lengthSecond);
	else if (lengthFirst < lengthSecond)
		Console::WriteLine("Другий рядок довший за другий ({0} > {1}).", lengthSecond, lengthFirst);
	else
		Console::WriteLine("Рядки мають однакову довжину ({0} = {1}).", lengthFirst, lengthSecond);

	return 0;
}