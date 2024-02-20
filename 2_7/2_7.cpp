//Krzysztof Czarnowus

#include <iostream>
#include <random>
#include <fstream>

#define RANGE 10000000

int generator()
{
	if (rand()%52 < 13) return 1; //jeśli w pierwszym losowaniu wyjdzie trefl
	else if (rand()%51 < 13) return 1; //jeśli w drugim losowaniu wyjdzie trefl
	else if (rand()%50 < 13) return 1; //jeśli w trzecim losowaniu wyjdzie trefl
	else return 0; //jeśli żadna z trzech kart nie jest treflem
}

int main()
{
	srand(time(NULL));
	std::ofstream zapis;
	zapis.open ("out.txt");
	int n = 0; //ilość powtórzeń eksperymentu
	int trefl = 0; //ilość eksperymentów zakończonych wyciągnięciem trefla
	while (n<RANGE)
	{
		for(int x=0; x<100; ++x)
		{
			++n;
			trefl+=generator();
		}
		std::cout << "Ilość powtórzeń: " << n << "\tPrawdopodobieństwo: " << (1-(double)trefl/(double)n) << std::endl;
		zapis << n << "\t" << (1-(double)trefl/(double)n) << std::endl;
	}
	zapis.close();
}
