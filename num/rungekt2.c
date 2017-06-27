#include<stdio.h>
double fnf(double x, double y)
{
    return (y - 12.0*x + 3.0);
}

int main(void)
{
    int i;
    double x, y, h, k1, k2, k;
    char zz;
    printf("ルンゲクッタ二次公式により\n\n");
    printf("dy/dx = y - 12.0 * x + 3.0 を解きます");
    printf("\n\nエンターキーを押してください.\n");
    scanf("%c" ,&zz);
    printf("    X               Y\n");
    x = 0.0;
    y = 1.0;
    h = 0.1;
    printf("%10.6lf         %10.6lf\n",x,y);
    for(i=1; i<=20; i++){
        k1 = h * fnf(x, y);
        k2 = h * fnf(x+h, y+k1);
        k = (k1 + k2) / 2.0;
        x = x + h;
        y = y + k;
        printf("%10.6lf     %10.6lf\n",x,y);
    }
    return 0;
}

