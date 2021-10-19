#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;


float touch(float x)
{
	float y{ 228 };
	return y;
}


float _funcdif(float x)
{
	float y_ = -x + 7 - (4 / x);
	return y_;
}


float _funcSecondDif(float x)
{
	float y_ = -2;
	return y_;
}


float _func(float x)
{
	return -(x * x) + 7 * x - 4 * log(x) - 7;
}


float diff(float x)
{
	return(3 * pow(x, 2) - 2 * x - 7);
}


float diff2(float x)
{
	return(6 * x - 2);
}


bool checkSign(float y)
{
	if (y > 0)
		return true;
	else
		return false;
}


float fi(float x)
{
	return x - _func(x) / _funcdif(x);
}


float rec(float a, float b, float e, int& iter)
{
	float x0 = (a + b) / 2;
	iter++;

	//Приближенный корень
	if (b - a < 2 * e)
		return x0;
	else
	{
		if (_func(a) * _func(x0) < 0)
			return rec(a, x0, e, iter);
		else
			return rec(x0, b, e, iter);
	}
}


void _Newton_method(float a, float b)
{
	float  x0;

	if (_func(a) * _func(b) < 0)
	{
		for (float e = 0.1; e >= 0.0001; e *= 0.1)
		{
			int iter = 0;
			x0 = rec(a, b, e, iter);
			cout << "x = " << x0 << endl;
			cout << "e = " << e << endl;
			cout << "Кол-во итераций = " << iter << endl;
			cout << endl;
		}
	}
	else
		cout << "Неподходящий отрезок" << endl;
}


void _falseposition_method(float a, float b)
{
	float x0{ a };
	for (float e = 0.1; e >= 0.0001; e *= 0.1)

}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float a{ 1 }, b{ 2 };

	cout << "======метод ньютона======" << endl;
	_Newton_method(a,b);

	//cout << "======метод простых итераций======" << endl;

	cout << "======метод хорд======" << endl;
	_falseposition_method(a, b);
}