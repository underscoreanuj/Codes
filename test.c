#include <stdio.h>
int main()
{
    int r, h;
    float area;
    printf("Enter radius of the cylinder: \n");
    scanf("%d", &r);
    printf("enter height of cylinder: \n");
    scanf("%d", &h);
    area = 3.14 * r * r * h;
    printf("area of cylinder is= %f \n", area);
    return 0;
}