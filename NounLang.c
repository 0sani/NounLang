#include <stdio.h>
#include <string.h>

// brainf*ck interpreter
void run(char* inputString) {
    char array[30000] = {0};
    char *ptr = array;

    size_t i = 0;
    size_t len = strlen(inputString);
    size_t loop;

    for (; i < len; i++) {
        char instruction = inputString[i];

        if (instruction == '>') {
            ++ptr;
        } else if (instruction == '<') {
            --ptr;
        } else if (instruction == '+') {
            ++*ptr;
        } else if (instruction == '-') {
            --*ptr;
        } else if (instruction == '.') {
            putchar(*ptr);
        } else if (instruction == ',') {
            *ptr = getchar();
        } else if (instruction == ']' && *ptr) {
            loop = 1;
            while (loop > 0) {
                instruction = inputString[--i];
                if (instruction == '[') {
                    loop--;
                } else if (instruction == ']') {
                    loop++;
                }
            }
        }
    }
}

char* convertToBF() {

    system("python3 bfConverter.py > tmp.txt");

    FILE *fp = fopen("tmp.txt", "r");
    static char buffer[1000];
    fread(buffer, 1001,1,fp);
    fclose(fp);
    return buffer;
}


int main() {
    run(convertToBF());
    system("rm tmp.txt");
    return 0;
}
