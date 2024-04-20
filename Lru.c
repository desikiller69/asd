#include<stdio.h>

void display(int fr[], int frsize) {
 printf("\n");
 for(int i = 0; i < frsize; i++)
 printf("%d\t", fr[i]);
}
int main() {
 int fr[3], fs[3];
 int p[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
 int pf = 0, frsize = 3;
 for(int i = 0; i < frsize; i++)
 fr[i] = -1;
 for(int j = 0; j < 12; j++) {
 int flag1 = 0, flag2 = 0;

 for(int i = 0; i < frsize; i++) {
 if(fr[i] == p[j]) {
 flag1 = 1;
 flag2 = 1;
 break;
 }
 }
 if(flag1 == 0) {
 for(int i = 0; i < frsize; i++) {
 if(fr[i] == -1) {
 fr[i] = p[j];
 flag2 = 1;
 break;
 }
 }
 }
 if(flag2 == 0) {
 for(int i = 0; i < frsize; i++)
 fs[i] = 0;
 for(int k = j - 1, l = 1; l <= frsize - 1; l++, k--) {
 for(int i = 0; i < frsize; i++) {
 if(fr[i] == p[k])
 fs[i] = 1;
 }
 }
 int index;
 for(index = 0; index < frsize; index++) {
 if(fs[index] == 0)
 break;
 }
 fr[index] = p[j];
 pf++;
 }
 display(fr, frsize);
 }
 printf("\nNo of Page Faults: %d", pf + frsize);

 return 0;
}