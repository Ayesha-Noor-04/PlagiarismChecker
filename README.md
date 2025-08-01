Sentence Similarity and Plagiarism Check (C++)
This project implements a sentence similarity checker in C++. It checks whether two sentences are similar by determining if one can be transformed into the other by inserting an arbitrary phrase. It also calculates the percentage similarity between the two sentences.

Features
Core Functions
bool checksimilar(std::string str1, std::string str2)

Returns true if the two sentences are similar based on the defined rule.

float percentagesimilarity(std::string str1, std::string str2)

Returns the percentage similarity between the two sentences.

Problem Explanation
Two sentences are considered similar if one can be transformed into the other by inserting an arbitrary sentence (possibly empty) anywhere within one of them.

Examples
Example 1
vbnet
Copy
Edit
Input:
sentence1 = "My name is Haley"
sentence2 = "My Haley"

Output: true
Explanation: "name is" can be inserted into sentence2 to form sentence1.
Example 2
makefile
Copy
Edit
Input:
sentence1 = "of"
sentence2 = "A lot of words"

Output: false
Explanation: No insertion can make the two sentences identical.
Example 3
vbnet
Copy
Edit
Input:
sentence1 = "Eating right now"
sentence2 = "Eating"

Output: true
Explanation: "right now" can be inserted at the end of sentence2.
