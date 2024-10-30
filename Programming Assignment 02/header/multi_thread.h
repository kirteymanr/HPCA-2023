#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2 // Number of threads to use

typedef struct {
    int input_row, input_col, kernel_row, kernel_col, output_row, output_col;
    int *input, *kernel;
    long long unsigned int *output;
    int thread_id;
} ThreadData;
// pthread_mutex_t mutex;
void *computeConvolution(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int start_i = data->thread_id * (data->output_row / NUM_THREADS);
    int end_i = (data->thread_id + 1) * (data->output_row / NUM_THREADS);
    if (data->thread_id + 1 == NUM_THREADS)
        end_i = data->output_row;
    // pthread_mutex_lock(&mutex);
    // std::cout << "Thread_id = " << data->thread_id <<  " Start_i = " << start_i << " End_i = " << end_i << std::endl;
    // pthread_mutex_unlock(&mutex);
    for (int output_i = start_i; output_i < end_i; output_i++) {
        for (int output_j = 0; output_j < data->output_col; output_j++) {
            for (int kernel_i = 0; kernel_i < data->kernel_row; kernel_i++) {
                for (int kernel_j = 0; kernel_j < data->kernel_col; kernel_j++) {
                    int input_i = (output_i + 2 * kernel_i) % data->input_row;
                    int input_j = (output_j + 2 * kernel_j) % data->input_col;
                    data->output[output_i * data->output_col + output_j] +=
                        data->input[input_i * data->input_col + input_j] *
                        data->kernel[kernel_i * data->kernel_col + kernel_j];
                }
            }
        }
    }
    pthread_exit(NULL);
}

void multiThread(int input_row, int input_col, int *input,
                 int kernel_row, int kernel_col, int *kernel,
                 int output_row, int output_col, long long unsigned int *output) {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].input_row = input_row;
        thread_data[i].input_col = input_col;
        thread_data[i].input = input;
        thread_data[i].kernel_row = kernel_row;
        thread_data[i].kernel_col = kernel_col;
        thread_data[i].kernel = kernel;
        thread_data[i].output_row = output_row;
        thread_data[i].output_col = output_col;
        thread_data[i].output = output;
        thread_data[i].thread_id = i;
        pthread_create(&threads[i], NULL, computeConvolution, (void *)&thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}
