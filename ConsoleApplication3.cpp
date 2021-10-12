#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double xp, xk, x, dx, eps, a, R, S;
	int n;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(10) << "x" << " |"
		<< setw(10) << "arcth(x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;
	 
		x = xp;
		while (x <= xk && abs(x)>1)
		{
			n = 0;
			a = 1.0 / x;
			S = a;
			do {
				R = (2 * n + 1) / ((2 * n + 3) * x * x);
				n++;
				a *= R;
				S += a;
			} while (abs(a) >= eps);

			cout << "|" << setw(10) << setprecision(2) << x << " |"
				<< setw(10) << setprecision(5) << atanh(1.0 / x) << " |"
				<< setw(10) << setprecision(5) << S << " |"
				<< setw(5) << n << " |"
				<< endl;
		   x += dx;
	}
	cout << "-------------------------------------------------" << endl;
	
	return 0;
}

