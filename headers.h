#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string>

using namespace std;


//constante que contem os naipes
enum Naipe{P, E, C, O};

//constante que contem tipos de mao
enum TipoMao{RSF, SF, FK, FH, F, S, TK, TP, OP, HC};

class Carta{
    private:
        Naipe naipe;
        int valor;
        
    public:
        //construtores
        Carta(Naipe, int);
        Carta();

        //metodos basicos
        Naipe getNaipe();
        void setNaipe(Naipe);
        int getValor();
        void setValor(int);
};

class Jogador{
    private:
        string nome;
        int dinheiro;
        Carta mao[5];
        int contCartas = 0;
        int forcaMao;
        int aposta;
        int pingo;
        string tipoMao;

        //metodos para identicar forca da mao
        bool eRoyaStraightlFlush();
        bool eStraightFlush();
        bool eFourOfKind();
        bool eFullHouse();
        bool eFlush();
        bool eStraight();
        bool eThreeKind();
        bool eTwoPairs();
        bool eOnePair();
        bool eHighCard();
        
    public:
        //construtores
        Jogador(string, int);
        Jogador();

        //metodos basicos
        string getNome();
        void setNome(string);
        int getDinheiro();
        void setDinheiro(int);
        int getAposta();
        void setAposta(int);
        int getPingo();
        void setPingo(int);
        TipoMao getMao();
        void setCartasMao(Carta);
        void setforcaMao(TipoMao);
        int getforcaMao();
        void ordenaMao();
        int getcontCartas();
        void lavaMao();
        void setTipoMao(TipoMao);
        string getTipoMao();
};

class Partida{
    private:
        int tamanho;
        static const int MAXTAM = 10;
        Jogador _jogadores[MAXTAM];
        int numJogadores = 0;
        int numRodadas = 0;
        int id = 0;
        int contador = 0;
        int montante = 0;

    public:
        Partida(int);
        void addJogadorCarta(string, int, Naipe);
        void InsereInicio(Jogador);
        string vencedorRodada(int);
        Naipe transNaipe(string);
        int transValor(string);
        Naipe voltaNaipe(string);
        void addJogadorDinheiro(int, int, int);
        void setnumJogadores(int);
        int getnumJogadores();
        void mudaDinheiro(int, int);
        int getDinheiroJogadores(int);
        string getNomeJogadores(int);
        int balancoJogador(int);
        int getMontante();
        string getTipoMaoJogadores(int);
        int getID();
        void ordenaJogadores(int);
        int getPingoRodada();
};

#endif