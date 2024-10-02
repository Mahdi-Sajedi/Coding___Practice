#include <algorithm>
#include <iostream>
#include <cmath>
#include <cuda_runtime.h>

using namespace std;

__global__ void add(int n, float* x, float*y, float* z) {
  int idx = blockDim.x * blockIdx.x + threadIdx.x;
  if (idx<n)
    z[idx] = x[idx] + y[idx];
}

int main(void) {
  int N = 1<<20;

  float* x = new float[N];
  float* y = new float[N];
  float* z = new float[N];

  for (int i=0; i<N; i++){
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  float *d_x, *d_y, *d_z;

  cudaMalloc(&d_x, N * sizeof(float));
  cudaMalloc(&d_y, N * sizeof(float));
  cudaMalloc(&d_z, N * sizeof(float));

  cudaMemcpy(d_x, x, N * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_y, y, N * sizeof(float), cudaMemcpyHostToDevice);

  int blockSize = 256;
  int numBlocks = (N + blockSize - 1) / blockSize;
  
  // Create CUDA events to measure time
  cudaEvent_t start, stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  // Record the start event
  cudaEventRecord(start);
  
  add<<<numBlocks, blockSize>>>(N, d_x, d_y, d_z);
  
  // Record the stop event
  cudaEventRecord(stop);
  cudaEventSynchronize(stop);

  // Calculate the time elapsed between the two events
  float milliseconds = 0;
  cudaEventElapsedTime(&milliseconds, start, stop);
  cout << "Kernel execution time: " << milliseconds << " milliseconds" << endl;
  
  cudaMemcpy(z, d_z, N * sizeof(float), cudaMemcpyDeviceToHost);
  
  float err = 0.0;
  for (int i=0; i<N; i++){
    err += fabs(z[i] - 3.0f);
  }
  cout << "error is" << err << endl;

  // free device memory
  cudaFree(d_x);
  cudaFree(d_y);
  cudaFree(d_z);

  // free host memory
  delete[] x;
  delete[] y;
  delete[] z;
  
  return 0;
}
