#include <stdio.h>
#include <string>
#include <bitset>
#include <sstream>
#include <vector>
#include <iomanip>

#include "Block.h"
#include "Transaction_data.h"
#include "Kodavimas.cpp"


Block::Block(int idx,std::vector<Transaction_data> full, std::string prev_hash,std::string merkel_root)
{
    index=idx;
    merkel=merkel_root;
    pilnas=full;
    previous_hash=prev_hash;
    block_hash = generate_hash();

}

int Block::get_index()
{
return index;
}



std::string Block::generate_hash()
{
    std::string tarpinis;

    for(int i=0;i<pilnas.size();i++)
    {
        tarpinis+=kardinalus_pokyciai(std::to_string(pilnas[i].amount)+pilnas[i].receive_key+pilnas[i].send_key+std::to_string(pilnas[i].timestamp));
    }

    std::string tdata_hash=kardinalus_pokyciai(tarpinis);
    std::string prev_hash=kardinalus_pokyciai(previous_hash);
    std::string abu=kardinalus_pokyciai(tdata_hash+prev_hash);



    return abu;
}


std::string Block::get_hash()
{
return block_hash;
}



std::string Block::get_previous_hash()
{
return previous_hash;
}


bool Block::is_hash_valid()
{

return generate_hash()== get_hash();
}
