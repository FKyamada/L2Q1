#include "Fila.h"

//Construtor
Fila::Fila()
{
	primeiro = NULL;
}
//M�todos de Acesso
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
//M�todos
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
		setPrimeiro(aux);//o primeiro elemento da Fila passa a ser o primeiro n�;
		ultimo = primeiro;//incializandoo ultimo n�;
	}
	else {

		ultimo->setProximo(aux); //armazena proxino n� da nova Fila;
		ultimo = ultimo->getProximo(); //Mudando o valor do Ultimo N� ;

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
			cout << pAux->getInfo();//impress�o do n� atual
			if (pAux->getProximo() != NULL)//Se ainda existem n�s...
			{
				cout << ", ";
				pAux = pAux->getProximo(); //passa-se ao pr�ximo n�
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
					//Quando o elem � o primeiro da Fila...
	else {
		No* pAux = primeiro;//armazena o primeiro a ser removido.
		primeiro = primeiro->getProximo(); //passa-se ao pr�ximo n�,
										   //que agora � o primeiro.
		pAux->~No(); //destrui��o do n� removido
		delete pAux; //destrui��o do n� removido de forma mais limpa
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
			pAux = pAux->getProximo(); //passa-se ao pr�ximo n�
	}
	return false; //nenhum n� com valor "elem" foi encontrado
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
{//A Fila deve ser destru�da n� por n�.
	No* pAux;
	while (primeiro != NULL)
	{
		pAux = primeiro;
		primeiro = primeiro->getProximo();
		pAux->~No();
	}
}