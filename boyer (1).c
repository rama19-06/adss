#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pattern[50];
    int n, m, i, j, found = 0;

    printf("Enter text: ");
    gets(text);

    printf("Enter pattern: ");
    gets(pattern);

    n = strlen(text);
    m = strlen(pattern);

    i = 0;

    while (i <= n - m) {
        j = m - 1;

        while (j >= 0 && pattern[j] == text[i + j])
            j--;

        if (j < 0) {
            printf("Pattern found at position %d\n", i);
            found = 1;
            i++;
        }
        else {
            i = i + 1;
        }
    }

    if (found == 0)
        printf("Pattern not found");

    return 0;
}
