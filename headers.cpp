#include "headers.h"
#include <iostream>
#include <string>

using namespace std;


//*******************CARTA*******************

//contrutor parametrico - inicia a classe carta com valores
//entrada: naipe, valor
//saida:
Carta::Carta(Naipe _naipe, int _valor){

    //inicializa os componentes
    this->naipe = _naipe;
    this->valor = _valor;
}

//contrutor default - inicia a classe carta sem argumentos
//entrada:
//saida:
Carta::Carta(){}

//metodo get para naipe - retorna o valor de naipe
//entrada:
//saida: naipe
Naipe Carta::getNaipe(){

    return (naipe);
}

//metodo set para naipe - altera o valor de naipe
//entrada: naipe
//saida:
void Carta::setNaipe(Naipe _naipe){

    naipe = _naipe;
}

//metodo get para valor - retorna o valor de valor
//entrada:
//saida: valor
int Carta::getValor(){

    return (valor);
}

//metodo set para valor - altera o valor de valor
//entrada: valor
//saida:
void Carta::setValor(int _valor){

    valor = _valor;
}


//*******************JOGADOR*******************

//contrutor parametrico - inicia a classe jogador com valores
//entrada: naipe, valor
//saida:
Jogador::Jogador(string _nome, int _dinheiro){

    //inicializa os componentes
    this->nome = _nome;
    this->dinheiro = _dinheiro;
}

//contrutor default - inicia a classe carta sem argumentos
//entrada:
//saida:
Jogador::Jogador(){}

//metodo get para nome - retorna o valor de nome
//entrada:
//saida: nome
string Jogador::getNome(){

    return (nome);
}

//metodo get para nome - altera o valor de nome
//entrada: nome
//saida:
void Jogador::setNome(string _nome){

    nome = _nome;
}

//metodo get para dinheiro - retorna o valor de dinheiro
//entrada:
//saida: dinheiro
int Jogador::getDinheiro(){

    return (dinheiro);
}

//metodo get para dinheiro - altera o valor de dinheiro
//entrada: dinheiro
//saida:
void Jogador::setDinheiro(int _dinheiro){

    dinheiro = _dinheiro;
}

int Jogador::getAposta(){

	return (aposta);
}

void Jogador::setAposta(int _aposta){

	aposta = _aposta;
}

int Jogador::getPingo(){

	return (pingo);
}

void Jogador::setPingo(int _pingo){

	pingo = _pingo;
}

//metodo set para mao - insere carta na mao
//entrada: carta
//saida:
void Jogador::setCartasMao(Carta _carta){

	mao[contCartas] = _carta;
	contCartas++;
}

bool Jogador::eRoyaStraightlFlush(){

	bool flush, royal;

	ordenaMao();

	flush = eFlush();

	if(mao[0].getValor() == 1 && mao[1].getValor() == 10 && mao[2].getValor() == 11 && mao[3].getValor() == 12 && mao[4].getValor() == 13){
		royal = true;
	}
	else{
	    royal = false;
	}

	if(flush == true && royal == true)
		return true;
	else
		return false;
}

bool Jogador::eStraightFlush(){

	bool straight, flush;

	straight = eStraight();

	flush = eFlush();

	if(straight == true && flush == true)
		return true;
	else
		return false;

}

bool Jogador::eFourOfKind(){

	int contador = 0;
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){

			if(mao[i].getValor() == mao[j].getValor()){
				contador++;
			}
		}
	}

	if(contador == 17){
		return true;
	}
	else{
		return false;
	}
}

bool Jogador::eFullHouse(){

	int contador = 0;
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){

			if(mao[i].getValor() == mao[j].getValor()){
				contador++;
			}
		}
	}

	if(contador == 13){
		return true;
	}
	else{
		return false;
	}
}

bool Jogador::eFlush(){

	bool flush;

	for(int i = 0; i < 4; i++)
		if(mao[i].getNaipe() == mao[i+1].getNaipe())
			flush = true;
		else
		{
			flush = false;
			break;
		}

	return flush;
}

bool Jogador::eStraight(){

	bool straight;

	ordenaMao();

	for(int i = 0; i < 4; i++)
		if((mao[i].getValor()) == mao[i+1].getValor()-1)
			straight = true;
		else
		{
			straight = false;
			break;
		}

	return straight;
}

bool Jogador::eThreeKind(){

	int contador = 0;
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){

			if(mao[i].getValor() == mao[j].getValor()){
				contador++;
			}
		}
	}

	if(contador == 11){
		return true;
	}
	else{
		return false;
	}
}

bool Jogador::eTwoPairs(){

	int contador = 0;
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){

			if(mao[i].getValor() == mao[j].getValor()){
				contador++;
			}
		}
	}

	if(contador == 9){
		return true;
	}
	else{
		return false;
	}	
}

bool Jogador::eOnePair(){

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){

			if((mao[i].getValor() == mao[j].getValor()) && (mao[i].getNaipe() != mao[j].getNaipe())){
				return true;
			}
		}
	}

	return false;
}

TipoMao Jogador::getMao(){

	if(eRoyaStraightlFlush() == true)
		return RSF;
	else if(eStraightFlush() == true)
		return SF;
	else if(eFourOfKind() == true)
		return FK;
	else if(eFullHouse() == true)
		return FH;
	else if(eFlush() == true)
		return F;
	else if(eStraight() == true)
		return S;
	else if(eThreeKind() == true)
		return TK;
	else if(eTwoPairs() == true)
		return TP;
	else if(eOnePair() == true)
		return OP;
	else
		return HC;
}

void Jogador::setforcaMao(TipoMao m){

	if(m == RSF)
		forcaMao = 9;
	
	if(m == SF)
		forcaMao = 8;

	if(m == FK)
		forcaMao = 7;

	if(m == FH)
		forcaMao = 6;

	if(m == F)
		forcaMao = 5;

	if(m == S)
		forcaMao = 4;

	if(m == TK)
		forcaMao = 3;

	if(m == TP)
		forcaMao = 2;

	if(m == OP)
		forcaMao = 1;

	if(m == HC)
		forcaMao = 0;
}

int Jogador::getforcaMao(){

	return forcaMao;
}

void Jogador::ordenaMao(){
	
	int i, j;

	Carta aux;
    
    for(i = 0; i < 5-1; i++){
        
        for(j = 1; j < 5-i; j++){
            
            if(mao[j].getValor() < mao[j-1].getValor()){
                
                aux = mao[j-1];
                mao[j-1] = mao[j];
                mao[j] = aux;
            }
        }
    }
}

int Jogador::getcontCartas(){
    
    return contCartas;
}

void Jogador::lavaMao(){
    
    mao[0] = Carta();
    mao[1] = Carta();
    mao[2] = Carta();
    mao[3] = Carta();
    mao[4] = Carta();
}

void Jogador::setTipoMao(TipoMao _tipoMao){

	if(_tipoMao == RSF)
		tipoMao = "RSF";
	
	if(_tipoMao == SF)
		tipoMao = "SF";

	if(_tipoMao == FK)
		tipoMao = "FK";

	if(_tipoMao == FH)
		tipoMao = "FH";

	if(_tipoMao == F)
		tipoMao = "F";

	if(_tipoMao == S)
		tipoMao = "S";

	if(_tipoMao == TK)
		tipoMao = "TK";

	if(_tipoMao == TP)
		tipoMao = "TP";

	if(_tipoMao == OP)
		tipoMao = "OP";

	if(_tipoMao == HC)
		tipoMao = "HC";

}

string Jogador::getTipoMao(){

	return tipoMao;
}


//*******************PARTIDA*******************

Partida::Partida(int _numJogadores){

    this->numJogadores = _numJogadores;
}

void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, Naipe naipe){

    if(_jogadores[0].getNome() == nomeJogador){
        _jogadores[0].setCartasMao(Carta(naipe, numero_pontos_carta));
		contador++;

		if(contador == 4){
            _jogadores[0].setforcaMao(_jogadores[0].getMao());
			_jogadores[0].setTipoMao(_jogadores[0].getMao());
			contador = 0;
        }
    }
    else{
        Jogador new_jogador = Jogador();
        new_jogador.setNome(nomeJogador);
        new_jogador.setCartasMao(Carta(naipe, numero_pontos_carta));
        InsereInicio(new_jogador);
    };
}

void Partida::InsereInicio(Jogador _jogador){

    int i;
    if (tamanho == MAXTAM)
    throw "ERRO: Lista cheia!";
    tamanho++;
    for(i=tamanho;i>0;i--)
    _jogadores[i] = _jogadores[i-1];
    _jogadores[0] = _jogador;
}

string Partida::vencedorRodada(int numGlobal){

	int valor = 0;
	int registrador;
	int montanteRodada = 0;

	for(int i = 0; i < numJogadores; i++){

		if(_jogadores[i].getforcaMao() > valor){

			valor = _jogadores[i].getforcaMao();
			registrador = i;
		}
	}

	id = registrador;
	
	for(int i = 0; i < numJogadores; i++){
	    
	    montanteRodada = montanteRodada + _jogadores[i].getAposta();
	    _jogadores[i].setDinheiro(_jogadores[i].getDinheiro() - _jogadores[i].getAposta() - _jogadores[i].getPingo());
	}
	
	montante = montanteRodada + (numGlobal*_jogadores[0].getPingo());
	_jogadores[registrador].setDinheiro(montanteRodada + _jogadores[registrador].getDinheiro());

	return (_jogadores[registrador].getNome());
}

Naipe Partida::transNaipe(string mao){
    
    Naipe naipe;
    string temp;
    
    if(mao.length() == 3){
        
        temp = mao[2];
        
        naipe = voltaNaipe(temp);
    } 
    else{
        
        temp = mao[1];
        
        naipe = voltaNaipe(temp);
    }
    
    return naipe;
}

int Partida::transValor(string mao){
    
    int valor;
    
    if(mao.length() == 3){

        mao.erase(2);
        
        valor = stoi(mao);
    } 
    else{
        
        mao.erase(1);
        
        valor = stoi(mao);
    }
    
    return valor;
}

Naipe Partida::voltaNaipe(string temp){
    
    if(temp == "P")
		return P;
		
	if(temp == "E")
		return E;
		
	if(temp == "C")
		return C;
		
	if(temp == "O")
		return O;
}

void Partida::addJogadorDinheiro(int aposta, int pingo, int dinheiro){

	_jogadores[0].setAposta(aposta);
	_jogadores[0].setPingo(pingo);
	_jogadores[0].setDinheiro(dinheiro);	
}

void Partida::setnumJogadores(int _numJogadores){
    
    numJogadores = _numJogadores;
}

void Partida::mudaDinheiro(int _dinheiro, int posi){
    
    _jogadores[posi].setDinheiro(_dinheiro);
}

int Partida::getDinheiroJogadores(int posi){
    
    return _jogadores[posi].getDinheiro();
}

string Partida::getNomeJogadores(int posi){
    
    return _jogadores[posi].getNome();
}

int Partida::balancoJogador(int i){
    
    int balanco = 0;
    
    if(id == i){
        
        balanco = - _jogadores[i].getAposta() - _jogadores[i].getPingo() + montante;
    } 
    else{
        
        balanco = - _jogadores[i].getAposta() - _jogadores[i].getPingo();
    }
    
    return balanco;
}

int Partida::getnumJogadores(){
    
    return numJogadores;
}

int Partida::getMontante(){

	return montante;
}

string Partida::getTipoMaoJogadores(int i){

	return _jogadores[i].getTipoMao();
}

int Partida::getID(){
    
    return id;
}

void Partida::ordenaJogadores(int num){

	Jogador aux;
    
    for(int i = 0; i < num-1; i++){
        
        for(int j = 1; j < num-i; j++){
            
			if(_jogadores[j].getDinheiro() > _jogadores[j-1].getDinheiro()){
                
                aux = _jogadores[j-1];
                _jogadores[j-1] = _jogadores[j];
                _jogadores[j] = aux;
            }
        }
    }
}

int Partida::getPingoRodada(){
    
    return _jogadores[0].getPingo();
}