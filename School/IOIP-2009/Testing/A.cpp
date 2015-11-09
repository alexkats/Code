#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <assert.h>

#define DEBUG
#define ASSERT

using namespace std;

typedef long long LL;

int n, a [100010], b [100010], q;

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n;
	q = 0;	

	for (int i = 1; i <= n; i++)
		cin >> a [i];

	for (int i = 1; i <= n; i++)
		cin >> b [i];

	for (int i = 1; i <= n; i++)
		if (a [i] == b [i])
			q++;

	cout << q << endl;

	return 0;
}	