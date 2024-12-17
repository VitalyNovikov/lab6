#include <iostream>
using namespace std;

/*
Array11.
Array75.
*/

const int N = 50; // Максимальний розмір масиву

// Прототипи функцій
void input_arr(int arr[], int &n);              // Введення масиву
void output_arr(const int arr[], int n);        // Виведення масиву
void task1();                                   // Завдання 1
void task2();                                   // Завдання 2
void reverse_between_min_max(int arr[], int n); // Перетворення для завдання 2
void elements_multiple_k(const int arr[], int n, int k); // Вивід елементів кратних K

int main()
{
    int choice;
    do
    {
        cout << "\nВиберіть завдання: \n";
        cout << "1 - Завдання 1\n";
        cout << "2 - Завдання 2\n";
        cout << "0 - Вихід\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 0:
            cout << "Вихід з програми...\n";
            break;
        default:
            cout << "Некоректний вибір, спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}

// Функція для введення масиву
void input_arr(int arr[], int &n)
{
    cout << "Введіть кількість елементів масиву (2-50): ";
    cin >> n;
    if (n < 2 || n > N)
    {
        cout << "Некоректний розмір масиву.\n";
        return;
    }
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

// Функція для виведення масиву
void output_arr(const int arr[], int n)
{
    cout << "Елементи масиву: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Завдання 1: Вивести елементи з індексами кратними K
void task1()
{
    int arr[N], n, k;
    input_arr(arr, n);
    cout << "Введіть число K (1 <= K <= " << n << "): ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Некоректне значення K.\n";
        return;
    }

    output_arr(arr, n);
    elements_multiple_k(arr, n, k);
}

// Функція для виведення елементів з індексами кратними K
void elements_multiple_k(const int arr[], int n, int k)
{
    cout << "Елементи з індексами кратними " << k << ": ";
    for (int i = k - 1; i < n; i += k)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Завдання 2: Перетворення масиву
void task2()
{
    int arr[N], n;
    input_arr(arr, n);
    output_arr(arr, n);
    reverse_between_min_max(arr, n);
    cout << "Масив після перетворення:\n";
    output_arr(arr, n);
}

// Функція для перестановки елементів між мінімальним і максимальним елементами
void reverse_between_min_max(int arr[], int n)
{
    int minIndex = 0, maxIndex = 0;

    // Пошук індексів мінімального і максимального елементів
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }

    // Забезпечуємо, що minIndex йде перед maxIndex
    if (minIndex > maxIndex)
        swap(minIndex, maxIndex);

    // Переворот елементів між minIndex і maxIndex включно
    for (int i = minIndex, j = maxIndex; i < j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}
