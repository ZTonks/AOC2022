#include<stdlib.h>
#include<stdio.h>

#include<stacking.h>

void printSolution(char stacks[NUM_STACKS][MAX_STACK_HEIGHT]) {
    printf("Top of stacks: ");

    for (int i = 0; i < NUM_STACKS; i++) {
        struct TOPOFSTACK topOfStack;
        getTopOfStack(stacks[i], &topOfStack);
        printf("[%c]", topOfStack.item);
        if (i < NUM_STACKS - 1)
            printf(", ");
        else
            printf("\n");
    }
}

int main()
{
    FILE* inputptr = fopen("/Users/zak/Documents/AOC2022/day5/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    char stacks[NUM_STACKS][MAX_STACK_HEIGHT] = { { LINE_TERMINATOR } };
    int linesRead = 0;

    // read stacks
    while ((read = getline(&line, &len, inputptr)) > 1)
    {
        int out = parseStackLine(stacks, line, read, linesRead++);
        if (out < 0)
            return out;
    }

    // read procedure
    while ((read = getline(&line, &len, inputptr)) != -1)
    {
        struct REARRANGEMENT rearrangement;
        int out = parseMove(stacks, line, read, &rearrangement);
        if (out < 0)
            return out;
        out = rearrange(stacks, &rearrangement);
        if (out < 0)
            return out;
    }

    printSolution(stacks);

    return 0;
}