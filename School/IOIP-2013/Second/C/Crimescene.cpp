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
#define NAME "crimescene"

typedef unsigned long long ULL;

using namespace std;

ULL l, cx [100010], cy [100010];
int n, k, fr [100010];
float tmpcx [100010], tmpcy [100010], a [100010];
ULL ax, ay;

float sqr (float a)
{
	return a * a;
}	

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> n >> l >> k;

	for (int i = 1; i <= k; i++)
		cin >> fr [i];

	for (int i = 1; i <= n; i++)
		cin >> cx [i] >> cy [i];

	for (int i = 1; i <= n; i++)
	{
		ax = fabs (cx [i] - cx [i % n + 1]);
		ay = fabs (cy [i] - cy [i % n + 1]);

		if (ax == 0)
		{
			a [i] = ay;
			continue;
		}

		if (ay == 0)
		{
			a [i] = ax;
			continue;
		}	

		float r = float (ay) / float (ax);
		cout << atan (r) << endl;
		a [i] = float (ay) / sin (atan (float (float (ay) / float (ax))));
	}	

	for (int i = 1; i <= n; i++)
		cout << a [i] << endl;	

	return 0;

}	