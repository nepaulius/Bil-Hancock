#ifndef TRANSACTION_DATA_H_INCLUDED
#define TRANSACTION_DATA_H_INCLUDED

struct Transaction_data{

    double amount;
    std::string send_key;
    std::string receive_key;
    time_t timestamp;
    std::string thash;

    Transaction_data(){};

    Transaction_data(double amt,std::string sender,std::string receiver,time_t time,std::string th)
    {
        amount=amt;
        send_key=sender;
        receive_key=receiver;
        timestamp=time;
        thash=th;
    };

};


#endif // TRANSACTION_DATA_H_INCLUDED
