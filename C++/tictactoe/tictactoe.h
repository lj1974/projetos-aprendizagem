#define CLASSES_H_INCLUDED

using namespace std;

#define limpar system("clear");
#define setbuf setbuf(stdin, NULL);

class Tic
{

private:
  char tela[4][4] = {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'},
  };

  short int l, c;
  short int cont_vezes = 1;

public:
  void inicialPage();

  tuple<string, string> getNomes();

  void jogoMain();

  char getSimbolo(int contador);

  void setTabuleiro();

  int verificaPosition(int po_f);

  void getPosition(int po_f1);

  void setNovoTabuleiro(int p);
};

//Função que rege o jogo.

void Tic::jogoMain()
{

  int position;
  char simbol;
  string nome_par, nome_imp;

  tie(nome_par, nome_imp) = getNomes();

  while (cont_vezes <= 9)
  {

    setTabuleiro();

    while (true)
    {

      cout << "\n\n\n"
           << endl;

      cout << "\tEscolha uma posição: ";
      cin >> position;
      setbuf;

      cont_vezes++;
      break;
    }

    getPosition(position);
  }

  if (cont_vezes > 9)
  {
    setTabuleiro();
  }
}

void Tic::inicialPage()
{

  cout << "\nBem-vindo ao jogo da velha.\nDuas pessoa podem jogar.\nGanha quem consegue uma sequencia tripla.\n\n ";
}

tuple<string, string> Tic::getNomes()
{

  string nome1, nome2;

  cout << "\tNome do jogador 1: ";
  getline(cin, nome1);

  setbuf;

  cout << "\tNome do jogador 2: ";
  getline(cin, nome2);

  limpar;

  transform(nome1.begin(), nome1.end(), nome1.begin(), ::toupper);

  transform(nome2.begin(), nome2.end(), nome2.begin(), ::toupper);

  cout << "\tJogador 1, " << nome1 << ", é\t[X]\n\tJogador 2, " << nome2 << ", é\t[O]\n\n";

  return make_tuple(nome1, nome2);
}

void Tic::setTabuleiro()
{

  cout << "\n\n";

  for (l = 0; l < 3; l++)
  {
    if (l < 1)
      cout << "    |      |  \n";
    for (c = 0; c < 3; c++)
    {
      cout << tela[l][c];
      if (c == 2)
        continue;
      cout << "   |  ";
    }
    cout << "\n----|------|----\n";
    if (l == 2)
      cout << "    |      |  ";
  }

  cout << "\n\n\n";
}

int Tic::verificaPosition(int po_l)
{

  int verificado;

  if (po_l < 1 && po_l > 10)
  {
    verificado = 0;
  }
  else if (po_l >= 1 && po_l <= 9)
  {
    verificado = 1;
  }

  return verificado;
}

void Tic::getPosition(int po_l1)
{

  int verificado1 = verificaPosition(po_l1);

  if (verificado1 == 0)
  {
    cout << "\n\t\tInsira apenas posiçoes validas!\n\n"
         << endl;
  }
  else
  {
    setNovoTabuleiro(po_l1);
  }
}

char Tic::getSimbolo(int contador)
{

  char simbolo;

  if (contador % 2 == 0)
  {
    simbolo = 'X';
  }
  else if (contador % 2 != 0)
  {
    simbolo = 'O';
  }

  return simbolo;
}

void Tic::setNovoTabuleiro(int p_final)
{

  char s = getSimbolo(cont_vezes);
  int tabela[3];
  int i = 0;

  l = (p_final - 1) / 3;
  c = (p_final - 1) % 3;

  char uso = tela[l][c];

  if (uso == 'X' || uso == 'O')
  {
    cout << "\n\tEscolha posição vaga!\n";
    cont_vezes--;
  }
  else
  {
    tela[l][c] = s;
  }
}

//LJ
