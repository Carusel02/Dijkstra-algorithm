#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>   
#include <stdbool.h>
#include <limits.h>

#define V 5
 
int delivery(float *distance, bool *visit, int *traversal) {
    float min = 9999;
    int index;
    
    for(int i = 0 ; i < 5 ; i++)
        printf("**distance %d = %10.1lf \t\t bool %d = %d \n", i, distance[i], i, visit[i]);

    for(int v = 0 ; v < 5 ; v++) {
        printf("visit[v] == false && distance[v] <= min\n");
        printf("%d == %d && %.1lf <= %.1lf\n", visit[v], 0, distance[v], min);
        if(visit[v] == false && distance[v] <= min) {
        min = distance[v];
        index = v;
        }
    }
    
    printf("index = %d\n", index);
    return index;
}

 
void printSolution(float *dist) {
    printf("Vector \t\t Distanta\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %.1lf\n", i, dist[i]);
}

void dijkstra(float graph[V][V], int source)
{
    float dist[V];
    bool visit[V];
    int traversal[5] = {-1} ;
 
    for (int i = 0; i < V; i++) {
        dist[i] = 9999;
        visit[i] = false;
    }
 
    dist[source] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = delivery(dist, visit, traversal);
 
        // Mark the picked vertex as processed
        visit[u] = true;

 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!visit[v] && graph[u][v] && dist[u] != 9999 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                traversal[v] = u;
            }

        for(int i = 0 ; i < 5 ; i++)
          printf("distance %d = %10.1lf \t\t bool %d = %d \n", i, dist[i], i, visit[i]);
    }
    
    for(int i = 0 ; i < 5 ; i++)
        printf("traversal %d = %d\n", i, traversal[i]);
    printSolution(dist);
}



int main() {
    int n;
    float matrix[5][5] = {{0.0, 2.5, 0.0, 1.4, 0.0} ,
                          {0.0, 0.0, 0.0, 0.0, 2.3} ,
                          {3.0, 0.0, 0.0, 0.0, 0.0} ,
                          {1.4, 0.0, 0.0, 0.0, 0.0} ,
                          {0.0, 0.0, 0.5, 0.0, 0.0}
                            } ;

        // float matrix[5][5] = {{0.0, 0.0, 3.0, 1.4, 0.0} ,
        //                     {2.5, 0.0, 0.0, 0.0, 0.0} ,
        //                     {0.0, 0.0, 0.0, 0.0, 0.5} ,
        //                     {1.4, 0.0, 0.0, 0.0, 0.0} ,
        //                     {0.0, 2.3, 0.0, 0.0, 0.0}
        //                     } ;
     

    dijkstra(matrix,0);
    

    return 0;
}