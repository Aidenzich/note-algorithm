#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std ;

int partition(std::vector<int> &vec, int low, int high)
{
    int middle = low + (high - low) / 2;

    if((vec.at(middle) >= vec.at(low) && vec.at(middle) <= vec.at(high))
        || (vec.at(middle) <= vec.at(low) && vec.at(middle) >= vec.at(high)))
        std::swap(vec.at(high), vec.at(middle));

    if((vec.at(high) >= vec.at(low) && vec.at(high) <= vec.at(middle))
        || (vec.at(high) <= vec.at(low) && vec.at(high) >= vec.at(middle)))
        std::swap(vec.at(low), vec.at(high));


    int pivot = vec.at(low);
    
    int i = low - 1, j = high + 1;

    while(true)
    {
        do
        {
            i++;
        } while(vec.at(i) < pivot);

        do
        {
            j--;
        } while(vec.at(j) > pivot);

        if(i >= j)
            return j;

        std::swap(vec.at(i), vec.at(j));
    }
}

void quickSort(std::vector<int> &vec, int low, int high)
{
    if(low < high)
    {
        int pi = partition(vec, low, high);
        cout << pi << "\n";
        quickSort(vec, low, pi);
        quickSort(vec, pi + 1, high);
    }
}

int main()
{
    int num;
    cin >> num;
    std::vector<int> input;

    for (int i=0; i < num; i++){
        int temp;
        cin >> temp;
        input.push_back(temp);
    }


    quickSort(input, 0, input.size() - 1);
    
    // for(auto iter = input.begin(); iter != input.end(); ++iter)
    //     std::cout << *iter << " ";
    // std::cout << "\n";

    
    return 0;
}