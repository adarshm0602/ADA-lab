#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;
int bubblesort(int *a, int n) {
count = 0;
int i, j, t, flag = 0;
for (i = 0; i < n-1; i++) {
flag = 0;
for (j = 0; j < n-i-1; j++) {
count++;
if (a[j] > a[j+1]) {
t = a[j];
a[j] = a[j+1];
a[j+1] = t;
flag = 1;
}
}
if (!flag) break;
}
return count;
}
int insertionsort(int *arr, int n) {
int count = 0;
for (int i = 1; i < n; i++) {
int value = arr[i];
int j = i - 1;
while (count++ && arr[j] > value) {
arr[j+1] = arr[j];
j--;
if (j < 0) break;
}
arr[j+1] = value;
}
return count;
}
int selectionsort(int *a, int n) {
int i, j, min, t, count = 0;
for (i = 0; i < n-1; i++) {
min = i;
for (j = i+1; j < n; j++) {
if (a[j] < a[min]) min = j;
count++;
}
if (min != i) {
t = a[min];
a[min] = a[i];
a[i] = t;
}
}
return count;
}
void plotter(int ch) {
int *arr, n;
srand(time(NULL));
FILE *f1, *f2, *f3;
switch (ch) {
case 4:
f1 = fopen("bs.out", "a");
f2 = fopen("bw.out", "a");
f3 = fopen("ba.out", "a");
break;
case 5:
f1 = fopen("is.out", "a");
f2 = fopen("iw.out", "a");
f3 = fopen("ia.out", "a");
break;
case 6:
f1 = fopen("ss.out", "a");
f2 = fopen("sw.out", "a");
f3 = fopen("sa.out", "a");
break;
}
n = 10;
while (n <= 30000) {
arr = (int*) malloc(sizeof(int) * n);
for (int i = 0; i < n; i++) arr[i] = n - i;
int count = 0;
switch (ch) {
case 4:
count = bubblesort(arr, n);
fprintf(f2, "%d\t%d\n", n, count);
break;
case 5:
count = insertionsort(arr, n);
fprintf(f2, "%d\t%d\n", n, count);
break;
case 6:
count = selectionsort(arr, n);
fprintf(f2, "%d\t%d\n", n, count);
break;
}
count = 0;
for (int i = 0; i < n; i++) arr[i] = i + 1;
switch (ch) {
case 4: count = bubblesort(arr,n);
break;
case 5: count = insertionsort(arr,n);
break;
case 6: count = selectionsort(arr,n);
break;
}
fprintf(f1, "%d\t%d\t\n", n, count);
for (int i=0; i<n; i++) arr[i] = rand() % n;
count=0;
switch(ch){
case 4: count = bubblesort(arr,n);
break;
case 5: count = insertionsort(arr,n);
break;
case 6: count = selectionsort(arr,n);
break;
}
fprintf(f3, "%d\t%d\t\n", n, count);
if (n<10000) n=n*10;
else n=n+10000;
free(arr);
}
}
void tester (int ch){
int *arr, n;
printf("Enter no. of elements :\n");
scanf("%d",&n);arr = (int*) malloc ( sizeof(int)*n );
printf("Enter elements of array\n");
for(int i=0; i<n; i++) scanf("%d", &arr[i]);
printf("Elements before sort :\n");
for(int i=0; i<n; i++) printf("%d ", arr[i]);
printf("\n");
switch(ch){
case 1: bubblesort (arr,n); break;
case 2: insertionsort(arr,n); break;
case 3: selectionsort(arr,n); break;
}
printf("Elements after sort :\n");
for(int i=0; i<n; i++) printf("%d ", arr[i]);
printf("\n");
}
int main(){
int key;
printf("1. Bubblesort Tester\n2. Insertion sort Tester\n");
printf("3. Selection sort Tester\n4. Bubblesort Plotter\n5. Insertion Sort Plotter\n6. Selection Sort Plotter\n7. Exit\n");
while(1) {
     printf("enter the choice:");
    scanf("%d", &key);
switch(key){
case 1: tester ( key ); break;
case 2: tester ( key ); break;
case 3: tester ( key ); break;
case 4: plotter (key); break;
case 5: plotter (key); break;
case 6: plotter (key); break;
case 7: exit(0);
}
}
}
