#include <iostream>
using namespace std;
template <typename Type>
class CVector
{
private:
    Type* m_pVect; // Pointer to the buffer
    int m_nCount, // Control how many elements are actually used
        m_nMax, // Control the number of allocated elements
        m_nDelta; // To control the growing
    void Init(int delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(int delta); // Constructor
    void Insert(Type elem); // Insert a new element
    void Print();
    // More methods go here
};
template <typename Type>
void CVector<Type>::Init(int delta) {
    m_pVect = NULL;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

template <typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
}


template <typename Type>
void CVector<Type>::Resize()
{
    m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
    // The Max has to be increased by delta
    m_nMax += m_nDelta;
}

template <typename Type> void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

template <typename Type>
void CVector<Type>::Print() {
    for (int i = 0; i < 100; i++) {
        cout << m_pVect[i] << endl;
    }
}

int main()
{
    CVector<int> v(10);
    v.Insert(360);
    for (int i = 100; i > 0; i--) {
        v.Insert(i);
    }
    v.Print();
}