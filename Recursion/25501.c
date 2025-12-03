#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int *count){
    (*count)++; 
    // 그냥 count를 증가시키면 복사본인 지역 변수만 증가한다.
    // -> isPalindrome 함수의 실제 변수 count는 증가하지 않음.
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, count);
}

void isPalindrome(const char *s){
    int count = 0;
    int result = recursion(s, 0, strlen(s)-1, &count);
    printf("%d %d\n", result, count);
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        char temp[1001];
        scanf("%s", temp);
        isPalindrome(temp);
    }

    return 0;
}