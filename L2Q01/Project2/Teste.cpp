#include "Teste.h"

void main() {
	cout << "+++++++++++++++++++++++++++\n";
	cout << "Programa de Teste de Fila\n";
	cout << "+++++++++++++++++++++++++++\n";
	Fila fila;
	int n, opcao;
	while ((opcao = menu()) != SAIR)
	{
		switch (opcao)
		{
		case IMPRIMIR:
			fila.imprime();
			cout << endl;
			break;
		case INSERIR:
			cout << "n? ";
			cin >> n;
			fila.insere(n);
			break;
		case APAGAR:
			fila.remove();
			cout << endl;
			break;
		case PROCURAR:
			cout << "n? ";
			cin >> n;
			if (fila.existe(n))
				cout << "O elemento estah na lista!\n";
			else
				cout << "Este elemento nao estah na lista...\n";
			break;
		case SAIR:
			fila.sair();
			break;
		default:
			cout << "Opcao Invalida! \n";
		} //fim do switch
	} //fim do while
} //fim do main

int menu()
{
	int opcao;
	cout << IMPRIMIR << " - imprimir a fila\n";
	cout << INSERIR << " - inserir um elemento\n";
	cout << APAGAR << " - retirar um elemento\n";
	cout << PROCURAR << " - verificar se o elemento estah presente na fila\n";
	cout << SAIR << " - encerrar o programa\n";
	cout << "Opcao ? ";
	cin >> opcao;
	return opcao;
}