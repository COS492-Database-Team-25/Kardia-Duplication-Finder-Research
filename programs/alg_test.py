# Please consult ../testdata/additional_text_files/running_tester.md for instructions on how to run this program

from ctypes import CDLL, c_char_p, c_double
import csv
import time
timer = 0
timer_done = 'no'

# Determines algorithm used by code
while True:
        temp = input("Enter which Algorithm you would like to use -> ")
        if temp == "c" or temp == "cosine": # Cosine Similarity
                lib = CDLL('./cosinelibrary.so')
                lib_function = lib.cosine_similarity_interface
                lib_function.argtypes = [c_char_p, c_char_p]
                lib_function.restype = c_double
                break
        elif temp == "j" or temp == "jaccard": # Jaccard Similarity
                lib = CDLL('./jaccardlibrary.so')
                lib_function = lib.jaccard_sim
                lib_function.argtypes = [c_char_p, c_char_p]
                lib_function.restype = c_double
                break
        elif temp == "l" or temp == "levenshtein": # Levenshtein Similarity
                lib = CDLL('./levenshteinlibrary.so')
                lib_function = lib.levenshtein
                lib_function.argtypes = [c_char_p, c_char_p]
                lib_function.restype = c_double
                break
        elif temp == "lcs" or temp == "g" or temp == "longest common subsequence" or temp == "gestalt": # Longest Common Subsequence
                lib = CDLL('./gestaltlibrary.so')
                lib_function = lib.main
                lib_function.argtypes = [c_char_p, c_char_p]
                lib_function.restype = c_double
                break
        else: # for wrong inputs
                print("Not a valid input")

while True:    
        # take input for fuzziness   
        fuzzyness = input("Choose a fuzziness value (Anywhere from 0.0 to 1.0) ->")
        
        # Make sure fuzzyness is a float
        if not float(fuzzyness):
                print("Not a valid input, please input a real number between 0.0 and 1.0")
                continue
        else:
                fuzzyness = float(fuzzyness)

        # Make sure fuzziness is between 0.0 and 1.0
        if fuzzyness > 1.0 or fuzzyness < 0.0:
                print("Number not in between 0.0 and 1.0, please input a real number between 0.0 and 1.0")
        else:
                break
possablematches = 0
data = []
startingdata = []
idtracker = 0
idtracker_two = 0
with open('../data/test_data_30000.csv', mode='r') as file:
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
                          result = lib_function(person_one, person_two)
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
