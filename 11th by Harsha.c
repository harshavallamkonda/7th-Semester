#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <assert.h>
#include <time.h>
int min_arr(int arr[], int n)
{
    int i;
    int min = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
 
    return min;
}
int largest(int arr[], int n)
{
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}
int *create_rand_nums(int num_elements) {
  int *rand_nums = (int *)malloc(sizeof(int) * num_elements);
  assert(rand_nums != NULL);
  int i;
  for (i = 0; i < num_elements; i++) {
    rand_nums[i] = (rand() % (5 - 3 + 1) + 3);
    printf("val=%d\t",rand_nums[i]);
  }
  
  return rand_nums;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: avg num_elements_per_proc\n");
    exit(1);
  }

  int num_elements_per_proc = atoi(argv[1]);

  MPI_Init(NULL, NULL);

  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  srand(time(NULL)*world_rank);   
  int *rand_nums = NULL;
  rand_nums = create_rand_nums(num_elements_per_proc);

  int local_min=min_arr(rand_nums,num_elements_per_proc);
  printf("min=%d\t",local_min);
  
  int local_max=largest(rand_nums,num_elements_per_proc);
  printf("max=%d\t",local_max);
  
  int local_sum = 0;
  int i;
  for (i = 0; i < num_elements_per_proc; i++) {
    local_sum += rand_nums[i];
  }

  float avg=(float)local_sum / (float)num_elements_per_proc;
  printf("\nLocal sum for process %d - %d, avg = %f\n",world_rank,local_sum,avg);

  int global_sum;
  MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0,
             MPI_COMM_WORLD);
  int global_min;
  MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0,
             MPI_COMM_WORLD);
 int global_max;
  MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0,
             MPI_COMM_WORLD);

  if (world_rank == 0) {
   float avg1= (float)global_sum / (float)(world_size * num_elements_per_proc);
    printf("\nTotal sum = %d, avg = %f\n", global_sum,avg1);
    printf("\nTotal min = %d", global_min);
 printf("\nTotal max = %d", global_max);
  }
  free(rand_nums);

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();

  //CODE WRITTEN BY VALLAMKONDA VENKATA SREE HARSHA
  //USN: 1NT18CS181
  //SECTION: B

}


