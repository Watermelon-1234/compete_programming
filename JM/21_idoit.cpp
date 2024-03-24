#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ��ƥΩ����@�i�P�A��^�P���ƭȡ]1��11�����^
int drawCard() {
    return rand() % 11 + 1;
}

// ��ƥΩ�P�_�O�_�z�P
bool isBusted(int total) {
    return total > 21;
}

int main() {
    // ��l���H���ƥͦ���
    srand(static_cast<unsigned int>(time(nullptr)));

    int totalScore = 0;
    char choice;

    cout << "�w��Ө�21�I�C���I\n";

    do {
        int card = drawCard();
        totalScore += card;

        cout << "�z���F�@�i�P�A�ƭȬ��G" << card << endl;
        cout << "�ثe�`���G" << totalScore << endl;

        if (isBusted(totalScore)) {
            cout << "�z�z�P�F�I" << endl;
            break;
        }

        cout << "�O�_�~���P�H(y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "�C�������A�z���̲ױo���O�G" << totalScore << endl;

    return 0;
}
