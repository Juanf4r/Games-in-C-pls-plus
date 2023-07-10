/*Ahorcado Juego en Consola C++ */

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<Windows.h>

std::string seguir = "S";
std::string palabrasF[3] = { "CONSOLA","DISCORD","GAMER"};
std::string palabrasN[3] = { "BANEADO","CAMPERO","CHETADO" };
std::string palabrasD[3] = { "BUFF","NERF","CRAFTEO" };
std::string palabrasE[3] = { "GOTY","KAPPA","PUSHEAR" };
int ops = 0;

void opsElegir()
{
	switch (ops)
	{
	case 1:	break;

	case 2:	break;

	case 3:	break;

	case 4:	break;

	default: break;
	}
}

void Inicio()
{
	std::cout << "BIENVENIDO AL AHORCADO\n"; Sleep(777);
	std::cout << "En este juego debes adivinar la palabra correcta!\n"; Sleep(1500);
	std::cout << "Elige la dificultad: \n";

	std::cout << "1.Facil\n2.Normal\n3.Dificil\n4.Extremo!\n\n"; std::cin >> ops;
	do 
	{
		std::cout << "\nError. Seleccione una opcion: \n";
		std::cout << "1.Facil\n2.Normal\n3.Dificil\n4.Extremo!\n\n"; std::cin >> ops;
	} while (ops != 1 and ops != 2 and ops != 3 and ops != 4);
	system("CLS"); opsElegir();
}

int main()
{
	system("CLS");

	do
	{
		Inicio();
		std::cout << "Desea seguir jugando?\n";
		std::cout << "S para Si, N para No\n"; std::cin >> seguir;

	}while (seguir == "S" or seguir == "s");

	system("pause");
	return 0;
}