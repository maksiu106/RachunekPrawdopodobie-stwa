//Krzysztof Czarnowus

#include <iostream>
#include <math.h>
#include <random>
#include <fstream>

#define RANGE 9

double count_pi(int n)
{
	int in_circle = 0;
	for (int i=0; i<n; ++i)
	{
		double x = (double)rand()/RAND_MAX;
		double y = (double)rand()/RAND_MAX;
		if (pow(x,2)+pow(y,2)<1) ++in_circle;
	}
	return (double)4*in_circle/n;
}

int main()
{
	double results[RANGE];
	srandom(time(NULL));
	std::ofstream zapis;
	zapis.open ("out.txt");
	for (int i=0; i<RANGE; i++)
	{
		int counts = pow(10,(i+1)); //ilosc wylosowanych liczb, na podstawie ktorych sprobuje sie zgadnac liczbe pi
		results[i] = count_pi(counts);
		std::cout << "Wygenerowanie 10^" << i+1 << " liczb pseudolosowych doprowadzilo do otrzymania wartosci liczby pi rownej: " << results[i] << std::endl;
		zapis << "10e" << i+1 << "\t" << results[i] << std::endl;
	}
	zapis.close();
}
