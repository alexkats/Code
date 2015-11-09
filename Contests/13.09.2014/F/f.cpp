#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME ""
#define INF (int) 1e9 + 7
#define INFLONG (ll) 1e18 + 7
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

char known [10000];
int a [10000];

int main ()
{
    srand (time (0));
    memset (known, 0, sizeof (known));

    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 0; i < n * 6; i++) {
        int coord = rand () % (n * n);

        while (known [coord])
            coord = rand () % (n * n);

        int x = coord % n;
        int y = (coord - x) / n;
        cout << x + 1 << " " << y + 1 << endl;
        cout.flush ();
        cin >> a [coord];
        known [coord] = 1;
        cnt++;

        if (cnt == (n * n))
            break;
    }

    int m = INF;
    int m_coord = 0;

    for (int i = 0; i < n * n; i++)
        if (known [i] && a [i] < m)
        {
            m = a [i];
            m_coord = i;
        }

    int curr = m_coord;
    
    while (1)
    {
        int x = curr % n;
        int y = (curr - x) / n;
        char br = 0;

        for (int dx = -1; dx < 2; dx++)
        {
            for (int dy = -1; dy < 2; dy++)
            {
                if (dx == 0 && dy == 0)
                    continue;

                if ((y + dy >= 0) && (y + dy < n) && (x + dx >= 0) && (x + dx < n))
                {
                    int tmp = (y + dy) * n + x + dx;

                    if (known [tmp])
                    {
                        if (a [tmp] < a [curr])
                        {
                            curr = tmp;
                            br = 1;
                            break;
                        }
                    }
                    else
                    {
                        cout << (x + dx) + 1 << " " << (y + dy) + 1 << endl;
                        cout.flush ();
                        cin >> a [tmp];
                        known [tmp] = 1;

                        if (a [tmp] < a [curr])
                        {
                            curr = tmp;
                            br = 1;
                            break;
                        }
                    }
                }

                if (br)
                    break;
            }

            if (br)
                break;
        }

        if (!br)
        {
            cout << 0 << " " << 0 << endl;
            cout.flush ();
            cout << x + 1 << " " << y + 1 << endl;
            cout.flush ();
            break;
        }
    }

    return 0;
}
