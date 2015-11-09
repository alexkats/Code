#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main ()
{

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> x_king_black >> y_king_black >> x_rook1 >> y_rook1 >> x_rook2 >> y_rook2 >> x_king_white >> y_king_white;

	x_flag = false;
	y_flag = false;
	warn_rook1 = false;
	warn_rook2 = false;
	good = false;	

	if (x_rook1 == x_rook2 && (x_king_white != x_rook1 || max (y_rook1, y_rook2) - y_king_white > abs (y_rook1 - y_rook2)))
		x_flag = true;

	if (y_rook1 == y_rook2 && (y_king_white != y_rook1 || max (x_rook1, x_rook2) - x_king_white > abs (x_rook1 - x_rook2)))
		y_flag = true;

	if (abs (x_rook1 - x_king_black) == 1 && abs (y_rook1 - y_king_black) == 1)
		warn_rook1 = true;

	if (abs (x_rook2 - x_king_black) == 1 && abs (y_rook2 - y_king_black) == 1)
		warn_rook2 = true;

	if (warn_rook1 && warn_rook2)
	{
		good = true;

		if (!x_flag && !y_flag)
		{
			cout << "R1 0 " << y_rook2 - y_rook1 << endl;
			y_rook1 += (y_rook2 - y_rook1);
			cout.flush ();
			cin >> x >> y;

			if (x == 0 && y == 0)
				return 0;

			x_king_black += x;
			y_king_black += y;
		}
	}

	if ((warn_rook1 || warn_rook2) && !good)
	{
		if (x_rook1 == x_rook2 || y_rook1 == y_rook2)
		{
			if (x_rook1 == x_rook2 && !x_flag)
			{
				cout << "K 1 0" << endl;
				x_king_white++;
				cout.flush ();
				cin >> x >> y;

				if (x == 0 && y == 0)
					return 0;

				x_king_black += x;
				y_king_black += y;
			}
			else
			
			if (y_rook1 == y_rook2 && !y_flag)
			{
				cout << "K 0 1" << endl;
				y_king_white++;
				cout.flush ();
				cin >> x >> y;

				if (x == 0 && y == 0)
					return 0;

				x_king_black += x;
				y_king_black += y;
			}

			if (warn_rook1)
			{
				if (x_rook1 == x_king_black + 1)
				{
					if (y_rook1 == y_king_black + 1)
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R1 3 0" << endl;
								cout.flush ();
								x_rook1 += 3;
								cin >> x >> y;
       	
								if (x == 0 && y == 0)
									return 0;
       	
								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R1 -5 0" << endl;
								cout.flush ();
								x_rook1 -= 5;
								cin >> x >> y;
       	
								if (x == 0 && y == 0)
									return 0;
       	
								x_king_black += x;
								y_king_black += y;
							}
						}
						else
						{
							if (y_king_white < y_king_black)
							{
								cout << "R1 0 3" << endl;
								cout.flush ();
								y_rook1 += 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R1 0 -5" << endl;
								cout.flush ();
								y_rook1 -= 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
					}
					else
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R1 3 0" << endl;
								cout.flush ();
								x_rook1 += 3;
								cin >> x >> y;

				                        	if (x == 0 & y == 0)
				                        		return 0;

				                        	x_king_black += x;
				                        	y_king_black += y;
				                        }
				                        else
				                        {
				                        	cout << "R1 -5 0" << endl;
				                        	cout.flush ();
				                        	x_rook1 += 5;
				                        	cin >> x >> y;

				                        	if (x == 0 && y == 0)
				                        		return 0;

				                        	x_king_black += x;
				                        	y_king_black += y;
				                 	}
				                 }
				                 else
				                 {
				                 	if (y_king_white < y_king_black)
				                 	{
				                 		cout << "R1 0 5" << endl;
				                 		cout.flush ();
				                 		y_rook1 += 5;
				                 		cin >> x >> y;

				                 		if (x == 0 && y == 0)
				                 			return 0;

				                 		x_king_black += x;
				                 		y_king_black += y;
				                 	}
				                 	else
				                 	{
				                 		cout << "R1 0 -3" << endl;
				                 		cout.flush ();
				                 		y_rook1 -= 3;
				                 		cin >> x >> y;

				                 		if (x == 0 && y == 0)
				                 			return 0;

				                 		x_king_black += x;
				                 		y_king_black += y;
				                 	}
				            	}
				        }
				}
				else
				{
					if (y_rook1 == y_king_black + 1)
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R1 5 0" << endl;
								cout.flush ();
								x_rook1 += 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R1 -3 0" << endl;
								cout.flush ();
								x_rook1 -= 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
						else
						{
							if (y_king_white < y_king_black)
							{
								cout << "R1 0 3" << endl;
								cout.flush ();
								y_rook1 += 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R1 0 -5" << endl;
								cout.flush ();
								y_rook1 -= 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
					}
					else
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R1 5 0" << endl;
								cout.flush ();
								x_rook1 += 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R1 -3 0" << endl;
								cout.flush ();
								x_rook1 -= 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
						else
						{
							if (y_king_white < y_king_black)
							{
								cout << "R1 0 5" << endl;
								cout.flush ();
								y_rook1 += 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R1 0 -3" << endl;
								cout.flush ();
								y_rook1 -= 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
					}
				}
			}
			else
			{
				if (x_rook2 == x_king_black + 1)
				{
					if (y_rook2 == y_king_black + 1)
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R2 3 0" << endl;
								cout.flush ();
								x_rook2 += 3;
								cin >> x >> y;
       	
								if (x == 0 && y == 0)
									return 0;
       	
								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R2 -5 0" << endl;
								cout.flush ();
								x_rook2 -= 5;
								cin >> x >> y;
       	
								if (x == 0 && y == 0)
									return 0;
       	
								x_king_black += x;
								y_king_black += y;
							}
						}
						else
						{
							if (y_king_white < y_king_black)
							{
								cout << "R2 0 3" << endl;
								cout.flush ();
								y_rook2 += 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R2 0 -5" << endl;
								cout.flush ();
								y_rook2 -= 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
					}
					else
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R2 3 0" << endl;
								cout.flush ();
								x_rook2 += 3;
								cin >> x >> y;

				                        	if (x == 0 & y == 0)
				                        		return 0;

				                        	x_king_black += x;
				                        	y_king_black += y;
				                        }
				                        else
				                        {
				                        	cout << "R2 -5 0" << endl;
				                        	cout.flush ();
				                        	x_rook2 += 5;
				                        	cin >> x >> y;

				                        	if (x == 0 && y == 0)
				                        		return 0;

				                        	x_king_black += x;
				                        	y_king_black += y;
				                 	}
				                 }
				                 else
				                 {
				                 	if (y_king_white < y_king_black)
				                 	{
				                 		cout << "R2 0 5" << endl;
				                 		cout.flush ();
				                 		y_rook2 += 5;
				                 		cin >> x >> y;

				                 		if (x == 0 && y == 0)
				                 			return 0;

				                 		x_king_black += x;
				                 		y_king_black += y;
				                 	}
				                 	else
				                 	{
				                 		cout << "R2 0 -3" << endl;
				                 		cout.flush ();
				                 		y_rook2 -= 3;
				                 		cin >> x >> y;

				                 		if (x == 0 && y == 0)
				                 			return 0;

				                 		x_king_black += x;
				                 		y_king_black += y;
				                 	}
				            	}
				        }
				}
				else
				{
					if (y_rook2 == y_king_black + 1)
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R2 5 0" << endl;
								cout.flush ();
								x_rook2 += 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R2 -3 0" << endl;
								cout.flush ();
								x_rook2 -= 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
						else
						{
							if (y_king_white < y_king_black)
							{
								cout << "R2 0 3" << endl;
								cout.flush ();
								y_rook2 += 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R2 0 -5" << endl;
								cout.flush ();
								y_rook2 -= 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
					}
					else
					{
						if (x_rook1 != x_rook2)
						{
							if (x_king_white < x_king_black)
							{
								cout << "R2 5 0" << endl;
								cout.flush ();
								x_rook2 += 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R2 -3 0" << endl;
								cout.flush ();
								x_rook2 -= 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
						else
						{
							if (y_king_white < y_king_black)
							{
								cout << "R2 0 5" << endl;
								cout.flush ();
								y_rook2 += 5;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
							else
							{
								cout << "R2 0 -3" << endl;
								cout.flush ();
								y_rook2 -= 3;
								cin >> x >> y;

								if (x == 0 && y == 0)
									return 0;

								x_king_black += x;
								y_king_black += y;
							}
						}
					}
				}
			}
		}
	}	

	if (!good)
	{
		if (x_rook1 != x_king_white && y_rook2 != y_king_white)
		{
			while (abs (x_rook1 - x_rook2) > 100)
			{
				cout << "R1 " << (x_rook2 - x_rook1) / abs (x_rook2 - x_rook1) * 100 << " 0" << endl;
				cout.flush ();
			}

			cout << "R1 " << x_rook2 - x_rook1 << " 0" << endl;
			cout.flush ();
		}
		else
		{
			while (abs (y_rook1 - y_rook2) > 100)
			{
				cout << "R1 0 " << (y_rook2 - y_rook1) / abs (y_rook2 - y_rook1) * 100 << endl;
				cout.flush ();
			}

			cout << "R1 0 " << y_rook2 - y_rook1 << endl;
			cout.flush ();
		}	
	
	for (int i = 1; i <= 100; i++)
	{
		cin >> dx >> dy;

		if (dx == 0 && dy == 0)
			return 0;

			

		cout.flush ();	

	return 0;

}	