    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int cmp(void* a, void* b)
    {
        char* pa = *(char**) a;
        char* pb = *(char**) b;

        return strcmp(pa, pb);
    }

    int main()
    {
        int N, M;
        scanf("%d %d", &N, &M);

        char** listen = (char **)malloc(N * sizeof(char*));

        for(int i = 0; i < N; i++)
        {
            listen[i] = (char *)malloc(21 * sizeof(char));
            scanf("%s", listen[i]);
        }

        qsort(listen, N, sizeof(char *), cmp);

        char** both = (char **)malloc(N * sizeof(char *));
        int both_count = 0;

        for(int i = 0; i < M; i++)
        {
            char name[21];
            scanf("%s", name);

            char *key = name;
            // bsearch 첫 번째 인자는 listen 배열의 원소와 같은 타입이어야 함. 
            // listen의 각 원소는 char* 이므로 key도 char* 타입으로 맞추어 넣어준다.
            if(bsearch(&key, listen, N, sizeof(char *), cmp))
            {
                both[both_count] = (char *)malloc(21 * sizeof(char));
                strcpy(both[both_count], name);
                // both[both_count] = strdup(name); => malloc과 strcpy의 기능을 동시에 수행
                both_count++;
            }
        }

        qsort(both, both_count, sizeof(char *), cmp);

        printf("%d\n", both_count);
        
        for(int i = 0; i < both_count; i++)
        {
            printf("%s\n", both[i]);
            free(both[i]);
        }

        for(int i = 0; i < N; i++)
        {
            free(listen[i]);
        }

        free(listen);
        free(both);

        return 0;
    }