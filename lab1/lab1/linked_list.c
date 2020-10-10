#include "linked_list.h"
#include "limits.h"

node *linked_list_init(){
    node *head = (node*)malloc(sizeof(node));
    head->count = 0;
    head->next = NULL;
    return head;
}

void linked_list_free(node *head){
    node *cur = head;
    node *last;
    while(cur != NULL){
        last = cur;
        cur = cur->next;
        free(last);
    }
}

char linked_list_string[0x10000];

char *linked_list_tostring(node *head){
    node *cur = head->next;
    char *position;
    int length = 0;
    while(cur != NULL){
        position = linked_list_string + length;
        length += sprintf(position, "%d", cur->value);
        cur = cur->next;
        if(cur != NULL){
            position = linked_list_string + length;
            length += sprintf(position, "->");
        }
    }
    position = linked_list_string + length;
    length += sprintf(position, "%c", '\0');
    return linked_list_string;
}

int linked_list_size(node *head){
    return head->count;
}

void linked_list_append(node *head, int val){
    node *cur = head;
    node *new_node;
    while(cur->next != NULL){
        cur = cur->next;
    }
    new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    cur->next = new_node;
    head->count++;
}

/* your implementation goes here */

<<<<<<< HEAD
/* insert val at position index */
void linked_list_insert(node *head, int val, int index) {
    if(index < 0) return;
    if(index > head->count) return;
    node *cur = head;
    node *new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    int idx = 0;
    while(idx < index && cur->next!=NULL){
        cur = cur->next;
        idx++;
    }
    new_node->next = cur->next;
    cur->next = new_node;
    head->count++;
}

/* delete node at position index */
void linked_list_delete(node *head, int index) {
    if(index < 0 ) return;
    if(index >= head->count) return;
    node *cur = head;
    node *nxt;
    int idx = 0;
    while(idx < index && cur->next != NULL){
        cur = cur->next;
        idx++;
    }
    nxt = cur->next;
    cur->next = nxt->next;
    free(nxt);
    head->count--;
}

/* remove the first occurence node of val */
void linked_list_remove(node *head, int val) {
    node *cur = head;
    node *last;
    node *nxt;
    while(cur->next != NULL){
        last = cur;
        cur = cur->next;
        nxt = cur->next;
        if(cur->value == val){
            last->next = nxt;
            free(cur);
            head->count--;
            return;
        }
    }
}

/* remove all occurences of val */
void linked_list_remove_all(node *head, int val) {
    node *cur = head;
    node *last = head;
    node *target;
    while(cur->next != NULL){
        cur = cur->next;
        target = cur;
        if(target->value == val) {
            last->next = cur->next;
            free(target);
            head->count--;
        } else {
            last = cur;
        }
    }
}

/* get value at position index */
int linked_list_get(node *head, int index) {
    node *cur = head;
    int idx = 0;
    while(cur->next != NULL){
        cur = cur->next;
        if(idx == index) {
            return cur->value;
        }
        idx++;
    }
    return INT_MIN;
}

/* search the first index of val */
int linked_list_search(node *head, int val) {
    node *cur = head;
    int idx = 0;
    while(cur->next != NULL){
        cur = cur->next;
        if(cur->value == val) {
            return idx;
        }
        idx++;
    }
    return -1;
}

/* search all indexes of val */
node *linked_list_search_all(node *head, int val) {
    node *cur = head;
    node *result = linked_list_init();
    int idx = 0;
    while(cur->next != NULL){
        cur = cur->next;
        if(cur->value == val) {
            linked_list_append(result, idx);
        }
        idx++;
    }
    return result;
}
=======
void linked_list_insert(node *head, int val, int index){

}

void linked_list_delete(node *head, int index){

}

void linked_list_remove(node *head, int val){

}

void linked_list_remove_all(node *head, int val){

}

int linked_list_get(node *head, int index){
    return 0;
}

int linked_list_search(node *head, int val){
    return 0;
}

node *linked_list_search_all(node *head, int val){
    return linked_list_init();
}
>>>>>>> 0be3fb9e5232023f1a747b67697795c4800963e7
