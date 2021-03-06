/*
 *
 * Author: Sanhu Li
 * CS 441/541: Finicky Voter (Assignment 2 Part 2)
 * Oct. 20, 2014
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include "semaphore_support.h"
#include "stdbool.h"
#include "string.h"

/*****************************
* Defines
*****************************/


/*****************************
* Structures
*****************************/
typedef struct {
    int id;
    char type;
} voter_t;

/*****************************
* Global Variables
*****************************/
char *booth;
char which;
int num_booth;
int num_repub;
int num_democ;
int num_indep;
int *repub_q;
int r_s = 0, r_e = 0;
int *democ_q;
int d_s = 0, d_e = 0;
int *indep_q;
int i_s = 0, i_e = 0;
semaphore_t sem_booth;
semaphore_t station_lock;
semaphore_t mutex;
semaphore_t lock;
semaphore_t q_lock;

/*****************************
* Function Declarations
*****************************/
void usage();

void start_booth();

void *voter(void *arg);

void print_configure(const int booth, const int repub, const int democ, const int indep);

char *buffer2str(char *buf, int num);

void print_slashes();

int findBooth();

bool findNo(char type);

void add(int * queue, int val, int *end);
int pop(int *queue, int *start, int *end);
int next(int *queue, int start, int end);