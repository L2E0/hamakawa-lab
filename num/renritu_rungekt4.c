#include<stdio.h>

double fnf(double x, double y, double z)
{
    return (y - 12.0*x + z);
}

double fng(double x, double y, double z)
{
    return (y - 9.0*x + z);
}

int main(void)
{
    int i;
    double x, y, z, h, k1, k2, k3, k4, l1, l2, l3, l4, k, l;
    char zz;
    printf("ルンゲクッタ４次公式により\n\n");
    printf("|dy/dx = y - 12.0*x + z\n");
    printf("|dy/dx = y - 9.0*x + z\n\nの連立微分方程式を解きます");
    printf("\n\nエンターキーを押してください.\n");
    scanf("%c" ,&zz);
    printf("    X               Y               Z\n");
    x = 0.0;
    y = 1.0;
    z = 3.0;
    h = 0.1;
    printf("%10.6lf     %10.6lf     %10.6lf\n",x,y,z);
    for(i=1; i<=30; i++){
        k1 = h * fnf(x, y, z);
        l1 = h * fng(x, y, z);
        k2 = h * fnf(x+h/2, y+k1/2, z+l1/2);
        l2 = h * fng(x+h/2, y+k1/2, z+l1/2);
        k3 = h * fnf(x+h/2, y+k2/2, z+l2/2);
        l3 = h * fng(x+h/2, y+k2/2, z+l2/2);
        k4 = h * fnf(x+h, y+k3, z+l3);
        l4 = h * fng(x+h, y+k3, z+l3);

        k = (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        l = (l1 + 2*l2 + 2*l3 + l4) / 6.0;

        x = x + h;
        y = y + k;
        z = z + l;
        printf("%10.6lf     %10.6lf     %10.6lf\n",x,y,z);
    }
    return 0;
}

