#include <stdio.h>
#include <string.h>
#include "BruteForce.h"
#define _CRT_SECURE_NO_WARNINGS


#define MAX_BUFFER 512

int main(int argc, char** argv)
{
    char* FilePath;
    FILE* fp;

    char  Text[MAX_BUFFER];
    char* Pattern;
    int   PatternSize = 0; // size_t 
    int   Line = 0;


    if (argc < 3) {
        printf("Usage: %s <FilePath> <Pattern>\n", argv[0]);
        return 1;
    }
        argv[1] = "\\kjv.txt";
        argv[2] = "Faithful";
   

    FilePath = argv[1];
    Pattern = argv[2];

    PatternSize = strlen(Pattern);

    if ((fp = fopen(FilePath, "r")) == NULL)
    {
        printf("Cannot open file:%s\n", FilePath);
        return 1;
    }

    while (fgets(Text, MAX_BUFFER, fp) != NULL)
    {
        int Position =
            BruteForce(Text, strlen(Text), 0, Pattern, PatternSize);

        Line++;

        if (Position >= 0)
        {
            printf("line:%d, column:%d : %s", Line, Position + 1, Text);
        }
    }

    fclose(fp);

    return 0;
}
