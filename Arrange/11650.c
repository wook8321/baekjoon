#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

int compare(void* a, void* b)
{
    point* a1 = (point*) a;
    point* b1 = (point*) b;

    if(a1->x != b1->x) return a1->x - b1->x;

    else return a1->y - b1->y;
}

int main()
{
    int n;
    scanf("%d", &n);

    point* points = malloc(sizeof(point) * n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qsort(points, n, sizeof(point), compare);

    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    free(points);

    return 0;
}