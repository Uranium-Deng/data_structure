/*************************************************************************
	> File Name: 2.list.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月03日 星期二 22时18分24秒
 ************************************************************************/

#include <iostream>
using namespace std;

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct List {
    struct ListNode head;
    int length;
} List;

ListNode *getNewNode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = val;
    node->next = NULL;
    return node;
}
List *getList() {
    List *list = (List *)malloc(sizeof(List));
    list->head.next = NULL;
    list->length = 0;
    return list;
}

bool insert(List *list, int ind, int val) {
    if (!list) return false;
    if (ind < 0 || ind > list->length) return false;
    ListNode *p = &(list->head), *q = getNewNode(val);
    while (ind--) p = p->next;
    q->next = p->next;
    p->next = q;
    list->length++;
    return true;
}

bool erase(List *list, int ind) {
    if (!list) return false;
    if (ind < 0 || ind >= list->length) return false;
    ListNode *p = &(list->head);
    while (ind--) p = p->next;
    ListNode *delete_node = p->next;
    p->next = delete_node->next;
    free(delete_node);
    list->length--;
    return true;
}

void reverse_list(List *list) {
    if (!list) return ;
    ListNode *p = list->head.next, *q;
    list->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = list->head.next;
        list->head.next = p;
        p = q;
    }
}

void output(List *list) {
    if (!list) return ;
    printf("List(%d) = [", list->length);
    for (ListNode *p = list->head.next; p; p = p->next) {
        if (p - list->head.next) printf("->");
        printf("%d", p->data);
    }
    printf("]\n");
}


void clear_list(List *list) {
    if (!list) return ;
    ListNode *p = (list->head).next, *delete_node = NULL;
    while (p) {
        delete_node = p;
        p = p->next;
        free(delete_node);
    }
    free(list);
}


int main() {
    #define MAX_OP 20
    srand(time(0));
    List *list = getList();
    int val, ind, op;
    for (int i = 0; i < MAX_OP; i++) {
        val = rand() % 100;
        ind = rand() % (list->length + 3) - 1;
        op = rand() % 5;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d into list = %d\n", val, ind, insert(list, ind, val));
                break;
            }
            case 3: {
                printf("reverse_list!\n");
                reverse_list(list); break;
            }
            case 4: {
                printf("erase item at %d from list = %d\n", ind, erase(list, ind));
                break;
            }
            default: {
                printf("it's impossible\n");
            }
        }
        output(list);
        printf("\n");
    }
    clear_list(list);
    return 0;
}
/*代码结果输出：
reverse_list!
List(0) = []

insert 86 at 0 into list = 1
List(1) = [86]

erase item at 2 from list = 0
List(1) = [86]

insert 5 at 2 into list = 0
List(1) = [86]

erase item at 1 from list = 0
List(1) = [86]

reverse_list!
List(1) = [86]

insert 87 at 2 into list = 0
List(1) = [86]

insert 97 at 1 into list = 1
List(2) = [86->97]

erase item at 1 from list = 1
List(1) = [86]

insert 32 at -1 into list = 0
List(1) = [86]

insert 3 at -1 into list = 0
List(1) = [86]

insert 81 at 1 into list = 1
List(2) = [86->81]

insert 94 at 2 into list = 1
List(3) = [86->81->94]

insert 5 at 2 into list = 1
List(4) = [86->81->5->94]

insert 97 at 4 into list = 1
List(5) = [86->81->5->94->97]

insert 99 at 5 into list = 1
List(6) = [86->81->5->94->97->99]

insert 79 at 3 into list = 1
List(7) = [86->81->5->79->94->97->99]

insert 7 at 8 into list = 0
List(7) = [86->81->5->79->94->97->99]

reverse_list!
List(7) = [99->97->94->79->5->81->86]

insert 92 at 0 into list = 1
List(8) = [92->99->97->94->79->5->81->86]
*/

