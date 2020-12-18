#include "GameMap.h"
#include "GameObject.h"
#include "GameObjectList.h"
#include "Item.h"
#include "Snake.h"
#include "Tail.h"
#include "util.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>

struct Pos {
    int x;
    int y;
};

int getRandomNumber(int max) {
    // 시드값을 얻기 위한 random_device 생성.
    static std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    static std::mt19937 gen(rd());

    // 0 부터 max - 1 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> dis(0, max - 1);

    // 랜덤 값 생성
    int r = dis(gen);
    return r;
}

/**
 * @brief 위치들이 겹치지 않는지 확인
 * @param target 확인할 대상 위치
 * @param excepts_count 겹치면 안되는 위치들의 갯수
 * @param excepts 겹치면 안되는 위치들
 * @return 안겹치면 true, 겹치면 false
*/
bool isPositionNotOverlaped(const Pos& target, const int excepts_count, const Pos* excepts) {
    for (int i = 0; i < excepts_count; i++) {
        const Pos& except = excepts[i];

        if (target.x == except.x && target.y == except.y) {
            return false;
        }
    }

    return true;
}

/**
 * @brief 스네이크 몸통 위치 리스트를 반환한다.
 * @param snake 스네이크
 * @return 스네이크 몸통 위치 리스트
*/
std::vector<Pos> getExecptPos(Snake& snake) {
    auto* tails = snake.getList();
    std::vector<Pos> excepts;
    for (int i = 0; i < tails->getCount(); i++) {
        auto* tail = tails->retrieve(i);
        excepts.push_back(Pos { tail->getX(), tail->getY() });
    }

    return excepts;
}

/**
 * @brief 스네이크와 겹치지 않는 아이템의 위치를 반환
 * @param mapSize 맵 크기 x = widht, y = height
 * @param snake 스네이크
 * @return 스네이크와 겹치지 않는 위치
*/
Pos getRandomItemPosition(const Pos& mapSize, Snake& snake) {
    Pos rp;
    bool check = false;

    do {
        rp.x = getRandomNumber(mapSize.x);
        rp.y = getRandomNumber(mapSize.y);
        std::vector<Pos> excepts = getExecptPos(snake);
        check = isPositionNotOverlaped(rp, excepts.size(), &excepts[0]);
    } while (!check);

    return rp;
}

/**
 * @brief 스네이크와 아이템이 부딪혔는가
 * @param snake 
 * @param item 
 * @return 
*/
bool isCollideSnakeAndItem(Snake& snake, Item& item) {
    auto* head = snake.getList()->retrieve(0);

    return (head->getX() == item.getX()) && (head->getY() == item.getY());
}

/**
 * @brief 스네이크와 벽이 부딪혔는가
 * @param snake 
 * @param mapSize 
 * @return 
*/
bool isCollideSnakeAndWall(Snake& snake, Pos& mapSize) {
    auto* head = snake.getList()->retrieve(0);

    return head->getX() <= 0
           || head->getX() >= mapSize.x
           || head->getY() <= 0
           || head->getY() >= mapSize.y;
}

/**
 * @brief 스네이크가 자기 몸통에 부딪혔는가
 * @param snake 
 * @return 
*/
bool isCollideSnakeItSelf(Snake& snake) {
    auto* head = snake.getList()->retrieve(0);
    for (int i = 1; i < snake.getList()->getCount(); i++) {
        auto* tail = snake.getList()->retrieve(i);
        if (head->getX() == tail->getX() && head->getY() == tail->getY()) {
            return true;
        }
    }

    return false;
}

int main() {
    constexpr int Width = 30;
    constexpr int Height = 30;

    GameMap* map = new GameMap();
    map->initMap();
    Pos mapSize { map->getWidth(), map->getHeight() };

    Snake* snake = new Snake();
    auto excepts = getExecptPos(*snake);
    const auto item_pos = getRandomItemPosition(mapSize, *snake);
    Item item(item_pos.x, item_pos.y);

    ScreenInit();

    bool is_stop = false;
    Pos snake_last_pos;
    while (!is_stop) {
        ScreenClear();

        int input_key;
        if (_kbhit()) {
            input_key = _getch();
            switch (input_key) {
            case UP:
                snake->setDir(0);
                break;
            case DOWN:
                snake->setDir(1);
                break;
            case LEFT:
                snake->setDir(2);
                break;
            case RIGHT:
                snake->setDir(3);
                break;
            default:
                break;
            }
        }

        auto* last = snake->getList()->retrieve(snake->getList()->getCount() - 1);
        snake_last_pos = Pos {
            last->getX(), last->getY()
        };
        snake->update();

        if (isCollideSnakeAndItem(*snake, item)) {
            auto* tails = snake->getList();
            auto* last = tails->retrieve(tails->getCount() - 1);
            tails->append(new Tail(snake_last_pos.x, snake_last_pos.y));
            const auto pos = getRandomItemPosition(mapSize, *snake);
            item.setXY(pos.x, pos.y);
        }

        if (isCollideSnakeAndWall(*snake, mapSize) && isCollideSnakeItSelf(*snake)) {
            ScreenPrint(mapSize.x + 1, 1, L"Game Over!");
            is_stop = true;
        }

        // map->draw();
        snake->draw();
        item.draw(0);
        Sleep(100);
        ScreenFlipping();
    }
    ScreenRelease();
}
