from ctypes import CDLL, c_int, c_char_p, POINTER, c_float
import csv
import timeit
def test():
        possiblematches = 0
        cosine_lib = CDLL('/Users/calebranzau/Desktop/Jterm Project/Kardia-Duplication-Finder-Research/programs/levenshtein/library.so')
        cosine_lib.levenshtein.argtypes = [c_int, POINTER(c_char_p)]
        cosine_lib.levenshtein.restype = c_float

        fuzzyness = .98
        data = []
        startingdata = []
        trackingdata = []
        idtracker = 0
        idtracker_two = 0
        with open('/Users/calebranzau/Desktop/Jterm Project/Kardia-Duplication-Finder-Research/data/test_data_30000.csv', mode='r') as file:
                reader = csv.reader(file)
                header = next(reader)
                for row in reader:
                        person_one_first = row[1].strip()
                        person_one_last = row[3].strip()
                        person_one = person_one_first + " " + person_one_last
                        startingdata.append(person_one)
                print('finding dups')
                for person_one in startingdata:
                        #print(idtracker)
                        idtracker_two = 0
                        idtracker += 1
                        if idtracker %100 == 0:
                                print(idtracker)
                                print("possiable matches: ",possiblematches)
                        person_one = person_one.encode('utf-8')
                        for person_two in startingdata:
                                idtracker_two += 1
                                argv = (c_char_p * 3)()
                                argv[0] = b"program"
                                argv[1] = person_one
                                argv[2] = person_two.encode('utf-8')
                                #print(argv[1],argv[2])
                                argc = len(argv)
                                result = cosine_lib.levenshtein(argc, argv)
                                #print(result)
                                dataSearching_one = str(person_one) + ' ' + str(idtracker)
                                dataSearching_two = person_two + " " + str(idtracker_two)
                                if result > fuzzyness and idtracker != idtracker_two and dataSearching_two not in trackingdata:
                                        possiblematches += 1
                                        #print(argv[1],argv[2])
                                        #print(result)
                                        trackingdata.append(dataSearching_one)
                                        new_row = {"id_one":idtracker , "name_one":person_one,"id_two":idtracker_two,"name_two":person_two}
                                        data.append(new_row)

                

                with open("/Users/calebranzau/Desktop/Jterm Project/Kardia-Duplication-Finder-Research/data/test_data_matches.csv", mode="w", newline="") as file:
                        fieldnames = ["id_one","name_one","id_two","name_two"]
                        writer = csv.DictWriter(file, fieldnames=fieldnames)

                        writer.writeheader()
                        writer.writerows(data)
                possiblematches = possiblematches/2
                print("Data written to matches.csv")
                print("Found ",possiblematches," possible matches out of 3000")
execution_time = timeit.timeit(test, number=1)
print(f"Cosine took {execution_time:.6f} seconds to run")
