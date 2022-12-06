#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

#include<stacking.h>

#define MAX_MOVE_DIGITS 2

int getTopOfStack(
    char stack[MAX_STACK_HEIGHT],
    struct TOPOFSTACK* topOfStack)
{
    if (stack[0] == LINE_TERMINATOR) {
        topOfStack->index = -1;
        return 0;
    }

    int i;
    for (i = 1; i < MAX_STACK_HEIGHT; i++) {
        int lastIndex = i - 1;
        char currentChar = stack[lastIndex];
        if (currentChar != LINE_TERMINATOR && stack[i] == LINE_TERMINATOR) {
            topOfStack->index = lastIndex;
            topOfStack->item = currentChar;
            return 0;
        }
    }

    return -1;
}

int rearrange(
    char stacks[NUM_STACKS][MAX_STACK_HEIGHT],
    struct REARRANGEMENT* rearrangement)
{
    char* stackFrom = stacks[rearrangement->stackFromIndex - 1];
    char* stackTo = stacks[rearrangement->stackToIndex - 1];

    struct TOPOFSTACK topOfStackTo;
    struct TOPOFSTACK topOfStackFrom;

    int errCode;

    errCode = getTopOfStack(stackTo, &topOfStackTo);
    errCode = errCode || getTopOfStack(stackFrom, &topOfStackFrom);

    if (errCode)
        return errCode;

    int i = 0;
    int start = topOfStackFrom.index - rearrangement->numBlocks + 1;

    for (int j = start; i < rearrangement->numBlocks; j++) {
        stackTo[topOfStackTo.index + 1 + i++] = stackFrom[j];
        stackFrom[j] = LINE_TERMINATOR;
    }

    return 0;
}

int parseStackLine(
    char stacks[NUM_STACKS][MAX_STACK_HEIGHT],
    char* line,
    int read,
    int lineNo
) {
    if (isdigit(line[1]))
        return 0;

    int j = 0;
    for (int i = 1; i < read; i += 4) {
        char currentChar = line[i];
        if (currentChar != ' ')
            stacks[j][INITIAL_MAX_STACK_HEIGHT - 1 - lineNo] = currentChar;
        j++;
    }

    return 0;
}

int parseMove(
    char stacks[NUM_STACKS][MAX_STACK_HEIGHT],
    char* line,
    int lineLength,
    struct REARRANGEMENT* rearrangement
) {
    char toParse[MAX_MOVE_DIGITS] = { LINE_TERMINATOR };

    int j = 0;

    for (int i = 5; line[i] != ' ' && j < MAX_MOVE_DIGITS; i++)
        toParse[j++] = line[i];

    if (j-- == 0)
        return -1;

    rearrangement->numBlocks = atoi(toParse);
    rearrangement->stackFromIndex = atoi(line + j + 12);
    rearrangement->stackToIndex = atoi(line + j + 16);
    return 0;
}
