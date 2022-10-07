## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
This project generates report cards of all students by running .exe file. The idea is to replicate [this](https://www.mathsolympiad.org/wp-content/uploads/2021/08/ESR-Sample.pdf) till Section 2. As an input we need an excel file in which result of all the students is present and their pictures are also available , and both types of files by default is available in this project (You can replace it with your one). By running pdfGenerator.exe file, in few seconds you will notice that Pdfs are being generated as per the information.  
	
## Technologies
Project is created with:
* Python 2.7 : Source Code is written in Python language.
* Libraries : Reportlab - To generate Pdfs, Openpyxl - To read data from excel file , Metaplotlib - To draw graphs inside Pdfs.
* Pyinstaller : To convert Python source code to .exe.
	
## Setup
To run this project, Clone it locally using cmd:

```
C:\>mkdir project
C:\>cd project
C:\project>git init
C:\project>git clone https://github.com/BhuwaneshNainwal/General-Projects/tree/main/Python%20Report%20Card%20Project
```

## Demo

![](https://github.com/BhuwaneshNainwal/Python-Automation/blob/master/Report%20Card%20Automation/dist/report.gif)

