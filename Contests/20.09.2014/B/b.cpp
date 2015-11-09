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

#define NAME "b"
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

int n, m;
int a [100][100];

int main ()
{
    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    cin >> n >> m;

    rep0(i, n)
        rep0(j, m)
            cin >> a [i][j];

    int ans = INF;
    int ans_1, ans_2;

    rep0(i, m - 1)
        rep(j, i + 1, m)
        {
            int t1 = 0;
            int t2 = 0;
            int t3 = 0;
            int t4 = 0;

            rep0(k, n)
            {
                if (a [k][i] == 1 && a [k][j] == 1)
                    t1++;

                if (a [k][i] == 1 && a [k][j] == 2)
                    t2++;

                if (a [k][i] == 2 && a [k][j] == 1)
                    t3++;

                if (a [k][i] == 2 && a [k][j] == 2)
                    t4++;
            }

            int max_t = -INF;
            max_t = max (t1, max (t2, max (t3, t4)));

            if (max_t < ans)
            {
                ans = max_t;
                ans_1 = i + 1;
                ans_2 = j + 1;
            }
        }

    cout << ans << endl << ans_1 << " " << ans_2 << endl;

    return 0;
}
