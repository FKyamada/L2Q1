#pragma once

#include "No.h"
class Fila
{
	No* primeiro, *ultimo;
public:
	//Construtor
	Fila(); //cria Fila vazia
			 //M�todos de Acesso
	No* getUltimo();
	void setUltimo(No* novoNo);
	No*getPrimeiro(); //retorna o primeiro n� da Fila
	void setPrimeiro(No* novoNo); //torna "novoNo" o primeiro n� da Fila


	//M�todos
	bool eVazia(); //retorna verdadeiro se a lista � uma fila vazia
	void insere(int elem); //insere elemento no in�cio
	No* remove(); //remove todas as ocorrencias de elem
	bool existe(int elem); //verifica se elem existe
	void imprime(); //imprime todos os elementos
	void sair();
	//Destrutor
	~Fila(); //Destroi todos os n�s da Fila
};
