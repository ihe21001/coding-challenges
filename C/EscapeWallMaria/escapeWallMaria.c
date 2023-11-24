#include <stdio.h>
#include <stdbool.h>
#define DEBUG 0

typedef struct{
    int row, col, moves;
} node;

void find_positions(char match, int N, int M, char array[][M + 1], int position[2], int* count) {
    *count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (match == array[i][j]) {
                position[0] = i; // Store row
                position[1] = j; // Store column
                (*count)++;
            }
        }
    }
}

int BFS(int N, int M, char wallMaria[][M + 1], int start[2], int t){
    bool visited[N][M];
    node queue[N*M];
    int front_q=0, rear_q=0; //pointer queue
    int move_direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; //up, down, left, right
    int move_definition[4]={'D','U','R','L'};

    // Initialize visited to falses
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            visited[i][j] = false;
    
    if (DEBUG)
    {
        printf("Visitid matrix:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) 
                printf("%d",visited[i][j]);
        printf("\n");
        }
    }
    
    // start node:
    node startNode = {start[0],start[1],0};
    // Add to que:
    queue[rear_q++]=startNode;
    // mark node as visited
    visited[start[0]][start[1]] = true;

    if (start[0] == 0 || start[0] == N-1 || start[1] == 0 || start[1] == M-1){
        if (DEBUG){
            printf("row: %d, col: %d\n",start[0],start[1]);
        }
    return startNode.moves;
    }


    if (DEBUG)
    {
        printf("Visitid matrix:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) 
                printf("%d",visited[i][j]);
        printf("\n");
        }
    }
    

    //Processing the queue:
    while(front_q<rear_q){
        node node_current = queue[front_q++];

        for (int i = 0; i < 4; i++)
        {
            int node_test_row = node_current.row + move_direction[i][0];
            int node_test_col = node_current.col + move_direction[i][1];

            //check bounderies
            if(node_test_row < 0 || node_test_row >= N || node_test_col < 0 || node_test_col >= M)
                continue;

            //check wall or visited
            if (wallMaria[node_test_row][node_test_col]=='1' || visited[node_test_row][node_test_col]){
                continue;
            }

            char new_node = wallMaria[node_test_row][node_test_col];
            // Validate the direction
            if (DEBUG)
            {
                printf("Ned node= %c , Def= %c , i = %d\n", new_node, move_definition[i], i);
            }
            
            if(((new_node == move_definition[0] && i == 0) || 
                (new_node == move_definition[1] && i == 1) || 
                (new_node == move_definition[2] && i == 2) || 
                (new_node == move_definition[3] && i == 3)) || 
                    wallMaria[node_test_row][node_test_col] == '0'){
                    visited[node_test_row][node_test_col] = true;
                    node new_node = {node_test_row,node_test_col,node_current.moves+1};
                    queue[rear_q++] = new_node;

                    if (new_node.row == 0 || new_node.row == N-1 || new_node.col == 0 || new_node.col == M-1){
                        if (DEBUG)
                        {
                        printf("row: %d, col: %d\n",node_test_row,node_test_col);
                        }
                    return new_node.moves;
                }

                if (DEBUG)
                {
                    printf("Visitid matrix:\n");
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < M; j++) 
                            printf("%d",visited[i][j]);
                    printf("\n");
                    }
                }
    
            }
            
        }
        
        
    }
    return -1;
}

int main() {
    
    //**//**//**INPUT**//**//**//
    int t = 0, N = 0, M = 0, moves=0;
    scanf("%d %d %d", &t, &N, &M); // time // rows // columns
    char wallMaria[N][M + 1]; // +1 for the null terminator of the string
    for (int i = 0; i < N; i++)  scanf("%s", wallMaria[i]); // Scan each row as a string
    if (DEBUG)
    {
        printf("\n");
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    printf("%c", wallMaria[i][j]);
                }
                printf("\n"); // Optionally, to print each row in a new line.
            }
    }
    //**//**//**-----**//**//**//

    //**//**//**Find s position**//**//**//
    int match_count_s = 0; 
    int start_pos[2];
    find_positions('S', N, M, wallMaria, start_pos, &match_count_s);
    if (DEBUG)
    {
        if(match_count_s > 0) {
            printf("S found at position (%d, %d)\n", start_pos[0], start_pos[1]);        
            }
    } 
    if (match_count_s!=1) { // NO s or to many s in matrix
        //printf("NOT POSSIBLE");
        return 0;
        }
    //**//**//**---------------**//**//**//

    
    //**//**//**BFS**//**//**//
    moves = BFS(N, M, wallMaria, start_pos, t);
    if(moves == -1 || moves > t){
        printf("NOT POSSIBLE");
        return 0;
    }
    //**//**//**---**//**//**//

    if (DEBUG)
    {
        printf("time:");
    }
    
    printf("%d", moves);
    return 0;
}
