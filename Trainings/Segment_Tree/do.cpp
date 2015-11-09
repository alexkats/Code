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
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define NAME "do"
#define maxn 1000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n, t [maxn * 4];
int a [maxn];

void build (int a [], int v, int trl, int trr)
{
	if (trl == trr)
		t [v] = a [trl];
	else
	{
		int trm = (trl + trr) / 2;
		build (a, v * 2, trl, trm);
		build (a, v * 2 + 1, trm + 1, trr);
		t [v] = t [v * 2] + t [v * 2 + 1];
	}
}

int sum (int v, int trl, int trr, int l, int r)
{
	if (l > r)
		return 0;

	if (l == trl && r == trr)
		return t [v];

	int trm = (trl + trr) / 2;

	return sum (v * 2, trl, trm, l, min (r, trm)) + sum (v * 2 + 1, trm + 1, trr, max (l, trm + 1), r);
}

void update (int v, int trl, int trr, int pos, int new_val)
{
	if (trl == trr)
		t [v] = new_val;
	else
	{
		int trm = (trl + trr) / 2;

		if (pos <= trm)
			update (v * 2, trl, trm, pos, new_val);
		else
			update (v * 2 + 1, trm + 1, trr, pos, new_val);

		t [v] = t [v * 2] + t [v * 2 + 1];
	}
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i];

	build (a, 1, 0, n - 1);

	out << sum (1, 0, n - 1, 1, 3) << endl;

	update (1, 0, n - 1, 2, 1);

	out << sum (1, 0, n - 1, 1, 3) << endl;	

	return 0;

}	