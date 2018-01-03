#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    int key;
    // return if argument length greater than 2 or equals 0
    if (argc > 2 || argc == 1) {
        printf("Insufficient arguments!");
        return 1;
    }
    // cast argument 1 (key) to integer
    key = atoi(argv[1]);
    printf("plaintext: ");
    string text = get_string();
    // continue if get_string return value != NULL
    if (text != NULL) {
        printf("ciphertext: ");
        for (int i = 0, n = strlen(text); i < n; i++) {
            // if text[i] is alpha, convert to alphabet index from ASCII and rotate 'key' times
            // find result % 26 and convert back
            if (isalpha(text[i])) {
                if (isupper(text[i])) {
                    printf("%c", (((text[i] - 65) + key) % 26) + 65);
                }
                else {
                    printf("%c", (((text[i] - 97) + key) % 26) + 97);
                }
            }
            else {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }
}