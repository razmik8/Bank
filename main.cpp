#include <iostream>
#include "myheader.hpp"
int main(){
	bank a;
    a.create_account("Valod",1234);
	a.deposit(1234,1000);
	a.create_account("Bob",1122);
	a.create_account("Bil",1133);
	a.withdraw(1234,500);
	a.deposit(1133,500);
	a.displayinfo();
    return 0;
}
