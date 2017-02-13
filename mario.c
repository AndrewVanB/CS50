    #include <stdio.h>
    #include <cs50.h>
    
        int input;
        int inputValid= false;
    
        void printRow(int amount);
        void inputCheck(void);
    
    int main(void) {
        printf("Height: ");
            do {
            input = get_int();
            inputCheck();
        } while(inputValid == false);
    
        printRow(input);
    
         return 0;
    }
    
    void inputCheck(void) {
        if (input == 0) {
            inputValid = true;
        } else if (input < 1  || input > 23) {
            printf("Retry: ");
            inputValid = false;
    
        } else if (input > 0 && input <= 23) {
            inputValid = true;
        }
    }
    
    void printRow(int amount) {
        int boxes = 1;
    
        for(int row = 0; row < amount; row++) {
    
            int spaces = amount - boxes;
            
            if (amount > 1) {
                for(int x = 0; x < spaces; spaces--) {
                    printf(" ");
                }
            }
    
            for(int i = 0; i < boxes; i++) {
                printf("#");
            }
    
            printf("  ");
    
            for(int i = 0; i < boxes; i++) {
                printf("#");
            }
            boxes++;
            printf("\n");
        }
    }
