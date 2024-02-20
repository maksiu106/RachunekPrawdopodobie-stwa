//Krzysztof Czarnowus

#include <iostream>
#include <math.h>
#include <random>
#include <cstdlib>

double generator()
{
	double x = (double)rand()/(double)RAND_MAX;
	if (x < 1.0/6.0) return (sqrt(6.0*x) - 1.0);
	else if (x > 5.0/6.0) return (3.0 - sqrt(6.0-6.0*x));
	else return (3.0*x - 0.5);
}

//argument linii komend - ilość wygenerowanych liczb
int main(int argc, char *argv[])
{
	int N = atoi(argv[1]);
	int n = 100; //ilość przegródek w pudełku
	double h = 4.0/(double)n; //szerokość przegródki
	srand(time(NULL));
	std::cout << "Wyniki dla" << std::endl << "N = " << N << std::endl << "n = " << n << std::endl << "h = " << h << std::endl << std::endl;

	double result[n];
	for (int i=0; i<n; ++i) result[i] = 0; //wypełnianie histogramu zerami

	for (int i=0; i<N; ++i) //po tej pętli w tablicy result będzie ilość wpadnięć do pudełka
	{
		double x = generator();
		int index = (x+1)/h;
		result[index] += 1;
	}

	for (int i=0; i<n; ++i) //normowanie histogramu
	{
		result[i] = result[i]/((double)N*h);
	}

	std::cout << "Srodek przegrodki\tWartosc" << std::endl;
	for (int i=0; i<n; ++i)
	{
		std::cout << ((double)i*h)+(h/2.0)-1 << "\t" << result[i] << std::endl;
	}
}
