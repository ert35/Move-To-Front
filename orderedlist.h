//
//  orderedlist.h
//  ert35P1
//
//  Created by Elaina Teramoto on 10/6/17.
//  Copyright © 2017 Elaina Teramoto. All rights reserved.
//

#ifndef orderedlist_h
#define orderedlist_h

using namespace std;

int binarySearch(unsigned *arrayValues,int length, unsigned find);
void merge(unsigned *arr, int l, int m, int r);
void mergeSort(unsigned *arr, int l, int r);


int binarySearch(unsigned *arrayValues,int length, unsigned find)
{
    int bottom = 0;
    while(bottom  <= length-1)
    {
        int mid = (bottom + (length-1))/2;
        if (find ==arrayValues[mid]) //if find is the middle
            return mid;
        else if(find > arrayValues[mid]) // if find is larger than the middle
            bottom = mid + 1; //cuts array search in half
        else if(find < arrayValues[mid]) // if find is small than the middle
            length = mid - 1; //cuts array search in half
    }
    return -1;
}


void merge(unsigned *unorderarr, int left, int middle, int right)
{
    int bsize = middle - left + 1;
    int tsize =  right - middle;
    int a = 0, b = 0, c = left;
    int bottom[bsize], top[tsize];
    
    //copy data into temporary arrays
    for (int i = 0; i < bsize; i++)
        bottom[i] = unorderarr[left + i];
    for (int j = 0; j < tsize; j++)
        top[j] = unorderarr[middle + 1+ j];
    
    //merge the temporary arrays back in the original array
    while (a < bsize && b < tsize)
    {
        if (bottom[a] <=top[b])
        {
            unorderarr[c] = bottom[a];
            a++;
        }
        else
        {
            unorderarr[c] = top[b];
            b++;
        }
        c++;
    }
    while (a < bsize)
    {
        unorderarr[c] = bottom[a];
        a++;
        c++;
    }
    while (b < tsize)
    {
        unorderarr[c] = top[b];
        b++;
        c++;
    }
}

void mergeSort(unsigned *unorderarr, int left, int right)
{
    //subarray
    if (left < right)
    {
        int middle = left+(right-left)/2;
        //sort first and second half
        mergeSort(unorderarr, left, middle);
        mergeSort(unorderarr, middle+1, right);
        merge(unorderarr, left, middle, right);
    }
}
#endif /* orderedlist_h */
