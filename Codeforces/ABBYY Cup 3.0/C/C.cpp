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
#define NAME ""

typedef long long ll;

using namespace std;

int n, m, a [85][85], q;
bool z [3210], flag;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> n >> m;

	q = 0;

	for (int i = 1; i <= n * m / 2; i++)
		z [i] = false;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a [i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!z [a [i][j]])
			{
				z [a [i][j]] = true;
				flag = false;

				for (int i1 = 1; i1 <= n; i1++)
				{
					for (int j1 = 1; j1 <= m; j1++)
						if (a [i1][j1] == a [i][j] && !(i1 == i && j1 == j))
						{
							flag = true;

							if ((abs (i1 - i) + abs (j1 - j)) != 1)
								q++;

							break;
						}

					if (flag)
						break;
				}
			}

	cout << q + 1 << endl;	

	return 0;

}	