
#include <iostream>
using namespace std;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
int posicaoElemento(int valor);
//--------------------------


const int MAX = 10;;
int lista[MAX]{};
int nElementos = 0;


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Linear";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	nElementos = 0;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (nElementos == 0)
	{
		cout << " A lista esta vazia \n";
	}
	else {
		cout << "Elementos: \n";
		for (int n = 0; n < nElementos; n++) {
			cout << lista[n] << endl;
		}
	}
}

void inserirElemento()
{
	int pos;
	int valor;
	if (nElementos < MAX) {
		cout << "Digite o elemento: ";
		cin >> valor;
		pos = posicaoElemento(valor);

		if (pos != -1)
		{
			cout << "Elemento já esta na lista" << endl;
		}
		else
		{
			lista[nElementos] = valor;
			nElementos++;
		}

	}
	else {
		cout << "Lista cheia";
	}

}

void excluirElemento()
{
	// Checa se a lista possui elementos
		if (nElementos == 0) {
			cout << "A lista não possui elementos.\n";
		}
		else { // Caso possua elementos: 
			int valor = 0; // Declaro uma variável chamada "valor" com o valor 0
			cout << "Digite o valor da Lista que deseja Excluir:\n"; //Pede para o usuário digitar o valor na lista que ele quer excluir
			cin >> valor; // O usuário digita o valor que ele excluir, e armazena na variável "valor"
			int pos = posicaoElemento(valor); // Invoco a função posicaoElemento() e passo como parâmetro, o valor digitado pelo usuário, essa função retorna a posição do elemento digitado pelo usuário
			if (pos == -1) { // Se o valor retornado for -1
				cout << "Elemento nao encontrado.\n"; // Mostra para o usuário que o elemento digitado não foi encontrado
			}
			else { // caso o valor NÃO seja -1
				for (int i = 0; i < nElementos - 2; i++) { // Crio um laço de repetição que percorre a lista até o penúltimo elemento
					lista[i] = lista[i + 1]; // Atribuo ao índice atual no laço de repetição, o valor do índice seguinte
				}
				nElementos = nElementos - 1; // Diminuo o numero de elementos em 1, ja que um elemento foi excluído
			}
		}
}

void buscarElemento()
{
	int valor;
	cout << "Digite o elemento que queira buscar: ";
	cin >> valor;
	int pos = posicaoElemento(valor);

	if (pos != -1) {
		cout << "O elemento foi encontrado na posicao" << pos << endl;
	}
	else
	{
		cout << "O elemento digitado nao foi encontrado" << endl;
	}
}

int posicaoElemento(int valor)
{
	for (int i = 0; i < nElementos; i++) {
		if (lista[i] == valor) {
			return i;
		}
	}
	return -1;
}

