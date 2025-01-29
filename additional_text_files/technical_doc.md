# Technical Document: List of Program Files

## 1. Overview

This document provides a comprehensive list of program files, their functions, and their interdependencies. It is designed to assist developers, maintainers, and users in understanding the structure and purpose of each file within the program.

## 2. Directory Structure

KARDIA-DUPLICATION-FINDER-RESEARCH/
|- additional_text_files/
|  |- test_logs/
|  |  |- extensive_research_cosine.md
|  |  |- first_test_results_cosine.md
|  |  |- first_test_results_gestalt.md
|  |  |- first_test_results_jaccard.md
|  |- repository_doc.md
|  |- running_tester.md
|  |- technical_doc.md
|- data/
|  |- generate_names_with_typos_misclicks_couples.py
|  |- generate_names.py
|  |- matches.csv
|  |- test_data_10000.csv
|  |- test_data_20000.csv
|  |- test_data_30000.csv
|- programs/
|  |- README.md
|  |- CHANGELOG.md
|- sql/
|  |- phase_one_reddy.sql
|  |- phase_three_yeats.sql
|  |- Phase1.sql
|  |- Phase3_conntact_info.sql
|- .gitignore
|- README.md

## 3. File Descriptions

### data files (data/)

**generate_names_with_typos_misclicks_couples.py**

Function: Creates a csv file including first and last names, contact information, address, and wether or not it is a duplicate entry. If it is a duplicate entry it also includes the type of duplicate a typo, misclick, or swapped order of couples names. These csv files are to be used for running alg_test.py.

Dependencies: None

**generate_names.py**

Function: A much simpler version of generate_names_with_typos_misclicks_couples.py only includes first and last names with some duplicates.

Dependencies: None

### algorithm programs (programs/)

**alg_test.py**

Function: Allows you to run all algorithms see running_tester.md

Dependencies: A csv file created from generate_names_with_typos_misclicks_couples.py

**cosine_similarity.c**

Function: Takes the cosine similarity of two given words 3 seperate times with different variations of linked characters.

Dependencies: alg_test.py

**gestalt_pattern_matching.c**

Function: Finds the most common subsequence of two strings.

Dependencies: alg_test.py

**jaccard_algorithm.c**

Function: Takes the intercestion of the two strings divided by the union.

Dependencies: alg_test.py

**levenshtein_no_malloc.c**

Function: Finds the amount of insertions, deleations, or substitutions needed to make two strigs similar.

Dependencies: alg_test.py

## 4. Version Control

Ensure all changes to files are tracked using version control (e.g., Git). Each file should have clear commit messages detailing modifications.

## 5. Best Practices

File Naming: Use descriptive names that reflect the file's purpose.

Code Comments: Include comments in source code for better readability.

Testing: Regularly update test files to cover new features or changes in functionality.

Documentation: Keep documentation files up to date with the current state of the program.
