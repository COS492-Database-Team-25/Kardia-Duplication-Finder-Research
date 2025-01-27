# Documentation for This Repository
**.vscode** - stores some files to help VS Code
**additional_text_files** - stores other markdown files
    * algorithms.md - brief description of what each algorithm does, abandoned?
    * repository_doc.md - brief description of each file in the repository (You are here!)
    * running_tester.md - explains the testing process in a simplistic manner
    * vm_process.md - explains how to use the LightSys VM and port forwarding, deprecated as we decided against using       LightSys's test database
**data** - stores all data and data-generating code
    * generate_names.py - a simple name generator
    * generate_names_with_typos_missclicks_couples.py - a more complex name generator that accounts for edge cases such as misspellings, misclicks, and coupling
    * matches.csv - an example of what the matches.csv from alg_test.py looks like (otherwise, I have no clue why it's here)
    * test_data_with_couples_and_typos_and_missclicks.csv
    * test_data_with_couples_and_typos_missclicks_and_emails.csv - this one is used for testing currently
    * test_data_with_couples_and_typos.csv
    * testdata_names.csv - made from old name generator, generate_names.py
    * testdata_names.db - database version of testdata_names.csv
**data_population** - ***DEPRECATED, DO NOT WORRY ABOUT***
**programs** - stores programs which run and test algorithms
    * *algorithm_test.dSYM/Contents* - a side effect of trying to debug algorithm_test.c using VS Code, leaving here in case someone wants to debug it
    * cosine/cosine_similarity.c - returns the Cosine Similarity of two strings
    * gestalt/gestalt_pattern_matching.c - returns the Similarity of two strings using Gestalt's Longest Common Subsequence
    * jaccard/jaccard_algorithm.c - returns the Jaccard Similarity of two strings
    * *levenshtein* - contains code for Levenshtein Edit Distance
        * levenshtein_distance.c - prototype for levenshtein that doesn't work
        * levenshtein_no_malloc.c - working version of levenshtein code
        * phase_two_levenshtein_distance_psuedocode.txt - pseudocode for levenshtein, shows thought process behind levenshtein code
    * .gitattributes - an attempt to get matches.csv files stored in GitHub LFS (did not work)
    * algtest.py - main algorithm tester code, uses CDLLs to run algorithms implemented in C
    * algorithm_test.c - attempt to code algorithm tester in C, needs debugging
**sql** - contains SQL queries which mock the duplicate-selection of LightSys's Kardia algorithm in the simplest way possible
    * Phase1.sql - runs a very simple query to search for duplicates in p_partner within LightSys's test database
    * phase_one_reddy.sql - basic search query, similar results to Phase1.sql
    * phase_three_yeats.sql - an improved version of phase_one_reddy.sql that also searches in p_location within LightSys's test database
    * Phase3_contact_info.sql - an improved version of phase_one_reddy.sql that also searches in p_contact_info within LightSys's test database
.gitignore - tells git to ignore stacked changes
README.md - introduction to project