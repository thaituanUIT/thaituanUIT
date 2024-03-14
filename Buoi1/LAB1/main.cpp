#include <iostream>

using namespace std;

struct PhanSo
{
    int iTuSo;
    int iMauSo;
};

typedef PhanSo PS;


void scanf(PS& A)
{
    cin >> A.iTuSo1 >> A.iMauSo1;
}

int scanf(PS A)
{
    cin >> A.iTuSo1 >> A.iMauSo1;
    return A;
}

void printf(PS A)
{
    cout << A.iTuSo << "/" << A.iMauSo;
}

void printf(PS* A)
{
    cout << A->iTuSo << "/" << A->iMauSo;
}

/*
3. Rut gon phan so
Input:
     + PhanSo a -> Dat ()

Output:
     + return ps
*/
int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

PhanSo RutGon(PS A)
{
    PhanSo B;
    int GCD = UCLN(A.iTuSo, A.iMauSo);
    B.iTuSo = A.iTuSo / GCD;
    B.iMauSo = A.iMauSo / GCD;
    return B;
}

/*
4. So sanh hai phan so
Input:
    + PhanSo A
    + PhanSo B
Output:
    + return 1: >
    + return 0: =
    + return -1: <
*/

int SoSanhHaiPhanSo(PS A, PS B)
{
    int TuSo = A.iTuSo * B.iMauSo - B.iTuSo * A.iMauSo;
    int MauSo = A.iMauSo * B.iMauSo;

    if (MauSo != 0)
    {
        if (TuSo == 0)
            return 0;
        else if (TuSo > 0)
            return 1;
        else
            return -1;
    }
}

/*
Cau 7: Nhan hai phan so
Input:
    + PhanSo A
    + PhanSo B
Output;
    + return PS
*/

PhanSo NhanHaiPhanSo(PS A, PS B)
{
    PhanSo C, D;
    C.iTuSo = A.iTuSo * B.iTuSo;
    C.iMauSo = A.iMauSo * B.iMauSo;

    int GCD = RutGon(C.iTuSo, C.iMauSo);
    D.iTuSo = C.iTuSo / GCD;
    D.iMauSo = C.iMauSo / GCD;
    return D;
}

/*
Cau 8: Cong hai phan so
Input:



*/
int main()
{
    PS A, B;

    //Test Cau 1: Nhap phan so
    scanf(A);
    scanf(B);

    //Test Cau 2: Xuat, in phan so
    printf(A);
    printf(&B);

    //Test Cau 3: Rut gon phan so
    printf(RutGon(A));
    printf(RutGon(B));

    //Test Cau 4: So sanh hai phan so
    if (SoSanhHaiPhanSo(A, B) == 0)
    {
        cout << "Equal";
    }
    else if (SoSanhHaiPhanSo(A, B) == 1)
    {
        cout << "Greater";
    }
    else if (SoSanhHaiPhanSo(A, B) == -1)
    {
        cout << "Smaller";
    }

    //Test Cau 7: Nhan hai phan so
    printf(NhanHaiPhanSo(A, B));

    //Test Cau 8: Cong hai phan so
    return 0;
}
