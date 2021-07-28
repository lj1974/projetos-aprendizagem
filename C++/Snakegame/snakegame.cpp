#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>

using namespace std;

#define clear system("cls");
#define stdinbuff setbuf(stdin, NULL);

bool gameOver;

class Snake
{

public:
  void Setup();
  void Draw();
  void Message();
  int Click(char key);
  void Input(int id_key);
  void Move();
  void Logic();

private:
  const int height = 18;
  const int width = 40;
  int x, y, fruitX, fruitY;
  char fruit = 'Q';
  int score;

  enum Direction
  {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
  };
  Direction dir;
};

void Snake::Setup()
{

  srand(time(NULL));

  gameOver = false;
  dir = STOP;
  x = height / 2;
  y = width / 2;
  fruitX = rand() % height;
  fruitY = rand() % width;
  score = 0;
}

void Snake::Draw()
{
  int i, j;

  clear;

  for (i = 0; i < width; i++)
  {
    cout << "#";
  }
  cout << endl;

  for (i = 1; i <= height; i++)
  {
    for (j = 1; j <= width; j++)
    {
      if (j == 1)
      {
        cout << "#";
      }
      else if (j == width)
      {
        cout << "#\n";
      }
      else if (i == x && j == y)
      {
        cout << "<";
      }
      else if (i == fruitX && j == fruitY)
      {
        cout << fruit;
      }
      else
      {
        cout << " ";
      }
    }
  }

  for (int i = 0; i < width; i++)
  {
    cout << "#";
  }
  cout << endl;
}

void Snake::Message()
{
  cout << endl;
  cout << "SCORE: " << score << endl;
  cout << "Choose one of the four directions to move the snake\nUP(W), LEFT(A), RIGHT(D) OR DOWN(S) LETTER KEY.\nYour objective is to eat the fruit 'Q'\nGood luck! Or press 'X' to surrender...\n";
}

int Snake::Click(char key)
{

  int id;

  switch (key)
  {
  case 'W':
  case 'w':
    id = 1;
    break;

  case 'A':
  case 'a':
    id = 2;
    break;

  case 'D':
  case 'd':
    id = 3;
    break;

  case 'S':
  case 's':
    id = 4;
    break;

  case 'X':
  case 'x':
    id = 5;
    break;

  default:
    id = 0;
    break;
  }

  return id;
}

void Snake::Input(int id_key)
{

  switch (id_key)
  {
  case 1:
    dir = UP;
    break;

  case 2:
    dir = LEFT;
    break;

  case 3:
    dir = RIGHT;
    break;

  case 4:
    dir = DOWN;
    break;

  case 5:
    gameOver = true;
    cout << "\nEND!" << endl;
    break;

  case 0:
    break;
  }
}

void Snake::Move()
{
  switch (dir)
  {
  case UP:
    x--;
    break;

  case LEFT:
    y--;
    break;

  case RIGHT:
    y++;
    break;

  case DOWN:
    x++;
    break;

  default:
    break;
  }
}

void Snake::Logic()
{
  // IF SNAKES HIT WALLS
  if (x <= 0 || x >= height || y <= 0 || y >= width)
  {
    gameOver = true;
    cout << "\nGAME OVER!\n";
  }

  // If snake reaches the fruit
  // then update the score
  if (x == fruitX && y == fruitY)
  {
    fruitX = rand() % height;
    fruitY = rand() % width;
    score++;
  }
}

int main(int argc, char *argv[])
{

  Snake show;

  char key;
  int idNum;

  show.Setup(); //BASIC

  while (!gameOver)
  {

    // SET UP THE GAME
    show.Draw();
    show.Message();

    // TO GET WHICH KEY IS PRESSED.
    stdinbuff;
    key = getchar();

    idNum = show.Click(key);
    show.Input(idNum);
    stdinbuff;

    show.Move();
    show.Logic();
  }

  return 0;
}