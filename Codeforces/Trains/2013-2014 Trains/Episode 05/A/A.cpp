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

int t, n;
string s [10000];
bool flag;

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> t;

	for (int e = 0; e < t; e++)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> s [i];

		sort (s, s + n);
		flag = false;

		for (int i = 0; i < (n - 1); i++)
		{
			int len = s [i].length ();

			if (s [i] == s [i + 1].substr (0, len))
			{
				cout << "NO" << endl;
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		cout << "YES" << endl;	
	}	

	return 0;

}	