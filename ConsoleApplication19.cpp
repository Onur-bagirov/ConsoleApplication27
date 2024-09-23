#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;


int* menfi_ededler(int a[], int olcu, int& yeni_olcu)
{
    int* yeni_massiv = new int[olcu];
    yeni_olcu = 0;
    for (int i = 0; i < olcu; i++) {

        if (a[i] >= 0) 
        {
            yeni_massiv[yeni_olcu++] = a[i];
        }
    }
    return yeni_massiv;
}

int* birlesdir(int a[], int m, int b[], int n, int& yeni_olcu) 
{
    yeni_olcu = m + n; 
    int* yeni_massiv = new int[yeni_olcu];
    for (int i = 0; i < m; i++) 
    {
        yeni_massiv[i] = a[i];
    }
    for (int i = 0; i < n; i++) 
    {
        yeni_massiv[m + i] = b[i];
    }
    return yeni_massiv;
}

int* ortaq_elementler(int a[], int m, int b[], int n, int& yeni_olcu) 
{
    yeni_olcu = 0;
    int* yeni_massiv = new int[m];
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (a[i] == b[j]) 
            {
                yeni_massiv[yeni_olcu++] = a[i];
                break;
            }
        }
    }
    return yeni_massiv;
}

int* a_olan_b_olmayan(int a[], int m, int b[], int n, int& yeni_olcu) 
{
    yeni_olcu = 0;
    int* yeni_massiv = new int[m]; 
    for (int i = 0; i < m; i++) 
    {
        bool tapildi = false;
        for (int j = 0; j < n; j++) 
        {
            if (a[i] == b[j]) 
            {
                tapildi = true;
                break;
            }
        }
        if (!tapildi) 
        {
            yeni_massiv[yeni_olcu++] = a[i];
        }
    }
    return yeni_massiv;
}

int* ortaq_olmayan(int a[], int m, int b[], int n, int& yeni_olcu) 
{
    yeni_olcu = 0;
    int* yeni_massiv = new int[m + n];
 
    for (int i = 0; i < m; i++) 
    {
        bool tapildi = false;
        for (int j = 0; j < n; j++) 
        {
            if (a[i] == b[j]) 
            {
                tapildi = true;
                break;
            }
        }
        if (!tapildi) 
        {
            yeni_massiv[yeni_olcu++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        bool tapildi = false;
        for (int j = 0; j < m; j++) 
        {
            if (b[i] == a[j]) {
                tapildi = true;
                break;
            }
        }
        if (!tapildi) {
            yeni_massiv[yeni_olcu++] = b[i];
        }
    }
    return yeni_massiv;
}

bool sadedir(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) return false;
    }
    return true;
}

int* sil_sade_ededler(int a[], int olcu, int& yeni_olcu) 
{
    yeni_olcu = 0;
    int* yeni_massiv = new int[olcu];
    for (int i = 0; i < olcu; i++) 
    {
        if (!sadedir(a[i])) 
        {
            yeni_massiv[yeni_olcu++] = a[i];
        }
    }
    return yeni_massiv;
}

void yazdir(int arr[], int olcu) 
{
    for (int i = 0; i < olcu; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int M, N;

    srand(time(0));

    cout << "Enter A Array size : ";
    cin >> M;


    cout << "Enter B Array size : ";
    cin >> N;

    int* A = new int[M];

    cout << "A Array :  ";

    for (int i = 0; i < M; i++) 
    {
        A[i] = rand() % 21 - 10;
        cout << A[i] << " ";
    }
    cout << endl;

    int* B = new int[N];

    cout << "B Array : ";

    for (int i = 0; i < N; i++) 
    {
        B[i] = rand() % 21 - 10; 
        cout << B[i] << " "; 
    }

    cout << endl;

    int yeni_olcu;

    cout << "=======================";
    cout << "\n\n";
    cout << "Tap - 1";
    cout << "\n\n\n\n";

    int* yeni_massiv1 = menfi_ededler(A, M, yeni_olcu);

    cout << "New Array : ";

    yazdir(yeni_massiv1, yeni_olcu);
    delete[] yeni_massiv1;

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================";
    cout << "\n\n";
    cout << "Tap - 3";
    cout << "\n\n\n\n";

    int* yeni_massiv2 = birlesdir(A, M, B, N, yeni_olcu);

    cout << "Birlestirimis array :  ";

    yazdir(yeni_massiv2, yeni_olcu);
    delete[] yeni_massiv2;

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================";
    cout << "\n\n";
    cout << "Tap - 3";
    cout << "\n\n\n\n";

    int* yeni_massiv3 = ortaq_elementler(A, M, B, N, yeni_olcu);

    cout << "Ortak array : ";

    yazdir(yeni_massiv3, yeni_olcu);
    delete[] yeni_massiv3;

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================";
    cout << "\n\n";
    cout << "Tap - 4";
    cout << "\n\n\n\n";

    int* yeni_massiv4 = a_olan_b_olmayan(A, M, B, N, yeni_olcu);

    cout << "A-da olub B-də olmayan eded :  ";

    yazdir(yeni_massiv4, yeni_olcu);
    delete[] yeni_massiv4;

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================";
    cout << "\n\n";
    cout << "Tap - 5";
    cout << "\n\n\n\n";


    int* yeni_massiv5 = ortaq_olmayan(A, M, B, N, yeni_olcu);

    cout << "Ortak olmayan eded : ";

    yazdir(yeni_massiv5, yeni_olcu);
    delete[] yeni_massiv5;


    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================";
    cout << "\n\n";
    cout << "Tap - 6";
    cout << "\n\n\n\n";

    int* yeni_massiv6 = sil_sade_ededler(A, M, yeni_olcu);

    cout << "Sade ededlerden sonra : ";

    yazdir(yeni_massiv6, yeni_olcu);
    delete[] yeni_massiv6;

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "=======================";

    delete[] A;
    delete[] B;

    return 0;
}
