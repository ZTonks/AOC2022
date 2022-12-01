#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define ELVES_FOR_MOST 3
#define INDEX_NOT_SEEN -1

void updateCalorieMaxes(
    int* calorieStorage,
    int currentCalories)
{
    int minIndexSeen = INDEX_NOT_SEEN;
    int minSeen = INT_MAX;

    for (int j = 0; j < ELVES_FOR_MOST; j++) {
        int stored = calorieStorage[j];

        if (currentCalories > stored && stored < minSeen) {
            minIndexSeen = j;
            minSeen = stored;
        }
    }

    if (minIndexSeen > INDEX_NOT_SEEN)
        calorieStorage[minIndexSeen] = currentCalories;
}

int main()
{
    FILE* inputptr = fopen("/Users/zak/Documents/AOC2022/day1/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int mostCalories[ELVES_FOR_MOST] = { };
    int currentCalories = 0;

    while ((read = getline(&line, &len, inputptr)) != -1)
    {
        // we can rely on the last line being a blank line
        // getline returns number of characters read including newline
        if (read > 1) {
            int i;

            for (i = 0; i < read - 1; i++) {
                if (line[i] != ' ')
                    break;
            }

            if (i == read)
                continue;

            currentCalories += atoi(line);
        }
        else {
            updateCalorieMaxes(mostCalories, currentCalories);
            currentCalories = 0;
        }
    }

    // account for the last batch
    updateCalorieMaxes(mostCalories, currentCalories);

    int total = 0;

    for (int i = 0; i < ELVES_FOR_MOST; i++) {
        int stored = mostCalories[i];
        
        total += stored;

        printf("Most calories %d: %d\n", i + 1, stored);
    }

    printf("Total: %d\n", total);

    return 0;
}
