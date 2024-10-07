# CodeCamp1

## Overview
This project, named **CodeCamp1**, was developed as part of my learning journey in Java programming and unit testing using JUnit. The main functionality includes the implementation of a `CharGrid` class that calculates the area of a specified character in a grid of characters.

## Features
- **CharGrid Class**: Contains methods for constructing a character grid and calculating the area for a given character.
- **JUnit Testing**: Includes unit tests to ensure the correct functionality of the `CharGrid` methods.

## Getting Started

### Prerequisites
- Java Development Kit (JDK) 21 or higher
- JUnit 4 or 5
- A Java IDE (e.g., Eclipse, IntelliJ, or Apache NetBeans)

### Installation

1. Clone the repository:

   ```bash
   git clone ...
   cd Coding___Practice/codecamp1
2. Compile the Java files:

```bash
javac -cp .:path/to/junit.jar CharGrid.java CharGridTest.java
```
3. Run the JUnit tests:

```bash
java -cp .:path/to/junit.jar:path/to/hamcrest.jar org.junit.runner.JUnitCore CharGridTest
```
### Usage

To use the CharGrid class, you can create an instance with a character grid, then call the charArea(char ch) method to find the area of the specified character.

### Example:
```java
char[][] grid = {
    {'a', 'a', 'b'},
    {'a', 'a', 'b'},
    {'b', 'b', 'b'}
};

CharGrid charGrid = new CharGrid(grid);
int area = charGrid.charArea('a'); // Returns 4
```

### Testing

The CharGridTest class contains unit tests for verifying the functionality of the CharGrid class.

#### Example Test:
```java
@Test
public void testCharArea() {
    char[][] grid = {
        {'a', 'a', 'b'},
        {'a', 'a', 'b'},
        {'b', 'b', 'b'}
    };
    CharGrid charGrid = new CharGrid(grid);
    assertEquals(4, charGrid.charArea('a')); // Area of 'a' should be 4 (2x2)
}
```
### Conclusion

This project helped solidify my understanding of Java programming concepts and the importance of unit testing. I learned how to implement and run JUnit tests to ensure the reliability of my code.

### License
Adapted partially from CS108 2008/09 Stanford course.
