#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int count = 0;
int stringmatching(char *text, char *pattern, int n, int m, int whoCalled) {
count = 0;
for (int i = 0; i <= n - m; i++) {
int j = 0;
while (j < m) {
count++;
if (pattern[j] != text[i + j])
break;
j++;
}
if (j == m) {
if(!whoCalled) printf("THE PATTERN FOUND\n");
return count;
}
}
if(!whoCalled) printf("THE PATTERN NOT FOUND\n");
return count;
}
void plotter() {
FILE *f1 = fopen("stringbest.txt", "a");
FILE *f2 = fopen("stringworst.txt", "a");
FILE *f3 = fopen("stringavg.txt", "a");
char *text = (char *)malloc(1000 * sizeof(char));
char *pattern;
for (int i = 0; i < 1000; i++) {
*(text + i) = 'a';
}
int m = 10, n = 1000;
while (m <= 1000) {
pattern = (char *)malloc(m * sizeof(char));
// For Best case
for (int i = 0; i < m; i++)
pattern[i] = 'a';
stringmatching(text, pattern, n, m, 1);
fprintf(f1, "%d\t%d\n", m, count);
// For Worst casepattern[m - 1] = 'b';
stringmatching(text, pattern, n, m, 1);
fprintf(f2, "%d\t%d\n", m, count);
// For Average case
for (int i = 0; i < m; i++)
pattern[i] = 97 + rand() % 3;
stringmatching(text, pattern, n, m, 1);
fprintf(f3, "%d\t%d\n", m, count);
free(pattern);
if (m < 100)
m += 10;
else
m += 100;
}
free(text);
fclose(f1);
fclose(f2);
fclose(f3);
}
int main() {
int m, n;
char text[100], pattern[100];
while (1) {
printf("ENTER 1. TO TEST STRING MATCHING\n2. TO PLOT STRING MATCHING\n3. TO EXIT\n");
int ch;
scanf("%d", &ch);
switch (ch) {
case 1:
printf("ENTER THE PATTERN LENGTH\n");
scanf("%d", &m);
printf("ENTER THE PATTERN\n");
getchar(); // Consume the newline character left in the input buffer
fgets(pattern,sizeof(pattern), stdin);
pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character from the input
printf("ENTER THE TEXT LENGTH\n");
scanf("%d", &n);
printf("ENTER THE TEXT\n");
getchar(); // Consume the newline character left in the input buffer
fgets(text, sizeof(text), stdin);text[strcspn(text, "\n")] = '\0'; // Remove the newline character from the input
int comparisons = stringmatching(text, pattern, n, m, 0);
printf("Number of comparisons: %d\n", comparisons);
break;
case 2:
plotter();
break;
case 3:
exit(0);
}
}
return 0;
}
