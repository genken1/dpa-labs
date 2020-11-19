#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node *newNode(char ch, int freq, Node *left, Node *right) {
    Node *node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// функция кодирования
void encode(Node *root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// функция декодирования
void decode(Node *root, int &index, string str) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}


void buildHuffmanTree(string text) {
    // подсчитываем частоту встречающихся символов
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    // компаратор для приоритетной очереди
    struct comp {
        bool operator()(Node *l, Node *r) {
            // наиболее приоритетный с наименьшей частотой
            return l->freq > r->freq;
        }
    };

    // приоритетная очередь для сохранения узлов
    priority_queue<Node *, vector<Node *>, comp> pq;

    // инициализируем очередь узлами без связей
    for (auto pair: freq) {
        pq.push(newNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1) {
        // Удаляем два узла с наибольшей приоритетностью (наименьшей частотой)
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Создаём связь, у которой частота - это сумма значений приоритетных узлов
        int sum = left->freq + right->freq;
        pq.push(newNode('\0', sum, left, right));
    }

    // корневой узел дерева
    Node *root = pq.top();

    unordered_map<char, string> huffmanCode;
    // кодируем строку
    encode(root, "", huffmanCode);

    cout << "Кодировка символов :\n" << '\n';
    for (const auto& pair: huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nЗаданная строка :\n" << text << '\n';

    // формируем строку бинарного кода
    string str = "";
    for (char ch: text) {
        str += huffmanCode[ch];
    }

    cout << "\nБинараная строка:\n" << str << '\n';

    int index = -1;
    cout << "\nДекодированная строка: \n";
    while (index < (int) str.size() - 2) {
        decode(root, index, str);
    }
}

int main() {
    system("chcp 65001");
    system("cls");

    string text = "Chushkin Oleg Victorovech";

    buildHuffmanTree(text);

    return 0;
}