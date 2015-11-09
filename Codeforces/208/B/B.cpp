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

#define NAME "b"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep(i,n) (for (int i = 0; i < n; i++))

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n, m;
string s, w [100000];
bool z [100000] = {false};

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> w [i];

	cin >> s;

	int m = (int) s.length ();

	bool fl1 = false, fl2 = false;
	int q = 0, l = 0;

	for (int i = 0; i < m; i++)
	{
		if (s [i] == '<')
		{
			fl1 = true;
			continue;
		}

		if (s [i] == '3' && fl1)
		{
			fl2 = true;
			continue;
		}

		if (s [i] == w [q][l])
		{
			l++;

			if (l == (int) w [q].length ())
			{
				z [q] = true;
				q++;
				l = 0;
			}

			fl1 = fl2 = false;
		}
	}

	if (z [n - 1] && fl1 && fl2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;	

	return 0;
}	