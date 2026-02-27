#include <stdio.h>
#include <stdlib.h>

extern unsigned int ram[];
extern int sum(int size);

int main(int argc, char* argv[]){
    FILE *file = fopen(argv[1], "r");
    int size;
    fscanf(file, "%d", &size);
    int intlist[size];
    for(int i = 0; i < size; i++){
        fscanf(file, "%*[^\n]");
        fscanf(file, "%*c");
        fscanf(file, "%d", &intlist[i]);
    }
    fclose(file);
    for(int i = 0; i < size; i++){
        ram[i] = intlist[i];
    }
    
    unsigned int result = sum(size);
    printf("Sum: %u\n", result);
    printf("Size: %d\n", size);
}
