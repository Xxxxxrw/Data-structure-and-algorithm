#include <bits/stdc++.h>
using namespace std;
int a, b, c;
bool vis[21][21][21];
long long store[21][21][21];
long long w(int x, int y, int z)
{
    if(x <= 0 || y <= 0 || z <= 0) return 1;
    if(x > 20 || y > 20 || z > 20) return w(20, 20, 20);
    if(vis[x][y][z]) return store[x][y][z];
    if(x < y && y < z){
        store[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
        vis[x][y][z] = 1;
        return store[x][y][z];
    }
    store[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x-1, y-1, z-1);
    vis[x][y][z] = 1;
    return store[x][y][z];
}
int main()
{
    while(~scanf("%d%d%d", &a, &b, &c))
    {
    	if(a == -1 && b == -1 && c == -1) break; 
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}
