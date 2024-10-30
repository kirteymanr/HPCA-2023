// Create other necessary functions here

__global__
void gpuConvolution(int input_row, int input_col, int* input, 
                    int kernel_row, int kernel_col, int* kernel,
                    int output_row, int output_col, 
                    long long unsigned int* output 
                    )
{
    int output_i = blockIdx.x * blockDim.x + threadIdx.x;
    int output_j = blockIdx.y * blockDim.y + threadIdx.y;

    if (output_i < output_row && output_j < output_col){
        long long unsigned int sum = 0;

        for (int kernel_i = 0; kernel_i < kernel_row; kernel_i++){
            int kernel_offset = kernel_i * kernel_col;
            int input_i = (output_i + 2*kernel_i) % input_row;
            int input_offset = input_i*input_col;
            for(int kernel_j = 0; kernel_j< kernel_col; kernel_j++){
                int input_j = (output_j + 2*kernel_j) % input_col;
                sum += input[input_offset +input_j] * kernel[kernel_offset +kernel_j];
            }
        }

        output[output_i * output_col + output_j] = sum;
    }
}


// Fill in this function
void gpuThread( int input_row, 
                int input_col,
                int *input, 
                int kernel_row, 
                int kernel_col, 
                int *kernel,
                int output_row, 
                int output_col, 
                long long unsigned int *output ) 
{
    int* d_input, *d_kernel;
    long long unsigned int* d_output;

    //Allocating memory in GPU
    cudaMallocManaged(&d_input, input_row * input_col * sizeof(int));
    cudaMallocManaged(&d_kernel, kernel_row * kernel_col * sizeof(int));
    cudaMallocManaged(&d_output, output_row * output_col * sizeof(long long unsigned int));

    // copying input and kernel matrices to CUDA memory
    cudaMemcpy(d_input, input, input_row * input_col * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_kernel, kernel, kernel_row * kernel_col * sizeof(int), cudaMemcpyHostToDevice);

    // Defining grid and block dimensions
    dim3 blockDim(32,32);
    dim3 gridDim((output_row + blockDim.x - 1) / blockDim.x, (output_col + blockDim.y - 1) / blockDim.y);

    // Launching CUDA kernel
    gpuConvolution<<<gridDim, blockDim>>>(input_row, input_col, d_input, kernel_row, kernel_col, d_kernel, output_row, output_col, d_output);

    // Wait for GPU to finish before accessing on host
    cudaDeviceSynchronize();
    
    cudaMemcpy(output, d_output, output_row * output_col * sizeof(long long unsigned int), cudaMemcpyDeviceToHost);

    // Free cuda memory
    cudaFree(d_input);
    cudaFree(d_kernel);
    cudaFree(d_output);

    
}
