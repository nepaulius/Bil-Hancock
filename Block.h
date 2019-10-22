#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "Transaction_data.h"


class Block{
public:
    std::string block_hash;
    std::string previous_hash;
    std::string merkel;
    time_t start;
    std::vector<Transaction_data> data;
    int nonce;
    std::string default_target;
    Block(std::string hashblock,std::string hashprevious,std::string merkel_,time_t start_,std::vector<Transaction_data> full, int nonce_,std::string default_target_);



};

#endif // BLOCK_H_INCLUDED
