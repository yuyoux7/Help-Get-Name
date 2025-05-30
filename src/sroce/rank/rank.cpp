#include "rank.hpp"

auto callrankback = [] (sroce sc) 
{
    if (sc.acc == rank::SSS && sc.sroce == sroce::SSS)
    if (sc.acc >= rank::SS && sc.sroce >= sroce::SS)
    if (sc.acc >= rank::S && sc.sroce >= sroce::SS)
    if (sc.acc >= rank::S && sc.sroce >= sroce::S)
    if (sc.acc >= rank::A && sc.sroce >= sroce::A)
    if (sc.acc >= rank::B && sc.sroce >= sroce::B)
    if (sc.acc >= rank::C && sc.sroce >= sroce::C)
    if (sc.acc >= rank::D && sc.sroce >= sroce::D)
    else 
    {
        return rank(rank::F);
    }
};