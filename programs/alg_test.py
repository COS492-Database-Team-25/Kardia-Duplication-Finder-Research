# Please consult ../testdata/additional_text_files/running_tester.md for instructions on how to run this program

from ctypes import CDLL, c_char_p, c_double
import csv
import timeit

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

while True:
        data_size = input("Enter a letter for a database size (A:10,000 B:20,000 C:30,000) ->")
        if data_size == "A" or data_size == "a":
                size = "10000"
                break
        if data_size == "B" or data_size == "b":
                size = "20000"
                break
        if data_size == "C" or data_size == "c":
                size = "30000"
                break
def test(fuzzyness, size):
        possablematches = 0
        data = []
        startingdata = []
        idtracker = 0
        idtracker_two = 0
        with open('../data/test_data_'+size+'.csv', mode='r') as file:
                reader = csv.reader(file)
                header = next(reader)
                for row in reader:
                        person_one_first = row[1].strip()
                        person_one_last = row[3].strip()
                        person_one = person_one_first + " " + person_one_last
                        startingdata.append(person_one)
                print('finding dups')
                for person_one in startingdata:
                        if idtracker % 100 == 0:
                                print(idtracker)
                        idtracker_two = 0
                        idtracker += 1
                        person_one = person_one.encode('utf-8')
                        for person_two in startingdata:
                                idtracker_two += 1
                                person_two = person_two.encode('utf-8')
                                if idtracker < idtracker_two:
                                        #print(idtracker, idtracker_two)
                                        result = lib_function(person_one, person_two)
                                        if result > fuzzyness and idtracker != idtracker_two:
                                                possablematches += 1
                                                new_row = {"id_one":idtracker , "name_one":person_one,"id_two":idtracker_two,"name_two":person_two}
                                                data.append(new_row)
                                
                                        
                print("tee hee")
                timer_done = "yes"
                print(possablematches)

                with open("matches.csv", mode="w", newline="") as file:
                        fieldnames = ["id_one","name_one","id_two","name_two"]
                        writer = csv.DictWriter(file, fieldnames=fieldnames)

                        writer.writeheader()
                        writer.writerows(data)
    
        print("Data written to matches.csv")

time = timeit.timeit(test(fuzzyness,size))
print("Time "+temp+" took to run: "+time)