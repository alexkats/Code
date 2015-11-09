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

#define NAME "clock"
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

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    int a, b;
    cin >> a >> b;
    int ans1_h, ans1_m, ans2_h, ans2_m;

    if (a % 12 != 0 && b % 12 != 0)
    {
        puts ("No solution");
        return 0;
    }

    if (a % 12 == 0)
        ans1_m = a / 6;
    else
        ans1_m = 60;

    if (b % 12 == 0)
        ans2_m = b / 6;
    else
        ans2_m = 60;

    int dm1 = ans1_m / 2;
    int dm2 = ans2_m / 2;

    if ((b - dm1) % 30 == 0 && ans1_m < 60)
    {
        ans1_h = (b - dm1) / 30;
        
        if (ans1_h < 10)
            cout << "0";

        cout << ans1_h << ":";

        if (ans1_m < 10)
            cout << "0";

        cout << ans1_m << endl;
        return 0;
    }

    if ((a - dm2) % 30 == 0 && ans2_m < 60)
    {
        ans2_h = (a - dm2) / 30;

        if (ans2_h < 10)
            cout << "0";

        cout << ans2_h << ":";

        if (ans2_m < 10)
            cout << "0";

        cout << ans2_m << endl;
        return 0;
    }

    puts ("No solution");

    return 0;
}
