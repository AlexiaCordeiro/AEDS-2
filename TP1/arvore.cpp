#include <iostream>
#include <stdlib.h>
using namespace std;

struct No {
    int item;
    No *esq;
    No *dir;
};

class arvore{
    private: No *root;
    int numComparisons;

    public: arvore() {
        root = NULL;
        numComparisons = 0;
    };

    public: void inserir(int value) {
        No *n = new No(); //cria um novo nó quando se insere o valor
        n->item = value; // o nó recebe o valor 
        n->dir = NULL;
        n->esq = NULL;

        if(root == NULL) { //se vazia, a raiz vira o valor recentemente adicionado
            root = n;
        }else{
            No *recent = root; //se não, o no mais novo recebe  a raiz
            No *old;

            while (true) { 
            old = recent; // valor antigo recebe o mais recente
            if (value <= recent->item) { // se o item do valor mais recente for maior que o valor inserido
                recent = recent->esq; // o item recente se move para a esquerda
                if (recent == NULL) {
                    old->esq = n;
                    return;
                }
                numComparisons++;
            } else { // se for menor
                recent = recent->dir; // o valor recente vai pra direita
                if (recent == NULL) {
                    old->dir = n;
                    return;
                }
                numComparisons++;
            }
                
            }
        } //fim do else

    }// fim do inserir

    public: No *search(int key){
        
        if(root == NULL){
            return NULL;
        }
        No *recent = root; // cria um nó recente que recebe a raiz

        while(recent->item!=key){ // enquanto o item recente não for igual a chave o loop não termina
            
            if(key < recent -> item){//se a chavve for menor que o item, continua a procurar para a esquerda
                recent = recent-> esq;
            }else{ //se a chavve for maior que o item, continua a procurar para a direita
                recent = recent->dir;

            }   
            if(recent == NULL){
                return NULL;
            }
            
        } // fim do while
       
        return recent;
    }// fim do No search 

    int get_num_comparisons() {
        return numComparisons;
    }
    

};