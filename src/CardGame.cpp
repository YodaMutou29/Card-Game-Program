/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include "CardGame.h"
#include "GoFish.h"

Card* CardGame::pickUpCard() {
  Card* card = gameDeck->getTopCard();
  gameDeck->getCurrentDeck().pop_back();
  //gameDeck->setTopCard(gameDeck->getCurrentDeck().back());
  return card;
}

bool CardGame::cardInHand(Player* p, Card* c) {
  return p->getCurrentHand().checkForCard(c);
}
