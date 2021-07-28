// jogo de dados
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolar(void);
int main(void)
{

  srand(time(NULL));

  int op, status, ans;

  printf("Bem-vindo ao jogo!\n");
  printf("Role numeros pares para vencer\n");
  printf("Ou perca miseravelmente com impares.\n");
  printf("\n");

  do
  {
    printf("Começar? 1.Sim\\\\2.Não\n");
    scanf("%d", &op);
    if (op == 2)
      do
      {
        printf("Adeus, covarde.\n");
        break;
      } while (op == 2);

    else
      do
      {
        status = rolar();
        if (status % 2 == 0)
          printf("Parabens pela vitoria!\n");

        else
          printf("Temos um perdedor!\n");
        break;
      } while (op == 1);

    printf("\n");
    printf("Reiniciar? 0.Sim\\\\9.Nao\n");
    scanf("%d", &ans);

  } while (ans == 0);

  printf("Adeus definitivo.\n");

  return 0;
}

int rolar(void)
{
  int jogada, face;
  for (jogada = 1; jogada <= 1; jogada++)
    ;
  face = (rand() % 100);
  printf("jogador obteve: %2d\n", face);
  return face;
}

//LJ