#include<stdio.h>
#include<stdlib.h>

#include<rpsenums.h>
#include<rpsparsing.h>

int main()
{
    FILE* inputptr = fopen("/Users/zak/Documents/AOC2022/day2/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int totalScore = 0;

    while ((read = getline(&line, &len, inputptr)) != -1 && read > 1)
    {
        enum RPS_OPPONENT opponentPlay = parseOpponent(line[0]);
        enum RPS_PLAYED myPlay = parsePlayer(line[2]);
        int score = evaluateWin(myPlay, opponentPlay);
        if (score < 0) {
            return -1;
        }
        totalScore += myPlay + score;
    }

    printf("Total score: %d\n", totalScore);

    return 0;
}
