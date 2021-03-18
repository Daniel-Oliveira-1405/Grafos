#include<iostream>
#include<vector>
#include "grafos.h"

using namespace std;

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
	
	grafo.removerVertice(v5);
	Vertice v=grafo.getVertice(4);
	grafo.novaConexao(0,5,400,false); // Rio de Janeiro para Vitória (400 km -> Direcionado)
	
	grafo.imprimirGrafo();
}
