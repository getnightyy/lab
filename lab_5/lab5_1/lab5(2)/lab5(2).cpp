#include "pch.h"
using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;
    Console::WriteLine(L"Програма для обчислення напруженості електричного поля E = F/q");
    Console::WriteLine();

    int n = 0;

    while (true)
    {
        try
        {
            Console::Write(L"Введи кількість вимірювань: ");
            n = Int32::Parse(Console::ReadLine());
            if (n <= 0)
            {
                Console::WriteLine(L"Кількість вимірювань повинна бути більшою за 0!!!");
                continue;
            }
            break;
        }
        catch (FormatException^)
        {
            Console::WriteLine(L"Потрібно ввести ціле число!");
        }
        catch (OverflowException^)
        {
            Console::WriteLine(L"Введене число занадто велике або мале!");
        }
    }

    array<double>^ q = gcnew array<double>(n);
    array<double>^ F = gcnew array<double>(n);
    array<double>^ E = gcnew array<double>(n);

    Console::WriteLine(L"\n*** Таблиця вимірювань кулонівської сили ***");

    for (int i = 0; i < n; i++)
    {
        Console::WriteLine(L"\nВимірювання N{0}:", i + 1);

        while (true)
        {
            try
            {
                Console::Write(L"Заряд q (Кл): ");
                q[i] = Double::Parse(Console::ReadLine());
                if (q[i] == 0)
                {
                    Console::WriteLine(L"Заряд не може дорівнювати 0!");
                    continue;
                }
                break;
            }
            catch (FormatException^)
            {
                Console::WriteLine(L"Введи число (наприклад: 0,001)!");
            }
            catch (OverflowException^)
            {
                Console::WriteLine(L"Значення занадто велике або мале!");
            }
        }

        while (true)
        {
            try
            {
                Console::Write(L"Кулонівська сила F (Н): ");
                F[i] = Double::Parse(Console::ReadLine());
                break;
            }
            catch (FormatException^)
            {
                Console::WriteLine(L"Введи число (наприклад: 5,2)!");
            }
            catch (OverflowException^)
            {
                Console::WriteLine(L"Значення занадто велике або мале!");
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        E[i] = F[i] / q[i];
    }
    Console::WriteLine(L"\n_____________________________________________________");
    Console::WriteLine(L"|         Результати обчислень E = F/q               |");
    Console::WriteLine(L"|____________________________________________________|");
    Console::WriteLine(L"\nN\tq (Кл)\t\tF (Н)\t\tE (Н/Кл)");
    Console::WriteLine(L"─────────────────────────────────────────────────────");

    for (int i = 0; i < n; i++)
    {
        Console::WriteLine(L"{0}\t{1:F2}\t\t{2:F4}\t\t{3:F4}",
            i + 1, q[i], F[i], E[i]);
    }

    double sumE = 0;
    for (int i = 0; i < n; i++)
    {
        sumE += E[i];
    }
    double avgE = sumE / n;

    Console::WriteLine(L"─────────────────────────────────────────────────────");
    Console::WriteLine(L"\nСереднє значення напруженості поля: E_сер = {0:F4} Н/Кл", avgE);

    double maxE = E[0], minE = E[0];
    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (E[i] > maxE)
        {
            maxE = E[i];
            maxIndex = i;
        }
        if (E[i] < minE)
        {
            minE = E[i];
            minIndex = i;
        }
    }

    Console::WriteLine(L"\nМаксимальна напруженість: E_max = {0:F4} Н/Кл (вимірювання N{1})", maxE, maxIndex + 1);
    Console::WriteLine(L"Мінімальна напруженість: E_min = {0:F4} Н/Кл (вимірювання N{1})", minE, minIndex + 1);
    Console::ReadKey();
    return 0;
}