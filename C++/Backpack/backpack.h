#include <iostream>
#include <string.h>
#include <vector>
#include <cstdio>
#include <stdio.h>

#define clearScreen system("clear");
#define setb setbuf(stdin, NULL);

using namespace std;


class Backpack {
	public:
	void setQuestion();


	private:
	void addBackpack();
	void eraseBackpack();
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
	clearScreen;
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
		cout << "\n\tEscreva um item:\n\t(Entre 0 para finalizar)\t";
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

		clearScreen;
		setb;
		cout << "\n\n";
		if(SETBP.size() == 0) 
			cout << "\n\tMochila vazia!\n" << endl;
		else{
			for(int i = 0; i < SETBP.size(); i++){
				for(int j=1; j < SETBP[i].size()-1; j++) {
					if(!SETBP[i][j].empty())
						cout << i << "." << j << "-> " << SETBP[i][j] << endl;
				}
			}
		}

		finalQuestions();

}

void Backpack::eraseBackpack() {
	int ans1, ans2;
	char first_ans;
	setb;

	cout << "\n\n\tQual item deseja retirar?\n\t1. Apagar tudo\n\t2.Escolher manualmente\n\t(Escreva as 2 colunas corretamente)" << endl;
	cin >> first_ans;

	if(first_ans == '1') SETBP.clear();

	else if(first_ans == '2') {
		cout <<"\tPrimeira coluna: ";
		cin >> ans1;
		setb;
		cout<<"\n\tSegunda coluna: ";
		cin >> ans2;

		clearScreen;
		cout << "\n\tItem -> " << SETBP[ans1][ans2] << " apagado." << endl;

		if(!SETBP[ans1][ans2].empty()) SETBP[ans1][ans2].erase();
		else if(SETBP[ans1][ans2].empty())
			cout << "\n\tPosição vazia!\n" << endl;
	}


	clearScreen;
	finalQuestions();

}

void Backpack::finalQuestions() {
	char next;

	setb;
	cout << "\n\n\tO que deseja?\n\t1. Adicionar itens\n\t2.Abrir mochila\n\t3. Apagar Itens\n\t4.Fechar" << endl;
	setb;
	cin >> next;
	setbuf(stdin, NULL);
		
	if(next == '1') addBackpack();
	else if(next == '2')  setBackpack();
	else if(next == '3' && SETBP.size() != 0) eraseBackpack();
	else if(next == '3' && SETBP.size() == 0) {
		cout << "\n\n\tMochila Vazia!!\n" << endl;
		finalQuestions();
	}
	else if(next == '4')  clearScreen;;
		
}
