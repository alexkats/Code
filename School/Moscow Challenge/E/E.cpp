#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long n, m, price [501], start [501], finish [501], enter, money, length, quit, sum, r [501], q, m1;
bool result;

void search (long long &sum)
{
	if (sum == money)
	{
		result = true;
		return;
	}

	for (int i = 1; i <= q; i++)
	{
		sum -= price [r [i]];

		if (result || sum <= 0)
		{
			sum += price [r [i]];
			return;
		}	

		search (sum);
		sum += price [r [i]];
	}
} 

int main ()
{

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> price [i] >> start [i] >> finish [i];

	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> enter >> money >> length;	
		quit = enter + length;
		result = false;
		q = 0;
		m1 = 1e5;
		sum = 0;

		for (int j = 1; j <= n; j++)
		{
		        if (start [j] <= enter && finish [j] > quit && price [j] <= money)
			{
				q++;
				r [q] = j;
				m1 = min (m1, price [j]);
				sum += price [j];

				if (price [j] == money)
				{
					cout << "YES" << endl;
					result = true;
					break;
				}	

				if (sum == money)
				{
					cout << "YES" << endl;
					result = true;
					break;
				}	
			}
		}

		if (result)
			continue;

		if (q == 0)
		{
			cout << "NO" << endl;
			break;
		}

		if (money > sum)
		{
			cout << "NO" << endl;
			continue;
		}

		if (money == sum)
		{
			cout << "YES" << endl;
			continue;
		}	
                
          	if (q == 1 && money != m1)
		{
			cout << "NO" << endl;
			continue;
		}				           

		if (money < m1)
		{
			cout << "NO" << endl;
			continue;
		}

		if (money == m1)
		{
			cout << "YES" << endl;
			continue;
		}	

		search (sum);

		if (result)
		{
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}	

	return 0;

}	