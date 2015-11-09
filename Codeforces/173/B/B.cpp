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
typedef unsigned long long ULL;

using namespace std;

LL s1, s2;
int n, k, a, g, s [1000010];

int main ()
{

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n;

	s1 = 0;
	s2 = 0;
	k = 1;

	for (int i = 1; i <= n; i++)
	{
		cin >> a >> g;

		if (k == 1)
			if (abs (s1 + a - s2) <= 500)
			{
				s1 += a;
				s [i] = 1;
			}
			else
			{
				k = 2;
				s2 += g;
				s [i] = 2;
			}
		else
			if (abs (s2 + g - s1) <= 500)
			{
				s2 += g;
				s [i] = 2;
			}
			else
			{
				k = 1;
				s1 += a;
				s [i] = 1;
			}
	}

	for (int i = 1; i <= n; i++)
		if (s [i] == 1)
			cout << "A";
		else
			cout << "G";	

	return 0;

}	