#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 定義牌的結構
struct Card {
    string suit;
    string rank;
    int value;
};

// 初始化牌堆
vector<Card> initializeDeck() {
    vector<Card> deck;
    string suits[] = {"方塊", "梅花", "紅心", "黑桃"};
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

// 洗牌
void shuffleDeck(vector<Card> &deck) {
    srand(time(nullptr));
    for (int i = 0; i < deck.size(); ++i) {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}

// 發牌
Card dealCard(vector<Card> &deck) {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// 主遊戲函數
void playGame() {
    vector<Card> deck = initializeDeck();
    shuffleDeck(deck);

    // 初始化玩家和莊家的手牌
    vector<Card> playerHand;
    vector<Card> dealerHand;

    // 發兩張牌給玩家和莊家
    playerHand.push_back(dealCard(deck));
    playerHand.push_back(dealCard(deck));

    dealerHand.push_back(dealCard(deck));
    dealerHand.push_back(dealCard(deck));

    // 玩家的回合
    while (true) {
        // 顯示玩家手中的牌和分數
        cout << "玩家的手牌: ";
        for (const auto &card : playerHand) {
            cout << card.rank << card.suit << " ";
        }
        int playerScore = 0;
        for (const auto &card : playerHand) {
            playerScore += card.value;
        }
        cout << "分數: " << playerScore << endl;

        // 詢問玩家是否要牌
        string choice;
        cout << "是否要牌? (y/n): ";
        cin >> choice;

        if (choice == "y") {
            playerHand.push_back(dealCard(deck));
            // 檢查玩家是否爆牌
            if (playerScore > 21) {
                cout << "玩家爆牌！莊家勝利。" << endl;
                return;
            }
        } else {
            break;
        }
    }
}

int main() {
    cout << "歡迎來到21點遊戲！" << endl;
    playGame();
    return 0;
}
