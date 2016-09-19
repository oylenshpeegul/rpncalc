#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     //  getch()
#include <termios.h>    // getch()
#include <ctype.h>      // isalpha isdigit
/*
 
a add
s subtrack
m multipy
d divide

*/

double  buffer3,
        buffer2,
        buffer1,
        buffery,
        bufferx;
char tempBuffer[50];

void pressingEnter(char input[50]);

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
}

void clearScreen(){
    for (int i = 0; i <= 50; i++){
        printf("\n\n\n\n\n\n\n\n\n\n\n");
    }
}
void refresh(userInputInProgress){
    clearScreen();
    printf("%.15f\n%.15f\n%.15f\n%.15f\n", buffer3,
                                            buffer2,
                                            buffer1,
                                            buffery);
    if (userInputInProgress == 1)
        printf("%s\n", tempBuffer);
    else
        printf("%.15f\n", bufferx);
}
void userInsert(){
    char i;
    char tempBuffer[50] = "";
    
    do {
        i = getch();
//        strcat(tempBuffer, &i);
        refresh(1);
        
    } while (isdigit(i));
    
    if (i == 'h') pressingEnter(tempBuffer);
    
}
void pressingEnter(char input[50]){
    
}

int main() {
    double  buffer3 = 0,
            buffer2 = 0,
            buffer1 = 0,
            buffery = 0,
            bufferx = 0;
    while (1){
        char c = getch();
        if      (c == 'q') break;
        else if (c == 'u') refresh(0);
        else if (c == 'i') userInsert();
        else continue;
    }  
}

