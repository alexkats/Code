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

#define NAME "f"
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

char good [105][105];
int a [105][105];
int n;

char all_good (int x, int y)
{
    if (good [x - 1][y + 1] && a [x - 1][y + 1] != (int) 1e9)
        return 0;

    if (good [x][y + 1] && a [x][y + 1] != (int) (1e9))
        return 0;

    if (good [x + 1][y + 1] && a [x + 1][y + 1] != (int) (1e9))
        return 0;

    if (good [x - 1][y] && a [x - 1][y] != (int) (1e9))
        return 0;

    if (good [x + 1][y] && a [x + 1][y] != (int) (1e9))
        return 0;

    if (good [x - 1][y - 1] && a [x - 1][y - 1] != (int) (1e9))
        return 0;

    if (good [x][y - 1] && a [x][y - 1] != (int) (1e9))
        return 0;

    if (good [x + 1][y - 1] && a [x + 1][y - 1] != (int) (1e9))
        return 0;

    return 1;
}

char ok (int x, int y)
{
    if (good [x][y] == 0 || good [x][y] == 2)
        return 1;
    else
        return 0;
}

int main ()
{
    cin >> n;
    int x = 1;
    int y = 1;

    rep0(i, (n + 2))
        rep0(j, (n + 2))
        {
            good [i][j] = 2;
            a [i][j] = (int) 1e9;
        }

    rep0(i, (n + 2))
    {
        good [0][i] = 1;
        good [i][0] = 1;
        good [n + 1][i] = 1;
        good [i][n + 1] = 1;
    }

    while (1)
    {
        if (!good [x][y])
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (a [x][y] == (int) 1e9)
        {
            cout << x << " " << y << endl;
            cout.flush ();
            cin >> a [x][y];
        }

        char fin = 0;
        char used = 0;

        if (!ok (x - 1, y - 1) && x != 1 && y != 1)
            fin = 1;
        
        if (ok (x - 1, y - 1) && a [x - 1][y - 1] == (int) 1e9 && x != 1 && y != 1)
        {
            fin = 1;
            cout << x - 1 << " " << y - 1 << endl;
            cout.flush ();
            cin >> a [x - 1][y - 1];
        }

        if (a [x - 1][y - 1] > a [x][y])
        {
            fin = 0;
            good [x - 1][y - 1] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x - 1][y - 1] == a [x][y])
            good [x][y] = good [x - 1][y - 1] = 0;
        else
            good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (!ok (x, y - 1) && y != 1)
            fin = 1;

        if (ok (x, y - 1) && a [x][y - 1] == (int) 1e9 && y != 1)
        {
            fin = 1;
            cout << x << " " << y - 1 << endl;
            cout.flush ();
            cin >> a [x][y - 1];
        }

        if (a [x][y - 1] > a [x][y])
        {
            fin = 0;
            good [x][y - 1] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x][y - 1] == a [x][y])
            good [x][y] = good [x][y - 1] = 0;
        else
            if (!used)
                good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (!ok (x + 1, y - 1) && x != n && y != 1)
            fin = 1;

        if (ok (x + 1, y - 1) && a [x + 1][y - 1] == (int) 1e9 && x != n && y != 1)
        {
            fin = 1;
            cout << x + 1 << " " << y - 1 << endl;
            cout.flush ();
            cin >> a [x + 1][y - 1];
        }

        if (a [x + 1][y - 1] > a [x][y])
        {
            fin = 0;
            good [x + 1][y - 1] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x + 1][y - 1] == a [x][y])
            good [x][y] = good [x + 1][y - 1] = 0;
        else
            if (!used)
                good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (!ok (x - 1, y) && x != 1)
            fin = 1;

        if (ok (x - 1, y) && a [x - 1][y] == (int) 1e9 && x != 1)
        {
            fin = 1;
            cout << x - 1 << " " << y << endl;
            cout.flush ();
            cin >> a [x - 1][y];
        }

        if (a [x - 1][y] > a [x][y])
        {
            fin = 0;
            good [x - 1][y] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x - 1][y] == a [x][y])
            good [x][y] = good [x - 1][y] = 0;
        else
            if (!used)
                good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (!ok (x + 1, y) && x != n)
            fin = 1;

        if (ok (x + 1, y) && a [x + 1][y] == (int) 1e9 && x != n)
        {
            fin = 1;
            cout << x + 1 << " " << y << endl;
            cout.flush ();
            cin >> a [x + 1][y];
        }

        if (a [x + 1][y] > a [x][y])
        {
            fin = 0;
            good [x + 1][y] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x + 1][y] == a [x][y])
            good [x][y] = good [x + 1][y] = 0;
        else
            if (!used)
                good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (!ok (x - 1, y + 1) && x != 1 && y != n)
            fin = 1;

        if (ok (x - 1, y + 1) && a [x - 1][y + 1] == (int) 1e9 && x != 1 && y != n)
        {
            fin = 1;
            cout << x - 1 << " " << y + 1 << endl;
            cout.flush ();
            cin >> a [x - 1][y + 1];
        }

        if (a [x - 1][y + 1] > a [x][y])
        {
            fin = 0;
            good [x - 1][y + 1] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x - 1][y + 1] == a [x][y])
            good [x][y] = good [x - 1][y + 1] = 0;
        else
            if (!used)
                good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (!ok (x, y + 1) && y != n)
            fin = 1;

        if (ok (x, y + 1) && a [x][y + 1] == (int) 1e9 && y != n)
        {
            fin = 1;
            cout << x << " " << y + 1 << endl;
            cout.flush ();
            cin >> a [x][y + 1];
        }

        if (a [x][y + 1] > a [x][y])
        {
            fin = 0;
            good [x][y + 1] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x][y + 1] == a [x][y])
            good [x][y] = good [x][y + 1] = 0;
        else
            if (!used)
                good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }
        
        if (!ok (x + 1, y + 1) && x != n && y != n)
            fin = 1;

        if (ok (x + 1, y + 1) && a [x + 1][y + 1] == (int) 1e9 && x != n && y != n)
        {
            fin = 1;
            cout << x + 1 << " " << y + 1 << endl;
            cout.flush ();
            cin >> a [x + 1][y + 1];
        }

        if (a [x + 1][y + 1] > a [x][y])
        {
            fin = 0;
            good [x + 1][y + 1] = 0;
            good [x][y] = 1;
            used = 1;
        }
        else if (a [x + 1][y + 1] == a [x][y])
            good [x][y] = good [x + 1][y + 1] = 0;
        else
            if (!used)
                good [x][y] = 0;

        if (fin)
        {
            if (x == n)
            {
                x = 1;
                y++;
            }
            else
                x++;

            continue;
        }

        if (all_good (x, y))
        {
            cout << 0 << " " << 0 << endl;
            cout.flush ();
            cout << x << " " << y << endl;
            cout.flush ();
            break;
        }

        if (!used)
            good [x][y] = 0;
        else
            good [x][y] = 1;

        if (x == n)
        {
            x = 1;
            y++;
        }
        else
            x++;
    }

    return 0;
}
