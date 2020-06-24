#include "stdafx.h"
#include "Comunidades.h"

int Comunidades::nrComunidades = -1;

Comunidades::Comunidades()
{
	nrComunidades++;
	this->_nrComunidades = nrComunidades;

}

int Comunidades::getNrComunidades() {
	return this->_nrComunidades;
}

Comunidades::~Comunidades()
{
}
