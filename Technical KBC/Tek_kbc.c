> Vikash:
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 FILE *fp;
 int i;
 struct quiz
 {
  char str[300];
  char a[50];
  char b[50];
  char c[50];
  char d[50];
  char right;
 };
 struct quiz temp;
 fp=fopen("Quiz.txt","wb+");
 
 struct quiz q1 = { "How many times will GeeksQuiz be printed in the below program?\n#include <stdio.h>\nint main()\n{\n\tint i=1024;\n\tfor (; i; i >>= 1)\n\t\tprintf(\"GeeksQuiz\");\n\treturn 0;\n}",
  "A. 10", "B. 11", "C. infinite loop", "D. compile-time error", 'B'};
 fwrite(&q1,sizeof(q1),1,fp);
 
 fseek(fp,0,SEEK_END);
 
 struct quiz q2 = { "What is the output of the below program?\n#include <stdio.h>\nint main()\n{\n\tint i=0;\n\tswitch (i)\n\t{\n\t\tcase '0': printf(\"Geeks\");\n\t\t\tbreak;\n\t\tcase '1': printf(\"Quiz\");\n\t\t\tbreak;\n\t\tdefault: printf(\"GeeksQuiz\");\n\t}\n\treturn 0;\n}",
  "A. Geeks", "B. Quiz", "C. GeeksQuiz", "D. compile-time error", 'C' };
 fwrite(&q2,sizeof(q2),1,fp);
 
 struct quiz q3 = { "Predict the output of the below program:\n#include <stdio.h>\n#define EVEN 0\n#define ODD 1\nint main()\n{\n\tint i=3;\n\tswitch (i & 1)\n\t{\n\t\tcase EVEN: printf(\"Even\");\n\t\t\tbreak;\n\t\tcase ODD: printf(\"Odd\");\n\t\t\tbreak;\n\t\tdefault: printf(\"Default\");\n\t}\n\treturn 0;\n}",
  "A. Even", "B. Odd", "C. Default", "D. compile-time error", 'B' };
 fwrite(&q3,sizeof(q3),1,fp);
 
 struct quiz q4 = { "Predict the output of the below program:\n#include <stdio.h>\nint main()\n{\n\tint i;\n\tif (printf(\"0\"))\n\t\ti = 3;\n\telse\n\t\ti = 5;\n\tprintf(\"%d\", i);\n\treturn 0;\n}",
  "A. 3", "B. 5", "C. 03", "D. 05", 'C' };
 fwrite(&q4,sizeof(q4),1,fp);
 
 struct quiz q5 = { "Predict the output of the below program:\n#include <stdio.h>\nint main()\n{\n\tint c = 5, no = 10;\n\tdo\n\t{\n\t\tno /= c;\n\t} while(c--);\n\tprintf (\"%dn\", no);\n\treturn 0;}",
  "A. run-time error", "B. 1", "C. 0", "D. compile-time error", 'A' };
 fwrite(&q5,sizeof(q5),1,fp);
 
 struct quiz q6 = { "Predict the output of the below program:\n#include <stdio.h>\nint main()\n{\n\tint check = 20, arr[] = {10, 20, 30};\n\tswitch (check)\n\t{\n\t\tcase arr[0]: printf(\"Geeks \");\n\t\tcase arr[1]: printf(\"Quiz \");\n\t\tcase arr[2]: printf(\"GeeksQuiz\");\n\t}\n\treturn 0;\n}",
  "A. Quiz", "B. Quiz GeeksQuiz", "C. GeeksQuiz", "D. compile-time error", 'D' };
 fwrite(&q6,sizeof(q6),1,fp);
 
 struct quiz q7 = { "Predict the output of the below program:\n#include <stdio.h>\nint main()\n{\n\tint a=5;switch(a)\n\t{\n\t\tdefault:\n\t\t\ta = 4;\n\t\tcase 6:\n\t\t\ta--;\n\t\tcase 5:\n\t\t\ta = a+1;\n\t\tcase 1:\n\t\t\ta = a-1;\n\t}\n\tprintf(\"%d\", a);\n\treturn 0;}",
  "A. 3", "B. 4", "C. 5", "D. none of these", 'C' };
 fwrite(&q7,sizeof(q7),1,fp);
 
 struct quiz q8 = { "Which combination of the integer variables x, y and z makes the \nvariable a get the value 4 in the following expression?\n\ta = ( x > y ) ? (( x > z ) ? x : z) : (( y > z ) ? y : z )",
  "A. x = 6, y = 5, z = 3", "B. x = 5, y = 4, z = 5", "C. x = 6, y = 3, z = 5", "D. x = 3, y = 4, z = 2", 'D' };
 fwrite(&q8,sizeof(q8),1,fp);
 
 struct quiz q9 = { "What is going to happen when we compile and run the following C program?\n#include <stdio.h>\nint main()\n{\n\tint i = 1, j;\n\tfor ( ; ; )\n\t{ \n\t\tif (i)\n\t\t\tj = --i;\n\t\tif (j < 10)\n\t\t\tprintf(\"GeeksQuiz\", j++);\n\t\telse\n\t\t\tbreak;\n\t}\n\treturn 0;\n}",
  "A. print GeeksQuiz 10 times", "B. compile-time error", "C. infinite loop", "D. print GeeksQuiz 9 times", 'A' };
 fwrite(&q9,sizeof(q9),1,fp);
 
 struct quiz q10 = { "Predict the output of the below program:\n#include <stdio.h>\nint main()\n{\n\tunsigned int i = 65000;\n\twhile (i++ != 0);\n\tprintf(\"%d\", i);\n\treturn 0;\n}",
  "A. infinite loop", "B. 0", "C. 1", "D. run-time error", 'C' };

> Vikash:
fwrite(&q10,sizeof(q10),1,fp);
 
 struct quiz q11 = { "Predict the output of following program?\n#include \"stdio.h\"\nint main()\n{\n\tchar arr[100];\n\tprintf(\"%d\", scanf(\"%s\", arr));\n\t/* Suppose that input value given\n\tfor above scanf is \"Quiz\" */\n\treturn 0;\n}",
  "A. 9", "B. 1", "C. 10", "D. 100", 'B' };
 fwrite(&q11,sizeof(q11),1,fp);
 
 struct quiz q12 = { "Predict the output of the following code:\n#include <stdio.h>\n// Assume base address of \"GeeksQuiz\" to be 1000\nint main()\n{\n\tprintf(5 + \"GeeksQuiz\");\n\treturn 0;\n}",
  "A. GeeksQuiz", "B. Quiz", "C. 1005", "D. compile-time error", 'B' };
 fwrite(&q12,sizeof(q12),1,fp);
 
 struct quiz q13 = { "Predict the output of the below program:\n#include <stdio.h>\nint main()\n{\n\tprintf(\"%c \", 5[\"GeeksQuiz\"]);\n\treturn 0;\n}",
  "A. Q", "B. s", "C. run-time error", "D. compile-time error", 'A' };
 fwrite(&q13,sizeof(q13),1,fp);
 
 struct quiz q14 = { "Predict the output of following program?\n#include <stdio.h>\nint main(void) \n{\n\tint x = printf(\"GeeksQuiz\");\n\tprintf(\"%d\", x);\n\treturn 0;\n}",
  "A. GeeksQuiz1", "B. GeeksQuizGeeksQuiz", "C. GeeksQuiz10", "D. GeeksQuiz9", 'D' };
 fwrite(&q14,sizeof(q14),1,fp);
 
 struct quiz q15 = { "What will be the output of the following C code?\n#include <stdio.h>\nint main( )\n{\n\tint i;\n\tfor ( i=0; i<5; i++ )\n\t{\n\t\tint i = 10;\n\t\tprintf ( \"%d \", i );\n\t\ti++;\n\t}\n\treturn 0;\n}",
  "A. 0 1 2 3 4", "B. 10 11 12 13 14", "C. 10 10 10 10 10", "D. infinite-loop", 'C' };
 fwrite(&q15,sizeof(q15),1,fp);
 
 rewind(fp);
 while(fread(&temp,sizeof(temp),1,fp)==1)
  printf("\n%s \n\n%-30s %-30s \n%-30s %-30s\n%c\n",temp.str,temp.a,temp.b,temp.c,temp.d,temp.right);
 getch();
 fclose(fp);
}
