#include <stdio.h>
#include <stdlib.h>

#define iType char
#define MALLOC(p,s) \
    if(!((p)=malloc(s))){ \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

typedef struct {
    int key;
    iType item;
}element;

typedef struct node* treePointer;
struct node {
    element data;
    treePointer leftChild, rightChild;
};



int main() {




	return 0;
}

treePointer create(){
    treePointer tree = NULL;
    return tree;
}

element* iterSearch(treePointer tree, int k) {
    while (tree) {
        if (k == tree->data.key)
            return &(tree->data);
        if (k < tree->data.key)
            tree = tree->leftChild;
        else
            tree = tree->rightChild;
    }
    return NULL;
}

element* search(treePointer root, int k) {
    if (!root)
        return NULL;
    if (k == root->data.key)
        return &(root->data);
    if (k < root->data.key)
        return search(root->leftChild, k);

    return search(root->rightChild, k);
}

treePointer modifiedSearch(treePointer tree, int k) {
    treePointer lastNode = NULL;
    if ((!tree) || search(tree, k))
        return NULL;
    while (tree) {
        lastNode = tree;
        if (k < tree->data.key)
            tree = tree->leftChild;
        else
            tree = tree->rightChild;
    }
    return lastNode;
}

void insert(treePointer* node, int k, iType Item) {
    treePointer ptr;
    treePointer temp = modifiedSearch(*node, k);
    if (temp || !(*node)) {
        MALLOC(ptr, sizeof(*ptr));
        ptr->data.key = k;
        ptr->data.item = Item;
        ptr->leftChild = ptr->rightChild = NULL;
        if (*node) {
            if (k < temp->data.key)
                temp->leftChild = ptr;
            else
                temp->rightChild = ptr;
        }
        else
            *node = ptr;
    }
}

treePointer delete(treePointer node, int k) {
    treePointer root = node;
    treePointer parent = node;
    treePointer temp = modifiedSearch(node, k);
    int keep = 1;
    if (!temp) {
        printf("There is no %d in this tree.\n", k);
        return root;
    }

    else if (!(temp->leftChild) && !(temp->rightChild)) {
        while (keep) {

            if (k < parent->data.key) {
                if (k == (parent->leftChild)->data.key) {
                    parent->leftChild = NULL;
                    keep = 0;
                }
                else
                    parent = parent->leftChild;
            }

            else if (k > parent->data.key) {
                if (k == (parent->rightChild)->data.key) {
                    parent->rightChild = NULL;
                    keep = 0;
                }
                else
                    parent = parent->rightChild;
            }
        }
        free(temp);
        return root;
    }

    else if (!(temp->leftChild) || !(temp->rightChild) && (temp->leftChild!=temp->rightChild)) {
        if (k == parent->data.key) {//delete node is root.
            if (!(temp->leftChild))
                root = temp->rightChild;
            else
                root = temp->leftChild;
            free(temp);
            return root;
        }

        while (keep) {
            if (k < parent->data.key) {
                if (k == (parent->leftChild)->data.key) {
                    keep = 0;
                    if (!(temp->leftChild))
                        parent->leftChild = temp->rightChild;
                    else
                        parent->leftChild = temp->leftChild;
                }
                else
                    parent = parent->leftChild;
            }
            else if (k >= parent->data.key) {
                if (k == (parent->rightChild)->data.key) {
                    keep = 0;
                    if (!(temp->leftChild))
                        parent->rightChild = temp->rightChild;
                    else
                        parent->rightChild = temp->leftChild;
                }
                else
                    parent = parent->rightChild;
            }

        }
        free(temp);
        return root;
    }

    else {//two kids
        treePointer leftL,rightS,parent2=node;
        leftL = findLargest(temp);
        int i = 0; int j = 0;
        //keep = 1;
        while (keep) {
            i++;
            if (leftL->data.key < parent->data.key) {
                if (leftL->data.key == (parent->leftChild)->data.key)
                    keep = 0;
                else
                    parent = parent->leftChild;
            }
            else if (leftL->data.key > parent->data.key) {
                if (leftL->data.key == (parent->rightChild)->data.key)
                    keep = 0;
                else
                    parent = parent->rightChild;
            }
        }
        keep = 1;
        rightS = findSmallest(temp);
        while (keep) {
            j++;
            if (rightS->data.key < parent2->data.key) {
                if (rightS->data.key == (parent2->leftChild)->data.key)
                    keep = 0;
                else
                    parent2 = parent2->leftChild;
            }
            else if (rightS->data.key > parent2->data.key) {
                if (rightS->data.key == (parent2->rightChild)->data.key)
                    keep = 0;
                else
                    parent2 = parent2->rightChild;
            }
        }


        if (temp == root) {//parent is root.
            if (i <= j) {
                leftL->leftChild = temp->leftChild;
                leftL->rightChild = temp->rightChild;
                if (leftL->data.key == (parent->rightChild)->data.key) {
                    parent->rightChild = NULL;
                }
                else
                    parent->
            }
            else


            free(temp);
            return leftL;
        }

        while (keep) {

            if (leftL->data.key < parent->data.key) {
                if (leftL->data.key == (parent->leftChild)->data.key) {
                    keep = 0;
                    parent->leftChild = NULL;
                }
                else
                    parent = parent->leftChild;
            }
            else if (leftL->data.key > parent->data.key) {
                if (leftL->data.key == (parent->rightChild)->data.key) {
                    keep = 0;
                    parent->rightChild = NULL;
                }
                else
                    parent = parent->rightChild;
            }
            


        }

    }




}

treePointer findSmallest(treePointer node) {
    treePointer small = node;
    do
    {
        small = small->leftChild;
        if (small == NULL)
            return NULL;
    } while (small->leftChild==NULL);
    return small;
}

treePointer findLargest(treePointer node) {
    treePointer large = node;
    do
    {
        large = large->rightChild;
        if (large == NULL)
            return NULL;
    } while (large->rightChild == NULL);
    return large;
}
