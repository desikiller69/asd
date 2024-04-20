#include<stdio.h>

int fr[10], n, m;
void display() {
 for(int i = 0; i < m; i++)
 printf("%d\t", fr[i]);
 printf("\n");
}
void main() {
 int page[20], fs[10];
 int max, found=0, lg[10], index, k, l, flag1=0, flag2=0, pf=0;
 float pr;
 printf("Enter length of the reference string: ");
 scanf("%d", &n);
 printf("Enter the reference string: ");
 for(int i = 0; i < n; i++)
 scanf("%d", &page[i]);
 printf("Enter number of frames: ");
 scanf("%d", &m);
 for(int i = 0; i < m; i++)
 fr[i] = -1;
 pf = m;
 for(int j = 0; j < n; j++) {
 flag1 = 0;
 flag2 = 0;
 for(int i = 0; i < m; i++) {
 if(fr[i] == page[j]) {
 flag1 = 1;
 flag2 = 1;
 break;
 }
 }
 if(flag1 == 0) {
 for(int i = 0; i < m; i++) {
 if(fr[i] == -1) {
 fr[i] = page[j];
 flag2 = 1;
 break;
 }
 }
 }
 if(flag2 == 0) {
 for(int i = 0; i < m; i++)
 lg[i] = 0;
 for(int i = 0; i < m; i++) {
 for(k = j + 1; k < n; k++) {
 if(fr[i] == page[k]) {
 lg[i] = k - j;
 break;
 }
 }
 }
 found = 0;
 for(int i = 0; i < m; i++) {
 if(lg[i] == 0) {
 index = i;
 found = 1;
 break;
 }
 }
 if(found == 0) {
 max = lg[0];
 index = 0;
 for(int i = 0; i < m; i++) {
 if(max < lg[i]) {
 max = lg[i];
 index = i;
 }
 }
 }
 fr[index] = page[j];
 pf++;
 }
 display();
 }
 printf("Number of page faults: %d\n", pf);
 pr = (float)pf / n * 100;
 printf("Page fault rate = %f \n", pr);

}
