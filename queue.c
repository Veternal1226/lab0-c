#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    if (!q)
        return;
    while (q->head) {
        list_ele_t *target = q->head;
        q->head = q->head->next;
        free(target->value);
        free(target);
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q)  // q is NULL
        return false;
    list_ele_t *newh = (list_ele_t *) malloc(sizeof(list_ele_t));
    if (!newh) {  // malloc fail
        free(newh);
        return false;
    }
    int len = strlen(s) + 1;  // +1 to save \0
    newh->value = (char *) malloc(sizeof(char) * len);
    if (!newh->value) {  // malloc fail
        free(newh->value);
        free(newh);
        return false;
    }
    strncpy(newh->value, s, len);
    newh->next = q->head;
    q->head = newh;
    if (q->size == 0)
        q->tail = newh;
    q->size++;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q)  // q is NULL
        return false;
    list_ele_t *newt = (list_ele_t *) malloc(sizeof(list_ele_t));
    if (!newt) {  // malloc fail
        free(newt);
        return false;
    }
    int len = strlen(s) + 1;  // +1 to save \0
    newt->value = (char *) malloc(sizeof(char) * len);
    if (!newt->value) {  // malloc fail
        free(newt->value);
        free(newt);
        return false;
    }
    strncpy(newt->value, s, len);
    q->tail->next = newt;
    q->tail = newt;
    newt->next = NULL;
    if (q->size == 0)
        q->tail = newt;
    q->size++;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q || !q->head || !sp) {  // queue is NULL/empty,or sp is NULL ->fail
        return false;
    }
    list_ele_t *rdyrm = q->head;
    int len = strlen(q->head->value) + 1;
    if (bufsize < len)
        len = bufsize;

    strncpy(sp, q->head->value, len);
    q->head = q->head->next;
    q->size--;
    free(rdyrm->value);
    free(rdyrm);
    return true;

}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
