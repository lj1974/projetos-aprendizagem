#define limpar system("cls");
#define setbuf setbuf(stdin, NULL);

class AtmDoing {

  protected:
  void getPayment();
  float saldo;

  private:
  void setForma_pagamento(int option);
  void setDinheiro();
  void setPix();
  void setCartaoCredito();

  void setNovoSaldo(float valor1);


};

void AtmDoing::getPayment(){
  int forma_pag;
  cout << "\n\tEscolha forma de pagamento:\n\t1.Dinheiro\n\t2.PIX\n\t3.Cartao de Credito" << endl;
  cin >> forma_pag;
  setbuf;
  setForma_pagamento(forma_pag);
  limpar;

}

void AtmDoing::setForma_pagamento(int option){
  switch(option){
    case 1:
    setDinheiro();
    break;

    case 2:
    setPix();
    break;

    case 3:
    setCartaoCredito();
    break;

    default:
    cout << "\n\tEscolha apenas opçoes validas\n\tProcedimento encerrado" << endl;
  }
}

void AtmDoing::setDinheiro(){
  float valor;
  cout << "\n\tEscolha valor de recarga:  ";
  cin >> valor;
  setbuf;

  setNovoSaldo(valor);
  limpar;
}

void AtmDoing::setPix(){
  cout << "\n\tChave: 12345678";
  setbuf;
}

void AtmDoing::setCartaoCredito(){
  float valor;

  string num_cartaoCred;
  string nome;
  int cvc;

  int count;
  bool repeat = true;

  int confirm;

  cout << "\n\tValor da recarga: ";
  cin >> valor;

  cout << "\n\tDigite o nome completo do titular: \n";
  cin >> nome;
  
  do{
  cout << "\n\n\tDigite o numero do cartão:  \n";
  cin >> num_cartaoCred;
  setbuf;
 
  for(int i = 0; i <= num_cartaoCred.length(); i++){
    count++;
  }
  count -=1;
  
  if(count != 2){
    cout <<"\n\tNumero de cartão invalido\n" << endl;
    count = 0;
  }
  else{
  repeat = false;
  }
  } while(repeat);

  cout << "\n\tDigite o CVC do cartao: ";
  cin >> cvc;

  limpar;

  cout << "\n\tConfira as informaçoes: \n";
  cout << "\tNome completo: " << nome;
  cout << "\n\tNum do cartao: " << num_cartaoCred;
  cout << "\n\tCVC do cartao: " << cvc;

  cout << "\n\tConfirmar? (S = 1/N = 0) ";
  cin >> confirm;
  setbuf;

  if(confirm == 1){
    setNovoSaldo(valor);
    limpar;
  }
  else{
    cout << "\n\tOperaçao cancelada\n";
  }


}

void AtmDoing::setNovoSaldo(float valor1) {
float novo_saldo;
novo_saldo = saldo + valor1;

cout << "\n\tNovo saldo: " << novo_saldo;
}



class Atm : protected AtmDoing {

  public:

  void setScreen();

  protected:
  void getNum_cartao(string num_card);
  void getAnswerProcedure(int option1);

  private:
  void setSecondScreen(float num_card);
  void setCancel();
  string num_card;

};

void Atm::setCancel(){
  int cancel_card;
  limpar;

  cout << "Tem certeza que quer cancelar o cartao " << num_card << " ?\n\t(Sim = 1/ Nao = 2)" << endl;
  setbuf;
  cin >> cancel_card;

  if(cancel_card == 1){
    limpar;
    cout << "\n\tCartao cancelado, nao\n\tpodera mais ser usado\n\tProcesso encerrado" << endl;;
  }
  else if(cancel_card == 2){
    limpar;
    cout << "\n\tOperaçao cancelada" << endl;;
  }

}

void Atm::setScreen(){
  bool repeat = true;
  unsigned int count = 0;

  do{
  cout << "\n\n\tDigite o numero do cartão\n\ta ser recarregado: ";
  cin >> num_card;
  setbuf;
 
  for(int i = 0; i <= num_card.length(); i++){
    count++;
  }
  count -=1;
  
  if(count != 2){
    cout <<"\n\tNumero de cartão invalido\n" << endl;
    count = 0;
  }
  else{
  getNum_cartao(num_card);
  repeat = false;
  }
  } while(repeat);


}

void Atm::getNum_cartao(string num_card){
  saldo = 12.40;

setSecondScreen(saldo);
}

void Atm::setSecondScreen(float saldo_card){
  int option;
  cout << "\n\tSaldo disponivel: " << saldo_card;
  cout << "\n\t1. Recarregar cartao\n\t2.Cancelar cartao" << endl;
  cin >> option;
  setbuf;

  getAnswerProcedure(option);
}

void Atm::getAnswerProcedure(int option1){
  switch(option1){
    case 1:
    getPayment();
    break;

    case 2:
    setCancel();
    break;

    default:
    cout << "\n\tEscolha apenas opçoes validas\n\tProcedimento encerrado" << endl;
  }
}