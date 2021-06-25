#include <cstring>
#include <iostream>
#include <ctime>

#include "forca.h"

using namespace std;

int main(int argc, char *argv[])
{

  Forca display;

  int opcao;

  display.inicialPage();

  while (true)
  {
    cout << "\n\n\t\tESCOLHA.\n\t\t1.Soloplayer\n\t\t2.Multiplayer\n\n";
    cin >> opcao;
    if (opcao == 2)
    {
      limpar;
      setbuf;
      Multi();
    }
    else if (opcao == 1)
    {
      limpar;
      setbuf;
      Solo();
    }
    else
      clog << " ERROR. Selecione opçao valida.\n\n";
  }

  return 0;
}

//LJ