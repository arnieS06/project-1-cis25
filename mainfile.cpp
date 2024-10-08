#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
using namespace std;

string cardToString(int card);
int cardValue(int card);

// this functiton draws random card numbers from 1 - 13,
// prints the first and second card,
// and gives a sum of the player's cards
int drawHand(string playerType) {
    int firstCard = (rand() % 13) + 1;
    int secondCard = (rand() % 13) + 1;

    cout << playerType << "'s first card was " << cardToString(firstCard) << endl;
    cout << playerType << "'s second card was " << cardToString(secondCard) << endl;

    return cardValue(firstCard) + cardValue(secondCard);
}


// this function is for special cases where some 
// numbered cards have special values like "ace", etc.
string cardToString(int card) {
    switch (card) {
        case 1: 
            return "Ace";
        case 11: 
            return "JACK";
        case 12: 
            return "Queen";
        case 13: 
            return "King";
        default: 
            return to_string(card);
    }
}

// this function assigns specific numerical values
// to cards that exceet a certain limit
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

// this function uses logic to find if the
// player or dealer won the round 
void findWinner(int playerSum, int dealerSum, string playerName, bool &playerWin) {
    //using this function to find final winner 
    cout << "\nSum of player's cards: " << playerSum << endl;
    cout << "Sum of dealer's cards: " << dealerSum << endl;

    if (playerSum > dealerSum) {
        cout << playerName << " wins!" << endl;
        playerWin = true;
    }

    else if (dealerSum > playerSum) {
        cout << "Dealer wins!" << endl;
    }

    else if (playerSum > 21) {
        cout << "It looks like your hand exceeds 21, you lose. bad luck." << endl;
    }

    else {
        cout << "Draw, no one wins." << endl;
    }
}


// this function finds out if the player wins
// or loses money based on their match outcome
void betWinner(int playerBet, bool playerWin) {
    if (playerWin) {
        cout << "\nLooks like the dealer owes you your money,\n";
        cout << "go and get the " << playerBet << "$ you won!" << endl;
    }

    else {
        cout << "\nSeems like you won no money,\n";
        cout << "you must've drawn or lost the round.\n";
        cout << "Time to pay the dealer " << playerBet << "$" << endl;
    }
}


// calling all functions and game logic
int main() {
    
    srand(time(0));

    bool playAgain = true;
    bool playerWin;
    string player;
    string playerResponse;
    int playerBet;


    while (playAgain) {
        playerWin = false;

        cout << "Welcome to blackjack, please enter your name -> ";
        getline(cin, player);

        cout << "How many $ do you wanna bet that you'll win this round? -> ";
        cin >> playerBet;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n" << player << "'s hand: \n";
        int playerSum = drawHand(player);


        cout << "\nDealer's hand: \n";
        int dealerSum = drawHand("Dealer");
 

        // finding the winner of the match
        findWinner(playerSum, dealerSum, player, playerWin);

        if (playerSum == 21) {
            cout << "\n Blackjack!!";
            playerWin = true;
        }

        if (dealerSum == 21) {
            cout << "Dealer has gotten blackjack!\n";
        }


        // finding the winner of the bet the player placed
        betWinner(playerBet, playerWin);

        // asking player if they wanna play again
        cout << "\n Wanna play one more time? (Y/N): ";
        getline(cin, playerResponse);
        
        if (playerResponse != "Y" && playerResponse != "y") {
            playAgain = false;
            cout << "come play again next time!" << endl;
        }
    }    


    
}