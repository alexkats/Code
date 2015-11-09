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

#define NAME "c"
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

bool s_cl = true;
bool q_cl = true;
bool d_cl = true;
int n, a [100000];
vector <int> b;
int q;

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a [i];

	for (int i = 0; i < n; i++)
	{
		if (a [i] != 0)
		{
			b.pb (a [i]);
			continue;
		}

		sort (b.begin (), b.end ());
		reverse (b.begin (), b.end ());

		if (b.size () > 3)
		{
			q = 0;

			for (int j = (i - (int) b.size ()); j < i; j++)
			{
				if ((a [j] == b [0] || a [j] == b [1] || a [j] == b [2]) && q == 0)
				{
					cout << "pushStack" << endl;
					q++;
				}	
				else if ((a [j] == b [0] || a [j] == b [1] || a [j] == b [2]) && q == 1)
				{
					cout << "pushQueue" << endl;
					q++;
				}	
				else if ((a [j] == b [0] || a [j] == b [1] || a [j] == b [2]) && q == 2)
				{
					cout << "pushBack" << endl;
					q++;
				}	
				else
					cout << "pushFront" << endl;
			}

			s_cl = false;
			q_cl = false;
			d_cl = false;	
		}
		else if (b.size () == 1)
		{
			cout << "pushStack" << endl;
			s_cl = false;
		}
		else if (b.size () == 2)
		{
			cout << "pushStack" << endl;
			cout << "pushQueue" << endl;
			s_cl = false;
			q_cl = false;
		}
		else if (b.size () == 3)
		{
			cout << "pushStack" << endl;
			cout << "pushQueue" << endl;
			cout << "pushBack" << endl;
			s_cl = false;
			q_cl = false;
			d_cl = false;
		}	

		if (a [i] == 0)
		{
			if (s_cl && q_cl && d_cl)
				cout << 0 << endl;
			else if (s_cl && q_cl && !d_cl)
				cout << 1 << " popBack" << endl;
			else if (s_cl && !q_cl && d_cl)
				cout << 1 << " popQueue" << endl;
			else if (!s_cl && q_cl && d_cl)
				cout << 1 << " popStack" << endl;
			else if (s_cl && !q_cl && !d_cl)
				cout << 2 << " popQueue popBack" << endl;
			else if (!s_cl && q_cl && !d_cl)
				cout << 2 << " popStack popBack" << endl;
			else if (!s_cl && !q_cl && d_cl)
				cout << 2 << " popStack popQueue" << endl;
			else
				cout << 3 << " popStack popQueue popBack" << endl;
		}

		s_cl = true;
		q_cl = true;
		d_cl = true;
		b.clear ();
	}	

	return 0;
}	