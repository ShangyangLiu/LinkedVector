/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "LinkedVector.h"
using namespace std;

int main()
{
    LinkedVector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.show();
    cout<<"在第1个位置处插入5后";
    vector.insert(1,5);
    vector.show();
    vector.remove(0);
    cout<<"删除第0个元素后：";
    vector.show();
    LinkedVector<int> vec = vector.subList(1,2);
    vec.show();


    return 0;
}








