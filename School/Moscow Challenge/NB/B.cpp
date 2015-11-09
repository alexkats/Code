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

long long k = 0;
int i;
double t, ch, n [1000001], m [1000001];

int main ()
{

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> t;
	ch = sqrt (t);

	for (int i = 1; i <= floor (ch); i++)
	{
		if (floor ((t - 1 + i) / (2 * i + 1)) == (t - 1 + i) / (2 * i + 1) && i <= (t - 1 + i) / (2 * i + 1))
		{
			k++;
			m [k] = i;
			n [k] = (t - 1 + i) / (2 * i + 1);
		}
		else
		{
			if (floor ((t - i) / (2 * i - 1)) == (t - i) / (2 * i - 1) && i < (t - i) / (2 * i - 1))
			{
				k++;
				m [k] = i;
				n [k] = (t - i) / (2 * i - 1);
			}
			else
			{
				if (floor ((t + i) / (2 * i + 1)) == (t + i) / (2 * i + 1) && i < (t + i) / (2 * i + 1))
				{
					k++;
					n [k] = i;
					m [k] = (t + i) / (2 * i + 1);
				}
				else
				{
					if (floor ((t - i - 1) / (2 * i - 1)) == (t - i - 1) / (2 * i - 1) && i < (t - i - 1) / (2 * i - 1))
					{
						k++;
						n [k] = i;
						m [k] = (t - i - 1) / (2 * i - 1);
					}
				}
			}
		}
	}

	cout << k << endl;

	for (int i = 1; i <= k; i++)
		cout << floor (n [i]) << " " << floor (m [i]) << endl;

	return 0;

}	