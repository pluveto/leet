#include <iostream>
#include <memory>
#include <string>

using namespace std;

unique_ptr<int> make1()
{
    return unique_ptr<int>( new int(1) );
}
 
unique_ptr<int> increment( unique_ptr<int> i )
{
    ++*i;
    return i;
}
 
int main()
{
    unique_ptr<int> p = increment(make1());
    std::cout << *p << std::endl;
}