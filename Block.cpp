#include <stdio.h>
#include <string>
#include <bitset>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>

#include "Block.h"
#include "Transaction_data.h"



Block::Block(std::string hashblock,std::string hashprevious,std::string merkel_,long long int  start_,std::vector<Transaction_data> full, int nonce_,std::string default_target_,std::string version_)
{
    block_hash=hashblock;
    previous_hash=hashprevious;
    merkel=merkel_;
    start=start_;
    data=full;
    nonce=nonce_;
    default_target=default_target_;
    version=version_;
}

