#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{

  int tabuada, valor, i;

  cout << "Digite o numero da tabuada que deseja: ";
  cin >> tabuada;
  for (valor = 1; valor < 11; valor++)
  {
    i = tabuada * valor;
    cout << tabuada << " x " << valor << " = "
         << i << endl;
  }

  return 0;
}