//
// Created by Tptogiar on 2022/9/7.
//

#ifndef SKIP_LIST_SKIPLIST_H
#define SKIP_LIST_SKIPLIST_H

struct SkipListNode{
    int key;
    int value;
    int maxLevel;
    struct SkipListNode* next[];
};

struct SkipList{
    int level;
    int nodeCount;
    struct SkipListNode* head;
};

extern struct SkipList* skipListCreate(int maxLevel);
extern int skipListInsert(struct SkipList* list,int key,int value);
extern int skipListDelete(struct SkipList* list,int key);
extern int skipListModify(struct SkipList* list,int key,int value);
extern int skipListSearch(struct SkipList* list,int key,int *value);
extern int skipListDestroy(struct SkipList* list);



#endif //SKIP_LIST_SKIPLIST_H
