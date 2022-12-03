#ifndef RUCKSACK_H
#define RUCKSACK_H

#define ELF_GROUP 3
#define MAX_ARRAY 60

struct ELF_RUCKSACK {
    char rucksack[MAX_ARRAY];
    int numItems;
};

// int getRucksackPriority(char* rucksackLine, int lineLength); // part 1 only
int elfGroupBadgePriority(struct ELF_RUCKSACK* rucksacks);

#endif
