#include <stdio.h>
#include <cs50.h>

void inputCheck(void);

    int input;
    bool inputValid = false;
    
int main(void) {
    float itg; //input(minutes) to gallons
    float bottles;
    float temp;
    float gpm = 1.5f; //gallons per minute
    float opg = 128.0f; //ounces per gallon
    float opb = 16.0f; //ounces per bottle of water
    
    printf("Minutes: ");
    do {
        input = get_int();
        inputCheck();
    } while(inputValid == false);
    
    itg = gpm*(float) input;
    temp = itg*opg;
    bottles = temp/opb;
    printf("Bottles: %.0f\n", bottles);
}

void inputCheck(void) {
    if (input <= 0) {
        printf("Retry: ");
        inputValid = false;
    } else if (input > 0) {
        inputValid = true;
    }
}
