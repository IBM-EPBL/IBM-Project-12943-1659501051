import random
while(True):
    a=random.randint(10,99)
    b=random.randint(10,99)
    if(a>40 and b>70):
   	 print("high temprature and humidity of:",a,b,"%","alarm is on")
   elif(a<30 and b<55):
           print("Normal temprature and humidity of:",a,b,"%","alarm is off")	
           break
