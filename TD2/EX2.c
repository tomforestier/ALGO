#include <stdio.h>
#include <stdlib.h>


void swap_int(int *a, int *b) {
    int temp = *a; 
    *a = *b;       
    *b = temp;     
}


int is_sorted_ascending(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void selection_sort(int A[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int min = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap_int(&A[i], &A[min]);
        }
    }
}

void insertion_sort(int A[], int n) {
    for (int i = 1; i <= n - 1; i++) {        
        int key = A[i];        
        int j = i - 1;        
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];            
            j = j - 1;
        }        
        A[j + 1] = key;
    }
}

void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap_int(&A[j], &A[j + 1]);
            }
        }
    }
}

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;    

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0; 
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void merge_sort(int A[], int left, int right) {
    if (left < right) {        
        int mid = left + (right - left) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (A[j] <= pivot) {
            i++;
            swap_int(&A[i], &A[j]);
        }
    }
    swap_int(&A[i + 1], &A[high]);
    return (i + 1);
}

void quick_sort(int A[], int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quick_sort(A, low, p - 1);
        quick_sort(A, p + 1, high);
    }
}

int main() {
    int n = 10000; 

    int *original = (int *)malloc(n * sizeof(int));
    int *A = (int *)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        original[i] = rand() % 1000000;
    }

    clock_t begin, end;
    double t_selection, t_insertion, t_bubble, t_merge, t_quick;

    copy_array(original, A, n);
    begin = clock();
    selection_sort(A, n);
    end = clock();
    t_selection = (double)(end - begin) / CLOCKS_PER_SEC;

    copy_array(original, A, n);
    begin = clock();
    insertion_sort(A, n);
    end = clock();
    t_insertion = (double)(end - begin) / CLOCKS_PER_SEC;

    copy_array(original, A, n);
    begin = clock();
    bubble_sort(A, n);
    end = clock();
    t_bubble = (double)(end - begin) / CLOCKS_PER_SEC;

    copy_array(original, A, n);
    begin = clock();
    merge_sort(A, 0, n - 1);
    end = clock();
    t_merge = (double)(end - begin) / CLOCKS_PER_SEC;

    copy_array(original, A, n);
    begin = clock();
    quick_sort(A, 0, n - 1);
    end = clock();
    t_quick = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Resultats pour n = %d :\n", n);
    printf("- Selection Sort : %.6f secondes\n", t_selection);
    printf("- Insertion Sort : %.6f secondes\n", t_insertion);
    printf("- Bubble Sort    : %.6f secondes\n", t_bubble);
    printf("- Merge Sort     : %.6f secondes\n", t_merge);
    printf("- Quick Sort     : %.6f secondes\n", t_quick);

    return 0;
}
