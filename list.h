//
//  list.h
//  ert35P1
//
//  Created by Elaina Teramoto on 10/6/17.
//  Copyright © 2017 Elaina Teramoto. All rights reserved.
//

#ifndef list_h
#define list_h

using namespace std;
template <typename T>
class List;

template <typename T>
class List {
public:
    List();
    ~List();
    void moveToFront(T& );
    void add(const T & );
    
private:
    Node<T> *frontPtr;
}; // List class

template<typename T>
List<T>::List()
{
    frontPtr = 0;
}

template<typename T>
List<T>::~List()
{
    while (frontPtr != 0)
    {
        if(frontPtr->getNextPtr() == NULL ) //only one value on the list
        {
            frontPtr = NULL;
        }
        else
        {
            Node <T> *fptr = frontPtr;
            frontPtr = frontPtr-> getNextPtr();
            frontPtr-> setPrevPtr(fptr->getPrevPtr());
        }
    }
}

template<typename T>
void List<T>::moveToFront(T &object)
{
    Node<T> *tempPtr = frontPtr;
    while ((tempPtr!=0) && !(tempPtr->getObject()==object))
    {
        tempPtr = tempPtr-> getNextPtr();
    }
    if (tempPtr->getObject() == object)
    {
        // finds the object
        if(tempPtr ==frontPtr)
        {
            return;
        }
        else
        {
            tempPtr ->getPrevPtr ()->setNextPtr(tempPtr->getNextPtr());
            if (!(tempPtr->getNextPtr()==NULL))
            {
                tempPtr ->getNextPtr()->setPrevPtr(tempPtr ->getPrevPtr());
            }
            tempPtr->setNextPtr(frontPtr);
            tempPtr ->setPrevPtr(NULL);
            frontPtr->setPrevPtr(tempPtr);
            frontPtr = tempPtr;
        }
    }
}

template<typename T>
void List<T>:: add( const T &object )
{
    //adds the object to the end of the linked list
    Node<T> *tempBPtr = new Node<T>(object);
    if (!(frontPtr==NULL))
    {
        tempBPtr->setNextPtr(frontPtr);
        frontPtr-> setPrevPtr(tempBPtr);
    }
    frontPtr = tempBPtr;
    

    
    
    
    
    
    
    
}

#endif /* list_h */
