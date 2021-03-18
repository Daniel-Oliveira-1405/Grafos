#include<iostream>
#include<vector>

using namespace std;

//-------------------------------------------------
// VÉRTICES (Classe)
//-------------------------------------------------

class Vertice
{
public:
	Vertice(string nome);
	Vertice(const Vertice& copia);
	void novoVizinho(int v, int peso);
	void removerVizinho(int v);
	void mudarNome(string nome);
	virtual ~Vertice();
	
	string getNome(){return this->nome;}
	
	bool operator==(Vertice v){
		if(nome==v.getNome() && vizinhos==v.vizinhos && pesos==v.pesos)
			return true;
		return false;
	}
	
	vector<int> vizinhos;
	vector<int> pesos;
protected:
	string nome;
};

//-------------------------------------------------
// GRAFOS (classe)
//-------------------------------------------------

class Grafo
{
public:
	Grafo(){}
	void novaConexao(int v1, int v2, int peso=0, bool duplo=false);
	void novaConexao(Vertice v1, Vertice v2, int peso=0, bool duplo=false);
	void novoVertice(Vertice v);
	void novoVertice(string nome);
	void removerVertice(int p);
	void removerVertice(Vertice v);
	void removerConexao(int v1, int v2, bool duplo);
	void imprimirGrafo();
	int IndiceDoVertice(Vertice v);
	int IndiceDoVertice(string nome);
	Vertice& getVertice(int index);
	
	void operator=(Grafo g){
		g.vertices = vertices;
		g.removidos = removidos;
	}
	bool operator==(Grafo g){
		if(g.vertices==vertices && g.removidos==removidos)
			return true;
		return false;
	}
protected:
	vector<Vertice> vertices;
	vector<int> removidos;
};

//-------------------------------------------------
// VÉRTICES (funções)
//-------------------------------------------------

Vertice::Vertice(string nome)
{
	if(nome=="") this->nome="Sem nome";
	else this->nome=nome;
	this->vizinhos={};
}

Vertice::~Vertice(){
}

Vertice::Vertice(const Vertice& copia){
	this->nome=copia.nome;
	this->vizinhos = copia.vizinhos;
}

void Grafo::removerVertice(Vertice v){
	int v1=IndiceDoVertice(v);
	if(v1!=-1) removerVertice(v);
}

void Vertice::mudarNome(string nome){
	this->nome=nome;
}

void Vertice::novoVizinho(int v, int peso)
{
	this->vizinhos.push_back(v);
	this->pesos.push_back(peso);
}

void Vertice::removerVizinho(int v){
	for(int i=0; i<vizinhos.size(); i++){
		if(vizinhos[i]==v){
			vector<int>::iterator it=vizinhos.begin();
			it+=v-1;
			vizinhos.erase(it);
			return NULL;
		}
	}
}

Vertice& Grafo::getVertice(int index){
	return vertices[index];
}

//-------------------------------------------------
// 			    GRAFOS (Funções)
//-------------------------------------------------

void Grafo::novaConexao(int v1, int v2, int peso, bool duplo)
{
	if(v1 >= vertices.size() || v2 >= vertices.size()){
		throw "Pelo menos um dos vertices nao existe.\n";
		return NULL;
	}
	vertices[v1].novoVizinho(v2,peso);
	if(duplo)
		vertices[v2].novoVizinho(v1,peso);
}

int Grafo::IndiceDoVertice(Vertice v){
	int vv=-1;
	for(int i=0; i<vertices.size(); i++)
		if(vertices[i]==v){
			vv=i;
			break;
		}
	return vv;
}

int Grafo::IndiceDoVertice(string nome){
	int ind=-1;
	for(int i=0; i<vertices.size(); i++)
		if(vertices[i].getNome()==nome){
			ind=i;
			break;
	}
	return ind;
}

void Grafo::novaConexao(Vertice v1, Vertice v2, int peso, bool duplo){
	int V1=IndiceDoVertice(v1);
	int V2=IndiceDoVertice(v2);
	if(V1==-1 || V2==-1){
		throw "Pelo menos um dos vertices nao existe.\n";
		return NULL;
	}
	novaConexao(V1,V2,peso,duplo);
}

void Grafo::removerVertice(int p){
	bool duplo=true;
	for(int i=0; i<vertices.size(); i++){
		if(i!=p)
			removerConexao(i,p,false);
	}
	vertices[p]=Vertice("");
	removidos.push_back(p);
}

void Grafo::removerConexao(int v1, int v2, bool duplo){
	vertices[v1].removerVizinho(v2);
	if(duplo)
		vertices[v2].removerVizinho(v1);
}

void Grafo::novoVertice(string nome)
{
	novoVertice(Vertice(nome));
}

void Grafo::novoVertice(Vertice v)
{
	loop: for(int i=0; i<vertices.size(); i++){
		if(vertices[i].getNome()==v.getNome()){
			v.mudarNome(v.getNome()+" (Copia)");
			goto loop;
		}
	}
	if(removidos.size()==0)
		vertices.push_back(v);
	else{
		vector<int>::iterator it=removidos.begin();
		removidos.erase(it);
		vertices[*it]=v;
	}
}

void Grafo::imprimirGrafo()
{
	for(int i=0; i<vertices.size(); i++)
	{
		if(vertices[i]==Vertice("")) continue;
		cout << "Vizinhos do vertice " << vertices[i].getNome() << ": ";
		vector<int> vizinhos = vertices[i].vizinhos;
		if(vizinhos.size()==0){
			cout << "\n\n";
			continue;
		}
		for(int j=0; j<vizinhos.size(); j++){
			int index=vizinhos[j];
			Vertice v=vertices[index];
			cout << v.getNome() << " (Peso/Dist: " << vertices[i].pesos[j] << "), ";
		}
		cout << "\b\b.\n\n";
	}
	/*
	for(int i=0; i<vertices.size(); i++){
		vector<int> vizinhos = vertices[i].vizinhos;
		for(int j=0; j<vizinhos.size(); j++){
			int index=vizinhos[j];
			Vertice v=vertices[index];
			cout << vertices[i].getNome() << " => " << vertices[i].pesos[j] << " => " << v.getNome() << "\n";
		}
	}*/
}
