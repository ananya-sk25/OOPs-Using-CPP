#include <iostream>
using namespace std;
class Matrix{
private:
    int data[2][2];
public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
    data[0][0] = a;
    data[0][1] = b;
    data[1][0] = c;
    data[1][1] = d;
    }
    void input(){
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> data[i][j];
    }
    Matrix operator+(const Matrix &m){
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }
    Matrix operator-(const Matrix &m){
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] - m.data[i][j];
        return result;
    }
    Matrix operator*(const Matrix &m){
        Matrix result;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
        return result;
    }
    int* operator[](int index){
        return data[index];
    }
    friend ostream& operator<<(ostream &out, const Matrix &m){
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";
                out << endl;
        }
        return out;
    }
};
int main(){
    Matrix A, B;
    cout << "Enter 4 elements of Matrix A:" << endl;
    A.input();
    cout << "Enter 4 elements of Matrix B:" << endl;
    B.input();
    Matrix sum = A + B;
    Matrix difference = A - B;
    Matrix product = A * B;
    cout << "\nMatrix A:\n" << A;
    cout << "Matrix B:\n" << B;
    cout << "Addition:\n" << sum;
    cout << "Subtraction:\n" << difference;
    cout << "Multiplication:\n" << product;
    cout << "First element of A: " << A[0][0] << endl;
    return 0;
}
