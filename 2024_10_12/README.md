Script for finding image files containing name 'cat' in a specified directory (default to home directory) and all its subdirectories, and logging those filenames in a log file.
```bash
#!/bin/bash

# Define the directory to search in (use current directory by default)
SEARCH_DIR="${1:-.}"

# Define the regex pattern to match filenames with "cat" and common image file extensions
REGEX="(^|[^a-zA-Z])cat([^a-zA-Z]|$).*\.(jpg|jpeg|png|gif|bmp)$"

# Define the log file to store the results
LOG_FILE="cat_images.log"

# Clear the log file if it already exists
> "$LOG_FILE"

# Find image files with "cat" in the filename and log them
find "$SEARCH_DIR" -type f | grep -Ei "$REGEX" | while read -r file; do
    echo "$file"     # Print the file path to the console
    echo "$file" >> "$LOG_FILE"  # Append the file path to the log file
done

# Output a message when done
echo "Search complete. Results logged in $LOG_FILE."

```

- ```SEARCH_DIR="${1:-.}"```: 1 refers to first input argument. :- means in case of no argument passed to the script, use ```.```

- ```REGEX="(^|[^a-zA-Z])cat([^a-zA-Z]|$).*\\.(jpg|jpeg|png|gif|bmp)$"```

  -  ```(^|[^a-zA-Z])``` ensures 'cat' either starts the filename or it is preceded by non-alphabetic characters like -, _, 1, 2, 0, etc.

  - ```([^a-zA-Z]|$)``` ensures that filename ends with 'cat'  or there are non-alphabetic characters following it

  - ```.*``` matches any characters (zero or more)

  - ```(jpg|jpeg|png|gif|bmp)$``` matches common image file extensions at the end of the filename.

- ```LOG_FILE="cat_images.log"``` logfile

- ```> "$LOG_FILE"```

  - ```>``` is redirection operator. it clears the file content, or if it doesn't exist it creates the file.

  - use of quote around $filename ensures capture of filesnames with spaces
 
- ```find "$SEARCH_DIR" -type f```

  - gives a list of all regular (-f option) files in specified directory

- ```grep -Ei "$REGEX"``` filters the list to filenames that match the ```"$REGEX"``` pattern.

  - i for case insensitive: cat or CAT

  - E for use of extended regular expressions that allows more complex patterns like +, {}
 
- ```bash
    while read -r file; do 
      echo "$file"     # Print the file path to the console
      echo "$file" >> "$LOG_FILE"  # Append the file path to the log file 
    done 
    ```

  - `read` command processes each line (filename) of input (here list of filenames that match the reex pattern) one by one, storing it in the ```file``` variable for use inside the loop.
 
  -  ```-r``` flag ensures that backslashes (\) are treated literally rather than as escape characters
    
- an example of using while loop without pipe:
  ```bash
  while read -r line; do
    echo "Student: $line"
  done < students.txt
  ```
  - ```<``` operator ridirects the contents of ```students.txt``` to while loop as input
