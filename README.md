# Kardia-Duplication-Finder-Research
This project was created in association with LightSys with the intention of finding a faster duplicate-finder algorithm than their current Cosine Similarity algorithm.

#### -- Project Status: Active

## Project Intro/Objective
This project's main objective is to improve the runtime of the algorithm which finds duplicate entries in a large dataset. We mainly tested the Cosine Similarity and Levenshtein Edit Distance. These algorithms are tweaked versions which hopefully will save runtime comapred to their original counterparts.

### Partner
* LightSys
* https://lightsys.org

### Technologies
* MySQL
* C

## Project Description
LightSys, the company behind the missionary fund-management application Kardia, came to us, more specifically Taylor University, in order to help them improve their algorithm for duplicate-finding. As of now, their duplicate-finding program averages O(n^2). On a smaller database, this is manageable. But as the database gets larger, this program will only get slower.

As stated above, we will be using improved versions of Levenshtein and Cosine Similarity to test their runtime compared to their original versions, already implemented into their coding language, Centrallix. To test these algorithms, we are using our own test database, found in the data tab of data_population. The aim of this database is to replicate a real account database as best as we can, complete with entries with typos and problematic edge cases.

## Team Members
* Colten Yeats
* Ethan Reddy
* Caleb Ranzau
* Gabriel Wilson


