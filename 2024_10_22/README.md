##digging into [quantized](https://android.googlesource.com/platform/external/gemmlowp/+/HEAD/doc/quantization_example.cc) example of gemmlowp

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
