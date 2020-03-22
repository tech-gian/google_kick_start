#include <stdio.h>
#include <stdlib.h>

typedef struct list_node* ListNode;

struct list_node {
    int x;
    ListNode next;    
};

void list_insert_end(ListNode* node, int value) {
    while (*node!=NULL) {
        node = &((*node)->next);
    }
    *node = malloc(sizeof(struct list_node));
    (*node)->x = value;
    (*node)->next = NULL;
}


int main(void) {

    int T;
    scanf("%d", &T);

    int** n_array = malloc(2*sizeof(int*));
    n_array[0] = malloc(T*sizeof(int));
    n_array[1] = malloc(T*sizeof(int));

    ListNode** basic = malloc(T*sizeof(ListNode*));
    for (int i=0 ; i<T ; i++) {
        scanf("%d", &(n_array[0][i]));
        basic[i] = malloc(n_array[0][i]*(sizeof(ListNode)));

        int K;
        scanf("%d", &K);
        scanf("%d", &(n_array[1][i]));
    
        for (int j=0 ; j<n_array[0][i] ; j++) {
            basic[i][j] = NULL;

            for (int k=0 ; k<K ; k++) {
                int value;
                scanf("%d", &value);
                list_insert_end(&basic[i][j], value);
            }
        }
    
    }

    for (int i=0 ; i<T ; i++) {
        int sum = 0;

        for (int j=0 ; j<n_array[1][i] ; j++) {
            int max = 0;
            int pos;

            for (int k=0 ; k<n_array[0][i] ; k++) {
                if (basic[i][k]!=NULL) {
                    if (basic[i][k]->x==max) {
                        int temp_max = 0;
                        for (int m=0 ; m<n_array[0][i] ; m++) {
                            ListNode temp_basic = basic[i][m];
                            int counter = n_array[1][i] - j;
                            int temp_sum = 0;
                            while (temp_basic->next!=NULL && counter!=0) {
                                temp_sum += temp_basic->x;
                                counter--;
                                temp_basic = temp_basic->next;
                            }
                            if (temp_sum>temp_max) {
                                temp_max = temp_sum;
                                pos = m;
                            }
                        }
                        max = basic[i][pos]->x;
                    }
                    if (basic[i][k]->x>max) {
                        max = basic[i][k]->x;
                        pos = k;
                    }
                }
            }

            sum += max;
            basic[i][pos] = basic[i][pos]->next;
        }

        printf("Case #%d: %d\n", i+1, sum);
    }
}