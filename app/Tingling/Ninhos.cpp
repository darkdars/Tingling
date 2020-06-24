#include "stdafx.h"
#include "Ninhos.h"
#include "Migalhas.h"


int Ninhos::nrNinho = 0;


Ninhos::Ninhos():_nEnergiaTransferido(1)
{
	
}

Ninhos::Ninhos(int energiaInicial, int energiaPNFormiga, int unidadesETFormiga, int posicao) : _energia(energiaInicial), _percentagem(energiaPNFormiga), _nEnergiaTransferido(unidadesETFormiga), _posicao(posicao) {
	this->nrNinho++;
	this->_nNinho = nrNinho;
	this->_energiaInicial = energiaInicial;
}


void Ninhos::setEnergia(int valor) {
	this->_energia = valor;
}

int Ninhos::getEnergia() {
	return this->_energia;
}

void Ninhos::setPercentagem(int valor) {
	this->_percentagem = valor;
}

int Ninhos::getPercentagem() {
	return this->_percentagem;
}

void Ninhos::setEnergiaTransferida(int valor) {
	this->_nEnergiaTransferido = valor;

}

int Ninhos::getEnergiaTransferida() {
	return this->_nEnergiaTransferido;

}

int Ninhos::get_nrNinho() {
	return _nNinho;
}

int Ninhos::getComunidade() {
	return _com.getNrComunidades();
}

void Ninhos::setFormigasExploradoras(Exploradora c) {
	_nFormigas.push_back(c);
}

void Ninhos::getFormigasNinho(int dimensao) {
	int x = 0,linha = 0;
	if (_nFormigas.size() == 0) {
		cout << "Nao existem Formigas neste ninho!" << endl;
		return;
	}

	cout << "Formigas:" << endl;
	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		x = 0;
		linha = 0;
		int aux = _nFormigas[i].getPosicao();
		x = aux % dimensao;
		aux = aux - x;
		linha = aux / dimensao;

		cout << "Formiga " << _nFormigas[i].getNFormiga() << " do tipo " << _nFormigas[i].getTipo() << " Energia - " << _nFormigas[i].getEnergia() << " na linha " << linha+1 << " e coluna " << x << "!\n";
	}


}

unsigned int Ninhos::getNrFormigasC() {
	return _nFormigas.size();
}

int Ninhos::getPosicaoNinho() {
	return this->_posicao;
}

void Ninhos::getFormigasPos(int posicao) {

	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		if (_nFormigas[i].getPosicao() == posicao) {
			cout << "Formiga " << _nFormigas[i].getNFormiga() << " do tipo " << _nFormigas[i].getTipo() << " com energia " << _nFormigas[i].getEnergia() << "!" << endl;
		}
	}
	

}


void Ninhos::getLinhaColuna(int posicao, int &linha, int &coluna, int dimensao) {
	linha = 0;
	coluna = 0;
	int aux = 0;

	aux = posicao % dimensao;
	coluna = aux;
	
	posicao = posicao - aux;
	posicao = posicao / dimensao;
	linha = posicao;
	


}

unsigned int Ninhos::getTamanhoVecF() {
	return _nFormigas.size();
}

void Ninhos::mexeFormigasNinho(vector<char> &mapa,int dimensao, vector<Migalhas> &migalhas, vector<Ninhos> &ninhos) {
	char c;
	int linha = 0, coluna = 0, linha_aux = 0, coluna_aux = 0, posicao_aux = 0, posicao = 0, j = 0,posicaoMaior = 0, Maior = 0,linhas,colunas;
	bool casaLivre = false;
	int confirma;


	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		
		c = _nFormigas[i].getTipo();
		linha = 0;
		coluna = 0;
		linha_aux = 0;
		linhas = 0;
		colunas = 0;
		coluna_aux = 0;
		posicao_aux = 0;
		casaLivre = false;
		confirma = 0;

		posicao = _nFormigas[i].getPosicao();
		//implementar depois o resto
		if (c == 'E') {

			
				do {

					_nFormigas[i].getLinhaColuna(posicao, linha, coluna, dimensao);
					_nFormigas[i].geraPosicaoF(8, linha_aux, coluna_aux);

					posicao_aux = calculaPosicao(linha + linha_aux, coluna + coluna_aux, dimensao);

					if (posicao_aux < mapa.size() && posicao_aux >= 0) {



						if ((coluna_aux + coluna) < dimensao && (coluna_aux + coluna) >= 0) {


							if (mapa[posicao_aux] == '-') {
								mapa[posicao_aux] = 'E';

								if (mapa[posicao] == 'E') {
									mapa[posicao] = '-';
								}

						
								_nFormigas[i].setPosicao(posicao_aux);


								coluna_aux = coluna_aux - coluna;
								if (coluna_aux < 0) {
									coluna_aux *= -1;
								}

								linha_aux = linha_aux - linha;
								if (linha_aux < 0) {
									linha_aux *= -1;
								}


								_nFormigas[i].decrementaEnergia(1 + linha_aux + coluna_aux);
								casaLivre = true;
							}
							else if (mapa[posicao_aux] == _nFormigas[i].getNrNinho() + '0') {
								if (mapa[posicao] == 'E') {
									mapa[posicao] = '-';
								}


								_nFormigas[i].setPosicao(posicao_aux);
								_nFormigas[i].decrementaEnergia(1 + linha_aux + coluna_aux);
								casaLivre = true;
							}
							else if (mapa[posicao_aux] == '+') {
								if (mapa[posicao] == 'E') {
									mapa[posicao] = '-';
								}
								mapa[posicao_aux] = 'E';
								_nFormigas[i].setPosicao(posicao_aux);
								_nFormigas[i].decrementaEnergia(1 + linha_aux + coluna_aux);

								for (unsigned int j = 0; j < migalhas.size(); j++) {
									if (migalhas[j].getPosicao() == posicao_aux) {
										_nFormigas[i].acrescentaEnergia(migalhas[j].getEnergia());
										migalhas[j].~Migalhas();
										migalhas.erase(migalhas.begin() + j);
									}
								}


								
								
								casaLivre = true;
							}



						}
					}

				} while (casaLivre == false);
			
			


			

		}
		else if (c == 'e') {

		}
		else if (c == 'A') {
			linha_aux = 0;
			coluna_aux = 0;
		
			//primeira regra - Assalta tentar implementar
			for (unsigned int x = 0; x < ninhos.size(); x++) {
				vector<Formigas> form = ninhos[x].getFormigas();
				if (form[0].getNrNinho() != _nFormigas[i].getNrNinho()) {
					for (unsigned int o = 0; o < form.size(); o++) {
						for (unsigned int da = -4; da < 4; da++) {
							for (unsigned int po = -4; po < 4; po++) {
								if (form[o].getPosicao() == (posicao + (da * dimensao) + po) && confirma == 0) {
									_nFormigas[i].acrescentaEnergia(form[o].getEnergia() / 2);
									form[o].decrementaEnergia(form[o].getEnergia() / 2);
									confirma = 1;
								}
							}
							

						}
						

					}
				}
				

				
				


			}

			//segunda regra -- dirijir-se a que tem mais energia
			if (confirma == 0) {
				for (unsigned int x = 0; x < ninhos.size(); x++) {
					vector<Formigas> form = ninhos[x].getFormigas();
					if (form[0].getNrNinho() != _nFormigas[i].getNrNinho()) {
						for (unsigned int o = 0; o < form.size(); o++) {
							for (unsigned int da = -8; da < 8; da++) {
								for (unsigned int po = -8; po < 8; po++) {
									if (form[o].getPosicao() == (posicao + (da * dimensao) + po) && confirma == 0) {
										if (form[o].getEnergia() > Maior) {
											posicaoMaior = form[o].getPosicao();
											Maior = form[o].getEnergia();
										}
									}
								}


							}


						}
					}

				}

				getLinhaColuna(posicaoMaior, linha, coluna, dimensao);
				getLinhaColuna(posicao, linhas, colunas, dimensao);

				if (linha < linhas) {
					coluna_aux = linhas - linha;
					linha_aux = colunas - coluna;
				}
				else {
					coluna_aux = linha - linhas;
					linha_aux = coluna - colunas;
				}

				

				if (linha_aux >= 0 && coluna_aux >= 0 && linha_aux < dimensao && coluna_aux < dimensao) {
					
					if (calculaPosicao(linha_aux, coluna_aux, dimensao) < mapa.size() && calculaPosicao(linha_aux, coluna_aux, dimensao) >= 0) {
						_nFormigas[i].setPosicao(calculaPosicao(linha_aux, coluna_aux, dimensao));
						confirma = 1;
					}
					
				
				}

				


			}


			//Regra Come Migalha
			if (confirma == 0) {
				for (unsigned int j = 0; j < migalhas.size(); j++) {

					for (unsigned int o = -4; o < _nFormigas[i].getRaioMovimento(); o++) {
						for (unsigned int x = -4; x < _nFormigas[i].getRaioMovimento(); x++) {
							if (migalhas[j].getPosicao() == (posicao + (o * dimensao) + x)) {
								_nFormigas[i].acrescentaEnergia(migalhas[j].getEnergia() / 4);
								migalhas[j].decrementaEnergia(migalhas[j].getEnergia() / 4);
								x = 100;
								o = 100;
								j = migalhas.size() + 1;
								confirma = 1;
							}


						}


					}
			}
			

			}


			//regraProcura Migalha
			if (confirma == 0) {

				for (unsigned int j = 0; j < migalhas.size(); j++) {

					for (unsigned int o = -8; o < 8; o++) {
						for (unsigned int x = -8; x < 8; x++) {
							if (migalhas[j].getPosicao() == (posicao + (o * dimensao) + x)) {
								if (migalhas[j].getEnergia() > Maior) {
									Maior = migalhas[j].getEnergia();
									posicaoMaior = migalhas[j].getPosicao();
								}


							}


						}


					}
				}

				getLinhaColuna(posicaoMaior, linha, coluna, dimensao);
				getLinhaColuna(posicao, linhas, colunas, dimensao);

				if (linha < linhas) {
					coluna_aux = linhas - linha;
					linha_aux = colunas - coluna;
				}
				else {
					coluna_aux = linha - linhas;
					linha_aux = coluna - colunas;
				}



				if (linha_aux >= 0 && coluna_aux >= 0 && linha_aux < dimensao && coluna_aux < dimensao) {
					if (calculaPosicao(linha_aux, coluna_aux, dimensao) < mapa.size() && calculaPosicao(linha_aux, coluna_aux, dimensao) >= 0) {
						_nFormigas[i].setPosicao(calculaPosicao(linha_aux, coluna_aux, dimensao));
						confirma = 1;
					}

				}




			}


			
			//RegraPasseia
			if (confirma == 0) {
				do {

					_nFormigas[i].getLinhaColuna(posicao, linha, coluna, dimensao);
					_nFormigas[i].geraPosicaoF(4, linha_aux, coluna_aux);

					posicao_aux = calculaPosicao(linha + linha_aux, coluna + coluna_aux, dimensao);

					

					if (posicao_aux < mapa.size() && posicao_aux >= 0) {

						if ((coluna_aux + coluna) < dimensao && (coluna_aux + coluna) >= 0) {
							if (mapa[posicao_aux] == '-') {
								mapa[posicao_aux] = 'A';

								if (mapa[posicao] == 'A') {
									mapa[posicao] = '-';
								}

								coluna_aux = coluna_aux - coluna;
								if (coluna_aux < 0) {
									coluna_aux *= -1;
								}

								linha_aux = linha_aux - linha;
								if (linha_aux < 0) {
									linha_aux *= -1;
								}


								_nFormigas[i].setPosicao(posicao_aux);
								casaLivre = true;
							}
							else if (mapa[posicao_aux] == _nFormigas[i].getNrNinho() + '0') {
								if (mapa[posicao] == 'A') {
									mapa[posicao] = '-';
								}


								_nFormigas[i].setPosicao(posicao_aux);
								casaLivre = true;
							}

						}
					}

				} while (casaLivre == false);

			}
			
		_nFormigas[i].decrementaEnergia(1 + 2 * (linha_aux + coluna_aux));
	
		

		}
		else if (c == 'a') {

		}
		else if (c == 'S') {




			//Regra passeia
			do {

				_nFormigas[i].getLinhaColuna(posicao, linha, coluna, dimensao);
				_nFormigas[i].geraPosicaoF(_nFormigas[i].getRaioMovimento(), linha_aux, coluna_aux);

				posicao_aux = calculaPosicao(linha + linha_aux, coluna + coluna_aux, dimensao);

				if (posicao_aux < mapa.size() && posicao_aux >= 0) {

					if ((coluna_aux + coluna) < dimensao && (coluna_aux + coluna) >= 0) {
						if (mapa[posicao_aux] == '-') {
							mapa[posicao_aux] = 'S';

							if (mapa[posicao] == 'S') {
								mapa[posicao] = '-';
							}


							_nFormigas[i].setPosicao(posicao_aux);


							coluna_aux = coluna_aux - coluna;
							if (coluna_aux < 0) {
								coluna_aux *= -1;
							}

							linha_aux = linha_aux - linha;
							if (linha_aux < 0) {
								linha_aux *= -1;
							}
							casaLivre = true;
						}
						else if (mapa[posicao_aux] == _nFormigas[i].getNrNinho() + '0') {
							if (mapa[posicao] == 'S') {
								mapa[posicao] = '-';
							}


							_nFormigas[i].setPosicao(posicao_aux);
							casaLivre = true;
						}

					}
				}

			} while (casaLivre == false);

			_nFormigas[i].decrementaEnergia(10);




		}
		else if (c == 's') {

		}
		else if (c == 'C') {
			

			//RegraFoge
			for (unsigned int x = 0; x < ninhos.size(); x++) {
				vector<Formigas> form = ninhos[x].getFormigas();
				if (form[0].getNrNinho() != _nFormigas[i].getNrNinho()) {
					for (unsigned int o = 0; o < form.size(); o++) {
						for (unsigned int da = -5; da < 5; da++) {
							for (unsigned int po = -5; po < 5; po++) {
								if (form[o].getPosicao() == (posicao + (da * dimensao) + po) && confirma == 0) {

									getLinhaColuna(form[o].getPosicao(), linha, coluna, dimensao);
									getLinhaColuna(posicao, linhas, colunas, dimensao);
									confirma = 1;

									if (linha > linhas && coluna > colunas) {
										linha_aux = linhas - 3;

										if (linha_aux < 0) {
											linha_aux = linhas;
											confirma = 0;
										}


									}
									else {
										linha_aux = linhas + 3;

										if (linha_aux > dimensao) {
											linha_aux = linhas;
											confirma = 0;
										}



									}

									if (confirma == 1) {
										if (calculaPosicao(linha_aux, coluna_aux, dimensao) >= 0 && calculaPosicao(linha_aux, coluna_aux, dimensao) < dimensao* dimensao) {
											_nFormigas[i].setPosicao(calculaPosicao(linha_aux, coluna_aux, dimensao));
										}
										confirma = 0;
										
									}

								
								


								}


							}
						}
					}
				}
			}


			//Regra Come Migalha
			if (confirma == 0) {
				for (unsigned int j = 0; j < migalhas.size(); j++) {

					for (unsigned int o = -3; o < _nFormigas[i].getRaioMovimento(); o++) {
						for (unsigned int x = -3; x < _nFormigas[i].getRaioMovimento(); x++) {
							if (migalhas[j].getPosicao() == (posicao + (o * dimensao) + x)) {
								_nFormigas[i].acrescentaEnergia(migalhas[j].getEnergia() / 2);
								migalhas[j].decrementaEnergia(migalhas[j].getEnergia() / 2);
								x = 100;
								o = 100;
								j = migalhas.size() + 1;
								confirma = 1;
							}


						}


					}
				}


			}


			//regraProcura Migalha
			if (confirma == 0) {

				for (unsigned int j = 0; j < migalhas.size(); j++) {

					for (unsigned int o = -5; o < 5; o++) {
						for (unsigned int x = -5; x < 5; x++) {
							if (migalhas[j].getPosicao() == (posicao + (o * dimensao) + x)) {
								if (migalhas[j].getEnergia() > Maior) {
									Maior = migalhas[j].getEnergia();
									posicaoMaior = migalhas[j].getPosicao();
								}


							}


						}


					}
				}

				getLinhaColuna(posicaoMaior, linha, coluna, dimensao);
				getLinhaColuna(posicao, linhas, colunas, dimensao);

				if (linha < linhas) {
					coluna_aux = linhas - linha;
					linha_aux = colunas - coluna;
				}
				else {
					coluna_aux = linha - linhas;
					linha_aux = coluna - colunas;
				}



				if (linha_aux >= 0 && coluna_aux >= 0 && linha_aux < dimensao && coluna_aux < dimensao) {
					if (calculaPosicao(linha_aux, coluna_aux, dimensao) >= 0 && calculaPosicao(linha_aux, coluna_aux, dimensao) < dimensao*dimensao) {
					_nFormigas[i].setPosicao(calculaPosicao(linha_aux, coluna_aux, dimensao));
					confirma = 1;
					if (mapa[posicao] == 'C') {
						mapa[posicao] = '-';
					}
					}
					

					

				}




			}



			//RegraVaiParaONinho
			if (confirma == 0) {
				if (_nFormigas[i].getIter() > 10) {
					if (_nFormigas[i].getEnergia() > _nFormigas[i].getEnergiaInicial() || _nFormigas[i].getEnergia() < _nFormigas[i].getEnergiaInicial() / 2) {

						for (unsigned int xpto = 0; xpto < ninhos.size(); xpto++){
							if (_nFormigas[i].getNrNinho() == ninhos[xpto].get_nrNinho()) {
								posicaoMaior = ninhos[xpto].getPosicaoNinho();
							}
						}

						for (unsigned int o = -3; o < 3; o++) {
							for (unsigned int x = -3; x < 3; x++) {
								if (posicaoMaior == (posicao + (o * dimensao) + x) && confirma == 0) {
									_nFormigas[i].setPosicao(posicaoMaior);
									confirma = 1;
									if (mapa[posicao] == 'C') {
										mapa[posicao] = '-';
									}
									
								}
							}
						}


						if (confirma == 0) {
							for (unsigned int o = -5; o < 5; o++) {
								for (unsigned int x = -5; x < 5; x++) {
									if (posicaoMaior == (posicao + (o * dimensao) + x) && confirma == 0) {
									
										
										_nFormigas[i].setPosicao(posicaoMaior);


										confirma = 1;
										if (mapa[posicao] == 'C') {
											mapa[posicao] = '-';
										}

									}
								}
							}


						}



					}


				}
			}



			//regra passeia
			if (confirma == 0) {
				do {

					_nFormigas[i].getLinhaColuna(posicao, linha, coluna, dimensao);
					_nFormigas[i].geraPosicaoF(3, linha_aux, coluna_aux);

					posicao_aux = calculaPosicao(linha + linha_aux, coluna + coluna_aux, dimensao);

					if (posicao_aux < mapa.size()) {

						if ((coluna_aux + coluna) < dimensao && (coluna_aux + coluna) >= 0) {
							if (mapa[posicao_aux] == '-') {
								mapa[posicao_aux] = 'C';

								if (mapa[posicao] == 'C') {
									mapa[posicao] = '-';
								}


								_nFormigas[i].setPosicao(posicao_aux);


								coluna_aux = coluna_aux - coluna;
								if (coluna_aux < 0) {
									coluna_aux *= -1;
								}

								linha_aux = linha_aux - linha;
								if (linha_aux < 0) {
									linha_aux *= -1;
								}
								casaLivre = true;
							}
							else if (mapa[posicao_aux] == _nFormigas[i].getNrNinho() + '0') {
								if (mapa[posicao] == 'C') {
									mapa[posicao] = '-';
								}


								_nFormigas[i].setPosicao(posicao_aux);
								casaLivre = true;
							}

						}
					}

				} while (casaLivre == false);
			}

			_nFormigas[i].setIter(1);
			_nFormigas[i].decrementaEnergia(1 + (linha_aux + coluna_aux));

		}
		else if (c == 'c') {

		}
		else if (c == 'V') {

			//regra protege
			for (unsigned int x = 0; x < ninhos.size(); x++) {
				vector<Formigas> form = ninhos[x].getFormigas();
				if (form[0].getNrNinho() != _nFormigas[i].getNrNinho()) {
					for (unsigned int o = 0; o < form.size(); o++) {
						for (unsigned int da = -7; da < 7; da++) {
							for (unsigned int po = -7; po < 7; po++) {
								if (form[o].getPosicao() == (posicao + (da * dimensao) + po) && confirma == 0) {
					

									for (unsigned int op = 0; o < form.size(); op++) {
										for (unsigned int das = -7; das < 7; das++) {
											for (unsigned int pos = -7; pos < 7; pos++) {
												
												if (_nFormigas[op].getPosicao() == (posicao + (das * dimensao) + pos) && confirma == 0) {
													
													posicaoMaior = form[i].getPosicao() + _nFormigas[op].getPosicao();
													int resto = posicaoMaior % 2;

						

													posicaoMaior = (posicaoMaior - resto) / 2;
	

													if (posicaoMaior >= 0 && posicaoMaior < dimensao * dimensao) {
														_nFormigas[i].setPosicao(posicaoMaior);

														if (mapa[posicao] == 'V') {
															mapa[posicao] = '-';
														}

														if (mapa[posicaoMaior] == '-') {
															mapa[posicaoMaior] = 'V';
														}

															confirma = 1;
													}
													
				

													
												}

											}
										}
									}


									
								}
							}


						}


					}
				}






			}



			//Regra Come Migalha
			if (confirma == 0) {
				for (unsigned int j = 0; j < migalhas.size(); j++) {

					for (unsigned int o = -5; o < _nFormigas[i].getRaioMovimento(); o++) {
						for (unsigned int x = -5; x < _nFormigas[i].getRaioMovimento(); x++) {
							if (migalhas[j].getPosicao() == (posicao + (o * dimensao) + x)) {
								_nFormigas[i].acrescentaEnergia(migalhas[j].getEnergia() * 0.75);
								migalhas[j].decrementaEnergia(migalhas[j].getEnergia() * 0.75);
								x = 100;
								o = 100;
								j = migalhas.size() + 1;
								confirma = 1;
							}


						}


					}
				}


			}


			//regraProcura Migalha
			if (confirma == 0) {

				for (unsigned int j = 0; j < migalhas.size(); j++) {

					for (unsigned int o = -7; o < 7; o++) {
						for (unsigned int x = -7; x < 7; x++) {
							if (migalhas[j].getPosicao() == (posicao + (o * dimensao) + x)) {
								if (migalhas[j].getEnergia() > Maior) {
									Maior = migalhas[j].getEnergia();
									posicaoMaior = migalhas[j].getPosicao();
								}


							}


						}


					}
				}

				getLinhaColuna(posicaoMaior, linha, coluna, dimensao);
				getLinhaColuna(posicao, linhas, colunas, dimensao);

				if (linha < linhas) {
					coluna_aux = linhas - linha;
					linha_aux = colunas - coluna;
				}
				else {
					coluna_aux = linha - linhas;
					linha_aux = coluna - colunas;
				}



				if (linha_aux >= 0 && coluna_aux >= 0 && linha_aux < dimensao && coluna_aux < dimensao) {
					_nFormigas[i].setPosicao(calculaPosicao(linha_aux, coluna_aux, dimensao));
					confirma = 1;

				}




			}


			//Regra passeia
			if (confirma == 0) {
				do {

					_nFormigas[i].getLinhaColuna(posicao, linha, coluna, dimensao);
					_nFormigas[i].geraPosicaoF(5, linha_aux, coluna_aux);

					posicao_aux = calculaPosicao(linha + linha_aux, coluna + coluna_aux, dimensao);

					if (posicao_aux < mapa.size() && posicao_aux >= 0) {

						if ((coluna_aux + coluna) < dimensao && (coluna_aux + coluna) >= 0) {
							if (mapa[posicao_aux] == '-') {
								mapa[posicao_aux] = 'V';

								if (mapa[posicao] == 'V') {
									mapa[posicao] = '-';
								}


								_nFormigas[i].setPosicao(posicao_aux);


								coluna_aux = coluna_aux - coluna;
								if (coluna_aux < 0) {
									coluna_aux *= -1;
								}

								linha_aux = linha_aux - linha;
								if (linha_aux < 0) {
									linha_aux *= -1;
								}
								casaLivre = true;
							}
							else if (mapa[posicao_aux] == _nFormigas[i].getNrNinho() + '0') {
								if (mapa[posicao] == 'V') {
									mapa[posicao] = '-';
								}


								_nFormigas[i].setPosicao(posicao_aux);
								casaLivre = true;
							}

						}
					}

				} while (casaLivre == false);
			}
			

			_nFormigas[i].decrementaEnergia(1 + (coluna_aux + linha_aux));

		}
		else if (c == 'v') {


		}
		


	}
	


}

int Ninhos::calculaPosicao(int linha, int coluna, int dimensao) {
	int aux = 0;
	aux = ((linha - 1) * dimensao) + coluna - 1;
	return aux;

}

void Ninhos::acrescentaEnergia(int energia) {
	this->_energia += energia;
}

void Ninhos::acrescentaEnergiaFormigas(int linha, int coluna, int dimensao, int energia) {
	
	int posicao = calculaPosicao(linha, coluna, dimensao);

	
	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		if (_nFormigas[i].getPosicao() == posicao) {
			_nFormigas[i].acrescentaEnergia(energia);
			cout << "Energia Acrescentada a Formiga " << _nFormigas[i].getNFormiga() << "!" << endl;
		}
	}


}


void Ninhos::mataFormigas(int linha, int coluna, int dimensao, vector<char> &mapa) {
	
	int posicao = calculaPosicao(linha, coluna, dimensao);

	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		if (_nFormigas[i].getPosicao() == posicao) {
			_nFormigas[i].~Formigas();
			_nFormigas.erase(_nFormigas.begin() + i);
			
			if (!isdigit(mapa[posicao]) && mapa[posicao] != '+') {
				mapa[posicao] = '-';
			}




		}


	}


}

void Ninhos::mataFormigasTodas(vector<char> &mapa) {
	int posicao = 0;
	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		posicao = 0;
		posicao = _nFormigas[i].getPosicao();
		_nFormigas[i].~Formigas();
		_nFormigas.erase(_nFormigas.begin() + i);

		if (!isdigit(mapa[posicao]) && mapa[posicao] != '+') {
			mapa[posicao] = '-';
		}
	}


}



void Ninhos::setFormigasCuidadoras(Cuidadora c) {
	_nFormigas.push_back(c);
}

void Ninhos::setFormigasVigilantes(Vigilante c) {
	_nFormigas.push_back(c);
}

void Ninhos::setFormigasAssaltantes(Assaltante c) {
	_nFormigas.push_back(c);
}

void Ninhos::setFormigasSupresa(Surpresa c) {
	_nFormigas.push_back(c);
}


int Ninhos::migalhaPosAdjacente(int posicao, vector<char> mapa) {

	if (mapa[posicao] == '+') {
		return 1;
	}

	return 0;

}

void Ninhos::verificaEnergiaFormigas(vector <char> &mapa) {
	int posicao = 0;
	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		if (_nFormigas[i].getEnergia() <= 0) {
			posicao = 0;
			posicao = _nFormigas[i].getPosicao();
			if (!isdigit(mapa[posicao])) {
				mapa[posicao] = '-';
			}

			_nFormigas[i].~Formigas();
			_nFormigas.erase(_nFormigas.begin() + i);
		}
	}

}

vector<Formigas> Ninhos::getFormigas() {
	return this->_nFormigas;
}

void Ninhos::setNrNinhoStatic0(){
	this->nrNinho = 0;
}

void Ninhos::setNrNinho(int ninho) {
	this->_nNinho = ninho;
}



void Ninhos::setPosicao(int posicao) {
	this->_posicao = posicao;
}

void Ninhos::setEnergiaInicial(int energia) {
	this->_energiaInicial = energia;
}

int Ninhos::getEnergiaInicial() {
	return this->_energiaInicial;
}

int Ninhos::verificaFormigasPos(int posicao) {
	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		if (_nFormigas[i].getPosicao() == posicao) {
			return 1;
		}
	}
	return 0;
}

Ninhos::~Ninhos()
{
	_com.~Comunidades();
	for (unsigned int i = 0; i < _nFormigas.size(); i++) {
		_nFormigas[i].~Formigas();
	}

}
