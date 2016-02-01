#include <stdio.h>
#include <math.h>

double getLoanAmount(void);
double getIntrestRate(void);
int getTerm(void);
double monthlyIntrest(double);
double  monthlyPayment(double, double, int);
void amortizationSchedule(int, double, double, double, double);

int main() {
    double  principle, intrestRate, mIntrest, mPayment;
    int term;
    
    principle= getLoanAmount();
    intrestRate= getIntrestRate();
    term= getTerm();
    mIntrest= monthlyIntrest(intrestRate);
    mPayment= monthlyPayment(mIntrest, principle, term);
    amortizationSchedule(term, principle, mIntrest, mPayment, intrestRate);
    
    return 0;
}

double getLoanAmount(void)  {
    double lAmount;
    
    printf("Enter A Loan Amount: ");
    scanf("%lf", &lAmount);
    
    return lAmount;
}

double getIntrestRate(void) {
    double iRate;
    
    printf(("Enter Intrest Rate: "));
    scanf("%lf", &iRate);
    
    return iRate;
}

int getTerm(void)   {
    int term;
    
    printf(("Enter Loan Term: "));
    scanf("%d", &term);
    
    return term;
}

double monthlyIntrest(double intrestRate) {
    double miRate;
    
    miRate= ((intrestRate/12)/100);
    
    return miRate;
}

double monthlyPayment(double mInterest, double principle, int term) {
    double mPay;
    int mTerm;
    
    mTerm= term*12;
    
    mPay= ((mInterest*principle)*pow(1+mInterest, mTerm))/(pow(1+mInterest,mTerm)-1);
    
    return mPay;
}

void amortizationSchedule(int term, double principle, double mIntrest, double mPayment, double intrestRate) {
    int i=0;
    double balance= principle;
    double iPaymnt= 0, pPaymnt= 0;
    double iPayed= 0,pPayed= 0;

    printf("\n\n\nLoan Amount: %.2lf\n", principle);
    printf("Term: %d\n", term);
    printf("Rate: %.2lf\n", intrestRate);
	printf("\nMonthly Payment: %.2lf\n", mPayment);
    
    //table
    printf("%-7s %-15s %-17s %-17s %-15s %-15s\n", "Month", "Balance", "Interest Payment", "Principle Payment", "Intrest Paid", "Principle Paid");
    printf("%-7s %-15s %-17s %-17s %-15s %-15s\n", "-----", "----------", "----------------", "-----------------", "------------", "--------------");
    printf("%-7d %10.2lf %17.2lf %17.2lf %15.2lf %15.2lf\n", i, balance, iPaymnt, pPaymnt, iPayed, pPayed);
	term*=12;
	//loop
    for(i=1; i<=term; i++){
        
        iPaymnt= balance*mIntrest;
        pPaymnt= mPayment-iPaymnt;
        balance-=pPaymnt;
        iPayed+=iPaymnt;
        pPayed+=pPaymnt;
        
        
        printf("%-7d %10.2lf %17.2lf %17.2lf %15.2lf %15.2lf\n", i, balance, iPaymnt, pPaymnt, iPayed, pPayed);
	}

	printf("\n\nWith a principal loan amount of $%.2lf at an interest rate of %.2lf, you will pay $%.2lf in intrest by the end of the loan term. Thats a total Payment of $%.2lf.\n", principle, intrestRate, iPayed, iPayed+pPayed);
}

//add an error message for letter or comma entries during input.
//make program continue until user tells it to stop. (do while loop).
//creat diffrent views other than monthly break down (for example:yearly, 5-6years,monthly with yearly break downs)
//