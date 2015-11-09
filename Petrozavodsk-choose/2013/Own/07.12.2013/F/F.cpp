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
 
#define NAME "square"
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

bool ok (int w1, int h1, int w2, int h2, int w3, int h3)
{
	if (w1 + w2 + w3 == h1 && h1 == h2 && h2 == h3)
		return true;

	if (h1 + h2 + h3 == w1 && w1 == w2 && w2 == w3)
		return true;

	if (w1 + w2 == w3 && h1 == h2 && h1 + h3 == w3)
		return true;

	if (w1 + w3 == w2 && h1 == h3 && h1 + h2 == w2)
		return true;

	if (w2 + w3 == w1 && h2 == h3 && h2 + h1 == w1)
		return true;

	if (h1 + h2 == h3 && w1 == w2 && w1 + w3 == h3)
		return true;

	if (h1 + h3 == h2 && w1 == w3 && w1 + w2 == h2)
		return true;

	if (h2 + h3 == h1 && w2 == w3 && w2 + w1 == h1)
		return true;

	return false;
}

int w1, h1, w2, h2, w3, h3;	

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d %d\n%d %d\n%d %d", &w1, &h1, &w2, &h2, &w3, &h3);
	
	if (ok (w1, h1, w2, h2, w3, h3))
		puts ("YES");
	else
		puts ("NO");	

	return 0;

}	