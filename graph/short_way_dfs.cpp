// S = final, I = start, # = block

const int MAX = 1001;
vector<vector<char>> ady (MAX, vector<char>(MAX));
vector<vector<int>> visited (MAX, vector<int>(MAX, -1));
struct Estado{
    int x,y,d;
    Estado(int _x, int _y, int _d):x(_x), y(_y), d(_d){};
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void BFS(int x,int y,int h,int w){
    Estado inicial = {x, y, 1};
    queue<Estado> Q;
    Q.push(inicial);
    for(int i=0;i<h;i++){
        fill(visited[i].begin(), visited[i].end(), -1);
    }
    while(!Q.empty()){
        Estado actual = Q.front();
        Q.pop();
        if(ady[actual.x][actual.y] == 'S'){
            return;
        }
        visited[actual.x][actual.y] = actual.d;
        for(int i=0;i<4;i++){
            int nx = dx[i] + actual.x;
			int ny = dy[i] + actual.y;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && ady[nx][ny] != '#' && (visited[nx][ny]==-1 || visited[nx][ny]>actual.d)) {
                visited[nx][ny] = actual.d;
                Estado adyacente = {nx, ny, actual.d + 1};
                Q.push(adyacente);
            }
        }
    }
    return;
}
