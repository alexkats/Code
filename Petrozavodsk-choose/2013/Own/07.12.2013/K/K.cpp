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
#include <bitset>
#include <map>
#include <cassert>
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "xo"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; 
 
using namespace std;

char check1 ()
{
	res1 = 0;
	int qx = 0;
	int qo = 0;

	rep0(i, m)
		rep0(j, n)
		{
			if (j == 0)
				qx = qo = 0;

			if (a [j][i] == 'X')
			{
				qx++;
				qo = 0;
			}
			else if (a [j][i] == 'O')
			{
				qo++;
				qx = 0;
			}
			else
				qx = qo = 0;

			if (qx == 5 || qo == 5)
			{
				res1++;
				symb1 = (qx == 5) ? 0 : 1;
				coord1 = mp (j, i);
			}	

			if (res1 > 1)
				return 1;

			if (qx > 9 || qo > 9)
				return 1;	
		}

	return 0;
}

char check2 ()
{
	res2 = 0;
	int qx = 0;
	int qo = 0;

	rep0(i, n)
		rep0(j, m)
		{
			if (j == 0)
				qx = qo = 0;

			if (a [i][j] == 'X')
			{
				qx++;
				qo = 0;
			}
			else if (a [i][j] == 'O')
			{
				qo++;
				qx = 0;
			}
			else
				qx = qo = 0;

			if (qx == 5 || qo == 5)
			{
				res2++;
				symb2 =	(qx == 5) ? 0 : 1;
				coord2 = mp (i, j);
			}

			if (res2 > 1)
				return 1;

			if (qx > 9 || qo > 9)
				return 1;

			if (res1 && res2 && symb1 != symb2)
				return 1;
		}

	if (!(res1 && res2))
		return 0;

	int i = coord2.frs;
	int j = coord2.snd;

	while (a [i][j] == 'X')
	{
		j--;

		if (j == -1)
		{
			j++;
			break;
		}	
	}

	if (j)
		j++;

	char ok = 0;
	int left1 = 0;
	int right1 = 0;
	int left2 = 0;
	int right2 = 0;
	int curr1 = 0;
	int curr2 = j;
	int cur = 0;	

	while (a [i][curr2] == 'X')
		curr2++;

	curr2--;	
	right2 = curr2 - j + 1;

	while (a [i][j] == 'X')
	{
		if (i == 0)
			if (a [i + 1][j] == 'X')
			{
				right2--;
				cur = j;
				break;
			}	

		if (a [i][j] == 'X' && (a [i - 1][j] == 'X' || a [i + 1][j] == 'X'))
		{
			right2--;
			cur = j;
			break;
		}

		left2++;
		right2--;
	}

	while (a [i][cur])
	{
		i--;

		if (i == -1)
		{
			i++;
			break;
		}
	}

	if (i)
		i++;

	curr1 = i;

	while (a [curr1][cur] == 'X')
		curr1++;

	curr1--;
	right1 = curr1 - i + 1;	

	while (a [curr1][cur] == 'X')
	{
		if (curr1 == 0)
			if (cur == 0)
				if (a [curr1][cur + 1] == 'X')
				{
					right1--;
					cur2	

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	int curr = 0;
	int n = 0;
	int m = 0;
	int nx, no, mx, mo, nmx, nmo;
	nx = no = mx = mo = nmx = nmo = 0;
	string s;
	char a [100][100] = {'.'};
	int qx = 0;
	int qo = 0;

	while (cin >> s)
	{
		n = max (n, (int) s.length ());

		rep0(i, (int) s.length ())
			if (s [i] == 'X')
			{
				a [i][curr] = 'X';
				qx++;
			}	
			else if (s [i] == 'O')
			{
				a [i][curr] = 'O';
				qo++;
			}	
			else
				a [i][curr] = '.';	

		curr++;
		m = curr;
	}

	if (qo > qx || (qx - qo) > 1)
	{
		puts ("INCORRECT");
		return 0;
	}	

	(check1 () || check2 () || check3 () || check4 ())
		puts ("INCORRECT");
	else
		puts ("CORRECT");	

	return 0;

}	