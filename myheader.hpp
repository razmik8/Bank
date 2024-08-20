#include <string>
#ifndef header
#define header
class account {
    private:
        std::string name;
        int account_number;
        int balance;
    public:
        account();
        account(const account& a) = delete;

        std::string get_name()const;
        int get_ac_number()const;
        int get_balance()const;

        void set_name(std::string);
        void set_ac_number(int);
        void set_balance(int);
        
        void deposit(int);
        void withdraw(int);
};
class bank {
    private:
        int capacity;
        int size;
        account*arr_account;
    public:
        bank();
        ~bank();
        bank(const bank& a) = delete;
        bank& operator=(const bank& a) = delete;

        void create_account(const std::string&,int);
        void deposit(int,int);
        void withdraw(int,int);
        void displayinfo();
};
#endif
