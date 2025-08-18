#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define GRID_SIZE 7

char specification[GRID_SIZE * GRID_SIZE];
bool visited[GRID_SIZE][GRID_SIZE] = {{false}};
int count = 0;

bool can_up(int index, int x, int y) {
    return y > 0 && !visited[x][y-1] && (specification[index] == '?' || specification[index] == 'U');
}

bool can_down(int index, int x, int y) {
    return y < GRID_SIZE-1 && !visited[x][y+1] && (specification[index] == '?' || specification[index] == 'D');
}

bool can_left(int index, int x, int y) {
    return x > 0 && !visited[x-1][y] && (specification[index] == '?' || specification[index] == 'L');
}

bool can_right(int index, int x, int y) {
    return x < GRID_SIZE-1 && !visited[x+1][y] && (specification[index] == '?' || specification[index] == 'R');
}

void search(int index, int x, int y) {
    if (index == GRID_SIZE * GRID_SIZE) return;
    if (x == 0 && y == GRID_SIZE-1) {
        if (index == GRID_SIZE * GRID_SIZE - 1) count ++;
        return;
    }

    if (can_up(index, x, y) && can_down(index, x, y) && !can_left(index, x, y) && !can_right(index, x, y)) return;
    if (!can_up(index, x, y) && !can_down(index, x, y) && can_left(index, x, y) && can_right(index, x, y)) return;

    if (can_up(index, x, y)) {
        visited[x][y-1] = true;
        search(index+1, x, y-1);
        visited[x][y-1] = false;
    }

    if (can_down(index, x, y)) {
        visited[x][y+1] = true;
        search(index+1, x, y+1);
        visited[x][y+1] = false;
    }

    if (can_left(index, x, y)) {
        visited[x-1][y] = true;
        search(index+1, x-1, y);
        visited[x-1][y] = false;
    }

    if (can_right(index, x, y)) {
        visited[x+1][y] = true;
        search(index+1, x+1, y);
        visited[x+1][y] = false;
    }
}

int main(){
    scanf("%s", specification);

    visited[0][0] = true;
    search(0, 0, 0);

    printf("%d\n", count);
    return EXIT_SUCCESS;
}
