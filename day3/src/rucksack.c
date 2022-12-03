#include<stdio.h>
#include<stdlib.h>

#define LOWERCASE_START 'a'

int checkUnique(
    char* compartment,
    int compartmentLength,
    char item
) {
    for (int i = 0; i < compartmentLength; i++) {
        if (compartment[i] == item)
            return 0;
    }
    return 1;
}

int getItemPriority(
    char item
) {
    if (item > LOWERCASE_START) {
        return item - LOWERCASE_START + 1;
    }

    return item - 'A' + ('z' - LOWERCASE_START + 1) + 1;
}

int getRucksackPriority(
    char* rucksackLine,
    int lineLength
) {
    int compSize = lineLength / 2;

    for (int i = 0; i < compSize; i++) {
        char* secondCompartment = rucksackLine + compSize;
        char item = rucksackLine[i];
        if (!checkUnique(secondCompartment, compSize, item))
            return getItemPriority(item);
    }

    return -1;
}
