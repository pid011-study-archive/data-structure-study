
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

enum class Card
{
    Scissors,
    Rock,
    Paper
};

enum class GameResult
{
    Win,
    Lose,
    Draw
};

class Game
{
public:
    Card get_card_of_turn();

protected:
    Card turn;
};

Card Game::get_card_of_turn()
{
    return this->turn;
}

class GameAI : public Game
{
public:
    GameAI();
    void set_random_card_of_turn();
};

GameAI::GameAI()
{
    srand((unsigned)time(NULL));
}

void GameAI::set_random_card_of_turn()
{
    int r = rand() % 3;
    Card result = static_cast<Card>(r);
    this->turn = result;
}

class Player : public Game
{
public:
    void set_card_of_turn(Card playerCard);
};

void Player::set_card_of_turn(Card playerCard)
{
    this->turn = playerCard;
}

string card_to_string(Card card)
{
    switch (card)
    {
    case Card::Scissors:
        return "����";
    case Card::Rock:
        return "����";
    case Card::Paper:
        return "��";
    }

    return "";
}

//c1�� c2�� ���Ͽ� c1�� �������� �ºΰ�� ��ȯ
GameResult compare_card(Card c1, Card c2)
{
    if (c1 == c2)
    {
        return GameResult::Draw;
    }
    bool result = false;

    switch (c1)
    {
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

int main()
{
    GameAI* ai = new GameAI;
    Player* player = new Player;

    while (true)
    {
        cout << "����������! ������ ���ǰ���?" << endl;
        cout << "1. ����, 2. ����, 3. ��" << endl;
        cout << "> ";

        int input = 0;
        cin >> input;

        player->set_card_of_turn(static_cast<Card>(input - 1));
        Sleep(1000);
        cout << "����...";
        Sleep(1000);
        cout << "����...";
        Sleep(1000);
        cout << "��!" << endl;
        Sleep(1000);
        ai->set_random_card_of_turn();

        cout << "�÷��̾� : " << card_to_string(player->get_card_of_turn()) << endl;
        cout << "��ǻ�� : " << card_to_string(ai->get_card_of_turn()) << endl;

        GameResult result = compare_card(player->get_card_of_turn(), ai->get_card_of_turn());
        switch (result)
        {
        case GameResult::Win:
            cout << "��!";
            break;
        case GameResult::Lose:
            cout << "�й�...";
            break;
        case GameResult::Draw:
            cout << "�����ϴ�.";
            break;
        }
        cout << "\n\n";
        cout << "�ٽ� �Ͻðڽ��ϱ�? (y/n)" << endl
            << "> ";
        string retry;
        getline(cin, retry);
        if (retry != "y")
        {
            break;
        }
    }

    delete ai;
    delete player;
}
