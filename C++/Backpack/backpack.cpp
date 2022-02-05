#include <iostream>
#include <clocale>

#include "backpack.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "pt_BR.UTF-8");

	Backpack *show = new Backpack();

	show->setQuestion();
	
	return 0;
}