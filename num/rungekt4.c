#include<stdio.h>
double fnf(double x, double y)
{
    return (y - 12.0*x + 3.0);
}

int main(void)
{
    int i;
    double x, y, h, k1, k2, k3, k4, k;
    char zz;
    printf("ルンゲクッタ４次公式により\n\n");
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
        k2 = h * fnf(x+h/2, y+k1/2);
        k3 = h * fnf(x+h/2, y+k2/2);
        k4 = h * fnf(x+h, y+k3);

        k = (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x = x + h;
        y = y + k;
        printf("%10.6lf     %10.6lf\n",x,y);
    }
    return 0;
}

