# HPCA Programming Assignment 2: Optimizing Performance of Dilated Convolution

This repository contains the code and report for **HPCA Programming Assignment 2**, which focuses on optimizing the performance of Dilated Convolution (DC) through single-threaded, multi-threaded, and GPU-based implementations. The assignment covers optimization techniques using CPU and GPU resources, aiming to achieve significant speedup and scalability.

## Repository Structure

- **header/**: Contains implementation files for each part:
  - `single_thread.h`: Single-threaded CPU implementation (Part A-I)
  - `multi_thread.h`: Multi-threaded CPU implementation using pthreads (Part A-II)
  - `gpu_thread.h`: GPU implementation in CUDA (Part B)

- **reports/**: Contains the assignment reports detailing methodology, optimizations, and performance analysis:
  - `Report_PartA.pdf`: CPU-based implementation report, covering both single-threaded and multi-threaded optimization.
  - `Report_PartB.pdf`: GPU-based implementation report, detailing CUDA optimizations and performance evaluation.

## Assignment Overview

1. **Dilated Convolution (DC)**:
   - Involves an input matrix and kernel matrix to produce an output matrix.
   - The Kernel Matrix slides over the Input Matrix, performing multiplications and accumulations to generate each cell in the Output Matrix.

2. **Optimization Tasks**:
   - **Part A-I**: Optimize the single-threaded DC implementation using CPU performance counters to identify and address bottlenecks.
   - **Part A-II**: Develop a multi-threaded DC implementation using pthreads and test scalability across various thread counts.
   - **Part B**: Implement DC on a GPU using CUDA, optimizing for parallelism and maximizing GPU resource utilization.

## Instructions

1. **CPU Implementations (Part A)**:
   - Ensure all optimizations are implemented in the respective `header/*.h` files.
   - Use Linux’s `perf` tool to measure performance improvements for the single-threaded implementation.
   - For multi-threaded DC, utilize `pthreads` and measure scalability by varying thread counts.

2. **GPU Implementation (Part B)**:
   - Implement DC on a CUDA-enabled GPU, optimizing for GPU memory and parallel computation.
   - Use tools like `NVprof` or `Nsight` for performance analysis (or `GPGPU-sim` for testing on a simulator if a GPU is unavailable).

3. **Running the Code**:
   - Follow the setup instructions in the GitHub repository’s main `README.md` to compile and run the code with example matrix sizes.
   - Ensure that `main.cpp` (CPU) and `main.cu` (GPU) files are not modified, as per submission requirements.

## Report Details

Each report includes:
- **Runtime Analysis**: Baseline runtimes and performance gains achieved through optimizations.
- **Performance Metrics**: Analysis of hardware performance counters, RMSE, R2, and scalability (for multi-threaded CPU implementation).
- **Scalability**: Evaluation of multi-threaded performance and GPU resource utilization.

## References

- [Perf Tool Tutorial](https://perf.wiki.kernel.org/index.php/Tutorial)
- [GPGPU-Sim for CUDA](https://github.com/gpgpu-sim/gpgpu-sim_distribution)
- [NVIDIA CUDA Download](https://developer.nvidia.com/cuda-11.0-download-archive)

## Author

Prepared by: Kirteyman Singh Rajput

---

This repository serves as a comprehensive resource for experimenting with and optimizing the performance of Dilated Convolution across CPU and GPU platforms.
