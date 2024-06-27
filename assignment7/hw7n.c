// name: Dylan Mesa
// email: mesa.d@northeastern.edu

// Hash table with doubly linked list for chaining/
#include <stdio.h>
#include <stdlib.h> 

struct bucket* hashTable = NULL; 
int BUCKET_SIZE = 10; 

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
    newNode->next = NULL;
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
        printf("Added %d to table with key %d.\n", value, key);
    }
    //bucket not empty
    else{
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head->prev = newNode;
        hashTable[hashIndex].head = newNode;
        printf("Added %d to table with key %d.\n", value, key);
    }
}

// remove a key
void remove_key(int key){
    int hashIndex = hashFunction(key);
    struct node* curr = hashTable[hashIndex].head;
    while(curr != NULL){
        //head is key
        if(curr->key == key && curr->prev == NULL){
            //more to list
            if(curr->next != NULL){
                curr->next->prev = NULL;
                hashTable[hashIndex].head = curr->next;
                printf("Removed key %d from table.\n", key);
                return;
            }
            //list empty
            else{
                hashTable[hashIndex].head = NULL;
                printf("Removed key %d from table.\n", key);
                return;
            }
        }
        //key at middle or end of list
        else if(curr->key == key && curr->prev != NULL){
            curr->prev->next = curr->next;
            printf("Removed key %d from table.\n", key);
            return;
        }
        //go next node
        curr = curr->next;
    }
    printf("Key not found.\n");
}

// search a value using a key
void search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;
    while(node != NULL){
        if(node->key == key){
            printf("Key %d found with value %d.\n", node->key, node->value);
            return;
        }
        node = node->next;
    }
    printf("Key not found.\n");
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

int main(){
    hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
    
    add(0, 1);
    add(1, 10);
    add(11, 12);
    add(21, 14);
    add(31, 16);
    add(5, 18);
    add(7, 19);

    display();

    remove_key(31);
    remove_key(11);

    display();

    search(11);
    search(1);
}
