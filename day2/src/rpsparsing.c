#include<stdio.h>

#include<rpsenums.h>

#define MODULUS 3

enum RPS_OPPONENT parseOpponent(
    char play
) {
    switch (play) {
        case 'A':
            return OPP_ROCK;
        case 'B':
            return OPP_PAPER;
        case 'C':
            return OPP_SCISSORS;
        default:
            return 0;
    }
}

struct AIM_PLAY* parsePlayer(
    enum RPS_OPPONENT opponentPlay,
    char intention,
    struct AIM_PLAY* aimPlay
) {
    switch (intention) {
        case 'X':
            aimPlay->aim = AIM_LOSE;
            aimPlay->play = (opponentPlay + MODULUS + 2) % MODULUS;
            break;
        case 'Y':
            aimPlay->aim = AIM_DRAW;
            aimPlay->play = (int)opponentPlay;
            break;
        case 'Z':
            aimPlay->aim = AIM_WIN;
            aimPlay->play = (opponentPlay + 1) % MODULUS;
            break;
        default:
            return NULL;
    }
    return aimPlay;
}

enum POINTS evaluatePoints(
    struct AIM_PLAY* aimPlay
) {
    return aimPlay->play + 1 + aimPlay->aim * POINTS_FACTOR;
}
