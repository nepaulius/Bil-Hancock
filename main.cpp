#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>


#include "Transaction_data.h"
#include "Block.h"
#include "Blokc_chain.h"

#include "Block_chain.cpp"

#include "Block.cpp"
#include "Vartotojas.cpp"



int main()
{

    std::vector<User> visi_vart=generate_vartot();

    std::vector<Transaction_data>vartot_transac=generate_vartot_transac(visi_vart);

    std::vector<Transaction_data>gut_transactions=find_only_gut_transactions(vartot_transac,visi_vart);

    Blocks_maker(gut_transactions);




    return 0;
}
