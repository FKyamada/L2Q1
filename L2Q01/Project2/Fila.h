#pragma once

#include "No.h"
class Fila
{
	No* primeiro, *ultimo;
public:
	//Construtor
	Fila(); //cria Fila vazia
			 //Métodos de Acesso
	No* getUltimo();
	void setUltimo(No* novoNo);
	No*getPrimeiro(); //retorna o primeiro nó da Fila
	void setPrimeiro(No* novoNo); //torna "novoNo" o primeiro nó da Fila


	//Métodos
	bool eVazia(); //retorna verdadeiro se a lista é uma fila vazia
	void insere(int elem); //insere elemento no início
	No* remove(); //remove todas as ocorrencias de elem
	bool existe(int elem); //verifica se elem existe
	void imprime(); //imprime todos os elementos
	void sair();
	//Destrutor
	~Fila(); //Destroi todos os nós da Fila
};
