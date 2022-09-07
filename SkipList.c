//
// Created by Tptogiar on 2022/9/8.
//
#include "SkipList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstring>

static struct SkipListNode* skipListNodeCreate(int level,int key,int value){

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





