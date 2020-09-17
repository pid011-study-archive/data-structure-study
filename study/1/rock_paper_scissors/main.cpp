#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

enum class Card { Scissors, Rock, Paper };

enum class GameResult { Win, Lose, Draw };

class Game {
public:
    Card get_card_of_turn();

protected:
    Card turn;
};

Card Game::get_card_of_turn() {
    return this->turn;
}

class GameAI : public Game {
public:
    GameAI();
    void set_random_card_of_turn();
};

GameAI::GameAI() {
    srand((unsigned)time(NULL));
}

void GameAI::set_random_card_of_turn() {
    int r       = rand() % 3;
    Card result = static_cast<Card>(r);
    this->turn  = result;
}

class Player : public Game {
public:
    void set_card_of_turn(Card playerCard);
};

void Player::set_card_of_turn(Card playerCard) {
    this->turn = playerCard;
}

string card_to_string(Card card) {
    switch (card) {
    case Card::Scissors:
        return "가위";
    case Card::Rock:
        return "바위";
    case Card::Paper:
        return "보";
    }

    return "";
}

//c1과 c2를 비교하여 c1을 기준으로 승부결과 반환
GameResult compare_card(Card c1, Card c2) {
    if (c1 == c2) {
        return GameResult::Draw;
    }
    bool result = false;

    switch (c1) {
    case Card::Scissors:
        result = c2 == Card::Paper;
        break;
    case Card::Rock:
        result = c2 == Card::Scissors;
        break;
    case Card::Paper:
        result = c2 == Card::Rock;
        break;
    }

    return result ? GameResult::Win : GameResult::Lose;
}

int main() {
    GameAI* ai     = new GameAI;
    Player* player = new Player;

    while (true) {
        cout << "가위바위보! 무엇을 낼건가요?" << endl;
        cout << "1. 가위, 2. 바위, 3. 보" << endl;
        cout << "> ";

        int input = 0;
        cin >> input;

        player->set_card_of_turn(static_cast<Card>(input - 1));
        Sleep(1000);
        cout << "가위...";
        Sleep(1000);
        cout << "바위...";
        Sleep(1000);
        cout << "보!" << endl;
        Sleep(1000);
        ai->set_random_card_of_turn();

        cout << "플레이어 : " << card_to_string(player->get_card_of_turn()) << endl;
        cout << "컴퓨터 : " << card_to_string(ai->get_card_of_turn()) << endl;

        GameResult result = compare_card(player->get_card_of_turn(), ai->get_card_of_turn());
        switch (result) {
        case GameResult::Win:
            cout << "승!";
            break;
        case GameResult::Lose:
            cout << "패배...";
            break;
        case GameResult::Draw:
            cout << "비겼습니다.";
            break;
        }

        cout << "\n\n";
        cout << "다시 하시겠습니까? (y/n)" << endl << "> ";
        string retry;
        getline(cin, retry);

        if (retry != "y") {
            break;
        }
    }

    delete ai;
    delete player;
}
