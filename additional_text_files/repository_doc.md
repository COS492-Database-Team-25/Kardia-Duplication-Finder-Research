# Documentation for This Repository
- **.vscode** - supplementary files for VS Code
- **additional_text_files** - stores other markdown files
    * *test_logs* - the test logs for algorithms
    * repository_doc.md - a full tour of the repository (you are here!)
    * running_tester.md - helpful guide on how to run the tester
- **data** - stores data and data generating programs
    * generate_names_with_typos_missclicks_couples.py - advanced database generator, used for test data
    * generate_names.py - primitive database generator
    * matches.csv - example of what matches.csv will look like when run
    * test_data_10000.csv - 10000 entries
    * test_data_20000.csv - 20000 entries
    * test_data_30000.csv - 30000 entries
- **programs** - stores algorithm programs and the algorithm tester
    * algorithm_test.dSYM - artifact of debugging algorithm_test.c, leaving here in case someone wishes to debug algorithm_test.c
    * *cosine*/cosine_similarity.c - implements Cosine Similarity (referred to as "c" in alg_test)
    * *gestalt*/gestalt_pattern_matching.c - implements Longest Common Subsequence (referred to as "lcs" or "g" in alg_test)
    * *jaccard*/jaccard_algorithm.c - implements Jaccard Similarity (referred to as "j" in alg_test)
    * *levenshtein* - implements Levenshtein Edit Distance (referred to as "l" in alg_test)
        * levenshtein_distance.c - second iteration of code
        * levenshtein_no_malloc.c - working code, used with alg_test.py
        * phase_two_levenshtein_distance_psuedocode.txt - planning stage of levenshtein
        * phase_two_levenshtein_distance.c - first iteration of code
    * .gitattributes - failed attempt to get GitHub LFS to store a large matches.csv file (did not work)
    * alg_test.py - main testing function - consult running_tester.md for information on how to run the tester
    * algorithm_test.c - attempt to code algorithm tester in C, needs major tweaks and debugging
- *.gitignore* - for ignoring staged changes
- *README.md* - introduction to project
