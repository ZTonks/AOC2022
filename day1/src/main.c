#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* inputptr = fopen("/Users/zak/Documents/AOC2022/day1/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int mostCalories = 0;
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
            currentCalories = 0;
        }

        if (currentCalories > mostCalories)
            mostCalories = currentCalories;
    }

    printf("Most calories: %d\n", mostCalories);

    return 0;
}
