#ifndef BLOKC_CHAIN_H_INCLUDED
#define BLOKC_CHAIN_H_INCLUDED

#include <vector>



class Blockchain{
    private:
        Block create_genesis_block();
        std::vector<Block> chain;

    public:
        Blockchain();

        std::vector<Block> get_chain();
        Block *get_latest_block();
        bool is_chain_valid();
        void addBlock(std::vector<Transaction_data> op);
        void print_chain();



};


#endif // BLOKC_CHAIN_H_INCLUDED
