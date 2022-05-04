#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <cassert>
#include "Sorts_algh.h"
#include <chrono>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

template<typename T, class Compare = less<T>>
void TimerSort(vector<T> & vec, int & sort_type, int & size_vec)
{
  Compare cmp;
     if(sort_type == 1)

    {     auto a = chrono::steady_clock::now();
          qs(vec);
          auto b = chrono::steady_clock::now();
          double time = chrono::duration <double, milli> (b - a).count();
          cout <<"Size Array :"<< size_vec<<" "<<"Time ---> " << time << " ms";
          cout << endl;
          

    }

    else if(sort_type == 2){

          auto a = chrono::steady_clock::now();
          heapSort(vec);
          auto b = chrono::steady_clock::now();
          double time = chrono::duration <double, milli> (b - a).count();
          cout << "Size Array :"<< size_vec<<" "<<"Time ---> " << time << " ms";
          cout << endl;
          

    }
    else if(sort_type == 3){
          auto a = chrono::steady_clock::now();
          Insert(vec);
          auto b = chrono::steady_clock::now();
          double time = chrono::duration <double, milli> (b - a).count();
          cout <<"Size Array :"<< size_vec<<" "<<"Time ---> " << time << " ms";
          //cout << endl;
    }
    else if(sort_type == 4){
          auto a = chrono::steady_clock::now();
          Select(vec);
          auto b = chrono::steady_clock::now();
          double time = chrono::duration <double, milli> (b - a).count();
          cout << "Size Array :"<< size_vec<<" "<<"Time ---> " << time << " ms";
          //cout << endl;
    }
      else if(sort_type == 5){
          auto a = chrono::steady_clock::now();
          Buble(vec);
          auto b = chrono::steady_clock::now();
          double time = chrono::duration <double, milli> (b - a).count();
          cout <<"Size Array :"<< size_vec<<" "<<"Time ---> " << time << " ms";
          //cout << endl;

    }

}

void ShowTypeSort(int& type)
{
  if(type == 1)cout << "Быстрая Сортировка:" << endl;
    else if(type == 2)cout << "Пирамидальная Сортировка:"<< endl;
    else if(type == 3)cout << "Сортировка Вставками:";
    else if(type == 4)cout << "Сортировка Выбором:"; 
    else if(type == 5)cout << "Сортировка Пузырьком:";
}


void String_sort(vector<string>& str, int & size_vec, int sort_type){

mt19937 generator{random_device{}()};
uniform_int_distribution<int> distribution{'a', 'z'};
random_device  rd;
mt19937     rng(rd());
uniform_int_distribution<int>  num(2, 20);  //генерирую длинну строки


for(int i = 0 ; i <= size_vec; ++i) {

      auto generate_len = num(rng);
      string rand_str(generate_len, '\0');
      for(auto& dis: rand_str)
      dis = distribution(generator);

      str.push_back(rand_str);
}

      TimerSort(str,sort_type,size_vec);

}

void Data_sort(vector<Data>& vec, int & size_vec, int sort_type){

random_device  rd;
  mt19937     rng(rd());
  uniform_int_distribution<int>  day(1, 30),month(1,12),year(1700,2300);


for(int i = 0; i < size_vec ; ++i )
  {
         vec.push_back(Data{day(rng),month(rng),year(rng)});
  }
  
  TimerSort(vec,sort_type,size_vec);
}

void Number_sort(vector<double>& vec, int & size_vec, int sort_type)
{
  random_device  rd;
  mt19937     rng(rd());
  uniform_real_distribution<double>  num(-1000.0, 1000.0);

  for(int i = 0; i <= size_vec;++i)
    {
        vec.push_back(num(rng));
    }

    TimerSort(vec,sort_type,size_vec);
}



void NumberSortingAnalysis(){

  vector<double>numbers; 

  for(int n_type =1; n_type <= 3 ; n_type++)
{
    
    ShowTypeSort(n_type);
    for(int i = 4096; i <=140000; i*=2) // 8 192/ 16 384/ 32 768 / 65 536 / 131 072 // for(int i = 4096; i <=32768; i*=2)
      { 

        
        Number_sort(numbers,i,n_type);


      }
cout << endl;
cout << endl;

}

}

void StringsSortingAnalysis(){

  vector<string>str; 

  for(int n_type =1; n_type <= 3 ; n_type++)
{
    
    ShowTypeSort(n_type);
    for(int i = 4096; i <=140000; i*=2) // 8 192/ 16 384/ 32 768 / 65 536 / 131 072 // for(int i = 4096; i <=32768; i*=2)
      { 

        
        String_sort(str,i,n_type);


      }
cout << endl;
cout << endl;

}

}

void DatesSortingAnalysis(){

vector<Data> data;

for(int n_type =1; n_type <= 3 ; n_type++)
{
    
    ShowTypeSort(n_type);
    for(int i = 4096; i <=140000; i*=2)// 8 192/ 16 384/ 32 768 / 65 536 / 131 072 // for(int i = 4096; i <=32768; i*=2)
      { 

        
        Data_sort(data,i,n_type);


      }
cout << endl;
cout << endl;

}

}



int main (){
 
cout << "Анализ различных сортировок над разными типами данных "<< endl;
cout << endl;

cout << "Анализ эффективности алгоритмов при сортировке чисел "<< endl;
cout << endl;
NumberSortingAnalysis();
cout << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------"<<endl;
cout << "Анализ эффективности алгоритмов при сортировке строк "<< endl;
cout << endl;
StringsSortingAnalysis();
cout << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------"<<endl;
cout << "Анализ эффективности алгоритмов при сортировке дат "<< endl;
cout << endl;
DatesSortingAnalysis();
cout << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------"<<endl;

  return 0;
}






