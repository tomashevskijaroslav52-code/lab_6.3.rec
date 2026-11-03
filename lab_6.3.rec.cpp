#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1) Рекурсивна функція для масиву цілих чисел (int)
int CountEven(const int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 == 0)
            return 1 + CountEven(a, size, i + 1);
        else
            return CountEven(a, size, i + 1);
    }
    else
    {
        return 0;
    }
}

// 2) Шаблон рекурсивної функції для масивів довільного типу даних
template <typename T>
int CountEven(const T* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 == 0)
            return 1 + CountEven<T>(a, size, i + 1);
        else
            return CountEven<T>(a, size, i + 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n] = { 2, 5, 8, 11, 14, 3, 6, 9, 12, 15 };

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << a[i];
    }
    cout << endl;

    // Виклик звичайної рекурсивної функції (починаючи з індексу 0)
    int count1 = CountEven(a, n, 0);
    cout << "CountEven(a, n, 0) [recursive function] = " << count1 << endl;

    // Виклик шаблону рекурсивної функції для типу int
    int count2 = CountEven<int>(a, n, 0);
    cout << "CountEven<int>(a, n, 0) [recursive template] = " << count2 << endl;

    return 0;
}
