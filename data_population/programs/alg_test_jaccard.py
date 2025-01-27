from ctypes import CDLL, c_char_p, c_double
import csv
import timeit
def test():
        possiblematches = 0
        timer_done = 'no'
        jaccard_lib = CDLL('./library_jaccard.so')
        jaccard_lib.jaccard_sim.argtypes = [c_char_p, c_char_p]
        jaccard_lib.jaccard_sim.restype = c_double
        fuzzyness = .2
        data = []
        startingdata = []
        idtracker = 0
        idtracker_two = 0
        with open('test_data_with_couples_and_typos_missclicks_and_emails_copy.csv', mode='r') as file:
                reader = csv.reader(file)
                header = next(reader)
                for row in reader:
                        person_one_first = row[1].strip()
                        person_one_last = row[3].strip()
                        person_one = person_one_first + " " + person_one_last
                        startingdata.append(person_one)
                print('finding dups')
                for person_one in startingdata:
                        idtracker_two = 0
                        idtracker += 1
                        person_one = person_one.encode('utf-8')
                        for person_two in startingdata:
                                idtracker_two += 1
                                person_two = person_two.encode('utf-8')
                                result = jaccard_lib.jaccard_sim(person_one, person_two)
                                if result <= fuzzyness and idtracker != idtracker_two:
                                        possiblematches += 1
                                        new_row = {"id_one":idtracker , "name_one":person_one,"id_two":idtracker_two,"name_two":person_two}
                                        data.append(new_row)
                

                with open("matches_jaccard.csv", mode="w", newline="") as file:
                        fieldnames = ["id_one","name_one","id_two","name_two"]
                        writer = csv.DictWriter(file, fieldnames=fieldnames)

                        writer.writeheader()
                        writer.writerows(data)
            
                print("Data written to matches.csv")
                print("Found ",possiblematches," possible matches")
execution_time = timeit.timeit(test, number=1)
print(f"Jaccard took {execution_time:.6f} seconds to run")
