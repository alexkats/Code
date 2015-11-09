#define NAME "d"

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

vpii all;

void find_all (int k)
{
    for (int i = 1; i * i <= k; i++)
        if (k % i == 0)
            all.pb (mp (i, k / i));
}

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    int n;
    cin >> n;
    vi a (n);
    int q1 = 0;
    int q2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a [i];
        
        if (a [i] == 1)
            q1++;
        else
            q2++;
    }

    set <pii> ans;
    find_all (q1);
    vpii searching;
    int curr = (int) all.size () - 1;

    if (curr > -1 && all [curr].frs == all [curr].snd)
        curr--;

    for (int i = curr; i > -1; i--)
        all.pb (mp (all [i].snd, all [i].frs));

    for (int i = 0; i < (int) all.size (); i++)
        searching.pb (all [i]);

    all.clear ();

    if (q1 != q2)
    {
        find_all (q2);
        curr = (int) all.size () - 1;

        if (curr > -1 && all [curr].frs == all [curr].snd)
            curr--;

        for (int i = curr; i > -1; i--)
            all.pb (mp (all [i].snd, all [i].frs));

        for (int i = 0; i < (int) all.size (); i++)
            searching.pb (all [i]);

        all.clear ();
    }

    for (int i = 0; i < (int) searching.size (); i++)
        all.pb (searching [i]);

    searching.clear ();
    sort (all.begin (), all.end ());
    curr = (int) all.size ();

    for (int i = 0; i < curr; i++)
    {
        int s = all [i].frs;
        int t = all [i].snd;
        pii curr_in_game = mp (0, 0);
        pii curr_in_set = mp (0, 0);
        char bad = 0;

        for (int j = 0; j < n; j++)
        {
            if (curr_in_game.frs == s || curr_in_game.snd == s)
            {
                bad = 1;
                break;
            }

            if (a [j] == 1)
                curr_in_set.frs++;
            else
                curr_in_set.snd++;

            if (curr_in_set.frs == t || curr_in_set.snd == t)
            {
                if (curr_in_set.frs == t)
                    curr_in_game.frs++;
                else
                    curr_in_game.snd++;

                curr_in_set = mp (0, 0);

            }
        }

        int m = max (curr_in_game.frs, curr_in_game.snd);

        if (curr_in_game.frs == curr_in_game.snd)
            m = -1;

        if (!bad && m == s && curr_in_set == mp (0, 0))
            ans.insert (all [i]);
    }

    vpii final_ans;

    while (!ans.empty ())
    {
        final_ans.pb (*ans.begin ());
        ans.erase (ans.begin ());
    }

    sort (final_ans.begin (), final_ans.end ());
    cout << (int) final_ans.size () << endl;

    for (int i = 0; i < (int) final_ans.size (); i++)
        cout << final_ans [i].frs << " " << final_ans [i].snd << endl;

    return 0;
}
