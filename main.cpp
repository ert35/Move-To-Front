//
//  main.cpp
//  ert35P1
//
//  Created by Elaina Teramoto on 10/6/17.
//  Copyright © 2017 Elaina Teramoto. All rights reserved.
//
/*
 Compare runtimes of Binary Search and Merge sort to move to front.
 
 */


#include "main.h"
using namespace std;
int main(int argc, const char * argv[])
{

    List<int>list;
    List<int>qList;
    clock_t timeBegin, timeEnd, timeBegin2, timeEnd2;
    double mergetime = 0.0,movetime = 0.0;
    int length, querysize, queryvalue, value;

    ifstream inFile(argv[1]);
    if (!(inFile.is_open()))
    {
        return 0;
    }
    else{
        inFile>> length;
        unsigned *arrayValues = new unsigned[length];
        // reading in the list values
        for (int i= 0; i< length; i++)
        {
            inFile>>value;
            //adds them into the linked list and array
            list.add(value);
            arrayValues[i]=value;
        }
        //reads in query list
        inFile>> querysize;
        int *qValues = new int[querysize];
        for (int j= 0; j< querysize; j++)
        {
            inFile>>queryvalue;
            //adds them into the linked list and array
            qList.add(queryvalue);
            qValues[j]=queryvalue;
            
        }
        timeBegin = clock();
        //puts the list in order
        mergeSort(arrayValues, 0, length-1);
        for (int k= 0; k< querysize; k++)
        {
            //goes through every query value
            binarySearch(arrayValues, length, qValues[k]);
        }
        timeEnd = clock();
        timeBegin2 = clock();
        for (int m= 0; m< querysize; m++)
        {
            //goes through every query value
            list.moveToFront(qValues[m]);
        }
        timeEnd2 = clock();
    }
    inFile.close();
    // caculate time and print
    mergetime = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    movetime = (double)(timeEnd2 - timeBegin2)/CLOCKS_PER_SEC;
    cout << "Total runtime for merge sort and binary is "
        << mergetime <<" seconds" <<endl;
    cout << "Total runtime for move to front is " << movetime <<" seconds" <<endl;
    if (mergetime < movetime)
        cout << "Merge Sort and Binary ran faster than Move to Front." <<endl;
    else if (mergetime == movetime)
        cout <<"Merge Sort and Binary ran the same time as Move to Front." <<endl;
    else
        cout << "Move to Front ran faster than Merge Sort and Binary." <<endl;
        
    return 0;
}
