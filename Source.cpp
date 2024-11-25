#include <iostream>
#include <windows.h>
#include "Time.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int x;
	int y;
	cout << "Введите время, часы(0-23) и минуты(0-59):" << endl;
	cin >> x >> y;
	if ((x < 0) || (x > 23) || (y < 0) || (y > 59))
	{
		cout << "Некорректно введено время!" << endl;
	}
	else
	{
		Time t(x, y);
		int a;
		unsigned int x;
		int c;
		do
		{
			cout << "1. Добавить определенное кол-во минут." << endl;
			cout << "2. Вывод времени." << endl;
			cout << "3. Добавление 1 минуты." << endl;
			cout << "4. Вычитание 1 минуты." << endl;
			cout << "5. Показать кол-во часов." << endl;
			cout << "6. Проверка на 0." << endl;
			cout << "7. Добавить определенное кол-во минут." << endl;
			cout << "8. Вычесть определенное кол-во минут." << endl;
			cout << "0. Выход!" << endl;
			cout << "Выберите действие:" << endl;
			cin >> a;
			switch (a)
			{
			case 1:
			{
				cout << "Введите колличество минут которое хотите добавить:" << endl;
				cin >> x;
				if (x <= 0)
				{
					cout << "Вы ввели отрицательное число или 0" << endl;
				}
				else
				{
					t.plusM(x);
				}
				cout << t << endl;
				break;
			}
			case 2:
			{
				cout << t << endl;
				break;
			}
			case 3:
			{
				t++;
				cout << t << endl;
				break;
			}
			case 4:
			{
				--t;
				cout << t << endl;
				break;
			}
			case 5:
			{
				short int hoursOnly = static_cast<short int>(t);
				cout << "Часы: " << hoursOnly << endl << endl;
				break;
			}
			case 6:
			{
				bool Zero = t;
				cout << "Время не равно нулю: " << (Zero ? "true" : "false") << endl << endl;
				break;
			}
			case 7:
			{
				int m;
				cout << "Введите кол-во минут которое хотите добавить (0-59): " << endl;
				cin >> m;
				if ((m < 0) || (m > 59))
				{
					cout << "Неверное кол-во минут." << endl << endl;
				}
				else
				{
					Time c(0, m);
					cout << t + c << endl;
				}
				break;
			}
			case 8:
			{
				int m;
				cout << "Введите кол-во минут которое хотите вычесть (0-59): " << endl;
				cin >> m;
				if ((m < 0) || (m > 59))
				{
					cout << "Неверное кол-во минут." << endl << endl;
				}
				else
				{
					Time c(0, m);
					cout << t - c << endl;
				}
				break;
			}
			}
		} while (a != 0);
	}
}