#include "pch.h"
#include "Windows.h"
using namespace System;

int main(array<String^>^ args)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Зчитую рядок
    Console::Write("Введіть рядок: ");
    String^ input = Console::ReadLine()->Trim();
    // Trim() для прибирання зайвих пробілів з початку та в кінці рядка

    // Створюю новий рядок у зворотному порядку без масиву
    String^ reversed = "";
    for (int i = input->Length - 1; i >= 0; i--)
    {
        reversed += input[i]; // додаю символ з кінця на початок
    }

    // Вивід результату
    Console::WriteLine();
    Console::WriteLine("Рядок у зворотному порядку: {0}", reversed);

    return 0;
}
