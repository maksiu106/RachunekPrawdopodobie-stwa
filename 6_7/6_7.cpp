//Krzysztof Czarnowus

#include <iostream>
#include <math.h>
#include <random>
#include <cstdlib>

double generator()
{
	double sum = 0;
	for (int i = 0; i<3; ++i) {
		sum += pow(sqrt((-2.0)*log((double)rand()/(double)RAND_MAX)) * cos(2.0*M_PI*(double)rand()/(double)RAND_MAX), 2);
	}
	return sum;
}

//argument linii komend - ilość wygenerowanych liczb
int main(int argc, char *argv[])
{
	int N = atoi(argv[1]);
	int n = 100; //ilość przegródek w pudełku
	double h = 10.0/(double)n; //szerokość przegródki
	srand(time(NULL));
	std::cout << "Wyniki dla" << std::endl << "N = " << N << std::endl << "n = " << n << std::endl << "h = " << h << std::endl << std::endl;

	double result[n];
	for (int i=0; i<n; ++i) result[i] = 0; //wypełnianie histogramu zerami

	for (int i=0; i<N; ++i) //po tej pętli w tablicy result będzie ilość wpadnięć do pudełka
	{
		double x = generator();
		int index = x/h;
		if (index < n) result[index] += 1;
	}

	for (int i=0; i<n; ++i) //normowanie histogramu
	{
		result[i] = result[i]/((double)N*h);
	}

	std::cout << "Srodek przegrodki\tWartosc" << std::endl;
	for (int i=0; i<n; ++i)
	{
		std::cout << ((double)i*h)+(h/2.0) << "\t" << result[i] << std::endl;
	}
}
