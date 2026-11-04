
#include<iostream>
using namespace std;

#define N 2

template<class T>
class Matrix
{
    T M[N][N];
public:
    Matrix()
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                M[i][j] = 0;
    }
    void init()
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>M[i][j];
    }
    Matrix<T> operator+(const Matrix<T>& B)
    {
        Matrix<T> temp;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                temp.M[i][j] = M[i][j] + B.M[i][j];
        return temp;
    }
    Matrix<T> operator*(const T& c)
    {
        Matrix<T> temp;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                temp.M[i][j] = M[i][j]*c;
        return temp;
    }
    friend ostream& operator<<(ostream& out,Matrix<T>& A)
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<" "<<A.M[i][j]<<" ";
            }
            cout<<endl;
        }

        return out;
    }
};

template<class T>
T maxElement(const T* A,int l)
{
    T temp = A[0];
    for(int i=0;i<l;i++)
        if(temp < A[i])
            temp = A[i];
    return temp;
}
template<>
string maxElement<string>(const string* A,int l)
{
    string temp = A[0];
    for(int i=0;i<l;i++)
        if(temp.length() < A[i].length())
            temp = A[i];
    return temp;
}

int main()
{
    Matrix<int> A,R1;
    cout<<"A matrix(int)\n";
    A.init();
    R1 = A * 2;
    cout<<"A*2:\n"<<R1;
    Matrix<double> B,C,R2;
    cout<<"B matrix(double)\n";
    B.init();
    cout<<"C matrix(double)\n";
    C.init();
    R2 = B+C;
    cout<<"B+C:\n"<<R2;

    int intArr[6] = {1,4,6,5,2,3};
    string strArr[6] = {"audi","bmw","lamborghini","ferrari","maserati","rollsroyce"};

    cout<<"Max int in int array:            "<<maxElement(intArr,6)<<endl;
    cout<<"longest string in string array:  "<<maxElement(strArr,6)<<endl;
    return 0;
}
