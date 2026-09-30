# DSA Quiz Application in C

This is a C language conversion of the original C++ DSA Quiz Application from [Anisha1343/dsa-quiz-application](https://github.com/Anisha1343/dsa-quiz-application).

## Features

- **Question Management**: Add multiple choice questions with 4 options each
- **Quiz Taking**: Interactive quiz experience
- **Answer Validation**: Automatic checking of user answers
- **Scoring System**: Tracks correct answers and calculates total score
- **Performance Report**: Detailed results showing each question, correct answer, user's answer, and status

## Data Structures Used

1. **Linked List for Questions**: Stores all quiz questions
2. **Linked List for Responses**: Stores user's answers and results

## Compilation

### Using GCC directly:
```bash
cd dsa_quiz_c
gcc -Wall -Wextra -std=c11 -o dsa_quiz main.c
```

### Using Makefile:
```bash
cd dsa_quiz_c
make
```

## Running the Program

```bash
./dsa_quiz
```

## Program Flow

1. Enter the number of questions you want to add to the quiz
2. For each question, provide:
   - Question number
   - Question text
   - Option A, B, C, D
   - Correct answer (A, B, C, or D)
3. The quiz will start automatically
4. Answer each question by entering A, B, C, or D
5. View your performance report with:
   - Question numbers
   - Correct answers
   - Your answers
   - Status (CORRECT/WRONG)
   - Points for each question
   - Total score

## Example Session

```
Enter number of questions: 2
Enter Question number: 1
Enter Question: What is the time complexity of binary search?
Enter option A: O(1)
Enter option B: O(n)
Enter option C: O(log n)
Enter option D: O(n^2)
Enter Correct option: C

Enter Question number: 2
Enter Question: Which data structure uses LIFO?
Enter option A: Queue
Enter option B: Stack
Enter option C: Array
Enter option D: Linked List
Enter Correct option: B

Question No: 1
What is the time complexity of binary search?
A. O(1)
B. O(n)
C. O(log n)
D. O(n^2)
Enter your answer: C
STATUS: CORRECT

Question No: 2
Which data structure uses LIFO?
A. Queue
B. Stack
C. Array
D. Linked List
Enter your answer: B
STATUS: CORRECT

==========================================================================
 FINAL PERFORMANCE REPORT
==========================================================================

Q.No.      Correct    Your Ans     Status          Points  
--------------------------------------------------------------------------
1          C          C            CORRECT         1       
2          B          B            CORRECT         1       
--------------------------------------------------------------------------

TOTAL SCORE : 2
==========================================================================
```

## Files in this Directory

- `main.c`: Main source code of the DSA Quiz Application
- `Makefile`: Build automation file
- `CONVERSION_NOTES.md`: Detailed notes on C++ to C conversion
- `README.md`: This file
- `test_input.txt`: Sample input for testing

## Cleaning Up

To remove the compiled binary:
```bash
make clean
```

Or:
```bash
rm -f dsa_quiz
```

## Technical Details

- **Language**: C11 standard
- **Memory Management**: Dynamic allocation with `malloc()` and proper deallocation
- **Input/Output**: Uses `printf()`, `scanf()`, and `fgets()`
- **String Handling**: Manual newline removal using `strcspn()`
- **Formatting**: Achieved through `printf()` format specifiers

## Conversion from C++

All core features and logic from the original C++ version have been preserved:
- ✅ Linked list data structures
- ✅ Question insertion
- ✅ Quiz taking functionality
- ✅ Answer validation
- ✅ Scoring system
- ✅ Performance report generation

A PROJECT MADE FOR SUBJECT:-DATA STRUCTURES IN SEMESTER 3 IN A.D.I.T INSTITUTE BY VATSAL SHAH , VASU PATEL AND SNEHIL SONI. 


See `CONVERSION_NOTES.md` for detailed information on the conversion process.
