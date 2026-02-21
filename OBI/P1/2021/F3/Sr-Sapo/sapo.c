#include <stdio.h>

#define maxn 101

int x, y;
int ix, iy, nx, ny;
static int tab[maxn][maxn];

static int dx[12] = {1, 2, 3, -1, -2, -3, 0, 0, 0, 0, 0, 0};
static int dy[12] = {0, 0, 0, 0, 0, 0, 1, 2, 3, -1, -2, -3};

static int mark[maxn][maxn];

int px, py;

int dfs(int cx, int cy) {
    mark[cx][cy] = 1;
    for (int i = 0; i < 12; ++i) {
        px = cx + dx[i]; py = cy + dy[i];
        if (px >= 0 && px <= x && py >= 0 && py <= y && tab[px][py] && !mark[px][py]) {
            if (px == nx && py == ny) return 1;
            if (dfs(px, py)) return 1;
        }
    }
    return 0;
}

int main() {
    int n, tx, ty;
    scanf ("%d %d %d", &x, &y, &n);
    while (n--) {
        scanf ("%d %d", &tx, &ty);
        tab[tx][ty] = 1;
    }
    scanf ("%d %d %d %d", &ix, &iy, &nx, &ny);
    puts(dfs(ix, iy) ? "S" : "N");
    return 0;
}
