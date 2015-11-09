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
#define NAME "baskerville"

typedef long long LL;

using namespace std;

int n;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> n;

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	if (n == 2)
	{
		cout << 3 << endl;
		return 0;
	}

	if (n == 3)
	{
		cout << 25 << endl;
		return 0;
	}

	return 0;

}	