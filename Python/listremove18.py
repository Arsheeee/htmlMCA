a = list(map(int, input("Enter the list elements separated by space: ").split()))

for num in a:
    if num % 2 != 0:
        print(num)
