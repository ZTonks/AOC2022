#include<stdlib.h>

#include<parsing.h>

int parseFirstValue(
    char* assignments,
    int* index
) {
    char toParse[5];
    int arrIndex = 0;
    for (int i = *index; ; i++) {
        if (assignments[i] == '-') {
            *index = i + 1;
            return atoi(toParse);
        }
        toParse[arrIndex++] = assignments[i];
    }
    return -1;
}

int parseSecondValue(
    char* assignments,
    int* index,
    int lineLength
) {
    char toParse[5];
    int arrIndex = 0;
    for (int i = *index; i < lineLength; i++) {
        if (assignments[i] == ',') {
            *index = i + 1;
            return atoi(toParse);
        }
        toParse[arrIndex++] = assignments[i];
    }
    if (toParse[0] == '\0')
        return -1;
    return atoi(toParse);
}

int hasContain(
    char* assignments,
    int lineLength
) {
    int index = 0;
    int* indexPtr = &index;
    int valOne = parseFirstValue(assignments, indexPtr);
    int valTwo = parseSecondValue(assignments, indexPtr, lineLength);

    int valThree = parseFirstValue(assignments, indexPtr);
    int valFour = parseSecondValue(assignments, indexPtr, lineLength);

    return valOne <= valThree && valTwo >= valFour
        || valThree <= valOne && valFour >= valTwo;
}
