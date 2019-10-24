#ifndef BLOKC_CHAIN_H_INCLUDED
#define BLOKC_CHAIN_H_INCLUDED

#include <vector>

struct Nonce_counter
{
    std::vector<int>nonce_counter{0,0,0,0,0};
    void set_nonce_counter(int block_id,int nonce)
    {
        nonce_counter[block_id]=nonce;
    }
    int get_nonce_counter(int block_id)
    {
        return nonce_counter[block_id];
    }
};
class Blockchain{
public:

std::vector<Block> chain;
Block create_genesis_block();
int addBlock(std::vector<Transaction_data> data,int sec_counter,int block_id, Nonce_counter & ID);
void print_block();
void check_trans_id(Transaction_data data);
int timer_sec;


};



#endif // BLOKC_CHAIN_H_INCLUDED
