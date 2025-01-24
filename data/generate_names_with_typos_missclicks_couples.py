# Create Test Data Names
#
#
import random
import csv
from faker import Faker
def create_email(first_name,last_name,random_two_digit_number,random_number,couple):
    gmail = "@gmail.com"
    bright = "@bright.net"
    yahoo = "@yahoo.com"
    outlook = "@outlook.com"
    if couple == "no":
        #if random_number is 0 then create first_name last_name email
        if random_number == 0:
            email = first_name+last_name
        #if random_number is 1 then create first letter of firstname and then last_name email
        elif random_number == 1:
            first_name = list(first_name)
            email = first_name[0]+last_name
        #if random_number is 2 then create first letter of firstname and then last_name with random_two_digit_number email
        elif random_number == 2:
            first_name = list(first_name)
            email = first_name[0]+last_name+str(random_two_digit_number)
        #if random_number is 3 then create first_name last_name with random_two_digit_number email
        elif random_number == 3:
            email = first_name+last_name+str(random_two_digit_number)
    elif couple == "yes":
        email = last_name+str(random_two_digit_number)
    if random_number == 0:
        email = email + gmail
    if random_number == 1:
        email = email + bright
    if random_number == 2:
        email = email + yahoo
    if random_number == 3:
        email = email + outlook


    return email


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
    data_to_be_saved = []
    number_of_typos = 0
    number_of_couples = 0
    number_of_missclicks = 0
    fake = Faker()
    x = 1

    print("id,given_name,preferred_name,surname,match")
    #random names
    for i in range(2000):
        address = fake.address()
        first_name = fake.first_name()
        last_name = fake.last_name()
        matching = "no"
        couple = "no"
        typo = "no"
        Is_missclick = "no"
        random_number2 = random.randint(10,99)
        random_number = random.randint(0,3)
        email = create_email(first_name,last_name,random_number2,random_number,couple)
        new_row = {"id":str(x),"given_name":first_name,"preferred_name":first_name,"surname":last_name,"email":email,
                   "address":address,"match":matching,"typo":typo,"couple":couple,"missclick":Is_missclick}
        new_data = ['id',str(x),first_name,last_name,email,address]
        data_to_be_saved.append(new_data)
        data.append(new_row)
        x+=1
        

    #matches in first name
    for i in range(500):
        couple = "no"
        typo = "no"
        matching = "yes"
        Is_missclick = "no"
        address = fake.address()
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
        #if random_number is 45 insert missclick in the last name
        elif random_number == 46:
            Is_missclick = "Last Name"
            random_index = random.randint(0,(len(last_name) - 2))
            last_name_typo = missclick(last_name,random_index)
            number_of_missclicks += 1
        #if random_number is 45 insert missclick in the first name
        elif random_number == 47:
            Is_missclick = "First Name"
            random_index = random.randint(0,(len(first_name) - 2))
            first_name_typo = missclick(first_name,random_index)
            number_of_missclicks += 1
        #if random_number is between 20 and 10 have it be a husband and wife
        elif random_number < 21 and random_number > 9:
            number_of_couples += 1
            first_name1 = fake.first_name()
            first_name2 = fake.first_name()
            first_name = first_name1 +" and "+ first_name2
            first_name_typo = first_name
            couple = "yes"
            #if random_number is between 10 and 12 flip their names
            if random_number < 13 and random_number > 9:
                first_name = first_name2 +" and "+ first_name1
        random_number2 = random.randint(10,99)
        random_number = random.randint(0,3)
        email = create_email(first_name,last_name,random_number2,random_number,couple)
        email_typo = create_email(first_name_typo,last_name_typo,random_number2,random_number,couple)
        new_row = {"id":str(x),"given_name":first_name_typo,"preferred_name":first_name_typo,"surname":last_name_typo,"email":email_typo,"address":address,"match":matching,"typo":typo,"couple":couple,
                   "missclick":Is_missclick}
        new_data = ['id',str(x),first_name_typo,last_name_typo,email,address]
        data_to_be_saved.append(new_data)
        data.append(new_row)
        #print(str(x)+","+first_name_typo+","+first_name_typo, last_name_typo+","+last_name_typo+","+matching+","+typo)
        x+=1
        new_row = {"id":str(x),"given_name":first_name,"preferred_name":first_name,"surname":last_name,"email":email,"address":address,"match":matching,"typo":typo,"couple":couple,"missclick":Is_missclick}
        data.append(new_row)
        new_data = ['id',str(x),first_name,last_name,email,address]
        data_to_be_saved.append(new_data)
        x+=1

    #print(data)
    print("Number of typos: ", number_of_typos)
    print("Number of couples: ", number_of_couples)
    print("Number of missclicks: ", number_of_missclicks)
    print(data_to_be_saved)
    with open("test_data_with_couples_and_typos_missclicks_and_emails.csv", mode="w", newline="") as file:
        fieldnames = ["id","given_name","preferred_name","surname","email","address","match","typo","couple","missclick"]
        writer = csv.DictWriter(file, fieldnames=fieldnames)

        writer.writeheader()
        writer.writerows(data)
    
    print("Data written to test_data_with_couples_and_typos.csv")
main()
