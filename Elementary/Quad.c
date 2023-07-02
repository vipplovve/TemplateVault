#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c;
    int i;
    float s1,s2,d;
    printf("Enter Values of A,B and C as in (Ax^2 +Bx +C=0): ");
    scanf("%f %f %f",&a,&b,&c);
    d=(b*b)-(4*a*c);
    if(d<0)
        i=1;
    else if(d>0)
        i=2;
    else
        i=3;
    switch(i)
    {
    case 1:
        d=sqrt(-d);
        s1=(b)/2*a;
        s2=(d)/2*a;
        printf("\nThe Complex Solutions to this Equation are:- \n");
        printf("%.2f + %.2f i \n",s1,s2);
        printf("%.2f - %.2f i \n",s1,s2);

        break;

    case 2:
        d=sqrt(d);
        s1=(b)/2*a;
        s2=(d)/2*a;
        printf("\nThe Solutions to this Equation are:- \n");
        printf("%.2f \n",s1-s2);
        printf("%.2f \n ",s1+s2);
        break;

    case 3:
        printf("\nThe solutions to this Equation Coincide and they are: ");
        printf("%.2f and %.2f",-b/2*a,-b/2*a);
        break;


    }
    return 0;

}
