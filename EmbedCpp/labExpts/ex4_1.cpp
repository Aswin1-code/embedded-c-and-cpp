#include <iostream>
#include <string>
using namespace std;

const int N = 2;

// Class Template
template<class T>
class Matrix
{
    T M[N][N];

public:
    Matrix()
    {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                M[i][j] = T{};
    }

    void init()
    {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> M[i][j];
    }

    Matrix<T> operator+(const Matrix<T>& B) const
    {
        Matrix<T> temp;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                temp.M[i][j] = M[i][j] + B.M[i][j];
        return temp;
    }

    Matrix<T> operator*(const T& c) const
    {
        Matrix<T> temp;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                temp.M[i][j] = M[i][j] * c;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Matrix<T>& A)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                out << A.M[i][j] << " ";
            out << endl;
        }
        return out;
    }
};

// Function Template
template<class T>
T maxElement(const T* A, int n)
{
    T max = A[0];
    for(int i=1; i<n; i++)
        if(max < A[i])
            max = A[i];
    return max;
}

// Function Template Specialization
template<>
string maxElement<string>(const string* A, int n)
{
    string longest = A[0];
    for(int i=1; i<n; i++)
        if(longest.length() < A[i].length())
            longest = A[i];
    return longest;
}

int main()
{
    Matrix<int> A, R1;
    cout << "Enter integer matrix:\n";
    A.init();

    R1 = A * 2;
    cout << "A * 2:\n" << R1;

    Matrix<double> B, C, R2;
    cout << "Enter first double matrix:\n";
    B.init();
    cout << "Enter second double matrix:\n";
    C.init();

    R2 = B + C;
    cout << "B + C:\n" << R2;

    int intArr[] = {1, 4, 6, 5, 2, 3};
    string strArr[] = {"audi", "bmw", "lamborghini",
                       "ferrari", "maserati", "rollsroyce"};

    cout << "Maximum integer: " << maxElement(intArr, 6) << endl;
    cout << "Longest string: " << maxElement(strArr, 6) << endl;

    return 0;
}