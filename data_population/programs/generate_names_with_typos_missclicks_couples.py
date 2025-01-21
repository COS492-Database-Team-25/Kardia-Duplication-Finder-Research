# Create Test Data Names
# 
# 
import random
import csv
from faker import Faker
def missclick(name, index):
    alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    temp0 = list(name)
    random_letter = random.randint(0,25)
    while temp0[index] != alphabet[random_letter]:
        #print(temp0[index],alphabet[random_letter])
        temp0[index] = alphabet[random_letter]
        
    temp0 = ''.join(temp0)
    return temp0
    
    
    
def swap(name, index,left_or_right):
    temp0 = list(name)
    temp1 = temp0[index]
    #if 0 go right
    if left_or_right == 0:
        temp2 = temp0[index+1]
        temp0[index+1] = temp1
        temp0[index] = temp2
    elif left_or_right == 1:
        temp2 = temp0[index-1]
        temp0[index-1] = temp1
        temp0[index] = temp2
    temp0 = ''.join(temp0)
    return temp0
     
def main():
    data = []
    number_of_typos = 0
    number_of_couples = 0
    number_of_missclicks = 0
    fake = Faker()
    x = 1
    
    print("id,given_name,preferred_name,surname,match")
    for i in range(50000):
        first_name = fake.first_name()
        last_name = fake.last_name()
        matching = "no"
        couple = "no"
        typo = "no"
        Is_missclick = "no"
        new_row = {"id":str(x),"given_name":first_name,"preferred_name":first_name,"surname":last_name,"match":matching,"typo":typo,"couple":couple,"missclick":Is_missclick}
        data.append(new_row)
        x+=1
        

    for i in range(5000):
        couple = "no"
        typo = "no"
        matching = "yes"
        Is_missclick = "no"
        first_name = fake.first_name()
        first_name_typo = first_name
        last_name = fake.last_name()
        last_name_typo = last_name
        
        random_number = random.randint(1, 50)
        #if random_number is 35 insert typo in the first name
        if random_number == 35:
            typo = "First Name"
            left_or_right = random.randint(0,1)
            random_index = random.randint(1,(len(first_name) - 2))
            first_name_typo = swap(first_name,random_index,left_or_right)
            number_of_typos += 1
            
        #if random_number is 45 insert typo in the last name
        elif random_number == 45:
            typo = "Last Name"
            left_or_right = random.randint(0,1)
            random_index = random.randint(0,(len(last_name) - 2))
            last_name_typo = swap(last_name,random_index,left_or_right)
            number_of_typos += 1
        elif random_number == 46:
            Is_missclick = "Last Name"
            random_index = random.randint(0,(len(last_name) - 2))
            last_name_typo = missclick(last_name,random_index)
            number_of_missclicks += 1
        elif random_number == 47:
            Is_missclick = "First Name"
            random_index = random.randint(0,(len(first_name) - 2))
            first_name_typo = missclick(first_name,random_index)
            number_of_missclicks += 1
        #if random_number is between 20 and 10 have it be a husband and wife
        elif random_number < 21 and random_number > 9:
            number_of_couples += 1
            first_name = fake.first_name()+" and "+ fake.first_name()
            first_name_typo = first_name
            couple = "yes"
                
        new_row = {"id":str(x),"given_name":first_name_typo,"preferred_name":first_name_typo,"surname":last_name_typo,"match":matching,"typo":typo,"couple":couple,
                   "missclick":Is_missclick}
        data.append(new_row)
        #print(str(x)+","+first_name_typo+","+first_name_typo, last_name_typo+","+last_name_typo+","+matching+","+typo)
        x+=1
        new_row = {"id":str(x),"given_name":first_name,"preferred_name":first_name,"surname":last_name,"match":matching,"typo":typo,"couple":couple,"missclick":Is_missclick}
        data.append(new_row)
        #print(data)
        #print(str(x)+","+first_name+","+first_name, last_name+","+last_name+","+matching+","+typo)
        x+=1
        
        
        
    print("Number of typos: ", number_of_typos)
    print("Number of couples: ", number_of_couples)
    print("Number of missclicks: ", number_of_missclicks)
    with open("test_data_with_couples_and_typos.csv", mode="w", newline="") as file:
        fieldnames = ["id","given_name","preferred_name","surname","match","typo","couple","missclick"]
        writer = csv.DictWriter(file, fieldnames=fieldnames)

        writer.writeheader()
        writer.writerows(data)

    print("Data written to test_data_with_couples_and_typos.csv")
main()
