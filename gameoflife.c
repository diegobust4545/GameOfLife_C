#include <stdio.h>
// Diego Bustamante
// Section A
// Sources: http://www.tutorialspoint.com/cprogramming/c_file_io.htm

unsigned char item[300];
FILE * file;
int uniCounter;
char array[60][40];
char copyArray[60][40];

void readBit();
void printGrid();
void switchCell();
int cellCounter(int , int);

int main(){
    readBit();
    printGrid();
    switchCell();
    printGrid();
    return 0;
}

void readBit(){
    int counter,x,y =0;
    
    
    file = fopen("blinkers","rb");
    fread(item, sizeof(int), 300, file);
    // For loop for reading the file
    for (int i = 0; i < 300; i++) {
        if (item[i] == 0) { // checks to see if the current
            for (int k=0; k<8; k++){
                array[x][y] = ' ';
                counter++;
                x++;
                if (counter == 60) {
                    counter = 0;
                    y++;
                    x=0;
                }
                
            }
        }
        else {
            for (int j = 7; j>=0;j--) {
                if ((item[i] >> j&1)==1) {
                    array[x][y] = 'O';
                }
                else{
                    array[x][y] = ' ';
                }
                x++;
                counter++;
                if (counter == 60) {
                    counter = 0;
                    y++;
                    x=0;
                }
            }
        }
    }
}


void printGrid(){
    int counter = 0;
    printf("Grid From 2D Array: \n");
    for(int i = 0; i<40; i++) {
        for (int j = 0; j < 60; j++) {
            printf("%c",array[j][i]);
        }
        printf("\n");
    }
}

// counts the amount of live cells surrounding it
int cellCounter(int x, int y){
    int counter = 0;
        if (array[x-1][y-1]=='O') {
            counter++;
        }
    
        if(array[x][y-1]=='O') {
            counter++;
        }
    
        if (array[x+1][y-1]=='O') {
            counter++;
        }
    
        if (array[x-1][y]=='O') {
            counter++;
        }
    
        if (array[x+1][y]=='O') {
            counter++;
        }
    
        if (array[x-1][y+1]=='O') {
            counter++;
        }

        if (array[x][y+1]=='O') {
            counter++;
        }
    
        if (array[x+1][y+1]=='O') {
            counter++;
        }
    return counter;
}

//switch the cells
void switchCell(){
    printf("\nGrid with Switched Cells: \n");
    for (int i = 0;i<100;i++){
        //printf("Amount of Iterations: %d\n",i);
        for(int i = 0; i<40; i++) {
            for (int j = 0; j < 60; j++) {
                int cell = cellCounter(j,i);
                
                if (cell<2 && array[j][i]=='O') {
                    copyArray[j][i] = ' ';
                }
            
            
                else if(cell>3 && array[j][i]=='O'){
                    copyArray[j][i]=' ';
                }
            
            
                else if((cell==3 || cell==2) && array[j][i]=='O'){
                    copyArray[j][i]='O';
                }
            
            
                else if(cell==3 && array[j][i]==' '){
                    copyArray[j][i]='O';
                }
    
                else if(cell!=3 && array[j][i]==' '){
                    copyArray[j][i]=' ';
                }
            }
            //printf("\n");
        }
        for(int i = 0; i<40; i++) {
            for (int j = 0; j < 60; j++){
                array[j][i]=copyArray[j][i];
            
            }
        }
    }
}
