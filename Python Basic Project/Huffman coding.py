# Huffman coding is used to reduce the size of the file 
import heapq
import os

class BinaryTreeNode:
    def __init__(self,value,frequency):
        self.value = value
        self.frequency = frequency
        self.left = None
        self.right = None

    def __lt__(self,other):
        return self.frequency < other.frequency

    def __eq__(self,other):
        return self.frequency == other.frequency


class HuffmanCoding:
    def __init__(self,path):
        self.path = path
        self.__heap = []
        self.__codes = {}

    def __make_frequency_dict(self,text):
        freq_dict = {}
        for char in text:
            if char not in freq_dict:
                freq_dict[char] = 0 
            freq_dict[char] += 1
        return freq_dict

    def __buildheap(self,freq_dict):
        for key in freq_dict:
            frequency = freq_dict[key]
            binary_tree_node = BinaryTreeNode(key,frequency)
            heapq.heappush(self.__heap,binary_tree_node)

    def __buildTree(self):
        while((len(self.__heap))>1):
            binary_tree_node_1 = heapq.heappop(self.__heap)
            binary_tree_node_2 = heapq.heappop(self.__heap)
            freq_sum = binary_tree_node_1.frequency + binary_tree_node_2.frequency
            newnode = BinaryTreeNode(None,freq_sum)
            newnode.left = binary_tree_node_1
            newnode.right = binary_tree_node_2
            heapq.heappush(self.__heap,newnode)
        return

    def buildcodeshelper(self,head,curr_bits):
        if head is None:
            return 
        if head.value is not None:
            self.__codes[head.value] = curr_bits
            return
        self.buildcodeshelper(head.left,curr_bits+"0")
        self.buildcodeshelper(head.right,curr_bits+"1")

    def __buildcodes(self):
        head = self.__heap[0]
        self.buildcodeshelper(head,"")

    def __getEncodedtext(self,text):
        encoded_text = ""
        for char in text:
            encoded_text += self.__codes[char]
        return encoded_text

    def __getPaddedEncodedText(self,encoded_text):
        padded_amount=8-(len(encoded_text)%8)
        
        for i in range(padded_amount):
            encoded_text+='0'
        padded_info="{0:08b}".format(padded_amount)
        padded_encoded_text=padded_info+encoded_text
        return padded_encoded_text

    def __getBytesArray(self,padded_encoded_text):
        array = []
        for i in range(0,len(padded_encoded_text),8):
            byte = padded_encoded_text[i:i+8]
            array.append(int(byte,2))

        return array

    def compress(self):

        # get file from the path
        file_name,file_extension = os.path.splitext(self.path)
        output_path = file_name + ".bin"
        # read text from file
        with open(self.path,"r+") as file , open(output_path,"wb") as output:
            text = file.read()
            text = text.rstrip()

        # make frequency dictionary from the text
        freq_dict = self.__make_frequency_dict(text)

        # construct the heap from the frequency dict
        self.__buildheap(freq_dict)

        # construct the binary tree from the heap
        self.__buildTree()

        # construct the codes from the binary tree
        self.__buildcodes()

        # creating the encoded text using the codes
        encoded_text = self.__getEncodedtext(text)

        # padded this encoded text first 
        padded_encoded_text = self.__getPaddedEncodedText(encoded_text)
        # put this encoded text into the binary.file
        bytes_array = self.__getBytesArray(padded_encoded_text)
        final_bytes = bytes(bytes_array)
        # return this binary file as output
        output.write(final_bytes)
        print("compressed!!")

        return output_path



path = "/home/saket18/hello.txt"   # you can give the path of your file
h = HuffmanCoding(path)
output_path = h.compress()		# it will return the path of the output file
