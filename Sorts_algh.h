#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

template<typename T,class Compare = less<T>>
void PrintSortMass(vector<T> const & vec)
{
        for(auto v :vec)
        {
            cout << v << " ";
        }
}


template<typename T, class Compare = less<T>>
 void Buble( vector<T> & vec){
     Compare cmp;
     //cout << "Cортировка Пузырьком :" << endl;
        int x = 0;
     for(int j = 1; j < vec.size(); j++ ){
         
         for(int i = 0; i < vec.size()- 1; i++){
             if(vec[i] > vec[i+1])
             {
                 ++x;
                auto temp = vec[i];
                 vec[i] = vec[i+1];
                 vec[i+1] = temp;
                 
                
                 
             }
             
         }
     }

        cout << endl;
 }

template<typename T, class Compare = less<T>>
 void Select(vector<T> /*const*/ & vec)
 {
    Compare cmp;
    //cout << "Cортировка Выбором:" << endl;
    for(int i = 0; i < vec.size()-1; i++){
        int min_i = i;

        for ( int j = i + 1; j < vec.size();j++){
            if(vec[j] < vec[min_i]){
                min_i = j;
            }
        }   
            
            auto temp = vec[i];
                 vec[i] = vec[min_i];
                 vec[min_i] = temp;
                 
                 

    }
    
cout << endl;
 }
template<typename T, class Compare = less<T>>
 void Insert(vector<T>  & vec){
 Compare cmp;
    //cout << "Cортировка Вставками:" << endl;
    

	int i, j ;
for (i = 1; i < vec.size(); i++)
{
    auto temp = vec[i];
    for (j = i - 1; j >= 0; j--)
    {
        if (vec[j] < temp)
            break;
        
        vec[j + 1] = vec[j];
        vec[j] = temp;
        
    }
}
cout << endl;
 }

struct Data
{
    int day;
    int month;
    int year;
    
    bool operator< (const Data &c2)
{
    
    if(year < c2.year){
    return true;}

    if (year == c2.year && month < c2.month){
        return true;
    }

    if (year == c2.year && month == c2.month && day < c2.day){
        return true;

    }

    return false;
}
    
    bool operator> (const Data &c2)
{
    
    if(year > c2.year){
    return true;}

    if (year == c2.year && month > c2.month){
        return true;
    }

    if (year == c2.year && month == c2.month && day > c2.day){
        return true;

    }

    return false;
}

};
ostream& operator<< (ostream& out, const Data& data) 
{
	out <<data.day <<"."<<data.month <<"."<<data.year;
	return out;
}

template<typename T, class Compare = less<T>>
void heapify(vector<T>& vec, int n ,int i)
{
    int largest = i;

    int l = 2 * i + 1 ;
    int r = 2 * i + 2 ;

    if(l < n && vec[l] > vec[i])
    {
        largest = l;
    }

     if (r < n && vec[r] > vec[largest]){
        largest = r;
     }
        
        if(largest != i)
        {
            swap(vec[i],vec[largest]);
            heapify(vec,n,largest);
        }
}



template<typename T, class Compare = less<T>>
 void heapSort(vector<T> /*const*/ & vec)
 {
    Compare cmp;
    //cout << "Cортировка Пирамидальным методом:" << endl;

    int  n = vec.size();
    for(int i = n /2 - 1; i >= 0; i--){
        heapify(vec,n,i);
    }
        for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(vec[0], vec[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(vec, i, 0);
    }

}
 
template<typename T, class Compare = less<T>>
void qSort(vector<T> /*const*/ & vec, int first ,int last )
{   
    int i = first, j = last;
    T x = vec[(first + last) / 2];
  
    do {
        while (vec[i] < x) i++;
        while (vec[j] > x) j--;
  
        if(i <= j) {
            if (vec[i] > vec[j]) swap(vec[i], vec[j]);
        
            i++;
            j--;
        }


    } while (i <= j);
  
    if (i < last) {

        qSort(vec, i, last);

    }


    if (first < j){
        
        qSort(vec, first, j);
    }
}

template<typename T, class Compare = less<T>>
void qs(vector<T> /*const*/ & vec)
{   
    //cout << "Быстрая сортировка :"<< endl;
    Compare cmp;
    int size = vec.size();
    int first = 0;
    int last = size - 1 ;
    qSort(vec,first,last);

}