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

#define NAME "dt2"
#define maxn 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int t [maxn * 4][maxn * 4], a [maxn][maxn], n, m;

void build_y (int vx, int lx, int rx, int vy, int ly, int ry)
{
	if (ly == ry)
		if (lx == rx)
			t [vx][vy] = a [lx][ly];
		else
			t [vx][vy] = t [vx * 2][vy] + t [vx * 2 + 1][vy];
	else
	{
		int my = (ly + ry) / 2;
		build_y (vx, lx, rx, vy * 2, ly, my);
		build_y (vx, lx, rx, vy * 2 + 1, my + 1, ry);
		t [vx][vy] = t [vx][vy * 2] + t [vx][vy * 2 + 1];
	}
}

void build_x (int vx, int lx, int rx)
{
	if (lx == rx)
		build_y (vx, lx, rx, 1, 0, m - 1);
	else
	{
		int mx = (lx + rx) / 2;
		build_x (vx * 2, lx, mx);
		build_x (vx * 2 + 1, mx + 1, rx);
	}
}

int sum_y (int vx, int vy, int trly, int trry, int ly, int ry)
{
	if (ly > ry)
		return 0;

	if (ly == trly && ry == trry)
		return t [vx][vy];

	int trmy = (trly + trry) / 2;

	return sum_y (vx, vy * 2, trly, trmy, ly, min (ry, trmy)) + sum_y (vx, vy * 2 + 1, trmy + 1, trry, max (ly, trmy + 1), ry);
}

int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
	if (lx > rx)
		return 0;

	if (lx == tlx && rx == trx)
		return sum_y (vx, 1, 0, m - 1, ly, ry);

	int tmx = (tlx + trx) / 2;

	return sum_x (vx * 2, tlx, tmx, lx, min (rx, tmx), ly, ry) + sum_x (vx * 2 + 1, tmx + 1, trx, max (lx, tmx + 1), rx, ly, ry);
}

void update_y (int vx, int lx, int rx, int vy, int ly ,int ry, int x, int y, int new_val)
{
	if (ly == ry)
		if (lx == rx)
			t [vx][vy] = new_val;
		else
			t [vx][vy] = t [vx * 2][vy] + t [vx * 2 + 1][vy];
	else
	{
		int my = (ly + ry) / 2;

		if (y <= my)
			update_y (vx, lx, rx, vy * 2, ly, my, x, y, new_val);
		else
			update_y (vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);

		t [vx][vy] = t [vx][vy * 2] + t [vx][vy * 2 + 1];
	}
}

void update_x (int vx, int lx, int rx, int x, int y, int new_val)
{
	if (lx == rx)
		update_y (vx, lx, rx, 1, 0, m - 1, x, y, new_val);
	else
	{
		int mx = (lx + rx) / 2;

		if (x <= mx)
			update_x (vx * 2, lx, mx, x, y, new_val);
		else
			update_x (vx * 2 + 1, mx + 1, rx, x, y, new_val);
	}
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n >> m;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			in >> a [i][j];

	build_x (1, 0, n - 1);

	out << sum_x (1, 0, n - 1, 2, 4, 1, 2) << endl;	

	return 0;

}	