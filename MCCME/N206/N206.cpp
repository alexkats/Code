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
#include <time.h>
#include <cassert>
#include <assert.h>

#define DEBUG
#define ASSERT
#define NAME ""

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n, m, a [15][15];

int main ()
{

	ifstream in ("input.txt");
	ofstream out ("output.txt");

	in >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a [i][j] = 0;

	for (int i = 1; i <= n; i++)
		a [i][1] = 1;

	for (int i = 1; i <= m; i++)
		a [1][i] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a [i][j] == 0)
				a [i][j] = a [i - 1][j] + a [i][j - 1];

	out << a [n][m] << endl;	

	return 0;

}	