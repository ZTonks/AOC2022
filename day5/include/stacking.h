#ifndef STACKING_H
#define STACKING_H

#define NUM_STACKS 9
#define MAX_STACK_HEIGHT 50
#define INITIAL_MAX_STACK_HEIGHT 8
#define LINE_TERMINATOR '\0'

struct TOPOFSTACK {
    int index;
    char item;
};

struct REARRANGEMENT {
    int numBlocks;
    int stackFromIndex;
    int stackToIndex;
};

int getTopOfStack(char stack[MAX_STACK_HEIGHT], struct TOPOFSTACK* topOfStack);
int rearrange(char stacks[NUM_STACKS][MAX_STACK_HEIGHT], struct REARRANGEMENT* rearrangement);
int parseMove(char stacks[NUM_STACKS][MAX_STACK_HEIGHT], char* line, int lineLength, struct REARRANGEMENT* rearrangement);
int parseStackLine(char stacks[NUM_STACKS][MAX_STACK_HEIGHT], char* line, int read, int lineNo);

#endif
