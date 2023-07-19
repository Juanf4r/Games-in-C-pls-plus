//Ahorcado en C++

#include<iostream>
#include<string>
#include<time.h>

std::string palabra_original = "";
std::string palabra_mostrar = "";
int vidas = 0;

void mostrar()
{
	std::cout << "\nVidas: " << vidas << "\n";
	std::cout << palabra_mostrar << "\n";
}

void ingresar(char x)
{
	bool perdiVidas = true;

	for (int i = 0; i < palabra_original.length(); i++)
	{
		if (x == palabra_original[i])
		{
			perdiVidas = false;
			palabra_mostrar[i] = x;
		}
	}

	if (perdiVidas == true) 
	{
		vidas--;
	}
}

void inicializar()
{
	vidas = 5;
	palabra_original = "Codigo Terminado";

	for (int i = 0; i < palabra_original.length(); i++)
	{
		if (palabra_original[i] >= 'A' && palabra_original[i] <= 'Z')
		{
			palabra_original[i] += 32;
		}
	}

	for (int i = 0; i < palabra_original.length(); i++)
	{
		if (palabra_original[i] >= 'a' && palabra_original[i] <= 'z')
		{
			palabra_mostrar+= '_';
		}
		else
		{
			palabra_mostrar += palabra_original[i];
		}
	}
}

int main()
{
	system("CLS");
	
	inicializar();
	mostrar();
	while (vidas > 0 && palabra_mostrar != palabra_original)
	{
		std::cout << "Solo escribe en minusculas!\n";
		char x;
		std::cin >> x;
		ingresar(x);
		mostrar();
		
	}
	if (vidas > 0)
	{
		std::cout << "Ganaste!\n";
	}
	else
	{
		std::cout << "Perdiste!\nLa palabra era: " << palabra_original << " \n";
	}

	system("pause");
	return 0;
}