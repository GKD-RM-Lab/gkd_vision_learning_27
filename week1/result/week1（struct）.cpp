#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct Armor
{
    int color;
    int lef;
    int top;
    int width;
    int height;
};
Armor a[101];
int number = 0;
int main()
{
    int x = 320, y = 240;
    char derect;
    int n;
    while (cin >> derect && derect != 'q')
    {
        if (derect == 'w' || derect == 's' || derect == 'a' || derect == 'd')
        {
            cin >> n;
            if (derect == 'w')
                y -= n;
            if (derect == 's')
                y += n;
            if (derect == 'a')
                x -= n;
            if (derect == 'd')
                x += n;
            if (x < 0)
                x = 0;
            if (y < 0)
                y = 0;
            if (x >= 640)
                x = 639;
            if (y >= 480)
                y = 479;
            printf("准星:(%d,%d)\n", x, y);
        }
        else if (derect == 'x')
        {
            cin >> a[number].color >> a[number].lef >> a[number].top >> a[number].width >> a[number].height;
            number++;
            int stage = -1;
            int mindis = 0, maxarea = 0;
            int bcx = 0, bcy = 0;
            for (int i = 0; i < number; i++)
            {
                if (a[i].color != 1)
                    continue;
                int area = a[i].width * a[i].height;
                if (area < 400)
                    continue;
                int xc = a[i].lef + a[i].width / 2;
                int yc = a[i].top + a[i].height / 2;
                int d = abs(xc - x) + abs(yc - y);
                if (stage == -1 || d < mindis || (d == mindis && area > maxarea))
                {
                    stage = i;
                    mindis = d;
                    maxarea = area;
                    bcx = xc;
                    bcy = yc;
                }
            }
            if (stage == -1)
            {
                printf("无有效目标\n");
            }
            else
            {
                int dx = bcx - x;
                int dy = bcy - y;
                printf("最近敌方装甲板:(%d,%d),距离:%d,调整:[", bcx, bcy, mindis);
                if (dx < 0)
                {
                    printf("a %d", -dx);
                }
                else if (dx > 0)
                {
                    printf("d %d", dx);
                }
                if (dx != 0 && dy != 0)
                    printf(", ");
                if (dy < 0)
                {
                    printf("w %d", -dy);
                }
                else if (dy > 0)
                {
                    printf("s %d", dy);
                }
                printf("]\n");
            }
        }
    }
    return 0;
}
