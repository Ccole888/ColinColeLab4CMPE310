#include <stdio.h>
#include <stdlib.h>

extern unsigned char ram[];
extern void sum(int size);

int main(){
    FILE *file = fopen("data.txt", "r");
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
    sum(size);
    unsigned int result = *(unsigned int*)&ram[0x51];
    printf("Sum: %u\n", result);
    printf("Size: %d\n", size);
}
