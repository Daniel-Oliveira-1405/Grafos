#include<iostream>
#include<vector>

using namespace std;

class Vertice
{
public:
	Vertice(string nome);
	Vertice(const Vertice& copia);
	void novoVizinho(int v, int peso);
	
	string getNome(){return this->nome;}
	
	vector<int> vizinhos;
	vector<int> pesos;
	
private:
	string nome;
};

Vertice::Vertice(string nome)
{
	if(nome=="") this->nome="Sem nome";
	else this->nome=nome;
}

Vertice::Vertice(const Vertice& copia){
	this->nome=copia.nome;
	this->vizinhos = copia.vizinhos;
}

void Vertice::novoVizinho(int v, int peso)
{
	this->vizinhos.push_back(v);
	this->pesos.push_back(peso);
}

class Grafo
{
public:
	Grafo(){}
	bool novaConexao(int v1, int v2, int peso=0, bool conexao_dupla=false);
	void novoVertice(Vertice v);
	void novoVertice(string nome);
	void imprimirGrafo();
private:
	vector<Vertice> vertices;
};

bool Grafo::novaConexao(int v1, int v2, int peso=0, bool conexao_dupla=false)
{
	if(v1 >= vertices.size() || v2 >= vertices.size())
		return false;
	vertices[v1].novoVizinho(v2,peso);
	if(conexao_dupla)
		vertices[v2].novoVizinho(v1,peso);
}

void Grafo::novoVertice(string nome)
{
	vertices.push_back(Vertice(nome));
}

void Grafo::novoVertice(Vertice v)
{
	vertices.push_back(v);
}

void Grafo::imprimirGrafo()
{
	for(int i=0; i<vertices.size(); i++)
	{
		cout << "Vertice " << vertices[i].getNome()/* << "(" << i << "):" */<< ": ";
		vector<int> vizinhos = vertices[i].vizinhos;
		for(int j=0; j<vizinhos.size(); j++){
			int index=vizinhos[j];
			Vertice v=vertices[index];
			cout << v.getNome() << " (Peso/Dist: " << vertices[i].pesos[j] << "), ";
		}
		cout << "\b\b  \n\n";
	}/*
	for(int i=0; i<vertices.size(); i++){
		vector<int> vizinhos = vertices[i].vizinhos;
		for(int j=0; j<vizinhos.size(); j++){
			int index=vizinhos[j];
			Vertice v=vertices[index];
			cout << vertices[i].getNome() << " => " << vertices[i].pesos[j] << " => " << v.getNome() << "\n";
		}
	}*/
}

int main(){
	Grafo grafo;
	Vertice v0("Rio de Janeiro");
	Vertice v1("Belo Horizonte");
	Vertice v2("Sao Paulo");
	Vertice v3("Brasilia");
	Vertice v4("Goiania");
	Vertice v5("Vitoria");
	Vertice v6("Curitiba");
	Vertice v7("Santos");
	Vertice v8("Sao Jose dos Campos");
	Vertice v9("Juiz de Fora");
	Vertice v10("Uberlandia");
	Vertice v11("Ribeirao Preto");
	Vertice v12("Campinas");
	
	grafo.novoVertice(v0);
	grafo.novoVertice(v1);
	grafo.novoVertice(v2);
	grafo.novoVertice(v3);
	grafo.novoVertice(v4);
	grafo.novoVertice(v5);
	grafo.novoVertice(v6);
	grafo.novoVertice(v7);
	grafo.novoVertice(v8);
	grafo.novoVertice(v9);
	grafo.novoVertice(v10);
	grafo.novoVertice(v11);
	grafo.novoVertice(v12);
	
	grafo.novaConexao(0,1,600,true); // Rio de Janeiro para Belo Horizonte
	grafo.novaConexao(0,5,400,true); // Rio de Janeiro para Vitória
	grafo.novaConexao(0,7,500,true); // Rio de Janeiro Para Santos
	grafo.novaConexao(0,8,300,true); // Rio de Janeiro para São José dos Campos
	
	grafo.novaConexao(1,2,500,true); // Belo Horizonte para São Paulo
	grafo.novaConexao(1,3,630,true); // Belo Horizonte para Brasília
	grafo.novaConexao(1,5,380,true); // Belo Horizonte para Vitória
	grafo.novaConexao(1,9,263,true); // Belo Horizonte para Juiz de Fora
	
	grafo.novaConexao(2,6,330,true); // São Paulo para Curitiba
	grafo.novaConexao(2,8,100,true); // São Paulo para São José dos Campos
	grafo.novaConexao(2,7,75,true);  //  "    "    "   Santos
	grafo.novaConexao(2,12,100,true);//  "    "    "   Campinas
	
	grafo.novaConexao(3,4,300,true); // Brasília para Goiânia
	grafo.novaConexao(3,10,430,true);//    "       "  Uberlândia
	
	grafo.novaConexao(10,11,250,true); // Ribeirão Preto para Uberlândia
	
	grafo.imprimirGrafo();
}
