# Documentation for This Repository
**additional_text_files** - stores other markdown files

**data_population** - stores our test database and several test programs
* *data* - stores database
    * testdata_names.csv - the initial form of the database
    * testdata_names.db - a usable database form of testdata_names
* *programs* - stores programs to test with the database
    * generate_names.py - uses Faker to create fake database entries, prints names for user to see
    * jaccard_algorithm.c - implements the Jaccard algorithm (not working, determined as low priority)
    * phase_two_levenshtein_distance.c - implements the Levenshtein edit distance algorithm
    * Phase1.sql - runs a very simple query to search for duplicates in p_partner within LightSys's test database
**project_phases** - contains SQL queries which mock the duplicate-selection of LightSys's Kardia algorithm in the simplest way possible
* phase_one_reddy.sql - basic search query, similar results to Phase1.sql
* phase_three_yeats.sql - an improved version of phase_one_reddy.sql that also searches in p_location within LightSys's test database
* Phase3_contact_info.sql - an improved version of phase_one_reddy.sql that also searches in p_contact_info within LightSys's test database