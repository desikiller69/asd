#include<stdio.h>

int f[50], inde[50], count = 0;

int main() {
    int i, k, j, n, c, p;

    for(i = 0; i < 50; i++) {
        f[i] = 0;
    }

x:
    printf("Enter index block: ");
    scanf("%d", &p);

    if(f[p] == 0) {
        f[p] = 1;
        printf("Enter number of files on index: ");
        scanf("%d", &n);
    } else {
        printf("Block already allocated\n");
        goto x;
    }

    for(i = 0; i < n; i++) {
        scanf("%d", &inde[i]);
    }

    for(i = 0; i < n; i++) {
        if(f[inde[i]] == 1) {
            printf("Block already allocated\n");
            goto x;
        }
    }

    for(j = 0; j < n; j++) {
        f[inde[j]] = 1;
    }

    printf("\nAllocated");
    printf("\nFile indexed");

    for(k = 0; k < n; k++) {
        printf("\n%d->%d:%d", p, inde[k], f[inde[k]]);
    }

    printf("\nEnter 1 to enter more files and 0 to exit: ");
    scanf("%d", &c);

    if(c == 1) {
        goto x;
    } else {
        return 0;
    }
}
