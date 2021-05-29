// Лабораторная работа 20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*#include <iostream>
#include "BinaryTree.h"
//#include "char_pointer_tree.h"
//#include "char_tree.cpp"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите количество элементов в бинарном дереве:" << endl;
    do {
        cout << ">";
        cin >> array_numbers_size;
        if (array_numbers_size < 1)
            cout << "Введите положительное число" << endl;
    } while (array_numbers_size < 1);
    array_numbers = new double[array_numbers_size];
    BinaryTree tree;
    cout << "Введите вещественные числа:\n";
    tree.create_balanced_binary_tree(array_numbers_size);
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t\t\tВЫВОД БИНАРНОГО ДЕРЕВА";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tГлубина дерева: " << tree.depth_tree();
    tree.print_tree();
    cout << "\n\n\n\n";
    system("pause");
    system("cls");
    BinaryTree search_tree;
    for (int i = 0; i < array_numbers_size; i++)
        search_tree.insert_in_search_tree(array_numbers[i]);
    isBalancedSortPrinting = false;
    cout << "\t\t\t\t\t\t\t\t\t\t\tВЫВОД БИНАРНОГО ДЕРЕВА ПОИСКА";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tГлубина дерева: " << search_tree.depth_tree();
    search_tree.print_tree();
    cout << "\n\n\n\n";
    system("pause");
    cout << endl;
    cout << "Максимальное значение элемента в дереве: " << search_tree.find_max() << endl;
    system("pause");
    system("cls");
    search_tree.print_tree();

    system("pause");
    return 0;
}*/
#include <iostream>
#include <Windows.h>
using namespace std;
COORD position;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

double* array_numbers;
int TreeSize;
int index = 1;
bool isBalancedSortPrinting = true;
const int start_x_position = 100;

//работа с деревом символов
struct CharNode {
    char data;
    CharNode* left, * right;
};
class BinaryTree {
private:
    CharNode* root;
    void delete_tree(CharNode* leaf) {
        if (leaf != NULL) {
            delete_tree(leaf->left);
            delete_tree(leaf->right);
            delete leaf;
        }
    }
    void create_balanced_binary_tree(CharNode*& leaf, int size) {
        if (size == 0) {
            leaf = NULL;
            return;
        }
        cout << ++index << ") ";
        char symbol;
        cin >> symbol;
        leaf = new CharNode;
        leaf->data = symbol;
        int left_subtree_size, right_subtree_size;
        get_subtrees_sizes(size, left_subtree_size, right_subtree_size);
        create_balanced_binary_tree(leaf->left, left_subtree_size);
        create_balanced_binary_tree(leaf->right, right_subtree_size);
    }
    int depth_tree(CharNode* leaf) {
        if (leaf == NULL)
            return 0;
        return max(depth_tree(leaf->right), depth_tree(leaf->left)) + 1;
    }
    void print_branch(CharNode* leaf, int x, int y) {
        if (leaf == NULL)
            return;
        position.X = x;
        position.Y = y;
        SetConsoleCursorPosition(hConsole, position);
        cout << leaf->data;
        int formula_new_x_left_leaf, formula_new_x_right_leaf;
        if (isBalancedSortPrinting) {
            formula_new_x_left_leaf = x - 2 * (y + 2);
            formula_new_x_right_leaf = x + 2 * (y + 2);
        }
        else {
            formula_new_x_left_leaf = x - 2 * (y + 1);
            formula_new_x_right_leaf = x + 2 * y;
        }
        print_branch(leaf->left, formula_new_x_left_leaf, y + 2);
        print_branch(leaf->right, formula_new_x_right_leaf, y + 2);
    }
    void print_tree(CharNode*& leaf) {
        if (leaf == NULL)
            return;
        CharNode* branch_left = NULL;
        CharNode* branch_right = NULL;
        branch_left = leaf->left;
        branch_right = leaf->right;
        position.X = start_x_position;
        position.Y = 3;
        SetConsoleCursorPosition(hConsole, position);
        cout << leaf->data;
        int depthOfTheTree = depth_tree(leaf);
        int offset_coefficient;
        if (isBalancedSortPrinting)
            offset_coefficient = 6;
        else
            offset_coefficient = 4;
        print_branch(branch_left, start_x_position - offset_coefficient * depthOfTheTree, 5);
        print_branch(branch_right, start_x_position + offset_coefficient * depthOfTheTree, 5);
    }
    int counting_k;
    void FindElem(CharNode* leaf, char k) {
        if (leaf == NULL)
            return;
        FindElem(leaf->left, k);
        FindElem(leaf->right, k);
        if (leaf->data == k)
            counting_k++;
    }
    void get_subtrees_sizes(const int size, int& left_size, int& right_size) {
        if ((size - 1) % 2 == 0) {
            left_size = (size - 1) / 2;
            right_size = left_size;
        }
        else {
            left_size = size / 2;
            right_size = (size - 1) / 2;
        }
    }
public:
    int FindElem(char key) {
        FindElem(root, key);
        return counting_k;
    }
    BinaryTree() {
        root = NULL;
        counting_k = 0;
    }
    ~BinaryTree() {
        delete_tree(root);
    }
    void create_balanced_binary_tree(int size) {
        char symbol;
        cout << "1) ";
        cin >> symbol;
        root = new CharNode;
        root->data = symbol;
        if ((size - 1) >= 0) {
            int left_subtree_size, right_subtree_size;
            get_subtrees_sizes(size, left_subtree_size, right_subtree_size);
            create_balanced_binary_tree(root->left, left_subtree_size);
            create_balanced_binary_tree(root->right, right_subtree_size);
        }
    }

    int depth_tree() {
        return depth_tree(root);
    }

    void print_tree() {
        print_tree(root);
    }
};
int main() {
    setlocale(LC_ALL, "");
    cout << "Введите количество элементов в бинарном дереве: "; cin >> TreeSize;
    while (TreeSize < 1) {
        cout << "Введите положительное число" << endl;
        cin >> TreeSize;
    }
    BinaryTree chrTree;
    chrTree.create_balanced_binary_tree(TreeSize);
    system("cls");
    chrTree.print_tree();
    cout << "\n\n\n\n";
    system("pause");
    cout << "Введите символ, который необходимо найти: ";
    char searched_symbol;
    cin >> searched_symbol;
    cout << "Искомый символ встречается в дереве " << chrTree.FindElem(searched_symbol) << " раз" << endl;
    system("pause");
    return 0;
}