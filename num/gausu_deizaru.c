#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int i, j, l, m;
	static float a[20][20], x[20], b[20], w, anorm, xnorm, eps;
	char z, zz;
	eps = 1.0e-6;
	while(1){
		printf("�@��̐�m�̓���");
		scanf("%d",&m);
		if((m <= 1) || (9 <= m))  continue;
		printf("�W���s��a�ƒ萔��b����͂��Ă�������\n\n");
		for(i=1; i<=m; i++){
			for(j=1; j<=m; j++){
				printf("a( %0d, %0d ) = " ,i,j);
				scanf("%f%c",&a[i][j],&zz);
			}
			printf("b( %d ) = ",i);
			scanf("%f%c" ,&b[i],&zz);
			printf("\n");
		}
		printf("\n���������͂��܂����B(y/n) ");
		scanf("%c%c",&z,&zz);
		if(z == 'y') break;
	}
	
	for(l=1; l<=30; l++){
		printf("l = %3d  ",l);
		for(i=1; i<=m; i++){
			printf(" %13.6f ", x[i]);
		}
		printf("\n");
		anorm = 0.0;
		xnorm = 0.0;
		for(i=1; i<=m; i++){
			w = b[i];
			for(j=1; j<=m; j++){
				if (i==j) continue;
				w = w - a[i][j] * x[j];
			}
			w = w / a[i][i];
			anorm = anorm + fabs( w - x[i] );
			xnorm = xnorm + fabs( w );
			x[i] = w;
		}
		if(anorm / xnorm <= 1.0e-6){
			printf("\n�������܂���\n");
			for(i=1; i<=m; i++){
				printf("x%d = %10.6f\n",i,x[i]);
			}
			return 0;
		}
	}
	printf("\n�������܂���ł����B\n");
	return 0;
}