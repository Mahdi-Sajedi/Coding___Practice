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

- Command line classpath

  • javac -classpath foo.jar:/some/dir:. Bar.java

- Run time classpath

  • Summary: the compile time classpath used to check classes during compilation, does not link them in. The run time classpath is used to find and load classes as they are referenced during the run

- Arguments: ```> java Foo aaa bbb``` aaa and bbb are arguments

## Static

• Static variables and methods are not associated with an object of the class. Instead, they are associated
with the class itself.

• a static variable named count in the Student class would be referred to as Student.count. 

### System.out is a static variable out in the System class that represents standard output.

• Game Design example:  the Monster class contains a *static* Monster.roar variable, and all the monster objects share that one variable for playing roar.mp3

• Math.max(a, b): max() is a **static** method in Math class

• s.getStress(): getStress() is a **regular** method and s points to an Student object.

• s.foo() compiles fine, but it discards s as a receiver, using its compile time type to determine which class to use and translating the call to the Student.foo() form

```java
public class Student {
 private int units; // units ivar for each Student
 // Define a static int counter
 // to count the number of students.
 // Assign it an initial value right here.
 private static int numStudents = 0;
 public Student(int init_units) {
 units = init_units;
 // Increment the counter
 Student.numStudents++;
 // (could write equivalently as numStudents++)
 }
 public static int getNumStudents() {
 // Clients invoke this method as Student.getNumStudents();
 // Does not execute against a receiver, so
 // there is no "units" to refer to here
 return Student.numStudents;
 }
 // rest of the Student class
 ...
} 
```
ChatGPT: This approach follows the principle of encapsulation, where you hide the internal state of an object (like numStudents) and provide controlled access through methods (like getNumStudents()).

## Files

• InputStream and OuputStream are the fundamental superclasses.

• The classes with "reader" or "writer" in the name deal with text files, e.g. FileReader, BufferedReader.

• For non-text data files (such as jpeg, png, mp3) use FileInputStream, FileOutputStream,
BufferedInputStream, BufferedOutputStream -- these treat the file as a plain sequence of
bytes.

• You can specify a unicode encoding to be used by the text readers and writers -- defines the translation between the bytes of the file and the **2-byte** unicode encoding of Java chars.

### Exception

•
```java
 try {
 stmt();
 stmt();
 stmt();
 stmt();
}
catch (Exception ex) {
 ex.printStackTrace();
 System.exit(1);
}
```

•  As a simple default strategy, put a printStackTrace() in the catch so you get an indication of what happened

• When an exception is thrown at runtime, it
looks for the first matching catch (...) clause -- so catch (Exception e) would catch any type of
exception, but catch (IOException e) would catch only IOExceptions.

• In Java code, if there is a method call like in.readLine() that can throw an exception, then the compiler
will insist that the calling code deal with the exception, typically with a try/catch block. This can be
annoying, since the compiler forces you to put in a try/catch when you don't want to think about that case.
However, this strict structure is one of the things that **makes Java code reliable in production**

• unchecked exceptions: out of bounds, null pointer
  
  all other "checked" exceptions need try/catch block, otherwise code won't compile

## Java Collections

- List, Set, Map
  
  • List is a general interface, and ArrayList and LinkedList are implementing classes. ArrayList is the best general purpose List

  • Lists can only store objects, like String and Integer, but not primitives like int. Another way to say this is that the collection classes can only
store pointers.

  • ```List<String> words = new ListArray<String>();``` -> ```words.add("This");``` -> ```words.size();``` -> ```words.get(0)```

  • The size() method returns the int size of a list (or any collection)

  • ```List<String> words2 = new ArrayList<String>(words);``` copies the pointers in words List to words2 (just like words2 = words)

  •  ```List<Object>``` can contain objects of different types, since all classes in Java inherit from Object.

       • Python is Dynamically typed so lists can contain different objects by default.

  •  subList(int fromIndex, int toIndex) example below
  
```java
 // colors2 is {"red", "green", "blue", "pink"}
 // Use subList() to make a "front" List showing just elements 0, 1, 2 of colors2.
 List front = colors2.subList(0, 3);
 System.out.println("front " + front); // [red, green, blue]
 // front is {"red", "green", "blue"}

 // Can make changees to front, and they go through to underlying colors2,
 // but do not make changes to colors2 while using front.

 front.contains("green"); // true
 front.remove("green");
 front.add("orange");
 // front is {"red", "blue", "orange"}
 // colors2 is {"red", "blue", "orange", "pink"}
```
  • Iterator example below.  Code that uses iteration must not modify the collection during the iteration.

```java
// Suppose we have a "words" list of strings:
List words = new ArrayList(); // create a list of strings

Iterator<String> it = words.iterator();
while (it.hasNext()) {
 String str = it.next();
 // Do something with str
}
```
```java
// words is: {"this", "and", "that"}
// Remove words length 4 or more.
Iterator<String> it = words.iterator();
while (it.hasNext()) {
 String str = it.next();
 if (str.length() >= 4) it.remove();
}
// words is: {"and"}
```

  • There is a more powerful type of iterator, the ListIterator, which works for list types, but not other collection types. The ListIterator can go forwards and backwards and can insert and delete. The ListIterator is powerful but more rarely used. Loop foreach and Iterator goes far enough for most use cases.

- Boxing/unboxing/autoboxing example: conversion between int value and Integer object.

```java
// Auto unboxing DOES NOT WORK with == -- this code is wrong.
 if (nums.get(0) == 126) {
 System.out.println("found 126");
 }

 // Use .intValue() to unbox manually -- this code is correct.
 if (nums.get(0).intValue() == 126) {
 System.out.println("found 126");
 }
```

• List of Integer objects uses more memory than array of ints but is more powerful.

## Set

• use standard Collection methods ```addAll(), iterator(), contains()```

• use standard utility methods ```addAll(), retainAll(), containsAll()``` to perform union, intersection and isSubset operations

- HashSet -> constant time find and insert (Always?) and only works with String and Integer which have a ```hashCode()``` defined.

- TreeSet -> an alternative to HashSet, more costly, keeps the set in sorted order, and iteration yields the values in sorted order

## Map

- a general interface of the basic map features

- implemented by 2 main classes: HashMap (Most commonly used) and TreeMap

- methods put() and get()

      Object get(Object key) -> null if there is no entry for this key in the map.

- Both the key and value must be object types such as String or Integer or List

- It is standard to declare the variable with the general type, Map, as shown here:
```java
Map<String, String> states = new HashMap<String, String>();
states.put("ca", "California");
states.put("az", "Arizona");
states.put("mn", "Minnesota");
states.put("nj", "New Jersey");
```

- very fast performance: With a HashMap, even if there are 100,000 entries in the map, get() and
put() can access a particular entry almost instantaneously (constant time).

- TreeMap is slower. Uses a Red-Black tree (a type of self-balancing binary search tree).

### Synchronization
HashMap:

Not synchronized (not thread-safe). You must manually synchronize it if used in a multi-threaded environment.

TreeMap:

Also not synchronized. Similar to HashMap, you must handle synchronization externally if needed.

- values() and keySet() methods

      Collection values() -- "live" read-only Collection of map values in some random order
      Set keySet() -- "live" set of keys in the map.

- Be careful! There is no separate set!! removing an element from the key set removes corresponding entry from the map. Also adding to the key set does not work and you must use put(). you can use common Collection operations for this set, like ```foreach, iterator(), add(), remove(), addAll(), removeAll()```.

- entrySet() method -> provides a set of special ```Map.Entry<KEY_TYPE, VALUE_TYPE>``` objects -- Entry class is defined inside Map class -> then you can use getKey() and getValue() on those Map.Entry objects

       This provides access to the entry data directly from the Map's internal data structures without the cost of calling get() for each key.

       The keySet() makes the most sense where performance is important. If performance is not critical, I find the plain keySet() approach to be more readable.


       
