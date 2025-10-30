class BankAccount :
    def __init__(self,name,balance = 0):
        self.name = name
        self.balance = balance
    def deposit(self , amount):
        self.balance+=amount
        print("Deposited Rs",amount) 
        print("Balance is now Rs",self.balance)
    def withdraw(self,amount):
        if amount > self.balance:
            print("Not enough balance.")
        else:
            self.balance-= amount
            print("Withdraw Rs",amount)
            print("Balance is now Rs",self.balance)

    def get_balance(self):
        print ("Balance : Rs",self.balance)

name=input("Enter your name : ")
balance=float(input("Enter starting balance : "))                       
account=BankAccount(name,balance)
while True :
    print("Choose Operation" CH)
    Choice = input("deposit,withdraw,balance,exit:").lower()
    if Choice == "deposit":
        amount = float(input("Amount to Deposit : "))
        account.deposit(amount)
    elif Choice == "withdraw":
        amount = float(input("Amount to Withdraw : "))
        account.withdraw(amount)
    elif Choice == "balance":
        account.get_balance()
    elif Choice == "exit":
        print("Done")
        break
    else : 
        print("Invalid Choice")        