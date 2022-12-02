#include<rpsenums.h>

#ifndef RPS_PARSING_H
#define RPS_PARSING_H

enum RPS_OPPONENT parseOpponent(char play);
struct AIM_PLAY* parsePlayer(enum RPS_OPPONENT opponentPlay, char intention, struct AIM_PLAY* aimPlay);
enum POINTS evaluatePoints(struct AIM_PLAY* aimPlay);

#endif
