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

int n, s, t, k, q, p [100010];
bool a [100010];

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n >> s >> t;

	for (int i = 1; i <= n; i++)
		cin >> p [i];

	k = s;
	q = 0;

	for (int i = 1; i <= n; i++)
		a [i] = false;

	while (k != t)
	{
		a [k] = true;
		k = p [k];
		q++;

		if (a [k])
		{
			cout << -1 << endl;
			return 0;
		}
	}

	cout << q << endl;	

	return 0;

}	