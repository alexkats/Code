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

#define NAME "scarecrow"
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
vector <int> a;
vector <int> full [100005];
int k;

char is_sorted ()
{
    rep0(i, (n - 1))
        if (a [i] > a [i + 1])
            return 0;

    return 1;
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &k);

    rep0(i, n)
    {
        int x;
        scanf ("%d", &x);
        a.pb (x);
    }

    rep0(i, k)
    {
        int j = i;
        
        while (j < n)
        {
            full [i].pb (a [j]);
            j += k;
        }

        sort (full [i].begin (), full [i].end ());

        j = i;
        int curr = 0;

        while (j < n)
        {
            a [j] = full [i][curr++];
            j += k;
        }

        full [i].clear ();
    }

    if (is_sorted ())
        puts ("YES");
    else
        puts ("NO");

    return 0;
}
