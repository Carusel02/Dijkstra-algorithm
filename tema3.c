#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int X = 0 ;

int Y = 0 ;

int Z = 0 ;

void dfs2(float **matrix, int node, int dim, int *visited, int afisare[20][20]) {
    
    afisare[Y][Z] = node ;
    printf("%d ", node);
    visited[node] = 1;
 
    // For every node of the graph
    for (int i = 0; i < dim ; i++) {
        
        if (matrix[node][i] != 0 && (!visited[i])) {
            Z++;
            dfs2(matrix, i, dim, visited, afisare);
        }
    }


}

void dfs(float **matrix, int node, int dim, int *visited, int *stack) {
    

    stack[X] = node;
    X++;



    visited[node] = 1;
 
    // For every node of the graph
    for (int i = 0; i < dim ; i++) {
 
        if (matrix[node][i] != 0 && (!visited[i])) {
            dfs(matrix, i, dim, visited, stack);
        }
    }

}


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

void trans(float **original, float **copy, int dim) {
    for(int i = 0 ; i < dim ; i++)
     for(int j = 0 ; j < dim ; j++)
      copy[i][j] = original[j][i];
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

        if(strstr("e2",arg) != NULL) {
         
         // vector nod vizitat
         int *vector = (int *)malloc(number_nodes * sizeof(int));
         // stiva ( sub forma de vector )
         int *stack = (int *)malloc(number_nodes * sizeof(int));
         for(int i = 0 ; i < number_nodes ; i++) {
             vector[i] = 0;
             stack[i] = -1;
         }
         
         // dfs din nodul 0
         dfs(matrix,0,number_nodes,vector,stack);
         
         // declarare matrice transpusa
         float **transpose = (float **)malloc(number_nodes * sizeof(float *));
         for(int i = 0 ; i < number_nodes ; i++) {
             transpose[i] = (float *)malloc(number_nodes * sizeof(float));
         }
         
         // transpunere matrice
         trans(matrix,transpose,number_nodes);

         print_matrix(matrix, number_nodes);
         printf("\n");
         print_matrix(transpose, number_nodes);
         
         // pop la stack
         int *stack_trans = (int *)malloc(number_nodes * sizeof(int));
         
         // refresh valori pentru alt dfs
         for(int i = 0 ; i < number_nodes ; i++) {
             vector[i] = 0;
             stack_trans[i] = stack[number_nodes - i - 1];
         }
         
         // scoatere depozite din componente tare conexe
         for(int i = 0 ; i < number_dep ; i++)
            vector[depozite[i]] = 1;


         for(int i = 0 ; i < number_nodes ; i++) {
             printf("order stack : %d\n", stack[i]);
         }

         for(int i = 0 ; i < number_nodes ; i++) {
             printf("order reverse stack : %d\n", stack_trans[i]);
         }
         
         // matrice afisare
         int afisare[20][20] = {0} ;
         
         // apelare dfs2
         for(int i = 0 ; i< number_nodes ; i++) {
            if(vector[stack_trans[i]] == 0) {
            Z = 0;
            dfs2(transpose, stack_trans[i], number_nodes, vector, afisare);
            Y++;
            printf("\n");
            }
         }
         
         int change;
         int sort;

         do {
         // sortare linii
         sort = 1;
         for(int i = 0 ; i < Y ; i++)
          for(int j = 0 ; j < 14 ; j++) 
            if(afisare[i][j] > afisare[i][j+1] && afisare[i][j] != 0 && afisare[i][j+1] != 0) {
             change = afisare[i][j];
             afisare[i][j] = afisare[i][j+1];
             afisare[i][j+1] = change;
             sort = 0;
          }
         
          }
          while(sort == 0);

         
         do {
         // sortare first element

         sort = 1;
         for(int i = 0 ; i < Y - 1 ; i++)
          if(afisare[i][0] > afisare [i+1][0]) {
              for(int j = 0 ; j < 15 ; j++) {
                  change = afisare[i+1][j];
                  afisare[i+1][j] = afisare[i][j];
                  afisare[i][j] = change;
              }
              sort = 0;
          }
          
          }
          while(sort == 0);
         
         // afisare
         int cp_y = Y;
         for(int i = 0 ; i < Y ; i++) {
           for(int j = 0 ; j < 15 ; j++) {
             if(afisare[i][j] != 0)
             printf("%d ", afisare[i][j]);
             if(cp_y > 1) {
             printf("\n");
             cp_y--;
             }
           }
         }  


         for (int i = 0; i < number_nodes; i++)
             free(transpose[i]);
        
         free(transpose);
         free(vector);
         free(stack);
         free(stack_trans);
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