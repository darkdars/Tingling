#pragma once
#include "Comunidades.h"
#include "Formigas.h"
#include "Exploradora.h"
#include "Cuidadora.h"
#include "Assaltante.h"
#include "Surpresa.h"
#include "Vigilante.h"
#include "Migalhas.h"
#include <iostream>
#include <vector>

using namespace std;

class Ninhos
{
public:
	Ninhos();
	Ninhos(int energiaInicial, int energiaPNFormiga, int unidadesETFormiga,int posicao);
	void setEnergia(int valor);
	int getEnergia();
	void setPercentagem(int valor);
	int getPercentagem();
	void setEnergiaTransferida(int valor);
	int getEnergiaTransferida();
	int get_nrNinho();
	int getComunidade();
	void setFormigasExploradoras(Exploradora c);
	void getFormigasNinho(int dimensao);
	unsigned int getNrFormigasC();
	int getPosicaoNinho();
	void getFormigasPos(int posicao);
	void getLinhaColuna(int posicao,int &linha, int &coluna, int dimensao);
	unsigned int getTamanhoVecF();
	void mexeFormigasNinho(vector<char> &mapa, int dimensao, vector<Migalhas> &migalhas, vector<Ninhos> &ninhos);
	int calculaPosicao(int linha, int coluna, int dimensao);
	void acrescentaEnergia(int energia);
	void acrescentaEnergiaFormigas(int linha, int coluna, int posicao, int energia);
	void mataFormigas(int linha, int coluna, int dimensao, vector<char> &mapa);
	void mataFormigasTodas(vector<char> &mapa);
	void setFormigasCuidadoras(Cuidadora c);
	void setFormigasVigilantes(Vigilante c);
	void setFormigasAssaltantes(Assaltante c);
	void setFormigasSupresa(Surpresa c);
	int migalhaPosAdjacente(int posicao, vector<char> mapa);
	void verificaEnergiaFormigas(vector <char> &mapa);
	vector<Formigas> getFormigas();
	void setNrNinhoStatic0();
	void setNrNinho(int ninho);
	void setPosicao(int posicao);
	void setEnergiaInicial(int energia);
	int getEnergiaInicial();
	int verificaFormigasPos(int posicao);
	static int nrNinho;
	~Ninhos();
private:
	int _energia;
	int _energiaInicial;
	int _percentagem;
	int _nEnergiaTransferido;
	int _nNinho;
	int _posicao;

	//Formigas
	vector<Formigas> _nFormigas;
	//Criar nova comunidade
	Comunidades _com;
	
};

