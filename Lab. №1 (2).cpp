#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

bool contains_required_digits(int n)
{
    while (n > 0)
    {
        int digit = n % 10;
        if (digit != 1 && digit != 2 && digit != 3 && digit != 4 && digit != 5)
            return false;
        n /= 10;
    }
    return true;
}

bool is_prime(int n)
{
    if (n <= 1 || !contains_required_digits(n))
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int count_primes(int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (is_prime(i))
        {
            // cout << i << endl;
            count++;
        }
    }
    return count;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "# # # Кол-во простых чисел длиной 1 символ: " << count_primes(0, 9) << endl;
    cout << "# # # Кол-во простых чисел длиной 2 символа: " << count_primes(10, 99) << endl;
    cout << "# # # Кол-во простых чисел длиной 3 символа: " << count_primes(100, 999) << endl;
    cout << "# # # Кол-во простых чисел длиной 4 символа: " << count_primes(1000, 9999) << endl;
    cout << "# # # Кол-во простых чисел длиной 5 символов: " << count_primes(10000, 99999) << endl;
    return 0;
}
