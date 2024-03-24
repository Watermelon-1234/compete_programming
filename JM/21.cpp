#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// �w�q�P�����c
struct Card {
    string suit;
    string rank;
    int value;
};

// ��l�ƵP��
vector<Card> initializeDeck() {
    vector<Card> deck;
    string suits[] = {"���", "����", "����", "�®�"};
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    for (const auto &suit : suits) {
        for (int i = 0; i < 13; ++i) {
            Card card = {suit, ranks[i], values[i]};
            deck.push_back(card);
        }
    }

    return deck;
}

// �~�P
void shuffleDeck(vector<Card> &deck) {
    srand(time(nullptr));
    for (int i = 0; i < deck.size(); ++i) {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}

// �o�P
Card dealCard(vector<Card> &deck) {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// �D�C�����
void playGame() {
    vector<Card> deck = initializeDeck();
    shuffleDeck(deck);

    // ��l�ƪ��a�M���a����P
    vector<Card> playerHand;
    vector<Card> dealerHand;

    // �o��i�P�����a�M���a
    playerHand.push_back(dealCard(deck));
    playerHand.push_back(dealCard(deck));

    dealerHand.push_back(dealCard(deck));
    dealerHand.push_back(dealCard(deck));

    // ���a���^�X
    while (true) {
        // ��ܪ��a�⤤���P�M����
        cout << "���a����P: ";
        for (const auto &card : playerHand) {
            cout << card.rank << card.suit << " ";
        }
        int playerScore = 0;
        for (const auto &card : playerHand) {
            playerScore += card.value;
        }
        cout << "����: " << playerScore << endl;

        // �߰ݪ��a�O�_�n�P
        string choice;
        cout << "�O�_�n�P? (y/n): ";
        cin >> choice;

        if (choice == "y") {
            playerHand.push_back(dealCard(deck));
            // �ˬd���a�O�_�z�P
            if (playerScore > 21) {
                cout << "���a�z�P�I���a�ӧQ�C" << endl;
                return;
            }
        } else {
            break;
        }
    }
}

int main() {
    cout << "�w��Ө�21�I�C���I" << endl;
    playGame();
    return 0;
}
