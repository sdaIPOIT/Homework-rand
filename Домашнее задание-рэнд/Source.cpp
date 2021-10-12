#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

long double fctr(int f)
{
	long double result = 1;
	for (; 1 < f; --f) {
		result = result * f;
	}
	return result;
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int a, b, rnd_num, x, attempts = 1, sum_nums = 0, m_num, cnt = 1, i;
	long double f;
	cout << "Ââåäèòå íèæíèé ïðåäåë\n";
	cin >> a;
	cout << "Ââåäèòå âåðõíèé ïðåäåë\n";
	cin >> b;

	rnd_num = a + (rand() % ((b - a) + 1));
	cout << "Ïîïðîáóéòå óãàäàòü çàãàäàííîå ÷èñëî\n";
	cin >> x;

	while (x != rnd_num)
	{
		attempts++;

		if (rnd_num < x && x != rnd_num)
		{
			cout << "Çàãàäàííîå ÷èñëî ìåíüøå ââåä¸ííîãî, ïîïðîáóéòå åù¸ ðàç\n";
			cin >> x;
		}
		else
		{
			cout << "Çàãàäàííîå ÷èñëî áîëüøå ââåä¸ííîãî, ïîïðîáóéòå åù¸\n";
			cin >> x;
		}
	}

	cout << "Âû óãàäàëè ÷èñëî, ïîçäðàâëÿþ!\n";
	cout << "Ê-âî âàøèõ ïîïûòîê ðàâíî " << attempts << endl;

	m_num = abs(rnd_num);

	do
	{
		sum_nums = sum_nums + (m_num % 10);
		m_num /= 10;
	} while (m_num != 0);

	cout << "Ñóììà öèôð çàãàäàííîãî ÷èñëà ðàâíà " << sum_nums << endl;

	if (rnd_num >= 0)
	{
		f = fctr(rnd_num);
		cout << "Ôàêòîðèàë ÷èñëà " << rnd_num << " ðàâåí " << f << endl;
	}
	else
	{
		cout << "Ôàêòîðèàë ýòîãî ÷èñëà ïîñ÷èòàòü íåâîçìîæíî\n";
	}

	if (rnd_num == 1)
	{
		cout << "Ýòî ïðîñòîå ÷èñëî\n";
	}
	else
	{
		do
			cnt++;
		while (rnd_num % cnt != 0);

		if (rnd_num / cnt == 1)
		{
			cout << "Ýòî ïðîñòîå ÷èñëî\n";
		}
		else
		{
			cout << "×èñëî íå ÿâëÿåòñÿ ïðîñòûì\n";

			for (i = 1; i < abs(rnd_num) / 2; i++)
			{
				if (rnd_num % i == 0)
				{
					cout << "Äåëèòåëü ÷èñëà " << rnd_num << " - " << i << endl;
				}
			}
		}
	}
	return 0;
}
