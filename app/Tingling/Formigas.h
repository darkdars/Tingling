#pragma once
class Formigas
{
public:
	Formigas();
	Formigas(int n_energia, int raioVisao, int raioMovimento,char tipo,int nrNinho);
	void setPosicao(int valor);
	int getPosicao();
	int getEnergiaInicial();
	int getEnergia();
	int getNFormiga();
	char getTipo();
	void getLinhaColuna(int posicao, int &linha, int &coluna, int dimensao);
	void geraPosicaoF(int raio,int &linha, int &coluna);
	int getNrNinho();
	void acrescentaEnergia(int energia);
	void decrementaEnergia(int energia);
	int getRaioVisao();
	int getRaioMovimento();
	int getCriadaNinho();
	void setCriandaNinho(int nr);
	void setRaioVisao(int raioVisao);
	void setRaioMovimento(int raioMovimento);
	void setEnergiaInicial(int energia);
	void setEnergia(int energia);
	void setNformiga(int nr);
	void setTipo(char tipo);
	void setnNinho(int nr);
	void setIter(int nr);
	int getIter();
	static int nFormiga;
	~Formigas();
private:
	int _raioVisao;
	int _raioMovimento;
	int _eInicial;
	int _energia;
	int _posicao;
	int _nFormiga;
	char _tipo;
	int _nNinho;
	int _criadaNinho;
	int iter;
};

