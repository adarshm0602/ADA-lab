#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct queue {
int f, r, *arr, cnt;
} QUE;
int graph[MAX][MAX], visited[MAX], s[MAX], count = 0;
void indegree(int graph[][MAX], int v, int inq[], QUE *temp, int flag[]) {
for (int i = 0; i < v; i++) {
for (int j = 0; j < v; j++) {
if (graph[i][j] == 1)
inq[j]++;
}
}
for(int i = 0; i < v; i++){
if (inq[i] == 0) {
temp->r = (temp->r + 1) % v;
temp->arr[temp->r] = i;
temp->cnt++;
flag[i] = 1;
}
}
}
void sourceremove(int graph[][MAX], int v, QUE *temp, int inq[], int flag[], int
whoCalled) {
int cnt = 0;
while (temp->cnt != 0) {
int source = temp->arr[temp->f];
temp->f = (temp->f + 1) % v;
s[cnt] = source;
temp->cnt--;
cnt++;
for (int i = 0; i < v; i++) {
count++;
if (graph[source][i] == 1) {
inq[i]--;
if (inq[i] == 0) {
temp->r = (temp->r + 1) % v;
temp->arr[temp->r] = i;
temp->cnt++;
flag[i] = 1;
}
}
}
}if(!whoCalled){
if (cnt != v) {
printf("Cycles exist, no topological sorting possible\n");
} else {
printf("The topological sorting is\n");
for (int i = 0; i < v; i++)
printf("%c\t", s[i] + 65);
}
}
}
void tester() {
int v;
printf("Enter the number of vertices\n");
scanf("%d", &v);
printf("Enter the adjacency matrix\n");
for (int i = 0; i < v; i++) {
for (int j = 0; j < v; j++) {
scanf("%d", &graph[i][j]);
}
}
printf("\nAdjacency matrix\n");
for (int i = 0; i < v; i++) {
for (int j = 0; j < v; j++) {
printf("%d\t", graph[i][j]);
}
printf("\n");
}
QUE q;
q.f = 0;
q.r = -1;
q.cnt = 0;
q.arr = (int *)malloc(sizeof(int) * v);
int *inq = (int *)malloc(sizeof(int) * v);
int *flag = (int *)malloc(sizeof(int) * v);
for (int i = 0; i < v; i++) inq[i] = 0;
for (int i = 0; i < v; i++) flag[i] = 0;
indegree(graph, v, inq, &q, flag);
sourceremove(graph, v, &q, inq, flag, 0);
free(q.arr);
free(inq);
free(flag);
}
void ploter(int k) {
FILE *f1, *f2;
f1 = fopen("TSRCWROST.txt", "a");
f2 = fopen("TSRCBEST.txt", "a");for (int n = 1; n <= 10; n++) {
count = 0;
int graph[n][n];
if (k == 0) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
if (i != j) {
graph[i][j] = 1;
} else {
graph[i][j] = 0;
}
}
}
} else {
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
graph[i][j] = 0;
}
}
for (int i = 0; i < n - 1; i++) {
graph[i][i + 1] = 1;
}
}
QUE q;
q.f = 0;
q.r = -1;
q.cnt = 0;
q.arr = (int *)malloc(sizeof(int) * n);
int *inq = (int *)malloc(sizeof(int) * n);
int *flag = (int *)malloc(sizeof(int) * n);
for (int i = 0; i < n; i++) inq[i] = 0;
for (int i = 0; i < n; i++) flag[i] = 0;
indegree(graph, n, inq, &q, flag);
sourceremove(graph, n, &q, inq, flag, 1);
if (k == 0) {
fprintf(f1, "%d\t%d\n", n, count);
} else {
fprintf(f2, "%d\t%d\n", n, count);
}
free(q.arr);
free(inq);
free(flag);
}
fclose(f1);
fclose(f2);
}int main() {
while (1) {
int key;
printf("ENTER THE CHOICE 1.TO TEST \n2.TO PLOT\nOTHER TO EXIT\n");
scanf("%d", &key);
switch (key) {
case 1:
tester();
break;
case 2:
for (int i = 0; i < 2; i++)
ploter(i);
break;
default:
exit(0);
}
}
return 0;
}
