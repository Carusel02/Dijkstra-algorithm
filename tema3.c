#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
int delivery(float *distance, int *vis, int *traversal, int dim) {
    float min = 9999; // declarare minim
    int index; // declarare index

    
    for(int v = 0 ; v < dim ; v++) {
        if(vis[v] == 0 && distance[v] <= min) {
        min = distance[v];
        index = v;
        }
    }

    return index;
}

 
void printSolution(float *dist, int dim) {
    printf("Vector \t\t Distanta\n");
    for (int i = 0; i < dim ; i++)
        printf("%d \t\t %.1lf\n", i, dist[i]);
}

void path(float **matrix, int dim, int start, int *magazine, int nr_magazine)
{
    float *dist = (float *)malloc(dim * sizeof(float));
    int  *visit = (int *)malloc(dim * sizeof(int));
    int *traversal = (int *)malloc(dim * sizeof(int));
 
    for (int i = 0; i < dim; i++) {
        dist[i] = 9999;
        visit[i] = 0;
        traversal[i] = -1;
    }
 
    dist[start] = 0;
 
    for (int X = 0; X < dim - 1; X++) {
        
        int nod = delivery(dist, visit, traversal, dim); // alegere nod
        visit[nod] = 1; // marcare nod

        for (int i = 0; i < dim; i++) {
            if (!visit[i] && matrix[nod][i] && dist[nod] != 9999 && dist[nod] + matrix[nod][i] < dist[i]) {
                dist[i] = dist[nod] + matrix[nod][i];
                traversal[i] = nod;
            }
        }
    }

    // printSolution(dist,dim);
    // for(int i = 0 ; i < nr_magazine ; i++) {
    //  printf("%d\n", magazine[i]);
    //  printf("%.1lf\n", dist[magazine[i]]);
    // }


    free(dist);
    free(visit);
    free(traversal);    
}

void printPath_0(int *parent, int j)
{
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
       
    printPath_0(parent, parent[j]);
    printf(" %d", j);
}

void printPath_1(int *parent, int j)
{
    if (parent[j] == -1) {
        // printf("%d ", j);
        return;
    }
    

    printPath_1(parent, parent[j]);
    printf(" %d", j);
}

void show_path(float **matrix, int dim, int start, int finish, int type)
{
    float *dist = (float *)malloc(dim * sizeof(float));
    int  *visit = (int *)malloc(dim * sizeof(int));
    int *traversal = (int *)malloc(dim * sizeof(int));
 
    for (int i = 0; i < dim; i++) {
        dist[i] = 9999;
        visit[i] = 0;
        traversal[i] = -1;
    }
 
    dist[start] = 0;
 
    for (int X = 0; X < dim - 1; X++) {
        
        int nod = delivery(dist, visit, traversal, dim); // alegere nod
        visit[nod] = 1; // marcare nod

        for (int i = 0; i < dim; i++) {
            if (!visit[i] && matrix[nod][i] && dist[nod] != 9999 && dist[nod] + matrix[nod][i] < dist[i]) {
                dist[i] = dist[nod] + matrix[nod][i];
                traversal[i] = nod;
            }
        }
    }
    
    if(type == 0)
    printPath_0(traversal, finish);
    else
    printPath_1(traversal, finish);

    free(dist);
    free(visit);
    free(traversal);    
}

float calculate(float **matrix, int dim, int start, int finish)
{
    float *dist = (float *)malloc(dim * sizeof(float));
    int  *visit = (int *)malloc(dim * sizeof(int));
    int *traversal = (int *)malloc(dim * sizeof(int));
 
    for (int i = 0; i < dim; i++) {
        dist[i] = 9999;
        visit[i] = 0;
        traversal[i] = -1;
    }
 
    dist[start] = 0;
 
    for (int X = 0; X < dim - 1; X++) {
        
        int nod = delivery(dist, visit, traversal, dim); // alegere nod
        visit[nod] = 1; // marcare nod

        for (int i = 0; i < dim; i++) {
            if (!visit[i] && matrix[nod][i] && dist[nod] != 9999 && dist[nod] + matrix[nod][i] < dist[i]) {
                dist[i] = dist[nod] + matrix[nod][i];
                traversal[i] = nod;
            }
        }
    }

     
    float return_function = dist[finish];
    free(dist);
    free(visit);
    free(traversal); 
    return return_function;   
}

void read_matrix(float **matrix, int dim, int nr_muchii) {
    if(dim <= 0)
    return;
    
    int x,y;
    float cost;

    for(int i = 0 ; i < dim ; i++)
        for(int j = 0 ; j < dim ; j++)
            matrix[i][j] = 0;
    
    
    for(int i = 0 ; i < nr_muchii ; i++) {
        scanf("%d %d %f", &x, &y, &cost);
        matrix[x][y] = cost ;
    }
}

void print_matrix(float **matrix, int dim) {
     if(dim <= 0)
     return;
     
     for(int i = 0 ; i < dim ; i++) {
         for(int j = 0 ; j < dim ; j++)
             printf("%.1lf ", matrix[i][j]);
         printf("\n");
     }
}


int main() {
    int number_nodes; // nr noduri
    int number_edge;  // nr muchii
    int number_dep;  // nr depozite

    
    scanf("%d %d %d", &number_nodes, &number_edge, &number_dep);

    float **matrix = (float **)malloc(number_nodes * sizeof(float *));
    for(int i = 0 ; i < number_nodes ; i++) {
        matrix[i] = (float *)malloc(number_nodes * sizeof(float));
    }
    
    read_matrix(matrix,number_nodes,number_edge);

    // id uri depozite
    int *depozite = (int *)malloc(number_dep * sizeof(int));
    for(int i = 0 ; i < number_dep ; i++) {
       scanf("%d", &depozite[i]);
    }

    int nr_cerinte;
    scanf("%d", &nr_cerinte);
    int nr_cer = nr_cerinte;

    for(int i = 0 ; i < nr_cerinte ; i++) {
        char arg[20];
        scanf("%s",arg);
        if(strstr("e1",arg) != NULL) {
          // id depozit
          int id_dep;
          scanf("%d", &id_dep);
        
          // nr magazine + id magazine
          int nr_magazine;
          scanf("%d", &nr_magazine);
          int *magazine = (int *)malloc(nr_magazine * sizeof(int));
          for(int i = 0 ; i < nr_magazine ; i++) {
              scanf("%d", &magazine[i]);
          }
          
          float sum = 0 ;
          for(int i = 0 ; i < nr_magazine ; i++) {
              printf("%d\n", magazine[i]);
              float tur = calculate(matrix,number_nodes,id_dep,magazine[i]);
              float retur = calculate(matrix,number_nodes,magazine[i],id_dep);
              printf("%.1lf %.1lf\n", tur, retur);
              show_path(matrix,number_nodes,id_dep,magazine[i],0);
              show_path(matrix,number_nodes,magazine[i],id_dep,1);
              printf("\n");
              sum = (float) (sum + tur + retur) ;
          }
          
          printf("%.1lf",sum);
          free(magazine);
        }
        
        if(nr_cer > 1) {
          printf("\n");
          nr_cer--;
        }

    }

    

     
    
    free(depozite);

    for (int i = 0; i < number_nodes; i++)
        free(matrix[i]);
    free(matrix);

    return 0; // return
}