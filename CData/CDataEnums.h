#ifndef PKMNPATTERNREDESIGN_CDATAENUMS_H
#define PKMNPATTERNREDESIGN_CDATAENUMS_H

enum class Stage { BASIC,
                   STAGE_1,
                   STAGE_2 };


enum class OwnerID { PLAYER_1 = 100000,
                     PLAYER_2 = 200000 };


enum class ZoneName { BASE,
                      DECK,
                      HAND,
                      DISCARD,
                      PRIZES,
                      ACTIVE,
                      BENCH,
                      ATTACHED };


#endif //PKMNPATTERNREDESIGN_CDATAENUMS_H
