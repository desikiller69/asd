#include<stdio.h>

int main() {
    int f[50], p, i, j, k, a, st, len, n, c;

    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("\nEnter the block numbers that are already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

X:
    printf("Enter the starting index block & length: ");
    scanf("%d%d", &st, &len);

    k = len;
    for (j = st; j < st + k; j++) {
        if (f[j] == 0) {
            f[j] = 1;
            printf("\n%d->%d", j, f[j]);
        } else {
            printf("\n%d->File is already allocated", j);
            k++;
        }
    }

    printf("\nDo you want to enter one more file? (yes-1/no-0): ");
    scanf("%d", &c);

    if (c == 1) {
        goto X;
    } else {
        return 0;
    }
}
