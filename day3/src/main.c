#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<rucksack.h>

void clearArrays(
    struct ELF_RUCKSACK* rucksacks
) {
    for (int i = 0; i < ELF_GROUP; i++)
        for (int j = 0; j < MAX_ARRAY; j++)
            rucksacks[i].rucksack[j] = '\0';
}

int main()
{
    FILE* inputptr = fopen("/Users/zak/Documents/AOC2022/day3/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    struct ELF_RUCKSACK rucksacks[ELF_GROUP] = { };
    int rucksacksRead = 0;

    int totalPriority = 0;

    while ((read = getline(&line, &len, inputptr)) != -1)
    {
        struct ELF_RUCKSACK* currentRucksack = &(rucksacks[rucksacksRead++]);
        strncpy(currentRucksack->rucksack, line, read);
        currentRucksack->numItems = read;

        if (rucksacksRead == ELF_GROUP) {
            int rucksackPriority = elfGroupBadgePriority(rucksacks);
            if (rucksackPriority < 1) {
                return -2;
            }
            totalPriority += rucksackPriority;
            rucksacksRead = 0;
            clearArrays(rucksacks);
        }
    }

    printf("Total priority: %d\n", totalPriority);

    return 0;
}
