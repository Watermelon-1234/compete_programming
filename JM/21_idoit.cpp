#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 函數用於抽取一張牌，返回牌面數值（1到11之間）
int drawCard() {
    return rand() % 11 + 1;
}

// 函數用於判斷是否爆牌
bool isBusted(int total) {
    return total > 21;
}

int main() {
    // 初始化隨機數生成器
    srand(static_cast<unsigned int>(time(nullptr)));

    int totalScore = 0;
    char choice;

    cout << "歡迎來到21點遊戲！\n";

    do {
        int card = drawCard();
        totalScore += card;

        cout << "您抽到了一張牌，數值為：" << card << endl;
        cout << "目前總分：" << totalScore << endl;

        if (isBusted(totalScore)) {
            cout << "您爆牌了！" << endl;
            break;
        }

        cout << "是否繼續抽牌？(y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "遊戲結束，您的最終得分是：" << totalScore << endl;

    return 0;
}
