#define NAME "a"

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
#include <climits>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <char> vc;
typedef vector <string> vs;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

template <typename T>
T sqr (T a)
{
    return a * a;
}

const int N = 100;

int g [26][26];
int n;
string s [N];
int used [26];
char cycle = 0;

void check (int v)
{
    if (used [v])
    {
        used [v] = 2;
        cycle = 1;
        return;
    }

    used [v] = 1;

    for (int i = 0; i < 26 && !cycle; i++)
        if (g [v][i] && used [i] != 2)
            check (i);

    used [v] = 2;
}

vi ans;

void dfs (int v)
{
    used [v] = 1;

    for (int i = 0; i < 26; i++)
        if (g [v][i] && !used [i])
            dfs (i);

    ans.pb (v);
}

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> s [i];

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            g [i][j] = 0;

    for (int i = 1; i < n; i++)
    {
        string a = s [i - 1];
        string b = s [i];
        char found = 0;

        for (int j = 0; j < min ((int) a.length(), (int) b.length ()); j++)
        {
            if (a [j] == b [j])
                continue;

            g [(int) (a [j] - 'a')][(int) (b [j] - 'a')] = 1;
            found = 1;
            break;
        }

        if (!found && a.length () > b.length ())
        {
            puts ("Impossible");
            return 0;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        memset (used, 0, sizeof (used));
        check (i);

        if (cycle)
        {
            puts ("Impossible");
            return 0;
        }
    }

    memset (used, 0, sizeof (used));

    for (int i = 0; i < 26; i++)
        if (!used [i])
            dfs (i);

    reverse (ans.begin (), ans.end ());

    for (int i = 0; i < 26; i++)
        cout << (char) (ans [i] + 'a');

    cout << endl;

    return 0;
}
