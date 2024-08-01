def process_vars(input):
    for i,num in enumerate(input):
        try:
            input[i] = int(num)
        except ValueError:
            pass
    if input[0] ==1:
        if input[0]=='':#a2+b2=c2  
            return pow(pow(c,2)-pow(b,2),0.5);
        if b=='':#a2+b2=c2  
            return pow(pow(c,2)-pow(a,2),0.5);
        if b=='':#a2+b2=c2  
            return pow(pow(a,2)+pow(b,2),0.5);
        
input =input().split(',');

# print(a,b,c);
# if b=='':
#     print("fuckyoutbitches")
print(process_vars(input));



