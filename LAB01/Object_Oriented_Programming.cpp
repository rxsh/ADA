#include <iostream>

using namespace std;

// Class CVector definition
class CVector
{
private:
    int *m_pVect, // Pointer to the buffer
    m_nCount, // Control how many elements are actually used
    m_nMax, // Control how many are allocated as maximum
    m_nDelta; // To control the growing
    void Init(int delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(int delta); // Constructor
    void Insert(int elem); // Insert a new element
    // More methods go here
    void Print();

};

void CVector::Resize()
{
    m_pVect = (int*)realloc(m_pVect, sizeof(int) *
    (m_nMax + m_nDelta));
    // The Max has to be increased by delta
    m_nMax += m_nDelta;
}

void CVector::Insert(int elem)
{
    if( m_nCount == m_nMax ) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Init(int delta){
    m_pVect = NULL;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

CVector::CVector(int delta){
    Init(delta);
}

void CVector::Print(){
    for(int i=0;i<100;i++){
        cout << m_pVect[i] << endl;
    }
}


int main(){

    CVector vect(10);

    for(int i=0; i < 100; i++){
        vect.Insert(i);
    }

    vect.Print();
    return 0;
}