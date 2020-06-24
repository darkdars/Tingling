#include "stdafx.h"
#include "Mundo.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Consola.h"

using namespace std;

Mundo::Mundo() :_dimensao(NULL)
{
}

void Mundo::setDimensao(int valor) {
	this->_dimensao = valor;

	for (int i = 0; i < _dimensao * _dimensao; i++)
		_mapa.push_back('-');


}

int Mundo::getDimensao() {
	//cout << "Dimensao: " << this->_dimensao << endl;
	return this->_dimensao;
}

void Mundo::imprimeMapa() {
	unsigned int i;
	int j = 1;
	system("CLS");
	Consola::setScreenSize(50, 200);
	Consola::setTextColor(Consola::VERMELHO);

	printf("  ");
	for (int k = 1; k <= _dimensao; k++) {
		printf(" %2d",k);
	}

	for ( i = 0; i < _dimensao * _dimensao; i++) {
		if ((i % (_dimensao)) == 0) {
			cout << endl;
			printf("%3d ", j++);
		}
		
		cout << _mapa[i] << "  ";
	}

	cout << endl;


}

void Mundo::setNinho(int nr, int linha, int coluna) {
	//this->_mapa.insert(_mapa.begin() + ((linha - 1) * _dimensao) + (coluna - 1), (nr + '0'));
	this->_mapa[((linha - 1) * _dimensao) + (coluna - 1)] = (nr + '0');

}

int Mundo::verificaNinho(int linha, int coluna) {
		//melhorar
	if (isdigit(_mapa[(((linha - 1) * _dimensao) + (coluna - 1))])){
		return 1;
	}
	if (_mapa[(((linha - 1) * _dimensao) + (coluna - 1))] != '-') {
		return 1;
	}



	return 0;

}

int Mundo::espacoMapa() {
	int numero = 0;

	for (unsigned int i = 0; i < _mapa.size(); i++) {
		if (_mapa[i] == '-') {
			numero++;
		}
	}

	return numero;
}

void Mundo::listaMundo() { //lista tudo sobre o mundo
	int n_espacos = 0, n_formigas = 0, n_migalhas = 0, n_exploradoras = 0, n_vigilantes = 0, n_ninhos = 0, n_assaltante = 0, n_cuidadora = 0, n_supresa = 0;

	//contar os elementos do mundo e imprimir de seguida
	for (unsigned int i = 0; i < _mapa.size(); i++) {

		if (_mapa[i] == '-') { // n espacos livres
			n_espacos++;
		}
		else if (_mapa[i] == 'M') { // verificar depois se é mesmo o M que representa as migalhas
			n_migalhas++;
		}
		else if (_mapa[i] == 'E') {
			n_exploradoras++;
			n_formigas++;
		}
		else if (_mapa[i] == 'V') {
			n_vigilantes++;
			n_formigas++;
		}
		else if (_mapa[i] == 'A') {
			n_assaltante++;
			n_formigas++;
		}
		else if (_mapa[i] == 'C') {
			n_cuidadora++;
			n_formigas++;
		}
		else if (_mapa[i] == 'S') {
			n_supresa++;
			n_formigas++;
		}
		else if (isdigit(_mapa[i])) {
			n_ninhos++;
		}
		else if (_mapa[i] == '+') {
			n_migalhas++;
		}
	}

	cout << "Listagem do Mundo (O que esta visivel no mapa)" << endl;
	cout << "Espacos Brancos - " << n_espacos << endl;
	cout << "Ninhos - " << n_ninhos << endl;
	cout << "Migalhas - " << n_migalhas << endl;
	cout << "Formigas - " << n_formigas << endl;
	cout << "Formigas Cuidadoras - " << n_cuidadora << endl;
	cout << "Formigas Vigilantes - " << n_vigilantes << endl;
	cout << "Formigas Assaltantes - " << n_assaltante << endl;
	cout << "Formigas Exploradoras - " << n_exploradoras << endl;
	cout << "Formigas Supresa - " << n_supresa << endl;

}

int Mundo::posicaoAleatoriaF() {
	vector<int> espacos;
	int v1 = 0;
	unsigned int v = 0;

	for (unsigned int i = 0; i < _mapa.size(); i++) {
		if (_mapa[i] == '-') {
			espacos.push_back(i);
		}
	}
	v = espacos.size();

	v1 = rand() % v;


	return espacos[v1];
}

void Mundo::setFormiga(char c, int posicao) {
	this->_mapa[(posicao)] = c;
	int aux = 0,coluna = 0, linha = 0;

	aux = posicao % (_dimensao);

	coluna = aux;

	posicao = posicao - aux;
	
	linha = posicao / (_dimensao);

	cout << "Formiga criada na posicao " << linha+1 << " e " << coluna+1 << endl;

}

vector<char> Mundo::getMapa() {
	return _mapa;
}

void Mundo::setMapa(vector<char> mapa) {
	_mapa = mapa;

}

int Mundo::verificaPosicao(int linha, int coluna) {

	if (_mapa[(((linha - 1) * _dimensao) + (coluna - 1))] != '-') {
		return 1;
	}

	return 0;
}

void Mundo::setMigalha(int linha, int coluna) {
	int aux = 0, posicao = 0;

	posicao = ((linha - 1) * _dimensao) + (coluna - 1);
	

	_mapa[posicao] = '+';

}

void Mundo::setMigalha(int posicao) {
	_mapa[posicao] = '+';

}

void Mundo::setXY(int x, int y) {
	this->_x = x;
	this->_y = y;
}

int Mundo::getX() {
	return this->_x;
}

int Mundo::getY() {
	return this->_y;
}


Mundo::~Mundo()
{
}
