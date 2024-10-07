# CodeCamp1

## Overview
This simple homework from Stanford's CS108 [course](https://web.stanford.edu/class/archive/cs/cs108/cs108.1092/oldSite.shtml), was worked out as part of my learning journey in Java programming and especially unit testing using JUnit. The main functionality includes the implementation of a `CharGrid` class that calculates the area of the smallest rectangle containing all occurrences of a specified character in a grid of characters.

## Features
- **CharGrid Class**: Contains methods for constructing a character grid and calculating the area for a given character.
- **JUnit Testing**: Includes unit tests to ensure the correct functionality of the `CharGrid` methods.

## Getting Started

### Prerequisites
- Java Development Kit (JDK) 21 or higher
- JUnit 4 or 5. I used JUnit 5.
- A Java IDE (e.g., Eclipse, IntelliJ, or Apache NetBeans). I used Eclipse.

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
