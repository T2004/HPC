# HPC Programming Experiments

[![GitHub Profile](https://img.shields.io/badge/GitHub-T2004-blue?style=flat-square&logo=github)](https://github.com/T2004)

This repository contains High-Performance Computing (HPC) programming experiments and implementations developed by [T2004](https://github.com/T2004).

##  Overview

This project demonstrates advanced HPC programming concepts with a focus on parallel computing, MPI implementations, and performance optimization techniques. The repository serves as a comprehensive collection of HPC experiments and educational materials.

##  Project Structure

`
HPC/
 Programming experiments/
    Matrix_vector_multiplication/
        include/          # Header files (.h)
        src/             # Source files (.c)
        Makefile         # Build configuration
 2024280084+Tanjim+ HPC Report 2025.pdf
 Programming_Report+2024280084+ Tanjim.pdf
 README.md
 .gitignore
`

##  Experiments

### Matrix Vector Multiplication
- **Location**: Programming experiments/Matrix_vector_multiplication/
- **Description**: Parallel implementation of matrix-vector multiplication using MPI
- **Features**:
  - Distributed memory parallelization
  - Performance optimization
  - Scalability analysis
  - Comprehensive benchmarking

##  Building and Running

### Prerequisites
- GCC compiler
- MPI implementation (OpenMPI or MPICH)
- Make build system

### Compilation
`ash
cd "Programming experiments/Matrix_vector_multiplication"
make
`

### Execution
`ash
mpirun -np <number_of_processes> ./matrix_vector_mult
`

##  Performance Analysis

The repository includes detailed performance reports and analysis:
- **HPC Report 2025**: Comprehensive analysis of parallel algorithms
- **Programming Report**: Implementation details and optimization strategies

##  Technologies Used

- **Languages**: C
- **Parallel Computing**: MPI (Message Passing Interface)
- **Build System**: Make
- **Performance Tools**: Profiling and benchmarking utilities
- **Documentation**: LaTeX reports

##  Key Features

-  Parallel algorithm implementations
-  Performance optimization techniques
-  Scalability analysis
-  Comprehensive documentation
-  Educational resources

##  Author

**GitHub Profile**: [T2004](https://github.com/T2004)

##  License

This project is part of academic coursework and research in High-Performance Computing.

##  Contributing

This repository serves as an educational resource. Feel free to explore the implementations and learn from the HPC techniques demonstrated.

---

*For more projects and contributions, visit my [GitHub profile](https://github.com/T2004)*
