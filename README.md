-> Plagiarism Checker in C

A simple content verification and plagiarism detection tool implemented in C. This program compares two text files, filters out common stop words, and calculates a similarity percentage based on matching words. It helps in identifying potential plagiarism by measuring textual overlap between documents.


-> Features

Reads and processes text files using standard C file handling

Converts all words to lowercase for consistent comparison

Removes common stop words (e.g., a, the, is, and, of)

Uses string matching to detect overlapping words

Calculates a similarity percentage

Provides plagiarism risk levels based on similarity score

->How It Works

The program reads words from two input text files.

Each word is converted to lowercase.

Common stop words are ignored to improve accuracy.

Remaining words are compared using string matching.

A similarity score is calculated using the formula:

Similarity (%) = (Matching Words / Total Words in File 1) × 100


Based on the score, the program classifies the similarity level.
->Similarity Interpretation

Above 50% → High possibility of plagiarism

25% – 50% → Moderate similarity (possible partial plagiarism)

Below 25% → Low similarity (probably original content)
->Tech Stack

Language: C

Concepts Used:

File handling

String manipulation

Tokenization

Basic NLP concepts (stop-word removal)
