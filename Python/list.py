print("Positive Number")
a = [-1,2,-3,4,5,-6,7]
for num in a:
    if (num > 0):
        print(num)

print("Squre of Numbers")
limit = int(input("enter the limit : "))

for num in range(1, limit + 1):
    print(num * num)

print("Vowels")
word = list(input("enter a word : "))
print("Vowels of the given word are")

for s in word:
    if s in ('a' , 'e' , 'i' , 'o' , 'u'):
        print(s)







        
