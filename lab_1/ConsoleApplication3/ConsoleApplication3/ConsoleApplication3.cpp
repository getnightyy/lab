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

    Console::WriteLine();

    // Порівняння рядків
    int result = String::Compare(first, second, true);

    if (result < 0)
        Console::WriteLine("{0} менше ніж {1}.", first, second);
    else if (result > 0)
        Console::WriteLine("{0} більше ніж {1}.", first, second);
    else
        Console::WriteLine("{0} еквівалентно {1}.", first, second);

    return 0;
}
