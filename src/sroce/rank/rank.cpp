#include "rank.hpp"

rank callrankback(sroce sc) 
{
    if (sc.acc == rankACCList::SSS)
        return rank(rkList::SSS);
    else if (sc.acc >= rankACCList::SS)
        return rank(rkList::SS);
    else if (sc.acc >= rankACCList::S)
        return rank(rkList::S);
    else if (sc.acc >= rankACCList::AAA)
        return rank(rkList::AAA);
    else if (sc.acc >= rankACCList::AA)
        return rank(rkList::AA);
    else if (sc.acc >= rankACCList::A)
        return rank(rkList::A);
    else if (sc.acc >= rankACCList::B)
        return rank(rkList::B);
    else if (sc.acc >= rankACCList::C)
        return rank(rkList::C);
    else if (sc.acc >= rankACCList::D)
        return rank(rkList::D);
    else 
    {
        return rank(rkList::F);
    }
};

rank::rank(sroce& sc)
{
    sc.acc = (((((sc.max * 101.0) + (sc.pf * 100.9) + (sc.gr * 80.0) + (sc.gd * 50.0) + (sc.bd * 10.0)) / 101.0) / sc.ttl) * 101.0);
    this->bsc = sc;
};
