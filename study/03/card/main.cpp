#include "card.hpp"

#include <iostream>

int main() {
    using namespace Card;
    using std::cout;

    CardInfo my_card = CardInfo(CardSuit::Club, CardNumber::Ace);
    my_card.flip();

    cout << to_string(my_card._suit) << " - " << to_string(my_card._number) << " - "
         << (my_card.get_card_is_front() ? "front" : "back") << '\n';
}
