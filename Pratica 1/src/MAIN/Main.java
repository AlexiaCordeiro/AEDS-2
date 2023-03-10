package MAIN;
import ArvoreBinaria.ArvoreBinaria;
import Item.Item;
import MSGerro.MSGerro;

import java.util.*;

public class Main {

    public static void main(String[]args){
        //criar objs
        ArvoreBinaria arvore = new ArvoreBinaria();
        Item it;

        int[] valores = {8, 10, 4, 9, 11, 2, 6, 3, 5, 1};

        for(int i = 0; i<10; i++){
            it = new Item(valores[i]);
            System.out.println(it.getChave());

            try{
                arvore.adminInsere(it);
            }
            catch (MSGerro e){
                System.out.println(e.getMessage());
                break;
            }
        }

        System.out.println("==================");

        for(int i = 0; i<10; i++){
            it = new Item(valores[i]);
            try{
                System.out.println(arvore.adminPesquisa(it));
            }
            catch (MSGerro e){
                System.out.println(e.getMessage());
                break;
            }
        }



    }
}
