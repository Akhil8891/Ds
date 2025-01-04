#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void main() {
    struct node *root = (struct node *)0; // null list
    struct node *insert(struct node*, int);
    void display(struct node*);
    struct node *search(struct node*, int);
    struct node *delete(struct node*, int);
    int opt, data;

    do {
        printf("\n 1.insert \n 2.search \n 3.delete \n 4.display \n 5.exit \n Your option:");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                printf("Data:");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Data:");
                scanf("%d", &data);
                if(search(root, data)) 
                    printf("Found the item\n");
                else
                    printf("Not found data\n");
                break;

            case 3:
                if(root == (struct node*)0) {
                    printf("Tree is empty\n");
                } else {
                    printf("Data:");
                    scanf("%d", &data);
                    root = delete(root, data);
                }
                break;

            case 4:
                display(root);
                break;

            case 5:
                exit(0);
        }
    } while(1);
}

// Display BST contents inorder
void display(struct node *bst) {
    if(bst != (struct node *)0) {
        display(bst->left);
        printf("%d\t", bst->data);
        display(bst->right);
    }
}

// To insert data in BST
struct node *insert(struct node *bst, int data) {
    struct node *t, *t1 = bst, *t2 = 0;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = t->right = (struct node *)0;

    if(bst == (struct node *)0) // Case of null BST
        bst = t;
    else { // Find insert position
        while(t1 != 0 && data != t1->data) {
            t2 = t1;
            if(data < t1->data)
                t1 = t1->left;
            else
                t1 = t1->right;
        }
        if(t1 == 0) { 
            if(data < t2->data)
                t2->left = t;
            else
                t2->right = t;
        } else {
            printf("Duplicate\n");
            free(t); // Free memory if duplicate
        }
    }
    return bst;
}

// Search for an item in BST
struct node *search(struct node *bst, int data) {
    while(bst != (struct node *)0 && bst->data != data) {
        if(data < bst->data)
            bst = bst->left;
        else
            bst = bst->right;
    }
    return bst;
}

// Delete a node item from BST


// Delete node item from BST
struct node *delete(struct node *bst, int data) {
    struct node *t1 = bst, *t2, *sucpar;

    // Find the node to be deleted
    while(t1 != 0 && t1->data != data) {
        t2 = t1;
        if(data < t1->data)
            t1 = t1->left;
        else
            t1 = t1->right;
    }

    if(t1 != (struct node *)0) { // Node found
        // Case 1: Node to be deleted is the root
        if(bst == t1 && bst->left == 0) {     // root is to be removed
            bst = bst->right;
            free(t1);  // Free the root node
        } else if(bst == t1 && bst->right == 0) {
            bst = bst->left;  // root node with only left child
            free(t1);  // Free the root node
        } 
        // Case 2: Node to be deleted has no children (leaf node)
        else if(t1->left == 0 && t1->right == 0) {
            if(t2->left == t1)
                t2->left = 0;
            else
                t2->right = 0;
            free(t1);  // Free the node memory
        } 
        // Case 3: Node to be deleted has one child
        else if(t1->left == 0 || t1->right == 0) {
            struct node *child = (t1->left != 0) ? t1->left : t1->right;
            if(t2->left == t1)
                t2->left = child;
            else
                t2->right = child;
            free(t1);  // Free the node memory
        } 
        // Case 4: Node to be deleted has two children 2.search 

        else {
            sucpar = t1;
            t2 = t1->right;
            while(t2->left != 0) {
                sucpar = t2;
                t2 = t2->left;
            }
            t1->data = t2->data;  // Copy inorder successor data to t1
            // Remove inorder successor
            if(sucpar->left == t2)
                sucpar->left = t2->right;
            else
                sucpar->right = t2->right;
            free(t2);  // Free the inorder successor node memory
        }
    }
    return bst;  // Return the modified tree
}

