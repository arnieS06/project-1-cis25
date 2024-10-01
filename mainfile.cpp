#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


string cardToString(int card);
int cardValue(int card);

// functiton makes the random card numbers from 1 - 13
int drawHand(string playerType) {
    int firstCard = (rand() % 13) + 1;
    int secondCard = (rand() % 13) + 1;

    cout << playerType << "'s first card was " << cardToString(firstCard) << endl;
    cout << playerType << "'s second card was " << cardToString(secondCard) << endl;

    return cardValue(firstCard) + cardValue(secondCard);
}

string cardToString(int card) {
    switch (card) {
        case 1: 
            return "A";
        case 11: 
            return "J";
        case 12: 
            return "Q";
        case 13: 
            return "K";
        default: 
            return to_string(card);
    }
}
// this function ill use to assign card values
// some cards are worth a letter
int cardValue(int card) {
    if (card == 1) {
        return 11;
    }
    
    else if(card > 10) {
        return 10;
    }

    else {
        return card;
    }

}

void findWinner(int playerSum, int dealerSum, string playerName) {
    //using this function to find final winner 
    cout << "\n Total player: " << playerSum << endl;
    cout << "Total Dealer: " << dealerSum << endl;

    if (playerSum > dealerSum) {
        cout << playerName << " wins!" << endl;
    }

    else if (dealerSum > playerSum) {
        cout << "Dealer wins!" << endl;
    }

    else {
        cout << "Draw, no one wins." << endl;
    }
}

int main() {

    // ask for input 
    // draw hand
    // use card value and assign values to all drawn cards
    // see if cards could have special values like letters
    // compare sum of cards
    // find the winner for that round
    // ask them to play again?
    // break the program if they say no

    
    srand(time(0));

    bool playAgain = true;
    string player;

    while (playAgain) {
        cout << "Welcome to blackjack, please enter your name -> ";
        getline(cin, player);

        cout << "\n" << player << "'s hand: \n";
        int playerSum = drawHand(player);

        if (playerSum == 21) {
            cout << "\n Blackjack!!";
        }

        cout << "\nDealer's hand: \n";
        int dealerSum = drawHand("Dealer");

        if (dealerSum == 21) {
        cout << "Dealer has gotten blackjack!\n";
        } 

        // finding the winner 

        findWinner(playerSum, dealerSum, player);

        cout << "\n Wanna play one more time? (Y/N): ";
        string playerResponse;
        getline(cin, playerResponse);
        if (playerResponse != "Y" && playerResponse != "y") {
            playAgain = false;
            cout << "come play again next time!" << endl;
        }
    }    



    
}

