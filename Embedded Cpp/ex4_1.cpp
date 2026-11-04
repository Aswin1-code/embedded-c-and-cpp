#include <iostream>
#include <string>
#include <complex>
using namespace std;

// Class Template
template <class T>
class Matrix
{
    T a[2][2];

public:

    Matrix(T x = T(), T y = T(),
           T z = T(), T w = T())
    {
        a[0][0] = x;
        a[0][1] = y;
        a[1][0] = z;
        a[1][1] = w;
    }

    // Display matrix
    void display()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
                cout << a[i][j] << " ";

            cout << endl;
        }
    }

    // Addition of matrices
    Matrix add(Matrix b)
    {
        return Matrix(
            a[0][0] + b.a[0][0],
            a[0][1] + b.a[0][1],
            a[1][0] + b.a[1][0],
            a[1][1] + b.a[1][1]
        );
    }

    // Scalar multiplication
    Matrix multiplyScalar(T s)
    {
        return Matrix(
            a[0][0] * s,
            a[0][1] * s,
            a[1][0] * s,
            a[1][1] * s
        );
    }
};

// Function Template
template <class T>
T maxElement(T arr[], int n)
{
    T max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Function Template Specialization for strings
template <>
string maxElement<string>(string arr[], int n)
{
    string longest = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i].length() > longest.length())
            longest = arr[i];
    }

    return longest;
}

// Main function
int main()
{
    // Integer Matrix
    Matrix<int> m1(1, 2, 3, 4);

    cout << "Integer Matrix:\n";
    m1.display();

    // Double Matrix
    Matrix<double> m2(1.5, 2.5, 3.5, 4.5);

    cout << "\nDouble Matrix:\n";
    m2.display();

    // Matrix Addition
    Matrix<int> m3 = m1.add(m1);

    cout << "\nMatrix Addition:\n";
    m3.display();

    // Scalar Multiplication
    Matrix<double> m4 = m2.multiplyScalar(2.0);

    cout << "\nScalar Multiplication:\n";
    m4.display();

    // Integer Array
    int arr[] = {10, 30, 20, 50, 40};

    cout << "\nLargest Integer: "
         << maxElement(arr, 5);

    // String Array
    string words[] = {"Apple", "Banana",
                      "Watermelon", "Mango"};

    cout << "\nLongest String: "
         << maxElement(words, 4);

    // Complex Number Matrix
    Matrix<complex<double>> cm(
        {1, 2}, {2, 3},
        {3, 4}, {4, 5}
    );

    cout << "\n\nComplex Number Matrix:\n";
    cm.display();

    // Complex Matrix Addition
    Matrix<complex<double>> cm2 = cm.add(cm);

    cout << "\nComplex Matrix Addition:\n";
    cm2.display();

    return 0;
}