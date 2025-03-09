#include "Lista.h"

Lista::Lista(){ 
	cabeca = 0; 
	qtd = 0;
	ultimoNoDado = 0;
	
} 

Lista::~Lista(){ 
	libera();
}

no_dado* Lista::getCabeca(){ 
	//Criado para acessar o atributo privado cabeca fazer a funcao imprimirFim funcionar
	return cabeca;
}

void Lista::insere_inicio(int i){ 

	no_dado* novo = new no_dado(i, cabeca);	

    cabeca = novo; 
   	if(qtd==0){
		ultimoNoDado=novo;
	}
	qtd++; 

}

void Lista::inserirFim(int i){ // OK
	if(qtd==0){
		insere_inicio(i);
		return;
	}
	
	no_dado* aux = cabeca;
	while(aux->prox!=NULL){
		aux = aux->prox;
	}
	no_dado * novo = new no_dado(i,NULL);
	aux->prox = novo;
	ultimoNoDado = novo;		
	qtd++;
}

void Lista::imprime(){ 
	if(!isEmpty(cabeca)){
		cout << "Info: ";
		for (no_dado* p = cabeca; p != NULL; p = p->prox)
			cout << p->info << " - ";			
		cout << endl;	
	} else
		cout << "Lista eh vazia! \n";
}

void Lista::imprimirFim(no_dado * aux){
	//Recursividade
	if(aux == NULL){
		cout << "Lista vazia" << endl;
	}

	if(!isEmpty(aux)){
		imprimirFim(aux->prox);
		cout << aux->info << " - ";	
	}
	
}

bool Lista::vazia(){ 
	return isEmpty(cabeca);
}

bool Lista::busca(int i){ 
	
	for (no_dado* p = cabeca; p != NULL; p = p->prox)
		if (p->info == i){
			//cout << "Endereco do dado encontrado: " <<static_cast<void*>(p) << endl;
			return true; 
		}
			
	
	return false; 		
}

bool Lista::retira(int i){ 
	no_dado* ant = NULL;
 	no_dado* p = cabeca; 

 	while (p != NULL && p->info != i) {
 		ant = p;
 		p = p->prox;
 	}
 	
	if (p == NULL){
		return false; 
	}
 		
 	if (ant == NULL) { 
 		cabeca = p->prox;
 	} else { 
 		ant->prox = p->prox;
 	}

 	free(p); 
 	qtd--; 
 	return true;
}

bool Lista::retiraInicio(){
	if(isEmpty(cabeca)){
		return false;
	}else{
		no_dado* aux = cabeca->prox;
		free(cabeca);
		cabeca = aux;
		qtd--;
		return true;
	}
}

bool Lista::retiraFim(){
	if(isEmpty(cabeca)){
		return false;
	}else{
		no_dado* aux = cabeca;
		while(aux->prox->prox!=NULL){
			aux= aux->prox;
		}
		free(aux->prox);
		aux->prox = NULL;
		ultimoNoDado = aux;
		qtd--;
		return true;
	}

}
int Lista::tamanho(){ 
	return qtd;
}

void Lista::libera(){ 
    no_dado* p = cabeca;
     while (p != NULL) {
         no_dado* t = p->prox; 
         free(p); 
         p = t; 
     }
     // Redefinindo os valores dos atributos diretamente
     cabeca = NULL;
     qtd = 0;
     ultimoNoDado = NULL;
}

bool Lista::isEmpty(no_dado* l){ 
	return l==0;
}

