import sys
match_list = [chr(x) for x in range(33,127)]

def generate_list_fixed_length(n):
        list_str = match_list
        if n > 1 :
                for i in range(1,n):
                        list_str = add_char_to_list_strings(list_str)
        return list_str

def add_char_to_list_strings(list_str):
        next_list = []
        for s1 in list_str : 
                for s2 in match_list : 
                        next_list.append(str(s1 + s2))
        return next_list

def generate_list_upto_n(n):
        list_str_upto = []
        for i in range(0,n+1) :
                list_str_upto = list_str_upto + generate_list_fixed_length(i)
        return list_str_upto

def calc_len(n):
        length = 94
        for i in range(1,n+1):
                length = length + 94**i
        return length

n = int(input("Enter length of ASCII string permutations to generate : "))
sel = int(input("To generate string of fixed length n : Press 1 \nTo generate string to length 1 to n : Press 2\nAny other Key to exit : \n"))
save = int(input("Would you like to save generated data in a text file ? Press 9 to save, any other key to continue : "))
path = ""
str_temp = ""
if save == 9 :
        path = input("Enter path or file name to save file : ")
        if save == 9 :
                f = open(path,'wt')
                        
if sel == 1 :
        l = iter(i for i in generate_list_fixed_length(n))
        for i in range(0,94**n):
                str_temp = next(l)
                print(str_temp)
                if save == 9 : 
                        f.write(str_temp + "\n")
                
if sel == 2 :
        l = iter(i for i in generate_list_upto_n(n))
        for i in range(0,calc_len(n)):
                str_temp = next(l)
                print(str_temp)
                if save == 9 : 
                        f.write(str_temp + "\n")
else : sys.exit(0)

f.close()
