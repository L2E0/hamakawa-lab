#include <stdio.h>
#include <math.h>

#define N 10



int main()
{
    int n, i, j, k;

    static double p, a[N][N], b[N], x[N], y[N], l[N][N], u[N][N];

    while (1)
    {
        puts("何元連立ですかぁ？ n =");
        scanf("%d", &n);
        if (n <= 1 || n >= (N - 1))
        {
            puts("8元連立までしか解けないんですけどっ!");
            continue;
        }

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
                scanf("%lf", &a[i][j]);
            scanf("%lf", &b[i]);
        }
        break;
    }

    // initialize
    for (i = 0; i < n; ++i)
        l[i][i] = 1;

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            u[i][j] = 0;

    // LUDecompsition
    for (i = 0; i < n; ++i)
    {
        p = a[i][i];
        if (fabs(p) < 1.0e-6)
        {
            puts("LU分解できませんよぉ？");
            return -1;
        }

        for (j = i; j < n + 1; ++j)
        {
            l[j][i] = a[j][i];
            a[i][j] = a[i][j] / p;
        }

        for (j = i + 1; j < n; ++j)
        {
            p = a[j][i];
            for (k = i; k < n + 1; ++k)
                a[j][k] = a[j][k] - a[i][k]  * p;
        }

        for (j = i; j < n; ++j)
            u[i][j] = a[i][j];
    }

    puts("下三角行列L");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
            printf("%lf ", l[i][j]);
        puts("");
    }
    puts("");
    puts("上三角行列U");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
            printf("%lf ", u[i][j]);
        puts("");
    }

    // LForwardsubs
    for (i = 0; i < n; ++i)
        y[i] = b[i];

    for (i = 0; i < n; ++i)
    {
        y[i] /= l[i][i];
        for (j = i + 1; j < n; ++j)
            y[j] -= y[i] * l[j][i];
    }

    // UBackwardsubs
    for (i = 0; i < n; ++i)
        x[i] = y[i];

    for (i = n - 1; i >= 0; --i)
    {
        x[i] /= u[i][i];
        for (j = i - 1; j >= 0; --j)
            x[j] -= x[i] * u[j][i];
    }

    puts("計算終わりましたぁ");

    for (i = 0; i < n; ++i)
        printf("x%d = %10.6lf\n", i + 1, x[i]);

    return 0;
}
