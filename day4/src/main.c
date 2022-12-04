#include<stdlib.h>
#include<stdio.h>

#include<parsing.h>

int main()
{
    FILE* inputptr = fopen("/Users/zak/Documents/AOC2022/day4/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int numOverlaps = 0;

    while ((read = getline(&line, &len, inputptr)) != -1)
    {
        numOverlaps += hasContain(line, read);
    }

    printf("Total overlaps: %d\n", numOverlaps);

    return 0;
}
