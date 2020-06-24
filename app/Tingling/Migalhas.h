#pragma once
class Migalhas
{
public:
	Migalhas();
	Migalhas(int energia);
	Migalhas(int energiaInicial, int linha, int coluna, int dimensao);
	void setPercInicialPVazias(int valor);
	int getPercInicialPVazias();
	void setEnergiaInicial(int valor);
	int getEnergiaInicial();
	void setnMigalhasInst(int valor);
	int getnMigalhasInst();
	int getEnergia();
	int getPosicao();
	void setPosicao(int posicao);
	void decrementaEnergia(int energia);
	void incrementaEnergia(int energia);
	void setEnergia(int energia);
	~Migalhas();
private:
	int _pInicialPvazias; // Percentagem inicial de posicoes vazias que tem (inicialmente) migalhas
	int _energiaInicial;
	int _nMigalhasInst;
	int _posicao;
	int _energia;
};

