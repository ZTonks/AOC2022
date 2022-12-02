#ifndef RPS_ENUMS_H
#define RPS_ENUMS_H

#define POINTS_FACTOR 3

enum RPS_OPPONENT {
    OPP_ROCK = 0,
    OPP_PAPER = 1,
    OPP_SCISSORS = 2
};

enum RPS_PLAYED {
    PLAY_ROCK = 0,
    PLAY_PAPER = 1,
    PLAY_SCISSORS = 2
};

enum RPS_AIM {
    AIM_LOSE = 0,
    AIM_DRAW = 1,
    AIM_WIN = 2
};

struct AIM_PLAY {
    enum RPS_AIM aim;
    enum RPS_PLAYED play;
};

enum POINTS {
    LOSS = 0,
    DRAW = POINTS_FACTOR,
    WIN = POINTS_FACTOR * 2
};

#endif
