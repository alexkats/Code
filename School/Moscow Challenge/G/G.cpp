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

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		a [x][y] = true;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d [i][j] = 1e9;

	for (int i = 1; i <= n; i++)
		d [i][i] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a [i][j])
				d [i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a [i][j] && !a [j][i])
				d [j][i] = 1;	

	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cin >> x >> y;

		if (d [x][y] < 2)
		{
			if (d [x][y] == 0)
				cout << 0 << endl;
			else
				cout << 1 << endl;

			continue;
		}	

		for (int j = 1; j <= n; j++)
			if (d [x][j] + d [j][y] == min (c, d [x][j] + d [j][y]))
			{
				c = d [x][j] + d [j][y];
				imin = j;
			}	
			
		q += c;	

	return 0;
}	