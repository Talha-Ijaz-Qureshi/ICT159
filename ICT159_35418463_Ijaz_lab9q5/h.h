// h.h
#ifndef H_H
#define H_H

#define NAME_SIZE 128  // Maximum name length

int readDataFromFile(const char *filename, char ***names, int **ages, float **wages, int *recordCount);
void writeDataToFile(const char *filename, char **names, int *ages, float *wages, int recordCount);
void freeMemory(char **names, int *ages, float *wages, int recordCount);
void searchAndPrintRecord(char **names, int *ages, float *wages, int recordCount, const char *searchName);

#endif
