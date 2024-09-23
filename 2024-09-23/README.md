## CS108 Fall 2008/09 OOP with Java

Instructor:
    
    Osvaldo Jiménez
    oj@cs.stanford.edu
    Gates 195

- CS107 was C++

- in Java '=' asignment always does Shallow copy. important remarks on GC.

```java
int[] a = new int[100];
a.length // .length() for strings
```

- 'Arrays' class with its convenience static methods. System.arraycopy() for (fast) copying of one array to another:

  • System.arraycopy(source-array, source-index, dest-array, dest-index, lengthto-copy);

- a.equals(b) : not a deep comparison, only compares the pointers.

  • Arrays.equals(a, b): for 1d arrays, uses equals on each pair of elements
  • Arrays.deepEquals(): for multi-dim arrays

- 2d array: m $\times$ n, a collection of m pointers each pointing at a 1d array of length n

   • System.arraycopy() does not copy all of a 2-d array -- it just copies the pointers in the outer
1-d array

- Packages, imports

   • Full name of the
String class is java.lang.String.

   • for ArrayList the full name is java.util.ArrayList. The java.util package contains utilities for
Java

   • All the later bytecode stages in the JVM use the full name, e.g. java.lang.Strings. Short names like Strings are only used in .java source files.

- Compile Time Import

  • ```import java.util.ArrayList;``` makes just that one class available by its short name
  
  • Having lots of import statements will not make your code any bigger or slower -- it only allows you to use shorter names in your .java code.

  • Example of possible ambiguity of List class: the generated .class files always use the long java.util.List or java.awt.List form in the bytecode.

  • Compiled Java code with many standard classes is still tiny -- your code just has references to the classes, not copies of them.

- Java Command Line

  • The command line java compiler is called javac
   
  • Foo$Bar.class contains the bytecode for a Bar class defined inside of Foo

  • The java command runs a program, and the argument is the class that contains main()

-  Command line classpath

  • javac -classpath foo.jar:/some/dir:. Bar.java 
  
