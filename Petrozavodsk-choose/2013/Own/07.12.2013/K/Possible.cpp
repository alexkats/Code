#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <utility>
#include <time.h>
#include <vector>
#include <algorithm>


#define pb push_back
#define pp pop_back
#define mp make_pair
#define infint 1e9
#define inflong 1e18
#define fori0 for(int i = 0; i < m; i++)
#define forj0 for(int j = 0; j < m; j++)
#define fori1 for(int i = 1; i <= n; i++)
#define forj1 for(int j = 1; j <= n; j++)
#define forxx(i, n, s) for(int i = 0; i < n; i += s)
#define name "xo"


typedef long long ll;
typedef unsigned long long ull;


using namespace std;

int curr = 0, a[105][105], qo = 0, qx = 0, Xmaxg = 0, Xmaxgi = 0, Xmaxgj= 0, Omaxg= 0, Omaxgi = 0, Omaxgj= 0, Xmaxv= 0, Xmaxvi = 0, Xmaxvj = 0, Omaxv = 0, Omaxvi = 0, Omaxvj = 0, n = 0, m = 0, tmx = 0, tmo = 0;
string s;
bool err = 0;

void solve()
{
	Xmaxg = 0;
	Xmaxv = 0;
	Omaxg = 0;
	Omaxv = 0;
	tmo = 0;
	tmx = 0;
	fori0
    	forj0
    	{
    		if (a[i][j] == 'X')	
    			tmx++;
    		else
    		{	if (tmx > Xmaxg)
    			{
    				if (Xmaxg == 5)
    					err = 1;
    				Xmaxg = tmx;
    			}
    			tmx = 0;
    	    }
    	    if (a[i][j] == 'O')	
    			tmo++;
    		else
    		{	if (tmo > Omaxg)
    			{
    				if (Omaxg == 5)
    					err = 1;
    				Omaxg = tmo;
    			}
    			tmo = 0;
    	    }
    	}
    forj0
    	fori0
       	{
    		if (a[i][j] == 'X')	
    			tmx++;
    		else
    		{	if (tmx >= Xmaxv)
    			{
    				if (Xmaxv >= 5)
    					err = 1; 
    				Xmaxv = tmx;
    			}
    			tmx = 0;
    	    }
    	    if (a[i][j] == 'O')	
    			tmo++;
    		else
    		{
    			if (tmo >= Omaxv)
				{
					if (Omaxv >= 5)
						err = 1;
					Omaxv = tmo;
				}
    			tmo = 0;
    	    }
    	}
    if(max(max(Xmaxg, Xmaxv), max(Omaxg, Omaxv)) >= 5)
    	err = 1;
}
 

int main()
{
    freopen(name".in", "r", stdin);
    freopen(name".out", "w", stdout);
    while (cin >> s)
    {
    	n = max (n, (int) s.length ());
 
        for(int i = 0; i < (int) s.length (); i++)
        	if (s [i] == 'X')
            {
            	a [i][curr] = 'X';
                qx++;
            }      
            else if (s [i] == 'O')
            {
            	a [i][curr] = 'O';
                qo++;
            }      
            else
            	a [i][curr] = '.';     
 
       	curr++;
        m = curr;
    }

    fori0
    	forj0
    	{
    		if (a[i][j] == 'X')	
    			tmx++;
    		else
    		{	if (tmx > Xmaxg)
    			{
    				if (Xmaxg >= 5)
    					err = 1;
    				Xmaxg = tmx;
    				Xmaxgi = i;
    				Xmaxgj = j;
    			}
    			tmx = 0;
    	    }
    	    if (a[i][j] == 'O')	
    			tmo++;
    		else
    		{	if (tmo > Omaxg)
    			{
    				if (Omaxg >= 5)
    					err = 1;
    				Omaxg = tmo;
    				Omaxgi = i;
    				Omaxgj = j;
    			}
    			tmo = 0;
    	    }
    	}
    if (tmx > Xmaxg)
    			{
    				if (Xmaxg >= 5)
    					err = 1;
    				Xmaxg = tmx;
    				Xmaxgi = n;
    				Xmaxgj = m;
    			}
    if (tmo > Omaxg)
    			{
    				if (Omaxg >= 5)
    					err = 1;
    				Omaxg = tmo;
    				Omaxgi = n;
    				Omaxgj = m;
    			}

    forj0
    	fori0
       	{
    		if (a[i][j] == 'X')	
    			tmx++;
    		else
    		{	if (tmx >= Xmaxv)
    			{
    				if (Xmaxv >= 5)
    					err = 1; 
    				Xmaxv = tmx;
    				Xmaxvi = i;
    				Xmaxvj = j;
    			}
    			tmx = 0;
    	    }
    	    if (a[i][j] == 'O')	
    			tmo++;
    		else
    		{	if (tmo >= Omaxv)
				{
					if (Omaxv >= 5)
						err = 1;
					Omaxv = tmo;
					Omaxvi = i;
					Omaxvj = j;
				}
    			tmo = 0;
    	    }
    	}
    if (tmx >= Xmaxv)
    			{
    				if (Xmaxv >= 5)
    					err = 1; 
    				Xmaxv = tmx;
    				Xmaxvi = n;
    				Xmaxvj = m;
    			}

    if (tmo >= Omaxv)
				{
					if (Omaxv >= 5)
						err = 1;
					Omaxv = tmo;
					Omaxvi = n;
					Omaxvj = m;
				}

    if (qx - qo < 0 || qx > qo + 1)
    	err = 1;

    if (max(Xmaxg, Xmaxv) >= 5 && qx == qo)
    	err = 1;

    if (max(Omaxg, Omaxv) >= 5 && qx == qo + 1)
    	err = 1;


    if (max(Xmaxg, Xmaxv) >= 5 && max(Omaxg, Omaxv) >= 5)
    	err = 1;

    if (Xmaxg > 9 || Xmaxv > 9 || Omaxg > 9 || Omaxv > 9)
    	err = 1;


    if (Xmaxg >= 5 && Xmaxv >= 5)
    {
    	if (Xmaxgj - Xmaxg <= Xmaxvj && Xmaxgj >= Xmaxvj && Xmaxvi - Xmaxv <= Xmaxgi && Xmaxvi >= Xmaxgi)
    	{
    	    a[Xmaxgi][Xmaxvj] = '.';
    		solve();
    	}
    	else
    		err = 1;
    }	

    if (Omaxg >= 5 && Omaxv >= 5)
    {
    	if (Omaxgj - Omaxg <= Omaxvj && Omaxgj >= Omaxvj && Omaxvi - Omaxv <= Omaxgi && Omaxvi >= Omaxgi)
    	{
    		a[Omaxgi][Omaxvj] = '.';
    		solve();
    	}
    	else
    		err = 1;
    }	
		

    if (err)
    	cout << "INCORRECT";
    else
    	cout << "CORRECT";
    
    	    
    return 0;
}