#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <windows.h>

using namespace std;

/*====================================================================================================
===================================   BlackJack Declarations    ======================================
====================================================================================================*/
bool finish = false;				//controls when the code ends
int player_total, opponent_starting, starting_cards, opponent_total, count;
int bet, earnings = 10000;			//providing an initial value of earnings so the game can be started
bool point = false;					//acts as a switch for the loop
char cont = 'y';

int player_card();
int opponent_card();
void win(int, int &earnings, int);
void lose(int, int &earnings, int);
void tie(int, int &earnings, int);
void jack(int, int &earnings, int);
void display(int, int &player_total, int &opponent_total, int, int &earnings, int);
void blackJack();
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
=================================    SlotMachine Declarations  =======================================
====================================================================================================*/
int slot1,slot2,slot3;

struct values{
	double points[8];
	string symbol[8];
}v;

void initialize();
void randomizer();
void slotOut();
void slotMachine();
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
==================================     Baccarat Declarations    ======================================
====================================================================================================*/
inline void WINBT(double *reward, double *bet);
int drawCard();
void outCard(int);
int points(int, int);
bool needMoreCards(int, int);
void gameEnd(int, int);
int Baccarat();
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
==================================        GUI Declarations      ======================================
====================================================================================================*/
void welcomeToCasino();
void slotMachineRules();
void blackJackRules();
void baccaratRules();
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
========================================        Main     =============================================
====================================================================================================*/
int main(){
    int choiceMain;
    system("CLS");
    welcomeToCasino();

    do{
        cout << endl << "Enter 1 to play Black Jack." << endl;
        cout << "Enter 2 to play Slot machine." << endl;
        cout << "Enter 3 to play Bacarrats." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << "Choice:    ";

        cin >> choiceMain;
        cout << endl;

        switch (choiceMain){
            case 0:
				cout << "Thank you for playing." << endl;
				cout << "Your total earnings were: " << earnings << endl;
                break;
            case 1:
                blackJackRules();
                blackJack();
                break;
            case 2:
                slotMachineRules();
                slotMachine();
                break;
            case 3:
                baccaratRules();
                Baccarat();
                break;
            default:
                cout << "Not a valid option." << endl;
        }
    }while(choiceMain != 0);
}
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
==================================    BlackJack Definition    ========================================
====================================================================================================*/
int player_card(){
	int card;
	return card = 2 + rand()%10;
}

int opponent_card(){
	int card;
	return card = 2 + rand()%10;
}

void win(int opponent_total, int &earnings, int bet){
	earnings += 2*bet;
	cout<<"Congratulations! You have won the game!"<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout <<"You earned $"<<bet<<". You now have $"<<earnings<<"."<<endl;
	finish = true;
}

void lose(int opponent_total, int &earnings, int bet){
	cout<<"You have lost the game."<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout<<"You lost $"<<bet<<". You now have $"<<earnings<<"."<<endl;
	finish = true;
}

void tie(int opponent_total, int &earnings, int bet){
	earnings += bet;
	cout<<"Its a tie."<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout<<"You still have $"<<earnings<<"."<<endl;
	finish = true;
}

void jack(int opponent_total, int &earnings, int bet){
	earnings += 2*bet;
	cout<<"Congratulations! Its a natural jack!"<<endl;
	cout<<"Your opponent had "<<opponent_total<<" cards."<<endl;
	cout <<"You earned $"<<bet<<". You now have $"<<earnings<<"."<<endl;
	finish = true;
}

void display(int count, int &player_total, int &opponent_total, int opponent_starting, int &earnings, int bet){
	
	switch(count){
		case 1:
			player_total += player_card();
			cout<<"Your cards are now : "<<player_total<<endl;
			if(opponent_total < 17)
					opponent_total += opponent_card();
					
			if(player_total > 21){
				if(opponent_total <= 21)
					lose(opponent_total, earnings, bet);
				else if(player_total > opponent_total)
					tie(opponent_total, earnings, bet);
				else if(player_total == opponent_total)
					tie(opponent_total, earnings, bet);
				else if(opponent_total > 21)
					tie(opponent_total, earnings, bet);
				else
					win(opponent_total, earnings, bet);
				break;
			}			
			cout<<"Your opponent's cards are : "<<opponent_starting<<" + ?"<<endl;
			
			break;
			
		case 2:
			
			if(player_total == 21)
				jack(opponent_total, earnings, bet);
			else if((player_total <= 21) && (player_total > opponent_total))
				win(opponent_total, earnings, bet);
			else if(player_total == opponent_total)
				tie(opponent_total, earnings, bet);
			else if(opponent_total > 21)
				win(opponent_total, earnings, bet);
			else
				lose(opponent_total, earnings, bet);
			
			break;
		
		default:
			cout<<"Invalid option entered."<<endl;
			break;
	}
}

void blackJack(){
	cout << endl << "Welcome to Blackjack!" << endl;
	
	do{
		do {
			cout<<"Your total cash is $"<<earnings<<"\nWhat bet would you like to place?:   $";
			cin >> bet;
            cout << endl;
	        if (bet > earnings || bet <= 0) {
	            cout << "Invalid bet. Please enter a valid amount." << endl;
	        } else {
	            earnings -= bet;
	            break;
	        }
	    } 
		while (true);
	    
		while(::count != 2){
			if(point == false){
				srand(time(0));
				starting_cards = (2 + rand()%10) + (2 + rand()%9);
				opponent_starting = 2 + rand()%10;
				opponent_total = opponent_starting + (2 + rand()%9);
				player_total = starting_cards;
			
				cout<<"Your opponent has : "<<opponent_starting<<" + ?"<<endl;
				cout<<"You have : "<<starting_cards<<endl;
			
				point = true;
			}
			if(finish == false){
				cout<<"\nWhat will your next action be?\n";
				cout<<"1. Hit\n";
				cout<<"2. Stand\n";
				cin>>::count;
				display(::count, player_total, opponent_total, opponent_starting, earnings, bet);
			}
			else
				break;
			}
			
		if(earnings == 0){
            cout<<"You're broke now"<<endl;
            break;
		}
		
		cout<<"\nWould you like to continue with black jack?(Y/N)"<<endl;
		cin>>cont;
		
		::count = 0;
		point = false;
		finish = false;
		
	} while(cont == 'Y' || cont == 'y');
}
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
===================================    SlotMachine Definition  =======================================
====================================================================================================*/
void initialize() {
	v.symbol[0] = "@";
	v.points[0] = 1.25;
	
	v.symbol[1] = "$";
	v.points[1] = 1.5;
	
	v.symbol[2] = "+";
	v.points[2] = 2;
	
	v.symbol[3] = "&";
	v.points[3] = 2.5;
	
	v.symbol[4] = "G";
	v.points[4] = 3;
	
	v.symbol[5] = "#";
	v.points[5] = 4;
	
	v.symbol[6] = "%";
	v.points[6] = 5;
	
	v.symbol[7] = "?";
	v.points[7] = 10;
}

void randomizer() {
	srand(time(0));
	slot1 = rand() % 8;
	slot2 = rand() % 8;
	slot3 = rand() % 8;
}

void slotOut() {
	cout << "-----------------" << endl;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			cout << v.symbol[slot1];
		}
		cout << " ";
		for (int i = 0; i < 4; i++) {
			cout << v.symbol[slot2];
		}
		cout << " ";
		for (int i = 0; i < 4; i++) {
			cout << v.symbol[slot3];	
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}

void slotMachine() {
    char choiceSM;
    do{
        double betSM, reward;
        reward = 0;
        initialize();

        cout << endl << "Your total cash is: " << earnings << endl;
        cout << "Welcome to slot machines! enter a value to bet: $";
        cin >> betSM;
        earnings -= betSM;
        for (int i = 45; i < 75; i++) {	
            system("CLS");
            cout << "Welcome to slot machines! enter a value to bet: $" << betSM << endl;
            randomizer();
            slotOut();
            Sleep(i*0.015);
        }
        cout << '\a';
        if (slot1 == slot2) {
            reward = betSM*v.points[slot1];
        }
        if (slot1 == slot3) {
            reward = betSM*v.points[slot1];
        }
        if (slot2 == slot3) {
            reward = betSM*v.points[slot2];
        }
        if (slot1 == slot2 && slot2 == slot3) {
            reward = betSM*v.points[slot1]*10;
            cout << "JACKPOT!" << endl;
        }
        if (reward > 0) {
            cout << "congratulations, you won: $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        } else {
            cout << "You lost: $" << betSM << endl;
            earnings -= reward;
            cout << "Your new balance is: " << earnings << endl;
        }

        cout << endl;
        cout << "Do you want to keep playing slot machine?(Y/N):     ";
        cin >> choiceSM;
        cout << endl;
    }while(choiceSM != 'N');
}
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
===================================     Baccarat Definition    =======================================
====================================================================================================*/
inline void WINBT(double *reward, double *bet) {
	*reward = (*bet) * 1.5;
}

int drawCard() {
	return (rand() % 13) + 1;
}
void outCard(int cardValue) {
	if (cardValue > 1 && cardValue <= 10) {
		cout << cardValue << " ";
	}
	switch(cardValue) 
	{
		case 1:
			cout << "A "; break;
		case 11:
			cout << "J "; break;
		case 12:
			cout << "Q "; break;
		case 13:
			cout << "K "; break;
	}
}

int points(int c1, int c2) {
	int sum;
	if (c1 > 9) {
		c1 = 0;
	}
	if (c2 > 9) {
		c2 = 0;
	}
	sum = c1 + c2;
	if (sum >= 10) {
		sum -= 10;
	}
	return sum;
}

bool needMoreCards(int scoreDealer, int scorePlayer) {
	if (scoreDealer < 3 && scorePlayer != 8) {
		return 1;
	}
	if (scoreDealer = 4 && scorePlayer > 1 && scorePlayer < 8) {
		return 1;
	}
	return 0;
}

void gameEnd(int dealer, int player) {
	cout << "Player score: " << player << endl;
	cout << "Dealer score: " << dealer << endl;
}

int Baccarat() {
	char choiceBT;
    do{
        srand(time(0));
        double bet, reward;
        int card1, card2, card3, player, dealer;
        int winCondition = -1;

        cout << endl << "Your total cash is: " << earnings << endl;

        cout << endl << "Welcome to Baccarat, enter a value to bet: $";
        cin >> bet;
        while (winCondition < 0 || winCondition > 2) {
			cout << "Enter 0 to bet on your own hand: " << endl;
			cout << "Enter 1 to bet on the dealer's hand" << endl;
            cout << "Enter 2 to bet on a draw" << endl;
			cout << "Enter choice: ";

            cin >> winCondition;
            if (winCondition != 1 && winCondition != 0 && winCondition != 2) {
                cout << "Enter a valid number." << endl;
            }
        }

        card1 = drawCard();
        card2 = drawCard();

        cout << endl << "Your hand is: ";
        outCard(card1); outCard(card2); cout << endl;

        player = points(card1, card2);
        dealer = points(drawCard(), drawCard());
        
        if (needMoreCards) {
            cout << "Dealer has drawn an additional card" << endl;
            dealer = points(dealer, drawCard());
        }
        
        gameEnd(dealer,player);
        
        if (dealer == player && winCondition == 2) {
            WINBT(&reward,&bet);
            cout << endl << "You win! $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        }else if (dealer > player && winCondition == 1) {
            WINBT(&reward,&bet);
            cout << endl << "You win! $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        }else if (dealer < player && winCondition == 0) {
            WINBT(&reward,&bet);
            cout << endl << "You win! $" << reward << endl;
            earnings += reward;
            cout << "Your new balance is: " << earnings << endl;
        } else{
			cout << endl << "You lose! $" << bet << " lost"  << endl;
			earnings -= bet;
			cout << "Your new balance is: " << earnings << endl;
		}
        
        cout << "Do you wish to keep on playing Bacarrats?(Y/N):    ";
        cin >> choiceBT;
        cout << endl;
    }while(choiceBT != 'N');
	if(choiceBT == 0)
		return 0;
}
/*====================================================================================================
======================================================================================================
====================================================================================================*/



/*====================================================================================================
==================================        GUI Definition      ========================================
====================================================================================================*/
void welcomeToCasino() {
    cout << endl;

    cout <<"================================================================================================================  \n";
    cout <<"================================================================================================================  \n";
    cout << "W   W EEEEE  L      CCCCC  OOOO  M   M EEEEE     TTTTTT OOOO       CCCCC     A      SSSS   IIIIII NN   N  OOOO   \n";
    cout << "W   W E      L     C      O    O MM MM E           TT  O    O     C         A A    S         II   N N  N O    O  \n";
    cout << "W W W EEE    L     C      O    O M M M EEE         TT  O    O     C        A   A    SSSS     II   N  N N O    O  \n";
    cout << "WW WW E      L     C      O    O M   M E           TT  O    O     C       AAAAAAA       S    II   N   NN O    O  \n";
    cout << "W   W EEEEE  LLLLL  CCCCC  OOOO  M   M EEEEE       TT   OOOO       CCCCC A       A  SSSS   IIIIII N    N  OOOO   \n";
    cout <<"================================================================================================================  \n";
    cout <<"================================================================================================================  \n";
}

void slotMachineRules(){
    cout << "Rules for slot machine." << endl;
    cout << "1. If the 3 lines are different your bet goes to 0." << endl;
    cout << "2. If two of the 3 lines are similar, your bet is going to be multiplied by a random number." << endl;
    cout << "3. If the 3 lines are same, your bet is going to be multiplied by a random number and then x10." << endl;
    cout << "Enjoy :)" << endl;
}

void blackJackRules(){
    cout << "Rule for blackjack." << endl;
    cout << "1. You have 2 options to play the game 'Hit and Stand'." << endl;
    cout << "a. Choosing Hit means that a card will be drawn from the deck between (2 - 11)."<<endl;
    cout << "b. Stand means that dealer's and player's cards will be checked."<<endl;
    cout << "2. The goal is to stay below or on the 21 cards value mark and above the dealer's card value."<<endl;
    cout << "3. If you are to go above the 21 cards mark (going bust) or if the dealer's card value is above yours," << endl;
    cout <<  "   you will lose, and the betted amount will be deducted." << endl;
    cout << "4. In case of equal final scores, or both players going bust, the game will conclude in a tie."<<endl;
}

void baccaratRules(){
    cout << "Rules for Bacarrats." << endl;
	cout << "1. Player and dealer draw a card each." << endl;
	cout << "2. player can bet on dealer's hand, his own hand, or draw." << endl;
	cout << "3. Score is equal to the sum of both cards." << endl;
	cout << "4. If card is 10, J, Q, K than you get 0 points. Other cards have 1-9 value." << endl;
	cout << "5. If sum is larger than 10, than the first number is deleted." << endl;
	cout << "6. Person with the highest score wins." << endl;
}
/*====================================================================================================
======================================================================================================
====================================================================================================*/
