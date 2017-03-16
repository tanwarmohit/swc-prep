#include <iostream>
#include <stdio.h>

using namespace std;

static int keys[4];
static char MAP[101][101];
static int visited[101][101];
static int R, C;
static int minSteps = 1 << 30;
static int finish;
static int currentSteps;


static bool CheckRange(int i, int j){
    return (i >= 0 && i < R && j >= 0 && j < C);
}

static bool CheckConnectivity(int i, int j){
    return CheckRange(i, j) && MAP[i][j] != '#';
}

static bool CheckPath(){
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            if(MAP[i][j] == 'X'){
                if(CheckConnectivity(i, j-1))
                    return true;
                if(CheckConnectivity(i, j+1))
                    return true;
                if(CheckConnectivity(i-1, j))
                    return true;
                if(CheckConnectivity(i+1, j))
                    return true;
            }
        }

    return false;
}

static void DFS(int i, int j, int indent){
    if(!CheckRange(i, j))
        return;

    if(finish)
        return;

    if(minSteps < currentSteps)
        return;

    if(visited[i][j])
        return;

    visited[i][j] = 1; 

    if(MAP[i][j] == 'X'){
        //cout << "Found X\n";
        minSteps = currentSteps;
        finish = 1;
        return;
    }

    bool cond = false;

    if(MAP[i][j] == '#')
        return;

    /*
    for(int k = 0; k < indent; k++)
        cout << " ";
    cout << i << " " << j << " " << MAP[i][j] << " " << visited[i][j] << " " << currentSteps << " " << keys[0] << " " << keys[1] << " " << keys[2] << " " << keys[3] << "\n";
    */

    if((MAP[i][j] == '.' || MAP[i][j] == '*')){
        cond = true;
        currentSteps++;
    }

    if(!cond && MAP[i][j] == 'B'){
        if(!keys[0])
            ;//currentSteps++;
        else
            cond = true;
    }
    if(!cond && MAP[i][j] == 'Y'){
        if(!keys[1])
            ;//currentSteps++;
        else
            cond = true;
    }
    if(!cond && MAP[i][j] == 'R'){
        if(!keys[2])
            ;//currentSteps++;
        else
            cond = true;
    }
    if(!cond && MAP[i][j] == 'G'){
        if(!keys[3])
            ;//currentSteps++;
        else
            cond = true;
    }
    
    if(!cond && MAP[i][j] == 'b'){
        keys[0] = 1;
        cond = true;
    }
   if(!cond && MAP[i][j] == 'y'){
        keys[1] = 1;
        cond = true;
    }
   if(!cond && MAP[i][j] == 'r'){
        keys[2] = 1;
        cond = true;
    }
   if(!cond && MAP[i][j] == 'g'){
        keys[3] = 1; 
        cond = true;
    }

    if(cond){
        MAP[i][j] = '.';
        DFS(i+1, j, indent+1);
        DFS(i, j+1, indent+1);
        DFS(i-1, j, indent+1);
        DFS(i, j-1, indent+1);
        currentSteps++;
    }

    visited[i][j] = 0;
    return;
        
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, PROCESS, x, y;
    char ch;
    cin >> T;
    for(int t = 1; t <= T; t++){
        currentSteps = 0;
        keys[0] = keys[1] = keys[2] = keys[3] = 0;
        cin >> R >> C;
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++){
                cin >> MAP[r][c];
                if(MAP[r][c] == 'X')
                    PROCESS = 1;
                if(MAP[r][c] == '*')
                    x = r, y = c;
                visited[r][c] = 0;
            }
        cout << "CASE #" << t << "\n";
        if(PROCESS && CheckPath()){
            //cout << "START\n";
            while(!finish){
                DFS(x, y, 0);
            }
            cout << minSteps << "\n";
            minSteps = 1 << 30;
            finish = 0;
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}