#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

//Classes
#include "Ninhos.h"
#include "Mundo.h"
#include "Migalhas.h"
#include "Formigas.h"



using namespace std;

class Configuracao
{
public:
	Configuracao();
	void Run();
	void ImprimeMenu();
	void Menu(string nome,bool &d);
	bool Verifica();
	void Comandos(string comando,bool &gameOn);
	void Simulacao();
	void Iteracao(int nIteracoes);
	int guardaFicheiro(string nome);
	void criaMigalhas();
	void criaMigalhasIniciais();
	void mudaFicheiro(string nome);
	~Configuracao();

private:
	Ninhos _ninho;
	Mundo _mundo;
	Migalhas _migalhas;
	vector<Ninhos> _nNinhos;
	vector<Migalhas> _nMigalhas;
	int _confirma[8]; //7 é o numero de comandos

protected:

};

