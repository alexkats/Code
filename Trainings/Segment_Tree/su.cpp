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
#include <iterator>

#define NAME "su"
#define maxn 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int t [maxn * 4], a [maxn], n;

void build (int a [], int v, int trl, int trr)
{
	if (trl == trr)
		t [v] = a [trl];
	else
	{
		int trm = (trl + trr) / 2;
		build (a, v * 2, trl, trm);
		build (a, v * 2 + 1, trm + 1, trr);
	}
}

void update (int v, int trl, int trr, int l, int r, int add)
{
	if (l > r)
		return;

	if (l == trl && r == trr)
		t [v] += add;
	else
	{
		int trm = (trl + trr) / 2;
		update (v * 2, trl, trm, l, min (r, trm), add);
		update (v * 2 + 1, trm + 1, trr, max (l, trm + 1), r, add);
	}
}

int get (int v, int trl, int trr, int pos)
{
	if (trl == trr)
		return t [v];

	int trm = (trl + trr) / 2;

	if (pos <= trm)
		return t [v] + get (v * 2, trl, trm, pos);
	else
		return t [v] + get (v * 2 + 1, trm + 1, trr, pos);
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	return 0;

}	