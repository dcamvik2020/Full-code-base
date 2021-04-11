#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};
/*
void transform (struct Rect * r)
{
    int a, b;
    a = r->lt.x * (-1);
    b = r->lt.y *(-1);

    r->lt.x = -r->rb.x;
    r->lt.y = -r->rb.y;

    r->rb.x = a;
    r->rb.y = b;
}
*/
struct Rect * transform (const struct Rect * src)
{
    struct Rect *s = (struct Rect *) malloc( 2 * sizeof(struct Point*));
    int x1, y1, x2, y2;
    x1 = src->lt.x;
    y1 = src->lt.y;
    x2 = src->rb.x;
    y2 = src->rb.y;

    s->lt.x = x1 - (y1 - y2);
    s->lt.y = y2 + x2 - x1;

    s->rb.x = x1;
    s->rb.y = y2;
    return s;
};

int main()
{
    struct Rect a = {{-1, 1}, {4, -2}};
    struct Rect * rect;
    rect = transform(&a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect->lt.x, rect->lt.y, rect->rb.x, rect->rb.y);
    free(rect);
    return 0;
}
