#include<stdio.h>
#include<stdlib.h>

#include<rucksack.h>

#define LOWERCASE_START 'a'
#define NO_PRIORITY_RESOLVED -1

int checkUnique(
    char* rucksackCompartment,
    int compartmentLength,
    char item
) {
    for (int i = 0; i < compartmentLength; i++) {
        if (rucksackCompartment[i] == item)
            return 0;
    }
    return 1;
}

// Part 1 only
// int getRucksackPriority(
//     char* rucksackLine,
//     int lineLength
// ) {
//     int compSize = lineLength / 2;

//     for (int i = 0; i < compSize; i++) {
//         char* secondCompartment = rucksackLine + compSize;
//         char item = rucksackLine[i];
//         if (!checkUnique(secondCompartment, compSize, item))
//             return getItemPriority(item);
//     }

//     return NO_PRIORITY_RESOLVED;
// }

int getItemPriority(
    char item
) {
    if (item > LOWERCASE_START) {
        return item - LOWERCASE_START + 1;
    }

    return item - 'A' + ('z' - LOWERCASE_START + 1) + 1;
}

int elfGroupBadgePriority(
    struct ELF_RUCKSACK* rucksacks
) {
    struct ELF_RUCKSACK firstElfRucksack = rucksacks[0];

    for (int i = 0; i < firstElfRucksack.numItems; i++) {
        char firstElfCurrentItem = firstElfRucksack.rucksack[i];
        int isInAllBackpacks = 1;

        for (int j = 1; j < ELF_GROUP && isInAllBackpacks; j++) {
            struct ELF_RUCKSACK otherElfRucksack = rucksacks[j];
            isInAllBackpacks = isInAllBackpacks &&
                !checkUnique(otherElfRucksack.rucksack, otherElfRucksack.numItems, firstElfCurrentItem);
        }

        if (isInAllBackpacks) {
            printf("%d, %c\n", getItemPriority(firstElfCurrentItem), firstElfCurrentItem);
            return getItemPriority(firstElfCurrentItem);
        }
    }

    return NO_PRIORITY_RESOLVED;
}
