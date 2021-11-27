#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define limpar setbuf(stdin, NULL);
#define tela system("clear");

class InterfacePlayer {

  public:


  char nome[20];
  int idade;

  unsigned int intel;
  unsigned int vigor;
  unsigned int saude;
  unsigned int feliz;

  unsigned int dinheiro;

  unsigned int favor_mat;
  unsigned int favor_jess;
  unsigned int favor_jasp;
  unsigned int favor_ma;

};



class Action : public InterfacePlayer{
  public:
  Action();
  void setGame();

  protected:

  void getName();
  void showAtributos();
  void setSheet_Answer();
  bool getAnswer();

  bool controle_trabalho(int valor);
  void fim();

  private:
  bool contaDinheiro(int valor);
  int random();
  int requisitos(int one, int two, int three);


  void exercicio();
  void comer();
  void beber();
  void estudar();
  void ler();
  void sair();
  void trabalhar();
  void social();
  void social_acoes(int valor);
  void crescer();

  void acidentes();
  void morte();

};

Action::Action(){
  this->idade = 0;
  this->intel = 0;
  this->vigor = 20;
  this->saude = 20;
  this->dinheiro = 30;
  this->favor_mat = 5;
  this->favor_jess = 5;
  this->favor_jasp = 5;
  this->favor_ma = 5;
}

void Action::setGame() {
   int option;
  bool repeat = true;
  bool sair;


  while(repeat) {
    cout<<"Play?\n";
    cout<<"1.YES // 2.NÃO\n";
    cin >> option;

  if(option==1){
    limpar;
    tela;

    getName();
    tela;

    while(sair == false){
      showAtributos();
      setSheet_Answer();
      sair = getAnswer();
      // controle();
    }
    if(sair == true){
      tela;
      fim();
      repeat = false;
    }  
    
  }
  else {
    limpar;
    tela;
    repeat = false;
  }
  }
}

void Action::getName(){
    cout<<"Qual o seu nome?" << endl;
    cin >> nome;
   limpar;
  }

void Action::showAtributos(){
    cout << "\nNome: " << nome << "\t\tIdade: " << idade << "\t\tDinheiro: " << dinheiro << endl;
    cout << "Inteligência: " << intel << "\t\tVigor: " << vigor << "\t\tSaúde: " << saude << endl;
  }

void Action::setSheet_Answer() {
    cout << "\nO que quer fazer?\n\n1.Se exercitar\n2.Comer\n3.Beber\n4.Estudar\n5.Ler um livro \n6.Sair de casa\n7.Ir ao trabalho\n8.Socializar com amigos\n9.Crescer (+1 ano)\n0.Abandonar sua vida\n";
  }

 bool Action::getAnswer(){
    int answer;
    bool sair2;
    cin >> answer;

    switch(answer){
      case 1:
      exercicio();
      break;

      case 2:
      comer();
      break;

      case 3:
      beber();
      break;

      case 4:
      estudar();
      break;

      case 5:
      ler();
      break;

      case 6:
      sair();
      break;

      case 7:
      trabalhar();
      break;

      case 8:
      social();
      break;

      case 9:
      crescer();
      break;


      case 0:
      sair2 = true;
      break;
      default:
      cout<< "\n\nerror. Tente novamente com um\n numero valido\n\n" << endl;
      break;
    }

  return sair2;
  }

bool Action::controle_trabalho(int valor) {
  bool num;

  switch(valor) {
    case 1:
    if(idade >= 6 && intel >= 30 && vigor >= 20){
      num = true;
    }
    else{
      num = false;
    }
    break;

    case 2:
    if(idade >= 10 && intel >= 10 && vigor >= 20){
      num = true;
    }
    else{
      num = false;
    }
    break;

    case 3:
    if(idade >= 15 && intel >= 10 && vigor >= 40){
      num = true;
    }
    else{
      num = false;
    }
    break;

    case 4:
    if(idade >= 18 && intel >= 30 && vigor >= 10){
      num = true;
    }
    else{
      num = false;
    }
    break;

    case 5:
    if(idade >= 15 && intel >= 10){
      num = true;
    }
    else{
      num = false;
    }
    break;

    default:
    cout<< "\n\nerror. Tente novamente com um\n numero valido\n\n" << endl;

  }

  return num;
}

bool Action::contaDinheiro(int valor) {
  bool result;
  if (dinheiro >= valor) {
    result = true;
  } else 
  result = false;

  return result;
}

int Action::random(){
  int number;
  srand((unsigned)time(0));
  number = (rand()%6)+1;

  return number;
}




void Action::exercicio(){
  cout << "\n\nAlongamento...\n";
  cout <<"VIGOR -1! SAUDE +1!\n\n";

  vigor-=1;
  saude+=1;
}



void Action::comer() {
  bool verf;
  int comida;
  cout << "\n\n1.JunkFood\n2.Saúdavel" << endl;
  cin >> comida;

    if(comida==1){
      verf = contaDinheiro(2);
      if(verf){
        cout << "\nComendo pizza...\n";
        cout << "SAUDE -1! DINHEIRO -2! VIGOR +2" << endl;

        saude-=1;
        dinheiro-=2;
        vigor+=2;
      }
      else {
        cout << "\n\nVoce nao tem dinheiro suficiente\nVa trabalhar!" << endl;
      }
    }
    else if (comida==2){
       verf = contaDinheiro(5);
      if(verf){
        cout << "\nComendo salada...\n";
        cout << "SAUDE +2! DINHEIRO -5! VIGOR +2" << endl;
      
        saude+=2;  
        dinheiro-=5;
        vigor+=2;
      }
      else {
        cout << "\n\nVoce nao tem dinheiro suficiente\nVa trabalhar!" << endl;
      }
       
    }
}

void Action::beber(){

  int bebida;
  bool verif;

  cout << "\n\n1.Água \n2.Suco\n3.Vodka" << endl;
  cin >> bebida;

    if(bebida==1){
       verif = contaDinheiro(1);
      if(verif){
        cout << "\n\nAgua refrescante..." << endl;
        cout<< "SAUDE +2! VIGOR +1! DINHEIRO -1!" << endl;

        saude +=2;
        vigor +=1;
        dinheiro -=1;
      }
      else {
        cout << "\n\nVoce nao tem dinheiro suficiente\nVa trabalhar!" << endl;
      }
      }
      else if(bebida==2){
         verif = contaDinheiro(3);
        if(verif){
          cout << "\n\nBebendo limonada..." << endl;
          cout<< "SAUDE +3! VIGOR +1! DINHEIRO -3!" << endl;

          saude +=3;
          vigor +=1;
          dinheiro -=3;
        }
        else {
        cout << "\n\nVoce nao tem dinheiro suficiente\nVa trabalhar!" << endl;
      }
      }
      else if(bebida==3){
         verif = contaDinheiro(5);
        if(verif){
          cout << "\n\nMinha cabeça está girando..." << endl;
          cout<< "SAUDE -2! DINHEIRO -5!" << endl;

          saude -=2;
          dinheiro -=5;
        }
        else {
        cout << "\n\nVoce nao tem dinheiro suficiente\nVa trabalhar!" << endl;
      }
      }
}

void Action::estudar(){
  cout << "\n\nEstudando matematica..." << endl;
  cout << "INTELIGENCIA +3! FELICIDADE -2!" << endl;

  intel +=3;
  feliz -=2;
}

void Action::ler(){
  cout<< "\n\nLendo uma aventura..." << endl;
  cout << "INTELIGÊNCIA +1! VIGOR -2! FELICIDADE +1!" <<endl;

  intel+=1;
  vigor-=2;
  feliz+=1;

}

void Action::sair(){
  int saircasa, casual;
  bool verif;
  string filme;

  cout<< "\n\n1.Jantar fora\n2.Ir a uma balada\n3.Ir ao cinema" << endl;
  cin >> saircasa;

 verif = contaDinheiro(10);
 if(verif){
  if(saircasa==1){
    cout << "\n\nQue comida deliciosa!"<< endl;

    dinheiro -=10;

    casual = random();

      if(casual==5){
    
        cout<< "Você está tendo uma dor de barriga..." << endl;
        cout << "SAUDE -3! DINHEIRO -10!" << endl;

        saude -=3;
      } 
       else {
          cout << "FELICIDADE +4! DINHEIRO -10!" << endl;

          feliz +=4;
       }
  }
  else if(saircasa==2){
        cout << "\n\nVamos dançar a noite toda!" << endl;
        dinheiro -=10;

        casual = random();

        if(casual==2){
          cout << "Voce está de ressaca..." << endl;
          cout << "VIGOR -5! FELICIDADE +3! SAUDE -3! DINHEIRO -10!" << endl;

          vigor -=3;
          feliz +=3;
          saude -=3;
        }
        else {
          cout << "VIGOR -5! FELICIDADE +5! DINHEIRO -10!" << endl;
          vigor -=3;
          feliz +=5;
        }
      }
      else if(saircasa==3){
        limpar;
        cout << "Qual o novo filme...?" << endl;
        getline(cin, filme);
        cout << endl<< filme << ", foi otimo!" << endl;
        cout << "FELICIDADE +5! INTELIGENCIA +1! DINHEIRO-10!" <<endl;
        feliz+=5;
        intel+=1;
        dinheiro -=10;
      }
  }
  else {
        cout << "\n\nVoce nao tem dinheiro suficiente\nVa trabalhar!" << endl;
      }

}

void Action::trabalhar(){
  int carreira;
  bool control;

  cout << "1.PINTOR (Requisitos:\n +6 IDADE +30 INTELIGENCIA +20 VIGOR)\n2.ATOR (Requisitos:\n+10 IDADE +10 INTELIGENCIA +20VIGOR)\n3.TENISTA (Requisitos\n+15 IDADE +10 INTELIGENCIA +40 VIGOR)\n4.PROGRAMADOR (Requisitos:\n +18 IDADE +30 INTELIGENCIA +10 VIGOR)\n5.FREELANCER (Requisitos:\n +15 IDADE +10 INTELIGENCIA)\n\n" << endl;
  cin >> carreira;

  control = controle_trabalho(carreira);
  if(control == false){
    cout << "\n\n\nVoce ainda nao pode exercer\n essa funçao! Continue tentando\n9 numa proxima vez.\n" << endl;
  }
  else {

  switch(carreira){
    case 1:
    cout<< "\n\nQue lindo quadro!\n É...uma arte...abstrata?\n" << endl;
    cout << "+50 DINHEIRO -5 VIGOR -2 SAUDE" << endl;

    dinheiro +=50;
    vigor-=5;
    saude-=5;
    break;

    case 2:
    cout << "\n\nSe esconda dos seus fãs, rapido!\n+150 DINHEIRO -15 VIGOR -10 SAUDE" << endl;

    dinheiro +=150;
    vigor-=15;
    saude-=10;
    break;

    case 3:
    cout << "\n\nMarcou 10 pontos no primeiro set!\n+70 DINHEIRO -15 VIGOR +3 SAUDE" << endl;

    dinheiro +=70;
    vigor-=15;
    saude+=3;
    break;

    case 4:
    cout << "\n\nQue codigo mais cheio de bugs.\n+120 DINHEIRO -2 VIGOR -10 SAUDE" << endl;

    dinheiro +=120;
    vigor-=2;
    saude-=10;
    break;

    case 5:
    cout << "\n\nQue cliente mais chato...\n+30 DINHEIRO -2 VIGOR -2 SAUDE" << endl;

    dinheiro +=30;
    vigor-=2;
    saude-=2;
    break;
  }
  }

}

void Action::social(){
  int amigo;
  cout<<"\n\nEscolha algum amigo:\n1.Mateus Favor = "<< favor_mat <<"\n2.Jessie Favor = " << favor_jess << "\n3.Jasper Favor = " << favor_jasp <<"\n4.Maçã Favor = " << favor_ma << "\n\n" << endl;
  cin >> amigo;
  vigor -= 1;

  switch(amigo) {
    case 1:
    social_acoes(1);
    favor_mat =-2;
    break;

    case 2:
    social_acoes(2);
    favor_jess=-5;
    break;

    case 3:
    social_acoes(3);
    favor_jasp =-3;
    break;

    case 4:
    social_acoes(4);
    favor_mat =-7;
    break;

    default:
    cout<< "\n\nerror. Tente novamente com um\n numero valido\n\n" << endl;
  }

  cout << "\n\n-1 VIGOR!\n\n" << endl;

}
void Action::social_acoes(int valor){
  int favor;
  int escolha;

  switch(valor){
    case 1:
    favor = favor_mat;
    break;

    case 2:
    favor = favor_jess;
    break;

    case 3:
    favor = favor_jasp;
    break;

    case 4:
    favor = favor_ma;
    break;
  }


  while(favor != 0 || escolha != 4){
  cout << "\n\nFavor Atual: "<< favor <<"\nO que quer fazer?\n1.Conversar\n2.Abraçar\n3.Chutar\n4.Ir embora";
  cin >> escolha;
  }
  if(favor == 0){
    cout << "\nVoce é odiado. Continuar?" << endl;
  }
}

void Action::crescer(){
  idade++;
  cout << "\n\n\nParabens! Agora voce tem " << idade << "!" << endl<< endl;
  acidentes();
  morte();
}


void Action::acidentes() {
  int casual; 
  casual = random();

  switch(casual){
    case 1:
    if(idade < 10){
    cout << "\n\nVoce caiu de uma arvore enquanto\n escalava com seus amigo e quebrou um dos braços.\n SAUDE -5!" << endl;

    saude-= 5;
    }
    else if(idade <= 40){
      cout << "\n\nVoce pegou um resfriado muito forte,\n quase foi parar no hospital!\n SAUDE -7! VIGOR -1!" << endl;

      saude-=7;
      vigor-=1;
    }
    else if(idade >= 70) {
      cout << "\n\nSeus pulmoes nao aguentam mais\n a poluiçao da cidade...\n SAUDE -10! VIGOR -5!" << endl;

      saude-=10;
      vigor-=5;
    }
    
    break;

    case 2:
    if(idade < 10){
      cout << "\n\nVoce ganhou uma competição escolar!\nINTELIGENCIA +2!" << endl;

      intel +=2;
    }
    else if(idade <= 40){
      cout << "\n\nVoce encontrou uma nota de\n 20 na calçada!\n DINHEIRO +20!" << endl;

      dinheiro+=20;
    }
    else if(idade >= 70) {
      cout << "\n\nO medico disse que sua saude esta\n tao forte quanto estava nos 40!\n SAUDE +10!" << endl;

      saude+=10;
    }

  break;
  
  case 3:
  case 4:
  case 5:
  case 6:
  break;

  }
 
}

void Action::morte(){
  int num;
  srand((unsigned)time(0));
  num = (rand()%30)+1;

  if(num == 27){
    if(idade >70 && saude < 30){
      tela;
      cout << "Voce sofreu um ataque cardiaco e morreu.\nDEAD END" << endl;
      fim();
      
    }
    else {
    tela;
    cout << "Voce sofreu um acidente de carro enquanto voltava pra casa. Voce morreu.\nDEAD END." << endl;
    fim();
    
    }
  }

  if(idade > 100 && num>10){
    tela;
     cout << "Voce sofreu um ataque cardiaco e morreu.\\nDEAD END" << endl;
     fim();
     
  }
}

void Action::fim(){
  cout << "\n\n\nObrigada por jogar!" << endl;
  showAtributos();
  exit(0);
}

int main() {

  Action *show2 = new Action();

  show2->setGame();



  return 0;
}