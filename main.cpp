#include <iostream>
#include <map> // Для завдання Array98
using namespace std;

const int N = 50; // Максимальний розмір масиву


// Прототипи функцій
void input_arr(int arr[], int &n);              // Введення масиву
void output_arr(const int arr[], int n);        // Виведення масиву
void task1();                                   // Завдання 1
void task2();                                   // Завдання 2
bool is_geometric_progression(const int arr[], int n, int &r); // Завдання Array25
void remove_elements_less_than_three(int arr[], int &n);       // Завдання Array98

int main()
{
    int choice;
    do
    {
        cout << "\nВиберіть завдання: \n";
        cout << "1 - Завдання Array25 (Геометрична прогресія)\n";
        cout << "2 - Завдання Array98 (Видалення елементів)\n";
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

// Завдання Array25: Перевірка геометричної прогресії
void task1()
{
    int arr[N], n, r;
    input_arr(arr, n);
    if (is_geometric_progression(arr, n, r))
        cout << "Масив утворює геометричну прогресію. Знаменник: " << r << endl;
    else
        cout << "Масив не утворює геометричну прогресію. Знаменник: 0" << endl;
}

// Функція перевірки геометричної прогресії
bool is_geometric_progression(const int arr[], int n, int &r)
{
    if (n < 2)
        return false; // Для прогресії потрібно мінімум 2 елементи

    r = arr[1] / arr[0]; // Обчислюємо початковий знаменник
    for (int i = 1; i < n; i++)
    {
        if (arr[i] / arr[i - 1] != r || arr[i] % arr[i - 1] != 0)
        {
            return false; // Перевіряємо умову геометричної прогресії
        }
    }
    return true;
}

// Завдання Array98: Видалення елементів, що зустрічаються менше 3 разів
void task2()
{
    int arr[N], n;
    input_arr(arr, n);
    remove_elements_less_than_three(arr, n);
    cout << "Розмір отриманого масиву: " << n << endl;
    output_arr(arr, n);
}

// Функція для видалення елементів, що зустрічаються менше 3 разів
void remove_elements_less_than_three(int arr[], int &n)
{
    map<int, int> freq;

    // Підрахунок частоти кожного елемента
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Формування нового масиву
    int new_arr[N], new_size = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] >= 3)
        {
            new_arr[new_size++] = arr[i];
        }
    }

    // Оновлення вихідного масиву
    for (int i = 0; i < new_size; i++)
    {
        arr[i] = new_arr[i];
    }
    n = new_size;
}
