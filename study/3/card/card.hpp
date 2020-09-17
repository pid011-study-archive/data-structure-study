#pragma once
#include <string>

namespace Card {
    enum class CardSuit { Spade, Diamond, Heart, Club };

    enum class CardNumber { Ace, N2, N3, N4, N5, N6, N7, N8, N9, N10, Jack, Queen, King };

    std::string to_string(CardSuit suit);
    std::string to_string(CardNumber number);

    class CardInfo {
    public:
        const CardSuit _suit;
        const CardNumber _number;

        CardInfo(CardSuit suit, CardNumber number, bool is_front = true)
            : _suit(suit), _number(number) {
            _is_front = is_front;
        }

        void flip();
        bool get_card_is_front();

    private:
        bool _is_front;
    };
}
