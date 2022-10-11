import os
def Return():
    C="Y"
    while(C=="Y"):
        PI=0        
        F=open("Return.txt","r")
        X=F.readline()
        while X:
            PI=PI+1
            X=F.readline()
        F.close()
        F=open("Return.txt","a+")
        PD=str(input("\t\t\t enter Returned Date          :"))
        VN=str(input("\t\t\t enter Student Name            :"))
        VPno=str(input("\t\t\t enter Student Phno.           :"))
        MI=str(input("\t\t\t enter Book Id              :"))
        Q=int(input("\t\t\t enter Quantity               :"))
        F.write(str(PI)+":"+PD+":"+VN+":"+VPno+":"+MI+":"+str(Q)+"\n")
        F.close()
        Z=open("Stock.txt","r")
        k=Z.readline()
        k=Z.readline()
        N=[]
        while k:
            A=k.split(":")
            N.append(A[0])
            k=Z.readline()
        Z.close()
        Z=open("Stock.txt","r")
        Y=open("Temp.txt","w")
        m=Z.readline()
        Y.write(m)
        m=Z.readline()
        while m:
            B=m.split(":")
            if(MI.strip()==B[0].strip()):
                B[3]=str(int(B[3])+Q)
                Y.write((":".join(B)+"\n"))
            else:
                Y.write((":".join(B)))
            m=Z.readline()
        C=input("\t\t\t You Want To Continue(Y/N)    :")
        Y.close()
        Z.close()
        os.remove("Stock.txt")
        os.rename("Temp.txt","Stock.txt")
def ReturnModification():
    F=open("Return.txt","r+")
    B=open("ReturnTemp.txt","w+")
    PI=str(input("\t\t\t Please enter Return id of \n\t\t\t Phone Record you want to modify"))
    k=F.readline()
    while k:
        A=k.split(":")
        if(A[0].strip()==PI):
            PD=str(input("\t\t\t enter Returned Date          :"))
            VN=str(input("\t\t\t enter Student Name            :"))
            VPno=str(input("\t\t\t enter Student Phno.           :"))
            MI=str(input("\t\t\t enter Book Id              :"))
            Q=int(input("\t\t\t enter Quantity               :"))
            K=open("Stock.txt","r")
            S=open("Stocktemp.txt","w")
            t=K.readline()
            while(t):
                c=t.split(":")
                t=K.readline()
                if(A[4]==c[0]):
                    c[3]=str(int(c[3])-int(A[5]))+"\n"
                    S.write((":".join(c)))
                else:
                    S.write((":".join(c)))
            K.close()
            S.close()
            os.remove("Stock.txt")
            os.rename("Stocktemp.txt","Stock.txt")
            B.write(str(PI)+":"+PD+":"+VN+":"+VPno+":"+MI+":"+str(Q)+"\n")
            K=open("Stock.txt","r")
            S=open("Stocktemp.txt","w")
            t=K.readline()
            while(t):
                c=t.split(":")
                t=K.readline()
                if(MI==c[0]):
                    c[3]=str(int(c[3])+int(Q))+"\n"
                    S.write((":".join(c)))
                else:
                    S.write((":".join(c)))
            K.close()
            S.close()
            os.remove("Stock.txt")
            os.rename("Stocktemp.txt","Stock.txt")
        else:
            B.write(k)
        k=F.readline()
    B.close()
    F.close()
    os.remove("Return.txt")
    os.rename("ReturnTemp.txt","Return.txt")
def Returndetail():
    F=open("Return.txt","r")
    print("*******************************************************")
    k=F.readline()
    A=k.split(":")
    for i in range(0,len(A)):
        print(A[i].strip(),end=" "*(15-len(A[i])))
    print()
    print("*******************************************************")
    F.close()
    F=open("Return.txt","r")
    k=F.readline()
    k=F.readline()
    while k:
        A=k.strip()
        A=A.split(":")
        for i in range(0,len(A)):
            print(A[i],end=" "*(15-len(A[i])))
        print()    
        k=F.readline()
    F.close()
def Stockdetail():