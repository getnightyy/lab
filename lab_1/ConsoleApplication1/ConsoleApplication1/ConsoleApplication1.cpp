#include "pch.h"
#include "windows.h"
using namespace System;

int main(array<String^>^ args)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Зчитуємо рядок
    Console::Write("Введіть рядок: ");
    String^ input = Console::ReadLine()->Trim();
    // Trim() для прибирання зайвих пробілів з початку та в кінці рядка

    String^ start("begin");
    String^ end1("end");

    String^ result = start + input + end1;
    int length = result->Length; // Length – кількість символів у System::String

    Console::WriteLine();
    Console::WriteLine("Результат: {0}", result);
    Console::WriteLine("Довжина отриманого рядка: {0}", length);

    return 0;
}
