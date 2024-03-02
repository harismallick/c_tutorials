#include <stdio.h>

void file_write(char* name, char* writeMode);
void file_delete(char* fileName);
void file_read(char* fileName);

int main() {

    // write names of bikini bottom residents to a file:
    file_write("Spongebob Squarepants\n", "w"); // write mode overwrites existing data in file
    file_write("Patrick Star\n", "a"); // append adds to the existing data in file by setting cursor to the end of the file.
    file_write("Sandy Cheeks\n", "a");

    // delete the file:
    // file_delete("read_write_files.txt");

    // reading the file:
    file_read("./read_write_files.txt");

    return 0;
}

void file_write(char* name, char* writeMode) {
    FILE *pFile = fopen("read_write_files.txt", writeMode);

    // use fprintf() to write to a file.
    fprintf(pFile, "%s", name);

    // must close a file after read/write operation is complete:
    fclose(pFile);
}
void file_delete(char* fileName) {
    if(remove(fileName) == 0) {
        printf("File was deleted.\n");
    }
    else {
        printf("No such file in the directory.\n");
    }
}
void file_read(char* fileName) {
    FILE *pF = fopen(fileName, "r");
    char buffer[255]; //This is how many characters will be retrieved from the file at a time.

    // Check if file exists
    if(pF != NULL) {
        printf("The residents of Bikini Bottom are:\n");
        while(fgets(buffer, 255, pF) != NULL) {
            printf("%s", buffer); // \n not required at the file contains them.
        }
    }
    else {
        printf("File not found.\n");
    }
    fclose(pF);
}