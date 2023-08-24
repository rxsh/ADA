#include <iostream>

using namespace std;

struct Vector
{
    int*m_pVect=NULL, // Pointer to the buffer
    m_nCount=0, // Control how many elements are actually used
    m_nMax=0, // Control how many are allocated as maximum
    m_nDelta=50; // To control the growing
};

void Resize(Vector *pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) *
        (pThis->m_nMax + pThis->m_nDelta));
    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector *pThis, int elem)
{
    if( pThis->m_nCount == pThis->m_nMax) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}


int main(){

    Vector vec;
    Vector* p = &vec;
    //Insert(p, 420);
    //cout << vec.m_pVect[0] << endl;

    for(int i=100; i>0;i--){
        Insert(p,i);
    }

    for(int i=0;i<100;i++){
        cout << vec.m_pVect[i] << endl;
    }



    return 0;
}