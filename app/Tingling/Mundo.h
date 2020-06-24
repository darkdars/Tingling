#pragma once
#include <vector>

using namespace std;

class Mundo
{
public:
	Mundo();
	void setDimensao(int valor);
	int getDimensao();
	void imprimeMapa();
	void setNinho(int nr, int linha, int coluna);
	int verificaNinho(int linha, int coluna); // se ja existe outro ninho
	int espacoMapa();
	void listaMundo();
	int posicaoAleatoriaF();
	void setFormiga(char c,int posicao);
	vector<char> getMapa();
	void setMapa(vector<char> mapa);
	int verificaPosicao(int linha, int coluna);
	void setMigalha(int linha, int coluna);
	void setMigalha(int posicao);
	void setXY(int x, int y);
	int getX();
	int getY();
	~Mundo();
private:
	int _dimensao;
	vector<char> _mapa;
	int _x;
	int _y;
};

