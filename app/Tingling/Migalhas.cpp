#include "stdafx.h"
#include "Migalhas.h"
#include <iostream>


using namespace std;

Migalhas::Migalhas()
{
}

Migalhas::Migalhas(int energia)
{
	this->_energia = energia;
}


Migalhas::Migalhas(int energiaInicial, int linha, int coluna, int dimensao):_energiaInicial(energiaInicial) {
	this->_posicao = ((linha - 1) * dimensao) + (coluna - 1);
	this->_energia = _energiaInicial;
}


void Migalhas::setPercInicialPVazias(int valor) {
	this->_pInicialPvazias = valor;
}

int Migalhas::getPercInicialPVazias() {
	return this->_pInicialPvazias;
}

void Migalhas::setEnergiaInicial(int valor) {
	this->_energiaInicial = valor;

}

int Migalhas::getEnergiaInicial() {
	return this->_energiaInicial;
}

void Migalhas::setnMigalhasInst(int valor) {
	this->_nMigalhasInst = valor;
}

int Migalhas::getnMigalhasInst() {
	return this->_nMigalhasInst;
}

int Migalhas::getEnergia() {
	return this->_energia;
}

int Migalhas::getPosicao() {
	return this->_posicao;
}

void Migalhas::setPosicao(int posicao) {
	this->_posicao = posicao;
}


void Migalhas::decrementaEnergia(int energia) {
	this->_energia -= energia;
}


void Migalhas::incrementaEnergia(int energia) {
	this->_energia += energia;
}

void Migalhas::setEnergia(int energia) {
	this->_energia = energia;
}

Migalhas::~Migalhas()
{
}
