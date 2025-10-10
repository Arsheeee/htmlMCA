a = int(input("Enter a number : "))
b = int(input("Enter another number : "))
c = int(input("Enter one more number : "))

if a>=b and a>=c:
    print("The largest number is : ",a)
if b>=a and b>=c:
    print("The largest  number is : ",b)
else :
    print("The largest  number is : ",c)

