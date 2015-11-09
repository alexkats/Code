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
#include <time.h>
#include <cassert>
#include <assert.h>

#define DEBUG
#define ASSERT
//#define NAME "c"

typedef unsigned long long ULL;
typedef long long LL;

using namespace std;

int n, m, a [110][110], s [110], c [210], r [210], qc1, qc2, qr1, qr2;

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n >> m;
	qc1 = 0;
	qc2 = 0;
	qr1 = 0;
	qr2 = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a [i][j];

	for (int i = 1; i <= m; i++)
	{
		s [i] = 0;

		for (int j = 1; j <= n; j++)
			s [i] += a [j][i];
	}

	for (int i = 1; i <= m; i++)
		if (s [i] < 0)
		{
			for (int j = 1; j <= n; j++)
				a [j][i] = - a [j][i];

			qc1++;
			c [qc1] = i;
		}

	for (int i = 1; i <= n; i++)
	{
		s [i] = 0;

		for (int j = 1; j <= m; j++)
			s [i] += a [i][j];
	}

	for (int i = 1; i <= n; i++)
		if (s [i] < 0)
		{
			for (int j = 1; j <= n; j++)
				a [i][j] = - a [i][j];

			qr1++;
			r [qr1] = i;
		}

	for (int i = 1; i <= m; i++)
	{
		s [i] = 0;

		for (int j = 1; j <= n; j++)
			s [i] += a [j][i];
	}

	for (int i = 1; i <= m; i++)
		if (s [i] < 0)
		{
			for (int j = 1; j <= n; j++)
				a [j][i] = - a [j][i];

			qc2++;
			c [qc1 + qc2] = i;
		}

	for (int i = 1; i <= n; i++)
	{
		s [i] = 0;

		for (int j = 1; j <= m; j++)
			s [i] += a [i][j];
	}

	for (int i = 1; i <= n; i++)
		if (s [i] < 0)
		{
			for (int j = 1; j <= n; j++)
				a [i][j] = - a [i][j];

			qr2++;
			r [qr1 + qr2] = i;
		}

	for (int i = 1; i <= n; i++)
	{
		s [i] = 0;

		for (int j = 1; j <= m; j++)
			s [i] += a [i][j];

		if (s [i] < 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		s [i] = 0;

		for (int j = 1; j <= n; j++)
			s [i] += a [j][i];

		if (s [i] < 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}	

	cout << qc1 + qc2 + qr1 + qr2 << endl;

	for (int i = 1; i <= qc1; i++)
		cout << "C " << c [i] << endl;

	for (int i = 1; i <= qr1; i++)
		cout << "R " << r [i] << endl;

	for (int i = qc1 + 1; i <= (qc1 + qc2); i++)
		cout << "C " << c [i] << endl;

	for (int i = qr1 + 1; i <= (qr1 + qr2); i++)
		cout << "R " << r [i] << endl;	

	return 0;

}	