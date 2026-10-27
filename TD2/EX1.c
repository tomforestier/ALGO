#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

int is_sorted_increasing(int L[], int length){
    for (int i=0; i<=length-2; i++){
        if (L[i] >= L[i+1])
            return 0;
    }
    return 1;
}

int linear_search(int L[], int length, int T){
    for (int i=0; i<length; i++){
        if (L[i] == T)
            return i;
    }
    return -1;
}

int min_val(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int jump_search(int L[], int T, int jump, int length){
    if (is_sorted_increasing(L, length) == 0 ){
        return -1;
    }
    int m = jump;
    int prev = 0;

    while (L[min_val(m, length) - 1] < T){
        prev = m;
        m = m + jump;
        if (prev >= length) {
            return -1;
        }
    }
    for (int i = prev; i < min_val(m, length); i++){
        if (L[i] == T) {
            return i;
        }
    }

    return -1;
}

int binary_search(int L[], int T, int length){
    if (is_sorted_increasing(L, length) == 0) {
        return -1;
    }
    int low = 0; 
    int high = length - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if (L[mid] == T){
            return mid;
        }
        if (L[mid] < T){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main(){
    int L[] = 
    int length = 10;
    int T = 23;
    int jump = (int)sqrt(length);

   clock_t begin, end;
    unsigned long millis;
    
    volatile int res;

    // Linear search
    begin = clock();
    res = linear_search(L, length, T);
    end = clock(); 
    millis = (end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("Finished linear search in %ld ms (Index: %d)\n", millis, res);

    // Jump search
    begin = clock();
    res = jump_search(L, T, jump, length);
    end = clock();
    millis = (end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("Finished jump search in %ld ms (Index: %d)\n", millis, res);

    // Binary search
    begin = clock();
    res = binary_search(L, T, length);
    end = clock();
    millis = (end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("Finished binary search in %ld ms (Index: %d)\n", millis, res);

    return 0;
}