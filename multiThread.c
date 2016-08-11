 #include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

void do_one_thing(int *);
void do_another_thing(int *);
void do_third_thing(int *);
void do_final_thing(int *);
void do_wrap_up(int, int, int, int);
 
int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
 
 
void main()
{
  pthread_t       thread1, thread2, thread3, thread4;
 
  pthread_create(&thread1, 
		 NULL,
		 (void *) do_one_thing,
		 (void *) &r1); 
 
  pthread_create(&thread2, 
		 NULL, 
		 (void *) do_another_thing,
		 (void *) &r2); 

  pthread_create(&thread3, 
		 NULL, 
		 (void *) do_another_thing,
		 (void *) &r3); 

  pthread_create(&thread4, 
		 NULL, 
		 (void *) do_another_thing,
		 (void *) &r4); 

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4, NULL);

  do_wrap_up(r1, r2, r3, r4);
 
}
 
void do_one_thing(int *pnum_times)
{
  int i, j, x;


  for (i = 0;  i < 4; i++) {
    printf("doing one thing\n"); 
    for (j = 0; j < 10000; j++) x = x + i;
    (*pnum_times)++;
  }
 
}
 
void do_another_thing(int *pnum_times)
{
  int i, j, x;


  for (i = 0;  i < 4; i++) {
    printf("doing another \n"); 
    for (j = 0; j < 10000; j++) x = x + i;
    (*pnum_times)++;
  }
 
}

void do_third_thing(int *pnum_times)
{
  int i, j, x;


  for (i = 0;  i < 4; i++) {
    printf("doing third thing\n"); 
    for (j = 0; j < 10000; j++) x = x + i;
    (*pnum_times)++;
  }
 
}

void do_final_thing(int *pnum_times)
{
  int i, j, x;


  for (i = 0;  i < 4; i++) {
    printf("doing final thing\n"); 
    for (j = 0; j < 10000; j++) x = x + i;
    (*pnum_times)++;
  }
 
}
 
void do_wrap_up(int one_times, int another_times, int third_time, int final_time)
{
  int total;
 
  total = one_times + another_times + third_time + final_time;
  printf("All done, one thing %d, another %d, third %d, final %d for a total of %d\n", one_times, another_times, third_time, final_time, total);
}
