# [Myth Machines](https://web.stanford.edu/class/cs107a/notes/myth-machines) at Stanford:

In CS 107, you won't run a single line of your code on your own laptop. Instead, you'll be using SSH to run all of your programs remotely on these Myth machines.

Do we have to? Yes. It's important to know how to use ssh and to use computers remotely through a terminal. Real programmers do this all the time, and especially so during the pandemic.

## What kind of software is on the Myth machines?

The Myth machines run a flavor of the Linux operating system. So yes, technically all the programs you write will be "Linux programs"! (But most C programs we write can be compiled to run on any computer system.)

- You may hear the Myth machines being referred to as "UNIX-like". UNIX was the first popular operating system. It was created in the 1970s and due to its generous licensing became widespread both in universities and commercially. Linux and macOS were both heavily influenced by UNIX and hence we call them "UNIX-like". You'll find that much of what you learn about using the terminal will apply to your Linux or macOS computer (if you have one) with little modification.

- Windows is not UNIX-like. If you open a terminal (called "Command Prompt") on Windows, you'll find that you can't even run ls because it doesn't exist. (Instead, you use a program called dir.) The underlying design of the operating system is also quite different and when you write super low-level programs, you'll have to interface with the OS differently compared to Linux and macOS.

The Myth machines use what's called the [Andrew File System](https://en.wikipedia.org/wiki/Andrew_File_System).
