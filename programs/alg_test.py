from ctypes import CDLL, c_char_p, c_double
import csv
import time
timer = 0
timer_done = 'no'
temp = input("Enter which Algorithm you would like to use -> ")
cosine_lib = CDLL('./'+temp+'library.so')
cosine_lib.cosine_similarity_interface.argtypes = [c_char_p, c_char_p]
cosine_lib.cosine_similarity_interface.restype = c_double
fuzzyness = .8
possablematches = 0
data = []
startingdata = []
idtracker = 0
idtracker_two = 0
with open('../data/test_data_with_couples_and_typos_missclicks_and_emails.csv', mode='r') as file:
        reader = csv.reader(file)
        header = next(reader)
        for row in reader:
                #print(row[3])
                person_one_first = row[1].strip()
                person_one_last = row[3].strip()
                person_one = person_one_first + " " + person_one_last
                #print(person_one)
                #person_one = person_one.encode('utf-8')
                startingdata.append(person_one)
        print('finding dups')
        '''
        while timer_done == 'no':
          time.sleep(1)
          timer = timer + 1
          if timer % 1000 == 1:
                  print("Im still alive time: "+str(timer))
        '''
        if True:
          for person_one in startingdata:
                  idtracker_two = 0
                  idtracker += 1
                  #print(person_one)
                  person_one = person_one.encode('utf-8')
                  for person_two in startingdata:
                          #print(person_two)
                          idtracker_two += 1
                          person_two = person_two.encode('utf-8')
                          result = cosine_lib.cosine_similarity_interface(person_one, person_two)
                          if result > fuzzyness and idtracker != idtracker_two:
                                  print(result)
                                  possablematches += 1
                                  new_row = {"id_one":idtracker , "name_one":person_one,"id_two":idtracker_two,"name_two":person_two}
                                  data.append(new_row)
                                  #print(new_row)
                
                #idtracker = 0
        print("tee hee")
        timer_done = "yes"
                                        #print(person_one,person_two)
        print(possablematches)
        print(timer)

        with open("matches.csv", mode="w", newline="") as file:
                fieldnames = ["id_one","name_one","id_two","name_two"]
                writer = csv.DictWriter(file, fieldnames=fieldnames)

                writer.writeheader()
                writer.writerows(data)
    
        print("Data written to matches.csv")

'''
        for row2 in reader:
                #print(row2[3])
                person_two_first = row2[1].strip()
                person_two_last = row2[3].strip()
                person_two = person_two_first + " " + person_two_last
                #print(person_two)
                person_two = person_two.encode('utf-8')
                #print(person_two)
                result = cosine_lib.cosine_similarity_interface(person_one, person_two)
                if float(result) > fuzzyness and row[0] != row2[0]:
                        print(row[0]," ",row2[0])
                        print(result)
                        possablematches += 1
                        #print(person_one,person_two)
            #print(result)
    print(possablematches)
'''
