## digging into [quantized](https://android.googlesource.com/platform/external/gemmlowp/+/HEAD/doc/quantization_example.cc) example of gemmlowp

---
---

## digging into [memory models](https://research.swtch.com/mm)

For example, this is the usual example distinguishing the two models:

```
Litmus Test: Write Queue (also called Store Buffer)
Can this program see r1 = 0, r2 = 0?

// Thread 1           // Thread 2
x = 1                 y = 1
r1 = y                r2 = x
On sequentially consistent hardware: no.
On x86 (or other TSO): yes!
```
In any sequentially consistent execution, either x = 1 or y = 1 must happen first, and then the read in the other thread must observe it, so r1 = 0, r2 = 0 is impossible. But on a TSO system, it can happen that Thread 1 and Thread 2 both queue their writes and then read from memory before either write makes it to memory, so that both reads see zeros.

This example may seem artificial, but using two synchronization variables does happen in well-known synchronization algorithms, such as Dekker’s algorithm or Peterson’s algorithm, as well as ad hoc schemes. They break if one thread isn’t seeing all the writes from another.

To fix algorithms that depend on stronger memory ordering, non-sequentially-consistent hardware supplies explicit instructions called memory barriers (or fences) that can be used to control the ordering. We can add a memory barrier to make sure that each thread flushes its previous write to memory before starting its read:
```
// Thread 1           // Thread 2
x = 1                 y = 1
barrier               barrier
r1 = y                r2 = x
```
With the addition of the barriers, r1 = 0, r2 = 0 is again impossible, and Dekker’s or Peterson’s algorithm would then work correctly. There are many kinds of barriers; the details vary from system to system and are beyond the scope of this post. The point is only that barriers exist and give programmers or __language implementers__ a way to force sequentially consistent behavior at critical moments in a program.

.
.
.
Here’s the litmus test that showed what it meant for x86 to have a total store order:
```
Litmus Test: Independent Reads of Independent Writes (IRIW)
Can this program see r1 = 1, r2 = 0, r3 = 1, r4 = 0?
(Can Threads 3 and 4 see x and y change in different orders?)

// Thread 1    // Thread 2    // Thread 3    // Thread 4
x = 1          y = 1          r1 = x         r3 = y
                              r2 = y         r4 = x
On sequentially consistent hardware: no.
On x86 (or other TSO): no.
On ARM/POWER: yes!
```
On ARM/POWER, different threads may learn about different writes in different orders. They are not guaranteed to agree about a total order of writes reaching main memory, so Thread 3 can see x change before y while Thread 4 sees y change before x.
