#include <iostream>
using namespace std;

double max_side(double first, double second)
{
	if (first > second)
	{
		return first;
	}
	else
	{
		return second;
	}
}

double min_side(double first, double second)
{
	if (first < second)
	{
		return first;
	}
	else
	{
		return second;
	}
}

double cut_cake(double length, double width, int pieces) 
{
	double ratio_side, result = 0;
	if (pieces == 1)
	{
		return max_side(length, width) / min_side(length, width);
	}
	for (int i = 1; i < pieces; i++) 
	{
		ratio_side = max_side(cut_cake(i*length / pieces, width, i), cut_cake((pieces - i)*length / pieces, width, (pieces - i)));
		if (result != 0) min_side(ratio_side, result);
		else result = ratio_side;
	}
	for (int j = 1; j < pieces; j++) 
	{
		ratio_side = max_side(cut_cake(length, j*width / pieces, j), cut_cake(length, (pieces - j)*width / pieces, (pieces - j)));
		result = min_side(ratio_side, result);
	}
	return result;
}

int main() {
	double length, width;
	int pieces;
	while (scanf("%lf %lf %li", &length, &width, &pieces)==3)
		printf("%.4lf\n", cut_cake(length, width, pieces));
	system("pause");
	return 0;
}
