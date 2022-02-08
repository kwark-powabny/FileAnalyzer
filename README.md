Program takes a list of text files (".txt") recursively and analyzes:
- how many files there are,
- how many lines each file has,
- how many words each file has,
- how many letters each file has (currently only Latin). 

As a parameter, the program takes the number of threads. When the parameter is missing, the program runs as a single thread. 


Thanks to Pradeep P for providing the example of simple thread pool (using a blocking queue) in C++:
https://www.pradeepbangalore.in/post/a-simple-thread-pool-using-a-blocking-queue-in-c
