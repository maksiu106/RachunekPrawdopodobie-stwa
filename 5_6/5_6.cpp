//Krzysztof Czarnowus

#include <iostream>
#include <math.h>
#include <random>
#include <cstdlib>
#include <fstream>

#define DATA_SIZE 10000000

double generator(int N)
{
	//generuje liczby z otwartego przedziału (0,2) i podnosi do odpowiedniej potęgi
	double x = rand();
	if (x == 0 || x == RAND_MAX) x = rand();
	return (double)(2*x)*(double)(2*x);
}

//argument linii komend - wymiar N-wymiarowego sześcianu
int main(int argc, char *argv[])
{
	int N = atoi(argv[1]);
	int n = 200; //ilość przegródek w pudełku
	double h = (double)pow(2,N)/(double)n; //szerokość przegródki
	double result[n];

	std::ofstream plik("output.txt");
	for (int i=0; i<n; ++i) result[i] = 0; //wypełnianie histogramu zerami

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 2.0);
	for (int i=0; i<DATA_SIZE; ++i) //po tej pętli w tablicy result będzie ilość wpadnięć do pudełka
	{
		double x = pow(dis(gen),N);
		int index = x/h;
		result[index] += 1;
	}

	for (int i=0; i<n; ++i) //normowanie histogramu
	{
		result[i] = result[i]/((double)DATA_SIZE*h);
	}

	plik << "x\tf(x)" << std::endl;
	for (int i=0; i<n; ++i)
	{
		plik << ((double)i*h)+(h/2.0) << "\t" << result[i] << std::endl;
	}

	plik.close();
}
