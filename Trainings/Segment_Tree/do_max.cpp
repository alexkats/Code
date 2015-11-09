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

#define NAME "do_max"    
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
		t [v] = max (t [v * 2], t [v * 2 + 1]);
	}
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

		t [v] = max (t [v * 2], t [v * 2 + 1]);
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

	out << t [1] << endl;

	update (1, 0, n - 1, 2, 13);

	out << t [1] << endl;

	return 0;

}	