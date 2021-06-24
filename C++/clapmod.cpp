#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <tuple>
using namespace std;


// JOGO CLAP, MODIFICADO
class Clap {

  public:

  void setIntro() {
    int op;

    cout << "Bem-vindo ao jogo!\n\n";
    cout << "REGRAS:\nGanha se rolar 7 ou 11.\n";
    cout << "Perde se rolar 2, 3 ou 12.\n";
    cout << "Se rolar outro numero,\n";
    cout << "rola novamente para conseguir um 11,\n";
    cout << "se conseguir um numero menor que 11, perde!\n\n";
    cout << "QUE COMECE O JOGO!\n\n\n";
    
  }

    // JOGO PRINCIPAL
  tuple <int,int> setGame(int total) {

    int total2, status, sorte;
    int cont = 0, sub = 0;
  

    switch(total) 
    {
      case 7:
      case 11:
      cout << "Voce venceu! Parabéns." << endl;
      cont++;
      sub++;
      break;

      case 2:
      case 3:
      case 12:
      cout << "Voce perdeu. Fim da linha." << endl;
      sub++;
      break;

      default:
      cout << "Sua pontuação: " << total << endl;
      sorte = (rand() % 12+1);
      total2 = total + sorte;
      if (total2 == 11 || total2 > 12) {
        cout << total << " + " << sorte << " = " << total2 << endl;
        cout << "Venceu! Parabéns." << endl;
        cont++;
        sub++;
      }
      else {
        cout << total << " + " << sorte << " = " << total2 << endl;
        cout << "Perdeu. Fim da linha." << endl;
        sub++;
      }
    }


    return(make_tuple(cont, sub));

    }

  int getSorteio() {
    srand(time(NULL));
    int dado;
    int dado1 = (rand() % 6+1);
    int dado2 = (rand() % 6+1);

    dado = dado1 + dado2;

    cout << dado1 << " + " << dado2 << " = " << dado << endl;

    return (dado);
  }


};

int main(int argc, char* argv[]) {
  Clap display;

  int op, dado, novo, jogo, conta, sub;
  int total = 0, play = 0;

  display.setIntro();
  cout << "Começar? Digite 1.Sim\\2.Nao\t";
  cin >> op;
  cout << "\n\n\n";

  if (op == 1){

    do {
      system("clear");
      dado = display.getSorteio();
      tie(conta, sub) = display.setGame(dado);
      total += conta;
      play += sub;

      cout << "\nNovamente? 1.SIM\\2.NAO\t";
      cin >> novo;
      if (novo == 2) {
        jogo = false;
        cout << "\nVitorias: " << total << "/" << play << endl;
      }
      else 
        jogo = true;

    } while (jogo == true);
  }
  else if (op == 2){
    cout << "Adeus" << endl;
  }


return 0;
}

// LJ