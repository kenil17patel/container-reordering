#include <iostream>
#include <algorithm>
#include <forward_list>
#include <list>
#include <functional>

struct Data {
    std::uint8_t x;
    double y;
};

// Prints the container data
template<typename T>
void printData(T& container){
    for(auto it = container.begin(); it != container.end(); ++it){
        std::cout<<unsigned(it->x)<<"-"<<unsigned(it->y)<<"  ";
    }
    std::cout<<std::endl;
}

// Reorders the container in such a way, that subset A preceeds subset B
template<typename T>
void reorderSubsetAB(T& container){
    // Sort container data in ascending order based on x member of Data struct so subsetA preceeds subsetB
    std::sort(container.begin(),container.end(),[](Data& obj1, Data& obj2){
        return obj1.x>obj2.x;
    });
}

// Template specialization for forward_list
template<>
void reorderSubsetAB(std::forward_list<Data>& container){
    // Sort container data in ascending order based on x member of Data struct so subsetA preceeds subsetB
    container.sort([](Data& obj1, Data& obj2){
        return obj1.x>obj2.x;
    });
}

// Template specialization for list
template<>
void reorderSubsetAB(std::list<Data>& container){
    // Sort container data in ascending order based on x member of Data struct so subsetA preceeds subsetB
    container.sort([](Data& obj1, Data& obj2){
        return obj1.x>obj2.x;
    });
}

// Reorders elements of subset B in such a way, that given number ```n``` of elements has smallest value of y and this n elements are in ascending order of y. Let this ```n``` elements be subset C
template<typename T>
int formSubsetC(T& container, std::uint8_t x_threshold) {
    // Finding that from where subsetB will be starting in container
    auto iterator = std::find_if(container.begin(),container.end(), [&x_threshold](Data& obj){
                    return obj.x<=x_threshold;
    });
    int bStartIndex = std::distance(container.begin(),iterator);
    // Sorting subsetB data in ascending order based on y member of Data struct 
    std::sort(iterator,container.end(),[](Data& obj1, Data& obj2){
          return obj1.y<obj2.y;
    });
    
    //return subsetB start index
    return bStartIndex;
}

// Template specialization for forward_list
template<>
int formSubsetC(std::forward_list<Data>& container, std::uint8_t x_threshold) {
    // Finding that from where subsetB will be starting in container
    auto iterator = std::find_if(container.begin(),container.end(), 
                    [&x_threshold](Data& obj){
                    return obj.x<=x_threshold;
    });
    int bStartIndex = std::distance(container.begin(),iterator);
    auto tempIterator=iterator;
    
    // Creating subsetB forward_list and sorting them in ascending order based on y member of Data struct 
    std::forward_list<Data> subsetBList;
    for(tempIterator; tempIterator != container.end(); ++tempIterator){
        subsetBList.push_front(*tempIterator);
    }
    subsetBList.sort([](Data& obj1, Data& obj2){
        return obj1.y<obj2.y;
    });
    
    // Resizing forward_list till subsetA
    container.resize(std::distance(container.begin(),iterator));
    
    // Will add data of subsetB list at the end of subsetA in main forward_list
    tempIterator = container.before_begin();
    for (auto& _ : container){
     tempIterator++;
    }
    for(auto it = subsetBList.begin();it!=subsetBList.end();it++){
        container.insert_after(tempIterator, *it);
        tempIterator++;
    }
    
    //return subsetB start index
    return bStartIndex;
}

// Template specialization for list
template<>
int formSubsetC(std::list<Data>& container, std::uint8_t x_threshold) {
    // Finding that from where subsetB will be starting in container
    auto iterator = std::find_if(container.begin(),container.end(), 
                    [&x_threshold](Data& obj){
                    return obj.x<=x_threshold;
    });
    int bStartIndex = std::distance(container.begin(),iterator);
    auto tempIterator=iterator;
    
    // Creating subsetB list and sorting them in ascending order based on y member of Data struct 
    std::list<Data> subsetBList;
    for(tempIterator; tempIterator != container.end(); ++tempIterator){
        subsetBList.push_front(*tempIterator);
    }
    subsetBList.sort([](Data& obj1, Data& obj2){
        return obj1.y<obj2.y;
    });
    // Resizing list till subsetA
    container.resize(std::distance(container.begin(),iterator));
    
    // Will add data of subsetB list at the end of subsetA in main list
    for(auto it = subsetBList.begin();it!=subsetBList.end();it++){
        container.push_back(*it);
    }
    
    //return subsetB start index
    return bStartIndex;
}

// Accepts callback as a parameter and applies it to elements of subset C. Callback takes ```Data&``` as parameter and returns no result
template<typename T>
void callbackOnSubsetC(T& container,int bStartIndex, int subsetCLength, std::function<void(Data&)> callback){
    auto it = container.begin()+bStartIndex;
    // Finding subsetB length
    int subsetBLength = std::distance(it, container.end());
    if(subsetCLength>subsetBLength){
        std::cout<<"subsetC length should not be greater then subsetB length"<<std::endl;
        return;
    }
    // Rotating foreach loop to perform callback on all the elements of subsetC only
    std::for_each(it, it+subsetCLength, callback);
}

// Template specialization for forward_list
template<>
void callbackOnSubsetC(std::forward_list<Data>& container, int bStartIndex, int subsetCLength, std::function<void(Data&)> callback){
    auto it = std::next(container.begin(), bStartIndex);
    // Finding subsetB length
    int subsetBLength = std::distance(it, container.end());
    if(subsetCLength>subsetBLength){
        std::cout<<"subsetC length should not be greater then subsetB length"<<std::endl;
        return;
    }
    // As we can not jump forward iterator randomly so used std::next to forward the iterator
    auto it2 = std::next(it, subsetCLength);
    // Rotating foreach loop to perform callback on all the elements of subsetC only
    std::for_each(it, it2, callback);
}

// Template specialization for list
template<>
void callbackOnSubsetC(std::list<Data>& container, int bStartIndex, int subsetCLength, std::function<void(Data&)> callback){
    auto it = std::next(container.begin(), bStartIndex);
    // Finding subsetB length
    int subsetBLength = std::distance(it, container.end());
    if(subsetCLength>subsetBLength){
        std::cout<<"subsetC length should not be greater then subsetB length"<<std::endl;
        return;
    }
    // As we can not jump forward iterator randomly so used std::next to forward the iterator
    auto it2 = std::next(it, subsetCLength);
    // Rotating foreach loop to perform callback on all the elements of subsetC only
    std::for_each(it, it2, callback);
}

// Callback function which is called for all elements of subsetC
void callback(Data& obj)
{
    std::cout<<unsigned(obj.x)<<"-"<<unsigned(obj.y)<<"  ";
}