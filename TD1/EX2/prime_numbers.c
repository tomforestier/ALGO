#include <stdio.h>
#include <time.h>
//1
int prime_naif(int n) {
    int c = 0;
    for (int i = 2; i < n; i++) {
        int premier = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                premier = 0;
                break;
            }
        }
        if (premier) {
            c++;
        }
    }
    return c;
}
//2
int prime_dyn(int n) {
    int prime[n];
    for (int i = 0; i < n; i++) {
        prime[i] = 1;
    }
    int c = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i] == 1) {
            c++;
            for (int j = i * 2; j < n; j += i) {
                prime[j] = 0;
            }
        }
    }
    return c;
}
//4 CLOCK
int main() {
    int n = 100;
    clock_t begin = clock();
    int c1 = prime_naif(n);
    clock_t end = clock();
    double temps1 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Naive    : %d premiers, %f secondes\n", c1, temps1);
    begin = clock();
    int c2 = prime_dyn(n);
    end = clock();
    double temps2 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Efficace : %d premiers, %f secondes\n", c2, temps2);
    return 0;
}
