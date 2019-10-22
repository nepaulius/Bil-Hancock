#include <stdio.h>
#include <string>
#include <bitset>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>

#include "Block.h"
#include "Transaction_data.h"



Block::Block(std::string hashblock,std::string hashprevious,std::string merkel_,time_t start_,std::vector<Transaction_data> full, int nonce_,std::string default_target_)
{
    block_hash=hashblock;
    previous_hash=hashprevious;
    merkel=merkel_;
    start=start_;
    data=full;
    nonce=nonce_;
    default_target=default_target_;
}

