#ifndef BOOK_H
#define BOOK_H

#include "Card.h"

class Book {
 public:
  Book(Card*);
  ~Book();

  Card* getCard();

 private:
  Card* card;
};
#endif
