f1=open("hello.txt","r")
f2=open("hiii.txt","w")
lines=f1.readlines()
for i in range(0,len(lines)):
 if i%2==0:
    f2.write(lines[i])
f1.close()    
f2.close()

print ("File copied successfully")
    