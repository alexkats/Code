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

#define NAME ""
#define INF 1000000000
#define EPS 0.0000000001

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ull sqr (ll a)
{
	ull c = a * a;

	return c;
}	

using namespace std;

int c1, c2, c3, c4, n, m, a [1000], b [1000];

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> c1 >> c2 >> c3 >> c4;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a [i];	

	for (int i = 0; i < m; i++)
		cin >> b [i];	

	int ansa = 0;
	int ansb = 0;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (a [i] == 0)
			continue;

		if (a [i] * c1 <= c2)
			ansa += a [i] * c1;
		else
			ansa += c2;
	}	
	
	ansa = min (ansa, c3);

	for (int i = 0; i < m; i++)
	{
		if (b [i] == 0)
			continue;
			

		if (b [i] * c1 <= c2)
			ansb += b [i] * c1;
		else
			ansb += c2;
	}	

	ansb = min (ansb, c3);

	ans = ansa + ansb;
	ans = min (ans, c4);

	cout << ans << endl;	

	return 0;

}	