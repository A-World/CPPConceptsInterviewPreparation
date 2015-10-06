// Following are the C methods that I need to go through
Important API's for linux programmers.
1. fork()
2. clone()
3. pipe(), pipe2()
4. wait(),waitpid(),waitid()
5. sched() : A set of scheduling related APIs, nearly 12 APIs are present.
6. proc()
7. vfork()
8. unshare()
9. read()
10. write()
11. popen()
12. signal()
13. select()
14. accept()
15. connect()
16. poll()
17. recv()
18. send()
19. bind()
20. listen()
21. socket()
22. unix()


// Following are the types of inter process communiction in linux

1.	File: A record stored on disk, or a record synthesized on demand by file server, which can be accessed by multiple processes.
2.	Signals: A system message sent from one process to another, not usually used to transfer data but instead used to remotely command the partnered process.
3.	Pipes: A two way data stream between two processes interfaced through standard input and output and read one character at a time.
4.	Named pipes: A pipe implemented through a file on system instead of standard input and output. Multiple processes can read and write to a file as a buffer for IPC data.
5.	Sockets: A data stream sent over a network interface, either to a different process on same or different computer in network.
6.	Message Queue: An anonymous data stream similar to socket usually implemented by operating system that allows multiple process to read and write to the message queue without being directly connected to each other.
7.	Semaphores: A simple structure that synchronizes multiple processes acting on shared resources.
8.	Shared Memory: Multiple processes are given access to same block of memory which creates a shared buffer for the process to communicate with each other.

Assignment is to write program for each of above types.






