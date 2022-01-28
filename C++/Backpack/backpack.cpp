#include <iostream>
#include <string.h>
#include <clocale>
#include <vector>
#include <cstdio>
#include <stdio.h>

#define clear system("cls");
#define setb setbuf(stdin, NULL);

using namespace std;


class Backpack {
	public:
	void setQuestion();


	private:
	void addBackpack();
	void setBackpack();
	void finalQuestions();
	void getAllItem(vector<string> getAll);

	vector<vector<string>> SETBP;
	int count = 0;
	

};

void Backpack::setQuestion() {
	char open;

	do {
	cout << "\n\tBem-vindo ao seu armazem.\n\tPressione 1 para abrir a mochila.\n";
	cin >> open;
	clear;
	}	while(open != '1');

	if(open == '1') {
		setb;
		setBackpack();
	}
}


void Backpack::addBackpack(){
	vector<string> get_item;
	char takeItem[30];

	while(strcmp(takeItem, "0") != 0) {
		setb;
		cout << "\n\tEscreva um item:\t";
		cin.getline(takeItem, 30);
		setb;
		count++;

		if(count > 15) {
			cout << "\n\tMOCHILA CHEIA!\n\n";
			break;
		}
		else get_item.push_back(takeItem);
	}

	getAllItem(get_item);
	finalQuestions();

}

void Backpack::getAllItem(vector<string> getAll) {
	SETBP.push_back(getAll);
}

void Backpack::setBackpack() {

		clear;
		setb;
		cout << "\n\n";
		if(SETBP.size() == 0) 
			cout << "\n\tMochila vazia!\n" << endl;
		else{
			for(int i = 0; i < SETBP.size(); i++){
				for(int j=1; j < SETBP[i].size()-1; j++)
					cout << "-> " << SETBP[i][j] << endl;
			}
		}

		finalQuestions();

}

void Backpack::finalQuestions() {
	char next;

	setb;
	cout << "\n\n\tO que deseja?\n\t1. Adicionar itens\n\t2.Abrir mochila\n\t3.Fechar" << endl;
	setb;
	cin >> next;
	setbuf(stdin, NULL);
		
	if(next == '1') addBackpack();
	else if(next == '2')  setBackpack();
	else if(next == '3')  clear;

		
}

int main() {
  setlocale(LC_ALL, "pt_BR.UTF-8");

	Backpack *show = new Backpack();

	show->setQuestion();
	
	return 0;
}