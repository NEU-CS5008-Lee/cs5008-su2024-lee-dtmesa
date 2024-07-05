// name: Dylan Mesa
// email: mesa.d@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 200

// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

struct bucket* hashTable; 
int BUCKET_SIZE = 400; 

// node struct
struct node {
    int key;
    int value;
    struct node* next;
    struct node* prev;
};

// bucket struct
struct bucket{
    struct node* head;
};

// create a new node
struct node* createNode(int key, int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//  hash function with %
int hashFunction(int key){
    return key % BUCKET_SIZE;
}

//  insert a new key
void add(int key, int value){
    int hashIndex = hashFunction(key);
    struct node* newNode = createNode(key, value);
    //bucket empty
    if(hashTable[hashIndex].head == NULL){
        hashTable[hashIndex].head = newNode;
    }
    //bucket not empty
    else{
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head->prev = newNode;
        hashTable[hashIndex].head = newNode;
    }
}

void display(){
    struct node* iterator;

    printf("\n========= display start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %d, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display complete ========= \n");
}

void hashFunction1(char* cityStr){
    int len = strlen(cityStr);
    add(len, len);
}

void hashFunction2(char* cityStr){
    int sum = 0;
    int len = strlen(cityStr);

    for(int i = 0; i < len; i++){
        sum += cityStr[i];
    }
    add(sum, sum);
}

void hashFunction3(char* cityStr){
    int product = 1;

    for(int i = 0; i < 2; i++){
        product *= cityStr[i];
    }
}

//END OF NEW

// check if a character c is a digit
bool isDigit(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

// append character c to string s
void appendChar(char* s, char c) {
  char charToStr[2];           // convert char to string
    charToStr[0] = c;
    charToStr[1] = '\0';          // put NUL to terminate string of one character
    strcat(s, charToStr);
}



int main () {

  char inputLine[MAXSTRING];   // temporary string to hold input line
  char cityStr[MAXSTRING];     // city name
  int  lineNum;                // line number (city rank)
  int  popInt;                 // population
  int  state;                  // FSM state
  int  nextChar;               // index of next character in input string
  char temp[MAXSTRING];        // temp string to build up extracted strings from input characters
  
  hashTable = (struct bucket*)malloc(BUCKET_SIZE * sizeof(struct bucket));
  for(int i = 0; i < BUCKET_SIZE; i++){
    hashTable[i].head = NULL;
  }
 
  FILE* fp;
  fp = fopen("pop.csv","r");

  if (fp != NULL) {
    fgets(inputLine, MAXSTRING, fp); // prime the pump for the first line

    // ***** BEGIN FINTITE STATE MACHINE *****
    
    // STARTSTATE: digit -> S1
    // S1: digit -> S1; , -> S2
    // S2: " -> S3
    // S3: !" -> S3; " -> S4
    // S4: , -> S5
    // S5: " -> S6; ( -> ACCEPTSTATE
    // S6: digit -> S6; , -> S6; " -> ACCEPTSTATE; 
    // ACCEPTSTATE: done!
    // else go to ERRORSTATE
    //
    while (feof(fp) == 0){

      nextChar = 0;
      state = STARTSTATE; 
      strcpy(temp,"");       // temp = ""

      if (nextChar >= strlen(inputLine)){
	// if no input string then go to ERRORSTATE
	state = ERRORSTATE;
      } 

      while ((state != ERRORSTATE) && (state != ACCEPTSTATE)) {
	switch (state) {
	  case STARTSTATE:
	    // look a digit to confirm a valid line
	    if (isDigit(inputLine[nextChar])) {
	      state = S1;
	      appendChar(temp, inputLine[nextChar]);
	    } else {
	      state = ERRORSTATE;
	    }  
	    break;


	case S1:
      	if(strlen(temp) >= 60){
        state = ACCEPTSTATE;
     	 }
      	else if (isDigit(inputLine[nextChar])) {
          state = S1;
          appendChar(temp, inputLine[nextChar]);
          strcpy(cityStr,"");
        } else if(inputLine[nextChar] == ','){
          state = S2;
        } else {
          state = ERRORSTATE;
        }
        break;

    case S2:
      if(strlen(temp) >= 60){
        state = ACCEPTSTATE;
      }
      else if(inputLine[nextChar] == '"') {
          state = S3;
          appendChar(temp, inputLine[nextChar]);
      } else {
        state = ERRORSTATE;
      }
      break;

    case S3:
      if(strlen(temp) >= 60){
        state = ACCEPTSTATE;
      }
      else if(strlen(cityStr) >= 30 && inputLine[nextChar] != '"'){
        state = S3;
        appendChar(temp, inputLine[nextChar]);
      }
      else if(inputLine[nextChar] != '"') {
          state = S3;
          appendChar(temp, inputLine[nextChar]);
          appendChar(cityStr, inputLine[nextChar]);
      } else if(inputLine[nextChar] == '"'){
          state = S4;
          appendChar(temp, inputLine[nextChar]);
      } else {
        state = ERRORSTATE;
      }
      break;

    case S4:
      if(strlen(temp) >= 60){
        state = ACCEPTSTATE;
      }
      else if(inputLine[nextChar] == ','){
          state = S5;
          popInt = 0;
          strcpy(temp,"");
      } else {
        state = ERRORSTATE;
      }
      break;

    case S5:
      if(inputLine[nextChar] == '"'){
            state = S6;
      } 
      else if(inputLine[nextChar] == '('){
              state = ACCEPTSTATE;
      } else {
          state = ERRORSTATE;
        }
      break;

    case S6:
      if (isDigit(inputLine[nextChar])) {
            state = S6;
            appendChar(temp, inputLine[nextChar]);
      } 
      else if(inputLine[nextChar] == ','){
        state = S6;
      }
      else if(inputLine[nextChar] == '"'){
              state = ACCEPTSTATE;
              popInt = atoi(temp);
      }
       else {
            state = ERRORSTATE;
          }
      break;
 
	    
	  case ACCEPTSTATE:
  
	    break;
	    
	  default:
	    state = ERRORSTATE;
	    break;
	} // end switch

	// advance input
	nextChar++;
	
      }	// end while state machine loop

      // ***** END FINITE STATE MACHINE *****
	  

      // process the line - print out raw line and the parsed fields
      //printf("> %.60s\n", inputLine);
      //printf("[%.30s]: %d\n", cityStr, popInt);
      hashFunction1(cityStr);
      //hashFunction2(cityStr);
      //hashFunction3(cityStr);

      // get next line
      fgets(inputLine, MAXSTRING, fp);
      
    } // end while file input loop
    

    fclose(fp);


  
  } else {
    printf("File not found!\n");
  }
    
    FILE* output = freopen("foo.txt", "w", stdout);

  display();

  fclose(output);

  for(int i = 0; i < BUCKET_SIZE; i++){
    struct node* curr = hashTable[i].head;
    while(curr != NULL){
        struct node* temp = curr;
        curr = curr->next;
        free(temp);
    }
  }
  free(hashTable);

  return 0;
}
