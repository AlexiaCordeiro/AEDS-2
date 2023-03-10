package ArvoreBinaria;

import Item.Item;
import MSGerro.MSGerro;

public class ArvoreBinaria  {

    private static class No {
        Item reg;
        No esq, dir;
    }
    private No raiz;
    private boolean vazio;

    public ArvoreBinaria(){
        this.raiz = null;
        vazio = true;
    }
    private No insere(Item reg, No p) throws MSGerro {
        //percorrer até achar um ponteiro nulo ou achar um item igual ao item a ser inserido
        if(p != null){
            if(reg.compara(p.reg) > 0){
                //pular para direita e chamar recursivamente pesquisa
                System.out.println("Salto para a direita");
                p.dir = insere(reg, p.dir);
            }

            //esquerda --> menor que
            else if(reg.compara(p.reg) > 0){
                System.out.println("Salto para a esquerda");
                p.esq = insere(reg, p.esq);
            }
            //igual
            else{
                //mensagem de erro
                throw new MSGerro("OBJETO JÁ EXISTENTE");
            }
        }
        //inserir
        //criar no
        p = new No();
        //adicionar item
        p.reg = reg;
        //configuarar filhos
        p.esq = null; p.dir = null;

        return p;
    }

    private Item pesquisa(Item reg, No p){
        if(p != null){
            //direita --> maior que
            if(reg.compara(p.reg) > 0){
                //pular para direita e chamar recursivamente pesquisa
                System.out.println("Salto para a direita");
                return pesquisa(reg, p.dir);
            }

            //esquerda --> menor que
            else if(reg.compara(p.reg) > 0){
                System.out.println("Salto para a esquerda");
                return pesquisa(reg, p.esq);
            }
            //igual
            else{
                //achou o item
                return p.reg;
            }
        }
        return null;
    }

    public void adminInsere(Item r) throws MSGerro {

        //primeiro item
        if(vazio){
            this.raiz = new No();
            //adicionar item
            raiz.reg = r;
            //configuarar filhos
            raiz.esq = null; raiz.dir = null;
        }
        //a partir do segundo item
        else{
            raiz = this.insere(r, raiz);
        }

    }

    public boolean adminPesquisa(Item r) throws MSGerro {
        //pesquisa em uma arvore vazia
        if(vazio){
            throw new MSGerro("ARVORE VAZIA");
        }
        //pesquisa em uma arvore com pelo menos um item
        else{
            if(pesquisa(r, raiz) != null){
                return true;
            }
            else{
                return false;
            }
        }
    }

}
