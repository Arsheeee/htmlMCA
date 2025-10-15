S1=input("Enter first string :")
S2=input("Enter second string :")

newS1 = S2[0] + S1[1:]
newS2 = S1[0] + S2[1:]

result = newS1 + newS2
print("New String : ",result)