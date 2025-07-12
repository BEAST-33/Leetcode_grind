class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1)
        {
            Node* curr = q.front();
            q.pop();
            if (!curr)
            {
                q.push(NULL);
                continue;
            }
            curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return root;
    }
};


class Solution {
public:
    // Based on level order traversal with O(1) extra space
    Node* connect(Node* root) {

        Node* head = NULL; // head of the next level
        Node* prev = NULL; // the leading node on the next level
        Node* cur = root;  // current node of current level

        // Outer loop: iterates through levels
        while (cur != NULL) {

            // Inner loop: iterates on the current level
            // and builds the 'next' connections for the level below
            while (cur != NULL) {
                // Process left child
                if (cur->left != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                // Process right child
                if (cur->right != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }
                // Move to the next node in the current level using its 'next' pointer
                cur = cur->next;
            }

            // Move to the next level
            cur = head;   // 'cur' now points to the first node of the next level
            head = NULL;  // Reset 'head' for the level after the next
            prev = NULL;  // Reset 'prev' for the level after the next
        }

        return root; // Return the original root
    }
};