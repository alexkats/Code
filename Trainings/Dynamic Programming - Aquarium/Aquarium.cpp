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
#include <ctime>
#include <cassert>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define INF 1e9
#define EPS 0.0000000001
#define NAME "aquarium"

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;	

using namespace std;

ull sqr (int a)
{
	ull ans;
	ans = a * a;

	return ans;
}	

int d [10000][15], a [15][15], k, n, ans, p [10000][15], m;

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");                                  

	in >> n;
	k = 1;
	ans = INF;	

	for (int i = 1; i <= n; i++)
		k *= 2;	

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> a [i][j];

	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			d [i][j] = inf;	

	for (int i = 0; i < n; i++)
		d [1 << i][i] = 0;

	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
		{
			m = inf;			
			for (int l = 0; l < n; l++)
				if (l != j)
				{
					if (d [i xor (1 << j)][l] + a [l][j] < m)
					{	
						m = d [i xor (1 << j)][l] + a [l][j];
						d [i][j] = m;
						p [i][j] = l;	
					}
				}
		}
	int last;	
	 
	for (int i = 0; i < n; i++)
		if (d [k - 1][i] < ans)
		{
			ans = d [k - 1][i];
			last = i;
		}	

	out << ans << endl;
	int mask = k - 1;

	for (int i = 0; i < n; i++)
	{
		out << last + 1 << " ";
		int pr = last;
		last = p [mask][last];
		mask = mask xor (1 << pr);
	}	

	return 0;

}	