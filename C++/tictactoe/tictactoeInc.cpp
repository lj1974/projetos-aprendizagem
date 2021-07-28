#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <tuple>

#include "tictactoe.h"

using namespace std;

#define limpar system("clear");
#define setbuf setbuf(stdin, NULL);

int main(int argc, char *argv[])
{

  Tic display;

  int start;

  display.inicialPage();

  while (true)
  {
    cout << "\t\tIniciar?\n\t\t1.SIM\n\t\t2.NAO" << endl;
    cin >> start;
    setbuf;
    limpar;

    if (start == 2)
    {
      cout << "Adeus." << endl;
      break;
    }

    else if (start == 1)
    {
      display.jogoMain();
      break;
    }
    else
    {
      cerr << "\n\nERROR. Selecione opção valida.";
      limpar;
    }
  }

  return 0;
}

//LJ