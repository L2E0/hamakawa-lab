#include <stdio.h>
#include <math.h>

#define N 10

int main()
{
    int n, i, j, k;
    char z, zz;

    static double a[N][N + N], p, s;

    while (1)
    {
        puts("何元行列？ n =");
        scanf("%d", &n);
        if (n <= 1 || n >= (N - 1)) continue;

        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                scanf("%lf", &a[i][j]);

        for (i = 0; i < n; ++i)
            for (j = n; j < n * 2; ++j)
                a[i][j] = (i == j - n);

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n * 2; ++j)
                printf("%lf ", a[i][j]);
            puts("");
        }
        break;
    }

    for (i = 0; i < n; ++i)
    {
        p = a[i][i];
        if (fabs(p) < 1.0e-6)
        {
            puts("一意解を持たない");
            return -1;
        }

        for (j = i; j < n * 2; ++j)
            a[i][j] = a[i][j] / p;

        for (j = 0; j < n; ++j)
        {
            if(j == i) continue;
            p = a[j][i];
            for (k = i; k < n * 2; ++k)
                a[j][k] = a[j][k] - a[i][k]  * p;
        }
    }

    for (i = 0; i < n; ++i)
    {
        for (j = n; j < n * 2; ++j)
            printf("%.4lf ", a[i][j]);
        puts("");
    }

    return 0;
}
