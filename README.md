# Log-Structured-File-System-LFS

Tools/Technologies: C, FUSE, Linux

A prototype of LFS was developed in this project on existing system calls interfaces using FUSE
that included major functionalities of file system such as reading and writing blocks, reading
and writing blocks via inodes, introduction of directory and extension of basic file system for
making the data blocks and inodes log structured, implementation of indirect blocks in inodes.
The final refined prototype was capable of checkpointing too with minimal overhead by just
manipulating the log directory.
