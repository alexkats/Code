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

#define NAME "divisors"
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

string NumberToString (int x)
{
    ostringstream ss;
    ss << x;
    return ss.str ();
}

char is_prime (int x)
{
    for (int i = 2; i <= floor (sqrt (x)); i++)
        if (x % i == 0)
            return 0;

    return 1;
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    
    int n;
    cin >> n;
    string ans = "9999999999";

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0 && is_prime (i))
            if (NumberToString (i) < ans)
                ans = NumberToString (i);
    }

    if (ans == "9999999999")
        ans = NumberToString (n);

    cout << ans << endl;

    return 0;
}
