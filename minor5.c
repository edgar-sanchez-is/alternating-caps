// =====================================================================
// Name:		Edgar Sanchez
// Course:		CSCE 3600
// Date:		March 7, 2016
// Title:		Minor Assignment 5
// Version:		1.0
// Description:		Implement Mutex Locks, creating one thread
// 			for each character in the sequence and capitalize
//			each letter that has an odd index.
// Format:		minor5
// =====================================================================

#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define SIZE 50

pthread_mutex_t myMutex; 	// Creates a new mutex
char sentence[2000]; 		// Sentence array, 2000 char max
int  charIndex = 0; 		// Char index for sentence array

// Converts lowercase un uppercase
char convertUppercase(char lower) {
	if ((lower > 96) && (lower < 123)) {
		return (lower - 32);
	}
	else {
		return lower;
	}
}

// Prints the converted sentence
void printChar() {
	printf("The new sentence is [%d]: \t%c\n", charIndex, sentence[charIndex]);
	charIndex++;
}

// Function initiated by each new thread
void * convertMessage(void *pVoid) {
	pthread_mutex_lock(&myMutex);	// Locks mutex

	// Capitalizes char if index is odd
	if (charIndex % 2) {
		sentence[charIndex] = convertUppercase(sentence[charIndex]);
	}
	
	printChar();
	pthread_mutex_unlock(&myMutex); // Unlocks mutex
	return 0;
}

int main() {
	pthread_t ts[SIZE]; // Define up to SIZE threads
	char buffer[SIZE];	// Buffer array of chars
	char *p;

	// Initializes and tests Mutex
	if (pthread_mutex_init(&myMutex, NULL) != 0) {
		printf("Mutex initialization failed\n");
		return 1;
	}

	printf("Please enter a phrase (less than 50 characters): ");

	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		if ((p = strchr(buffer, '\n')) != NULL) {
			*p = '\0';
		}
	}

	// Copies string to char array
	strcpy(sentence, buffer);
	
	printf("The original sentence is: \t %s\n", sentence);

	// Creates one thread for each character on the input word
	for(int i = 0; i < strlen(buffer) + 1; ++i) {
		pthread_create(&ts[i], NULL, convertMessage, NULL);
	}
	
	// Waits until all threads finish execution
	for(int i = 0; i < strlen(buffer); i++) {
		pthread_join(ts[i], NULL);
	}

	pthread_mutex_destroy(&myMutex);	// Destroys mutex
	printf("\n");
	return 0;
}