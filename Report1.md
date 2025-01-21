<!-- {% raw %} -->
# Rainfall I: OOPS25-Rainfall-010

## Source

Space: `·` Tab: `-` [EOL](https://en.wikipedia.org/wiki/Newline) `$`

```C++
  1 /*$
  2 ····rainfall.cpp$
  3 $
  4 ····Rainfall report. Inputs are rain amounts per hour. Output is the average$
  5 ····and heaviest hourly rainfall.$
  6 */$
  7 $
  8 #include <iostream>$
  9 #include <iomanip>$
 10 #include <vector>$
 11 $
 12 using namespace std;$
 13 $
 14 int main() {$
 15 ····vector<float> rainfall;$
 16 ····float t, m, n;$
 17 ····while (cin >> n) {$
 18 ········rainfall.push_back(n);$
 19 ····}$
 20 ····if (!rainfall.size()) {$
 21 ········cout << "Error: no rainfall data";$
 22 ········return 1;$
 23 ····}$
 24 ····t = rainfall[0];$
 25 ····m = rainfall[0];$
 26 ····for (vector<float>::size_type i = 1; i < rainfall.size(); ++i) {$
 27 ········t += rainfall[i];$
 28 ········if (rainfall[i] > m)$
 29 ············m = rainfall[i];$
 30 ····}$
 31 ····cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
 32 ····cout << "|:----------------|----------------|" << '\n';$
 33 ····cout << "| Average ········| ····" << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';$
 34 ····cout << "| Heaviest ·······| ····" << left << setw(10) << m << " |" << '\n';$
 35 $
 36 ····return 0;$
 37 }$

```

## Style

Changed files:

```console
rainfall.cpp
```

Indentation Patterns for rainfall.cpp

```console
····
········
············
```

## Guidelines

* ✔ Indentation consistently follows the flow of control
* ✔ Indentation is all spaces and not mixed spaces/tabs
* ✔ File ends in a newline

## Build
% mkdir build; cd build; cmake ..

```console
-- The C compiler identification is GNU 12.2.0
-- The CXX compiler identification is GNU 12.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```


## Commit Messages

```console
Add a header comment
Add return to main()
```

## Commits
## git checkout 6a9a39

% git show

```diff
commit 6a9a394829f737ef715ff02ba06fd474694fcc02
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 16 10:20:42 2025

    Add a header comment

diff --git a/rainfall.cpp b/rainfall.cpp
index 3b0651c..57decdb 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -1,3 +1,10 @@
+/*
+    rainfall.cpp
+
+    Rainfall report. Inputs are rain amounts per hour. Output is the average
+    and heaviest hourly rainfall.
+*/
+
 #include <iostream>
 #include <iomanip>
 #include <vector>

```


% cmake ..

```console
-- The C compiler identification is GNU 12.2.0
-- The CXX compiler identification is GNU 12.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp

```diff
```

## git checkout 486fc8

% git show

```diff
commit 486fc8fdc8ce653cb16aa717d2f8ab4029caecb3
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 16 10:29:20 2025

    Add return to main()

diff --git a/rainfall.cpp b/rainfall.cpp
index 57decdb..0a3469a 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -32,4 +32,6 @@ int main() {
     cout << "|:----------------|----------------|" << '\n';
     cout << "| Average         |     " << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';
     cout << "| Heaviest        |     " << left << setw(10) << m << " |" << '\n';
+
+    return 0;
 }

```


% cmake ..

```console
-- The C compiler identification is GNU 12.2.0
-- The CXX compiler identification is GNU 12.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /Build
```
% make

```console
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```

% diff oracle/rainfall.cpp rainfall.cpp

```diff
```


<!-- {% endraw %} -->
