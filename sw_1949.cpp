#include <iostream>
using namespace std;
int ans = 0, N, K;
int pos_x[4] = {0, 1, 0, -1};
int pos_y[4] = {1, 0, -1, 0};
int arr[9][9];
int visited[9][9];
 
void find(int x, int y, int current, int depth, int used) {
    visited[x][y] = 1;
    if (ans < depth) ans = depth;
    for (int i = 0; i < 4; i++) {
        int nx = x + pos_x[i];
        int ny = y + pos_y[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
            if (current > arr[nx][ny]) {
                find(nx, ny, arr[nx][ny], depth + 1, used);
            }
            else if(!used){
                if (current > arr[nx][ny] - K) {
                    find(nx, ny, current - 1, depth + 1, 1);
                }
            }
        }
    }
    visited[x][y] = 0;
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int max = 0;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                if (arr[i][j] > max) max = arr[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == max) find(i, j, max, 1, 0);
            }
        }
        cout << "#" << t << " " << ans << "\n";
        ans = 0;
    }
    return 0;
}
