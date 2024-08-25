#include<vector>
#include<array>
#include<deque>
#include<forward_list>
#include<list>

#include "containre_reordering.h"

// test_case: all the sequence container tested at once 
int main(){    
    std::cout<<"\n-------------------vector--------------------"<<std::endl;
    std::vector<Data> vec;
    vec.push_back(Data{78,69});
    vec.push_back(Data{12,6});
    vec.push_back(Data{2,45});
    vec.push_back(Data{100,30});
    vec.push_back(Data{25,51});
    vec.push_back(Data{45,12});
    vec.push_back(Data{18,85});    
    //1
    reorderSubsetAB<std::vector<Data>>(vec);
    printData<std::vector<Data>>(vec);    
    //2
    std::uint8_t x_threshold_v = 20;
    int bStartIndex_v = formSubsetC<std::vector<Data>>(vec, x_threshold_v);
    printData<std::vector<Data>>(vec);    
    //3
    int subsetCLength_v = 3;
    callbackOnSubsetC<std::vector<Data>>(vec, bStartIndex_v, subsetCLength_v, callback);
    
    // test_case: passing n for subsetC length more then subsetB length
    std::cout<<"\n-------------------array--------------------"<<std::endl;

    std::array<Data, 5> arr = {Data{11,50}, Data{1,54}, Data{10,57}, Data{12,51}, Data{33,51}};    
    //1
    reorderSubsetAB<std::array<Data, 5>>(arr);
    printData<std::array<Data, 5>>(arr);    
    //2
    std::uint8_t x_threshold_a = 20;
    int bStartIndex_a = formSubsetC<std::array<Data, 5>>(arr, x_threshold_a);
    printData<std::array<Data, 5>>(arr);    
    //3
    int subsetCLength_a = 8;
    callbackOnSubsetC<std::array<Data, 5>>(arr, bStartIndex_a, subsetCLength_a, callback);

    // test_case: didn't keep x value for any element less x_throshold so, subsetB itself not able to form
    std::cout<<"\n-------------------deque--------------------"<<std::endl;

    std::deque<Data> deque;
    deque.push_back(Data{78,69});
    deque.push_back(Data{122,6});
    deque.push_back(Data{29,45});
    deque.push_back(Data{100,30});
    deque.push_back(Data{25,51});
    deque.push_back(Data{45,12});
    deque.push_back(Data{66,85});    
    //1
    reorderSubsetAB<std::deque<Data>>(deque);
    printData<std::deque<Data>>(deque);    
    //2
    std::uint8_t x_threshold_d = 20;
    int bStartIndex_d = formSubsetC<std::deque<Data>>(deque, x_threshold_d);
    printData<std::deque<Data>>(deque);    
    //3
    int subsetCLength_d = 3;
    callbackOnSubsetC<std::deque<Data>>(deque, bStartIndex_d, subsetCLength_d, callback);

    // test_case: didn't keep x value for any element greater then x_throshold so, subsetA itself not able to form
    std::cout<<"\n-------------------forward_list--------------------"<<std::endl;

    std::forward_list<Data> flist;
    flist.push_front(Data{78,69});
    flist.push_front(Data{12,6});
    flist.push_front(Data{2,45});
    flist.push_front(Data{99,30});
    flist.push_front(Data{25,51});
    flist.push_front(Data{45,12});
    flist.push_front(Data{18,85});    
    //1
    reorderSubsetAB<std::forward_list<Data>>(flist);
    printData<std::forward_list<Data>>(flist);    
    //2
    std::uint8_t x_threshold_f = 100;
    int bStartIndex_f = formSubsetC<std::forward_list<Data>>(flist, x_threshold_f);
    printData<std::forward_list<Data>>(flist);    
    //3
    int subsetCLength_f = 2;
    callbackOnSubsetC<std::forward_list<Data>>(flist, bStartIndex_f, subsetCLength_f, callback);

    std::cout<<"\n-------------------list--------------------"<<std::endl;

    std::list<Data> list;
    list.push_front(Data{78,69});
    list.push_front(Data{12,6});
    list.push_front(Data{2,45});
    list.push_front(Data{100,30});
    list.push_front(Data{25,51});
    list.push_front(Data{45,12});
    list.push_front(Data{18,85});    
    //1
    reorderSubsetAB<std::list<Data>>(list);
    printData<std::list<Data>>(list);    
    //2
    std::uint8_t x_threshold_l = 20;
    int bStartIndex_l = formSubsetC<std::list<Data>>(list, x_threshold_l);
    printData<std::list<Data>>(list);    
    //3
    int subsetCLength_l = 2;
    callbackOnSubsetC<std::list<Data>>(list, bStartIndex_l, subsetCLength_l, callback);    
}