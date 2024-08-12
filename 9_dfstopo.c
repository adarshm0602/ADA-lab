#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], path[MAX], stack[MAX], top = -1;
int c = 0, count = 0;
void dfs(int n, int start) {
visited[start] = 1;
path[start] = 1;
for (int i = 0; i < n; i++) {
if (graph[start][i] && visited[i] == 1 && path[i] == 1)
c = 1;
if (graph[start][i] && visited[i] == 0)
dfs(n, i);
count++; // Increment count for plotter
}
path[start] = 0;
stack[++top] = start;
}
void tester() {
int n;
printf("\nEnter the number of vertices:\n");
scanf("%d", &n);
printf("\nEnter the adjacency matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
visited[i] = 0;
path[i] = 0;
}
printf("\nTopological Order:\n");
for (int i = 0; i < n; i++) {
if (visited[i] == 0)
dfs(n, i);
}
if (c == 1) {
printf("IT HAS A LOOP SO NO TOPOLOGICAL ORDER\n");
return;
}for (int i = top; i >= 0; i--) {
printf(" --> %c", stack[i] + 65);
}
printf("\n");
}
void ploter(int k) {
FILE *f1 = fopen("DFSBEST.txt", "a");
FILE *f2 = fopen("DFSWORST.txt", "a");
for (int v = 1; v <= 10; v++) {
for (int i = 0; i < v; i++) {
for (int j = 0; j < v; j++) {
if (k == 0) {
graph[i][j] = (i != j) ? 1 : 0;
} else {
graph[i][j] = 0;
if (i < v - 1 && j == i + 1) {
graph[i][j] = 1;
}
}
}
visited[i] = 0;
path[i] = 0;
}
count = 0;
top = -1;
c = 0;
for (int i = 0; i < v; i++) {
if (visited[i] == 0)
dfs(v, i);
}
if (k == 0)
fprintf(f2, "%d\t%d\n", v, count);
else
fprintf(f1, "%d\t%d\n", v, count);
}
fclose(f1);
fclose(f2);
}
int main() {
while (1) {
int key;
printf("Enter the choice:\n1. To Test DFS\n2. To Plot\nAny other number to Exit\n");
scanf("%d", &key);
switch (key) {
case 1:tester();
break;
case 2:
for (int i = 0; i < 2; i++)
ploter(i);
printf("Data entered into the files\n");
break;
default:
exit(0);
}
}
return 0;
}
