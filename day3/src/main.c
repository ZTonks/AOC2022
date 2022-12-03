#include<stdio.h>
#include<stdlib.h>

#include<rucksack.h>

int main()
{
    FILE* inputptr = fopen("/Users/zak/Documents/AOC2022/day3/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int totalPriority = 0;

    while ((read = getline(&line, &len, inputptr)) != -1)
    {
        int rucksackPriority = getRucksackPriority(line, read);
        if (rucksackPriority < 1) {
            return -2;
        }
        totalPriority += rucksackPriority;
    }

    printf("Total priority: %d\n", totalPriority);

    return 0;
}
