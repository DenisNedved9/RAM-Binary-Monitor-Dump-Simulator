#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int main(){
    //created the ram for 1KB
    int size_ram = 1024; // 1 KB
    char *ram = malloc(size_ram);
    srand(time(NULL));
    

    if (ram == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    int h = 0;

    //generate random data into RAM
    while (h < 20) {
        FILE *Ram_data = fopen("ram_data.bin", "wb");
        FILE *Ram_data_txt = fopen("ram_data.txt", "w");
        if (Ram_data == NULL || Ram_data_txt == NULL) {
            printf("Failed to open files.\n");
            free(ram);
            return 1;
        }
        
        for (int i = 0; i < size_ram; i++) {
            ram[i] = rand() % 255;
        }

     //send data into Ram_data.bin a Ram_data.txt
        fprintf(Ram_data_txt, "Data v RAM:\n");
        for (int i = 0; i < size_ram; i++) {
            fprintf(Ram_data_txt, "%u ", (unsigned char)ram[i]);
            fwrite(&ram[i], 1, 1, Ram_data);
            if ((i + 1) % 16 == 0) {
                fprintf(Ram_data_txt, "\n");
            }
        }
        fprintf(Ram_data_txt, "\n");
        fflush(Ram_data);
        fflush(Ram_data_txt);
        fclose(Ram_data);
        fclose(Ram_data_txt);
        //wait 500ms
        Sleep(500);
        h++;
        
    }
    free(ram);
    return 0;
}
