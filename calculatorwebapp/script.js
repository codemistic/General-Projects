"use strict";
const n1=document.getElementsByClassName("numbers");
const n2=document.getElementsByClassName("operator");

//console.log(n1,"\n",n2);
//console.log(typeof(+(n1[4].textContent)));
let sum="";
let num="";

function number(e){
    if(e.target.textContent==='C'){
        document.getElementById("screen").textContent="";
        sum="";
        return;
    }
    if(e.target.textContent!=='='){
        if(sum.length===26){
            alert("cannot enter number greater than is");
            return;
        }
        
         sum=sum+e.target.textContent;
         document.getElementById("screen").textContent=sum;
         return;
    }
    if(e.target.textContent==='='){
        document.getElementById("screen").textContent=eval(sum);
        sum="";
        return;
    }
}
n1[0].addEventListener("click",number);
n1[1].addEventListener("click",number);
n1[2].addEventListener("click",number);
n1[3].addEventListener("click",number);
n1[4].addEventListener("click",number);
n1[5].addEventListener("click",number);
n1[6].addEventListener("click",number);
n1[7].addEventListener("click",number);
n1[8].addEventListener("click",number);
n1[9].addEventListener("click",number);
n2[0].addEventListener("click",number);
n2[1].addEventListener("click",number);
n2[2].addEventListener("click",number);
n2[3].addEventListener("click",number);
n2[4].addEventListener("click",number);
n2[5].addEventListener("click",number);
n2[6].addEventListener("click",number);

