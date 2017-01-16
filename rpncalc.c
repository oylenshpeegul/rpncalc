#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double buffer3;
double buffer2;
double buffer1;
double buffery;
double bufferx;

void userInputMode();
void refreshBuffers();
void spacePrint(double number);
int numbersBeforeDec(double x);
// Stack manipulation:
void pushStack(double newInsert);
void collapseStack(double newInsert);
void updateBufferx(double newInsert);
void rollU(int refresh);
void rollD(int refresh);
void swap(int refresh);

int main() {
    buffer3 = 0;
    buffer2 = 0;
    buffer1 = 0;
    buffery = 0;
    bufferx = 0;
    refreshBuffers();
}

void userInputMode() {
    char i;
    double temp; 
    printf("                   ");
    scanf("%s", &i);

    if      (i == 'a') collapseStack(buffery + bufferx);
    else if (i == 's') collapseStack(buffery - bufferx); 
    else if (i == 'm') collapseStack(buffery * bufferx); 
    else if (i == 'd') collapseStack(buffery / bufferx); 
    else if (i == 'c') updateBufferx(bufferx * -1); 
    else if (i == 'r') rollD(1); 
    else if (i == 'x') swap(1); 
    else if (i == 't') updateBufferx(sqrt(bufferx)); 
    else if (i == 'e') collapseStack(pow(buffery, bufferx));
    else if (i == 'u') updateBufferx(sin(bufferx)); 
    else if (i == 'i') updateBufferx(cos(bufferx)); 
    else if (i == 'o') updateBufferx(tan(bufferx)); 
    else if (i == 'q') exit(0); 
    else if (i == 'p') pushStack(3.141592653589793238462); 
    else pushStack(atof(&i));
}
void refreshBuffers(){
    for (int i = 0; i <= 100; i++) printf("\n");

    printf("Buffer 3:");
    spacePrint(buffer3);
    printf("%.15lf", buffer3);
    printf("\n");
    
    printf("Buffer 2:");
    spacePrint(buffer2);
    printf("%.15lf", buffer2);
    printf("\n");

    printf("Buffer 1:");
    spacePrint(buffer1);
    printf("%.15lf", buffer1);
    printf("\n");

    printf("Buffer y:");
    spacePrint(buffery);
    printf("%.15lf", buffery);
    printf("\n");

    printf("Buffer x:");
    spacePrint(bufferx);
    printf("%.15lf", bufferx);
    printf("\n");

    userInputMode();
}

void spacePrint(double number) {
    char buffer[50];
    snprintf(buffer, 50, "%lf", number);
    int numlen = strlen(strtok(buffer,"."));
    for (int i = 0; i <= 10 - numlen; i++)
        printf(" ");
}

int numbersBeforeDec(double w) {
    char buffer[50];
    snprintf(buffer, 50, "%lf", w);
    return strlen(strtok(buffer,"."));
}

// Stack manipulation

void pushStack(double newInsert) {
    rollU(0);
    bufferx = newInsert;
    refreshBuffers();
}
void collapseStack(double newInsert) {
    rollD(0);
    bufferx = newInsert;
    buffer3 = 0;
    refreshBuffers();
}
void updateBufferx(double newInsert) {
    bufferx = newInsert;
    refreshBuffers();
}
void rollU(int refresh) {
    double temp = buffer3;
    buffer3 = buffer2;
    buffer2 = buffer1;
    buffer1 = buffery;
    buffery = bufferx;
    bufferx = temp;
    if (refresh == 1) refreshBuffers();
}
void rollD(int refresh) {
    double temp = bufferx;
    bufferx = buffery;
    buffery = buffer1;
    buffer1 = buffer2;
    buffer2 = buffer3;
    buffer3 = temp;
    if (refresh == 1) refreshBuffers();
}
void swap(int refresh) {
    double temp = bufferx;
    bufferx = buffery;
    buffery = temp;  
    if (refresh == 1) refreshBuffers();
}
