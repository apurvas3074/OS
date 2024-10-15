#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void clook(int req[], int n, int head) {
    int total_seek = 0, i;
    int left[100], right[100], l_count = 0, r_count = 0;

    for (i = 0; i < n; i++) {
        if (req[i] < head) left[l_count++] = req[i];
        if (req[i] > head) right[r_count++] = req[i];
    }

    qsort(left, l_count, sizeof(int), cmpfunc);
    qsort(right, r_count, sizeof(int), cmpfunc);

    printf("C-LOOK Seek Sequence: ");
    for (i = 0; i < r_count; i++) {
        total_seek += abs(head - right[i]);
        head = right[i];
        printf("%d ", head);
    }
    for (i = 0; i < l_count; i++) {
        total_seek += abs(head - left[i]);
        head = left[i];
        printf("%d ", head);
    }
    printf("\nTotal Seek Time (C-LOOK): %d\n", total_seek);
}

int main() {
    int n, i, head;
    int req[100];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    clook(req, n, head);

    return 0;
}





































































































/*
$ gcc clook.c -o clook  # Compiling the program (assuming the file is named clook.c)
$ ./clook                # Running the compiled program

Enter number of requests: 5
Enter request sequence: 40 10 30 50 20
Enter initial head position: 35
C-LOOK Seek Sequence: 40 50 10 20 30 
Total Seek Time (C-LOOK): 75

*/ 
