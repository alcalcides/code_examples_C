/**
* Implementação de lista encadeada simples 
* SEM head
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elto Elto;
typedef struct list List;
//typedef struct content Content;

struct elto {
    int content;
    Elto *next;
};


struct list {
    int numEltos;
    Elto *firstElto;
};

Elto* newElto(int content);
void displayElto(Elto *elto);
Elto* delElto(Elto *elto);
List* newList();
bool isEmptyList(List *lista);
bool insertEltoTopList(List *lista, Elto *pioneiro);
bool insertElto(List *lista, Elto* anterior, Elto* calouro);
void displayList(List *lista);
bool clearList(List *lista);
bool delEltoList(List *lista, Elto *antAlvo);
bool delTop(List *lista);
bool delValue(List *lista, int value);
List* delList (List *lista);
Elto* seek(List *lista, unsigned int pos);
Elto* lookFor(List *lista, int value);
Elto* lookForAnt(List *lista, int value);
bool belong(List* lista, int value);

/**
 * Cria um novo nó.
 * 
 * @param content é o conteúdo da nova célula
 * @return ponteiro para a célula criada
*/
Elto* newElto(int content){
    Elto *node = (Elto*)malloc(1*sizeof(Elto));
    if(node){
        node->content = content;
        node->next = NULL;
    }
    return node;
}

/**
 * Exibe os campos de um elemento.
 * Se o elemento não existir, exibe mensagem de erro.
 * 
 * @param elto é o ponteiro para a célula.
*/
void displayElto(Elto *elto){
    if(elto){
        printf("Alocado em: %p\n", elto);
        printf("Conteudo: %d\n", elto->content);
        printf("Proximo elemento: %p\n\n", elto->next);
    }
    else{
        printf("Elemento nulo\n");
    }
}

/**
 * Desaloca uma célula.
 * 
 * @param elto é o ponteiro para a célula a ser desalocada.
 * @return NULL a ser atribuído, sugestivamente, ao ponteiro.
*/
Elto* delElto(Elto *elto){    
    free(elto);
    return NULL;
}

/**
 * Cria uma lista vazia.
 * 
 * @return o ponteiro para a lista criada.
*/
List* newList(){
    List *lista = (List*)malloc(1*sizeof(List));
    lista->numEltos = 0;
    lista->firstElto = NULL;
    return lista;
}

/**
 * Indica se a lista está vazia.
 * 
 * @param lista é o ponteiro da lista.
 * @return true se a lista estiver vazia e falso caso contrário.
*/
bool isEmptyList(List* lista){
    bool isEmpty;
    isEmpty = lista->numEltos == 0 ? true : false;
    return isEmpty;
}


/**
 * Insere um célula no topo da lista.
 * 
 * @param lista é ponteiro para uma lista.
 * @param pioneiro é ponteiro para a primeira nova célula.
 * @return true se houver inserção e false caso contrário.
*/
bool insertEltoTopList(List *lista, Elto *pioneiro){
    bool inserido = false;
    pioneiro->next = lista->firstElto;   
    lista->firstElto = pioneiro;
    lista->numEltos++;
    inserido = true;
    return inserido;
}

/**
 * Insere, na lista não vazia, uma nova célula após 
 * a célula indicada como sua anterior.
 * 
 * @param lista é ponteiro para a lista não vazia.
 * @param anterior é o ponteiro para a célula anterior a nova célula.
 * @param calouro é o ponteiro para a nova célula.
 * @return true se houve a inserção e false caso contrário.
*/
bool insertElto(List *lista, Elto* anterior, Elto* calouro){
    bool inseriu = false;
    if(!isEmptyList(lista)){
        calouro->next = anterior->next;
        anterior->next = calouro;
        lista->numEltos++;
        inseriu = true;
    }
    return inseriu;
}

/**
 * Mostra todos os elementos de uma lista.
 * Se a lista estiver vazia, uma mensagem de erro é exibida.
 * 
 * @param lista é o ponteiro para a lista.
*/
void displayList(List *lista){
    int i;
    Elto *alvo = lista->firstElto;
    if(isEmptyList(lista)){
        printf("Lista %p vazia\n", lista);
    }
    else{
        printf("Lista tem %d elementos:\n", lista->numEltos);
        for(i = 0; i < lista->numEltos; i++){
            displayElto(alvo);
            alvo = alvo->next;
        }
    }
}

/**
 * Exclui todos os seus elementos da lista.
 * 
 * @param lista é o ponteiro para a lista.
 * @return true após esvaziar a lista.
*/
bool clearList(List *lista){
    while(!isEmptyList(lista)){
        delTop(lista);
    }
    return true;
}

/**
 * Remove o elemento alvo.
 * 
 * @param list é ponteiro para uma lista com pelo menos dois elementos.
 * @param antAlvo é o ponteiro para o elemento anterior ao elemento a ser excluído.
 * @return true se o elemento foi excluído da lista e false caso contrário.
*/
bool delEltoList(List *lista, Elto *antAlvo){
    bool removeu = false;
    if(lista->numEltos > 1){
        Elto *temp = antAlvo->next->next;
        delElto(antAlvo->next);
        antAlvo->next = temp;
        lista->numEltos--;
        removeu = true;
    }
    return removeu;
}

/**
 * Exclui o primeiro elemento de uma lista não vazia.
 * 
 * @param lista é ponteiro para a lista.
 * @return true se houve a exclusão ou false caso contrário.
*/
bool delTop(List *lista){
    bool removeu = false;
    if(!isEmptyList(lista)){
        Elto *temp = lista->firstElto->next;
        delElto(lista->firstElto);
        lista->firstElto = temp;
        lista->numEltos--;
        removeu = true;
    }
    return removeu;
}


/**
 * Exclui da lista o primeiro elemento encontrado com o determinado conteúdo.
 * 
 * @param list é o ponteiro para uma lista.
 * @param value é o valor a ser removido da lista.
 * @return true se houve a remoção ou false caso o valor procurado não esteja presente na lista.
*/
bool delValue(List *lista, int value){
    bool removeu = false;
    Elto* antAlvo;
    if(!isEmptyList(lista)){
        if(lista->firstElto->content == value){
            removeu = delTop(lista);
        }
        else{
            antAlvo = lookForAnt(lista, value);
            if(antAlvo){
                removeu = delEltoList(lista, antAlvo);
            }
        }
    }    
    return removeu;
}

/**
 * Desaloca todos os seus elementos da primeira posição até a última e, 
 * por fim, desaloca a lista.
 * 
 * @param lista é o ponteiro para uma lista.
 * @return NULL 
*/
List* delList (List *lista){
    while(!isEmptyList(lista)){
        delTop(lista);
    }    
    free(lista);
    return NULL;
}

/**
 * Busca o elemento na posição pos.
 * 
 * @param lista é o ponteiro para uma lista 
 * @param pos é a posição do elemento na lista, de zero a [lista->numElto - 1]
 * @return o ponteiro da célula que está na posição pos da lista ou
 * NULL caso a lista seja menor do que pos sugere
*/
Elto* seek(List *lista, unsigned int pos){
    int i;
    Elto *alvo = lista->firstElto;
    if(pos >= lista->numEltos)
        alvo = NULL;
    else{
        for(i = 0; i < pos; i++){
            alvo = alvo->next;
        }               
    }
    return alvo;
}

/**
 * Busca o primeiro elemento com o determinado conteúdo.
 * 
 * @param lista é o ponteiro para uma lista.
 * @param value é o valor procurado. 
 * @return ponteiro para o nó encontrado ou
 * NULL para indicar que a lista não contém o valor pesquisado.
*/
Elto* lookFor(List *lista, int value){
    Elto *temp = lista->firstElto;
    if(!isEmptyList(lista)){
        while(temp && temp->content != value){
            temp = temp->next;
        }
    }
    return temp;
}

/**
 * Busca o elemento anterior ao que tem um determinado conteúdo.
 * Se o elemento encontrado for o primeiro nó, o anterior é considerado NULL.
 * O sucesso ocorre se houver o valor na lista em qualquer célula que seja a primeira.
 * 
 * @param lista é o ponteiro para uma lista.
 * @param value é um valor procurado na lista.
 * @return ponteiro para o nó anterior ao encontrado ou
 * NULL caso não esteja presente na lista ou 
 * NULL caso o valor procurado está no primeiro elemento da lista.
*/
Elto* lookForAnt(List *lista, int value){
    Elto *anterior = lista->firstElto;
    if(!isEmptyList(lista)){
        if(lista->numEltos == 1){
            if(anterior->content != value)
                anterior = NULL;
        }
        else{
            //o alvo pode ser o elto de índice 0
            if(anterior->content == value){
                anterior = NULL;
            }
            //ou ser o elto de índice 1 ou maior
            else{
                while(anterior->next && anterior->next->content != value){
                    anterior = anterior->next;
                }
                //o alvo pode não estar na lista
                if(!anterior->next){
                    anterior = NULL;
                }
            }
        }
    }
    return anterior;
}

/**
 * Responde pela presença de determinado conteúdo na lista.
 * 
 * @param lista é o ponteiro para uma lista 
 * @param value é um valor procurado.
 * @return true se a lista contém o valor procura ou false caso contrário.
*/
bool belong(List* lista, int value){
    bool existe;
    Elto* antAlvo = lookFor(lista, value);
    existe = antAlvo ? true : false;
    return existe;
}