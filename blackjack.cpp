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
	while(end == false){
		char act = ' ';
		print();
		P1tot = score(p1hand,plastcard);
		cout<<"\t Player's current score : "<<P1tot<<endl;
		while(act != 'h' && act != 's' && act != 'q'){
			cout<<"h = Hit, s = Stand, q = Quit : ";  //allows the player to choose an action
			cin>>act;
		}
		if(act == 'h'){  //'hits'
			do{
			temp = rand()%52;
			p1hand[plastcard] = temp;
			}while(deck[temp] == false);
			plastcard++;
			P1tot = score(p1hand,plastcard);
			cout<<"Player's new score : "<<P1tot<<endl;
		}
		if(P1tot > 21){
				cout<<"Player1 bust!"<<endl;
				end = true;
			}
		else if(act == 's'){ // stand
			while(score(dealhand,dlastcard) < 17){
				do{
				temp = rand()%52;
				dealhand[dlastcard] = temp;
				}while(deck[temp] == false);
				dlastcard++;
			}
			Dealtot = score(dealhand,dlastcard);
			cout<<"\t Dealer's score : "<<Dealtot<<endl;
			dealerprint();
			if(Dealtot > 21){
			end = true;
			cout<<"Dealer busts! P1 wins."<<endl;
			}
			else if(P1tot > Dealtot && P1tot <= 21){
				cout<<"Player 1 wins!"<<endl;
				end = true;
			}
			else if(Dealtot > P1tot && Dealtot <= 21){
				cout<<"Dealer wins!"<<endl;
				end = true;
			}
			else if(Dealtot == P1tot){
				cout<<"Its a tie!"<<endl;
				end = true;
			}
		}
		else if(act == 'q')  //quit
			end = true;
		}
    



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
int convertcard(int card){  //returns the value of the card
	if(card%13 >= 9)
		return 10;
	else if(card%13 < 9 && card%13 != 0)
		return (card%13)+1;
	else if(card%13 == 0)
		return 0;
}
//calculates the score of the hand (any hand)
int score(int hand[],int lastcard){
	int ace = 0;
	int total = 0;
	for(int i = 0; i < lastcard;i++){
		if(convertcard(hand[i]) != 0)
			total = total + convertcard(hand[i]);
		else if(convertcard(hand[i]) == 0)
			ace++;
	}
	for(int i = 0; i < ace;i++){  // checks the ace, will change values if the score becomes higher later on
		if(total+ 11 <= 21)
			total = total +11;
		else if (total+11 > 21)
			total = total + 1;
	}
	return total;
}
//prints the player's hand 
void print(){
	string rank[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	string suit[4] = {"Spades","Hearts","Clubs","Diamonds"};
	string DealCard = "",PlayerCard = "";
	cout<<"Dealer's hand : "<<endl;
	DealCard = rank[dealhand[0]%13] + " Of " + suit[dealhand[0]/13];
	cout<<DealCard<<endl;
	cout<<"Player's hand : "<<endl;
	for(int i=0;i<plastcard;i++){
		PlayerCard = rank[p1hand[i]%13] + " Of " + suit[p1hand[i]/13];
		cout<<"\t "<<PlayerCard<<endl;
	}
}

//prints the dealer's hand 
void dealerprint(){
	string rank[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	string suit[4] = {"Spades","Hearts","Clubs","Diamonds"};
	string DealCard = "";
	cout<<"Dealer's hand : "<<endl;
	for(int i=0;i<dlastcard;i++){
		DealCard = rank[dealhand[i]%13] + " Of " + suit[dealhand[i]/13];
		cout<<"\t "<<DealCard<<endl;
	}
}

