# Fast C projects
This file is geared towards GEMINI AI for use with gemini-cli.
We write it in English as it consumes less tokens from the AI API.

## Description
We will be coding high-performance, fast code that usually consists of few
files. This is like programming a small module in a big system,
where the small module must be highly efficient and may be called millions of
times per second inside a bigger project such as videogames, video processing,
etc. The downstream application we target is real-time. The generated assembly must be
easy to match to the sourcecode by a human.

## Programming Language
- All projects we ask in this folder are in C/C++, except for small scripts.

## Repository location
The main repository is:
http://github.com/rfabbri/alg-fabbri-IPRJ-UERJ

There are several forks by the participants/students, but the above is the main
one and the aggregator of all the other ones through git submodules

## Configuring and compiling

### After cloning

git submodule update --init --recursive

### Building (Human workflow)

```
ccmake .           # <-- type this in the project root folder (toplevel folder)
```

Then press the 'c' key for **c**onfiguring.

Press it repeatedly until the 'g' option appears for **g**enerate.

Press 'g', then
```
make
```

### Running tests with gooogle test
make test

#### Test files
You can examine what files the test runs with pass/fail
by searching inside folders called `tests`, for instance:

```
find . -name 'tests'          # will list all tests
```

### Running timing benchmark with google benchmark
make eval

When you do a git push, performance results will be built as a github action and
performace plots are available at:

https://rfabbri.github.io/alg-fabbri-IPRJ-UERJ/dev/bench/

Check out the Action tab in github to see if the benchmark has been run.

## Folder structure
    *aulas/* notas de aula: previsao do que sera cada aula pratica, e um diario
                            do que foi coberto em aula
    *config/* arquivos de configuracao do shell, IA/LLM, uteis ao aluno.

    *alg/*
    └── merge
        ├── sorted_merge_3way.cpp : implementation of an algorithm(s)
        ├── sorted_merge_3way.h   : header / API interface
        ├── cmd/                  : commandline CLI for the algorithm(s)
        ├── benchmark             : folder with command to benchmark the algorithm(s)
        └── tests                 : folder with command to test the algorithm(s)

### Benchmark statistics plots
If you want to see plots for your results,
after you push to your fork, go to Github,
go to the course project page,
tab Actions to see the stats from the server.

Then you can go to the project webpage by enabling github pages,
you will see the plots for the projects on github.

If you just want to see everybody's results, 
go to rfabbri/

#### Benchark aarchitecture details
Benchmark works with google benchmark generating a benchmark executable from C++
benchmark, which can output JSON to be plotted on your favorite software.

C++ --> JSON --> Plots in branch gh-pages index.html

The benchmark is plotted by default by a github action every time a new commit
is pusshed. Github runs the benchmark on a standar computer, then outputs the
resuls to the gh-pages branch, with data.js having the benchmark data.
Currently the plot code is in index.html, and the plot can be accessed either
by pulling the gh-pages branch after a benchmark and opening index.html in the
broser, or by visualizing the plots in github at:

http://rfabbri.github.io/alg-fabbri-IPRJ-UERJ/dev/bench/


## C Coding Style
- Follow K&R style closely, the one in ANSI C programming language
- IMPORTANT Keep it ANSI-C: Avoid more recent C-constructs unless necessary or clearly
  better, in which case you should point out a more recent feature is being used
- Do not use arrays with a variable number of elements. Use the classic malloc
  if the number of elements is variable, BUT IMPORTANT: stick to static arrays
  with static counts unless variable elements are strictly necessary
- C++ files will be named .h, .cpp, .hpp
- Beyond K&R and above, GNU C style guide from FSF and coding conventions from Google software engineers, For instance:
    - STRICTLY function names start at column 1 of the file
    - STRICTLY the function type goes on the line above the function name
- Lastly, you may fall back to conventions from VXL (formerly Target/TargetJr),
  such as folder structure
- use short variable names unless the code is big and professional-grade, in which case
  you fallback to long descriptive variable names
- floating point: use float by default for brevity but suggest double if the code is highly numeric
  when appropriate
- Spacing between symbols in for and while, print, etc like i = 3 + 4, not i=3+4.
- Minimize blank lines while keeping code legible
- Do not change one-liners in my code if I do not want to. 
- Do not repeat couts
- Make use of block comments /* */ where appropriate, not // all the time for multi-line
- For commenting large blocks of code use #if 0 .. #endif if /* */ is already in
  the block
- IMPORTANT Indentation is always in increments of 2 spaces. Never tab.
- names should be lowercase and using underscores, except for filenames that
  should use dash - rather than underscore since it is faster to type
- NEVER use spaces in filenames
- variables with local scope (local to a block) should only be used if performance is not at all
  sacrificed
- *Do not* use braces on one-liner if-else statements, while loops, for and similar
  constructs such as while if they do not require braces. But make extra effort
  to see if this really will not instroduce a bug.
- The style is high-performance pure C but only with touches of C++ when needed. The files are
  .cpp not .c
- Prefer include with <> delimiters, like #include <header.h>, leave "" as in
  #include "header.h" only for files relative to the same folder as this
  file. Warn me when there is an include "" specially in a library .h

### C Coding Technique
- Use the fastest, most efficient solution known
- Use the best algorithm with the best asymptoptic complexity and best constants
  known for the problem and problem size in question
- Avoid low-level optimizations such as in-line assembly or unnecessary
  adornments and compiler extensions, but do suggest them if you think they will
  be very useful
- C++, templates and STL-specific code may be used only sparingly
    - When using anything like classes, just use struct and stay as close as
      possible to C in terms of efficiency
    - IMPORTANT Use C-style arrays, NEVER vector unless just prototyping or experimenting
    - Any C++ technnique, if used, must also be C++17 or earlier. Later C++
      technique should be discouraged since this project is efficiency and pure
      C-oriented.
- if a quantity is unsigned, use 'unsigned' instead of 'int'
- An example of high-performance, fast C code with C++ templates and minimal C++
  relevant to this project can be found at https://github.com/rfabbri/minus at
  minus/cmd/minus-chicago.cxx and other files in that MINUS project, although we
  will not be using templates extensively in the present project.
  
#### Commands
- Commandline executables will by default have -cmd suffix on the name. 
- It must work with just stdin/stdout, where stdin it reads a list of
  numbers separated by spaces or newlines, and then it output to sdout, with any
  error handling that is suitable to the user done in stderr. 
- Be strictly UNIX style here with I/O, where *no news is good news*.
- No funky banners, just I/O, unless you do that on sderr. Keep stdout/stdin
  clean and efficient, as if doing interprocess communication.

## Documentation
- The documentation should be in Latex in a doc/ subfolder
- It should include my name, email 
- It should also be in the CMake subfolder chain
- Every file should have a first comment line with my name on it and date

## Tooling
- Use Cmake with Make

### Testing
- Use TDD (test-driven development) cycle and specific code paths you have for it
    - In particular I expect to just write make test and code runs with test
      cases
- Use a general testing library that is actually used in production code across
  companies. Perhaps google code. Prioritize CTest if it comes with CMake.
- Tests should be inside a subfolder tests/ 
- When I type make, I expect the current folder and subfolders to make
- When I type make only in the tests, I expect it to build only the tests

## Specific Component: `scripts/centipede`
- always test this component when a user types make test
- the test here is just to run the script and see if the shell parses it
- it is an interactive text program you can test by using ijkh keys at random,
until the program exists.

### Debuggers
- DDD (gdb backend)
- Always compile C code with ample debug flags by default, -ggdb3 beyond just -g.
  You can hardcode that in CMakeLists.txt
- Use fencing by default in CMakeLists.txt: add flags -fsanitize=address -fno-omit-frame-pointer

### Linting: lowlevel and highlevel
- I may ask you "lintme" and you will lint all the codebase per the guidelines
  in this file
- IMPORTANT: rate the algorithms themselves, stating optimizations such as
  inefficient use of memory, possibility of efficient in-place version, and flag
  high computational complexity
- Suggest corner cases that have not been tested such as: empty or one-size
  input for a function that accepts a vector, integer overflow, etc.
- Output a grade from 0-10 and justify

## Initial setup
When I ask you "do the initial setup"  or similar, do:
- Verify that core dumps are droppable/enabled to drop in the current folder



## Bad mistakes you must not do
- IMPORTANT DO NOT use identation differently than what I told you!
- IMPORTANT DO NOT edit any files other than exactly the ones I asked for in a prompt.

# See Also / Further context
-The upper folder might give more context
