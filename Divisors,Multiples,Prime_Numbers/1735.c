#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int denom, numer;
    denom = b * d;          // 분모
    numer = a * d + b * c;  // 분자

    int g = gcd(denom, numer);

    denom /= g;
    numer /= g;

    printf("%d %d", numer, denom);

    return 0;
}