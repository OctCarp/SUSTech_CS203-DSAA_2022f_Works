## Problem E: Magic Number

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

Lihua defines Magic Number as that if you rotate the number 180 degrees the number will not change. For example, 69, 96, 111, 181 are magic numbers. 87, 76 are not. In particular, 0, 1, 8 will not change after 180 degrees rotation, 6 will change into 9 and 9 will change into 6, but 2 and 5 cannot change to each other or itself. Now Lihua wants to find the smallest and largest magic number in the range $L$ to $R$.

## Input

There are multiple test cases (less than 5), each test will contain two integers $L$ and $R$.

Note that the range of $L$ and $R$ is $0≤L≤R≤10^{12}$, it is guaranteed there is a least one magic number between $L$ and $R$(inclusive)

## Output

A single line for each test case, two integers: the smallest and largest magic number between $L$ and $R$.

## Sample Input

```
50 100
150 200
```

## Sample Output

```
69 96
181 181
```

## HINT

You can use **EOF** to judge the input is ended or not

In C++, you can read like this:

```c++
while(cin>>l>>r){
  ...
}
```

, and in Java, suppose sc is a Scanner, you can read like this:

```java
while(sc.hasNext()){
  l=sc.nextInt();
  r=sc.nextInt();
}
```

in command line, you can use Ctrl+D (or maybe Ctrl+Z) to cause **EOF**
