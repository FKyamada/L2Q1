#include "Fila.h"

//Construtor
Fila::Fila()
{
	primeiro = NULL;
}
//Métodos de Acesso
No* Fila::getPrimeiro()
{
	return primeiro;
}
void Fila::setPrimeiro(No* novoNo)
{
	primeiro = novoNo;
}
No* Fila::getUltimo()
{
	return ultimo;
}
void Fila::setUltimo(No* novoNo)
{
	ultimo = novoNo;
}
//Métodos
bool Fila::eVazia()
{
	if (primeiro == NULL)
		return true;
	return false;
}
void Fila::insere(int elem)
{
	No* aux = new No(elem);

	if (eVazia()) {
		setPrimeiro(aux);//o primeiro elemento da Fila passa a ser o primeiro nó;
		ultimo = primeiro;//incializandoo ultimo nó;
	}
	else {

		ultimo->setProximo(aux); //armazena proxino nó da nova Fila;
		ultimo = ultimo->getProximo(); //Mudando o valor do Ultimo Nó ;

	}
}
void Fila::imprime()
{
	if (eVazia())
		cout << "{ }";
	else
	{
		No* pAux = primeiro;
		cout << "{";
		while (true)
		{
			cout << pAux->getInfo();//impressão do nó atual
			if (pAux->getProximo() != NULL)//Se ainda existem nós...
			{
				cout << ", ";
				pAux = pAux->getProximo(); //passa-se ao próximo nó
			}
			else
			{ //fim da Fila
				cout << "}";
				break;
			}
		}
	}
}
No* Fila::remove()
{
	if (eVazia())
		return NULL;//o metodo retorna um ponteiro para No...
					//Quando o elem é o primeiro da Fila...
	else {
		No* pAux = primeiro;//armazena o primeiro a ser removido.
		primeiro = primeiro->getProximo(); //passa-se ao próximo nó,
										   //que agora é o primeiro.
		pAux->~No(); //destruição do nó removido
		delete pAux; //destruição do nó removido de forma mais limpa
	}
}
bool Fila::existe(int elem)
{
	if (eVazia())
		return false;
	No* pAux = primeiro;
	while (pAux != NULL)
	{
		if (pAux->getInfo() == elem)//elemento encontrado!
			return true;
		else
			pAux = pAux->getProximo(); //passa-se ao próximo nó
	}
	return false; //nenhum nó com valor "elem" foi encontrado
}
void Fila::sair()
{
	No*pAux = primeiro;
	while (pAux != NULL)
	{
		pAux->~No();
		delete pAux;
	}


}


//Destrutor
Fila::~Fila()
{//A Fila deve ser destruída nó por nó.
	No* pAux;
	while (primeiro != NULL)
	{
		pAux = primeiro;
		primeiro = primeiro->getProximo();
		pAux->~No();
	}
}