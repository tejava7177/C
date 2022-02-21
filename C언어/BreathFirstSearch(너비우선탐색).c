//
//  BreathFirstSearch(너비우선탐색).c
//  C언어
//
//  Created by 심주흔 on 2022/02/08.
//



//  *아직 미완성 된 코드*
/*
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct GraphType{
    int n;
    int **ptr;
}GraphType;

int *visited;

void init(GraphType* g, int max){
    int r, c;
    g->n = 0;
    for(r = 0; r <max; r++){
        for(c = 0; c< max; c++){
            g->ptr[r][c] = 0;
        }
    }
}


void insert_vertex(GraphType * g, int v, int max){
    if(((g->n) + 1) > max){
        return;
    }
    g->n++;
}

void insert_edge(GraphType * g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "GraphNode error\n");
        return;
    }
    g->ptr[start][end] = 1;
}

void dfs_mat(GraphType * g, int v){
    int w;
    visited[v] = TRUE;
    printf( "%d " , v);
    for(w = 0; w < g->n; w++){
        if(g->ptr[v][w] && !visited[w])
            dfs_mat(g,w);
    }
}
*/

