//probably accepted
#include <stdio.h>

#define MAXN 100

int Sx, Sy;
char matrix[MAXN][MAXN];
static int mark[MAXN][MAXN];
int l, c, found_o = 0, found_s = 0;

void dfs (int sx, int sy) {
    mark[sx][sy] = 1;
    if (matrix[sx][sy] == 'o') found_o = 1;
    if (!found_s) {Sx = sx; Sy = sy;}
    int coord[4][2] = {{sx+1, sy}, {sx-1, sy}, {sx, sy+1}, {sx, sy-1}};
    int px, py, cnt=0;
    for (int i =0;i<4;++i) {
        px = coord[i][0]; py = coord[i][1];
        if (px >= 0 && px < l && py >= 0 && py < c && !mark[px][py] && matrix[px][py] != '.') {
            dfs (px, py);
        } else {
            ++cnt;
            if (cnt==4 && !found_s && matrix[sx][sy] != 'o') found_s = 1;
        }
    }
}

int main() {
   scanf ("%d %d", &l, &c);
   for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf (" %c", &matrix[i][j]);
        }
   }
   for (int i=0;i<l;++i) {
       for (int j=0;j<c;++j) {
           if (!mark[i][j] && matrix[i][j] != '.') dfs (i, j);
           if (found_o && found_s) break;
           found_s = 0;
       }
       if (found_o && found_s) break;
   }
   printf ("%d %d\n", Sx+1, Sy+1);
   return 0;
}
