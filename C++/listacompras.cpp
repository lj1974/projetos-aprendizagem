#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdio>

#include <iomanip>
using std::fixed;
using std::ios;
using std::setprecision;
using std::setw;

int main()
{

  int i, n, s, j;
  char mes[20], produto[30][30];
  float valor_total, total, valor[30];
  char ch;

  cout << "Lista de compras do mês.\n";
  cout << "Digite o mes que estamos:  ";
  cin >> mes;

  for (;;)
  {
    cout << "Digite o nome do produto:  ";
    cin >> produto[i];

    cout << "Digite o preço do produto:  ";
    cin >> valor[i];

    valor_total += valor[i];
    total = static_cast<float>(valor_total);

    fflush(stdin);

    cout << "Continuar? (s//n)  \n";
    cin >> ch;

    if (ch == 'n')
    {
      break;
    }
    i++;
  }
  i++;

  system("clear");

  cout << "Tabela de compras do mês" << mes;
  cout << "PRODUTO      PREÇO\n";

  for (j = 0; j < i; j++)
  {
    cout << produto[j] << setw(15) << setprecision(2) << fixed << valor[j] << endl;
  }
  cout << "\nTOTAL:" << setw(6)
       << valor_total;

  return 0;
}