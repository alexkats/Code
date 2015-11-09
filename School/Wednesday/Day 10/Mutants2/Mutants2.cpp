#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int n, m, r, d [1001][1001], k [1001], a [1001][1001], x [1001], y [1001];

int main ()
{

	freopen ("mutants2.in", "r", stdin);
	freopen ("mutants2.out", "w", stdout);

	cin >> n >> m;
	r = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a [i][j];

	d [0][1] = a [1][1];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (d [i - 1][j] < d [i][j - 1])
			{
				d [i][j] = d [i - 1][j] + a [i][j];
				r++;
				k [r] = 1;
			} else {
				d [i][j] = d [i][j - 1] + a [i][j];
				r++;
				k [r] = 2;
			}

	x [r] = n;
	y [r] = m;
	cout << d [n][m] << endl;	

	for (int i = r - 1; i >= 1; i--)
		if (k [i] == 1)
		{
			x [i] = x [i + 1] - 1;
			y [i] = y [i + 1];
		} else {
			x [i] = x [i + 1];
			y [i] = y [i + 1] - 1;
		}

	for (int i = 1; i <= r; i++)
		cout << y [i] << " " << x [i] << endl;	

	return 0;

}	