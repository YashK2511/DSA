#include<iostream>
#include<stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

class ExpressionTree {
    Node* root;

public:
    ExpressionTree() {
        root = NULL;
    }

    void createFromPrefix(string expr) {
        stack<Node*> st;
        for (int i = expr.length() - 1; i >= 0; i--) {
            char ch = expr[i];
            Node* newNode = new Node(ch);

            if (isOperator(ch)) {
                newNode->left = st.top(); st.pop();
                newNode->right = st.top(); st.pop();
            }
            st.push(newNode);
        }
        root = st.top();
    }

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    void postorderNonRecursive() {
        if (root == NULL) return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* temp = s1.top(); s1.pop();
            s2.push(temp);

            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }

        cout << "Postorder Traversal: ";
        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
        cout << endl;
    }

    void displayPrefix(string expr) {
        cout << "Prefix Expression: " << expr << endl;
    }

    void deleteAll(Node* node) {
        if (node == NULL) return;
        deleteAll(node->left);
        deleteAll(node->right);
        delete node;
    }

    void cleanUp() {
        deleteAll(root);
    }
};

int main() {
    ExpressionTree et;
    string expr;
    cout << "Enter prefix expression (e.g., *+ab-cd): ";
    cin >> expr;

    et.createFromPrefix(expr);
    et.displayPrefix(expr);
    et.postorderNonRecursive();
    et.cleanUp();

    return 0;
}

