# VectorCompare
File comparison using vectors: (idea from my job at IT)

Description: 
- I made this project in C++. Originally, this was going to be used to do what my other project called “DatabaseCompare” does, however, when I finished this project, I was told to make it in PHP as it would connect into the system better.
- This program reads in two files, one with data that is out of date, and the other with data that is up to date.
- Next, the program compares the two files to determine if there are any copies in the out of date file and determines what data doesn’t belong.
- Finally, a file with the matching data is created, a file with all the copies in the out of date file is created and a file is created that contains all the data that doesn’t belong.

Process:
- I tried to create all the functions in this program to do only one thing. This way, the program is easy to follow.
- I took time creating function names and variable names to make the program as readable as possible. I wanted to make the program as readable as a book.
- The functions are all organized together so it is easy to find functions that are called within functions.

Difficulties Faced:
- I had troubles trying to think of names that I liked for functions and variables that would help the reader understand exactly what I was trying to say.
  - Solution: I would revisit names that I made multiple times and wasn’t afraid to go back and make changes to increase readability.
- This was the first time I used a vector as my main data structure. I wanted to use it due to its great scalability, but I was having problems understanding how it worked because I was so used to using arrays.
  - Solution: I made smaller programs using vectors to test scaling the vector up and down.

New Skills Acquired:
- I learned how to write code that is clean and easy to read.
- I learned the importance of choosing variable names and function names so that when I go back to look at my code, I don’t have to rely on comments that could be out of date.
