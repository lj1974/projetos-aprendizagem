#define CLASSES_H_INCLUDED
using namespace std;

#define limpar system("clear");
#define setbuf setbuf(stdin, NULL);
const int quant_palavras = 10; //palavras sorteadas/Modo Solo

class Forca
{

public:
  void inicialPage(); //Mensagem de boas-vindas.

  void jogoMain(char *palavra);

  //Variaveis da função jogoMain
  string setPalavra, letrasUs, telaUs;
  char *palavra[30], telaVer[30];
  char tela[30], letra[2], letras_us[26], tela_us[30];
  char *ptr;
  char verif[2];
  int i, max = 0, acert = 0;
};

void Forca::inicialPage()
{

  cout << "\n\nBEM-VINDO AO JOGO DA FORCA!\t\n\n";
  cout << "INSTRUÇÃO\n";
  cout << "(Multiplayer): Pessoa 1 escreve uma palavra.\n";
  cout << "\t\t\t   Pessoa 2 tenta acertar a palavra.\n\n";
  cout << "(Solo): Uma palavra é sorteada, você a adivinha.\n\n";
  cout << "Você tem cinco vidas para esbanjar suas chancess...\n"
       << endl;
}

// Função que rege o funcionamento do jogo.
void Forca::jogoMain(char *palavra)
{

  for (i = 0; i < strlen(palavra); i++)
  {
    tela[i] = '_';
  }

  cout << "\n\nQuantidade de letras: " << strlen(palavra) << endl;

  for (i = 0; i < strlen(palavra); i++)
  {
    cout << "\t" << tela[i];
  }

  verif[0] = '_';

  while (max <= 5 || (strchr(tela, verif[0]) != NULL))
  {

    cout << "\n\n\tdigite letra:  ";
    cin >> letra[0];
    cout << endl;

    if (strchr(palavra, letra[0]) != NULL)
    {
      ptr = strchr(palavra, letra[0]);

      while (ptr != NULL)
      {
        i = (ptr - palavra);
        ptr = strchr(ptr + 1, letra[0]);
        tela[i] = letra[0];
        telaUs += letra[0];
      }

      for (i = 0; i < strlen(palavra); i++)
      {
        cout << "\t" << tela[i];
      }
    }
    else
    {
      cout << "\n\tletra errada.\n";
      max++;
    }

    char *letras_us = new char[letrasUs.length() + 1];
    strcpy(letras_us, letrasUs.c_str());

    if (!(strchr(letras_us, letra[0])))
    {
      letrasUs += letra[0];
      letrasUs += ' ';
    }

    cout << "\n\n\tLetras usadas:";
    cout << "\t" << letrasUs << "\n";

    if (max == 5)
    {
      limpar;
      cout << "\n\n\n\tVoce perdeu... Palavra Secreta: " << palavra << endl;
      break;
    }
    else if (strchr(tela, verif[0]) == NULL)
    {
      limpar;
      cout << "\n\n\n\tVoce venceu! Palavra Adivinhada: " << palavra << endl;
      break;
    }
  }
}

class Multi : public Forca
{

public:
  Multi(); //Forca Multiplayer iniciador.

private:
  string getPalavra(); //Pega palavra do teclado.
};

Multi::Multi()
{

  Forca show;

  setPalavra = getPalavra();
  *palavra = &setPalavra[0];

  show.jogoMain(*palavra);
}

string Multi::getPalavra()
{

  string palavra_secreta;

  cout << "\n\n\tEscreva uma palavra :  ";
  getline(cin, palavra_secreta);
  limpar;

  return palavra_secreta;
}

class Solo : public Forca
{

public:
  Solo(); // Iniciador de Soloplayer

private:
  //Pega numero de banco local
  string getSorteio(int num);

  string setSorteio();

  int getNumero();

  // Banco de palavras local
  string deposito[quant_palavras]{
      "esqueleto",
      "elefante",
      "notebook",
      "comboio",
      "estante",
      "amarelo",
      "bolo",
      "gato",
      "minecraft",
      "fatiador"};
};

Solo::Solo()
{

  Forca show;
  int num1;
  num1 = getNumero();

  setPalavra = getSorteio(num1);
  *palavra = &setPalavra[0];

  show.jogoMain(*palavra);
}

int Solo::getNumero()
{

  int num;
  srand(time(NULL));

  num = rand() % (quant_palavras - 1);

  return num;
}

string Solo::getSorteio(int num)
{
  string palavra_sorteada;
  palavra_sorteada = deposito[num];

  return palavra_sorteada;
}

//LJ