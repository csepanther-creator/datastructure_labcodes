

#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int i, j, value;
};

class SparseMatrix {
public:
    int rows, cols;
    vector<Element> elements;
    
    SparseMatrix(int r, int c) : rows(r), cols(c) {}
    
    void transpose() {
        for (auto &elem : elements) {
            swap(elem.i, elem.j);
        }
        swap(rows, cols);
    }
};

int main() {
    
    SparseMatrix mat(3, 3);
    mat.elements = {{1, 2, 5}, {2, 3, 8}, {3, 1, 7}, {3, 3, 9}};
    cout << "Original elements (i, j, value):" << endl;
    for (auto &e : mat.elements) {
        cout << "(" << e.i << "," << e.j << "," << e.value << ")" << endl;
    }
    mat.transpose();
    cout << "\nTransposed elements (i, j, value):" << endl;
    for (auto &e : mat.elements) {
        cout << "(" << e.i << "," << e.j << "," << e.value << ")" << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int i, j, value;
};

class SparseMatrix {
public:
    int rows, cols;
    vector<Element> elements;

    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    SparseMatrix add(const SparseMatrix &other) {
        SparseMatrix result(rows, cols);
        int i = 0, j = 0;
        while (i < elements.size() && j < other.elements.size()) {
            if (elements[i].i < other.elements[j].i ||
               (elements[i].i == other.elements[j].i && elements[i].j < other.elements[j].j)) {
                result.elements.push_back(elements[i++]);
            } else if (elements[i].i > other.elements[j].i ||
                      (elements[i].i == other.elements[j].i && elements[i].j > other.elements[j].j)) {
                result.elements.push_back(other.elements[j++]);
            } else {
               
                Element e;
                e.i = elements[i].i;
                e.j = elements[i].j;
                e.value = elements[i].value + other.elements[j].value;
                result.elements.push_back(e);
                i++; j++;
            }
        }
        while (i < elements.size()) result.elements.push_back(elements[i++]);
        while (j < other.elements.size()) result.elements.push_back(other.elements[j++]);
        return result;
    }
};

int main() {
    SparseMatrix A(3, 3), B(3, 3);
    A.elements = {{1, 1, 5}, {2, 3, 8}};
    B.elements = {{1, 1, 7}, {3, 2, 6}};
    SparseMatrix C = A.add(B);
    cout << "Sum of matrices (i, j, value):" << endl;
    for (auto &e : C.elements) {
        cout << "(" << e.i << "," << e.j << "," << e.value << ")" << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Element {
    int i, j, value;
};

class SparseMatrix {
public:
    int rows, cols;
    vector<Element> elements;

    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    SparseMatrix multiply(const SparseMatrix &other) {
        SparseMatrix result(rows, other.cols);
        map<pair<int,int>, int> mp;
        for (auto &e1 : elements) {
            for (auto &e2 : other.elements) {
                if (e1.j == e2.i) {
                    mp[{e1.i, e2.j}] += e1.value * e2.value;
                }
            }
        }
        for (auto &entry : mp) {
            Element e;
            e.i = entry.first.first;
            e.j = entry.first.second;
            e.value = entry.second;
            if (e.value != 0)
                result.elements.push_back(e);
        }
        return result;
    }
};

int main() {
    SparseMatrix A(2, 3), B(3, 2);
    A.elements = {{1, 2, 4}, {2, 3, 5}};
    B.elements = {{1, 1, 7}, {2, 1, 6}};
    SparseMatrix C = A.multiply(B);
    cout << "Product of matrices (i, j, value):" << endl;
    for (auto &e : C.elements) {
        cout << "(" << e.i << "," << e.j << "," << e.value << ")" << endl;
    }
    return 0;
}

