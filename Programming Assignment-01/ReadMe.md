# Assignment 1: Branch Prediction and CPI Stack Analysis

This repository contains the code and report files for **Assignment 1** on branch prediction and CPI stack analysis. The assignment evaluates the performance of various branch predictors using the Champsim simulator and analyzes the CPI (Cycles Per Instruction) stack for programs with hardware performance counters.

## Repository Structure

- **Folder 1: Codes**
  - Contains all the code files, including Champsim simulator scripts and additional files for CPI stack analysis.
  
- **Folder 2: Report and Assignment PDF**
  - `Assignment-01.pdf`: The assignment document outlining the tasks and requirements.
  - `Report.pdf`: The report summarizing findings, methodology, and performance analysis for branch predictors and CPI stack.

## Contents

1. **Branch Prediction Analysis**:
   - Evaluation of G-share, perceptron, and TAGE predictors with a focus on MPKI (Mispredictions per Kilo Instructions) and IPC (Instructions per Cycle).
   - Exploration of history lengths, table sizes, and hybrid predictors.

2. **CPI Stack Analysis**:
   - Construction of a linear regression model for CPI stack using hardware performance counters.
   - Analysis of L1/L2/L3 cache misses, TLB misses, branch misprediction events, and their impact on CPI.
   - Statistical evaluation using RMSE, R2, adjusted R2 values, and residuals.

## Instructions

1. **Branch Prediction**:
   - Follow the setup instructions in `codes/branch_prediction/README.md` to run simulations with Champsim.
   - Use the SPEC benchmark traces provided in the `codes/benchmarks/` folder for evaluation.

2. **CPI Stack Analysis**:
   - Ensure hardware performance counters are accessible.
   - Run the scripts in `codes/cpi_stack_analysis/` to collect data and fit the regression model.

## References

- Champsim Simulator: [GitHub Repository](https://github.com/ChampSim/ChampSim)
- SPEC Benchmarks: [SPEC Traces](https://dpc3.compas.cs.stonybrook.edu/champsim-traces/speccpu/)

## Author

Prepared by: [Your Name]

---

This repository serves as a comprehensive resource for replicating the experiments and analyses outlined in **Assignment 1**.
