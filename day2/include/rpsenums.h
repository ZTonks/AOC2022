#ifndef RPS_ENUMS_H
#define RPS_ENUMS_H

#define POINTS_FACTOR 3

enum RPS_OPPONENT {
    OPP_ROCK = 1,
    OPP_PAPER = 2,
    OPP_SCISSORS = 3
};

enum RPS_PLAYED {
    PLAY_ROCK = 1,
    PLAY_PAPER = 2,
    PLAY_SCISSORS = 3
};

enum POINTS {
    LOSS = 0,
    DRAW = POINTS_FACTOR,
    WIN = POINTS_FACTOR * 2
};

#endif
