#include "stdafx.h"
#include "Formigas.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int Formigas::nFormiga = 0;

Formigas::Formigas() {

}

Formigas::Formigas(int n_energia, int raioVisao, int raioMovimento, char tipo, int nrNinho) : _energia(n_energia)
{
	this->_eInicial = n_energia;
	this->_raioMovimento = raioMovimento;
	this->_raioVisao = raioVisao;
	this->nFormiga++;
	this->_nFormiga = nFormiga;
	this->_tipo = tipo;
	this->_nNinho = nrNinho;
	this->_posicao = 0;
	this->_criadaNinho = 0;
}

void Formigas::setPosicao(int valor) {
	this->_posicao = valor;
}
int Formigas::getPosicao() {
	return _posicao;
}

int Formigas::getEnergiaInicial() {
	return this->_eInicial;
}

int Formigas::getEnergia(){
	return this->_energia;
}

int Formigas::getNFormiga() {
	return this->_nFormiga;
}

char Formigas::getTipo() {
	return this->_tipo;
}

void Formigas::getLinhaColuna(int posicao, int &linha, int &coluna, int dimensao) {
	linha = 0;
	coluna = 0;
	int aux = 0;

	aux = posicao % dimensao;
	coluna = aux;

	posicao = posicao - aux;
	linha = posicao / dimensao;

	//cout << "Esta na Linha : " << linha + 1 << " e coluna : " << coluna + 1 << endl;


}


void Formigas::geraPosicaoF(int raio,int &linha,int &coluna) {

	int v1, v2, positivoV1, positivoV2;

	v1 = rand() % (raio + 1);
	v2 = rand() % (raio + 1);


	positivoV1 = rand() % 2;
	positivoV2 = rand() % 2;

	if (positivoV1 == 0) {
		linha = v1;
	}
	else {
		linha = -v1;
	}

	if (positivoV2 == 0) {
		coluna = v2;
	}
	else {
		coluna = -v2;
	}
	
	
	//cout << "Gerou linha : " << linha << " e coluna : " << coluna << endl;


	
}

int Formigas::getNrNinho() {
	return _nNinho;
}

void Formigas::acrescentaEnergia(int energia) {
	this->_energia += energia;

}

void Formigas::decrementaEnergia(int energia) {
	this->_energia -= energia;
}

int Formigas::getRaioVisao() {
	return this->_raioVisao;
}

int Formigas::getRaioMovimento() {
	return this->_raioMovimento;
}

int Formigas::getCriadaNinho() {
	return this->_criadaNinho;
}

void Formigas::setCriandaNinho(int nr) {
	this->_criadaNinho = nr;
}

void Formigas::setRaioVisao(int raioVisao) {
	this->_raioVisao = raioVisao;
}


void Formigas::setRaioMovimento(int raioMovimento) {
	this->_raioMovimento = raioMovimento;
}


void Formigas::setEnergiaInicial(int energia) {
	this->_eInicial = energia;
}


void Formigas::setEnergia(int energia) {
	this->_energia = energia;
}

void Formigas::setNformiga(int nr) {
	this->_nFormiga = nr;
}

void Formigas::setTipo(char tipo) {
	this->_tipo = tipo;
}

void Formigas::setnNinho(int nr) {
	this->_nNinho = nr;
}


void Formigas::setIter(int nr) {
	this->iter += 1;
}

int Formigas::getIter() {
	return this->iter;
}


Formigas::~Formigas()
{
}
