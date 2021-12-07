#pragma once
#include <utility>

template <typename T>
void auSwap(T &x, T &y){
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

template <typename BidirectionalIter>
void auReverse(BidirectionalIter *beg, BidirectionalIter *end){
    for(;;){
        if(beg == end){
            break;
        }
        --end;

        if(beg == end){
            break;
        }

        int t = *beg;
        *beg = *end;
        *end = t;

        ++beg;
    }
}

template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Key &key){
    while(beg != end){
        if(*beg == key){
            return beg;
        }
        ++beg;
    }

    return beg;
}

template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auFindIf (ForwardIter beg, ForwardIter end, UnaryPredicate predicate){
    while(beg != end){
        if(predicate(*beg)){
            return beg;
        }
        ++beg;
    }

    return beg;
}