#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int n, m, c, t, k, a [101][101];

int main ()
{

	freopen ("cut.in", "r", stdin);
	freopen ("cut.out", "w", stdout);

	cin >> n >> m;
	cin >> k;

	if ((n * m) % k != 0)
	{
		cout << -1;
		return 0;
	}

	c = 0;
	t = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (c < k)
			{
				if (i % 2 != 0)
				{
					a [i][j] = t;
				} else {
					a [i][m - j + 1] = t;
				}	

				c++;
			} else {	
                        	c = 1;
				t++;

				if (i % 2 != 0)
				{
					a [i][j] = t;
				} else {
					a [i][m - j + 1] = t;
				}	
			}
		}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << a [i][j] << " ";

		cout << endl;
	}	

	return 0;

}	