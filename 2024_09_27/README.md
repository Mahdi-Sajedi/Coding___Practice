[cuda 2d block/grid mapping](http://thebeardsage.com/cuda-dimensions-mapping-and-indexing/)

dim3 is a 3d structure or vector type with three integers, x, y and z. One can initialise as many of the three coordinates as they like

   dim3 threads(256);           // Initialise with x as 256, y and z will both be 1
   dim3 blocks(100, 100);       // Initialise x and y, z will be 1
   dim3 anotherOne(10, 54, 32); // Initialises all three values, x will be 10, y gets 54 and z will be 32.

   ![image](https://github.com/user-attachments/assets/8ced215e-50f5-47f3-a1bc-ca20fd8c77cf)
  
   ![image](https://github.com/user-attachments/assets/e518dc01-7a92-40d6-b898-c2a3c46d5cc6)

Why Blocks and Threads?
Each GPU has a limit on the number of threads per block but (almost) no limit on the number of blocks. Each GPU can run some number of blocks concurrently, executing some number of threads simultaneously.

By adding the extra level of abstraction, higher performance GPU’s can simply run more blocks concurrently and chew through the workload quicker with absolutely no change to the code!
