#include<stdio.h>

int n, nf;
int in[100], p[50], hit = 0;
int pgfaultcnt = 0;

void initialize() {
    pgfaultcnt = 0;
    for (int i = 0; i < nf; i++)
        p[i] = 9999;
}

int isHit(int data) {
    hit = 0;
    for (int j = 0; j < nf; j++) {
        if (p[j] == data) {
            hit = 1;
            break;
        }
    }
    return hit;
}

void optimal() {
    initialize();
    int near[50];
    for (int i = 0; i < n; i++) {
        printf("\nFor %d :", in[i]);
        if (isHit(in[i]) == 0) {
            for (int j = 0; j < nf; j++) {
                int pg = p[j], found = 0;
                for (int k = i; k < n; k++) {
                    if (pg == in[k]) {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                }
                if (!found) near[j] = 9999;
            }
            int max = -9999, repindex;
            for (int j = 0; j < nf; j++) {
                if (near[j] > max) {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
            for (int k = 0; k < nf; k++)
                if (p[k] != 9999) printf(" %d", p[k]);
        } else {
            printf("No page fault");
        }
    }
    printf("\nTotal no of page faults: %d", pgfaultcnt);
}

int main() {
    printf("\nEnter length of page reference sequence: ");
    scanf("%d", &n);
    printf("\nEnter the page reference sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("\nEnter no of frames: ");
    scanf("%d", &nf);

    optimal();
    return 0;
}
















































































/* 
$ gcc page_replacement.c -o run  # Compile the program
$ ./run  # Run the program

Enter length of page reference sequence: 12
Enter the page reference sequence: 7 0 1 2 0 3 0 4 2 3 0 3 2
Enter number of frames: 3

For 7 : 7
For 0 : 7 0
For 1 : 7 0 1
For 2 : 0 1 2
For 0 : No page fault
For 3 : 1 2 3
For 0 : 2 3 0
For 4 : 3 0 4
For 2 : 0 4 2
For 3 : 4 2 3
For 0 : 2 3 0
For 3 : No page fault
For 2 : No page fault
Total no of page faults: 9
*/