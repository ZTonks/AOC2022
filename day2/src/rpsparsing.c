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

enum RPS_PLAYED parsePlayer(
    char play
) {
    switch (play) {
        case 'X':
            return PLAY_ROCK;
        case 'Y':
            return PLAY_PAPER;
        case 'Z':
            return PLAY_SCISSORS;
        default:
            return 0;
    }
}

enum POINTS evaluateWin(
    enum RPS_PLAYED play,
    enum RPS_OPPONENT opponent
) {
   if ((int)opponent == (int)play) {
    return DRAW;
   } else if (opponent % MODULUS == (play + 1) % MODULUS) {
    return LOSS;
   } else if ((opponent + 1) % MODULUS == play % MODULUS) {
    return WIN;
   } else {
    return -1;
   }
}
