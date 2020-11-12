#include <cstdio>
#include <cstdlib>
#include <ctime>

class Matrix {
public:
    Matrix(int row, int col) : _row(row), _col(col) {
        srand((unsigned)time(NULL));

        _map = new int*[_row];
        for (size_t i = 0; i < _row; i++) {
            _map[i] = new int[_col];
        }
    }

    ~Matrix() {
        for (size_t i = 0; i < _row; i++) {
            delete[] _map[i];
        }
        delete[] _map;
    }

    void set_rand() {
        for (size_t i = 0; i < _row; i++) {
            for (size_t j = 0; j < _col; j++) {
                _map[i][j] = rand() % 9 + 1;
            }
        }
    }

    void print() const {
        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _col; j++) {
                printf("%d%c", _map[i][j], j < _col - 1 ? ' ' : '\n');
            }
        }
    }

private:
    int _row;
    int _col;
    int** _map;
};

int main() {
    Matrix u(3, 5);
    u.set_rand();
    u.print();
}
