// FizzBuzz en C++
#include<iostream>
#include<cstdlib>
#include<Windows.h>

int num{ 0 };
std::string seguir = "S";

void calculo()
{
	for (int i = 1; i < num; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			std::cout << "FizzBuzz" << "\n";
		}
		else if (i % 5 == 0)
		{
			std::cout << "Buzz" << "\n";
		}
		else if (i % 3 == 0)
		{
			std::cout << "Fizz" << "\n";
		}
		else
		{
			std::cout << i << "\n";
		}
	}
}

int main()
{
	
	while (seguir == "S" or seguir == "s")
	{
		system("CLS");
		std::cout << "Digite el numero de Numeros a imprimir: "; std::cin >> num;
		calculo();

		std::cout << "\nDesea hacer el proceso de nuevo: S/N\n"; std::cin >> seguir;

		while (seguir != "S" and seguir != "s" and seguir != "N" and seguir != "n")
		{
			std::cout << "\n\tError. Digite S o N\t"; std::cin >> seguir;
		}

	}
	system("pause");
	return 0;
}