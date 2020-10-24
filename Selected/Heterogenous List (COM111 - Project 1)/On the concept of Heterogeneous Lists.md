# Heterogeneous lists
#### September 21st, 2020.
#### Juan Marcos Braga Faria 
## Preface 
A comment on the importance of data structures is pertinent here.

When we seek to solve a problem or situation computationally, it is always important to understand not only its functioning - how to understand the data to be analyzed and processed, or how the solution can be translated into mathematical and programming terms, as they directly impact on the efficiency of the project; but also the needs of those who will program and those who will use this solution.

Aspects such as the programmer's affinity with the language and technology used, the probability of errors and the need for future maintenance on the code that different implementations present, the ease of use; all of these factors must be chosen with great deliberation about what is needed from the program, and which can often be adopted at the expense of its efficiency and performance.
In this way, having knowledge of the different ways in which we can organize information in programs can and does prove to be a very powerful tool in the task of meeting the issues of efficiency, ease of programming and use. 

## Shopping at a supermarket, an example
Consider a normal costumer’s visit to the supermarket. They choose their products of choice, and head to the cashier to register and pay them. 

Most supermarkets today use an automated process of registering the products and providing a convenient list for review and sum of the values. But how does it really work? Clearly there is a list there, but what structure was used? Let us try to make a somewhat educated guess. 

The cashier needs only to store the product list during the short period of time each costumer goes through and pay for them. Therefore, just like a web browser uses space for a website only if there is a tab open and frees memory once it is closed; the program certainly does not need to store everything, and the list has got to be allocated dynamically.  

Additionally, once someone can buy food only for a day or needlessly stock toilet paper for a pandemic, the size of the list has to be flexible and malleable (wasting time moving items around in arrays would only waste the costumer’s precious time), and a linked list appears to be fit for the job.

So, a dynamic linked list should fit the job well, right? Not quite. 

Think about the types and quantities of data, or even better, think about the types of products you can buy at a store. Most items can be uniquely identified by the barcode, since there is little variation: a can of dog food can be represented by a code; a large can of the same food can be stores as either a completely new code, or with an additional information for the size. But what about when I buy meat? Or bread? Most likely it will be weighed, but that info must be saved somewhere. Other than mass, volume can also be variable, for local productions such as milk, for example. The quantity of products must also be remembered by the program (who could think someone would want more than one type of product at the same time!?). 

This situation appears to be a good fit for a very specific type of data structure: a heterogenous linked list. 

## The Concept
Heterogeneous lists, a generic list, or even, a dynamically allocated homogeneous list of heterogeneous objects. Despite having a somewhat toilsome implementation (specially in C), behind this scary term is a rather simple concept.

A heterogeneous list is a linked list that allows the programmer to add different types of data, as well as different amounts of them, into a normal looking linked list. 

Although one can add a struct of elements to another structure, this action is only done statically, and therefore does not allow for any future changes. To work around this problem, dynamically allocating the types of data desired and adding them to a container capable of storing a pointer to any type can get the job done. In C, this can be achieved by declaring this container of the type VOID*, which can be read as “pointer to anything”.

But how the program will know the size and amount of data of each element to use it? The simplest solution would be to add another variable to each element (or node) of the homogeneous linked list, then use it to store a pre-defined code that tells the computer what to expect from the pointer. 

The following image tries to illustrate a part of such list. 

## Implementation
(to-do)
