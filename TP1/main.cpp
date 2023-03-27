#include <iostream>
#include "arvore.cpp"
#include <cstdlib>
#include <random>
#include <chrono>

using namespace std;



int main(){

    arvore ordenado[9];
    arvore desordenado[9];

    int init = 0;
    for(int j = 0; j < 9; j++){ //iterando pelas 0 arvores
        for(int i = 1; i <= init+1000; i++){//colocando os valores até chegar ao valor init+1000
            auto start = chrono::high_resolution_clock::now(); //inicio da contagem de tempo
            ordenado[j].inserir(i); //inserção dos valores em uma árvore i
            auto stop = chrono::high_resolution_clock::now(); //fim da contagem de tempo

            /* if( i % 1000 == 0 ){ //calculo de comparações e de tempos de 1000 em 1000 valores
                cout << "Número de comparações para adição para o valor " << i<< ": " << ordenado[j].get_num_comparisons() << endl;
                cout << "O tempo de adição é de: " << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << " ns\n" << endl;
            } */
        }
        init+=1000;
        
    }

    for(int j = 0; j < 9; j++){//iterando pelas 0 arvores
        
        auto start1 = chrono::high_resolution_clock::now();//inicio da contagem de tempo
        No* result1 = ordenado[j].search(9001); //procuando um valor inexistente na árvore atual
        auto stop1 = chrono::high_resolution_clock::now();//fim da contagem de tempo
              
        
        if(result1 == NULL){
            cout << "Elemento " << 9001 << " não foi encontrado na árvore ordenada "<< j+1 <<endl;
            cout << "Número de comparações: " << ordenado[j].get_num_comparisons() << endl;
            cout << "O tempo de pesquisa é de: " << chrono::duration_cast<chrono::nanoseconds>(stop1 - start1).count() << " ns\n" << endl;
            cout << "--------------------------------" << endl;
        }else{
            cout << "Elemento " << 9001 << " foi encontrado na árvore ordenada "<< j << endl;
            cout << "--------------------------------" << endl;
        }
        
    } 

    int init2 = 0;
    for(int j = 0; j < 9; j++){
    
        srand(time(NULL));
        int random1 = init2 + (rand() % (init2+1000) - init2 + 1);

        for(int i = random1; i <= init2; i++){
            auto start1 = chrono::high_resolution_clock::now(); //inicio da contagem de tempo
            desordenado[j].inserir(i); //procuando um valor inexistente na árvore atual
            auto stop1 = chrono::high_resolution_clock::now(); //fim da contagem de tempo

            /* if( i % 1000 == 0 ){ //calculo de comparações e de tempos de 1000 em 1000 valores
                cout << "Número de comparações para adição do valor NÃO ORDENADO " << i<< ": " << ordenado[j].get_num_comparisons() << endl;
                cout << "O tempo de adição é de  NÃO ORDENADO: " << chrono::duration_cast<chrono::nanoseconds>(stop1 - start1).count() << " ns\n" << endl;
            } */
        }

        init2+=1000;
    }
    for(int j = 0; j < 9; j++){
        auto start2 = chrono::high_resolution_clock::now();//inicio da contagem de tempo
        No* result2 = desordenado[j].search(9001);//procuando um valor inexistente na árvore atual
        auto stop2 = chrono::high_resolution_clock::now();//fim da contagem de tempo

        if(result2 == NULL){
            cout << "\nElemento " << 9001<< " não foi encontrada na árvore não ordenada " << j+1 << endl;
            cout << "Comparação: " << desordenado[j].get_num_comparisons() << std::endl; 
            cout << "O tempo de pesquisa é de: " << chrono::duration_cast<chrono::nanoseconds>(stop2 - start2).count() << " ns" << std::endl;
            cout << "--------------------------------" << endl;
        }else{
            cout << "Elemento " << 9001 << " foi encontrado na árvore não ordenada "<< j << endl;
            cout << "--------------------------------" << endl;
        }
        
    }
   
}

