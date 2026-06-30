#include "BinarySearchTree.h"

void print_search_result(int searchTarget, TreeNode* result) {
    if(result != NULL)
        printf("found: %d\n", result->data);
    else    
        printf("Not found: %d\n", searchTarget);
}

int main(void) {
    TreeNode* tree = create_node(123);
    TreeNode* node = NULL;

    
    insert_node(tree, create_node(22));
    insert_node(tree, create_node(9918));
    insert_node(tree, create_node(424));
    insert_node(tree, create_node(17));
    insert_node(tree, create_node(3));
    insert_node(tree, create_node(98));
    insert_node(tree, create_node(34));
    insert_node(tree, create_node(760));
    insert_node(tree, create_node(310));
    insert_node(tree, create_node(4));
    insert_node(tree, create_node(221));
    insert_node(tree, create_node(777));
    insert_node(tree, create_node(2567));
    insert_node(tree, create_node(1111));
    insert_node(tree, create_node(6));

    int searchTarget = 98;
    node = search_node(tree, searchTarget);
    print_search_result(searchTarget, node);

    searchTarget = 117;
    node = search_node(tree, searchTarget);
    print_search_result(searchTarget, node);

    inorder_print(tree);
    printf("\n");

    node = remove_node(tree, NULL, 98);
    destroy_node(node);
    inorder_print(tree);
    printf("\n");

    destroy_tree(tree);
    return 0;
}