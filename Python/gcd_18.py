import math
a = int(input("Enter a number : "))
b = int(input("Enter the second number : "))

# print("GCD is : ",math.gcd(a,b))
if (a<b):
    k=a
else:
    k=b
for i in range(1,k+1):
    if(a%i==0 and b%i==0):
        gcd=i
print("gcd is:",gcd)


     
      