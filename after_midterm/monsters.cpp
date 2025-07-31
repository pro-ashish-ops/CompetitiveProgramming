#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n, m;
vector<string> grid;
vector<vector<int>> distMonster, distPlayer;
vector<vector<pii>> parent;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dirChar[] = {'D', 'U', 'R', 'L'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfsMonsters(queue<pii>& q) {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && distMonster[nx][ny] > distMonster[x][y] + 1) {
                distMonster[nx][ny] = distMonster[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfsPlayer(pii start, pii& end) {
    queue<pii> q;
    q.push(start);
    distPlayer[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            end = {x, y};
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!isValid(nx, ny)) continue;
            if (distPlayer[nx][ny] != 1e9) continue;
            if (distMonster[nx][ny] <= distPlayer[x][y] + 1) continue;

            distPlayer[nx][ny] = distPlayer[x][y] + 1;
            parent[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }

    return false;
}

string reconstructPath(pii start, pii end) {
    string path;
    pii cur = end;
    while (cur != start) {
        pii p = parent[cur.first][cur.second];
        for (int d = 0; d < 4; d++) {
            if (p.first + dx[d] == cur.first && p.second + dy[d] == cur.second) {
                path.push_back(dirChar[d]);
                break;
            }
        }
        cur = p;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    distMonster.assign(n, vector<int>(m, 1e9));
    distPlayer.assign(n, vector<int>(m, 1e9));
    parent.assign(n, vector<pii>(m, {-1, -1}));

    pii start;
    queue<pii> monsterQ;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
            if (grid[i][j] == 'M') {
                distMonster[i][j] = 0;
                monsterQ.push({i, j});
            }
        }
    }

    bfsMonsters(monsterQ);

    pii exitCell;
    if (bfsPlayer(start, exitCell)) {
        cout << "YES\n";
        string path = reconstructPath(start, exitCell);
        cout << path.size() << "\n" << path << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
