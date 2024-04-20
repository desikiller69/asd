#include<stdio.h>

int main() {
    int f[50], i, st, j, len, c;

    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

X:
    printf("\nEnter the starting block & length of file: ");
    scanf("%d%d", &st, &len);

    for (j = st; j < (st + len); j++) {
        if (f[j] == 0) {
            f[j] = 1;
            printf("\n%d->%d", j, f[j]);
        } else {
            printf("\nBlock already allocated");
            break;
        }
    }

    if (j == (st + len)) {
        printf("\nThe file is allocated to disk");
    }

    printf("\nDo you want to enter more files? (y-1/n-0): ");
    scanf("%d", &c);

    if (c == 1) {
        goto X;
    } else {
        return 0;
    }
}
