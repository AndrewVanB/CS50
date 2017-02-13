#include <stdio.h>
#include <cs50.h>

bool inputValid = false;
bool debug = false;
float input;
int quarter = 25, dime = 10, nickle = 5, penny = 1;
int cents;
int numberOfCoins;

void inputCheck(void);
void calculateChange(float amount);


/*
    ===========main Function=============
    
    Continuously check for input as long as inputValid is false.
    Once inputValid is true, run the calculateChange function,
    where it uses input as a parameter.
    
    So, if someone types in '0.41' it would technically look like
    calculateChange(0.41);
*/

int main(void) {
    printf("How much change do I owe you?\n");
    
    do {
        inputCheck();
    } while(inputValid == false);
    
    calculateChange(input);
    
    return 0;
}


/*
    =============inputCheck Function==============
    
    Continuously prompts the user for a float value,
    then sets the value as input.
    
    If input is a negative number, it will ask the user again,
    how much change is used.
    
    If input typecasted to a Char value, is greater than a, so if it has any value
    that is not a floating point value, it will ask the user to retry.
    
    Else, if none of those if statements are called, it will change inputValid to true
    ending the while loop in the main class.
*/
    
void inputCheck(void) {
    
    input = get_float();
    
    if(input < 0.0f) {
        printf("How much change is used?\n");
    } else if((char)input > 'a') {
        printf("Retry: ");
    } else {
        inputValid = true;
    }
}

/*
    ============calculateChange Functoin===============
    
    Converts the 'amount' value to an integer, cents now represents 0.41 as 41
    
    
*/

void calculateChange(float amount) {
    cents = amount * 1000 / 10;
    
    for(;cents > 0;) {
        if(cents >= quarter) {
            cents -= quarter;
        } else if(cents >= dime) {
            cents -= dime;
        } else if(cents >= nickle) {
            cents -= nickle;
        } else if(cents >= penny) {
            cents -= penny;
        }
        numberOfCoins++;
        printf("Cents Left: %i\n", cents);
    }
    printf("%i\n", numberOfCoins);
}
