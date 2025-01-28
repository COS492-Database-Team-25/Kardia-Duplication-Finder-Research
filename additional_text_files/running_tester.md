# How to Run alg_test.py
alg_test.py is a bit clunky and there are some things you should know before trying to test our algorithms. Here's how you properly run the tester.

**NOTE:** All tests were performed on Apple Silicon MacBooks, so this solution will only work with macOS products. If this does not work for your Windows or Linux computer and you find a way to call the code successfully, please write it down on this file! It will help whoever is playing with this code later.

# macOS Instructions
## Step 1: Figure Out How to Call the Algorithm You Want to Test
Each algorithm is able to be called through the alg_test.py function. But, you will have to specify how to do so. The code requires an input to run the code AFTER YOU COMPILE IT. It is important to know the inputs to call the function you want. 

Here are some shortcuts you can use for calling the specific algorithms. This is case-sensitive, so make sure you only use lowercase.
* l - Levenshtein Edit Distance
* c - Cosine Similarity
* j - Jaccard Similarity
* g / lcs - Gestalt aka Longest Common Subsequence

## Step 2: Compiling the Code
We used GCC to compile the code into a library.so file the alg_test.py code can use. The specific terminal command we used is long, lengthy and hard to remember, so I want to make sure this is as plug-and-play as possible. Here's a template command you can paste in your terminal and tweak:
**gcc -shared -o (algorithm name here)library.so -fPIC (directory)/(algorithm_source_file).c -lm**

**NOTE:** Please make sure you are typing this command in the right area in the repository. You should be in the programs directory, which is linked to testdata.

If you don't want to go through all the work to just use the function, here's all four of the commands here:
* l: gcc -shared -o levenshteinlibrary.so -fPIC levenshtein/levenshtein_no_malloc.c -lm
* c: gcc -shared -o cosinelibrary.so -fPIC cosine/cosine_similarity.c -lm
* j: gcc -shared -o jaccardlibrary.so -fPIC jaccard/jaccard_algorithm.c -lm
* g/lcs: gcc -shared -o gestaltlibrary.so -fPIC gestalt/gestalt_pattern_matching.c -lm

## Step 3: Run alg_test.py
To initiate the code, simple type this command into your terminal:
**arch -arm64 python3 alg_test.py**

After inputting this code into your terminal, you will be prompted with an input. Type in the shortcut or full name on the algorithm you just compiled. If all goes well, you will see "finding dups" or a CVS receipt full of numbers in your terminal. This means it's working.

## Step 4: Reading the Outputs
The numbers that scroll through the screen are relatively unimportant to the results. But they do represent the similarity of two strings. These numbers only get printed if two strings' similarity count is over the similarity threshold set. The default threshold is 0.8.

After the "tee hee" print message are the real results.

The top number is the number of matches found by the algorithm. These matches can be looked at in detail in the matches.csv file that is generated from the tester.

The bottom number is the amount of time it takes for the algorithm to search through a database. As far as I am aware, this function does not work, so unfortunately you have to time it the old-fashioned way.

I hope this file helps you understand how our tester works. Happy testing!
- *Colten Yeats*