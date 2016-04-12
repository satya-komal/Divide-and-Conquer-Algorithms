 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
   
int num;
void strassen(int a[][num], int b[][num], int c[][num], int size);
int main() {

int i, j, k, temp;

printf("Enter the size of nxn matrix:\n");

scanf("%d", &num);

temp = num;

if(num <= 0) {
printf("Enter a positive no which can be expressed in powers of 2:\n");
main();
}

else {
int m = isPowerOfTwo (num);
 if(m==1){

int a[num][num], b[num][num], c[num][num],d[num][num];

 //gets inputs for elements of  a and b from the random no generator function

for(i = 0; i < num; i++) {

for(j = 0; j < num; j++) {

 a[i][j]= rand()%10;

 }
}


for(i = 0; i < temp; i++) {

for(j = 0; j < temp; j++) {

 b[i][j]= rand()%10;

 }
}


printf("Matrix a:\n"); //printing the actual matrices for strassen's multiplication

for(i = 0; i < num; i++) {

for(j = 0; j < num; j++) {

printf("%d ", a[i][j]);

}

printf("\n");

}

printf("\nMatrix b:\n");

for(i = 0; i < num; i++) {

for(j = 0; j < num; j++) {

printf("%d ", b[i][j]);

}

printf("\n");

}
int n= num;
strassen(a, b, c, num);

printf("\nMatrix c obtained from Strassens multiplication is:\n");

for(i = 0; i < temp; i++) {

for(j = 0; j < temp; j++) {

printf("%d ", c[i][j]);

}

printf("\n");

   }
   
printf("\nMatrix d= a*b obtained from Normal multiplication is: \n ");   
   for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            d[i][j] = 0;
            for ( k = 0; k < n; k++)
            {  
                d[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    
    for ( i = 0; i < n; i++)
    { 
        for ( j = 0; j < n; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
   
   
  }
     else {
     printf("\nEnter a number which is a power of 2:\n");
     main();
     }
}
return 0;

}

void strassen(int a[][num], int b[][num], int c[][num], int size) {

int p1[size/2][size/2], p2[size/2][size/2], p3[size/2][size/2], p4[size/2][size/2], p5[size/2][size/2], p6[size/2][size/2], p7[size/2][size/2];

int temp1[size/2][size/2], temp2[size/2][size/2];

int q1, q2, q3, q4, q5, q6, q7, i, j;

if(size >= 2) { //give recursive calls

//p1

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp1[i][j] = a[i][j] + a[i + size / 2][j + size / 2];

}

}

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp2[i][j] = b[i][j] + b[i + size / 2][j + size / 2];

}

}

num = size / 2;

strassen(temp1, temp2, p1, size / 2);

//p2

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp1[i][j] = a[i + size / 2][j] + a[i + size / 2][j + size / 2];

}

}

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp2[i][j] = b[i][j];

}

}

num = size / 2;

strassen(temp1, temp2, p2, size / 2);

//p3

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp1[i][j] = a[i][j];

}

}

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp2[i][j] = b[i][j + size / 2] - b[i + size / 2][j + size / 2];

}

}

num = size / 2;

strassen(temp1, temp2, p3, size / 2);

//p4

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp1[i][j] = a[i + size / 2][j + size / 2];

}

}

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp2[i][j] = b[i + size / 2][j] - b[i][j];

}

}

num = size / 2;

strassen(temp1, temp2, p4, size / 2);

//p5

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp1[i][j] = a[i][j] + a[i][j + size / 2];

}

}

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp2[i][j] = b[i + size / 2][j + size / 2];

}

}

num = size / 2;

strassen(temp1, temp2, p5, size / 2);

//p6

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp1[i][j] = a[i + size / 2][j] - a[i][j];

}

}num = size / 2;

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp2[i][j] = b[i][j] + b[i][j + size / 2];

}

}

num = size / 2;

strassen(temp1, temp2, p6, size / 2);

//p7

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp1[i][j] = a[i][j + size / 2] - a[i + size / 2][j + size / 2];

}

}

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

temp2[i][j] = b[i + size / 2][j] + b[i + size / 2][j + size / 2];

}

}

num = size / 2;

strassen(temp1, temp2, p7, size / 2);

//c11

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

c[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];

}

}

//c12

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

c[i][j + size / 2] = p3[i][j] + p5[i][j];

}

}

//c21

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

c[i + size / 2][j] = p2[i][j] + p4[i][j];

}

}

//c22

for(i = 0; i < size / 2; i++) {

for(j = 0; j < size / 2; j++) {

c[i + size / 2][j + size / 2] = p1[i][j] + p3[i][j] - p2[i][j] + p6[i][j];

}

}

}

else if(size == 1) {

c[0][0] = a[0][0] * b[0][0];

}

}

int isPowerOfTwo (int x)
{
 while (((x % 2) == 0) && x > 1) /* While x is even and > 1 */
   x /= 2;
 return (x == 1);
}


