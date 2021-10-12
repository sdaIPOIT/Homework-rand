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
	cout << "Введите нижний предел\n";
	cin >> a;
	cout << "Введите верхний предел\n";
	cin >> b;

	rnd_num = a + (rand() % ((b - a) + 1));
	cout << "Попробуйте угадать загаданное число\n";
	cin >> x;

	while (x != rnd_num)
	{
		attempts++;

		if (rnd_num < x && x != rnd_num)
		{
			cout << "Загаданное число меньше введённого, попробуйте ещё\n";
			cin >> x;
		}
		else
		{
			cout << "Загаданное число больше введённого, попробуйте ещё\n";
			cin >> x;
		}
	}

	cout << "Вы угадали число, поздравляю!\n";
	cout << "К-во ваших попыток равно " << attempts << endl;

	m_num = abs(rnd_num);

	do
	{
		sum_nums = sum_nums + (m_num % 10);
		m_num /= 10;
	} while (m_num != 0);

	cout << "Сумма цифр загаданного числа равна " << sum_nums << endl;

	if (rnd_num >= 0)
	{
		f = fctr(rnd_num);
		cout << "Факториал числа " << rnd_num << " равен " << f << endl;
	}
	else
	{
		cout << "Факториал этого числа посчитать невозможно\n";
	}

	if (rnd_num == 1)
	{
		cout << "Это простое число\n";
	}
	else
	{
		do
			cnt++;
		while (rnd_num % cnt != 0);

		if (rnd_num / cnt == 1)
		{
			cout << "Это простое число\n";
		}
		else
		{
			cout << "Число не является простым\n";

			for (i = 1; i < abs(rnd_num) / 2; i++)
			{
				if (rnd_num % i == 0)
				{
					cout << "Делитель числа " << rnd_num << " - " << i << endl;
				}
			}
		}
	}
	return 0;
}