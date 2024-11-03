#include <stdio.h> 
#include "Topic7-AssessedExerciseLibHeader.h"

int main() {
    float kArr[10], cArr[10], fArr[10], avgArr[3], threshold;
    int underThreshold;

    if (returnIp(kArr)) {
        toCelsius(kArr, cArr);
        toFahren(cArr, fArr);

        printSamples(kArr, cArr, fArr);

        printf("\nSample number %d has the highest temperature.\n", returnMax(kArr));
        printf("Sample number %d has the lowest temperature.\n \n", returnMin(kArr));
        calcAvg(kArr, cArr, fArr, avgArr);
        printAvg(avgArr);
        threshold = input();
        underThreshold = kUnderThreshold(kArr, threshold);
        printf("\n%d samples have a Kelvin temperature below the threshold of %.2f.\n", underThreshold, threshold);
    }
    getchar();
    return 0;
}
