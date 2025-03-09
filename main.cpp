#include "Lista.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
	cout << "Menu" << endl;
	cout << "1 - Insere Inicio" << endl;
	cout << "2 - Insere Fim" << endl;
	cout << "3 - Imprimir" << endl;
	cout << "4 - Imprimir fim" << endl;
	cout << "5 - Esta vazio" << endl;		
	cout << "6 - Buscar" << endl;		
	cout << "7 - Retirar" << endl;	
	cout << "8 - Retira Inicio" << endl;		
	cout << "9 - Retira Fim " << endl;	
	cout << "10 - Tamanho da lista" << endl;		
	cout << "11 - Liberar" << endl;		
	cout << "12 - Destruir" << endl;//Destrutor	
	cout << "0 - Sair" << endl;	
	cout << "Escolha:";
}

void print_tamanho(int t){
	cout << "Tamanho da Lista: " << t << endl;	
}

void print_retira(bool x){
	if (x)
		cout << "Dado removido com sucesso da lista!" << endl;
	else	
		cout << "Dado nao encontrado na lista!" << endl;
}

void print_vazia(bool x){
	if (x)
		cout << "Lista vazia!" << endl;
	else	
		cout << "Lista nao vazia!" << endl;
}

void print_busca(bool x){
	if (x)
		cout << "Dado encontrado!" << endl;
	else	
		cout << "Dado nao encontrado!" << endl;
}
int inserirNumero(){
	int x;
	cout << "Digite um numero: ";
	cin >> x;	
	return x;
}
int main(int argc, char** argv) {
	Lista* lista = new Lista();//Inicializa a lista
	
	int op(0);
	do{
		
		menu();
		cin >> op;
		system("cls");
		switch (op)
		{
		case 1:
			lista->insere_inicio(inserirNumero());
			break;
		case 2:
			lista->inserirFim(inserirNumero());
			break;
		case 3:
			cout << "Imprimindo lista" << endl;
			lista->imprime();
			break;
		case 4:
			cout << "Imprimindo lista \n Info: " << endl;
			lista->imprimirFim(lista->getCabeca());
			cout << endl;
			break;
		case 5:
			lista->vazia();
			break;	
		case 6:
			if(lista->busca(inserirNumero())){
				cout << "Numero encontrado" << endl;
			}else{
				cout << "Numero inexistente" << endl;
			}
			break;
		case 7:
			if(lista->retira(inserirNumero())){
					cout << "Numero removido" << endl;
			}else{
					cout << "Numero inexistente" << endl;
				}
			break;
		case 8:
			if(lista->retiraInicio()){
				cout << "Numero removido" << endl;
			}else{
				cout << "Lista vazia" << endl;
			}
			break;
		case 9:
			if(lista->retiraFim()){
				cout << "Numero removido" << endl;
			}else{
				cout << "Lista vazia" << endl;
			}
			break;
		case 10:
			cout<< "Quantidade de itens na lista: " << lista->tamanho() << endl;
			break;
		case 11:	
			lista->libera();
			cout << "Lista liberada, nova lista instanciada" << endl;
			break;
		case 12:	
			lista->~Lista();
			cout << "Lista destruida" << endl;
			break;
		case 0:
			cout << "Saindo!" << endl;
			/* code */
			break;
		default:
			cout << "Digite uma opcao valida" << endl;
			break;
		}
	}while(op != 0);
	
	
	
	
	
	
	
	
	
	
	/*
	//Lista l; //instanciando objeto l conforme a classe Lista de forma est�tica
	Lista* l = new Lista(); //instanciando objeto l conforme a classe Lista de forma din�mica
	
	//l.insere_inicio(23); //abordagem est�tica de acesso a m�todos
	l->insere_inicio(23); //abordagem din�mica de acesso a m�todos
	l->insere_inicio(45);
	l->insere_inicio(56);
	l->insere_inicio(78);
	l->imprime();
	print_tamanho(l->tamanho());
	print_vazia(l->vazia());
	print_busca(l->busca(45));
    print_busca(l->busca(100));
    print_retira(l->retira(78));
    print_retira(l->retira(45));
    l->imprime();
	print_tamanho(l->tamanho());
	l->~Lista();
	system("pause");
	return 0;
	
	*/

}
