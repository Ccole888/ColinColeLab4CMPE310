#include <stdio.h>
#include <stdlib.h>

extern unsigned int ram[];
extern int sum(int size);
//Reads the file name from the command line
int main(int argc, char* argv[]){
    //opens file in read mode
    FILE *file = fopen(argv[1], "r");
    int size;
    //reads first line of the data file and stores as size
    fscanf(file, "%d", &size);
    //declare an array with size size
    int intlist[size];
    //adds each line of the data file to the intlist array
    for(int i = 0; i < size; i++){
        fscanf(file, "%*[^\n]");
        fscanf(file, "%*c");
        fscanf(file, "%d", &intlist[i]);
    }
    fclose(file);
    //puts intlist into ram
    for(int i = 0; i < size; i++){
        ram[i] = intlist[i];
    }
    //calls sum and prints result and size
    unsigned int result = sum(size);
    printf("Sum: %u\n", result);
    printf("Size: %d\n", size);
}
