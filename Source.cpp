#include <iostream>
#include <windows.h>
#include "Time.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int x;
	int y;
	cout << "������� �����, ����(0-23) � ������(0-59):" << endl;
	cin >> x >> y;
	if ((x < 0) || (x > 23) || (y < 0) || (y > 59))
	{
		cout << "����������� ������� �����!" << endl;
	}
	else
	{
		Time t(x, y);
		int a;
		unsigned int x;
		int c;
		do
		{
			cout << "1. �������� ������������ ���-�� �����." << endl;
			cout << "2. ����� �������." << endl;
			cout << "3. ���������� 1 ������." << endl;
			cout << "4. ��������� 1 ������." << endl;
			cout << "5. �������� ���-�� �����." << endl;
			cout << "6. �������� �� 0." << endl;
			cout << "7. �������� ������������ ���-�� �����." << endl;
			cout << "8. ������� ������������ ���-�� �����." << endl;
			cout << "0. �����!" << endl;
			cout << "�������� ��������:" << endl;
			cin >> a;
			switch (a)
			{
			case 1:
			{
				cout << "������� ����������� ����� ������� ������ ��������:" << endl;
				cin >> x;
				if (x <= 0)
				{
					cout << "�� ����� ������������� ����� ��� 0" << endl;
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
				cout << "����: " << hoursOnly << endl << endl;
				break;
			}
			case 6:
			{
				bool Zero = t;
				cout << "����� �� ����� ����: " << (Zero ? "true" : "false") << endl << endl;
				break;
			}
			case 7:
			{
				int m;
				cout << "������� ���-�� ����� ������� ������ �������� (0-59): " << endl;
				cin >> m;
				if ((m < 0) || (m > 59))
				{
					cout << "�������� ���-�� �����." << endl << endl;
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
				cout << "������� ���-�� ����� ������� ������ ������� (0-59): " << endl;
				cin >> m;
				if ((m < 0) || (m > 59))
				{
					cout << "�������� ���-�� �����." << endl << endl;
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