#include <iostream>

using namespace std;

class Matrix{
    int** values;
    int row, column;
    public:
    Matrix(int _row, int _column)
    : row(_row), column(_column) {
        values = new int* [_column];
        for(int i = 0; i < _column; i++) {
            values[i] = new int[_row];
        }
    }
    Matrix(const Matrix& m)
    : row(m.row), column(m.column) {
        values = new int*[column];
        for(int i = 0; i < column; i++) {
            values[i] = new int[row];
            for (int j = 0; j < row; j++) {
                values[i][j] = m.values[i][j];
            }
        }
    }
    
    ~Matrix(){
        for(int i = 0; i < column; i++) {
            delete[] values[i];
        }
        delete[] values;
    }

    Matrix operator+ (const Matrix& m) const{
        Matrix m_buf(m.row, m.column);
        for(int i = 0; i < m.column; i++){
            for(int j =0; j < m.row; j++) 
                m_buf.values[i][j] = values[i][j] + m.values[i][j];
        }
        return m_buf;
    }
    Matrix operator* (const int& times) const{
        Matrix m_buf(row, column);
        for(int i = 0; i < column; i++){
            for(int j =0; j < row; j++) 
                m_buf.values[i][j] = values[i][j] * times;
        }
        return m_buf;
    }
    Matrix& operator=(const Matrix& m) {
        row = m.row;
        column = m.column;
        values = new int*[column];
        for (int i = 0; i < column; i++) {
            values[i] = new int[row];
            for (int j = 0; j < row; j++) {
                values[i][j] = m.values[i][j];
            }
        }
    
        return *this;
    }
    


    friend ostream& operator << (ostream& os, const Matrix& m);
    friend istream& operator >> (istream& is, Matrix& m);

};
ostream& operator << (ostream& os, const Matrix& m){
    for(int i = 0; i<m.column; i++){
        for(int j = 0; j<m.row; j++){
            os << m.values[i][j] << '\t';
        }
        os << '\n';
    }
    return os;
}

istream& operator >> (istream& is, Matrix& m){
    for(int i = 0; i<m.column; i++){
        for(int j = 0; j<m.row; j++) is >> m.values[i][j];
    }
    return is;
}


int main(){
    Matrix m1(2,2), m2(2,2);
    cin >> m1;
    cin >> m2;

    Matrix m3(m1 + m2);
    Matrix m4(2,2);

    m4 = m3 * 10;

    cout << m3 << endl << m4 << endl;
}