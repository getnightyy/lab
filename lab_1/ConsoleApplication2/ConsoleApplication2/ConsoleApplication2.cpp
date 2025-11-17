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
    // Trim() для прибирання зайвих пробілів з початку та в кінці рядка

    // Зчитую другий рядок
    Console::Write("Введіть другий рядок: ");
    String^ second = Console::ReadLine()->Trim();

    // Об’єдную рядки в один
    String^ result = first + " " + second;

    Console::WriteLine();
    Console::WriteLine("Об'єднаний рядок: {0}", result);
    return 0;
}
