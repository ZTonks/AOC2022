#include<rpsenums.h>

#ifndef RPS_PARSING_H
#define RPS_PARSING_H

enum RPS_OPPONENT parseOpponent(char play);
enum RPS_PLAYED parsePlayer(char play);
enum POINTS evaluateWin(enum RPS_PLAYED play, enum RPS_OPPONENT opponent);

#endif
