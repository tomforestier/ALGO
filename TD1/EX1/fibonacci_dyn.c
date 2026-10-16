
#include <stdio.h>
#include <time.h>

unsigned long long fibonacci2(int n, unsigned long long DPFib[]) {
    if (n <= 1) {
        return n;
    }

    if (DPFib[n] != 0) {
        return DPFib[n];
    }

    DPFib[n] = fibonacci2(n - 1, DPFib) + fibonacci2(n - 2, DPFib);
    return DPFib[n];
}

int main() {
    int n = 90;
    unsigned long long DPFib[n + 1];
    for (int i = 0; i <= n; i++) {
        DPFib[i] = 0;
    }

    clock_t begin = clock();
    printf("Resultat: %llu\n", fibonacci2(n, DPFib));

    clock_t end = clock();
    unsigned long millis = (end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("Finished in %lu ms\n", millis);

    return 0;
}
