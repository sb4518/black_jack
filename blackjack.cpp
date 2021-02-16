#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int hold[52] = {};
bool deck[52] = {};
int P1tot = 0,Dealtot = 0, temp = 0,num = 0,plastcard = 2,dlastcard = 2; // the 'lastcard' variables are to keep track of amount of hits each player has
int p1hand[10];
int dealhand[10]; 

//Initialized the functions: 
void shuffle();
void deal();
int getvalue(int rank);
int convertcard(int card);
int score(int hand[],int lastcard);
void print();
void dealerprint();
void hit(int hand[]);


int main(){
    cout<<"Welcome to BlackJack!"<<endl; 
	srand(time(0));
	bool end = false;   //so it doesn't end
	shuffle();  //shuffles the cards
	deal();  //deals out 2 cards
    



}

void deal(){  //deals 2 cards to each player
	for(int i = 0; i < 2;i++){
		do{
			temp = rand()%52;
			p1hand[i] = temp;
		}while(deck[temp] == false);
		deck[temp] = false;
		do{
			temp = rand()%52;
			dealhand[i] = temp;
		}while(deck[temp] == false);
		deck[temp] = false;
	}
}

void shuffle(){   //sets all the elements of deck to true
	for(int i = 0; i < 52;i++)
		deck[i] = true;
}


