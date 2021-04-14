/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

/**
* Exception for trying to exceed max or min number of players
*/
class game_limit_error : public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit game_limit_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for a name that is too long, already taken, or is not a name
*/
class invalid_name_error : public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_name_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for attempting to remove a card that does not exist in Hand
*/
class invalid_card_error : public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_card_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

#endif // EXCEPTIONS_H
