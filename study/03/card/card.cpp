#include "card.hpp"

std::string Card::to_string(CardSuit suit) {
    switch (suit) {
    case Card::CardSuit::Spade:
        return "Spade";
    case Card::CardSuit::Diamond:
        return "Diamond";
    case Card::CardSuit::Heart:
        return "Heart";
    case Card::CardSuit::Club:
        return "Club";
    default:
        return "Unknown";
    }
}

std::string Card::to_string(CardNumber number) {
    switch (number) {
    case Card::CardNumber::Ace:
        return "A";
    case Card::CardNumber::N2:
        return "2";
    case Card::CardNumber::N3:
        return "3";
    case Card::CardNumber::N4:
        return "4";
    case Card::CardNumber::N5:
        return "5";
    case Card::CardNumber::N6:
        return "6";
    case Card::CardNumber::N7:
        return "7";
    case Card::CardNumber::N8:
        return "8";
    case Card::CardNumber::N9:
        return "9";
    case Card::CardNumber::N10:
        return "10";
    case Card::CardNumber::Jack:
        return "J";
    case Card::CardNumber::Queen:
        return "Q";
    case Card::CardNumber::King:
        return "K";
    default:
        return "Unknown";
    }
}

void Card::CardInfo::flip() {
    _is_front = !_is_front;
}

bool Card::CardInfo::get_card_is_front() {
    return _is_front;
}
