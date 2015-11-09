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

#define NAME "blind"
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

int n;
int max_p;
int max_t;

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    cin >> n;
    max_p = -INF;
    max_t = -INF;

    rep0(i, n)
    {
        int x, y;
        cin >> x >> y;

        if (y)
            max_t = max (max_t, x);
        else
            max_p = max (max_p, x);
    }

    if (max_t > max_p)
        cout << max_t << endl;
    else
        cout << max_p * 2 - max_t << endl;

    return 0;
}
