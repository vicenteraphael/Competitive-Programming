#include <iostream>
#include <map>
#include <string>

int matrix[100][100], sl[100], sc[100];
int vals[100], index = 99, cnt=0;
std::map<std::string, int> Map;

int Get (std::string str) {
    auto ind = Map.find(str);
    if (ind == Map.end()) {
        Map[str] = ++index;
        return index;
    }
    return ind->second;
}

void remapMatrix (int l, int c, int v1, int v2) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if (matrix[i][j] == v1) matrix[i][j] = v2;
        }
    }
}

void findVar_lines (int l, int c) {
    int var, val, filledSum, filledCnt;
    bool found, theresVar;
    for (int i = 0; i < l; ++i) {
        found = true; theresVar = false;
        filledSum = 0; filledCnt = 0;
        for (int j = 0; j < c; ++j) {
            if (theresVar) {
                if (matrix[i][j] >= 100 && matrix[i][j] != var) {
                    found = false;
                    break;
                }
            }
            if (matrix[i][j] >= 100) {
                var = matrix[i][j];
                theresVar = true;
            } else {
                filledSum += matrix[i][j];
                ++filledCnt;
            }
        }
        if (found) {
            ++cnt;
            val = (sl[i]-filledSum)/(c-filledCnt);
            vals[var-100] = val;
            remapMatrix(l, c, var, val);
        }
    }
}

void findVar_columns (int l, int c) {
    int var, val, filledSum, filledCnt;
    bool found, theresVar;
    for (int i = 0; i < c; ++i) {
        found = true; theresVar = false;
        filledSum = 0; filledCnt = 0;
        for (int j = 0; j < l; ++j) {
            if (theresVar) {
                if (matrix[j][i] >= 100 && matrix[j][i] != var) {
                    found = false;
                    break;
                }
            }
            if (matrix[j][i] >= 100) {
                var = matrix[j][i];
                theresVar = true;
            } else {
                filledSum += matrix[j][i];
                ++filledCnt;
            }
        }
        if (found) {
            ++cnt;
            val = (sc[i]-filledSum)/(l-filledCnt);
            vals[var-100] = val;
            remapMatrix(l, c, var, val);
        }
    }
}

void printmatrix (int l, int c) {
    for (int i = 0; i < l; ++i) { 
        for (int j = 0; j < c; ++j) {
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}

int main() {
    int l, c;
    scanf ("%d %d", &l, &c);
    std::string var;

    //lê a matriz
    for (int i = 0; i < l; ++i) { 
        for (int j = 0; j < c; ++j) {
            std::cin>>var;
            matrix[i][j] = Get(var);
        }
        scanf ("%d", &sl[i]);
    }
    for (int i = 0; i < l; ++i) scanf ("%d", &sc[i]);

    printmatrix(l, c);

    //procura a primeira variável: checando nas linhas e colunas
    while (cnt <= c) {
        findVar_columns(l, c);
        printmatrix(l, c);
        findVar_lines(l, c);
        printmatrix(l, c);
    }

    return 0;
}