#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

class Card 
{
    public:
	int number;
	int index;
};

class Deck 
{
    public:
	Card cards[52];
	Deck() {
		int num = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 2; j <= 14; j++) {
				this->cards[num].index = i;
				this->cards[num].number = j;
				num++;
			}
		}
	}
};

const string suits[4] = { "Clubs", "Diamonds", "Hearts", "Spade" };

class Players {
public:
	string name;
	vector<Card> inHand;
};

void ShuffleDeck(int shuffleIndex[52])
{
	for (int i = 0; i < 52; i++) {
		shuffleIndex[i] = i;
	}
	random_shuffle(shuffleIndex, shuffleIndex + 52);
}

void DistributeCards(Players participants[4], Deck deck, int shuffleIndex[52])
{
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card tempCard;
			participants[i].inHand.push_back(tempCard);
			participants[i].inHand[j].index = deck.cards[shuffleIndex[count]].index;
			participants[i].inHand[j].number = deck.cards[shuffleIndex[count]].number;;
			count++;
		}
	}
}

void DisplayCardsPlayed(vector<Card>& cardsPlayed, int playerTurnIndex, vector<int>& playersPlayed)
{
	cout << "Cards Played:" << endl;
	for (int i = 0; i < playersPlayed.size(); i++) {
		switch (cardsPlayed[playersPlayed[i]].number) {
			case 11:
				cout << "Jack" << " of " << suits[cardsPlayed[playersPlayed[i]].index];
				break;
			case 12:
				cout << "Queen" << " of " << suits[cardsPlayed[playersPlayed[i]].index];
				break;
			case 13:
				cout << "King" << " of " << suits[cardsPlayed[playersPlayed[i]].index];
				break;
			case 14:
				cout << "Ace" << " of " << suits[cardsPlayed[playersPlayed[i]].index];
				break;
			default:
				cout << cardsPlayed[playersPlayed[i]].number << " of " << suits[cardsPlayed[playersPlayed[i]].index];
				break;
		}
        cout<<endl;
	}
	cout << "\n";
}

void DisplayPlayerCards(Players players[4], int playerTurnIndex)
{
	cout << "Cards you have:" << endl;
	for (int i = 0; i < players[playerTurnIndex].inHand.size(); i++) {
		switch (players[playerTurnIndex].inHand[i].number) {
			case 11:
				cout << i+1 << ") " << "Jack" << " of " << suits[players[playerTurnIndex].inHand[i].index] << endl;
				break;
			case 12:
				cout << i+1 << ") " << "Queen" << " of " << suits[players[playerTurnIndex].inHand[i].index] << endl;
				break;
			case 13:
				cout << i+1 << ") " << "King" << " of " << suits[players[playerTurnIndex].inHand[i].index] << endl;
				break;
			case 14:
				cout << i+1 << ") " << "Ace" << " of " << suits[players[playerTurnIndex].inHand[i].index] << endl;
				break;
			default:
				cout << i+1 << ") " << players[playerTurnIndex].inHand[i].number << " of " << suits[players[playerTurnIndex].inHand[i].index] << endl;
				break;
		}
	}
	cout << "\n";
}

void PlayCard(vector<Card>& cardsPlayed, int playerTurnIndex, Players players[4], int cardChoiceIndex)
{
	cardsPlayed[playerTurnIndex].index = players[playerTurnIndex].inHand[cardChoiceIndex].index;
	cardsPlayed[playerTurnIndex].number = players[playerTurnIndex].inHand[cardChoiceIndex].number;
	players[playerTurnIndex].inHand.erase(players[playerTurnIndex].inHand.begin() + cardChoiceIndex);
}

void CheckHighest(vector<Card>& cardsPlayed, int activeSuitIndex, int& highestIndex)
{
	int highest = 0;
	for (int i = 0; i < 4; i++) {
		if (cardsPlayed[i].index == activeSuitIndex && cardsPlayed[i].number > highest) {
			highest = cardsPlayed[i].number;
			highestIndex = i;
		}
	}
}

void DisplayScore(int score[4], Players players[4])
{
	cout << "Scores: " << endl;
	for (int i = 0; i < 4; i++) {
		cout << players[i].name << " : " << score[i] << endl;
	}
}

void DisplayWinner(int score[4], Players players[4])
{
	int highest = 0, winnerIndex;
	for (int i = 0; i < 4; i++) {
		if (score[i] > highest) {
			highest = score[i];
			winnerIndex = i;
		}
	}
	cout << "Winner: " << players[winnerIndex].name << endl;
}


int main() {
	Deck deck;
	Players players[4];
	int shuffleIndex[52], score[] = {0,0,0,0}, a = 0, index[] = { 1,3,0,2 };
	vector<Card> cardsPlayed;
	vector<int> playersPlayed;
	char okay, ready;

	for (int i = 0; i < 4; i++) {
		Card tempcard;
		tempcard.index = 0;
		tempcard.number = 0;
		cardsPlayed.push_back(tempcard);
	}

	for (int i = 0; i < 4; i++) {
		cout << "Enter Player " << i+1 << " name: ";
		cin >> players[i].name;
		system("CLS");
	}

	ShuffleDeck(shuffleIndex);
	DistributeCards(players, deck, shuffleIndex);

	while (a < 13) {
		int playerTurnIndex, activeSuitIndex, cardChoiceIndex, highestIndex;
		bool firstPlay = true;
		for (int i = 0; i < 4; i++) {
			playerTurnIndex = index[i];

			if (!firstPlay)
				DisplayCardsPlayed(cardsPlayed, playerTurnIndex, playersPlayed);

			cout << players[playerTurnIndex].name << "'s turn!" << "\n" << endl;
			cout << "Enter S to show cards: " << endl;
			cin >> ready;
			DisplayPlayerCards(players, playerTurnIndex);
			cout << "\nChoose a card to play (enter the number next to the card): " << endl;
			cin >> cardChoiceIndex;

			if (firstPlay)
				activeSuitIndex = players[playerTurnIndex].inHand[cardChoiceIndex].index;

			PlayCard(cardsPlayed, playerTurnIndex, players, cardChoiceIndex-1);

			system("CLS");
			firstPlay = false;
			playersPlayed.push_back(playerTurnIndex);
		}

		playersPlayed.clear();

		CheckHighest(cardsPlayed, activeSuitIndex, highestIndex);
		score[highestIndex]++;
		DisplayScore(score, players); 

		random_shuffle(index, index + 4);
		cout << "\n" << "Enter C continue" << endl;
		cin >> okay;

		system("CLS");

		a++;
	}

	DisplayWinner(score, players);

	return 0;
}

