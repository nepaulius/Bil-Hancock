#ifndef BLOKC_CHAIN_H_INCLUDED
#define BLOKC_CHAIN_H_INCLUDED

#include <vector>


class Blockchain{
public:

std::vector<Block> chain;
Block create_genesis_block();
int addBlock(std::vector<Transaction_data> data,int sec_counter,int block_id, std::vector<int> & vec_id);
void print_block();
void check_trans_id(std::vector<Transaction_data> data);
int timer_sec;


};



#endif // BLOKC_CHAIN_H_INCLUDED
