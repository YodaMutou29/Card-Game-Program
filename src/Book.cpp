#include "Book.h"
#include "Card.h"

Book::Book(Card* c) {
  card = c;
}

Book::~Book() {}

Card* Book::getCard() {
  return card;
}
