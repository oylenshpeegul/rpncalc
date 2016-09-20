#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // getch()
#include <termios.h>    // getch()
#include <ctype.h>      // isalpha() isdigita()

double  buffer3, buffer2, buffer1, buffery, bufferx;
char    tempBufferx[1];
int userInputInProgress;
double newInsert;

void convertTempToFloat();
void pressingEnter(char input[1]);
void operationalFunctions();
void commitTemp();
void pushInStack(double newInsert);
void rollUp();
void rollDown();
void collapseStack(double  newInsert);
void refreshWhileUserInput(char tempBufferx[1]);
void refreshBuffers();
char getch();

int main() {
    double  buffer3 = 0,
            buffer2 = 0,
            buffer1 = 0,
            buffery = 0,
            bufferx = 0;
    while (1){
        char c = getch();
        if      (c == 'q') break;
        else if (c == 'u') refreshBuffers();
        else if (c == 'h') pressingEnter(&c);
        else if (isdigit(c)) {
            refreshWhileUserInput(&c);
        }
        else continue;
    }
    /*char i;
    char tempBufferx[50] = "";
    do {
        i = getch();
        size_t len = strlen(tempBufferx);
        tempBufferx[len++] = i;
        tempBufferx[len] = '\0';
        refreshBuffers();
        
    } while (isdigit(i));
    
    if (i == 'h') pressingEnter(tempBufferx);   
*/
}
void convertTempToFloat() {
    
}
void pressingEnter(char input[50]){
    //something that makes input a float
    //bufferx becomes the converted tempBufferx
    //pushStack(0);
    //bufferx = new float
    //refresh(0, emptyString); 
    printf("%c", input);
    double temp = strtod(input,NULL);
    bufferx = temp;
    printf("%.4f", temp); 
//    refreshBuffers();
}

void operationalFunctions() {

}

// From string to num

void commitTemp() {

}

// Stack manipulation
void pushInStack(double newInsert) {
    buffer3 = buffer2;
    buffer2 = buffer1;
    buffer1 = buffery;
    bufferx = newInsert;
}

void collapseStack(double  newInsert) {
    bufferx = newInsert;
    buffery = buffer1;
    buffer1 = buffer2;
    buffer2 = buffer3;
    buffer3 = 0;
}
void rollUp() {
    double temp;
    temp = buffer3;
    buffer3 = buffer2;
    buffer2 = buffer1;
    buffer1 = buffery;
    buffery = bufferx;
    bufferx = temp;
}
void rollDown() {
    double temp;
    temp = bufferx;
    bufferx = buffery;
    buffery = buffer2;
    buffer2 = buffer3;
    buffer3 = temp;
}
void swapxy() {
    double temp;
    temp = bufferx;
    bufferx = buffery;
    buffery = temp;    
}

// Refresh Buffers

void refreshWhileUserInput(char tempBufferx[50]){
    for (int i = 0; i <= 50; i++) printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("%.15f\n%.15f\n%.15f\n%.15f\n", buffer3,
                                            buffer2,
                                            buffer1,
                                            buffery);
    printf("%s\n", tempBufferx);
}
void refreshBuffers() {
    for (int i = 0; i <= 50; i++) printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("%.15f\n%.15f\n%.15f\n%.15f\n%.15f\n",   buffer3,
                                                    buffer2,
                                                    buffer1,
                                                    buffery,
                                                    bufferx);
}

// Get character

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
