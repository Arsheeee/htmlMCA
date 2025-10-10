num1 = float(input("Enter a number : "))
op = input("Enter a operation ['+' , '-' , '*' , '/' , '%'] : ")
num2 = float(input("Enter another number : "))

if op == '+' :
    result = num1+num2
elif op == '-' :
    result = num1-num2
elif op == '*' :
    result = num1*num2
elif op == '/' :
    if num2!= 0:
       result = num1/num2
    else:
        print("A number cannot be divided by zero") 
elif op == '%':
    result = num1%num2

print("Result : ",result)              
    
