#include <iostream>
#include <cstlib>
#include <ctime>
#include <string>
using namespace std;


// functiton makes the random card numbers from 1 - 13
int drawHand(string playerType) {
    int firstCard = (rand() % 13) + 1;
    int secondCard = (rand() % 13) + 1;

    
}

string cardToString(int card) {
// thinking of using switch statement so far

}
// this function ill use to assign card values
// some cards are worth a letter
int cardValue(int card) {


}

void findWinner(int playerSum, int dealerSum, string playerName) {
    //using this function to find final winner i dont need a return type yet
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
}

