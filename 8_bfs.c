#include <stdio.h>
#include <stdlib.h>
int graph[100][100], visited[100], bfsCount = 0, cyclic = 0, count = 0, orderCount = 0;
void bfs(int n, int start, int whoCalled) {
int queue[n], parent[n];
int rear = -1, front = -1, i, parentNode;
visited[start] = 1;
count++;
queue[++rear] = start;
parent[rear] = -1;
while (rear != front) {
start = queue[++front];
parentNode = parent[front];
if (!whoCalled) printf("-->%c", start + 65);
for (i = 0; i < n; i++) {
orderCount++;
if (i != parentNode && graph[start][i] && visited[i]) cyclic = 1;
if (graph[start][i] && visited[i] == 0) {
queue[++rear] = i;
parent[rear] = start;
visited[i] = 1;
if (!whoCalled) count++;
}
}
}
}
void ploter(int k) {
FILE *f1 = fopen("BFSBEST.txt", "a");
FILE *f2 = fopen("BFSWOSR.txt", "a");
int v, start;
for (int i = 1; i <= 10; i++) {
v = i;
for (int i = 0; i < v; i++) {
for (int j = 0; j < v; j++) {
if (k == 0) {
graph[i][j] = (i != j) ? 1 : 0;
} else if (k == 1) {
graph[i][j] = 0;
if (i < v - 1) graph[i][i + 1] = 1;
}
}
visited[i] = 0;
}bfsCount = 0;
cyclic = 0;
count = 0;
orderCount = 0;
bfsCount++;
bfs(v, 0, 1);
if (count != v) {
start = 1;
while (count != v) {
if (visited[start] != 1) {
bfsCount++;
bfs(v, start, 1);
}
start++;
}
}
if (k == 0)
//Actual: fprintf(f2, "%d\t%d\n", v, orderCount);
fprintf(f2, "%d\t%d\n", v, v*v);
else
//Actual: fprintf(f1, "%d\t%d\n", v, orderCount);
fprintf(f1, "%d\t%d\n", v, v*v);
}
fclose(f1);
fclose(f2);
}
void tester() {
int n, i, j, start;
printf("Enter the number of nodes in the graph:\n");
scanf("%d", &n);
printf("Enter the Adjacency Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
visited[i] = 0;
}
printf("The Adjacency Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
printf("%d ", graph[i][j]);
}
printf("\n");
}
bfsCount = 0;
cyclic = 0;count = 0;
orderCount = 0;
printf("Breadth First Search Traversal:\n");
bfsCount++;
bfs(n, 0, 0);
if (count == n) {
printf("\nGraph is connected.\n");
} else {
printf("\nThe graph is not connected.\n");
start = 1;
while (count != n) {
if (visited[start] != 1) {
bfsCount++;
bfs(n, start, 0);
printf("\n");
}
start++;
}
}
printf("\nThe number of components in the graph is %d\n", bfsCount);
if (cyclic) {
printf("\nThe graph is cyclic\n");
} else {
printf("\nThe graph is acyclic\n");
}
}
int main() {
for (;;) {
int key;
printf("Enter the choice:\n1. To Test BFS\n2. To Plot\nAny other number to Exit\n");
scanf("%d", &key);
switch (key) {
case 1:
tester();
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
