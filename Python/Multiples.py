num = int(input("Enter a number : "))
n = int(input("Enter the number of multiples : "))

print(f"First {n} multiples of {num} are : ")
for i in range(1, n + 1):
    print(num * i)