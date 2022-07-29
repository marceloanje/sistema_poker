#include "headers.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

int main(){

    ifstream arq;
    
    arq.open("entrada.txt");  //abre o arquivos com dados
    if(!arq){
        cout << "Arquivo nao existente" << endl;
    }


    int n = 0, di = 0;
    
    stringstream str1;
    string linha1;
    getline(arq, linha1);
    str1 << linha1;
    str1 >> n >> di;    //realiza a leitura da primeira linha do arquivo

    string filename("saida.txt");  //cria o arquivo aonde ira constar a saida
    fstream output_fstream;
    output_fstream.open(filename, std::ios_base::out);
    if(!output_fstream.is_open()){
        cout << "Falha ao abrir" << filename << endl;
    }

    int v = 0;
    int cont = 0;
    Partida *g = new Partida(v);    //inicia uma partida global para armazenar o dinheiro dos jogadores a cada rodada
    
    for(int i = 0; i < n; i++){     //for para cada rodada n

        int j = 0, p = 0;
        
        stringstream str2;
        string linha2;
        getline(arq, linha2);
        str2 << linha2;
        str2 >> j >> p;     //realiza a leitura da segunda linha
        
        if(cont == 0){
            
            g->setnumJogadores(j);      //set para armazenar a quantidade de jogadores global
        }
        
        Partida *a = new Partida(j);    //inicia uma partida para cada rodada

        for(int k = 0; k < j; k++){
            
            string nome;
            int aposta = 0;
            string mao1, mao2, mao3, mao4, mao5;
            
            stringstream str3;
            string linha3;
            getline(arq, linha3);
            str3 << linha3;
            str3 >> nome >> aposta >> mao1 >> mao2 >> mao3 >> mao4 >> mao5;     //realiza a leitura dos atributos de cada jogador
            
            a->addJogadorCarta(nome, a->transValor(mao1), a->transNaipe(mao1));
            a->addJogadorCarta(nome, a->transValor(mao2), a->transNaipe(mao2));
            a->addJogadorCarta(nome, a->transValor(mao3), a->transNaipe(mao3));
            a->addJogadorCarta(nome, a->transValor(mao4), a->transNaipe(mao4));
            a->addJogadorCarta(nome, a->transValor(mao5), a->transNaipe(mao5));
            a->addJogadorDinheiro(aposta, p, di);
            
            if(cont == 0){
                    
                g->addJogadorCarta(nome, g->transValor(mao1), g->transNaipe(mao1));     //so armazena os jogadores na partida global
                g->addJogadorCarta(nome, g->transValor(mao2), g->transNaipe(mao2));     //na primeira rodada
                g->addJogadorCarta(nome, g->transValor(mao3), g->transNaipe(mao3));
                g->addJogadorCarta(nome, g->transValor(mao4), g->transNaipe(mao4));
                g->addJogadorCarta(nome, g->transValor(mao5), g->transNaipe(mao5));
                g->addJogadorDinheiro(aposta, p, di);
            }
        }
        
        a->vencedorRodada(g->getnumJogadores());        //descobre o jogador vencedor de cada rodada

        output_fstream << 1 << " " << a->getMontante() << " " << a->getTipoMaoJogadores(a->getID()) << endl;    //impressao da primeira
        output_fstream << a->getNomeJogadores(a->getID()) << endl;                                              //parte da saida
        
        cont++;
        
        for(int i = 0; i < g->getnumJogadores(); i++){                  //metododo para modificar o dinheiro dos
            for(int z = 0; z < a->getnumJogadores(); z++){              //jogadores globais a cada rodada
                
                if(g->getNomeJogadores(i) == a->getNomeJogadores(z)){
                    
                    g->mudaDinheiro(g->getDinheiroJogadores(i) + a->balancoJogador(z) + a->getPingoRodada(), i);
                }    
            }

            g->mudaDinheiro(g->getDinheiroJogadores(i) - a->getPingoRodada() , i); 
        }
    }

    output_fstream << "###" << endl;

    g->ordenaJogadores(g->getnumJogadores()); 

    for(int i = 0; i < g->getnumJogadores(); i++){
        
        output_fstream << g->getNomeJogadores(i) << " " << g->getDinheiroJogadores(i) << endl;      //segunda parte da saida
    }
    
    return 0;
}