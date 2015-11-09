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
//#define NAME "b"

typedef long long LL;

using namespace std;

int n, m, a [500000];
bool r [500000];

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		cin >> a [i];

	sort (a + 1, a + m + 1);

	for (int i = 1; i <= m; i++)
		r [a [i]] = true;

	for (int i = 1; i <= 2 * n - 1; i++)
		if (!r [2 * i - 1] && !r [2 * i])
		{
			cout << 2 * i - 1 << " " << 2 * i << endl;
			return 0;
		}

	for (int i = 1; i <= n; i++)
		if (!r [i * 4 - 2] && !r [i * 4])
		{
			cout << i * 4 - 2 << " " << i * 4 << endl;
			return 0;
		}

	int c = 0;	

	for (int i = 1; i <= 4 * n - 2; i++)
	{
		if (!r [i])
		{
			cout << i << " ";
			c++;
		}

		if (c == 2)
			return 0;
	}	

	return 0;

}	