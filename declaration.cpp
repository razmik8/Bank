#include <iostream>
#include "myheader.hpp"
account::account() {
    name = "no name";
    account_number = 0;
    balance = 0;
}
void account::set_name(const std::string Name){
    name = Name;
}
void account::set_balance(int Balance){
    balance = Balance;
}
void account::set_ac_number(int number){
    account_number = number;
}
std::string account::get_name()const {
    return name;
}
int account::get_balance() const {
    return balance;
}
int account::get_ac_number () const{
    return account_number;
}
void account::deposit(int m){
    balance+=m;
}
void account::withdraw(int m){
    balance-=m;
}

bank::bank(){
    capacity = 2;
    size = 0;
    arr_account = new account[capacity];
}
bank::~bank(){
	delete[] arr_account;
}
void bank::create_account(const std::string& Name, int Account_number){
    if(size == capacity){
        capacity *= 2;
        account* ptr = arr_account;
        arr_account = new account[capacity];
        for(int i = 0; i < size; i++){
            *(arr_account + i) = *(ptr + i);
        }
        delete[] ptr;
        ptr = nullptr;
	}
    arr_account[size].set_name(Name);
    arr_account[size].set_ac_number(Account_number);
    size++;
    
}
void bank::deposit(int number,int money){
    for(int i = 0;i < size;i++){
		if(arr_account[i].get_ac_number() == number){
			arr_account[i].deposit(money);
			return;
		}
	}
	std::cout << "Not found." << std::endl;
}
void bank::withdraw(int number,int money){
    for(int i = 0;i < size;i++){
		if(arr_account[i].get_ac_number() == number){
			arr_account[i].withdraw(money);
			return;
		}
	}
	std::cout << "Not found." << std::endl;
}
void bank::displayinfo(){
    for(int i = 0;i < size;i++){
        std::cout << i << ')' << std::endl;
        std::cout << "Name: "<< arr_account[i].get_name() << std::endl;
        std::cout << "Account number: "<< arr_account[i].get_ac_number() << std::endl;
        std::cout << "Balance: " << arr_account[i].get_balance() << std::endl;
    }
}
