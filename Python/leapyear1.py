print("Leap Years")
a=int(input("Enter the year : "))
if (a < 2025): 
  print("Leap years from the given year to the curent year")
for num in range (a , 2025):
    if ( num % 4 == 0 and num % 100 !=0 or num % 400 ==0) :
        print (f"{num} is a leap year")
else :
    print("Leap years from the current year to the given year")
for num in range (2025 , a):
    if ( num % 4 == 0 and num % 100 !=0 or num % 400 ==0) :
        print (f"{num} is a leap year")       

    