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
 
#define NAME "paradox"
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

int main ()
{

	freopen (NAME".in", "w", stdout);

	srand (time (0));

	int n = 1 + rand () % 5;
	cout << n << endl;

	rep0(i, n)
	{
		int k = 1 + rand () % 3;
		
		if (k == 1)
			cout << "AAA";
		else if (k == 2)
			cout << "BBB";
		else
			cout << "CCC";

		cout << "-";	

		k = 1 + rand () % 3;

		if (k == 1)
			cout << "AAA";
		else if (k == 2)
			cout << "BBB";
		else
			cout << "CCC";

		cout << endl;
	}	

	return 0;

}	