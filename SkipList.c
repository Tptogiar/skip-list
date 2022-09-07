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


