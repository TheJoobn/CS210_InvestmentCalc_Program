// AUTHOR - Jaden B Knuston.
// DATE -	3/28/23		(11:36)PM
//			3/29/23		(10:13)AM
//			3/31/23		(11:36)AM
//			4/1/23		(10:03)AM
//			5/2/23		(5:18)PM Final Turning
/* DESCRIPTION:	This program asks the user whether they want their monthly deposits added at the beginning or 
end of the month. It then gets multiple inputs from the user such as time length, interest rates, monthly deposits, 
and initicial investment. It calculates the yearly end balance, and the yearly interest total. It then returns lines 
for each year containing the total ballance and yearly interest earned.

/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


/*-------------------------------------------------------*/
//Get filled with input from user
float initialInvestment;	//Initial user investment
float annualInterest;		//Yealy interest percentage
float monthlyDeposit;		//Monthly user deposit
float years;				//Total years of investment
float months;				//Months calculated from number of years 

//Keeps track of the totals
float totalAmt;				//Total Balance Amount
float interestTotalAmt;		//Total Interest Earned
float yearTotalInt;			//Yearly Interest Total

//Used for continuing or ending the program
int playAgainInput;			//Inputs 1 or 2, 1 continues program, 2 quits using boolean value
bool playAgainResult = true;//The while loop continues until this becomes false
char beginOrEnd;			//Inputs user if they want their monthly deposit contributed at the beginning or end of the month


/*-------------------------------------------------------*/
/* FUNCTION DECLARATIONS */

// Display Functions
void initialDisplay();		//Outputs greeting and question preview.
void inputDisplay();		//Outputs the questions and recieves input from user.

void displayDecision();		//Chooses which displays below are needed
void noDepositTitle();		//Outputs Without-Deposit Title
void noDepositDisplay();	//Outputs Without-Deposit Info

void depositTitle();		//Outputs With-Deposit Title
void depositDisplayBegin();//Outputs With-Deposits Info for beginning of the month deposits
void depositDisplayEnd();	//Outputs With-Deposits Info for end of the month deposits

void playAgainFunc();		//Inputs if user wants to re-run the program or quit.

/*NEEDED BY RUBRIC*/
double balanceWithMonthlyDeposit(double, double, double, int); //Calculates With Deposit Totals
double calculateBalanceWithoutMonthlyDeposit(double, double, int); //Calculates Without Deposit Totals
void printDetails(int, double, double); //Prints Info and Totals on Individual Lines






/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------*/
/*START MAIN*/ /*START MAIN*/ /*START MAIN*/
int main() {
	cout << "STATUS: PROJECT 2 START" << endl;
	/*-------------------------------------------------------*/
	//Displays the questions the first time with no input
	initialDisplay();

	/*-------------------------------------------------------*/
	//Loop continues until user enters "2" and changes the boolean to false.
	while (playAgainResult == true) {

		/*-------------------------------------------------------*/
		//Outputs Questions and Inputs Info From User
		inputDisplay();

		/*-------------------------------------------------------*/
		//Decides which output diplay to use depending on user input
		displayDecision();

		/*-------------------------------------------------------*/
		//Asks the user if they want to re-run the program
		playAgainFunc(); //Changes playAgainResult to false to quit porgram.

		/*-------------------------------------------------------*/
	} /*END While*/
	cout << "\n" << "PROJECT:2 END" << endl;
	system("PAUSE");
} /*END MAIN*/ /*END MAIN*/ /*END MAIN*/
/*--------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/







/*START FUNCTIONS*/ /*START FUNCTIONS*/ /*START FUNCTIONS*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* OUTPUTS: Greeting and Instructions */
void initialDisplay() {

	//Greetings Message
	cout << "Welcome to Joob's Investment Calculator Program." << endl;
	cout << endl;

	//Output Pre-Questions To User
	cout << "Be prepared to answer the following questions:" << endl;
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	//User Must Press Any Button To Continue
	system("PAUSE");
	cout << endl;
	cout << endl;
} /*END*/


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* OUTPUTS: different questions and INPUTS from user. */
void inputDisplay() {

	//Reset variable for multiple instances
	beginOrEnd = ' ';

	//Inputs if user wants beginning of the month or end of the month deposits by typing B or E
	while (beginOrEnd != 'B' && beginOrEnd != 'E') {
		cout << "Do you want to contribute your monthly" << endl;
		cout << "deposit at the beginning or end of the month? " << endl;
		cout << "Please enter B for beginning or E for End: ";
		cin >> beginOrEnd; //Inputs B for beginning or E for ending, this helps choose calulation method
		cout << endl;
	}/*END*/


	//Output Questions To User, Inputs Answers
	cout << "********************************\n";
	cout << "********** Data Input **********\n";
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment; // Input Starting Investment
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit; // Input Monthly Deposit
	cout << "Annual Interest: %";
	cin >> annualInterest; // Input Annual Interest
	cout << "Number of years: ";
	cin >> years; // Input The Amount Of Years
	months = years * 12; // Gets the number of months from years.

	//User Must Press Any Button To Continue
	system("PAUSE");

	//Total Amount is set to the Initital Investment
	totalAmt = initialInvestment;
} /*END*/


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* Outputs A line containing the year, yearly balance, and the interest earned.*/
void printDetails(int year, double yearEndBalance, double interestEarned) {

	cout << year << "\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t\t$" << interestEarned << "\n";
} /*END*/


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/






/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
//Chooses which display the user will see depending on input choices.
void displayDecision() {
	
	//If user typed is 0 for monthly deposits, Outputs WITHOUT Monthly Deposits.
	if (monthlyDeposit == 0) {
		cout << endl;
		cout << "SPECIAL CASE: $0 Monthly Deposit";

		//Outputs info WITHOUT monthly deposits when 0 is entered for monthly deposit
		noDepositTitle();
		noDepositDisplay();
	} /*END If*/

	/*-------------------------------------------------------*/
	//Otherwise Outputs WITHOUT Monthly Deposits.
	else {
		//Outputs Info WITHOUT monthly deposits
		noDepositTitle();
		noDepositDisplay();

		//Outputs Info WITH monthly deposits
		depositTitle();

		//depositDisplayBegin();
		//depositDisplayEnd();

		//Outputs calculations with monthly deposits contibuted at the beginning of the month
		if (beginOrEnd == 'B') {
			depositDisplayBegin();

		}/*END*/
		//Outputs calculations with monthly deposits contibuted at the end of the month
		else if (beginOrEnd == 'E') {
			depositDisplayEnd();
		}/*END*/
	} /*END Else*/
}/*END*/ 


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/





/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* OUTPUTS: Title for WITHOUT-deposits info*/
void noDepositTitle() {

	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "=======================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "-----------------------------------------------------------------------\n";
} /*END*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* Calculated and outputs the results of the calculations WITHOUT-Deposits */
void noDepositDisplay() {

	//Set total amount to initial investment to be updated
	totalAmt = initialInvestment;

	//Display year data with monthly deposits
	for (int i = 0; i < years; ++i) {
		//Set yearly interest to zero at the start of the year
		yearTotalInt = 0;
		for (int j = 0; j < 12; ++j) {

			//Calculate monthly interest
			interestTotalAmt = (totalAmt) * ((annualInterest / 100) / 12);

			//Calculates yearly total interest
			yearTotalInt = yearTotalInt + interestTotalAmt;

			//Calculate monthly balance total
			totalAmt = totalAmt + interestTotalAmt;

		} /*END*/
		//Uses print function to output calculation results
		printDetails(i + 1, totalAmt, yearTotalInt);
	} /*END*/
} /*END*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/







/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* OUTPUTS: Title for WITH-deposits info*/
void depositTitle() {

	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "=======================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "-----------------------------------------------------------------------\n";
} /*END*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* Calculates and Outputs the results for beginning of the month deposits*/
void depositDisplayBegin() {
	//Set total amount to initial investment to be updated
	totalAmt = initialInvestment;

	//Display year data with monthly deposits
	for (int i = 0; i < years; ++i) {
		//Set yearly interest to zero at the start of the year
		yearTotalInt = 0;
		for (int j = 0; j < 12; ++j) {


			//Calculate monthly interest
			interestTotalAmt = (totalAmt + monthlyDeposit) * ((annualInterest / 100) / 12);

			//Calculates yearly total interest
			yearTotalInt = yearTotalInt + interestTotalAmt;

			//Calculate monthly balance total
			totalAmt = totalAmt + monthlyDeposit + interestTotalAmt;


		} /*END*/
		//Uses print function to output calculation results
		printDetails(i + 1, totalAmt, yearTotalInt);

	} /*END*/
}/*END*/


/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* Calculates and Outputs the results for end of the month deposits*/
void depositDisplayEnd() {

	//Set total amount to initial investment to be updated
	totalAmt = initialInvestment;

	//Display year data with monthly deposits
	for (int i = 0; i < years; ++i) {
		//Set yearly interest to zero at the start of the year
		yearTotalInt = 0;
		for (int j = 0; j < 12; ++j) {

			//Skips the first round
			if (j == 0) {

				//Calculate monthly interest
				interestTotalAmt = (totalAmt) * ((annualInterest / 100) / 12);

				//Calculate monthly balance total
				totalAmt = totalAmt + interestTotalAmt;

				//Calculates yearly total interest
				yearTotalInt = yearTotalInt + interestTotalAmt;

			}/*END*/

			else {

				//Calculate monthly interest
				interestTotalAmt = (totalAmt + monthlyDeposit) * ((annualInterest / 100) / 12);

				//Calculates yearly total interest
				yearTotalInt = yearTotalInt + interestTotalAmt;

				//Calculate monthly balance total
				totalAmt = totalAmt + monthlyDeposit + interestTotalAmt;

			}/*END*/

		} /*END*/
		//Uses print function to output calculation results
		totalAmt += monthlyDeposit;
		printDetails(i + 1, totalAmt, yearTotalInt);

	} /*END*/
} /*END*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/









/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/* Asks the user if they want to play again, program terminates if 2 is typed in */
void playAgainFunc() {

	bool i = false;
	while (i == false) { // Output options to user: 1 or 2
		cout << "\n\nWould you like to start again?\n";
		cout << "==============================================================\n";
		cout << "Please Enter:\t\t1\t\t\t2\n";
		cout << "--------------------------------------------------------------\n";
		cout << "            \tReruns Program\t\t Quits The Program\n";
		cout << "--------------------------------------------------------------\n";

		/*-------------------------------------------------------*/
		//Receives input to continue or quit program
		cin >> playAgainInput;
		if (playAgainInput == 1) { // 1 = Continue
			playAgainResult = true;
			i = true;
		} /*END*/

		/*-------------------------------------------------------*/
		else if (playAgainInput == 2) { // 2 = quit
			playAgainResult = false;
			i = true;
		} /*END*/

		/*-------------------------------------------------------*/
		else {
			cin >> playAgainInput; // if input is invalid, receives input again
		} /*END*/

	/*-------------------------------------------------------*/
	} /*END*/
	return;
} /*END*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/




/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
/*END FUNCTIONS*/ /*END FUNCTIONS*/ /*END FUNCTIONS*/