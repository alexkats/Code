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
 
#define NAME "endspiel"
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

int cx1, cy1, cx2, cy2;
char a, b, st;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%c%d %c%d %c", &a, &cy1, &b, &cy2, &st);

	cx1 = (int) (a - 'a');
	cx2 = (int) (b - 'a');
	cy1--;
	cy2--;

	if (cx1 == cx2 && abs (cy1 - cy2) == 1)
	{
		puts (st == 'B' ? "Black wins" : "White wins");
		return 0;
	}

	if (cy1 == cy2 && abs (cx1 - cx2) == 1)
	{
		puts (st == 'B' ? "Black wins" : "White wins");
		return 0;
	}

	if ((abs (cx1 - cx2) + abs (cy1 - cy2)) % 2 == 0)
	{
		puts (st == 'B' ? "White wins" : "Black wins");
		return 0;
	}
	else
	{
		puts (st == 'B' ? "Black wins" : "White wins");
		return 0;
	}		

	return 0;

}	