<div>
<img align="left" src="https://github.com/Ali-Elbana/File-IO-Module/assets/97269796/7508d21d-96ff-413e-85d9-868feff0ca01" alt="File I/O Module Logo" width="350">

# **File I/O Module: Simplifying C++ File Operations**

[![GitHub stars](https://img.shields.io/github/stars/Ali-Elbana/File-IO-Module?style=social)](https://github.com/Ali-Elbana/File-IO-Module/stargazers) 
[![GitHub forks](https://img.shields.io/github/forks/Ali-Elbana/File-IO-Module?style=social)](https://github.com/Ali-Elbana/File-IO-Module/network/members) 
[![GitHub watchers](https://img.shields.io/github/watchers/Ali-Elbana/File-IO-Module?style=social)](https://github.com/Ali-Elbana/File-IO-Module/watchers)

[![GitHub repo size](https://img.shields.io/github/repo-size/Ali-Elbana/File-IO-Module)](https://github.com/Ali-Elbana/File-IO-Module) 
[![License](https://img.shields.io/github/license/Ali-Elbana/File-IO-Module)](https://github.com/Ali-Elbana/File-IO-Module/blob/main/LICENSE) 

![GitHub search hit counter](https://img.shields.io/github/search/Ali-Elbana/File-IO-Module/goto?style=flat-square)
[![Contributors](https://img.shields.io/github/contributors/Ali-Elbana/File-IO-Module)](https://github.com/Ali-Elbana/File-IO-Module/graphs/contributors)

[![GitHub commit activity](https://img.shields.io/github/commit-activity/m/Ali-Elbana/File-IO-Module)](https://github.com/Ali-Elbana/File-IO-Module/commits/main) 
[![Last commit](https://img.shields.io/github/last-commit/Ali-Elbana/File-IO-Module)](https://github.com/Ali-Elbana/File-IO-Module/commits/main) 

[![GitHub pull requests](https://img.shields.io/github/issues-pr/Ali-Elbana/File-IO-Module)](https://github.com/Ali-Elbana/File-IO-Module/pulls)
![GitHub merged PRs](https://img.shields.io/github/issues-pr-closed/Ali-Elbana/File-IO-Module?style=flat-square)
</div>

<div>

</div>

----

## A collection of fuctions written in C++ for easier file operations.

### Introduction:

Welcome to the File I/O Module, a dedicated module crafted to enhance your C++ file handling experience. As a programmer, dealing with file operations can be intricate and time-consuming. This module aims to alleviate those challenges by providing a set of functions that streamline common file tasks, allowing you to focus on your application's core logic.

---

### Description:

The File I/O Module is a comprehensive solution designed to simplify File I/O operations in C++. Whether you're a beginner or an experienced developer, this module offers a range of functions that abstract away the complexities of reading, writing, and manipulating files.

---

### Key Features:

* **Effortless File Handling:** Simplify file operations with intuitive functions.
* **Robust Error Handling:** Ensure smooth execution with comprehensive error-handling mechanisms.
* **Versatile File Type Support:** Seamlessly work with various file types, including text and binary files.
* **Configurable Options:** Tailor file operations to match your application's unique requirements.
* **Cross-Platform Compatibility:** Write code that runs reliably across different platforms.
  
Empower your C++ projects with the File I/O Module. Whether you're building a small utility or a complex application, this module is designed to make file handling more efficient and less daunting.

***Elevate your C++ File I/O experience - integrate the File I/O Module into your projects today!***

---

## Table of Contents:

- [Mind map for the notes](#mind_map_for_the_notes)
- [Installation and Usage](#installation-and-usage)
- [Contribution Guidelines](#contribution_guidelines)
- [License](#license)
- [Contact Information](#contact-information)
- [Acknowledgments](#acknowledgments)

---

## Mind map for the notes:

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="X-UA-Compatible" content="ie=edge">
<title>Markmap</title>
<style>
* {
  margin: 0;
  padding: 0;
}
#mindmap {
  display: block;
  width: 100vw;
  height: 100vh;
}
</style>
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/markmap-toolbar@0.15.6/dist/style.css">
</head>
<body>
<svg id="mindmap"></svg>
<script src="https://cdn.jsdelivr.net/npm/d3@7.8.5/dist/d3.min.js"></script><script src="https://cdn.jsdelivr.net/npm/markmap-view@0.15.6/dist/browser/index.js"></script><script src="https://cdn.jsdelivr.net/npm/markmap-toolbar@0.15.6/dist/index.js"></script><script>(r => {
                setTimeout(r);
              })(() => {
  const {
    markmap,
    mm
  } = window;
  const {
    el
  } = markmap.Toolbar.create(mm);
  el.setAttribute('style', 'position:absolute;bottom:20px;right:20px');
  document.body.append(el);
})</script><script>((getMarkmap, getOptions, root2, jsonOptions) => {
                const markmap = getMarkmap();
                window.mm = markmap.Markmap.create(
                  "svg#mindmap",
                  (getOptions || markmap.deriveOptions)(jsonOptions),
                  root2
                );
              })(() => window.markmap,null,{"type":"heading","depth":0,"payload":{"lines":[0,1]},"content":"FIO Module Functions","children":[{"type":"heading","depth":1,"payload":{"lines":[3,4]},"content":"File creation and deletion","children":[{"type":"heading","depth":2,"payload":{"lines":[4,5]},"content":"Function to create a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[5,6]},"content":"Function to create a bin file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[6,7]},"content":"Function to delete any file","children":[]}]},{"type":"heading","depth":1,"payload":{"lines":[9,10]},"content":"File renaming and status","children":[{"type":"heading","depth":2,"payload":{"lines":[10,11]},"content":"Function to rename any file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[11,12]},"content":"Check file status","children":[]},{"type":"heading","depth":2,"payload":{"lines":[12,13]},"content":"Check if a file exists","children":[]},{"type":"heading","depth":2,"payload":{"lines":[13,14]},"content":"Count the number of lines in a file","children":[]}]},{"type":"heading","depth":1,"payload":{"lines":[16,17]},"content":"File opening and closing","children":[{"type":"heading","depth":2,"payload":{"lines":[17,18]},"content":"Function to open txt file in read mode","children":[]},{"type":"heading","depth":2,"payload":{"lines":[18,19]},"content":"Function to open txt file in write mode","children":[]},{"type":"heading","depth":2,"payload":{"lines":[19,20]},"content":"Function to open bin file in read mode","children":[]},{"type":"heading","depth":2,"payload":{"lines":[20,21]},"content":"Function to open bin file in write mode","children":[]}]},{"type":"heading","depth":1,"payload":{"lines":[23,24]},"content":"File reading and writing","children":[{"type":"heading","depth":2,"payload":{"lines":[24,25]},"content":"Function to clear the content of any type of files","children":[]},{"type":"heading","depth":2,"payload":{"lines":[25,26]},"content":"Read the first line of a text file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[26,27]},"content":"Read the last line of a text file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[27,28]},"content":"Read the entire txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[28,29]},"content":"Write on a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[29,30]},"content":"Append on a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[30,31]},"content":"Copy the content of one txt file to another txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[31,32]},"content":"Write any data in binary mode","children":[]},{"type":"heading","depth":2,"payload":{"lines":[32,33]},"content":"Append any data in binary mode","children":[]},{"type":"heading","depth":2,"payload":{"lines":[33,34]},"content":"Read any data from a bin file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[34,35]},"content":"Write data in chunks in bin file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[35,36]},"content":"Read data in chunks from bin file","children":[]}]},{"type":"heading","depth":1,"payload":{"lines":[38,39]},"content":"File positioning and manipulation","children":[{"type":"heading","depth":2,"payload":{"lines":[39,40]},"content":"Get a specific position in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[40,41]},"content":"Seek to a specific position in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[41,42]},"content":"Reset the position to the beginning of the file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[42,43]},"content":"Read a line at a specific position in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[43,44]},"content":"Write a line at a specific position in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[44,45]},"content":"Delete a line at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[45,46]},"content":"Read lines at a specific position in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[46,47]},"content":"Write lines at a specific position in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[47,48]},"content":"Delete lines at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[48,49]},"content":"Read a line at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[49,50]},"content":"Write a line at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[50,51]},"content":"Read lines at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[51,52]},"content":"Write lines at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[52,53]},"content":"Append a line at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[53,54]},"content":"Append lines at a specific number in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[54,55]},"content":"Search for a specific word in a txt file and return the first line number where it occurs","children":[]},{"type":"heading","depth":2,"payload":{"lines":[55,56]},"content":"Delete a specific word in a txt file","children":[]},{"type":"heading","depth":2,"payload":{"lines":[56,57]},"content":"Replace a specific word in a txt file","children":[]}]}]},{})</script>
</body>
</html>


---

## Installation and Usage:

You can clone the repository to your machine.

1. Clone the repository to your local machine, using the following command:

```BASH
git clone https://github.com/Ali-Elbana/File-IO-Module.git
```
2. Drag and drop the `FIO.cpp` and `FIO.hpp` file in your project wor directory.
3. Finally write this line `#include "FIO.hpp"` in your application file.

---

## Contribution Guidelines:

Contributions to the File I/O Module are welcome! If you have any suggestions, improvements, or additional content to contribute, please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your changes (```git branch feature/improvement```).
3. Make your modifications and additions.
4. Commit and push your changes to your forked repository(```git commit -am 'Add new feature'```, ```git push origin feature/improvement```).
5. Submit a pull request detailing the changes you made.

---

## License:

This project is licensed under the GNU GPLv3 License. Feel free to use, modify, and distribute the File I/O Module, following the terms of the license.

---

## Contact Information:

If you have any questions, suggestions, or feedback regarding the File I/O Module, please feel free to contact me at **alitheboss922@gmail.com** with subject [File I/O Module].

---

## Acknowledgments:

I would like to express my gratitude to the contributors and supporters who would help in creating and improving the File I/O Module. Your contributions are greatly appreciated.

---



