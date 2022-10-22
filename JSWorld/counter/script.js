var counter= document.querySelector(".counter");
var followers= document.querySelector(".followers");


// counter.innerHTML=1001;

let count=1;
setInterval(() => {
    if(count<1000){
    count++;
    counter.innerText=count;}
}, 5);
 
setTimeout(() => {
    followers.innerHTML="Follower on Instagram !!";
    
}, 5400);
