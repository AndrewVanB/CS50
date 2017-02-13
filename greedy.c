#include <stdio.h>
#include <cs50.h>

bool inputValid = false;
bool debug = false;
float input;
float quarter = 0.25f, dime = 0.10f, nickle = 0.05f, penny = 0.01f;
float change;
float numberOfCoins;

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
    printf("O hai! How much change is owed?\n");
    
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
    
    Makes the float value 'change' equal 'amount' which is the same as input, 
    since input was the parameter.
    
    If 'change' is greater than '0' run through this block and loop until 'change' is less than '0'.
    
        if 'quarter' (0.25f set at the top) is less than or equal to 'change', get the 'change' value, 
        and negate the 'quarter' (0.25f) value from the 'change' value and then increment 'numberOfCoins' by 1.
        
        else if 'dime' (0.10f set at the top) is less than or equal to 'change', get the 'change' value, 
        and negate the 'dime' (0.10f) value from the 'change' value and then increment 'numberOfCoins' by 1.
        
        else if 'nickle' (0.05f set at the top) is less than or equal to 'change', get the 'change' value, 
        and negate the 'dime' (0.05f) value from the 'change' value and then increment 'numberOfCoins' by 1.
        
        else if 'penny' (0.01f set at the top) is less than or equal to 'change', get the 'change' value, 
        and negate the 'penny' (0.01f) value from the 'change' value and then increment 'numberOfCoins' by 1.
        
        Once loop is complete, print the 'numberOfCoins' value, but only 2 numbers after the decimal.
*/

void calculateChange(float amount) {
    change = amount;
    
    
    for(;change > 0;) {
        if(quarter <= change) {
                                                            if(debug == true) printf("%.2f - %.2f\n", change, quarter);
            change -= quarter;
            numberOfCoins++;
        } else if(dime <= change) {
                                                            if(debug == true) printf("%.2f - %.2f\n", change, dime);
            change -= dime;
            numberOfCoins++;
        } else if(nickle <= change) {
                                                            if(debug == true) printf("%.2f - %.2f\n", change, nickle);
            change -= nickle;
            numberOfCoins++;
        } else if(penny >= change) {
                                                            if(debug == true) printf("%.2f - %.2f\n", change, penny);
            change -= penny;
            numberOfCoins++;
        }
    }
    printf("%.2f\n", numberOfCoins);
}
