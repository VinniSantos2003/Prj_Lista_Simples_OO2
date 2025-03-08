#include "no_dado.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


class Lista{
	
	private:
		no_dado* cabeca; 
		no_dado* ultimoNoDado;
		int qtd; 
	
	public:
		Lista(); 
		~Lista(); 
		//ALUNO
		no_dado* getCabeca();
		bool retiraInicio();
		void inserirFim(int i);
		void imprimirFim(no_dado* aux);
		bool retiraFim();
		//IRINEU
		void insere_inicio(int i); 
		void imprime(); 
		bool vazia(); 
		bool busca(int i); 
		bool retira(int i); 
		int tamanho(); 
		void libera(); 	
	
	private:
		bool isEmpty(no_dado* l); 
	
};
