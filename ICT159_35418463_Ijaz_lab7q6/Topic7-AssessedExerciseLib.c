#include "Topic7-AssessedExerciseLibHeader.h"
#include <stdio.h> 

int returnIp(float arr[]) {
    int typeCheck;
    printf("Please enter the kelvin temperatures of 10 samples\n");

    for (int i = 0; i<10; i++) {
        printf("%d. ", i+1);
        typeCheck = scanf("%f", &arr[i]);

        if (typeCheck == 0) {
            printf("Please enter a positive number only. \n");
            return 0;
        } else if (arr[i] < 0) {
            printf("Please enter a positive Kelvin temperature only.\n");
            i--;
        }
    }
    return 1;
}

void toCelsius(float arr[], float cArr[]) {
    for (int i = 0; i<10; i++) {
        cArr[i] = arr[i] - 273;
    }
       
}

void toFahren(float cArr[], float fArr[]) {
    for (int i = 0; i<10; i++) {
        fArr[i] = ((9 * cArr[i])/5) + 32;
    }   
}

void printSamples(float kArr[], float cArr[], float fArr[]) {
    for (int i = 0; i < 10; i++) {
        printf(" Sample %d: %.2fK | State: ", i+1, kArr[i]);
        state(cArr, i);
        printf(" | %.2f C | %.2f F \n", cArr[i], fArr[i]);
    }
}


int returnMax(float arr[]) {
    float max = arr[0];
    int maxIx = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIx = i;
        }
    }
    return maxIx + 1;
}

int returnMin(float arr[]) {
    float min = arr[0];
    int minIx = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIx = i;
        }
    }
    return minIx + 1;
}

void calcAvg(float arr[], float cArr[], float fArr[], float avgArr[]) {
    float kSum = 0, cSum = 0, fSum = 0;
    for (int i = 0; i<10; i++) {
        kSum += arr[i];
        cSum += cArr[i];
        fSum += fArr[i];
    }
    avgArr[0] = kSum / 10;
    avgArr[1] = cSum / 10;
    avgArr[2] = fSum / 10;
}

void printAvg(float avgArr[]) {
    printf("Average temperatures of samples in Kelvin: %.2f K \nAverage temperatures of samples in Celsius: %.2f C \nAverage temperatures of samples in Fahrenheit: %.2f F \n", avgArr[0], avgArr[1], avgArr[2]);
}

float input() {
    float input, type;
    printf("\nEnter a threshold to find K-temp samples lower it: ");
    do {
        type = scanf("%f", &input);
        while (getchar() != '\n');
        if (type && input > -1) {
            printf("\n***Note: Decimal numbers will be rounded to floor***");
            return input;
        }
        else {
            printf("Please enter a positive number only.");
        }
        
    } while(1);
}

int kUnderThreshold(float arr[], float threshold) {
    int i = 0;
    for (int j = 0; j<10; j++) {
        if (arr[j] < threshold)
        i += 1;
    }
    return i;
}

void state(float cArr[], int index) {
    if (cArr[index] > 0) {
        if (cArr[index] < 100) {
            printf("Liquid");
        }
        else {
            printf("Gas");
        }
    } 
    else {
        printf("Solid");
    }
}