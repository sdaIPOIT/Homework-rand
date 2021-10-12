#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
long double fctr(int n)
{
	long double result = 1;
	for (; 1 < n; --n) {
		result = result * n;
	}
	return result;
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int a, b, rnd_num, x, attempts = 1, sum_nums = 0, m_num, cnt = 1, i;
	long double f;
	cout << "������� ������ ������\n";
	cin >> a;
	cout << "������� ������� ������\n";
	cin >> b;

	rnd_num = a + (rand() % ((b - a) + 1));
	cout << "���������� ������� ���������� �����\n";
	cin >> x;

	while (x != rnd_num)
	{
		attempts++;

		if (rnd_num < x && x != rnd_num)
		{
			cout << "���������� ����� ������ ���������, ���������� ���\n";
			cin >> x;
		}
		else
		{
			cout << "���������� ����� ������ ���������, ���������� ���\n";
			cin >> x;
		}
	}

	cout << "�� ������� �����, ����������!\n";
	cout << "�-�� ����� ������� ����� " << attempts << endl;

	m_num = abs(rnd_num);

	do
	{
		sum_nums = sum_nums + (m_num % 10);
		m_num /= 10;
	} while (m_num != 0);

	cout << "����� ���� ����������� ����� ����� " << sum_nums << endl;

	if (rnd_num >= 0)
	{
		f = fctr(rnd_num);
		cout << "��������� ����� " << rnd_num << " ����� " << f << endl;
	}
	else
	{
		cout << "��������� ����� ����� ��������� ����������\n";
	}

	if (rnd_num == 1)
	{
		cout << "��� ������� �����\n";
	}
	else
	{
		do
			cnt++;
		while (rnd_num % cnt != 0);

		if (rnd_num / cnt == 1)
		{
			cout << "��� ������� �����\n";
		}
		else
		{
			cout << "����� �� �������� �������\n";

			for (i = 1; i < abs(rnd_num) / 2; i++)
			{
				if (rnd_num % i == 0)
				{
					cout << "�������� ����� " << rnd_num << " - " << i << endl;
				}
			}
		}
	}
	return 0;
}