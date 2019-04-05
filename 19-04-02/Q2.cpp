class Solution {
public:
    Node* connect(Node* root) {
        Node* result = root;
        Node* start = root;
        while (start != NULL && start->left != NULL){
            root = start;
            while (root != NULL){
                root->left->next = root->right;
                if (root->next != NULL){
                    root->right->next = root->next->left;
                }
                root = root->next;
            }
            start = start->left;
        }
        return result;
    }
};
