# [Myth Machines](https://web.stanford.edu/class/cs107a/notes/myth-machines) at Stanford:

In CS 107, you won't run a single line of your code on your own laptop. Instead, you'll be using SSH to run all of your programs remotely on these Myth machines.

Do we have to? Yes. It's important to know how to use ssh and to use computers remotely through a terminal. Real programmers do this all the time, and especially so during the pandemic.

## What kind of software is on the Myth machines?

The Myth machines run a flavor of the Linux operating system. So yes, technically all the programs you write will be "Linux programs"! (But most C programs we write can be compiled to run on any computer system.)

- You may hear the Myth machines being referred to as "UNIX-like". UNIX was the first popular operating system. It was created in the 1970s and due to its generous licensing became widespread both in universities and commercially. Linux and macOS were both heavily influenced by UNIX and hence we call them "UNIX-like". You'll find that much of what you learn about using the terminal will apply to your Linux or macOS computer (if you have one) with little modification.

- Windows is not UNIX-like. If you open a terminal (called "Command Prompt") on Windows, you'll find that you can't even run ls because it doesn't exist. (Instead, you use a program called dir.) The underlying design of the operating system is also quite different and when you write super low-level programs, you'll have to interface with the OS differently compared to Linux and macOS.

The Myth machines use what's called the [Andrew File System](https://en.wikipedia.org/wiki/Andrew_File_System).

* Assignment 1: [SAXPY program](https://github.com/stanford-cs149/asst1/tree/master/prog5_saxpy)

we want to perform ```result[i] = scale*X[i] + Y[i]``` for ```i = 0, ..., 20M``` and there is an interesting hardware-level phenomena. We load X[i] and Y[i] and compute result[i]. Because of ho modern CPUs work, upon writing to memory, is result[i] is not in cache, we first load cache line (64 bytes; e.g. 16 floats) to cache and then do the computation in cache and then write back the whole cache line to memory. The technical term is write-allocate policy (vs no-write-allocate policy). Here is ChatGPT talking:
```
When considering memory bandwidth, we also have to take into account the write-back behavior of caches. Most CPUs use a write-allocate policy, which works as follows:

- When writing to memory, if the data is not already in the cache, the CPU first loads the entire cache line containing the address.
- The modification is done in the cache, and later the cache line is written back to memory.
Thus, when writing to result[i], the CPU:

- Loads the cache line containing result[i] (even though it's writing, not reading).
- Writes the modified value back to memory.
```
