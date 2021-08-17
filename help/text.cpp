#include<iostream>
using namespace std;

int main(){
    int b[2][3]={{6,5,4},{3,2,1}};
    int *ptr=(int*)(&b[0]+1);
    printf("%d,%d",*(b[0]+1),*(ptr+1));
}