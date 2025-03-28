# The Algorithms in C++

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/761ad7446aa5491e95ce143758656c04)](https://www.codacy.com/app/Alexandr/Algorithms?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Alexandr/Algorithms&amp;utm_campaign=Badge_Grade)

These algorithms are the demonstration purposes only. There are
many algorithms implementations in the C++ standard
library that are much better for performance reasons. This
project contains the following algorithms...

## Allocators

| Name allocator     | Allocation | Free   |
|:------------------:|:----------:|:------:|
| Linear allocator   | O(1)       | -      |

## Cryptography

| Name algorithm          |
|:-----------------------:|
| Caesar cipher           |
| Hex                     |
| Crypto random + entropy |
| RC4 cipher              |

## Data structures

| Name structure     | Indexation  | Search         | Inserting    | Deleting    | Memory |
|:------------------:|:-----------:|:--------------:|:------------:|:-----------:|:------:|
| Circular buffer    | O(n)        | O(n)           | O(1)         | O(1)        | O(n)   |
| Linked list        | O(n)        | O(n)           | O(1)         | O(1)        | O(n)   |

## Search

| Name algorithm    | Data Structure | Average result | Worse result |
|:-----------------:|:--------------:|:--------------:|:------------:|
| Binary search     | Sorted array   | O(log(n))      | O(log(n))    |
| Linear search     | Array          | O(n)           | O(n)         |

## Set operations

| Name algorithm                        |
|:-------------------------------------:|
| Difference between ordered sets       |
| Intersection of the ordered sets      |
| Symmetric difference of ordered sets  |
| Union of the ordered sets             |
| Union of the ordered sets w doubles   |

## Smart pointers

| Name pointer          |
|:---------------------:|
| Shared smart pointer  |
| Unique smart pointer  |

## Sorting

| Name algorithm        |Data Structure | Best result  | Average result | Worse result |
|:---------------------:|:-------------:|:------------:|:--------------:|:------------:|
| Bubble sorting        |  Array        | O(n)         | O(n^2)         | O(n^2)       |
| Counting sorting      |  Array        | O(n)         | O(n)           | O(n)         |
| Insertion sorting     |  Array        | O(n^2)       | O(n^2)         | O(n^2)       |
| Move elements to left |  Array        | O(n)         | O(n)           | O(n)         |
| Quick sorting			|  Array        | O(n*log(n))  | O(n*log(n))    | O(n^2)       |
| Selection sorting     |  Array        | O(n)         | O(n^2)         | O(n^2)       |
| Shell sorting		    |  Array        | O(n^2)       | O(n^2)         | O(n^2)       |
| Stupid sorting	    |  Array        | O(n)         | O(n^3)         | O(n^3)       |

## Others
| Name algorithm         |
|:----------------------:|
| BackTrack              |
| Fibonacci              |
| Reversal forward list  |
| Rotate matrix          |

## Templates
| Name templates               |
|:----------------------------:|
| Copy string				   |
| Number to string 32 bits     |