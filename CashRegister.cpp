#include "CashRegister.h"
using namespace std;
void printChange(string change, int count){
	cout<<change << " - " << count<< "\t";
}
		bool verifyTendered(double amount, double tendered, bool &notEnough){
			if(tendered < amount){
					cout<<"The amount tendered: "
						  <<tendered << " is not enough. \n" ;
							notEnough = true;
			}
		  else if(tendered == amount){
				cout<<"The  amount tendered is exact. No change.\n";
			}
			else {
				cout<<"... Working returning change: $ ";
				cout<<tendered - amount<< "\n";
				}
				return true;
		}
		 void changeMaker(double itemPrice, double amountTendered){
			static const int HUNDRED$ = 10000;
		 	static const int FIFTY$ = 5000;
		 	static const int TWENTY$ = 2000;
		 	static const int TEN$ = 1000;
		 	static const int FIVE$ = 500;
		 	static const int  ONE$ = 100;
		 	static const int QUARTERS = 25;
		 	static const int DIMES = 10;
		 	static const int NICKELS = 5;
		 	static const int PENNIES = 1;

			double converted = amountTendered * 100;
			double convertedItemPrice = itemPrice * 100;
			double changeReturnedInPennies = converted - convertedItemPrice;
			double count = 0;
			// 100
			count = (int) changeReturnedInPennies / HUNDRED$;
			changeReturnedInPennies -= (count * HUNDRED$);
			printChange("$100", count);
			//50
			count = (int) changeReturnedInPennies / FIFTY$;
			changeReturnedInPennies -= (count * FIFTY$);
			printChange("$50", count);
			//20
			count = (int) changeReturnedInPennies / TWENTY$;
			changeReturnedInPennies -= (count * TWENTY$);
			printChange("$20", count);
			//10
			count = (int) changeReturnedInPennies / TEN$;
			changeReturnedInPennies -= (count * TEN$);
			printChange("$10", count);
			//5
			count = (int) changeReturnedInPennies / FIVE$;
			changeReturnedInPennies -= (count * FIVE$);
			printChange("$5", count);
			//1
			count = (int) changeReturnedInPennies / ONE$;
			changeReturnedInPennies -= (count * ONE$);
			printChange("$1", count);
			//.25
			count = (int) changeReturnedInPennies / QUARTERS;
			changeReturnedInPennies -= (count * QUARTERS);
			printChange("$0.25", count);
			//.10
			count = (int) changeReturnedInPennies / DIMES;
			changeReturnedInPennies -= (count * DIMES);
			printChange("$0.10", count);
			//.5
			count = (int) changeReturnedInPennies / NICKELS;
			changeReturnedInPennies -= (count * NICKELS);
			printChange("$.5", count);

			//.1
			count = (int) changeReturnedInPennies / PENNIES;
			changeReturnedInPennies -= (count * PENNIES);
			printChange("$.1", count);
		}
		int main(){

				 bool notEnough = false;
		     bool nextPurchase = false;

				double itemPrice = 0, customerTendered = 0;

					do{
							cout<<"=========================================\n";
							cout<<"What is the price of the item: "<<"\n >> ";
							cin>> itemPrice;
							cout<<"\n Enter your amount tendered:  \n";
							cin>> customerTendered;
							cout<<customerTendered - itemPrice << "\n";
							verifyTendered(itemPrice, customerTendered, notEnough);
							if(notEnough){nextPurchase = true;continue;}
							changeMaker(itemPrice, customerTendered);

					}while(nextPurchase);
		}
