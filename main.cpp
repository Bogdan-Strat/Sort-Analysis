#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;
ofstream g("date.out.txt");

void BubbleSort(vector<int> &v)
{
    int i,j,aux;
    for(i=0;i<v.size()-1;i++)
        for(j=0;j<(v.size()-i-1);j++)
            {
                if(v[j]>v[j+1])
                {
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                }
            }
}

void CountingSort(vector<int> &v)
{
    int i,maxi=0;
    vector<int> fr;
    vector<int> v_sortat;
    v_sortat.assign(v.size(),0);
    for(i=0;i<v.size();i++)
        if(v[i]>maxi)
            maxi=v[i];
    fr.assign((maxi+1),0);
    for(i=0;i<v.size();i++)
        fr[v[i]]++;
    for(i=1;i<=maxi;i++)
        fr[i]=fr[i]+fr[i-1];
    for(i=0;i<v.size();i++)
       {
        v_sortat[fr[v[i]]-1]=v[i];
        fr[v[i]]--;
       } 
    v.swap(v_sortat);
}

void Merge(vector<int> &v, int st, int mij, int dr)
{
    int length1,length2,i,j,d;
    vector<int> left;
    vector<int> right;

    length1=mij-st+1;
    length2=dr-mij;
    left.assign(length1,0);
    right.assign(length2,0);

    for(i=0;i<length1;i++)
        left[i]=v[st+i];
    for(i=0;i<length2;i++)
        right[i]=v[mij+1+i];
    
    i=0;
    j=0;
    d=st;

    while(i<length1 && j<length2)
        if(left[i]<=right[j])
            {
                v[d]=left[i];
                i++;
                d++;
            }
        else
        {
            v[d]=right[j];
            j++;
            d++;
        }
    
    while(i<length1)
        {
            v[d]=left[i];
            i++;
            d++;
        }
    while(j<length2)
    {
        v[d]=right[j];
        j++;
        d++;
    }
}

void MergeSort(vector<int> &v,int st, int dr)
{
    int mij;
    if(st<dr)
    {
        mij=(st+dr)/2;
        MergeSort(v,st,mij);
        MergeSort(v,mij+1,dr);
        Merge(v,st,mij,dr);
    }
}

int Partition(vector<int> &v, int st, int dr)
{
    int pivot,i,j,aux;

    pivot=v[dr];
    j=st;

    for(i=st;i<dr;i++)
        if(v[i]<=pivot)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            j++;
        }
    
    aux=v[j];
    v[j]=v[dr];
    v[dr]=aux;

    return j;
}

int RandomPivot(vector<int> &v, int  st, int dr)
{
    int piv,n,bux;
    n=rand();
    piv=st+n%(dr-st);

    bux=v[piv];
    v[piv]=v[dr];
    v[dr]=bux;

    return Partition(v,st,dr);
}

void QuickSortRandom(vector<int> &v, int st, int dr)
{
    int pivot_index;
    if(st<dr)
    {
        pivot_index=RandomPivot(v,st,dr);
        QuickSortRandom(v,st,pivot_index-1);
        QuickSortRandom(v,pivot_index+1,dr);
    }
}

void QuickSortFixed(vector<int> &v, int st, int dr)
{
    int pivot_index;
    if(st<dr)
    {
        pivot_index=Partition(v,st,dr);
        QuickSortFixed(v,st,pivot_index-1);
        QuickSortFixed(v,pivot_index+1,dr);
    }
}

void RadixCountSort(vector<int> &v, int exponent,int b)
{
    int i;
    vector<int> v_sortat;
    vector<int> fr;
    fr.assign(b,0);
    v_sortat.assign(v.size(),0);

    for(i=0;i<v.size();i++)
        fr[(v[i]/exponent)%b]++;
    
    for(i=1;i<b;i++)
        fr[i]=fr[i]+fr[i-1];

    for(i=v.size()-1;i>=0;i--)
    {
        v_sortat[fr[(v[i]/exponent)%b]-1]=v[i];
        fr[(v[i]/exponent)%b]--;
    }

    v.swap(v_sortat);
    v_sortat.clear();
}

void RadixSort(vector<int> &v,int b)
{
    int i, maxi=0,exponent;
    for(i=0;i<v.size();i++)
        if(v[i]>maxi)
            maxi=v[i];
    
    for(exponent=1;maxi/exponent>0;exponent=exponent*b)
        RadixCountSort(v,exponent,b);
    
}
int main(){

    //vector<int> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;
    vector<int> v6;
    vector<int> v7;
    vector<int> v8;
    
    int i,j,n,val,t,nr_maxim;
    cout<<"Numar teste: ";
    cin>>t;
    cout<<endl<<"Numar numere: ";
    cin>>n;
    cout<<endl<<"Numar maxim: ";
    cin>>nr_maxim;
    
    

   
    for(j=1;j<=t;j++)
    {
        srand(time(NULL));
        for(i=0;i<n;i++)
        {
            
            v1.push_back(rand()%nr_maxim+1);
            v2.push_back(rand()%nr_maxim+1);
            v3.push_back(rand()%nr_maxim+1);
            v4.push_back(rand()%nr_maxim+1);
            v5.push_back(rand()%nr_maxim+1);
            v6.push_back(rand()%nr_maxim+1);
            v7.push_back(rand()%nr_maxim+1);
            v8.push_back(rand()%nr_maxim+1);
            
        }
        
        for(i=1;i<=8;i++)
        if(i==1)
            {   if(n>=1000000 || nr_maxim>100000000)
                    g<<"Algoritmul BubbleSort nu a putut sorta"<<endl;
                else
                {
                try
                {
                sort(v1.begin(),v1.end());
                auto start1=high_resolution_clock::now();
                BubbleSort(v1);
                auto stop1=high_resolution_clock::now();
                auto duration1=duration_cast<microseconds>(stop1-start1);
                if(is_sorted(v1.begin(),v1.end())==1)
                    g<<"BubbleSort: "<<duration1.count()<<" microseconds"<<endl;
                else
                    g<<"Algoritmul BubbleSort nu a putut sorta"<<endl;
                }
                catch(...)
                {
                    g<<"Algoritmul BubbleSort nu a putut sorta"<<endl;
                }
                }
                
                v1.clear();
            }
        else if(i==2)
            {
                if(nr_maxim>100000000 || n>100000000)
                    g<<"Algoritmul CountSort nu a putut sorta"<<endl;
                else{
                        try{
                sort(v2.begin(),v2.end());
                auto start2=high_resolution_clock::now();
                CountingSort(v2);
                auto stop2=high_resolution_clock::now();
                auto duration2=duration_cast<microseconds>(stop2-start2);
                if(is_sorted(v2.begin(),v2.end())==1)
                    g<<"CountSort: "<<duration2.count()<<" microseconds"<<endl;
                else
                    g<<"Algoritmul CountSort nu a putut sorta"<<endl;
                }
                catch(...)
                {
                    g<<"Algoritmul CountSort nu a putut sorta"<<endl;
                }
                }

                v2.clear();
            }
        else if(i==3)
            {
                if(n>10000000  || nr_maxim>100000000)
                     g<<"Algorimul MergeSort nu a putut sorta"<<endl;
                else{
                    try{
                sort(v3.begin(),v3.end());
                auto start3=high_resolution_clock::now();
                MergeSort(v3,0,v3.size()-1);
                auto stop3=high_resolution_clock::now();
                auto duration3=duration_cast<microseconds>(stop3-start3);
                if(is_sorted(v3.begin(),v3.end())==1)
                    g<<"MergeSort: "<<duration3.count()<<" microseconds"<<endl;
                else
                    g<<"Algorimul MergeSort nu a putut sorta"<<endl;
                }
                catch(...)
                {
                    g<<"Algorimul MergeSort nu a putut sorta"<<endl;
                }
                }
                
                v3.clear();
            }
        else if(i==4)
            {   
                if(n>10000000  || nr_maxim>100000000)
                    g<<"Algoritmul RadixSort_baza_2 nu a putut sorta"<<endl;
                else{
                        try
                {
                sort(v4.begin(),v4.end());
                auto start4=high_resolution_clock::now();
                RadixSort(v4,2);
                auto stop4=high_resolution_clock::now();
                auto duration4=duration_cast<microseconds>(stop4-start4);
                if(is_sorted(v4.begin(),v4.end())==1)
                    g<<"RadixSort_baza_2: "<<duration4.count()<<" microseconds"<<endl;
                else
                    g<<"Algoritmul RadixSort_baza_2 nu a putut sorta"<<endl;
                }
                catch(...)
                {
                    g<<"Algoritmul RadixSort_baza_2 nu a putut sorta"<<endl;
                }
                }
                
                
                
                v4.clear();
            }
        else if(i==5)
            {
                if(nr_maxim>100000000 || n>100000000)
                    g<<"Algoritmul RadixSort_baza_10 nu a putut sorta"<<endl;
                else{
                        try{
                sort(v5.begin(),v5.end());
                auto start5=high_resolution_clock::now();
                RadixSort(v5,10);
                auto stop5=high_resolution_clock::now();
                auto duration5=duration_cast<microseconds>(stop5-start5);
                if(is_sorted(v5.begin(),v5.end())==1)
                    g<<"RadixSort_baza_10: "<<duration5.count()<<" microseconds"<<endl;
                else
                    g<<"Algoritmul RadixSort_baza_10 nu a putut sorta"<<endl;
                }
                catch(...)
                {
                    g<<"Algoritmul RadixSort_baza_10 nu a putut sorta"<<endl;
                }
                }
                v5.clear();
            }
        else if(i==6)
            {   
                if(n>1000000  || nr_maxim>100000000)
                    g<<"Algoritmul QuickSort_pivot_random nu a putut sorta"<<endl;
                else
                {
                try{
                sort(v6.begin(),v6.end());
                auto start6=high_resolution_clock::now();
                QuickSortRandom(v6,0,v6.size()-1);
                auto stop6=high_resolution_clock::now();
                auto duration6=duration_cast<microseconds>(stop6-start6);
                if(is_sorted(v6.begin(),v6.end())==1)
                    g<<"QuickSort_pivot_random: "<<duration6.count()<<" microseconds"<<endl;
                else
                    g<<"Algoritmul QuickSort_pivot_random nu a putut sorta"<<endl;
                }
                catch(...){
                    g<<"Algoritmul QuickSort_pivot_random nu a putut sorta"<<endl;
                }
                }
                
                v6.clear();
            }
        else if(i==7)
            {
                if(n>=1000000  || nr_maxim>100000000)
                    g<<"Algoritmul QuickSort_pivot_last_element nu a putut sorta"<<endl;
                else{
                try
                {
                    sort(v7.begin(),v7.end());
                auto start7=high_resolution_clock::now();
                QuickSortFixed(v7,0,v7.size()-1);
                auto stop7=high_resolution_clock::now();
                auto duration7=duration_cast<microseconds>(stop7-start7);
                if(is_sorted(v7.begin(),v7.end())==1)
                    g<<"QuickSort_pivot_last_element: "<<duration7.count()<<" microseconds"<<endl;
                else
                    g<<"Algoritmul QuickSort_pivot_last_element nu a putut sorta"<<endl;
                }
                catch(...)
                {
                     g<<"Algoritmul QuickSort_pivot_last_element nu a putut sorta"<<endl;
                }
                }
               
                
                v7.clear();
            }
        else if(i==8)
        {
            if(n>10000000  || nr_maxim>100000000)
                g<<"Algoritmul din C++ nu a putut sorta"<<endl;
            else{
                    try
                    {
                        sort(v8.begin(),v8.end());
                    auto start8=high_resolution_clock::now();
                    sort(v8.begin(),v8.end());
                    auto stop8=high_resolution_clock::now();
                    auto duration8=duration_cast<microseconds>(stop8-start8);
                    if(is_sorted(v7.begin(),v7.end())==1)
                        g<<"Algoritmul din C++: "<<duration8.count()<<" microseconds"<<endl;
                    else
                        g<<"Algoritmul din C++ nu a putut sorta"<<endl;   
                    }
                    catch(...)
                    {
                    g<<"Algoritmul din C++ nu a putut sorta"<<endl; 
                    }
                }
            
            v8.clear();
        }

    }

    
    return 0;
}
