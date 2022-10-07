1. In C++ every int is 32 bits.
2. They are indexed from right to left.
3. The bit representation of a paritcular number is either signed or unsigned.
4. Least Significat Bit (LSB) & Most Significant Bit (MSB): 10 in binary is (MSB Part)1010 (LSB Part), so from MSB side the number is 1010 from LSB side number is 0101. Endiness (storing the actual data in the memory): Little Endian (LSB), Big Endian (MSB).
5. 1's Complement is nothing but toggling every bit of the number. It is represented by using the symbol ~.
6. 2's Compliment is : ~X + 1
7. __builtin_clz(x): counts the number of zeros present in the leading position.
8. __builtin_ctz(x): count the trailing zeros.
9. (A + B) = (A ^ B) + 2(A&B)
Note : In the above equation, it is the full adder. Here A ^ B is the answer where as A&B is the carry. We are multiplying the A&B by 2 in order to left shift the bits. Instead of multiplying by 2 you can simply use left shift too. ( (A&B) << 1 )