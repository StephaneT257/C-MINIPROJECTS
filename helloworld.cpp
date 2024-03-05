#include <iostream>
#include <vector>
#include <string>

using std::cout;

int main()
{
    std::vector<std::string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const std::string& word : msg)
    {
     cout << word << " ";
    }
    cout << std::endl;
}