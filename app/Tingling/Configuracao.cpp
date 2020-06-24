#include "stdafx.h"
#include "Configuracao.h"
#include "Exploradora.h"
#include "Cuidadora.h"
#include "Assaltante.h"
#include "Surpresa.h"
#include "Vigilante.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdio.h>

Configuracao::Configuracao()
{
	for (int i = 0; i < 8; i++) {
		this->_confirma[i] = 0;
	}
}

void Configuracao::Run() {
	string comando;
	int confirma = 0;
	bool avanca = false;

	for (int i = 0; i < 8; i++) {
		this->_confirma[i] = 0;
	}

	do {

		system("Cls");
		//Comandos de inicio para a simulação, desde menu e afins
		ImprimeMenu();
		cout << "Insira o comando: ";
		getline(cin, comando);

		Menu(comando,avanca);


	} while (avanca != true);
	//guardar nm ficheiro
	if (guardaFicheiro("default.txt") != 0)
		return;

	Simulacao();

}

void Configuracao::ImprimeMenu() {

		cout << "Menu" << endl;
		cout << "defmundo <limite> - Define a dimensao do mundo" << endl;
		cout << "defen <energia> - Define o valor inicial da energia dos ninhos" << endl;
		cout << "defpc <valor> - Define o valor (percentagem) da energia inicial" << endl;
		cout << "defvt <valor> - Define o numero de unidades de energia transferidas entre ninho e formiga por iteracao." << endl;
		cout << "defmi <valor de 0 a 100> - Define a percentagem inicial posicoes vazias que tem (inicialmente) migalhas" << endl;
		cout << "defme <energia> - Define a energia inicial das novas migalhas." << endl;
		cout << "defnm <max> - Define o numero maximo de migalhas a serem criadas a cada instante." << endl;
		cout << "executa <nomeFicheiro> - Le comandos do ficheiro de texto designado por nomeFicheiro, um por linha, e executa-os." << endl;
		cout << "inicio - Inicia a simulacao" << endl;
}

void Configuracao::Menu(string nome,bool &d) {

	string aux,nomeFich;
	istringstream iss(nome);
	int x = 0;


	iss >> aux;

	cout << "Comando: " << aux << endl;

	if (aux == "defmundo") {
		x = 0;
		iss >> x;

		if (x < 10) {
			cout << "Erro Insira Mais dados!\n";
			system("PAUSE");
			return;
		}

		_mundo.setDimensao(x);
		cout << "Dimensao: " << _mundo.getDimensao() << endl;
		_confirma[0] = 1;

	}
	else if (aux == "defen") {
		iss >> x;

		if (x < 0) {
			cout << "Erro Insira Mais dados!\n";
			system("PAUSE");
			return;
		}



		_ninho.setEnergia(x);
		cout << "Energia inicial:  " << _ninho.getEnergia() << endl;
		_confirma[1] = 1;
	}
	else if (aux == "defpc") {
		iss >> x;

		if (x < 0) {
			cout << "Erro Insira Mais dados!\n";
			system("PAUSE");
			return;
		}

		_ninho.setPercentagem(x);
		cout << "Percentagem: " << _ninho.getPercentagem() << endl;
		_confirma[2] = 1;
		
	}
	else if (aux == "defvt") {
		iss >> x;

		if (x < 0) {
			cout << "Erro o valor tem de ser maior que 0!" << endl;
			return;
		}

		_ninho.setEnergiaTransferida(x);
		cout << "Energia Transferida: " << _ninho.getEnergiaTransferida() << endl;
		_confirma[3] = 1;
	}
	else if (aux == "defmi") {
		iss >> x;

		if (x < 0 && x > 100) {
			cout << "Erro Insira Mais dados!\n";
			system("PAUSE");
			return;
		}

		_migalhas.setPercInicialPVazias(x);
		_migalhas.getPercInicialPVazias();
		_confirma[4] = 1;
	}
	else if (aux == "defme") {
		iss >> x;

		if (x < 0) {
			cout << "Erro o valor tem de ser maior que 0!" << endl;
			return;
		}


		_migalhas.setEnergiaInicial(x);
		_migalhas.getEnergiaInicial();
		_confirma[5] = 1;
	}
	else if (aux == "defnm") {
		x = 0;
		iss >> x;

		if (x < 0) {
			cout << "Erro o valor tem de ser maior que 0!" << endl;
			return;
		}

		//_Ninho
		_migalhas.setnMigalhasInst(x);
		_migalhas.getnMigalhasInst();
		_confirma[6] = 1;

	}
	else if (aux == "executa") {
		iss >> nomeFich;
		string line,aux1;
		int num = 0;

		ifstream myfile(nomeFich);

		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				istringstream is(line);
				is >> aux1;

				if (aux1 == "defmundo") {
					num = 0;
					is >> num;

					if (num < 10) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
						return;
					}

					_mundo.setDimensao(num);
					cout << "Dimensao: " << _mundo.getDimensao() << endl;
					_confirma[0] = 1;

				}
				else if (aux1 == "defen") {
					is >> num;

					if (num < 0) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
						return;
					}



					_ninho.setEnergia(num);
					cout << "Energia: " << _ninho.getEnergia() << endl;
					_confirma[1] = 1;
				}
				else if (aux1 == "defpc") {
					is >> num;

					if (num < 0) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
						return;
					}

					_ninho.setPercentagem(num);
					cout << "Percentagem: " << _ninho.getPercentagem() << endl;
					_confirma[2] = 1;

				}
				else if (aux1 == "defvt") {
					is >> num;

					_ninho.setEnergiaTransferida(num);
					cout << "Energia Transferida: " << _ninho.getEnergiaTransferida() << endl;
					_confirma[3] = 1;
				}
				else if (aux1 == "defmi") {
					is >> num;

					if (num < 0 && num > 100) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
						return;
					}

					_migalhas.setPercInicialPVazias(num);
					_migalhas.getPercInicialPVazias();
					_confirma[4] = 1;
				}
				else if (aux1 == "defme") {
					is >> num;

					_migalhas.setEnergiaInicial(num);
					_migalhas.getEnergiaInicial();
					_confirma[5] = 1;
				}
				else if (aux1 == "defnm") {
					num = 0;
					is >> num;

					_migalhas.setnMigalhasInst(num);
					_migalhas.getnMigalhasInst();
					_confirma[6] = 1;
				}



			}

			myfile.close();
		}
		else {
			cout << "Erro a abrir o ficheiro " << nomeFich << endl;
		}


	}
	else if (aux == "inicio") {
		//Verificar
		if (Verifica() == false) {
			cout << "Nao utilizou todos os comandos!\n" << endl;
			system("Pause");
			return;
		}

		d = true;

	}
	else {
		cout << "Comando nao encontrado!\n";
	}

	system("PAUSE");
}

bool Configuracao::Verifica() {
	//verificar se todos os comandos estão com valores e devolve true or false, true se pode avancar false se nao pode


	for (int i = 0; i < 7; i++) {
		if (_confirma[i] != 1) {
			return false;
		}
	}
	

	return true;
}

void Configuracao::Comandos(string comando,bool &gameOn) {

	istringstream iss(comando);
	string aux, nomeFich;
	int x = 0, coluna = 0, linha = 0,tmp = 0,num = 0;
	char tipo;
	iss >> aux;

	if (aux == "ninho") {
	//falta implementar criar nova comunidade
		tmp = _mundo.getDimensao();
		system("cls");
		iss >> linha;
		iss >> coluna;
		

		if (linha < 0 || coluna < 0) {
			cout << "Insira outros valores!" << endl;
			return;
		}
		else if (linha > tmp || coluna > tmp) {
			cout << "Insira outros valores! " << endl;
			return;
		}


		//ver se é preciso fazer mais verificacoes (por exemplo: se ja existe ninho, se tem formiga , qualquer coisa)
		if (_mundo.verificaNinho(linha, coluna) == 1) { //melhorar o verifica ninho para as condicoes que são precisas!
			cout << "Ja se encontra um ninho na posicao (" << linha << "," << coluna << ")" << endl;
			return;
		} // vericifa se existe ninho, no sitio que foi indicado

		
		Ninhos newNinho(_ninho.getEnergia(), _ninho.getPercentagem(), _ninho.getEnergiaTransferida(), (((linha - 1) * _mundo.getDimensao()) + (coluna - 1)));


		_nNinhos.push_back(newNinho);

		_mundo.setNinho(newNinho.get_nrNinho(), linha, coluna);
		cout << "Ninho Criado Com Sucesso!" << endl;
		cout << "Com o nr: " << newNinho.get_nrNinho() << " na posicao (" << linha << "," << coluna << ")." << endl;
		cout << "Comunidade Criada com Sucesso!" << endl;
		cout << "Com o nr: " << newNinho.getComunidade() << endl;
	}
	else if (aux == "criaf") {
		//falta implementar
		iss >> x;

		if (x < 0) {
			cout << "Intruduza o numero de formigas que quer adicionar, tem de ser maior que 0!\n";
			return;
		}
		//ver se existe espaco suficiente no mapa para criar formigas
		if (_mundo.espacoMapa() < x) {
			cout << "Nao Tem espaco no mapa! So pode criar " << _mundo.espacoMapa() << " Formigas" << endl;
			return;
		}

		iss >> tipo;
		//TIPO DE FORMIGA

		iss >> num;

		if (num < 0) {
			cout << "Intruduza outro valor para o ninho!" << endl;
			return;
		}

		tmp = -1;

		for (unsigned int i = 0; i < _nNinhos.size(); i++) {
			if (_nNinhos[i].get_nrNinho() == num)
				tmp = i;
		}
		
		if (_nNinhos.size() == 0) {
			cout << "Nao existe ninhos criados!" << endl;
			return;
		}


		if (tmp < 0){
			cout << "Nao existe esse ninho!" << endl;
			return;
		}



		if (tipo == 'C') {
			for (int i = 0; i < x; i++) {
				num = 0;
				num = _mundo.posicaoAleatoriaF();
				Cuidadora temporaria(tmp);
				temporaria.setPosicao(num);
				_nNinhos[tmp].setFormigasCuidadoras(temporaria);
				//mete las no mapa
				_mundo.setFormiga('C', temporaria.getPosicao());
			}
		}
		else if (tipo == 'V') {
			for (int i = 0; i < x; i++) {
				num = 0;
				num = _mundo.posicaoAleatoriaF();
				Vigilante temporaria(tmp);
				temporaria.setPosicao(num);
				_nNinhos[tmp].setFormigasVigilantes(temporaria);
				//mete las no mapa
				_mundo.setFormiga('V', temporaria.getPosicao());
			}
		}
		else if (tipo == 'A') {
			for (int i = 0; i < x; i++) {
				num = 0;
				num = _mundo.posicaoAleatoriaF();
				Assaltante temporaria(tmp);
				temporaria.setPosicao(num);
				_nNinhos[tmp].setFormigasAssaltantes(temporaria);
				//mete las no mapa
				_mundo.setFormiga('A', temporaria.getPosicao());
			}
		}
		else if (tipo == 'E') {
			//criar formiga
			
			for (int i = 0; i < x; i++) {
				num = 0;
				num = _mundo.posicaoAleatoriaF();
				Exploradora temporaria(tmp);
				temporaria.setPosicao(num);
				_nNinhos[tmp].setFormigasExploradoras(temporaria);
				//mete las no mapa
				_mundo.setFormiga('E',temporaria.getPosicao());


			}
			



		}
		else if (tipo == 'S') {
			for (int i = 0; i < x; i++) {
				num = 0;
				num = _mundo.posicaoAleatoriaF();
				Surpresa temporaria(tmp);
				temporaria.setPosicao(num);
				_nNinhos[tmp].setFormigasSupresa(temporaria);
				//mete las no mapa
				_mundo.setFormiga('S', temporaria.getPosicao());
			}
		}
		else {
			cout << "Tipo de formigas nao existe!" << endl;
			return;
		}

		cout << "Sucesso a criar " << x << " Formigas do tipo " << tipo << " no ninho " << tmp+1 << "!" << endl;

	}
	else if (aux == "cria1") {
		iss >> tipo;

		iss >> num;

		if (num <= 0) {
			cout << "Insira outro valor para o ninho!" << endl;
			return;
		}

		iss >> linha;

		if (linha <= 0 || linha > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a linha!" << endl;
			return;
		}

		iss >> coluna;

		if (coluna <= 0 || coluna > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a coluna!" << endl;
			return;
		}


		for (unsigned int i = 0; i < _nNinhos.size(); i++) {
			if (_nNinhos[i].get_nrNinho() == num) {

				if (_mundo.verificaPosicao(linha, coluna) == 0) {
					num = (linha - 1) * _mundo.getDimensao() + coluna - 1;
					if (tipo == 'C') {
							Cuidadora temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasCuidadoras(temporaria);
							//mete las no mapa
							_mundo.setFormiga('C', temporaria.getPosicao());
						
					}
					else if (tipo == 'V') {
							Vigilante temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasVigilantes(temporaria);
							//mete las no mapa
							_mundo.setFormiga('V', temporaria.getPosicao());
				
					}
					else if (tipo == 'A') {
							Assaltante temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasAssaltantes(temporaria);
							//mete las no mapa
							_mundo.setFormiga('A', temporaria.getPosicao());
					
					}
					else if (tipo == 'E') {
							Exploradora temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasExploradoras(temporaria);
							//mete las no mapa
							_mundo.setFormiga('E', temporaria.getPosicao());
					}
					else if (tipo == 'S') {
							Surpresa temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasSupresa(temporaria);
							//mete las no mapa
							_mundo.setFormiga('S', temporaria.getPosicao());
					
					}
					else {
						cout << "Tipo de formigas nao existe!" << endl;
						return;
					}



				}
				else {

					//implementar a ver se é o ninho dele se for, mete senao da erro


					if (_nNinhos[i].getPosicaoNinho() == ((linha - 1) * _mundo.getDimensao() + coluna - 1)) {
						num = (linha - 1) * _mundo.getDimensao() + coluna - 1;
						if (tipo == 'C') {
							Cuidadora temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasCuidadoras(temporaria);

						}
						else if (tipo == 'V') {
							Vigilante temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasVigilantes(temporaria);

						}
						else if (tipo == 'A') {
							Assaltante temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasAssaltantes(temporaria);

						}
						else if (tipo == 'E') {
							Exploradora temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasExploradoras(temporaria);
						}
						else if (tipo == 'S') {
							Surpresa temporaria(tmp);
							temporaria.setPosicao(num);
							_nNinhos[tmp].setFormigasSupresa(temporaria);

						}
						else {
							cout << "Tipo de formigas nao existe!" << endl;
							return;
						}

					}
					else {
						cout << "Insira outra posicao!" << endl;
						return;
					}
					


				



				}
			





			}
		}



		
	}
	else if (aux == "migalha") {
		iss >> linha;

		if (linha <= 0 || linha > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a linha!" << endl;
			return;
		}

		iss >> coluna;

		if (coluna <= 0 || coluna > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a coluna!" << endl;
			return;
		}

		if (_mundo.verificaPosicao(linha,coluna) == 1) {
			cout << "Posicao Ocupada!" << endl;
			return;
		}
		else {

			Migalhas aux(_migalhas.getEnergiaInicial(),linha,coluna,_mundo.getDimensao());

			_nMigalhas.push_back(aux);

			_mundo.setMigalha(linha, coluna);

			cout << "Migalha Criada com sucesso na posicao (" << linha << " , " << coluna << ")." << endl;
		}
	

	}
	else if (aux == "foca") {
		iss >> linha;

		if (linha <= 0 || linha > _mundo.getDimensao()) {
			cout << "Intruduza outra linha!" << endl;
			return;
		}

		iss >> coluna;

		if (coluna <= 0 || coluna > _mundo.getDimensao()) {
			cout << "Intruduza outra coluna!" << endl;
			return;
		}

		_mundo.setXY(coluna,linha);



	} 
	else if (aux == "tempo") {
		x = 1;
		iss >> x;

		if (x <= 0) {
			cout << "Intruduza outro valor!" << endl;
			return;
		}


			Iteracao(x);
		
	}
	else if (aux == "energninho") {
		iss >> x;
		int verifica = 0;

		if (x >= 0) {
			cout << "Insira outro valor para o Numero de ninho!" << endl;
			return;
		}

		iss >> tmp;
		
		if (tmp <= 0) {
			cout << "Insira outro valor para a Energia!" << endl;
			return;
		}

		for (unsigned int i = 0; i < _nNinhos.size(); i++) {
			if (_nNinhos[i].get_nrNinho() == x) {
				verifica = i + 1;
			}
		}

		if (verifica == 0) {
			cout << "Nao existe o ninho especificado!" << endl;
			return;
		}

		_nNinhos[verifica - 1].acrescentaEnergia(tmp);




	}
	else if (aux == "energformiga") {
		iss >> linha;

		if (linha <= 0 || linha > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a linha!" << endl;
			return;
		}

		iss >> coluna;

		if (coluna <= 0 || coluna > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a coluna!" << endl;
			return;
		}

		iss >> tmp;

		if (tmp <= 0) {
			cout << "Intruduza outro valor para a Energia!" << endl;
			return;
		}

		
		for (unsigned int i = 0; i < _nNinhos.size(); i++) {
			_nNinhos[i].acrescentaEnergiaFormigas(linha, coluna, _mundo.getDimensao() , tmp);
		}




	}
	else if (aux == "mata") {
		iss >> linha;

		if (linha <= 0 || linha > _mundo.getDimensao()) {
			cout << "Insira outro valor para a linha!" << endl;
			return;
		}

		iss >> coluna;

		if (coluna <= 0 || coluna > _mundo.getDimensao()) {
			cout << "Insira outro valor para a coluna!" << endl;
			return;
		}

		vector<char> _mapatemp;
		_mapatemp = _mundo.getMapa();

		for (unsigned int i= 0; i < _nNinhos.size(); i++) {
			_nNinhos[i].mataFormigas(linha, coluna, _mundo.getDimensao(),_mapatemp);
		}

		_mundo.setMapa(_mapatemp);

	}
	else if (aux == "inseticida") {

		iss >> tmp;

		if (tmp <= 0) {
			cout << "Insira outro valor!" << endl;
			return;
		}

		vector <char> _mapatemp;

		_mapatemp = _mundo.getMapa();



		for (unsigned int i = 0; i < _nNinhos.size(); i++) {
			if (_nNinhos[i].get_nrNinho() == tmp) {
				_nNinhos[i].mataFormigasTodas(_mapatemp);
				_mapatemp[_nNinhos[i].getPosicaoNinho()] = '-';
				_nNinhos[i].~Ninhos();
				_nNinhos.erase(_nNinhos.begin() + i);

			}
		}
		_mundo.setMapa(_mapatemp);

	}
	else if (aux == "listamundo") {
		//falta implemetar coisas para a segunda meta
		_mundo.listaMundo();

		if (_nNinhos.size() < 0) {
			return;
		}
		cout << "Informacao relativa aos ninhos!" << endl;

		for (unsigned int i = 0; i < _nNinhos.size(); i++) {
			cout << "Comunidade " << _nNinhos[i].get_nrNinho() << endl;
			cout << "Ninho " << _nNinhos[i].get_nrNinho() << " Possui " << _nNinhos[i].getNrFormigasC() << " Formigas!" << endl;
			_nNinhos[i].getEnergia();
			_nNinhos[i].getPercentagem();
			_nNinhos[i].getEnergiaTransferida();

		}



	}
	else if (aux == "listaninho") {
		//falta implementar implementar coisas para a segunda meta
		unsigned int d = 0;

		iss >> d;

		if (d < 0) {
			cout << "Insira outro valor!" << endl;
			return;
		}

		if (d > _nNinhos.size()) {
			cout << "Insira outro valor!" << endl;
			return;
		}

		cout << "Comunidade: " << d << endl;
		cout << "Ninho: " << d << endl;
		_nNinhos[d-1].getFormigasNinho(_mundo.getDimensao());

	}
	else if (aux == "listaposicao") {
		//falta implemetar coisas para a segunda meta (Migalhas)
		iss >> linha;
		iss >> coluna;

		if (linha < 0 || linha > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a linha!" << endl;
			return;
		}

		if (coluna < 0 || coluna > _mundo.getDimensao()) {
			cout << "Intruduza outro valor para a coluna!" << endl;
			return;
		}


		tmp = (((linha - 1) * _mundo.getDimensao()) + (coluna - 1));

		//Ninho
		cout << "Listagem da linha " << linha << " e coluna " << coluna << endl;
		for (unsigned int i = 0; i < _nNinhos.size(); i++) {
			if (_nNinhos[i].getPosicaoNinho() == tmp) {
				cout << "Ninho " << _nNinhos[i].get_nrNinho() << " e Comunidade " << _nNinhos[i].getComunidade() << endl;
				cout << "Energia " << _nNinhos[i].getEnergia() << " , Energia transferida " << _nNinhos[i].getEnergiaTransferida() << " e Percentagem de Energia " << _nNinhos[i].getPercentagem() << "%!" << endl;
				_nNinhos[i].getFormigasPos(tmp);
				return;
			}

			_nNinhos[i].getFormigasPos(tmp);

		}

		
		




	}
	else if (aux == "guarda") {
		iss >> nomeFich;

		if (nomeFich == "default") {
			cout << "Insira outro nome!" << endl;
			return;
		}

		guardaFicheiro(nomeFich);

	} 
	else if (aux == "muda") {
		iss >> nomeFich;
		
		mudaFicheiro(nomeFich);
	} 
	else if (aux == "apaga") {
		iss >> nomeFich;

		if (nomeFich == "default.txt") {
			if (remove("default.txt") == 0) {
				Run();
			}
		

		}

		char array[30];

		strcpy_s(array, nomeFich.c_str());


		if (remove(array) == 0) {
			cout << "Removido com Sucesso!" << endl;
		}
	


	} 
	else if (aux == "sair") {
		gameOn = false;

	}
	else if (aux == "defen") {
		iss >> x;

		if (x < 0) {
			cout << "Erro Insira Mais dados!\n";
			system("PAUSE");
			return;
		}



		_ninho.setEnergia(x);
		_ninho.getEnergia();

	}
	else if (aux == "defpc") {
		iss >> x;

		if (x < 0) {
			cout << "Erro Insira Mais dados!\n";
			system("PAUSE");
			return;
		}

		_ninho.setPercentagem(x);
		_ninho.getPercentagem();
	}
	else if (aux == "defvt") {
		iss >> x;

		if (x < 0) {
			cout << "Erro o valor tem de ser maior que 0!" << endl;
			return;
		}

		_ninho.setEnergiaTransferida(x);
		_ninho.getEnergiaTransferida();
	}
	else if (aux == "defmi") {
		iss >> x;

		if (x < 0 && x > 100) {
			cout << "Erro Insira Mais dados!\n";
			system("PAUSE");
			return;
		}

		_migalhas.setPercInicialPVazias(x);
		_migalhas.getPercInicialPVazias();
	}
	else if (aux == "defme") {
		iss >> x;

		if (x < 0) {
			cout << "Erro o valor tem de ser maior que 0!" << endl;
			return;
		}

		_migalhas.setEnergiaInicial(x);
		_migalhas.getEnergiaInicial();
	}
	else if (aux == "defnm") {
		x = 0;
		iss >> x;

		if (x < 0) {
			cout << "Erro o valor tem de ser maior que 0!" << endl;
			return;
		}

		//_Ninho
		_migalhas.setnMigalhasInst(x);
		_migalhas.getnMigalhasInst();

	}
	else if (aux == "executa") {
		iss >> nomeFich;
		string line, aux1;
		int num = 0;

		ifstream myfile(nomeFich);

		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				istringstream is(line);
				is >> aux1;

				if (aux1 == "defen") {
					is >> num;

					if (num < 0) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
					}
					else {
						_ninho.setEnergia(num);
						_ninho.getEnergia();
					}

				}
				else if (aux1 == "defpc") {
					is >> num;

					if (num < 0) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
					}
					else {
						_ninho.setPercentagem(num);
						_ninho.getPercentagem();
					}

				}
				else if (aux1 == "defvt") {
					is >> num;

					if (x < 0) {
						cout << "Erro o valor tem de ser maior que 0!" << endl;
					}
					else {
						_ninho.setEnergiaTransferida(num);
						_ninho.getEnergiaTransferida();
					}

				}
				else if (aux1 == "defmi") {
					is >> num;

					if (num < 0 && num > 100) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
						return;
					}
					else {
						_migalhas.setPercInicialPVazias(num);
						_migalhas.getPercInicialPVazias();
					}

				}
				else if (aux1 == "defme") {
					is >> num;

					if (num < 0) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
					}
					else {
						_migalhas.setEnergiaInicial(num);
						_migalhas.getEnergiaInicial();
					}

				}
				else if (aux1 == "defnm") {
					num = 0;
					is >> num;


					if (num < 0) {
						cout << "Erro Insira Mais dados!\n";
						system("PAUSE");
					}
					else {
						_migalhas.setnMigalhasInst(num);
						_migalhas.getnMigalhasInst();
					}
					
				}

			}

			myfile.close();
		}
		else {
			cout << "Erro a abrir o ficheiro " << nomeFich << endl;
		}

	}


}

void Configuracao::Simulacao() {
	system("cls");
	cout << "Sou eu a Simulacao!" << endl;
	bool gameOn = true;
	string comando;

	criaMigalhasIniciais();
	do {
		cout << "Insira o comando: ";
		getline(cin, comando);

		//Meter listagem de comandos
		Comandos(comando, gameOn);
		system("PAUSE");
		system("cls");
	} while (gameOn == true);

	cout << "Fim da simulacao!" << endl;

}

void Configuracao::Iteracao(int nIteracoes) {

	int linha = 0, coluna = 0;
	vector<char> _mapatemp;

	for (int j = 0; j < nIteracoes; j++) {	

	criaMigalhas();

	_mapatemp = _mundo.getMapa();


	for (unsigned int i = 0; i < _nNinhos.size(); i++) {
		//mexe todas as formigas do ninho
		_nNinhos[i].mexeFormigasNinho(_mapatemp, _mundo.getDimensao(), _nMigalhas, _nNinhos);
		

	}



	//Ninhos criam 
	for (unsigned int i = 0; i < _nNinhos.size(); i++) {
		if (_nNinhos[i].getEnergia() > _nNinhos[i].getEnergiaInicial() / _ninho.getPercentagem()) {
			if (_nNinhos[i].verificaFormigasPos(_nNinhos[i].getPosicaoNinho()) == 0) {
				int v1 = rand() % 5 + 1;

				if (v1 == 1) {
					Cuidadora temporaria(_nNinhos[i].get_nrNinho());
					temporaria.setPosicao(_nNinhos[i].getPosicaoNinho());
					temporaria.setCriandaNinho(1);
					_nNinhos[i].setFormigasCuidadoras(temporaria);

				}
				else if (v1 == 2) {
					Vigilante temporaria(_nNinhos[i].get_nrNinho());
					temporaria.setPosicao(_nNinhos[i].getPosicaoNinho());
					temporaria.setCriandaNinho(1);
					_nNinhos[i].setFormigasVigilantes(temporaria);

				}
				else if (v1 == 3) {
					Assaltante temporaria(_nNinhos[i].get_nrNinho());
					temporaria.setPosicao(_nNinhos[i].getPosicaoNinho());
					temporaria.setCriandaNinho(1);
					_nNinhos[i].setFormigasAssaltantes(temporaria);

				}
				else if (v1 == 4) {
					Exploradora temporaria(_nNinhos[i].get_nrNinho());
					temporaria.setPosicao(_nNinhos[i].getPosicaoNinho());
					temporaria.setCriandaNinho(1);
					_nNinhos[i].setFormigasExploradoras(temporaria);
				}
				else if (v1 == 5) {
					Surpresa temporaria(_nNinhos[i].get_nrNinho());
					temporaria.setPosicao(_nNinhos[i].getPosicaoNinho());
					temporaria.setCriandaNinho(1);
					_nNinhos[i].setFormigasSupresa(temporaria);

				}


			}

		}
	}

	//Verificar morte de migalhas ou formigas energia = 0 ou energia < 0
	for (unsigned int x = 0; x < _nNinhos.size(); x++) {
		_nNinhos[x].verificaEnergiaFormigas(_mapatemp);

	}

	//Matar as migalhas
	for (unsigned int i = 0; i < _nMigalhas.size(); i++) {
		_nMigalhas[i].setEnergia(_nMigalhas[i].getEnergia() - 1); //Perde um de energia por iteração
		if (_nMigalhas[i].getEnergia() <= _migalhas.getEnergiaInicial() / 10) {
			_mapatemp[_nMigalhas[i].getPosicao()] = '-';
			_nMigalhas[i].~Migalhas();
			_nMigalhas.erase(_nMigalhas.begin() + i);
		}
	}

	}
	_mundo.setMapa(_mapatemp);
	_mundo.imprimeMapa();

}

int Configuracao::guardaFicheiro(string nome) {

	ofstream myfile;
	myfile.open(nome);

	if (!myfile.is_open()) {
		cout << "Erro a abrir o ficheiro para escrita!" << endl;
		return 1;
	}

	//Guardar informação de ninhos
	myfile << _ninho.getEnergia() << "\n";
	myfile << _ninho.getPercentagem() << "\n";
	myfile << _ninho.getEnergiaTransferida() << "\n";
	myfile << _ninho.get_nrNinho() << "\n";
	myfile << _ninho.getPosicaoNinho() << "\n";

	//mundo
	myfile << _mundo.getDimensao() << "\n";
	vector <char> mapa = _mundo.getMapa();
	for (unsigned int i = 0; i < (_mundo.getDimensao() * _mundo.getDimensao()); i++) {
		myfile << mapa[i] << "\n";
	}
	myfile << _mundo.getX() << "\n";
	myfile << _mundo.getY() << "\n";


	//Migalhas
	myfile << _migalhas.getPercInicialPVazias() << "\n";
	myfile << _migalhas.getEnergiaInicial() << "\n";
	myfile << _migalhas.getnMigalhasInst() << "\n";
	myfile << _migalhas.getPosicao() << endl;
	myfile << _migalhas.getEnergia() << endl;
	
	//Vector de ninhos
	myfile << _nNinhos.size() << "\n";
	for (unsigned int i = 0; i < _nNinhos.size(); i++) {
		myfile << _nNinhos[i].getEnergia() << "\n";
		myfile << _nNinhos[i].getEnergiaInicial() << "\n";
		myfile << _nNinhos[i].getPercentagem() << "\n";
		myfile << _nNinhos[i].getEnergiaTransferida() << "\n";
		myfile << _nNinhos[i].get_nrNinho() << "\n";
		myfile << _nNinhos[i].getPosicaoNinho() << endl;

		//Formigas
		vector<Formigas> formigas = _nNinhos[i].getFormigas();
		myfile << formigas.size() << "\n";

		for (unsigned j = 0; j < formigas.size(); j++) {
			myfile << formigas[j].getRaioVisao() << "\n";
			myfile << formigas[j].getRaioMovimento() << "\n";
			myfile << formigas[j].getEnergiaInicial() << "\n";
			myfile << formigas[j].getEnergia() << "\n";
			myfile << formigas[j].getPosicao() << "\n";
			myfile << formigas[j].getNFormiga() << "\n";
			myfile << formigas[j].getTipo() << "\n";
			myfile << formigas[j].getNrNinho() << "\n";
			myfile << formigas[j].getCriadaNinho() << "\n";
		}
	}


	//vector de formigas
	myfile << _nMigalhas.size() << "\n";

	for (unsigned int i = 0; i < _nMigalhas.size(); i++) {
		myfile << _nMigalhas[i].getPercInicialPVazias() << "\n";
		myfile << _nMigalhas[i].getEnergiaInicial() << "\n";
		myfile << _nMigalhas[i].getnMigalhasInst() << "\n";
		myfile << _nMigalhas[i].getPosicao() << "\n";
		myfile << _nMigalhas[i].getEnergia() << "\n";
	}




	myfile.close();
	return 0;
} // mudar

void Configuracao::criaMigalhas() {

	int v1 = rand() % _migalhas.getnMigalhasInst();
	int posicao = 0;



	for (int i = 0; i < v1; i++) {
		if(_mundo.espacoMapa() > 0) {
			Migalhas aux(_migalhas.getEnergiaInicial());
			posicao = 0;
			posicao = _mundo.posicaoAleatoriaF();
			aux.setPosicao(posicao);

			_mundo.setMigalha(posicao);

			_nMigalhas.push_back(aux);
		}
		


	}
	




}

void Configuracao::criaMigalhasIniciais() {
	int posicao = 0;

	int migalhas = (_migalhas.getPercInicialPVazias() / 100) * (_mundo.getDimensao() * _mundo.getDimensao());



	for (int i = 0; i < migalhas; i++) {
		if (_mundo.espacoMapa() > 0) {
			Migalhas aux(_migalhas.getEnergiaInicial());
			posicao = 0;
			posicao = _mundo.posicaoAleatoriaF();
			aux.setPosicao(posicao);

			_mundo.setMigalha(posicao);

			_nMigalhas.push_back(aux);
		}



	}

}

void Configuracao::mudaFicheiro(string nome) {
	
	ifstream myfile(nome);
	int ponto = 0, nrformigas = 0, raiovisao = 0,nrNinho = 0, raioMovimento = 0, energiaInicial = 0, energia = 0, posicao = 0,nrFormiga = 0;
	char tipo;
	string line;


	if (!myfile.is_open()) {
		cout << "Erro a Abrir o ficheiro!" << endl;
		return;
	}

	_ninho.setNrNinhoStatic0();
	_ninho.~Ninhos();

	//Ninho
	getline(myfile,line);
	_ninho.setEnergia(stoi(line));
	line.clear();

	getline(myfile, line);
	_ninho.setPercentagem(stoi(line));
	line.clear();

	getline(myfile, line);
	_ninho.setEnergiaTransferida(stoi(line));
	line.clear();

	getline(myfile, line);
	_ninho.setNrNinho(stoi(line));
	line.clear();

	getline(myfile, line);
	_ninho.setPosicao(stoi(line));
	line.clear();

	_mundo.~Mundo();

	//mundo
	getline(myfile, line);
	_mundo.setDimensao(stoi(line));
	ponto = stoi(line);
	line.clear();

	vector<char> mapa;
	for (unsigned int i = 0; i < (ponto * ponto); i++) {
		getline(myfile, line);
		mapa.push_back(line[0]);
		line.clear();
	}

	_mundo.setMapa(mapa);

	getline(myfile, line);
	int x = stoi(line);
	line.clear();

	getline(myfile, line);
	int y = stoi(line);
	line.clear();

	_mundo.setXY(x, y);

	//Migalhas
	_migalhas.~Migalhas();

	getline(myfile, line);
	_migalhas.setPercInicialPVazias(stoi(line));
	line.clear();

	getline(myfile, line);
	_migalhas.setEnergiaInicial(stoi(line));
	line.clear();

	getline(myfile, line);
	_migalhas.setnMigalhasInst(stoi(line));
	line.clear();

	getline(myfile, line);
	_migalhas.setPosicao(stoi(line));
	line.clear();

	getline(myfile, line);
	_migalhas.setEnergia(stoi(line));
	line.clear();

	//NINHOS
	ponto = 0;
	getline(myfile, line);
	ponto = stoi(line);
	line.clear();

	for (unsigned int i = 0; i < _nNinhos.size(); i++) {
		_nNinhos[i].~Ninhos();
	}

	_nNinhos.clear();


	for (unsigned int i = 0; i < ponto; i++) {
		nrformigas = 0;
		Ninhos aux;
		getline(myfile, line);
		aux.setEnergia(stoi(line));
		line.clear();

		getline(myfile, line);
		aux.setEnergiaInicial(stoi(line));
		line.clear();

		getline(myfile, line);
		aux.setPercentagem(stoi(line));
		line.clear();

		getline(myfile, line);
		aux.setEnergiaTransferida(stoi(line));
		line.clear();

		getline(myfile, line);
		aux.setNrNinho(stoi(line));
		line.clear();

		getline(myfile, line);
		aux.setPosicao(stoi(line));
		line.clear();

		getline(myfile, line);
		nrformigas = stoi(line);
		line.clear();


		

		for (unsigned int j = 0; j < nrformigas; j++) {
			getline(myfile, line);
			raiovisao = stoi(line);
			line.clear();

			getline(myfile, line);
			raioMovimento = stoi(line);
			line.clear();

			getline(myfile, line);
			energiaInicial = stoi(line);
			line.clear();

			getline(myfile, line);
			energia = stoi(line);
			line.clear();
		
			getline(myfile, line);
			posicao = stoi(line);
			line.clear();

			getline(myfile, line);
			nrFormiga = stoi(line);
			line.clear();

			getline(myfile, line);
			tipo = line[0];
			line.clear();

			getline(myfile, line);
			nrNinho = stoi(line);
			line.clear();

			if (tipo == 'C') {
				Cuidadora x(nrNinho);

				getline(myfile, line);
				x.setCriandaNinho(stoi(line));
				line.clear();

				x.setRaioVisao(raiovisao);
				x.setRaioMovimento(raioMovimento);
				x.setEnergiaInicial(energiaInicial);
				x.setEnergia(energia);
				x.setPosicao(posicao);
				x.setNformiga(nrFormiga);
				x.setTipo(tipo);
				x.setnNinho(nrNinho);

				aux.setFormigasCuidadoras(x);




			}
			else if (tipo == 'E') {
				Exploradora x(nrNinho);

				getline(myfile, line);
				x.setCriandaNinho(stoi(line));
				line.clear();

				x.setRaioVisao(raiovisao);
				x.setRaioMovimento(raioMovimento);
				x.setEnergiaInicial(energiaInicial);
				x.setEnergia(energia);
				x.setPosicao(posicao);
				x.setNformiga(nrFormiga);
				x.setTipo(tipo);
				x.setnNinho(nrNinho);

				aux.setFormigasExploradoras(x);



			}
			else if (tipo == 'V') {
				Vigilante x(nrNinho);

				getline(myfile, line);
				x.setCriandaNinho(stoi(line));
				line.clear();

				x.setRaioVisao(raiovisao);
				x.setRaioMovimento(raioMovimento);
				x.setEnergiaInicial(energiaInicial);
				x.setEnergia(energia);
				x.setPosicao(posicao);
				x.setNformiga(nrFormiga);
				x.setTipo(tipo);
				x.setnNinho(nrNinho);

				aux.setFormigasVigilantes(x);
			}
			else if (tipo == 'S') {
				Surpresa x(nrNinho);

				getline(myfile, line);
				x.setCriandaNinho(stoi(line));
				line.clear();

				x.setRaioVisao(raiovisao);
				x.setRaioMovimento(raioMovimento);
				x.setEnergiaInicial(energiaInicial);
				x.setEnergia(energia);
				x.setPosicao(posicao);
				x.setNformiga(nrFormiga);
				x.setTipo(tipo);
				x.setnNinho(nrNinho);

				aux.setFormigasSupresa(x);


			}
			else if (tipo == 'A') {
				Assaltante x(nrNinho);

				getline(myfile, line);
				x.setCriandaNinho(stoi(line));
				line.clear();

				x.setRaioVisao(raiovisao);
				x.setRaioMovimento(raioMovimento);
				x.setEnergiaInicial(energiaInicial);
				x.setEnergia(energia);
				x.setPosicao(posicao);
				x.setNformiga(nrFormiga);
				x.setTipo(tipo);
				x.setnNinho(nrNinho);

				aux.setFormigasAssaltantes(x);
			}

		}


		_nNinhos.push_back(aux);
	}

	//Migalhas
	getline(myfile, line);
	ponto = stoi(line);
	line.clear();

	_nMigalhas.clear();

	for (unsigned int i = 0; i < ponto; i++) {
		Migalhas d;
		getline(myfile, line);
		d.setPercInicialPVazias(stoi(line));
		line.clear();

		getline(myfile, line);
		d.setEnergiaInicial(stoi(line));
		line.clear();

		getline(myfile, line);
		d.setnMigalhasInst(stoi(line));
		line.clear();

		getline(myfile, line);
		d.setPosicao(stoi(line));
		line.clear();

		getline(myfile, line);
		d.setEnergia(stoi(line));
		line.clear();


		_nMigalhas.push_back(d);
	}





	myfile.close();
}

Configuracao::~Configuracao()
{
}
