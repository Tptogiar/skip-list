//
// Created by Tptogiar on 2022/9/8.
//
#include "SkipList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstring>

static struct SkipListNode* skipListCreateNode(int level, int key, int value){

    struct SkipListNode *node = NULL;
    node = malloc(sizeof(*node) + level * sizeof(node));
    if(node == NULL){
        return NULL;
    }
    memset(node,0,sizeof(*node)+level*sizeof(node));
    node->key = key;
    node->value = value;
    node->maxLevel = level;
    return node;
}


struct SkipList* skipListCreate(int maxLevel){
    struct SkipList* list = NULL;
    list = malloc(sizeof(*list));
    if(list==NULL){
        return NULL;
    }
    list->level = 1;
    list->nodeCount = 0;
    list->head = skipListCreateNode(maxLevel,0,0);
    if(list->head == NULL){
        free(list);
        return NULL;
    }
    return list;
}


static int skipListGetLevel(struct SkipList* list){
    int i = 0 ;
    int level = 1;
    for (int j = 0; j < list->head->maxLevel; ++j) {
        if((rand()%2) == 1){
            level++;
        }
    }
    return level;
}


int skipListInsertNode(struct SkipList* list, int key, int value){
    struct SkipListNode** update = NULL;
    struct SkipListNode* cur = NULL;
    struct SkipListNode* prev = NULL;
    struct SkipListNode* insert = NULL;
    int i = 0;
    int level = 0;

    if(list == NULL){
        return -1;
    }

    update = (struct SkipListNode**) malloc(sizeof(list->head->maxLevel * sizeof(struct SkipListNode*)));
    if(update == NULL){
        return -2;
    }

    prev = list->head;
    i = list->level -1;
    for(;i>=0;i--){
        while (((cur=prev->next[i]) != NULL) && (cur->key < key) ){
            prev = cur;
        }
        update[i] = prev;
    }
    if ( (cur != NULL) && (cur->key == key)){
        return -3;
    }
    level = skipListGetLevel(list);
    insert = skipListCreateNode(level,key,value);
    if(level > list->level){
        for (int j = list->level; j < level ; ++j) {
            update[j] = list->head;
        }
        list->level = level;
    }

    for (int i = 0; i < level ; ++i) {
        insert->next[i] = update[i]->next[i];
        update[i]->next[i] = insert;
    }

    list->nodeCount++;

    return 0;
}