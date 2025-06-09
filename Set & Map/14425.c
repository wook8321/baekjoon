/*
    문자열 비교를 이중 루프로 하기 때문에 시간 복잡도는 O(N * M)
    그로 인해 시간 초과 발생

#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    char first[10000][501];
    char second[10000][501];

    for(int i = 0; i < N; i++)
    {
        scanf("%s", first[i]); 
    }

    for(int i = 0; i < M; i++)
    {
        scanf("%s", second[i]); 
    }

    int count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(strcmp(first[i], second[j]) == 0)
            {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}

=> 트라이 or 해쉬 테이블(C언어는 직접 구현해야 해서 복잡도 높음)

    트라이(Trie)를 통해 문자열을 글자 단위로 트리 구조에 저장해
    문자열 검색을 O(L)로 가능 (L은 문자열 길이)

*/

#include <stdio.h>
#include <stdlib.h>


typedef struct TrieNode {
    struct TrieNode* children[26];  // 알파벳 개수만큼 포인터 배열 선언 => a~z까지의 자식 노드
    int end;
} TrieNode;

TrieNode* create_node() {
    TrieNode* node = TrieNode* malloc(sizeof(TrieNode));
    for(int i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    } 
    node->end = 0;

    return node;
}

void insert(TrieNode* root, char* str)
{
    TrieNode* cur = root;
    for(int i = 0; ; i++)
    {
        int idx = str[i] - 'a';
        if(!cur->children[idx]) 
            cur->children[idx] = create_node;
        cur = cur->children[idx];
    }
    
    cur->end = 1;
}

int search(TrieNode* root, char* str)
{
    TrieNode* cur = root;
    for(int i = 0; ; i++)
    {
        int idx = str[i] - 'a';
        if(!cur->children[idx])
            return 0;
        cur = cur->children[idx];
    }
    
    return cur->end;
}

void free_trie(TrieNode* root)
{
    for(int i = 0; i < 26; i++)
    {
        if(root->children[i])
            free_trie(root->children[i]);
    }

    free(root);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    TrieNode* root = create_node();
    char str[501];

    for(int i = 0; i < N; i++)
    {
        scanf("%s", str);
        insert(root, str);
    }

    int count = 0;
    
    for(int i = 0; i < M; i++)
    {
        scanf("%s", str);
        if(search(root, str))
            count++;
    }

    printf("%d", count);

    free_trie(root);

    return 0;
}