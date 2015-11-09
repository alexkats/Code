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

int l, r;

int main ()
{
    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d %d\n", &l, &r);

    int n1 = r;
    int n2 = l - 1;
    int curr = 1;

    while (1)
    {
        curr++;
        int bad = n1 / curr;
        n1 -= bad;

        if (bad == 0)
            break;
    }

    curr = 1;

    while (1)
    {
        curr++;
        int bad = n2 / curr;
        n2 -= bad;

        if (bad == 0)
            break;
    }

    int ans = n1 - n2;

    printf ("%d\n", ans);

    return 0;
}
