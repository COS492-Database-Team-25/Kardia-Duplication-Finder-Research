# Create Test Data Names
# 
# 
import random
from faker import Faker

fake = Faker()
x = 1
print("id,given_name,preferred_name,surname,match")
for i in range(2400):
    first_name = fake.first_name()
    last_name = fake.last_name()
    matching = "no"
    print(str(x)+","+first_name+","+first_name, last_name+","+last_name+","+matching)
    x+=1
    

for i in range(300):
    first_name = fake.first_name()
    last_name = fake.last_name()
    matching = "yes"
    random_number = random.randint(3, 9)
    print(random_number)
    print(str(x)+","+first_name+","+first_name, last_name+","+last_name+","+matching)
    x+=1
    print(str(x)+","+first_name+","+first_name, last_name+","+last_name+","+matching)
    x+=1