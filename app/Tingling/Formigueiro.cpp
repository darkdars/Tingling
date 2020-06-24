// Formigueiro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Configuracao.h"
#include "Consola.h"


void main()
{
	Configuracao start;

		Consola::setTextColor(Consola::PRETO);
		Consola::setTextSize(20, 20);
		Consola::setScreenSize(15, 1455);
		Consola::setBackgroundColor(Consola::BRANCO);

		start.Run();

		system("PAUSE");
}

