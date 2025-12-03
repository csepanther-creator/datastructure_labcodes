

#include <iostream>
using namespace std;

class DiagonalMatrix {
private:
    int *A;
    int n;
public:
    DiagonalMatrix(int size) : n(size) {
        A = new int[n];
    }
    ~DiagonalMatrix() {
        delete[] A;
    }
    void set(int i, int j, int value) {
        if (i == j)
            A[i - 1] = value;
    }
    int get(int i, int j) {
        if (i == j)
            return A[i - 1];
        else
            return 0;
    }
};

int main() {
    int n = 4;
    DiagonalMatrix mat(n);
    mat.set(1, 1, 5);
    mat.set(2, 2, 8);
    mat.set(3, 3, 3);
    mat.set(4, 4, 6);
    cout << "Element at (3,3): " << mat.get(3, 3) << endl;
    cout << "Element at (2,3): " << mat.get(2, 3) << endl;
    return 0;
}


#include <iostream>
using namespace std;

class TriDiagonalMatrix {
private:
    int *A;
    int n;
public:
    TriDiagonalMatrix(int size) : n(size) {
        A = new int[3*n - 2];
    }
    ~TriDiagonalMatrix() {
        delete[] A;
    }
    void set(int i, int j, int value) {
        if (i - j == 0)     
            A[n - 1 + (i - 1)] = value;
        else if (i - j == 1)  
            A[i - 2] = value;
        else if (j - i == 1)  
            A[(2*n - 1) + (i - 1)] = value;
    }
    int get(int i, int j) {
        if (i - j == 0)
            return A[n - 1 + (i - 1)];
        else if (i - j == 1)
            return A[i - 2];
        else if (j - i == 1)
            return A[(2*n - 1) + (i - 1)];
        else
            return 0;
    }
};

int main() {
    int n = 4;
    TriDiagonalMatrix mat(n);
 
    mat.set(1, 1, 4);
    mat.set(1, 2, 2);
    mat.set(2, 1, 3);
    mat.set(2, 2, 5);
    mat.set(2, 3, 7);
    mat.set(3, 2, 6);
    mat.set(3, 3, 9);
    mat.set(3, 4, 8);
    mat.set(4, 3, 1);
    mat.set(4, 4, 6);
    cout << "Element at (3,2): " << mat.get(3, 2) << endl;
    cout << "Element at (1,3): " << mat.get(1, 3) << endl;
    return 0;
}


#include <iostream>
using namespace std;

class LowerTriangular {
private:
    int *A;
    int n;
public:
    LowerTriangular(int size) : n(size) {
        A = new int[n*(n+1)/2];
    }
    ~LowerTriangular() {
        delete[] A;
    }
    void set(int i, int j, int value) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j - 1);
            A[index] = value;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j - 1);
            return A[index];
        } else
            return 0;
    }
};

int main() {
    int n = 4;
    LowerTriangular mat(n);
    mat.set(1, 1, 5);
    mat.set(2, 1, 8);
    mat.set(2, 2, 3);
    mat.set(3, 1, 6);
    mat.set(3, 2, 4);
    mat.set(3, 3, 1);
    mat.set(4, 1, 7);
    mat.set(4, 2, 2);
    mat.set(4, 3, 9);
    mat.set(4, 4, 10);
    cout << "Element at (4,2): " << mat.get(4, 2) << endl;
    cout << "Element at (2,4): " << mat.get(2, 4) << endl;
    return 0;
}

using namespace std;

class UpperTriangular {
private:
    int *A;
    int n;
public:
    UpperTriangular(int size) : n(size) {
        A = new int[n*(n+1)/2];
    }
    ~UpperTriangular() {
        delete[] A;
    }
    void set(int i, int j, int value) {
        if (i <= j) {
            int index = (i - 1) * n - ((i - 1) * (i - 2)) / 2 + (j - i);
            A[index] = value;
        }
    }
    int get(int i, int j) {
        if (i <= j) {
            int index = (i - 1) * n - ((i - 1) * (i - 2)) / 2 + (j - i);
            return A[index];
        } else
            return 0;
    }symmetric matrix
};

int main() {
    int n = 4;
    UpperTriangular mat(n);
    mat.set(1, 1, 2);
    mat.set(1, 2, 3);
    mat.set(1, 3, 5);
    mat.set(1, 4, 7);
    mat.set(2, 2, 1);
    mat.set(2, 3, 4);
    mat.set(2, 4, 6);
    mat.set(3, 3, 8);
    mat.set(3, 4, 9);
    mat.set(4, 4, 10);
    cout << "Element at (2,3): " << mat.get(2, 3) << endl;
    cout << "Element at (3,1): " << mat.get(3, 1) << endl;
    return 0;
}


#include <iostream>
using namespace std;

class SymmetricMatrix {
private:
    int *A;
    int n;
public:
    SymmetricMatrix(int size) : n(size) {
        A = new int[n*(n+1)/2];
    }
    ~SymmetricMatrix() {
        delete[] A;
    }
    void set(int i, int j, int value) {
        if (i >= j) {
            int index = (i*(i - 1)) / 2 + (j - 1);
            A[index] = value;
        } else {
            int index = (j*(j - 1)) / 2 + (i - 1);
            A[index] = value;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int index = (i*(i - 1)) / 2 + (j - 1);
            return A[index];
        } else {
            int index = (j*(j - 1)) / 2 + (i - 1);
            return A[index];
        }
    }
};

int main() {
    int n = 4;
    SymmetricMatrix mat(n);

    mat.set(1, 1, 5);
    mat.set(2, 1, 8);
    mat.set(2, 2, 3);
    mat.set(3, 1, 6);
    mat.set(3, 2, 4);
    mat.set(3, 3, 1);
    mat.set(4, 1, 7);
    mat.set(4, 2, 2);
    mat.set(4, 3, 9);
    mat.set(4, 4, 10);
    cout << "Element at (3,2): " << mat.get(3, 2) << endl;
    cout << "Element at (2,3): " << mat.get(2, 3) << endl;
    return 0;
}

