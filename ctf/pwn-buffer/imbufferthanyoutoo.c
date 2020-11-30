#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln() {
    int secret = 0x00000000;
    char buffer[12];

    printf("Input text into buffer: ");
    gets(buffer); // This may be a vulnerability...

    if(secret == 0xba659288) {
        printf("You found the flag!\n");
        system("cat flag.txt");
    } else {
        printf("It looks like you didn't overwrite the secret variable or overwrote using the wrong data.\n");
    }

    exit(0);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    vuln();
}
