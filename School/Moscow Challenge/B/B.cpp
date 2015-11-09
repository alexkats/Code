#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int x, n [100000], m [100000], poss, q, ans;

void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void QSort (int l, int r)
{
	int i = l;
	int j = r;
	int x = n [l + rand () % r];

	while (i <= j)
	{
		while (n [i] < x)
			i++;

		while (n [j] > x)
			j--;

		if (i <= j)
		{
			swap (n [i], n [j]);
			swap (m [i], m [j]);
			i++;
			j--;
		}
	}

	if (l < j)
		QSort (l, j);

	if (i < r)
		QSort (i, r);
}	

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> x;

	if (x == 1 || x == 2)
	{
		cout << 0 << endl;
		return 0;
	}

	if (x == 3)
	{
		cout << 1 << endl << "1 1" << endl;
		return 0;
	}	

	poss = sqrt (x);
	q = 0;

	for (int i = 1; i <= poss; i++)
	{
		if (double (double (x - i - 1) / double (i * 2 - 1)) == floor ((x - i - 1) / (i * 2 - 1)) && (x - i - 1) / (i * 2 - 1) <= i)
		{
			q++;
			n [q] = i;
			m [q] = (x - i - 1) / (i * 2 - 1);
		}
		else

		if (double (double (x + i) / double (i * 2 + 1)) == floor ((x + i * 2) / (i * 2 + 1)) && (x + i * 2) / (i * 2 + 1) > i)
		{
			q++;
			n [q] = i;
			m [q] = (x + i) / (i * 2 + 1);
		}
		else

		if (double (double (x - i) / double (i * 2 - 1)) == floor ((x - i) / (i * 2 - 1)) && (x - i) / (i * 2 - 1) < i)
		{
			q++;
			n [q] = (x - i) / (i * 2 - 1);
			m [q] = i;
		}
		else

		if (double (double (x + i - 1) / double (i * 2 + 1)) == floor ((x + i - 1) / (i * 2 + 1)) && (x + i - 1) / (i * 2 + 1) >= i)
		{
			q++;
			n [q] = (x + i - 1) / (i * 2 + 1);
			m [q] = i;
		}	
	}

	if (q == 0)
	{
		cout << q << endl;
		return 0;
	}	

	QSort (1, q);
	ans = q;

	for (int i = 1; i < q; i++)
		if (n [i] == n [i + 1] && m [i] == m [i + 1])
		{
			ans--;
			n [i] = -1;
		}	

	cout << ans << endl;

	for (int i = 1; i <= q; i++)
		if (n [i] > 0)
			cout << n [i] << " " << m [i] << endl;	

	return 0;
}	