#include<iostream>
using namespace std;
struct Node
{
    float heso; 
    int somu;
    Node *link;
};

struct ListDT
{
    Node *first, *last;
};

void InitDT(ListDT *l) 
{
    l->first = l->last = NULL; // Khởi tạo danh sách rỗng
}

Node *CallNode(float hs, int sm) 
{
    Node *p;
    p = new Node;
    if(p == NULL) return NULL; // Kiểm tra xem bộ nhớ đã được cấp phát thành công chưa
    p->heso = hs;
    p->somu = sm;
    p->link = NULL;
    return p;
}

void addNode(ListDT* lDT, Node *p)
{
    if(lDT->first == NULL) // Danh sách rỗng
    {
        lDT->first = lDT->last = p;
    }
    else
    {
        lDT->last->link = p; // Gán địa chỉ nút cuối bằng p
        lDT->last = p; // Chuyển p thành nút cuối
    }
}

void attachNode(ListDT *lDT, float hs, int sm)
{
    Node *pDT = CallNode(hs, sm);
    if(pDT == NULL) return;
    addNode(lDT, pDT);
}

void taoDT(ListDT *lDT) {
    float hs;
    int sm;
    int i = 0; // Counter for elements
    cout << "Bat dau nhap da thuc (Nhap he so 0 de ket thuc): " << endl;
    do {
        i++;
        cout << "Nhap so phan tu thu " << i << endl;
        cout << "Nhap he so = ";
        cin >> hs;
        if (hs == 0) break; // Exit if coefficient is zero
        cout << "Nhap so mu = ";
        cin >> sm;
        attachNode(lDT, hs, sm);
    } while (true);  // Infinite loop, broken by 'break' when hs == 0
    cout << "Ket thuc nhap" << endl;
}

void inDT(ListDT lDT)
{
    Node *p;
    p = lDT.first;
    cout << "\nf(x) = ";
    while (p != NULL)
    {
        cout << p->heso << " * x^" << p->somu;
        if(p->link != NULL && p->heso != 0) cout << " + ";
        p = p->link;
    }
}

int main() {
    ListDT DT1;
    InitDT(&DT1);
    taoDT(&DT1);
    inDT(DT1);
}
