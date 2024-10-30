# HPCA Programming Assignments

This repository contains solutions for **HPCA Programming Assignments** covering two main topics: **Branch Prediction and CPI Stack Analysis** (Assignment 01) and **Optimizing Performance of Dilated Convolution** (Assignment 02). Each assignment includes code implementations, performance analysis, and detailed reports documenting the results.

## Repository Structure

- **Assignment-01/**
  - Contains the code, report, and assignment document for **Branch Prediction and CPI Stack Analysis**.
  - This assignment involves evaluating branch predictors using the Champsim simulator and constructing CPI stacks using hardware performance counters.
  - See the `Assignment-01/README.md` for further details.

- **Assignment-02/**
  - Contains the code, report, and assignment document for **Optimizing Performance of Dilated Convolution**.
  - This assignment focuses on optimizing dilated convolution implementations on single-threaded CPU, multi-threaded CPU, and CUDA-based GPU.
  - See the `Assignment-02/README.md` for further details.

## Summary of Assignments

1. **Assignment 01: Branch Prediction and CPI Stack Analysis**
   - **Objective**: Evaluate different branch predictors (G-share, perceptron, TAGE) and analyze CPI stacks.
   - **Components**:
     - **Branch Prediction**: Analysis of branch predictor accuracy and efficiency across SPEC benchmarks.
     - **CPI Stack**: Development of a linear regression model to determine CPI stack for a set of benchmark programs.
   - **Deliverables**: Code in `codes/`, report in `reports/`, and assignment guidelines in `Assignment-01.pdf`.

2. **Assignment 02: Optimizing Performance of Dilated Convolution**
   - **Objective**: Optimize dilated convolution implementations on CPU and GPU.
   - **Components**:
     - **Part A-I**: Single-threaded CPU implementation optimization.
     - **Part A-II**: Multi-threaded CPU implementation using pthreads.
     - **Part B**: GPU implementation in CUDA.
   - **Deliverables**: Code in `header/`, report in `reports/`, and assignment guidelines in `Assignment-02.pdf`.

## How to Use

1. **Navigate to Each Assignment Folder**:
   - Each assignment has its own `README.md` with detailed instructions for setup, running code, and understanding the outputs.

2. **Run Code and View Reports**:
   - Each assignment contains code files organized for easy access to run simulations or optimizations as required.
   - Reports include performance evaluations and insights derived from each assignment’s tasks.

## Author

Prepared by: [Your Name]

---

This repository is a complete resource for the HPCA Programming Assignments, offering hands-on experience in performance analysis and optimization across CPU and GPU architectures.
