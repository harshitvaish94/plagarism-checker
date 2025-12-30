#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50
#define STOP_WORDS_COUNT 14

// List of common stop words to ignore
const char *stopWords[STOP_WORDS_COUNT] = {
    "a", "an", "the", "is", "in", "on", "at", "and", "or", "of", "to", "with", "for", "by"
};

// Convert a word to lowercase
void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Check if word is a stop word
int isStopWord(const char *word) {
    for (int i = 0; i < STOP_WORDS_COUNT; i++) {
        if (strcmp(word, stopWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Read words from file, skip stop words
int readWords(char *filename, char words[][WORD_LEN]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    int count = 0;
    char temp[WORD_LEN];

    while (fscanf(file, "%s", temp) == 1 && count < MAX_WORDS) {
        toLowerCase(temp);
        if (!isStopWord(temp)) {
            strcpy(words[count], temp);
            count++;
        }
    }

    fclose(file);
    return count;
}

// Count matching words
int countMatches(char words1[][WORD_LEN], int count1, char words2[][WORD_LEN], int count2) {
    int matches = 0;
    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (strcmp(words1[i], words2[j]) == 0) {
                matches++;
                break; // avoid duplicate counting
            }
        }
    }
    return matches;
}

// Main
int main() {
    char file1[] = "file1.txt";
    char file2[] = "file4mid.txt";

    char words1[MAX_WORDS][WORD_LEN];
    char words2[MAX_WORDS][WORD_LEN];

    int count1 = readWords(file1, words1);
    int count2 = readWords(file2, words2);

    if (count1 == -1 || count2 == -1) {
        return 1; // error reading files
    }

    int matches = countMatches(words1, count1, words2, count2);
    float similarity = (float)matches / count1 * 100;

    printf("Total words (excluding stop words) in file1: %d\n", count1);
    printf("Matching words: %d\n", matches);
    printf("Similarity: %.2f%%\n", similarity);

    if (similarity > 50) {
    printf("Warning: High possibility of plagiarism.\n");

} 
else if (similarity > 25) {
    printf("Caution: Moderate similarity. Possible partial plagiarism.\n");
} 
else {
    printf("Low similarity. Probably original work.\n");
}


   
   
   

    return 0;
}
